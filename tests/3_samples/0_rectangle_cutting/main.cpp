#include <0_common/window.hpp>
#include <thread>
#include <iostream>

#include "shaders/shared.inl"

#include <daxa/utils/pipeline_manager.hpp>

#include <daxa/utils/imgui.hpp>
#include <imgui_impl_glfw.h>

#define APPNAME "Daxa Sample: Rectangle Cutting"
#define APPNAME_PREFIX(x) ("[" APPNAME "] " x)

#include <daxa/utils/math_operators.hpp>

using namespace daxa::types;
using Clock = std::chrono::high_resolution_clock;

i32 const max_layers = 12;
i32 const max_levels = 16;

enum
{
    MAX_VERTS = 10000
};

struct App : AppWindow<App>
{
    daxa::Context daxa_ctx = daxa::create_context({
        .enable_validation = true,
    });
    daxa::Device device = daxa_ctx.create_device({
        .debug_name = APPNAME_PREFIX("device"),
    });

    daxa::Swapchain swapchain = device.create_swapchain({
        .native_window = get_native_handle(),
        .native_window_platform = get_native_platform(),
        .present_mode = daxa::PresentMode::DO_NOT_WAIT_FOR_VBLANK,
        .image_usage = daxa::ImageUsageFlagBits::TRANSFER_DST,
        .debug_name = APPNAME_PREFIX("swapchain"),
    });

    daxa::PipelineManager pipeline_manager = daxa::PipelineManager({
        .device = device,
        .shader_compile_options = {
            .root_paths = {
                "tests/3_samples/0_rectangle_cutting/shaders",
                "include",
            },
            .language = daxa::ShaderLanguage::GLSL,
        },
        .debug_name = APPNAME_PREFIX("pipeline_manager"),
    });

    daxa::ImGuiRenderer imgui_renderer = create_imgui_renderer();
    auto create_imgui_renderer() -> daxa::ImGuiRenderer
    {
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForVulkan(glfw_window_ptr, true);
        return daxa::ImGuiRenderer({
            .device = device,
            .format = swapchain.get_format(),
        });
    }

    // clang-format off
    std::shared_ptr<daxa::RasterPipeline> raster_pipeline = pipeline_manager.add_raster_pipeline({
        .vertex_shader_info = {.source = daxa::ShaderFile{"draw.glsl"}, .compile_options = {.defines = {daxa::ShaderDefine{"DRAW_VERT"}}}},
        .fragment_shader_info = {.source = daxa::ShaderFile{"draw.glsl"}, .compile_options = {.defines = {daxa::ShaderDefine{"DRAW_FRAG"}}}},
        .color_attachments = {{
            .format = swapchain.get_format(),
            .blend = {
                .blend_enable = 1u,
                .src_color_blend_factor = daxa::BlendFactor::SRC_ALPHA,
                .dst_color_blend_factor = daxa::BlendFactor::ONE_MINUS_SRC_ALPHA,
                .src_alpha_blend_factor = daxa::BlendFactor::ONE,
                .dst_alpha_blend_factor = daxa::BlendFactor::ONE_MINUS_SRC_ALPHA,
            },
        }},
        .raster = {},
        .push_constant_size = sizeof(DrawPush),
        .debug_name = APPNAME_PREFIX("raster_pipeline"),
    }).value();
    // clang-format on

    daxa::BufferId vertex_buffer = device.create_buffer(daxa::BufferInfo{
        .size = sizeof(DrawVertex) * MAX_VERTS,
        .debug_name = APPNAME_PREFIX("vertex_buffer"),
    });
    u32 vert_n = 0;

    daxa::ImageMipArraySlice s0 = {
        .image_aspect = daxa::ImageAspectFlagBits::COLOR | daxa::ImageAspectFlagBits::DEPTH,
        .base_mip_level = 3,
        .level_count = 5,
        .base_array_layer = 2,
        .layer_count = 4,
    };
    daxa::ImageMipArraySlice s1 = {
        .image_aspect = daxa::ImageAspectFlagBits::COLOR,
        .base_mip_level = 5,
        .level_count = 2,
        .base_array_layer = 3,
        .layer_count = 4,
    };

    App() : AppWindow<App>(APPNAME, 1600, 1200) {}

    ~App()
    {
        device.wait_idle();
        device.collect_garbage();
        ImGui_ImplGlfw_Shutdown();
        device.destroy_buffer(vertex_buffer);
    }

    auto update() -> bool
    {
        glfwPollEvents();
        if (glfwWindowShouldClose(glfw_window_ptr) != 0)
        {
            return true;
        }

        if (!minimized)
        {
            draw();
        }
        else
        {
            using namespace std::literals;
            std::this_thread::sleep_for(1ms);
        }

        return false;
    }

