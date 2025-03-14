#pragma once

#if !defined(DAXA_STORAGE_BUFFER_BINDING)
#define DAXA_STORAGE_BUFFER_BINDING 0
#define DAXA_STORAGE_IMAGE_BINDING 1
#define DAXA_SAMPLED_IMAGE_BINDING 2
#define DAXA_SAMPLER_BINDING 3
#define DAXA_BUFFER_DEVICE_ADDRESS_BUFFER_BINDING 4
#define DAXA_ID_INDEX_MASK (0x00FFFFFF)
#endif

typedef uint daxa_u32;
typedef bool daxa_b32;
typedef int daxa_i32;
typedef float daxa_f32;
typedef double daxa_f64;
typedef bool daxa_b32;
typedef bool2 daxa_b32vec2;
typedef bool3 daxa_b32vec3;
typedef bool4 daxa_b32vec4;
typedef float daxa_f32;
typedef double daxa_f64;
typedef float2 daxa_f32vec2;
typedef float2x2 daxa_f32mat2x2;
typedef float2x3 daxa_f32mat2x3;
typedef float2x4 daxa_f32mat2x4;
typedef double2 daxa_f64vec2;
typedef double2x2 daxa_f64mat2x2;
typedef double2x3 daxa_f64mat2x3;
typedef double2x4 daxa_f64mat2x4;
typedef float3 daxa_f32vec3;
typedef float3x2 daxa_f32mat3x2;
typedef float3x3 daxa_f32mat3x3;
typedef float3x4 daxa_f32mat3x4;
typedef double3 daxa_f64vec3;
typedef double3x2 daxa_f64mat3x2;
typedef double3x3 daxa_f64mat3x3;
typedef double3x4 daxa_f64mat3x4;
typedef float4 daxa_f32vec4;
typedef float4x2 daxa_f32mat4x2;
typedef float4x3 daxa_f32mat4x3;
typedef float4x4 daxa_f32mat4x4;
typedef double4 daxa_f64vec4;
typedef double4x2 daxa_f64mat4x2;
typedef double4x3 daxa_f64mat4x3;
typedef double4x4 daxa_f64mat4x4;
typedef float4 daxa_f32vec4;
typedef float4x2 daxa_f32mat4x2;
typedef float4x3 daxa_f32mat4x3;
typedef float4x4 daxa_f32mat4x4;
typedef int daxa_i32;
typedef int2 daxa_i32vec2;
typedef int2x2 daxa_i32mat2x2;
typedef int2x3 daxa_i32mat2x3;
typedef int2x4 daxa_i32mat2x4;
typedef uint2 daxa_u32vec2;
typedef uint2x2 daxa_u32mat2x2;
typedef uint2x3 daxa_u32mat2x3;
typedef uint2x4 daxa_u32mat2x4;
typedef int3 daxa_i32vec3;
typedef int3x2 daxa_i32mat3x2;
typedef int3x3 daxa_i32mat3x3;
typedef int3x4 daxa_i32mat3x4;
typedef uint3 daxa_u32vec3;
typedef uint3x2 daxa_u32mat3x2;
typedef uint3x3 daxa_u32mat3x3;
typedef uint3x4 daxa_u32mat3x4;
typedef int4 daxa_i32vec4;
typedef int4x2 daxa_i32mat4x2;
typedef int4x3 daxa_i32mat4x3;
typedef int4x4 daxa_i32mat4x4;
typedef uint4 daxa_u32vec4;
typedef uint4x2 daxa_u32mat4x2;
typedef uint4x3 daxa_u32mat4x3;
typedef uint4x4 daxa_u32mat4x4;

struct daxa_BufferId
{
    daxa_u32 buffer_id_value;
};

struct daxa_ImageViewId
{
    daxa_u32 image_view_id_value;
};

struct daxa_ImageId
{
    daxa_u32 image_view_id_value;
};

struct daxa_SamplerId
{
    daxa_u32 sampler_id_value;
};

namespace daxa
{
    template <typename T>
    Buffer<T> get_buffer(daxa_BufferId buffer_id);
    template <typename T>
    StructuredBuffer<T> get_StructuredBuffer(daxa_BufferId buffer_id);
    template <typename T>
    RWStructuredBuffer<T> get_RWStructuredBuffer(daxa_BufferId buffer_id);
    template <typename T>
    Texture1D<T> get_texture1D(daxa_ImageViewId image_id);
    template <typename T>
    Texture2D<T> get_texture2D(daxa_ImageViewId image_id);
    template <typename T>
    Texture3D<T> get_texture3D(daxa_ImageViewId image_id);
    template <typename T>
    Texture1DArray<T> get_texture1DArray(daxa_ImageViewId image_id);
    template <typename T>
    Texture2DArray<T> get_texture2DArray(daxa_ImageViewId image_id);
    template <typename T>
    RWTexture1D<T> get_RWTexture1D(daxa_ImageViewId image_id);
    template <typename T>
    RWTexture2D<T> get_RWTexture2D(daxa_ImageViewId image_id);
    template <typename T>
    RWTexture3D<T> get_RWTexture3D(daxa_ImageViewId image_id);

