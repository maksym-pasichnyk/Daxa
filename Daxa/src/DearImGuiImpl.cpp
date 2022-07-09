#include "DearImGuiImpl.hpp"

void embraceTheDarkness() {
  ImVec4* colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_WindowBg]               = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
  colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_PopupBg]                = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
  colors[ImGuiCol_Border]                 = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
  colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
  colors[ImGuiCol_FrameBg]                = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
  colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
  colors[ImGuiCol_FrameBgActive]          = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
  colors[ImGuiCol_TitleBg]                = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_TitleBgActive]          = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
  colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
  colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
  colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
  colors[ImGuiCol_CheckMark]              = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
  colors[ImGuiCol_SliderGrab]             = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
  colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
  colors[ImGuiCol_Button]                 = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
  colors[ImGuiCol_ButtonHovered]          = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
  colors[ImGuiCol_ButtonActive]           = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
  colors[ImGuiCol_Header]                 = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_HeaderHovered]          = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
  colors[ImGuiCol_HeaderActive]           = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
  colors[ImGuiCol_Separator]              = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
  colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
  colors[ImGuiCol_SeparatorActive]        = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
  colors[ImGuiCol_ResizeGrip]             = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
  colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
  colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
  colors[ImGuiCol_Tab]                    = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TabHovered]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_TabActive]              = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
  colors[ImGuiCol_TabUnfocused]           = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  //colors[ImGuiCol_DockingPreview]         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
  //colors[ImGuiCol_DockingEmptyBg]         = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotLines]              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogram]          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
  colors[ImGuiCol_TableBorderLight]       = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
  colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
  colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
  colors[ImGuiCol_DragDropTarget]         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
  colors[ImGuiCol_NavHighlight]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
  colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
  colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
  colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

  ImGuiStyle& style = ImGui::GetStyle();
  style.WindowPadding                     = ImVec2(8.00f, 8.00f);
  style.FramePadding                      = ImVec2(5.00f, 2.00f);
  style.CellPadding                       = ImVec2(6.00f, 6.00f);
  style.ItemSpacing                       = ImVec2(6.00f, 6.00f);
  style.ItemInnerSpacing                  = ImVec2(6.00f, 6.00f);
  style.TouchExtraPadding                 = ImVec2(0.00f, 0.00f);
  style.IndentSpacing                     = 25;
  style.ScrollbarSize                     = 15;
  style.GrabMinSize                       = 10;
  style.WindowBorderSize                  = 1;
  style.ChildBorderSize                   = 1;
  style.PopupBorderSize                   = 1;
  style.FrameBorderSize                   = 1;
  style.TabBorderSize                     = 1;
  style.WindowRounding                    = 7;
  style.ChildRounding                     = 4;
  style.FrameRounding                     = 3;
  style.PopupRounding                     = 4;
  style.ScrollbarRounding                 = 9;
  style.GrabRounding                      = 3;
  style.LogSliderDeadzone                 = 4;
  style.TabRounding                       = 4;
}

namespace daxa {
    ImGuiRenderer::ImGuiRenderer(DeviceHandle device, CommandQueueHandle queue, PipelineCompilerHandle& compiler) 
        : device{ device }
    {
        embraceTheDarkness();

        char const* vertex = R"--(
            struct uPushConstant {
                float2 uScale;
                float2 uTranslate;
                uint texture0_id;
                uint sampler0_id;
            };
            [[vk::push_constant]] const uPushConstant pc;
            struct VS_INPUT {
                float2 pos : POSITION;
                float2 uv  : TEXCOORD0;
                float4 col : COLOR0;
            };
            struct PS_INPUT {
                float4 pos : SV_POSITION;
                float4 col : COLOR0;
                float2 uv  : TEXCOORD0;
            };
            PS_INPUT main(VS_INPUT input) {
                PS_INPUT output;
                output.pos = float4(input.pos * pc.uScale + pc.uTranslate, 0, 1);
                output.col = input.col;
                output.uv  = input.uv;
                return output;
            }
        )--";