    void add_rect(DrawVertex *& buffer_ptr, f32vec2 p0, f32vec2 p1, f32vec4 col)
    {
        // clang-format off
        *buffer_ptr = DrawVertex{{p0.x, p0.y, 0.0f, 0.0f}, col}; ++buffer_ptr;
        *buffer_ptr = DrawVertex{{p1.x, p0.y, 0.0f, 0.0f}, col}; ++buffer_ptr;
        *buffer_ptr = DrawVertex{{p0.x, p1.y, 0.0f, 0.0f}, col}; ++buffer_ptr;

        *buffer_ptr = DrawVertex{{p1.x, p0.y, 0.0f, 0.0f}, col}; ++buffer_ptr;
        *buffer_ptr = DrawVertex{{p0.x, p1.y, 0.0f, 0.0f}, col}; ++buffer_ptr;
        *buffer_ptr = DrawVertex{{p1.x, p1.y, 0.0f, 0.0f}, col}; ++buffer_ptr;
        // clang-format on

        vert_n += 6;
    }

    void ui_update()
    {
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("Debug");
        {
            i32 mips[2] = {static_cast<i32>(s0.base_mip_level), static_cast<i32>(s0.level_count)};
            ImGui::SliderInt("Mip Base 0", &mips[0], 0, max_levels - 1);
            ImGui::SliderInt("Mip Count 0", &mips[1], 1, max_levels - mips[0]);
            s0.base_mip_level = static_cast<u32>(mips[0]);
            s0.level_count = static_cast<u32>(mips[1]);
            i32 arrs[2] = {static_cast<i32>(s0.base_array_layer), static_cast<i32>(s0.layer_count)};
            ImGui::SliderInt("Array Base 0", &arrs[0], 0, max_layers - 1);
            ImGui::SliderInt("Array Count 0", &arrs[1], 1, max_layers - arrs[0]);
            s0.base_array_layer = static_cast<u32>(arrs[0]);
            s0.layer_count = static_cast<u32>(arrs[1]);
        }
        {
            i32 mips[2] = {static_cast<i32>(s1.base_mip_level), static_cast<i32>(s1.level_count)};
            ImGui::SliderInt("Mip Base 1", &mips[0], 0, max_levels - 1);
            ImGui::SliderInt("Mip Count 1", &mips[1], 1, max_levels - mips[0]);
            s1.base_mip_level = static_cast<u32>(mips[0]);
            s1.level_count = static_cast<u32>(mips[1]);
            i32 arrs[2] = {static_cast<i32>(s1.base_array_layer), static_cast<i32>(s1.layer_count)};
            ImGui::SliderInt("Array Base 1", &arrs[0], 0, max_layers - 1);
            ImGui::SliderInt("Array Count 1", &arrs[1], 1, max_layers - arrs[0]);
            s1.base_array_layer = static_cast<u32>(arrs[0]);
            s1.layer_count = static_cast<u32>(arrs[1]);
        }
        ImGui::End();
        ImGui::Render();
    }

    void construct_scene(DrawVertex *& buffer_ptr)
    {
        vert_n = 0;
        using namespace daxa::math_operators;

        auto view_transform = [](auto v)
        {
            return (v / f32vec2{static_cast<f32>(max_levels), static_cast<f32>(max_layers)}) * 2.0f - 1.0f;
        };
        auto add_int_rect = [&](auto xi, auto yi, auto sx, auto sy, f32 scl, f32vec4 col)
        {
            f32vec2 const p0 = f32vec2{static_cast<f32>(xi), static_cast<f32>(yi)} + scl * 0.5f;
            f32vec2 const p1 = p0 + f32vec2{static_cast<f32>(sx), static_cast<f32>(sy)} - scl;
            add_rect(buffer_ptr, view_transform(p0), view_transform(p1), col);
        };

        for (i32 yi = 0; yi < max_layers; ++yi)
        {
            for (i32 xi = 0; xi < max_levels; ++xi)
            {
                add_int_rect(xi, yi, 1, 1, 0.1f, {0.1f, 0.1f, 0.1f, 0.5f});
            }
        }

        add_int_rect(s0.base_mip_level, s0.base_array_layer, s0.level_count, s0.layer_count, 0.0f, {0.3f, 0.9f, 0.3f, 0.9f});
        add_int_rect(s1.base_mip_level, s1.base_array_layer, s1.level_count, s1.layer_count, 0.0f, {0.9f, 0.3f, 0.3f, 0.9f});

        auto [s2_rects, s2_rect_n] = s0.subtract(s1);
        f32vec4 const s2_colors[4] = {
            {0.1f, 0.1f, 0.1f, 0.5f},
            {0.1f, 0.1f, 0.1f, 0.5f},
            {0.1f, 0.1f, 0.1f, 0.5f},
            {0.1f, 0.1f, 0.1f, 0.5f},
        };

        for (usize i = 0; i < s2_rect_n; ++i)
        {
            auto const & s2 = s2_rects[i];
            add_int_rect(s2.base_mip_level, s2.base_array_layer, s2.level_count, s2.layer_count, 0.2f, s2_colors[i]);
        }
    }