    [[vk::binding(DAXA_SAMPLER_BINDING, 0)]] SamplerState SamplerStateView[];
    SamplerState get_sampler(daxa_SamplerId sampler_id)
    {
        return SamplerStateView[DAXA_ID_INDEX_MASK & sampler_id.sampler_id_value];
    }

    [[vk::binding(DAXA_STORAGE_BUFFER_BINDING, 0)]] ByteAddressBuffer ByteAddressBufferView[];
    ByteAddressBuffer get_ByteAddressBuffer(daxa_BufferId buffer_id)
    {
        return ByteAddressBufferView[DAXA_ID_INDEX_MASK & buffer_id.buffer_id_value];
    }

    [[vk::binding(DAXA_STORAGE_BUFFER_BINDING, 0)]] RWByteAddressBuffer RWByteAddressBufferView[];
    RWByteAddressBuffer get_RWByteAddressBuffer(daxa_BufferId buffer_id)
    {
        return RWByteAddressBufferView[DAXA_ID_INDEX_MASK & buffer_id.buffer_id_value];
    }
} // namespace daxa

#define DAXA_DECL_BUFFER_STRUCT(Type, BODY)                                                                  \
    struct Type BODY;                                                                                        \
    namespace daxa                                                                                           \
    {                                                                                                        \
        [[vk::binding(DAXA_STORAGE_BUFFER_BINDING, 0)]] StructuredBuffer<Type> StructuredBufferView##Type[]; \
        template <>                                                                                          \
        StructuredBuffer<Type> get_StructuredBuffer(daxa_BufferId buffer_id)                                 \
        {                                                                                                    \
            return StructuredBufferView##Type[DAXA_ID_INDEX_MASK & buffer_id.buffer_id_value];               \
        }                                                                                                    \
    }
#define DAXA_DEFINE_GET_RWSTRUCTURED_BUFFER(Type, BODY)                                                          \
    struct Type BODY;                                                                                            \
    namespace daxa                                                                                               \
    {                                                                                                            \
        [[vk::binding(DAXA_STORAGE_BUFFER_BINDING, 0)]] RWStructuredBuffer<Type> RWStructuredBufferView##Type[]; \
        template <>                                                                                              \
        RWStructuredBuffer<Type> get_RWStructuredBuffer(daxa_BufferId buffer_id)                                 \
        {                                                                                                        \
            return RWStructuredBufferView##Type[DAXA_ID_INDEX_MASK & buffer_id.buffer_id_value];                 \
        }                                                                                                        \
    }
#define DAXA_DEFINE_GET_BUFFER(Type, BODY)                                               \
    struct Type BODY;                                                                    \
    namespace daxa                                                                       \
    {                                                                                    \
        [[vk::binding(DAXA_STORAGE_BUFFER_BINDING, 0)]] Buffer<Type> BufferView##Type[]; \
        template <>                                                                      \
        Buffer<Type> get_buffer(daxa_BufferId buffer_id)                                 \
        {                                                                                \
            return BufferView##Type[DAXA_ID_INDEX_MASK & buffer_id.buffer_id_value];     \
        }                                                                                \
    }
#define DAXA_DEFINE_GET_TEXTURE1D(Type)                                                       \
    namespace daxa                                                                            \
    {                                                                                         \
        [[vk::binding(DAXA_SAMPLED_IMAGE_BINDING, 0)]] Texture2D<Type> Texture1DView##Type[]; \
        template <>                                                                           \
        Texture1D<Type> get_texture1D<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                     \
            return Texture1DView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];    \
        }                                                                                     \
    }
#define DAXA_DEFINE_GET_TEXTURE2D(Type)                                                       \
    namespace daxa                                                                            \
    {                                                                                         \
        [[vk::binding(DAXA_SAMPLED_IMAGE_BINDING, 0)]] Texture2D<Type> Texture2DView##Type[]; \
        template <>                                                                           \
        Texture2D<Type> get_texture2D<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                     \
            return Texture2DView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];    \
        }                                                                                     \
    }
#define DAXA_DEFINE_GET_TEXTURE3D(Type)                                                       \
    namespace daxa                                                                            \
    {                                                                                         \
        [[vk::binding(DAXA_SAMPLED_IMAGE_BINDING, 0)]] Texture3D<Type> Texture3DView##Type[]; \
        template <>                                                                           \
        Texture3D<Type> get_texture3D<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                     \
            return Texture3DView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];    \
        }                                                                                     \
    }