        char const* fragment = R"--(
            #include "daxa.hlsl"
            struct uPushConstant {
                float2 uScale;
                float2 uTranslate;
                uint texture0_id;
                uint sampler0_id;
            };
            [[vk::push_constant]] const uPushConstant pc;
            struct PS_INPUT {
                float4 pos : SV_POSITION;
                float4 col : COLOR0;
                float2 uv  : TEXCOORD0;
            };
            float4 srgb_to_linear(float4 srgb) {
                float3 color_srgb = srgb.rgb;
                float3 selector = clamp(ceil(color_srgb - 0.04045), 0.0, 1.0); // 0 if under value, 1 if over
                float3 under = color_srgb / 12.92;
                float3 over = pow((color_srgb + 0.055) / 1.055, float3(2.4, 2.4, 2.4));
                float3 result = lerp(under, over, selector);
                return float4(result, srgb.a);
            }
            float4 main(PS_INPUT In) : SV_Target {
                Texture2D<float4> texture0 = daxa::getTexture2D<float4>(pc.texture0_id);
                SamplerState sampler0 = daxa::getSampler(pc.sampler0_id);
                return srgb_to_linear(In.col) * texture0.Sample(sampler0, In.uv);
            }
        )--";

        daxa::GraphicsPipelineBuilder pipelineBuilder;
        auto pipelineDescription = pipelineBuilder
            .setPushConstantSize(sizeof(u32))
            .addShaderStage({.source = vertex, .stage = VK_SHADER_STAGE_VERTEX_BIT})
            .addShaderStage({.source = fragment, .stage = VK_SHADER_STAGE_FRAGMENT_BIT})
            .setDebugName("ImGui render pipeline")
            .beginVertexInputAttributeBinding(VK_VERTEX_INPUT_RATE_VERTEX)
            .addVertexInputAttribute(VK_FORMAT_R32G32_SFLOAT)
            .addVertexInputAttribute(VK_FORMAT_R32G32_SFLOAT)
            .addVertexInputAttribute(VK_FORMAT_R8G8B8A8_UNORM)
            .endVertexInputAttributeBinding()
            .addColorAttachment(VK_FORMAT_B8G8R8A8_SRGB, VkPipelineColorBlendAttachmentState{
                .blendEnable = VK_TRUE,
                .srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA,
                .dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
                .colorBlendOp = VK_BLEND_OP_ADD,
                .srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE,
                .dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
                .alphaBlendOp = VK_BLEND_OP_ADD,
                .colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT,
            });

        pipeline = compiler->createGraphicsPipeline(pipelineDescription).value();

        recreatePerFrameData(4096, 4096);

        ImGuiIO& io = ImGui::GetIO();

        unsigned char* pixels;
        int width, height;
        io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
        size_t upload_size = width * height * 4 * sizeof(char);

        fontSheetId = device->createImageView({
            .image = device->createImage({
                .format = VK_FORMAT_R8G8B8A8_UNORM,
                .extent = {.width = (u32)width, .height = (u32)height, .depth = 1},
                .usage = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
            }),
            .format = VK_FORMAT_R8G8B8A8_UNORM,
        });

        auto cmdList = queue->getCommandList({});
        cmdList.queueImageBarrier({
            .image = device->info(fontSheetId).image,
            .layoutAfter = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
        });
        cmdList.singleCopyHostToImage({
            .src = pixels,
            .dst = device->info(fontSheetId).image,
        });
        cmdList.queueImageBarrier({
            .image = device->info(fontSheetId).image,
            .layoutBefore = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
            .layoutAfter = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
        });
        cmdList.finalize();
        queue->submitBlocking({
            .commandLists = { cmdList }
        });

        io.Fonts->SetTexID(0);
        samplerId = device->createSampler({});
    }
    
    ImGuiRenderer::~ImGuiRenderer() {
        device->destroySampler(samplerId);
        for (auto& frame : perFrameData) {
            if (frame.indexBuffer.isValid()) {
                device->destroyBuffer(frame.indexBuffer);
            }
            if (frame.vertexBuffer.isValid()) {
                device->destroyBuffer(frame.vertexBuffer);
            }
        }
    }

    void ImGuiRenderer::recreatePerFrameData(size_t newMinSizeVertex, size_t newMinSizeIndices) {
        perFrameData.clear();
        for (int i = 0; i < 3; i++) {
            perFrameData.push_back(PerFrameData{
                .vertexBuffer = device->createBuffer({
                    .size = newMinSizeVertex,
                    .memoryType = MemoryType::CPU_TO_GPU,
                    .debugName = "dear ImGui vertex buffer"
                }),
                .indexBuffer = device->createBuffer({
                    .size = newMinSizeIndices,
                    .memoryType = MemoryType::CPU_TO_GPU,
                    .debugName = "dear ImGui index buffer"
                }),
            });
        }
    }

    void ImGuiRenderer::recordCommands(ImDrawData* draw_data, daxa::CommandListHandle& cmdList, ImageViewHandle& target) {

        if (draw_data && draw_data->TotalIdxCount > 0) {
            //--        data upload        --//

            {
                auto frame = std::move(perFrameData.back());
                perFrameData.pop_back();
                perFrameData.push_front(std::move(frame));
            }

            auto& vertexBuffer  = perFrameData.front().vertexBuffer;
            auto& indexBuffer   = perFrameData.front().indexBuffer;

            if (draw_data->TotalVtxCount * sizeof(ImDrawVert) > device->info(vertexBuffer).size) {
                device->destroyBuffer(vertexBuffer);
                auto newSize = draw_data->TotalVtxCount * sizeof(ImDrawVert) + 4096;
                vertexBuffer = device->createBuffer({
                    .size = newSize,
                    //.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
                    //.memoryUsage = VMA_MEMORY_USAGE_CPU_TO_GPU,
                    .memoryType = MemoryType::CPU_TO_GPU,
                    .debugName = "dear ImGui vertex buffer",
                });
            }

            if (draw_data->TotalIdxCount * sizeof(ImDrawIdx) > device->info(indexBuffer).size) {
                device->destroyBuffer(indexBuffer);
                auto newSize = draw_data->TotalIdxCount * sizeof(ImDrawIdx) + 4096;
                indexBuffer = device->createBuffer({
                    .size = newSize,
                    //.usage = VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
                    //.memoryUsage = VMA_MEMORY_USAGE_CPU_TO_GPU,
                    .memoryType = MemoryType::CPU_TO_GPU,
                    .debugName = "dear ImGui index buffer",
                });
            }
            {
                auto vtx_dst = device->mapMemory(vertexBuffer);
                auto idx_dst = device->mapMemory(indexBuffer);

                for (int n = 0; n < draw_data->CmdListsCount; n++)
                {
                    const ImDrawList* draws = draw_data->CmdLists[n];
                    std::memcpy(vtx_dst.hostPtr, draws->VtxBuffer.Data, draws->VtxBuffer.Size * sizeof(ImDrawVert));
                    std::memcpy(idx_dst.hostPtr, draws->IdxBuffer.Data, draws->IdxBuffer.Size * sizeof(ImDrawIdx));
                    vtx_dst.hostPtr += draws->VtxBuffer.Size * sizeof(ImDrawVert);
                    idx_dst.hostPtr += draws->IdxBuffer.Size * sizeof(ImDrawIdx);
                }
            }
            //--  render command recording --//

            auto colorAttachments = std::array{
                RenderAttachmentInfo{
                    .image = target,
                    .layout = VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR,
                    .loadOp = VK_ATTACHMENT_LOAD_OP_LOAD,
                    .storeOp = VK_ATTACHMENT_STORE_OP_STORE,
                }
            };
            cmdList.beginRendering({
                .colorAttachments = colorAttachments,
            });

            cmdList.bindPipeline(pipeline);

            cmdList.bindVertexBuffer(0, vertexBuffer);

            cmdList.bindIndexBuffer(indexBuffer, 0, VkIndexType::VK_INDEX_TYPE_UINT16);

            {
                float scale[2];
                scale[0] = 2.0f / draw_data->DisplaySize.x;
                scale[1] = 2.0f / draw_data->DisplaySize.y;
                float translate[2];
                translate[0] = -1.0f - draw_data->DisplayPos.x * scale[0];
                translate[1] = -1.0f - draw_data->DisplayPos.y * scale[1];
                cmdList.pushConstant(scale);
                cmdList.pushConstant(translate, sizeof(scale));
                cmdList.pushConstant(samplerId, sizeof(translate) + sizeof(scale));
            }

            ImVec2 clip_off = draw_data->DisplayPos;         // (0,0) unless using multi-viewports
            ImVec2 clip_scale = draw_data->FramebufferScale; // (1,1) unless using retina display which are often (2,2)

            int global_vtx_offset = 0;
            int global_idx_offset = 0;
            for (int n = 0; n < draw_data->CmdListsCount; n++) {
                const ImDrawList* draws = draw_data->CmdLists[n];
                cmdList.pushConstant(fontSheetId, sizeof(u32) * 5);

                for (int cmd_i = 0; cmd_i < draws->CmdBuffer.Size; cmd_i++)  {
                    const ImDrawCmd* pcmd = &draws->CmdBuffer[cmd_i];

                    cmdList.pushConstant(daxa::ImageViewHandle::fromRaw(static_cast<u32>(reinterpret_cast<u64>(pcmd->TextureId))), sizeof(u32) * 5);

                    // Project scissor/clipping rectangles into framebuffer space
                    ImVec2 clip_min((pcmd->ClipRect.x - clip_off.x) * clip_scale.x, (pcmd->ClipRect.y - clip_off.y) * clip_scale.y);
                    ImVec2 clip_max((pcmd->ClipRect.z - clip_off.x) * clip_scale.x, (pcmd->ClipRect.w - clip_off.y) * clip_scale.y);

                    // Clamp to viewport as vkCmdSetScissor() won't accept values that are off bounds
                    if (clip_min.x < 0.0f) { clip_min.x = 0.0f; }
                    if (clip_min.y < 0.0f) { clip_min.y = 0.0f; }
                    if (clip_max.x > device->info(target).image->getVkExtent3D().width) { clip_max.x = (float)device->info(target).image->getVkExtent3D().width; }
                    if (clip_max.y > device->info(target).image->getVkExtent3D().height) { clip_max.y = (float)device->info(target).image->getVkExtent3D().height; }
                    if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y)
                        continue;
                    
                    // Apply scissor/clipping rectangle
                    VkRect2D scissor;
                    scissor.offset.x = (int32_t)(clip_min.x);
                    scissor.offset.y = (int32_t)(clip_min.y);
                    scissor.extent.width = (uint32_t)(clip_max.x - clip_min.x);
                    scissor.extent.height = (uint32_t)(clip_max.y - clip_min.y);

                    cmdList.setScissor(scissor);

                    // Draw
                    cmdList.drawIndexed(pcmd->ElemCount, 1, pcmd->IdxOffset + global_idx_offset, pcmd->VtxOffset + global_vtx_offset, 0);
                }
                global_idx_offset += draws->IdxBuffer.Size;
                global_vtx_offset += draws->VtxBuffer.Size;
            }

            cmdList.endRendering();
            cmdList.unbindPipeline();
            texHandlePtrToReferencedImageIndex.clear();
        }
    }
}