    void draw()
    {
        ui_update();

        auto reloaded_result = pipeline_manager.reload_all();
        if (reloaded_result.is_err())
        {
            std::cout << reloaded_result.to_string() << std::endl;
        }

        auto swapchain_image = swapchain.acquire_next_image();

        auto cmd_list = device.create_command_list({
            .debug_name = APPNAME_PREFIX("cmd_list"),
        });

        auto vertex_staging_buffer = device.create_buffer({
            .memory_flags = daxa::MemoryFlagBits::HOST_ACCESS_RANDOM,
            .size = sizeof(DrawVertex) * MAX_VERTS,
            .debug_name = APPNAME_PREFIX("vertex_staging_buffer"),
        });
        cmd_list.destroy_buffer_deferred(vertex_staging_buffer);

        auto * buffer_ptr = device.get_host_address_as<DrawVertex>(vertex_staging_buffer);
        construct_scene(buffer_ptr);

        cmd_list.pipeline_barrier({
            .awaited_pipeline_access = daxa::AccessConsts::HOST_WRITE,
            .waiting_pipeline_access = daxa::AccessConsts::TRANSFER_READ,
        });

        cmd_list.copy_buffer_to_buffer({
            .src_buffer = vertex_staging_buffer,
            .dst_buffer = vertex_buffer,
            .size = sizeof(DrawVertex) * vert_n,
        });

        cmd_list.pipeline_barrier({
            .awaited_pipeline_access = daxa::AccessConsts::TRANSFER_WRITE,
            .waiting_pipeline_access = daxa::AccessConsts::VERTEX_SHADER_READ,
        });

        cmd_list.pipeline_barrier_image_transition({
            .waiting_pipeline_access = daxa::AccessConsts::COLOR_ATTACHMENT_OUTPUT_WRITE,
            .before_layout = daxa::ImageLayout::UNDEFINED,
            .after_layout = daxa::ImageLayout::ATTACHMENT_OPTIMAL,
            .image_id = swapchain_image,
        });

        cmd_list.begin_renderpass({
            .color_attachments = {{.image_view = swapchain_image.default_view(), .load_op = daxa::AttachmentLoadOp::CLEAR, .clear_value = std::array<f32, 4>{0.5f, 0.5f, 0.5f, 1.0f}}},
            .render_area = {.x = 0, .y = 0, .width = size_x, .height = size_y},
        });
        cmd_list.set_pipeline(*raster_pipeline);
        cmd_list.push_constant(DrawPush{
            .face_buffer = this->device.get_device_address(vertex_buffer),
        });
        cmd_list.draw({.vertex_count = vert_n});
        cmd_list.end_renderpass();

        imgui_renderer.record_commands(ImGui::GetDrawData(), cmd_list, swapchain_image, size_x, size_y);

        cmd_list.pipeline_barrier_image_transition({
            .awaited_pipeline_access = daxa::AccessConsts::ALL_GRAPHICS_READ_WRITE,
            .before_layout = daxa::ImageLayout::ATTACHMENT_OPTIMAL,
            .after_layout = daxa::ImageLayout::PRESENT_SRC,
            .image_id = swapchain_image,
        });

        cmd_list.complete();

        device.submit_commands({
            .command_lists = {std::move(cmd_list)},
            .wait_binary_semaphores = {swapchain.get_acquire_semaphore()},
            .signal_binary_semaphores = {swapchain.get_present_semaphore()},
            .signal_timeline_semaphores = {
                {swapchain.get_gpu_timeline_semaphore(), swapchain.get_cpu_timeline_value()}},
        });
        device.present_frame({
            .wait_binary_semaphores = {swapchain.get_present_semaphore()},
            .swapchain = swapchain,
        });
    }

    void on_mouse_move(f32 /*unused*/, f32 /*unused*/) {}
    void on_mouse_button(i32 /*unused*/, i32 /*unused*/) {}
    void on_key(i32 /*unused*/, i32 /*unused*/) {}

    void on_resize(u32 sx, u32 sy)
    {
        minimized = (sx == 0 || sy == 0);
        if (!minimized)
        {
            swapchain.resize();
            size_x = swapchain.get_surface_extent().x;
            size_y = swapchain.get_surface_extent().y;
            draw();
        }
    }
};

auto main() -> int
{
    App app = {};
    while (true)
    {
        if (app.update())
        {
            break;
        }
    }
}