#define DAXA_DEFINE_GET_TEXTURE1DARRAY(Type)                                                            \
    namespace daxa                                                                                      \
    {                                                                                                   \
        [[vk::binding(DAXA_SAMPLED_IMAGE_BINDING, 0)]] Texture1DArray<Type> Texture1DArrayView##Type[]; \
        template <>                                                                                     \
        Texture1DArray<Type> get_texture1DArray<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                               \
            return Texture1DArrayView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];         \
        }                                                                                               \
    }
#define DAXA_DEFINE_GET_TEXTURE2DARRAY(Type)                                                            \
    namespace daxa                                                                                      \
    {                                                                                                   \
        [[vk::binding(DAXA_SAMPLED_IMAGE_BINDING, 0)]] Texture2DArray<Type> Texture2DArrayView##Type[]; \
        template <>                                                                                     \
        Texture2DArray<Type> get_texture2DArray<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                               \
            return Texture2DArrayView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];         \
        }                                                                                               \
    }
#define DAXA_DEFINE_GET_RWTEXTURE1D(Type)                                                         \
    namespace daxa                                                                                \
    {                                                                                             \
        [[vk::binding(DAXA_STORAGE_IMAGE_BINDING, 0)]] RWTexture1D<Type> RWTexture1DView##Type[]; \
        template <>                                                                               \
        RWTexture1D<Type> get_RWTexture1D<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                         \
            return RWTexture1DView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];      \
        }                                                                                         \
    }
#define DAXA_DEFINE_GET_RWTEXTURE2D(Type)                                                         \
    namespace daxa                                                                                \
    {                                                                                             \
        [[vk::binding(DAXA_STORAGE_IMAGE_BINDING, 0)]] RWTexture2D<Type> RWTexture2DView##Type[]; \
        template <>                                                                               \
        RWTexture2D<Type> get_RWTexture2D<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                         \
            return RWTexture2DView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];      \
        }                                                                                         \
    }
#define DAXA_DEFINE_GET_RWTEXTURE3D(Type)                                                         \
    namespace daxa                                                                                \
    {                                                                                             \
        [[vk::binding(DAXA_STORAGE_IMAGE_BINDING, 0)]] RWTexture3D<Type> RWTexture3DView##Type[]; \
        template <>                                                                               \
        RWTexture3D<Type> get_RWTexture3D<Type>(daxa_ImageViewId image_id)                        \
        {                                                                                         \
            return RWTexture3DView##Type[DAXA_ID_INDEX_MASK & image_id.image_view_id_value];      \
        }                                                                                         \
    }

DAXA_DEFINE_GET_TEXTURE2D(float)
DAXA_DEFINE_GET_TEXTURE2D(float2)
DAXA_DEFINE_GET_TEXTURE2D(float4)
DAXA_DEFINE_GET_TEXTURE2D(daxa_u32)
DAXA_DEFINE_GET_TEXTURE2D(daxa_u32vec4)

DAXA_DEFINE_GET_RWTEXTURE2D(float)
DAXA_DEFINE_GET_RWTEXTURE2D(float2)
DAXA_DEFINE_GET_RWTEXTURE2D(float4)
DAXA_DEFINE_GET_RWTEXTURE2D(daxa_u32)
DAXA_DEFINE_GET_RWTEXTURE2D(daxa_u32vec4)

#if !defined(DAXA_ENABLE_SHADER_NO_NAMESPACE)
#define DAXA_ENABLE_SHADER_NO_NAMESPACE 0
#endif
#if DAXA_ENABLE_SHADER_NO_NAMESPACE
#define b32vec1 daxa_b32vec1
#define b32vec2 daxa_b32vec2
#define b32vec3 daxa_b32vec3
#define b32vec4 daxa_b32vec4
#define f32 daxa_f32
#define f32vec1 daxa_f32vec1
#define f32vec2 daxa_f32vec2
#define f32mat2x2 daxa_f32mat2x2
#define f32mat2x3 daxa_f32mat2x3
#define f32mat2x4 daxa_f32mat2x4
#define f32vec3 daxa_f32vec3
#define f32mat3x2 daxa_f32mat3x2
#define f32mat3x3 daxa_f32mat3x3
#define f32mat3x4 daxa_f32mat3x4
#define f32vec4 daxa_f32vec4
#define f32mat4x2 daxa_f32mat4x2
#define f32mat4x3 daxa_f32mat4x3
#define f32mat4x4 daxa_f32mat4x4
#define i32 daxa_i32
#define i32vec1 daxa_i32vec1
#define i32vec2 daxa_i32vec2
#define i32vec3 daxa_i32vec3
#define i32vec4 daxa_i32vec4
#define u32 daxa_u32
#define u32vec1 daxa_u32vec1
#define u32vec2 daxa_u32vec2
#define u32vec3 daxa_u32vec3
#define u32vec4 daxa_u32vec4
#define i64 daxa_i64
#define i64vec1 daxa_i64vec1
#define u64 daxa_u64
#define u64vec1 daxa_u64
#endif
