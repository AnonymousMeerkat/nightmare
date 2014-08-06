#ifndef POINTER_C_GENERATED_HEADER_OPENGL_H
#define POINTER_C_GENERATED_HEADER_OPENGL_H

#if defined(__glew_h__) || defined(__GLEW_H__)
#error Attempt to include auto-generated header after including glew.h
#endif
#if defined(__gl_h_) || defined(__GL_H__)
#error Attempt to include auto-generated header after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error Attempt to include auto-generated header after including glext.h
#endif
#if defined(__gltypes_h_)
#error Attempt to include auto-generated header after gltypes.h
#endif
#if defined(__gl_ATI_h_)
#error Attempt to include auto-generated header after including glATI.h
#endif

#define __glew_h__
#define __GLEW_H__
#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gltypes_h_
#define __gl_ATI_h_

#ifndef APIENTRY
	#if defined(__MINGW32__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#else
		#define APIENTRY
	#endif
#endif /*APIENTRY*/

#ifndef CODEGEN_FUNCPTR
	#define CODEGEN_REMOVE_FUNCPTR
	#if defined(_WIN32)
		#define CODEGEN_FUNCPTR APIENTRY
	#else
		#define CODEGEN_FUNCPTR
	#endif
#endif /*CODEGEN_FUNCPTR*/

#ifndef GLAPI
	#define GLAPI extern
#endif


#ifndef GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS
#define GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS


#endif /*GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS*/


#include <stddef.h>
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
	typedef unsigned int GLenum;
	typedef unsigned char GLboolean;
	typedef unsigned int GLbitfield;
	typedef void GLvoid;
	typedef signed char GLbyte;
	typedef short GLshort;
	typedef int GLint;
	typedef unsigned char GLubyte;
	typedef unsigned short GLushort;
	typedef unsigned int GLuint;
	typedef int GLsizei;
	typedef float GLfloat;
	typedef float GLclampf;
	typedef double GLdouble;
	typedef double GLclampd;
	typedef char GLchar;
	typedef char GLcharARB;
	#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
		typedef unsigned short GLhalfARB;
		typedef unsigned short GLhalf;
		typedef GLint GLfixed;
		typedef ptrdiff_t GLintptr;
		typedef ptrdiff_t GLsizeiptr;
		typedef int64_t GLint64;
		typedef uint64_t GLuint64;
		typedef ptrdiff_t GLintptrARB;
		typedef ptrdiff_t GLsizeiptrARB;
		typedef int64_t GLint64EXT;
		typedef uint64_t GLuint64EXT;
		typedef struct __GLsync *GLsync;
		struct _cl_context;
		struct _cl_event;
		typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
		typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
		typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
		typedef unsigned short GLhalfNV;
		typedef GLintptr GLvdpauSurfaceNV;

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

extern int ogl_ext_ARB_imaging;
extern int ogl_ext_ARB_vertex_array_object;
extern int ogl_ext_ARB_texture_rg;
extern int ogl_ext_ARB_texture_compression_rgtc;
extern int ogl_ext_ARB_map_buffer_range;
extern int ogl_ext_ARB_half_float_vertex;
extern int ogl_ext_ARB_framebuffer_sRGB;
extern int ogl_ext_ARB_framebuffer_object;
extern int ogl_ext_ARB_depth_buffer_float;
extern int ogl_ext_ARB_uniform_buffer_object;
extern int ogl_ext_ARB_copy_buffer;
extern int ogl_ext_ARB_depth_clamp;
extern int ogl_ext_ARB_draw_elements_base_vertex;
extern int ogl_ext_ARB_fragment_coord_conventions;
extern int ogl_ext_ARB_provoking_vertex;
extern int ogl_ext_ARB_seamless_cube_map;
extern int ogl_ext_ARB_sync;
extern int ogl_ext_ARB_texture_multisample;
extern int ogl_ext_ARB_vertex_array_bgra;
extern int ogl_ext_ARB_texture_rgb10_a2ui;
extern int ogl_ext_ARB_texture_swizzle;
extern int ogl_ext_ARB_timer_query;
extern int ogl_ext_ARB_vertex_type_2_10_10_10_rev;
extern int ogl_ext_ARB_blend_func_extended;
extern int ogl_ext_ARB_occlusion_query2;
extern int ogl_ext_ARB_sampler_objects;
extern int ogl_ext_ARB_draw_indirect;
extern int ogl_ext_ARB_gpu_shader5;
extern int ogl_ext_ARB_gpu_shader_fp64;
extern int ogl_ext_ARB_shader_subroutine;
extern int ogl_ext_ARB_tessellation_shader;
extern int ogl_ext_ARB_transform_feedback2;
extern int ogl_ext_ARB_transform_feedback3;
extern int ogl_ext_ARB_ES2_compatibility;
extern int ogl_ext_ARB_get_program_binary;
extern int ogl_ext_ARB_separate_shader_objects;
extern int ogl_ext_ARB_vertex_attrib_64bit;
extern int ogl_ext_ARB_viewport_array;
extern int ogl_ext_ARB_base_instance;
extern int ogl_ext_ARB_shading_language_420pack;
extern int ogl_ext_ARB_transform_feedback_instanced;
extern int ogl_ext_ARB_compressed_texture_pixel_storage;
extern int ogl_ext_ARB_conservative_depth;
extern int ogl_ext_ARB_internalformat_query;
extern int ogl_ext_ARB_map_buffer_alignment;
extern int ogl_ext_ARB_shader_atomic_counters;
extern int ogl_ext_ARB_shader_image_load_store;
extern int ogl_ext_ARB_shading_language_packing;
extern int ogl_ext_ARB_texture_storage;
extern int ogl_ext_KHR_debug;
extern int ogl_ext_ARB_arrays_of_arrays;
extern int ogl_ext_ARB_clear_buffer_object;
extern int ogl_ext_ARB_compute_shader;
extern int ogl_ext_ARB_copy_image;
extern int ogl_ext_ARB_ES3_compatibility;
extern int ogl_ext_ARB_explicit_uniform_location;
extern int ogl_ext_ARB_fragment_layer_viewport;
extern int ogl_ext_ARB_framebuffer_no_attachments;
extern int ogl_ext_ARB_internalformat_query2;
extern int ogl_ext_ARB_invalidate_subdata;
extern int ogl_ext_ARB_multi_draw_indirect;
extern int ogl_ext_ARB_program_interface_query;
extern int ogl_ext_ARB_shader_image_size;
extern int ogl_ext_ARB_shader_storage_buffer_object;
extern int ogl_ext_ARB_stencil_texturing;
extern int ogl_ext_ARB_texture_buffer_range;
extern int ogl_ext_ARB_texture_query_levels;
extern int ogl_ext_ARB_texture_storage_multisample;
extern int ogl_ext_ARB_texture_view;
extern int ogl_ext_ARB_vertex_attrib_binding;
extern int ogl_ext_ARB_buffer_storage;
extern int ogl_ext_ARB_clear_texture;
extern int ogl_ext_ARB_enhanced_layouts;
extern int ogl_ext_ARB_multi_bind;
extern int ogl_ext_ARB_query_buffer_object;
extern int ogl_ext_ARB_texture_mirror_clamp_to_edge;
extern int ogl_ext_ARB_texture_stencil8;
extern int ogl_ext_ARB_vertex_type_10f_11f_11f_rev;
extern int ogl_ext_3DFX_multisample;
extern int ogl_ext_3DFX_tbuffer;
extern int ogl_ext_3DFX_texture_compression_FXT1;
extern int ogl_ext_AMD_blend_minmax_factor;
extern int ogl_ext_AMD_conservative_depth;
extern int ogl_ext_AMD_debug_output;
extern int ogl_ext_AMD_depth_clamp_separate;
extern int ogl_ext_AMD_draw_buffers_blend;
extern int ogl_ext_AMD_interleaved_elements;
extern int ogl_ext_AMD_multi_draw_indirect;
extern int ogl_ext_AMD_name_gen_delete;
extern int ogl_ext_AMD_performance_monitor;
extern int ogl_ext_AMD_pinned_memory;
extern int ogl_ext_AMD_query_buffer_object;
extern int ogl_ext_AMD_sample_positions;
extern int ogl_ext_AMD_seamless_cubemap_per_texture;
extern int ogl_ext_AMD_shader_stencil_export;
extern int ogl_ext_AMD_shader_trinary_minmax;
extern int ogl_ext_AMD_sparse_texture;
extern int ogl_ext_AMD_stencil_operation_extended;
extern int ogl_ext_AMD_texture_texture4;
extern int ogl_ext_AMD_transform_feedback3_lines_triangles;
extern int ogl_ext_AMD_vertex_shader_layer;
extern int ogl_ext_AMD_vertex_shader_tessellator;
extern int ogl_ext_AMD_vertex_shader_viewport_index;
extern int ogl_ext_APPLE_aux_depth_stencil;
extern int ogl_ext_APPLE_client_storage;
extern int ogl_ext_APPLE_element_array;
extern int ogl_ext_APPLE_fence;
extern int ogl_ext_APPLE_float_pixels;
extern int ogl_ext_APPLE_flush_buffer_range;
extern int ogl_ext_APPLE_object_purgeable;
extern int ogl_ext_APPLE_rgb_422;
extern int ogl_ext_APPLE_row_bytes;
extern int ogl_ext_APPLE_specular_vector;
extern int ogl_ext_APPLE_texture_range;
extern int ogl_ext_APPLE_transform_hint;
extern int ogl_ext_APPLE_vertex_array_object;
extern int ogl_ext_APPLE_vertex_array_range;
extern int ogl_ext_APPLE_vertex_program_evaluators;
extern int ogl_ext_APPLE_ycbcr_422;
extern int ogl_ext_ARB_bindless_texture;
extern int ogl_ext_ARB_cl_event;
extern int ogl_ext_ARB_color_buffer_float;
extern int ogl_ext_ARB_compatibility;
extern int ogl_ext_ARB_compute_variable_group_size;
extern int ogl_ext_ARB_debug_output;
extern int ogl_ext_ARB_depth_texture;
extern int ogl_ext_ARB_draw_buffers;
extern int ogl_ext_ARB_draw_buffers_blend;
extern int ogl_ext_ARB_draw_instanced;
extern int ogl_ext_ARB_explicit_attrib_location;
extern int ogl_ext_ARB_fragment_program;
extern int ogl_ext_ARB_fragment_program_shadow;
extern int ogl_ext_ARB_fragment_shader;
extern int ogl_ext_ARB_geometry_shader4;
extern int ogl_ext_ARB_half_float_pixel;
extern int ogl_ext_ARB_indirect_parameters;
extern int ogl_ext_ARB_instanced_arrays;
extern int ogl_ext_ARB_matrix_palette;
extern int ogl_ext_ARB_multisample;
extern int ogl_ext_ARB_multitexture;
extern int ogl_ext_ARB_occlusion_query;
extern int ogl_ext_ARB_pixel_buffer_object;
extern int ogl_ext_ARB_point_parameters;
extern int ogl_ext_ARB_point_sprite;
extern int ogl_ext_ARB_robust_buffer_access_behavior;
extern int ogl_ext_ARB_robustness;
extern int ogl_ext_ARB_robustness_isolation;
extern int ogl_ext_ARB_sample_shading;
extern int ogl_ext_ARB_seamless_cubemap_per_texture;
extern int ogl_ext_ARB_shader_bit_encoding;
extern int ogl_ext_ARB_shader_draw_parameters;
extern int ogl_ext_ARB_shader_group_vote;
extern int ogl_ext_ARB_shader_objects;
extern int ogl_ext_ARB_shader_precision;
extern int ogl_ext_ARB_shader_stencil_export;
extern int ogl_ext_ARB_shader_texture_lod;
extern int ogl_ext_ARB_shading_language_100;
extern int ogl_ext_ARB_shading_language_include;
extern int ogl_ext_ARB_shadow;
extern int ogl_ext_ARB_shadow_ambient;
extern int ogl_ext_ARB_sparse_texture;
extern int ogl_ext_ARB_texture_border_clamp;
extern int ogl_ext_ARB_texture_buffer_object;
extern int ogl_ext_ARB_texture_buffer_object_rgb32;
extern int ogl_ext_ARB_texture_compression;
extern int ogl_ext_ARB_texture_compression_bptc;
extern int ogl_ext_ARB_texture_cube_map;
extern int ogl_ext_ARB_texture_cube_map_array;
extern int ogl_ext_ARB_texture_env_add;
extern int ogl_ext_ARB_texture_env_combine;
extern int ogl_ext_ARB_texture_env_crossbar;
extern int ogl_ext_ARB_texture_env_dot3;
extern int ogl_ext_ARB_texture_float;
extern int ogl_ext_ARB_texture_gather;
extern int ogl_ext_ARB_texture_mirrored_repeat;
extern int ogl_ext_ARB_texture_non_power_of_two;
extern int ogl_ext_ARB_texture_query_lod;
extern int ogl_ext_ARB_texture_rectangle;
extern int ogl_ext_ARB_transpose_matrix;
extern int ogl_ext_ARB_vertex_blend;
extern int ogl_ext_ARB_vertex_buffer_object;
extern int ogl_ext_ARB_vertex_program;
extern int ogl_ext_ARB_vertex_shader;
extern int ogl_ext_ARB_window_pos;
extern int ogl_ext_ATI_draw_buffers;
extern int ogl_ext_ATI_element_array;
extern int ogl_ext_ATI_envmap_bumpmap;
extern int ogl_ext_ATI_fragment_shader;
extern int ogl_ext_ATI_map_object_buffer;
extern int ogl_ext_ATI_meminfo;
extern int ogl_ext_ATI_pixel_format_float;
extern int ogl_ext_ATI_pn_triangles;
extern int ogl_ext_ATI_separate_stencil;
extern int ogl_ext_ATI_text_fragment_shader;
extern int ogl_ext_ATI_texture_env_combine3;
extern int ogl_ext_ATI_texture_float;
extern int ogl_ext_ATI_texture_mirror_once;
extern int ogl_ext_ATI_vertex_array_object;
extern int ogl_ext_ATI_vertex_attrib_array_object;
extern int ogl_ext_ATI_vertex_streams;
extern int ogl_ext_EXT_422_pixels;
extern int ogl_ext_EXT_abgr;
extern int ogl_ext_EXT_bgra;
extern int ogl_ext_EXT_bindable_uniform;
extern int ogl_ext_EXT_blend_color;
extern int ogl_ext_EXT_blend_equation_separate;
extern int ogl_ext_EXT_blend_func_separate;
extern int ogl_ext_EXT_blend_logic_op;
extern int ogl_ext_EXT_blend_minmax;
extern int ogl_ext_EXT_blend_subtract;
extern int ogl_ext_EXT_clip_volume_hint;
extern int ogl_ext_EXT_cmyka;
extern int ogl_ext_EXT_color_subtable;
extern int ogl_ext_EXT_compiled_vertex_array;
extern int ogl_ext_EXT_convolution;
extern int ogl_ext_EXT_coordinate_frame;
extern int ogl_ext_EXT_copy_texture;
extern int ogl_ext_EXT_cull_vertex;
extern int ogl_ext_EXT_depth_bounds_test;
extern int ogl_ext_EXT_direct_state_access;
extern int ogl_ext_EXT_draw_buffers2;
extern int ogl_ext_EXT_draw_instanced;
extern int ogl_ext_EXT_draw_range_elements;
extern int ogl_ext_EXT_fog_coord;
extern int ogl_ext_EXT_framebuffer_blit;
extern int ogl_ext_EXT_framebuffer_multisample;
extern int ogl_ext_EXT_framebuffer_multisample_blit_scaled;
extern int ogl_ext_EXT_framebuffer_object;
extern int ogl_ext_EXT_framebuffer_sRGB;
extern int ogl_ext_EXT_geometry_shader4;
extern int ogl_ext_EXT_gpu_program_parameters;
extern int ogl_ext_EXT_gpu_shader4;
extern int ogl_ext_EXT_histogram;
extern int ogl_ext_EXT_index_array_formats;
extern int ogl_ext_EXT_index_func;
extern int ogl_ext_EXT_index_material;
extern int ogl_ext_EXT_index_texture;
extern int ogl_ext_EXT_light_texture;
extern int ogl_ext_EXT_misc_attribute;
extern int ogl_ext_EXT_multi_draw_arrays;
extern int ogl_ext_EXT_multisample;
extern int ogl_ext_EXT_packed_depth_stencil;
extern int ogl_ext_EXT_packed_float;
extern int ogl_ext_EXT_packed_pixels;
extern int ogl_ext_EXT_paletted_texture;
extern int ogl_ext_EXT_pixel_buffer_object;
extern int ogl_ext_EXT_pixel_transform;
extern int ogl_ext_EXT_pixel_transform_color_table;
extern int ogl_ext_EXT_point_parameters;
extern int ogl_ext_EXT_polygon_offset;
extern int ogl_ext_EXT_provoking_vertex;
extern int ogl_ext_EXT_rescale_normal;
extern int ogl_ext_EXT_secondary_color;
extern int ogl_ext_EXT_separate_shader_objects;
extern int ogl_ext_EXT_separate_specular_color;
extern int ogl_ext_EXT_shader_image_load_store;
extern int ogl_ext_EXT_shadow_funcs;
extern int ogl_ext_EXT_shared_texture_palette;
extern int ogl_ext_EXT_stencil_clear_tag;
extern int ogl_ext_EXT_stencil_two_side;
extern int ogl_ext_EXT_stencil_wrap;
extern int ogl_ext_EXT_subtexture;
extern int ogl_ext_EXT_texture;
extern int ogl_ext_EXT_texture3D;
extern int ogl_ext_EXT_texture_array;
extern int ogl_ext_EXT_texture_buffer_object;
extern int ogl_ext_EXT_texture_compression_latc;
extern int ogl_ext_EXT_texture_compression_rgtc;
extern int ogl_ext_EXT_texture_compression_s3tc;
extern int ogl_ext_EXT_texture_cube_map;
extern int ogl_ext_EXT_texture_env_add;
extern int ogl_ext_EXT_texture_env_combine;
extern int ogl_ext_EXT_texture_env_dot3;
extern int ogl_ext_EXT_texture_filter_anisotropic;
extern int ogl_ext_EXT_texture_integer;
extern int ogl_ext_EXT_texture_lod_bias;
extern int ogl_ext_EXT_texture_mirror_clamp;
extern int ogl_ext_EXT_texture_object;
extern int ogl_ext_EXT_texture_perturb_normal;
extern int ogl_ext_EXT_texture_sRGB;
extern int ogl_ext_EXT_texture_sRGB_decode;
extern int ogl_ext_EXT_texture_shared_exponent;
extern int ogl_ext_EXT_texture_snorm;
extern int ogl_ext_EXT_texture_swizzle;
extern int ogl_ext_EXT_timer_query;
extern int ogl_ext_EXT_transform_feedback;
extern int ogl_ext_EXT_vertex_array;
extern int ogl_ext_EXT_vertex_array_bgra;
extern int ogl_ext_EXT_vertex_attrib_64bit;
extern int ogl_ext_EXT_vertex_shader;
extern int ogl_ext_EXT_vertex_weighting;
extern int ogl_ext_EXT_x11_sync_object;
extern int ogl_ext_GREMEDY_frame_terminator;
extern int ogl_ext_GREMEDY_string_marker;
extern int ogl_ext_HP_convolution_border_modes;
extern int ogl_ext_HP_image_transform;
extern int ogl_ext_HP_occlusion_test;
extern int ogl_ext_HP_texture_lighting;
extern int ogl_ext_IBM_cull_vertex;
extern int ogl_ext_IBM_multimode_draw_arrays;
extern int ogl_ext_IBM_rasterpos_clip;
extern int ogl_ext_IBM_static_data;
extern int ogl_ext_IBM_texture_mirrored_repeat;
extern int ogl_ext_IBM_vertex_array_lists;
extern int ogl_ext_INGR_blend_func_separate;
extern int ogl_ext_INGR_color_clamp;
extern int ogl_ext_INGR_interlace_read;
extern int ogl_ext_INTEL_map_texture;
extern int ogl_ext_INTEL_parallel_arrays;
extern int ogl_ext_KHR_texture_compression_astc_ldr;
extern int ogl_ext_MESAX_texture_stack;
extern int ogl_ext_MESA_pack_invert;
extern int ogl_ext_MESA_resize_buffers;
extern int ogl_ext_MESA_window_pos;
extern int ogl_ext_MESA_ycbcr_texture;
extern int ogl_ext_NVX_conditional_render;
extern int ogl_ext_NV_bindless_multi_draw_indirect;
extern int ogl_ext_NV_bindless_texture;
extern int ogl_ext_NV_blend_equation_advanced;
extern int ogl_ext_NV_blend_equation_advanced_coherent;
extern int ogl_ext_NV_blend_square;
extern int ogl_ext_NV_compute_program5;
extern int ogl_ext_NV_conditional_render;
extern int ogl_ext_NV_copy_depth_to_color;
extern int ogl_ext_NV_copy_image;
extern int ogl_ext_NV_deep_texture3D;
extern int ogl_ext_NV_depth_buffer_float;
extern int ogl_ext_NV_depth_clamp;
extern int ogl_ext_NV_draw_texture;
extern int ogl_ext_NV_evaluators;
extern int ogl_ext_NV_explicit_multisample;
extern int ogl_ext_NV_fence;
extern int ogl_ext_NV_float_buffer;
extern int ogl_ext_NV_fog_distance;
extern int ogl_ext_NV_fragment_program;
extern int ogl_ext_NV_fragment_program2;
extern int ogl_ext_NV_fragment_program4;
extern int ogl_ext_NV_fragment_program_option;
extern int ogl_ext_NV_framebuffer_multisample_coverage;
extern int ogl_ext_NV_geometry_program4;
extern int ogl_ext_NV_geometry_shader4;
extern int ogl_ext_NV_gpu_program4;
extern int ogl_ext_NV_gpu_program5;
extern int ogl_ext_NV_gpu_program5_mem_extended;
extern int ogl_ext_NV_gpu_shader5;
extern int ogl_ext_NV_half_float;
extern int ogl_ext_NV_light_max_exponent;
extern int ogl_ext_NV_multisample_coverage;
extern int ogl_ext_NV_multisample_filter_hint;
extern int ogl_ext_NV_occlusion_query;
extern int ogl_ext_NV_packed_depth_stencil;
extern int ogl_ext_NV_parameter_buffer_object;
extern int ogl_ext_NV_parameter_buffer_object2;
extern int ogl_ext_NV_path_rendering;
extern int ogl_ext_NV_pixel_data_range;
extern int ogl_ext_NV_point_sprite;
extern int ogl_ext_NV_present_video;
extern int ogl_ext_NV_primitive_restart;
extern int ogl_ext_NV_register_combiners;
extern int ogl_ext_NV_register_combiners2;
extern int ogl_ext_NV_shader_atomic_counters;
extern int ogl_ext_NV_shader_atomic_float;
extern int ogl_ext_NV_shader_buffer_load;
extern int ogl_ext_NV_shader_buffer_store;
extern int ogl_ext_NV_shader_storage_buffer_object;
extern int ogl_ext_NV_tessellation_program5;
extern int ogl_ext_NV_texgen_emboss;
extern int ogl_ext_NV_texgen_reflection;
extern int ogl_ext_NV_texture_barrier;
extern int ogl_ext_NV_texture_compression_vtc;
extern int ogl_ext_NV_texture_env_combine4;
extern int ogl_ext_NV_texture_expand_normal;
extern int ogl_ext_NV_texture_multisample;
extern int ogl_ext_NV_texture_rectangle;
extern int ogl_ext_NV_texture_shader;
extern int ogl_ext_NV_texture_shader2;
extern int ogl_ext_NV_texture_shader3;
extern int ogl_ext_NV_transform_feedback;
extern int ogl_ext_NV_transform_feedback2;
extern int ogl_ext_NV_vdpau_interop;
extern int ogl_ext_NV_vertex_array_range;
extern int ogl_ext_NV_vertex_array_range2;
extern int ogl_ext_NV_vertex_attrib_integer_64bit;
extern int ogl_ext_NV_vertex_buffer_unified_memory;
extern int ogl_ext_NV_vertex_program;
extern int ogl_ext_NV_vertex_program1_1;
extern int ogl_ext_NV_vertex_program2;
extern int ogl_ext_NV_vertex_program2_option;
extern int ogl_ext_NV_vertex_program3;
extern int ogl_ext_NV_vertex_program4;
extern int ogl_ext_NV_video_capture;
extern int ogl_ext_OES_byte_coordinates;
extern int ogl_ext_OES_compressed_paletted_texture;
extern int ogl_ext_OES_fixed_point;
extern int ogl_ext_OES_query_matrix;
extern int ogl_ext_OES_read_format;
extern int ogl_ext_OES_single_precision;
extern int ogl_ext_OML_interlace;
extern int ogl_ext_OML_resample;
extern int ogl_ext_OML_subsample;
extern int ogl_ext_PGI_misc_hints;
extern int ogl_ext_PGI_vertex_hints;
extern int ogl_ext_REND_screen_coordinates;
extern int ogl_ext_S3_s3tc;
extern int ogl_ext_SGIS_detail_texture;
extern int ogl_ext_SGIS_fog_function;
extern int ogl_ext_SGIS_generate_mipmap;
extern int ogl_ext_SGIS_multisample;
extern int ogl_ext_SGIS_pixel_texture;
extern int ogl_ext_SGIS_point_line_texgen;
extern int ogl_ext_SGIS_point_parameters;
extern int ogl_ext_SGIS_sharpen_texture;
extern int ogl_ext_SGIS_texture4D;
extern int ogl_ext_SGIS_texture_border_clamp;
extern int ogl_ext_SGIS_texture_color_mask;
extern int ogl_ext_SGIS_texture_edge_clamp;
extern int ogl_ext_SGIS_texture_filter4;
extern int ogl_ext_SGIS_texture_lod;
extern int ogl_ext_SGIS_texture_select;
extern int ogl_ext_SGIX_async;
extern int ogl_ext_SGIX_async_histogram;
extern int ogl_ext_SGIX_async_pixel;
extern int ogl_ext_SGIX_blend_alpha_minmax;
extern int ogl_ext_SGIX_calligraphic_fragment;
extern int ogl_ext_SGIX_clipmap;
extern int ogl_ext_SGIX_convolution_accuracy;
extern int ogl_ext_SGIX_depth_pass_instrument;
extern int ogl_ext_SGIX_depth_texture;
extern int ogl_ext_SGIX_flush_raster;
extern int ogl_ext_SGIX_fog_offset;
extern int ogl_ext_SGIX_fragment_lighting;
extern int ogl_ext_SGIX_framezoom;
extern int ogl_ext_SGIX_igloo_interface;
extern int ogl_ext_SGIX_instruments;
extern int ogl_ext_SGIX_interlace;
extern int ogl_ext_SGIX_ir_instrument1;
extern int ogl_ext_SGIX_list_priority;
extern int ogl_ext_SGIX_pixel_texture;
extern int ogl_ext_SGIX_pixel_tiles;
extern int ogl_ext_SGIX_polynomial_ffd;
extern int ogl_ext_SGIX_reference_plane;
extern int ogl_ext_SGIX_resample;
extern int ogl_ext_SGIX_scalebias_hint;
extern int ogl_ext_SGIX_shadow;
extern int ogl_ext_SGIX_shadow_ambient;
extern int ogl_ext_SGIX_sprite;
extern int ogl_ext_SGIX_subsample;
extern int ogl_ext_SGIX_tag_sample_buffer;
extern int ogl_ext_SGIX_texture_add_env;
extern int ogl_ext_SGIX_texture_coordinate_clamp;
extern int ogl_ext_SGIX_texture_lod_bias;
extern int ogl_ext_SGIX_texture_multi_buffer;
extern int ogl_ext_SGIX_texture_scale_bias;
extern int ogl_ext_SGIX_vertex_preclip;
extern int ogl_ext_SGIX_ycrcb;
extern int ogl_ext_SGIX_ycrcb_subsample;
extern int ogl_ext_SGIX_ycrcba;
extern int ogl_ext_SGI_color_matrix;
extern int ogl_ext_SGI_color_table;
extern int ogl_ext_SGI_texture_color_table;
extern int ogl_ext_SUNX_constant_data;
extern int ogl_ext_SUN_convolution_border_modes;
extern int ogl_ext_SUN_global_alpha;
extern int ogl_ext_SUN_mesh_array;
extern int ogl_ext_SUN_slice_accum;
extern int ogl_ext_SUN_triangle_list;
extern int ogl_ext_SUN_vertex;
extern int ogl_ext_WIN_phong_shading;
extern int ogl_ext_WIN_specular_fog;

#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_EQUATION 0x8009
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_COLOR_TABLE 0x80D0
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_CONSTANT_ALPHA 0x8003
#define GL_CONSTANT_BORDER 0x8151
#define GL_CONSTANT_COLOR 0x8001
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_CONVOLUTION_BORDER_COLOR 0x8154
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_HISTOGRAM 0x8024
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_SINK 0x802D
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_MAX 0x8008
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MIN 0x8007
#define GL_MINMAX 0x802E
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_REDUCE 0x8016
#define GL_REPLICATE_BORDER 0x8153
#define GL_SEPARABLE_2D 0x8012
#define GL_TABLE_TOO_LARGE 0x8031

#define GL_VERTEX_ARRAY_BINDING 0x85B5

#define GL_R16 0x822A
#define GL_R16F 0x822D
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32F 0x822E
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_R8 0x8229
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_RG 0x8227
#define GL_RG16 0x822C
#define GL_RG16F 0x822F
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32F 0x8230
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_RG8 0x822B
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG_INTEGER 0x8228

#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE

#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_MAP_WRITE_BIT 0x0002

#define GL_HALF_FLOAT 0x140B

#define GL_FRAMEBUFFER_SRGB 0x8DB9

#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_DEPTH_STENCIL 0x84F9
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER 0x8D40
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_INDEX 0x8222
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_MAX_SAMPLES 0x8D57
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX16 0x8D49
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_UNSIGNED_NORMALIZED 0x8C17

#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD

#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_TYPE 0x8A37

#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37

#define GL_DEPTH_CLAMP 0x864F

#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C

#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F

#define GL_ALREADY_SIGNALED 0x911A
#define GL_CONDITION_SATISFIED 0x911C
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SIGNALED 0x9119
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_SYNC_STATUS 0x9114
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_UNSIGNALED 0x9118
#define GL_WAIT_FAILED 0x911D

#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_SAMPLE_POSITION 0x8E50
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D

#define GL_BGRA 0x80E1

#define GL_RGB10_A2UI 0x906F

#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46

#define GL_TIMESTAMP 0x8E28
#define GL_TIME_ELAPSED 0x88BF

#define GL_INT_2_10_10_10_REV 0x8D9F
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368

#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_SRC1_ALPHA 0x8589
#define GL_SRC1_COLOR 0x88F9

#define GL_ANY_SAMPLES_PASSED 0x8C2F

#define GL_SAMPLER_BINDING 0x8919

#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43

#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B

#define GL_DOUBLE 0x140A
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE

#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
/*Copied GL_UNIFORM_NAME_LENGTH From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_SIZE From: ARB_uniform_buffer_object*/

#define GL_CCW 0x0901
#define GL_CW 0x0900
#define GL_EQUAL 0x0202
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_ISOLINES 0x8E7A
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_PATCHES 0x000E
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_PATCH_VERTICES 0x8E72
#define GL_QUADS 0x0007
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TRIANGLES 0x0004
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1

#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23

#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
/*Copied GL_MAX_VERTEX_STREAMS From: ARB_gpu_shader5*/

#define GL_FIXED 0x140C
#define GL_HIGH_FLOAT 0x8DF2
#define GL_HIGH_INT 0x8DF5
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_LOW_FLOAT 0x8DF0
#define GL_LOW_INT 0x8DF3
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_MEDIUM_INT 0x8DF4
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_RGB565 0x8D62
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_SHADER_COMPILER 0x8DFA

#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257

#define GL_ACTIVE_PROGRAM 0x8259
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_VERTEX_SHADER_BIT 0x00000001

/*Copied GL_DOUBLE_MAT2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT2x3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT2x4 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT3x2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT3x4 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT4 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT4x2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_MAT4x3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_VEC2 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_VEC3 From: ARB_gpu_shader_fp64*/
/*Copied GL_DOUBLE_VEC4 From: ARB_gpu_shader_fp64*/
#define GL_RGB32I 0x8D83

#define GL_DEPTH_RANGE 0x0B70
/*Copied GL_FIRST_VERTEX_CONVENTION From: ARB_provoking_vertex*/
/*Copied GL_LAST_VERTEX_CONVENTION From: ARB_provoking_vertex*/
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_MAX_VIEWPORTS 0x825B
/*Copied GL_PROVOKING_VERTEX From: ARB_provoking_vertex*/
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_VIEWPORT 0x0BA2
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C

#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127

#define GL_NUM_SAMPLE_COUNTS 0x9380

#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC

#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB

#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001

#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F

#define GL_BUFFER 0x82E0
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_DISPLAY_LIST 0x82E7
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_PROGRAM 0x82E2
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_QUERY 0x82E3
#define GL_SAMPLER 0x82E6
#define GL_SHADER 0x82E1
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_VERTEX_ARRAY 0x8074

#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_COMPUTE_LOCAL_WORK_SIZE 0x8267
#define GL_COMPUTE_SHADER 0x91B9
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_LOCAL_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC

#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69

#define GL_MAX_UNIFORM_LOCATIONS 0x826E

#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315

#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_CLEAR_BUFFER 0x82B4
#define GL_COLOR_COMPONENTS 0x8283
#define GL_COLOR_ENCODING 0x8296
#define GL_COLOR_RENDERABLE 0x8286
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_FILTER 0x829A
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FULL_SUPPORT 0x82B7
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_TYPE From: ARB_shader_image_load_store*/
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_WIDTH 0x827E
#define GL_MIPMAP 0x8293
/*Copied GL_NUM_SAMPLE_COUNTS From: ARB_internalformat_query*/
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
/*Copied GL_RENDERBUFFER From: ARB_framebuffer_object*/
#define GL_SAMPLES 0x80A9
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_SRGB_DECODE_ARB 0x8299
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_2D_ARRAY 0x8C1A
/*Copied GL_TEXTURE_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
#define GL_TEXTURE_3D 0x806F
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VERTEX_TEXTURE 0x829B
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6

#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_ARRAY_SIZE 0x92FB
#define GL_ARRAY_STRIDE 0x92FE
/*Copied GL_ATOMIC_COUNTER_BUFFER From: ARB_shader_atomic_counters*/
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BLOCK_INDEX 0x92FD
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_BUFFER_VARIABLE 0x92E5
/*Copied GL_COMPATIBLE_SUBROUTINES From: ARB_shader_subroutine*/
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_IS_PER_PATCH 0x92E7
#define GL_IS_ROW_MAJOR 0x9300
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F
#define GL_MATRIX_STRIDE 0x92FF
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_NUM_ACTIVE_VARIABLES 0x9304
/*Copied GL_NUM_COMPATIBLE_SUBROUTINES From: ARB_shader_subroutine*/
#define GL_OFFSET 0x92FC
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_TYPE 0x92FA
#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE

/*Copied GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS From: ARB_shader_image_load_store*/
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4

#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA

#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_BUFFER_SIZE 0x919E

#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC

#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8

#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_BUFFER_STORAGE_FLAGS 0x8220
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_MAP_COHERENT_BIT 0x0080
#define GL_MAP_PERSISTENT_BIT 0x0040
/*Copied GL_MAP_READ_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_WRITE_BIT From: ARB_map_buffer_range*/

#define GL_CLEAR_TEXTURE 0x9365

#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C

#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194

#define GL_MIRROR_CLAMP_TO_EDGE 0x8743

#define GL_STENCIL_INDEX 0x1901
/*Copied GL_STENCIL_INDEX8 From: ARB_framebuffer_object*/

#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B

#define GL_MULTISAMPLE_3DFX 0x86B2
#define GL_MULTISAMPLE_BIT_3DFX 0x20000000
#define GL_SAMPLES_3DFX 0x86B4
#define GL_SAMPLE_BUFFERS_3DFX 0x86B3

#define GL_COMPRESSED_RGBA_FXT1_3DFX 0x86B1
#define GL_COMPRESSED_RGB_FXT1_3DFX 0x86B0

#define GL_FACTOR_MAX_AMD 0x901D
#define GL_FACTOR_MIN_AMD 0x901C

#define GL_DEBUG_CATEGORY_API_ERROR_AMD 0x9149
#define GL_DEBUG_CATEGORY_APPLICATION_AMD 0x914F
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD 0x914B
#define GL_DEBUG_CATEGORY_OTHER_AMD 0x9150
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD 0x914D
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD 0x914E
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD 0x914C
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD 0x914A
#define GL_DEBUG_LOGGED_MESSAGES_AMD 0x9145
#define GL_DEBUG_SEVERITY_HIGH_AMD 0x9146
#define GL_DEBUG_SEVERITY_LOW_AMD 0x9148
#define GL_DEBUG_SEVERITY_MEDIUM_AMD 0x9147
#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD 0x9144
#define GL_MAX_DEBUG_MESSAGE_LENGTH_AMD 0x9143

#define GL_DEPTH_CLAMP_FAR_AMD 0x901F
#define GL_DEPTH_CLAMP_NEAR_AMD 0x901E

#define GL_ALPHA 0x1906
#define GL_BLUE 0x1905
#define GL_GREEN 0x1904
#define GL_RED 0x1903
/*Copied GL_RG16UI From: ARB_texture_rg*/
/*Copied GL_RG8UI From: ARB_texture_rg*/
#define GL_RGBA8UI 0x8D7C
#define GL_VERTEX_ELEMENT_SWIZZLE_AMD 0x91A4
#define GL_VERTEX_ID_SWIZZLE_AMD 0x91A5

#define GL_DATA_BUFFER_AMD 0x9151
#define GL_PERFORMANCE_MONITOR_AMD 0x9152
#define GL_QUERY_OBJECT_AMD 0x9153
#define GL_SAMPLER_OBJECT_AMD 0x9155
#define GL_VERTEX_ARRAY_OBJECT_AMD 0x9154

#define GL_COUNTER_RANGE_AMD 0x8BC1
#define GL_COUNTER_TYPE_AMD 0x8BC0
#define GL_PERCENTAGE_AMD 0x8BC3
#define GL_PERFMON_RESULT_AMD 0x8BC6
#define GL_PERFMON_RESULT_AVAILABLE_AMD 0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD 0x8BC5
#define GL_UNSIGNED_INT64_AMD 0x8BC2

#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD 0x9160

#define GL_QUERY_BUFFER_AMD 0x9192
#define GL_QUERY_BUFFER_BINDING_AMD 0x9193
#define GL_QUERY_RESULT_NO_WAIT_AMD 0x9194

#define GL_SUBSAMPLE_DISTANCE_AMD 0x883F

/*Copied GL_TEXTURE_CUBE_MAP_SEAMLESS From: ARB_seamless_cube_map*/

#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS 0x919A
#define GL_MAX_SPARSE_TEXTURE_SIZE_AMD 0x9198
#define GL_MIN_LOD_WARNING_AMD 0x919C
#define GL_MIN_SPARSE_LEVEL_AMD 0x919B
#define GL_TEXTURE_STORAGE_SPARSE_BIT_AMD 0x00000001
#define GL_VIRTUAL_PAGE_SIZE_X_AMD 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_AMD 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_AMD 0x9197

#define GL_REPLACE_VALUE_AMD 0x874B
#define GL_SET_AMD 0x874A
#define GL_STENCIL_BACK_OP_VALUE_AMD 0x874D
#define GL_STENCIL_OP_VALUE_AMD 0x874C

#define GL_CONTINUOUS_AMD 0x9007
#define GL_DISCRETE_AMD 0x9006
#define GL_INT_SAMPLER_BUFFER_AMD 0x9002
#define GL_SAMPLER_BUFFER_AMD 0x9001
#define GL_TESSELLATION_FACTOR_AMD 0x9005
#define GL_TESSELLATION_MODE_AMD 0x9004
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD 0x9003

#define GL_AUX_DEPTH_STENCIL_APPLE 0x8A14

#define GL_UNPACK_CLIENT_STORAGE_APPLE 0x85B2

#define GL_ELEMENT_ARRAY_APPLE 0x8A0C
#define GL_ELEMENT_ARRAY_POINTER_APPLE 0x8A0E
#define GL_ELEMENT_ARRAY_TYPE_APPLE 0x8A0D

#define GL_DRAW_PIXELS_APPLE 0x8A0A
#define GL_FENCE_APPLE 0x8A0B

#define GL_ALPHA_FLOAT16_APPLE 0x881C
#define GL_ALPHA_FLOAT32_APPLE 0x8816
#define GL_COLOR_FLOAT_APPLE 0x8A0F
#define GL_HALF_APPLE 0x140B
#define GL_INTENSITY_FLOAT16_APPLE 0x881D
#define GL_INTENSITY_FLOAT32_APPLE 0x8817
#define GL_LUMINANCE_ALPHA_FLOAT16_APPLE 0x881F
#define GL_LUMINANCE_ALPHA_FLOAT32_APPLE 0x8819
#define GL_LUMINANCE_FLOAT16_APPLE 0x881E
#define GL_LUMINANCE_FLOAT32_APPLE 0x8818
#define GL_RGBA_FLOAT16_APPLE 0x881A
#define GL_RGBA_FLOAT32_APPLE 0x8814
#define GL_RGB_FLOAT16_APPLE 0x881B
#define GL_RGB_FLOAT32_APPLE 0x8815

#define GL_BUFFER_FLUSHING_UNMAP_APPLE 0x8A13
#define GL_BUFFER_SERIALIZED_MODIFY_APPLE 0x8A12

#define GL_BUFFER_OBJECT_APPLE 0x85B3
#define GL_PURGEABLE_APPLE 0x8A1D
#define GL_RELEASED_APPLE 0x8A19
#define GL_RETAINED_APPLE 0x8A1B
#define GL_UNDEFINED_APPLE 0x8A1C
#define GL_VOLATILE_APPLE 0x8A1A

#define GL_RGB_422_APPLE 0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB

#define GL_PACK_ROW_BYTES_APPLE 0x8A15
#define GL_UNPACK_ROW_BYTES_APPLE 0x8A16

#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE 0x85B0

#define GL_STORAGE_CACHED_APPLE 0x85BE
#define GL_STORAGE_PRIVATE_APPLE 0x85BD
#define GL_STORAGE_SHARED_APPLE 0x85BF
#define GL_TEXTURE_RANGE_LENGTH_APPLE 0x85B7
#define GL_TEXTURE_RANGE_POINTER_APPLE 0x85B8
#define GL_TEXTURE_STORAGE_HINT_APPLE 0x85BC

#define GL_TRANSFORM_HINT_APPLE 0x85B1

#define GL_VERTEX_ARRAY_BINDING_APPLE 0x85B5

/*Copied GL_STORAGE_CACHED_APPLE From: APPLE_texture_range*/
#define GL_STORAGE_CLIENT_APPLE 0x85B4
/*Copied GL_STORAGE_SHARED_APPLE From: APPLE_texture_range*/
#define GL_VERTEX_ARRAY_RANGE_APPLE 0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE 0x851E
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE 0x8521
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE 0x851F

#define GL_VERTEX_ATTRIB_MAP1_APPLE 0x8A00
#define GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE 0x8A03
#define GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE 0x8A05
#define GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE 0x8A04
#define GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE 0x8A02
#define GL_VERTEX_ATTRIB_MAP2_APPLE 0x8A01
#define GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE 0x8A07
#define GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE 0x8A09
#define GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE 0x8A08
#define GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE 0x8A06

/*Copied GL_UNSIGNED_SHORT_8_8_APPLE From: APPLE_rgb_422*/
/*Copied GL_UNSIGNED_SHORT_8_8_REV_APPLE From: APPLE_rgb_422*/
#define GL_YCBCR_422_APPLE 0x85B9

#define GL_UNSIGNED_INT64_ARB 0x140F

#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241

#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_FIXED_ONLY_ARB 0x891D
#define GL_RGBA_FLOAT_MODE_ARB 0x8820

#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345

#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143

#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A

#define GL_DRAW_BUFFER0_ARB 0x8825
#define GL_DRAW_BUFFER10_ARB 0x882F
#define GL_DRAW_BUFFER11_ARB 0x8830
#define GL_DRAW_BUFFER12_ARB 0x8831
#define GL_DRAW_BUFFER13_ARB 0x8832
#define GL_DRAW_BUFFER14_ARB 0x8833
#define GL_DRAW_BUFFER15_ARB 0x8834
#define GL_DRAW_BUFFER1_ARB 0x8826
#define GL_DRAW_BUFFER2_ARB 0x8827
#define GL_DRAW_BUFFER3_ARB 0x8828
#define GL_DRAW_BUFFER4_ARB 0x8829
#define GL_DRAW_BUFFER5_ARB 0x882A
#define GL_DRAW_BUFFER6_ARB 0x882B
#define GL_DRAW_BUFFER7_ARB 0x882C
#define GL_DRAW_BUFFER8_ARB 0x882D
#define GL_DRAW_BUFFER9_ARB 0x882E
#define GL_MAX_DRAW_BUFFERS_ARB 0x8824

#define GL_CURRENT_MATRIX_ARB 0x8641
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_MATRIX0_ARB 0x88C0
#define GL_MATRIX10_ARB 0x88CA
#define GL_MATRIX11_ARB 0x88CB
#define GL_MATRIX12_ARB 0x88CC
#define GL_MATRIX13_ARB 0x88CD
#define GL_MATRIX14_ARB 0x88CE
#define GL_MATRIX15_ARB 0x88CF
#define GL_MATRIX16_ARB 0x88D0
#define GL_MATRIX17_ARB 0x88D1
#define GL_MATRIX18_ARB 0x88D2
#define GL_MATRIX19_ARB 0x88D3
#define GL_MATRIX1_ARB 0x88C1
#define GL_MATRIX20_ARB 0x88D4
#define GL_MATRIX21_ARB 0x88D5
#define GL_MATRIX22_ARB 0x88D6
#define GL_MATRIX23_ARB 0x88D7
#define GL_MATRIX24_ARB 0x88D8
#define GL_MATRIX25_ARB 0x88D9
#define GL_MATRIX26_ARB 0x88DA
#define GL_MATRIX27_ARB 0x88DB
#define GL_MATRIX28_ARB 0x88DC
#define GL_MATRIX29_ARB 0x88DD
#define GL_MATRIX2_ARB 0x88C2
#define GL_MATRIX30_ARB 0x88DE
#define GL_MATRIX31_ARB 0x88DF
#define GL_MATRIX3_ARB 0x88C3
#define GL_MATRIX4_ARB 0x88C4
#define GL_MATRIX5_ARB 0x88C5
#define GL_MATRIX6_ARB 0x88C6
#define GL_MATRIX7_ARB 0x88C7
#define GL_MATRIX8_ARB 0x88C8
#define GL_MATRIX9_ARB 0x88C9
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_ATTRIBS_ARB 0x88AD
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB 0x88A1
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_MATRICES_ARB 0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_PARAMETERS_ARB 0x88A9
#define GL_MAX_PROGRAM_TEMPORARIES_ARB 0x88A5
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_PROGRAM_ATTRIBS_ARB 0x88AC
#define GL_PROGRAM_BINDING_ARB 0x8677
#define GL_PROGRAM_ERROR_POSITION_ARB 0x864B
#define GL_PROGRAM_ERROR_STRING_ARB 0x8874
#define GL_PROGRAM_FORMAT_ARB 0x8876
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#define GL_PROGRAM_INSTRUCTIONS_ARB 0x88A0
#define GL_PROGRAM_LENGTH_ARB 0x8627
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AE
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AA
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_PARAMETERS_ARB 0x88A8
#define GL_PROGRAM_STRING_ARB 0x8628
#define GL_PROGRAM_TEMPORARIES_ARB 0x88A4
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB 0x88B7

#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49

#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER From: ARB_framebuffer_object*/
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D

#define GL_HALF_FLOAT_ARB 0x140B

#define GL_PARAMETER_BUFFER_ARB 0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB 0x80EF

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE

#define GL_CURRENT_MATRIX_INDEX_ARB 0x8845
#define GL_CURRENT_PALETTE_MATRIX_ARB 0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB 0x8844
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB 0x8849
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB 0x8846
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB 0x8848
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB 0x8847
#define GL_MATRIX_PALETTE_ARB 0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB 0x8841
#define GL_MAX_PALETTE_MATRICES_ARB 0x8842

#define GL_MULTISAMPLE_ARB 0x809D
#define GL_MULTISAMPLE_BIT_ARB 0x20000000
#define GL_SAMPLES_ARB 0x80A9
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB 0x809F
#define GL_SAMPLE_BUFFERS_ARB 0x80A8
#define GL_SAMPLE_COVERAGE_ARB 0x80A0
#define GL_SAMPLE_COVERAGE_INVERT_ARB 0x80AB
#define GL_SAMPLE_COVERAGE_VALUE_ARB 0x80AA

#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2
#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE10_ARB 0x84CA
#define GL_TEXTURE11_ARB 0x84CB
#define GL_TEXTURE12_ARB 0x84CC
#define GL_TEXTURE13_ARB 0x84CD
#define GL_TEXTURE14_ARB 0x84CE
#define GL_TEXTURE15_ARB 0x84CF
#define GL_TEXTURE16_ARB 0x84D0
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TEXTURE18_ARB 0x84D2
#define GL_TEXTURE19_ARB 0x84D3
#define GL_TEXTURE1_ARB 0x84C1
#define GL_TEXTURE20_ARB 0x84D4
#define GL_TEXTURE21_ARB 0x84D5
#define GL_TEXTURE22_ARB 0x84D6
#define GL_TEXTURE23_ARB 0x84D7
#define GL_TEXTURE24_ARB 0x84D8
#define GL_TEXTURE25_ARB 0x84D9
#define GL_TEXTURE26_ARB 0x84DA
#define GL_TEXTURE27_ARB 0x84DB
#define GL_TEXTURE28_ARB 0x84DC
#define GL_TEXTURE29_ARB 0x84DD
#define GL_TEXTURE2_ARB 0x84C2
#define GL_TEXTURE30_ARB 0x84DE
#define GL_TEXTURE31_ARB 0x84DF
#define GL_TEXTURE3_ARB 0x84C3
#define GL_TEXTURE4_ARB 0x84C4
#define GL_TEXTURE5_ARB 0x84C5
#define GL_TEXTURE6_ARB 0x84C6
#define GL_TEXTURE7_ARB 0x84C7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_TEXTURE9_ARB 0x84C9

#define GL_CURRENT_QUERY_ARB 0x8865
#define GL_QUERY_COUNTER_BITS_ARB 0x8864
#define GL_QUERY_RESULT_ARB 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB 0x8867
#define GL_SAMPLES_PASSED_ARB 0x8914

#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF

#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB 0x8128
#define GL_POINT_SIZE_MAX_ARB 0x8127
#define GL_POINT_SIZE_MIN_ARB 0x8126

#define GL_COORD_REPLACE_ARB 0x8862
#define GL_POINT_SPRITE_ARB 0x8861

#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_NO_ERROR 0
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255

#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37
#define GL_SAMPLE_SHADING_ARB 0x8C36

/*Copied GL_TEXTURE_CUBE_MAP_SEAMLESS From: AMD_seamless_cubemap_per_texture*/

#define GL_BOOL_ARB 0x8B56
#define GL_BOOL_VEC2_ARB 0x8B57
#define GL_BOOL_VEC3_ARB 0x8B58
#define GL_BOOL_VEC4_ARB 0x8B59
#define GL_FLOAT_MAT2_ARB 0x8B5A
#define GL_FLOAT_MAT3_ARB 0x8B5B
#define GL_FLOAT_MAT4_ARB 0x8B5C
#define GL_FLOAT_VEC2_ARB 0x8B50
#define GL_FLOAT_VEC3_ARB 0x8B51
#define GL_FLOAT_VEC4_ARB 0x8B52
#define GL_INT_VEC2_ARB 0x8B53
#define GL_INT_VEC3_ARB 0x8B54
#define GL_INT_VEC4_ARB 0x8B55
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB 0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_ATTACHED_OBJECTS_ARB 0x8B85
#define GL_OBJECT_COMPILE_STATUS_ARB 0x8B81
#define GL_OBJECT_DELETE_STATUS_ARB 0x8B80
#define GL_OBJECT_INFO_LOG_LENGTH_ARB 0x8B84
#define GL_OBJECT_LINK_STATUS_ARB 0x8B82
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88
#define GL_OBJECT_SUBTYPE_ARB 0x8B4F
#define GL_OBJECT_TYPE_ARB 0x8B4E
#define GL_OBJECT_VALIDATE_STATUS_ARB 0x8B83
#define GL_PROGRAM_OBJECT_ARB 0x8B40
#define GL_SAMPLER_1D_ARB 0x8B5D
#define GL_SAMPLER_1D_SHADOW_ARB 0x8B61
#define GL_SAMPLER_2D_ARB 0x8B5E
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64
#define GL_SAMPLER_2D_SHADOW_ARB 0x8B62
#define GL_SAMPLER_3D_ARB 0x8B5F
#define GL_SAMPLER_CUBE_ARB 0x8B60
#define GL_SHADER_OBJECT_ARB 0x8B48

#define GL_SHADING_LANGUAGE_VERSION_ARB 0x8B8C

#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA
#define GL_SHADER_INCLUDE_ARB 0x8DAE

#define GL_COMPARE_R_TO_TEXTURE_ARB 0x884E
#define GL_TEXTURE_COMPARE_FUNC_ARB 0x884D
#define GL_TEXTURE_COMPARE_MODE_ARB 0x884C

#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF

#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB 0x9198
#define GL_MIN_SPARSE_LEVEL_ARB 0x919B
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB 0x91A8
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
#define GL_TEXTURE_SPARSE_ARB 0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB 0x91A7
#define GL_VIRTUAL_PAGE_SIZE_X_ARB 0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB 0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB 0x9197

#define GL_CLAMP_TO_BORDER_ARB 0x812D

#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E

#define GL_RGB32F 0x8815
/*Copied GL_RGB32I From: ARB_vertex_attrib_64bit*/
#define GL_RGB32UI 0x8D71

#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF

#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D

#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB 0x851C
#define GL_NORMAL_MAP_ARB 0x8511
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB 0x851B
#define GL_REFLECTION_MAP_ARB 0x8512
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#define GL_TEXTURE_CUBE_MAP_ARB 0x8513
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519

#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F

#define GL_ADD_SIGNED_ARB 0x8574
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_COMBINE_ARB 0x8570
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_CONSTANT_ARB 0x8576
#define GL_INTERPOLATE_ARB 0x8575
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_OPERAND2_ALPHA_ARB 0x859A
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_PREVIOUS_ARB 0x8578
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_RGB_SCALE_ARB 0x8573
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_SUBTRACT_ARB 0x84E7

#define GL_DOT3_RGBA_ARB 0x86AF
#define GL_DOT3_RGB_ARB 0x86AE

#define GL_ALPHA16F_ARB 0x881C
#define GL_ALPHA32F_ARB 0x8816
#define GL_INTENSITY16F_ARB 0x881D
#define GL_INTENSITY32F_ARB 0x8817
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_RGB16F_ARB 0x881B
#define GL_RGB32F_ARB 0x8815
#define GL_RGBA16F_ARB 0x881A
#define GL_RGBA32F_ARB 0x8814
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17

#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E

#define GL_MIRRORED_REPEAT_ARB 0x8370

#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5

#define GL_TRANSPOSE_COLOR_MATRIX_ARB 0x84E6
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB 0x84E5

#define GL_ACTIVE_VERTEX_UNITS_ARB 0x86A5
#define GL_CURRENT_WEIGHT_ARB 0x86A8
#define GL_MAX_VERTEX_UNITS_ARB 0x86A4
#define GL_MODELVIEW0_ARB 0x1700
#define GL_MODELVIEW10_ARB 0x872A
#define GL_MODELVIEW11_ARB 0x872B
#define GL_MODELVIEW12_ARB 0x872C
#define GL_MODELVIEW13_ARB 0x872D
#define GL_MODELVIEW14_ARB 0x872E
#define GL_MODELVIEW15_ARB 0x872F
#define GL_MODELVIEW16_ARB 0x8730
#define GL_MODELVIEW17_ARB 0x8731
#define GL_MODELVIEW18_ARB 0x8732
#define GL_MODELVIEW19_ARB 0x8733
#define GL_MODELVIEW1_ARB 0x850A
#define GL_MODELVIEW20_ARB 0x8734
#define GL_MODELVIEW21_ARB 0x8735
#define GL_MODELVIEW22_ARB 0x8736
#define GL_MODELVIEW23_ARB 0x8737
#define GL_MODELVIEW24_ARB 0x8738
#define GL_MODELVIEW25_ARB 0x8739
#define GL_MODELVIEW26_ARB 0x873A
#define GL_MODELVIEW27_ARB 0x873B
#define GL_MODELVIEW28_ARB 0x873C
#define GL_MODELVIEW29_ARB 0x873D
#define GL_MODELVIEW2_ARB 0x8722
#define GL_MODELVIEW30_ARB 0x873E
#define GL_MODELVIEW31_ARB 0x873F
#define GL_MODELVIEW3_ARB 0x8723
#define GL_MODELVIEW4_ARB 0x8724
#define GL_MODELVIEW5_ARB 0x8725
#define GL_MODELVIEW6_ARB 0x8726
#define GL_MODELVIEW7_ARB 0x8727
#define GL_MODELVIEW8_ARB 0x8728
#define GL_MODELVIEW9_ARB 0x8729
#define GL_VERTEX_BLEND_ARB 0x86A7
#define GL_WEIGHT_ARRAY_ARB 0x86AD
#define GL_WEIGHT_ARRAY_POINTER_ARB 0x86AC
#define GL_WEIGHT_ARRAY_SIZE_ARB 0x86AB
#define GL_WEIGHT_ARRAY_STRIDE_ARB 0x86AA
#define GL_WEIGHT_ARRAY_TYPE_ARB 0x86A9
#define GL_WEIGHT_SUM_UNITY_ARB 0x86A6

#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_ARRAY_BUFFER_BINDING_ARB 0x8894
#define GL_BUFFER_ACCESS_ARB 0x88BB
#define GL_BUFFER_MAPPED_ARB 0x88BC
#define GL_BUFFER_MAP_POINTER_ARB 0x88BD
#define GL_BUFFER_SIZE_ARB 0x8764
#define GL_BUFFER_USAGE_ARB 0x8765
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_DYNAMIC_COPY_ARB 0x88EA
#define GL_DYNAMIC_DRAW_ARB 0x88E8
#define GL_DYNAMIC_READ_ARB 0x88E9
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_READ_ONLY_ARB 0x88B8
#define GL_READ_WRITE_ARB 0x88BA
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_STATIC_COPY_ARB 0x88E6
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_STATIC_READ_ARB 0x88E5
#define GL_STREAM_COPY_ARB 0x88E2
#define GL_STREAM_DRAW_ARB 0x88E0
#define GL_STREAM_READ_ARB 0x88E1
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_WRITE_ONLY_ARB 0x88B9

#define GL_COLOR_SUM_ARB 0x8458
/*Copied GL_CURRENT_MATRIX_ARB From: ARB_fragment_program*/
/*Copied GL_CURRENT_MATRIX_STACK_DEPTH_ARB From: ARB_fragment_program*/
#define GL_CURRENT_VERTEX_ATTRIB_ARB 0x8626
/*Copied GL_MATRIX0_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX10_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX11_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX12_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX13_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX14_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX15_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX16_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX17_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX18_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX19_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX1_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX20_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX21_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX22_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX23_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX24_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX25_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX26_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX27_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX28_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX29_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX2_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX30_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX31_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX3_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX4_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX5_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX6_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX7_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX8_ARB From: ARB_fragment_program*/
/*Copied GL_MATRIX9_ARB From: ARB_fragment_program*/
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
/*Copied GL_MAX_PROGRAM_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_ENV_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_MATRICES_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB From: ARB_fragment_program*/
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
/*Copied GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_MAX_PROGRAM_TEMPORARIES_ARB From: ARB_fragment_program*/
#define GL_MAX_VERTEX_ATTRIBS_ARB 0x8869
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B0
/*Copied GL_PROGRAM_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_BINDING_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_ERROR_POSITION_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_ERROR_STRING_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_FORMAT_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_FORMAT_ASCII_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_LENGTH_ARB From: ARB_fragment_program*/
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
/*Copied GL_PROGRAM_NATIVE_ATTRIBS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_NATIVE_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_NATIVE_TEMPORARIES_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_PARAMETERS_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_STRING_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_TEMPORARIES_ARB From: ARB_fragment_program*/
/*Copied GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB From: ARB_fragment_program*/
/*Copied GL_TRANSPOSE_CURRENT_MATRIX_ARB From: ARB_fragment_program*/
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB 0x8625
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB 0x8643

#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_MAX_VARYING_FLOATS_ARB 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB 0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A
#define GL_VERTEX_SHADER_ARB 0x8B31

#define GL_DRAW_BUFFER0_ATI 0x8825
#define GL_DRAW_BUFFER10_ATI 0x882F
#define GL_DRAW_BUFFER11_ATI 0x8830
#define GL_DRAW_BUFFER12_ATI 0x8831
#define GL_DRAW_BUFFER13_ATI 0x8832
#define GL_DRAW_BUFFER14_ATI 0x8833
#define GL_DRAW_BUFFER15_ATI 0x8834
#define GL_DRAW_BUFFER1_ATI 0x8826
#define GL_DRAW_BUFFER2_ATI 0x8827
#define GL_DRAW_BUFFER3_ATI 0x8828
#define GL_DRAW_BUFFER4_ATI 0x8829
#define GL_DRAW_BUFFER5_ATI 0x882A
#define GL_DRAW_BUFFER6_ATI 0x882B
#define GL_DRAW_BUFFER7_ATI 0x882C
#define GL_DRAW_BUFFER8_ATI 0x882D
#define GL_DRAW_BUFFER9_ATI 0x882E
#define GL_MAX_DRAW_BUFFERS_ATI 0x8824

#define GL_ELEMENT_ARRAY_ATI 0x8768
#define GL_ELEMENT_ARRAY_POINTER_ATI 0x876A
#define GL_ELEMENT_ARRAY_TYPE_ATI 0x8769

#define GL_BUMP_ENVMAP_ATI 0x877B
#define GL_BUMP_NUM_TEX_UNITS_ATI 0x8777
#define GL_BUMP_ROT_MATRIX_ATI 0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI 0x8776
#define GL_BUMP_TARGET_ATI 0x877C
#define GL_BUMP_TEX_UNITS_ATI 0x8778
#define GL_DU8DV8_ATI 0x877A
#define GL_DUDV_ATI 0x8779

#define GL_2X_BIT_ATI 0x00000001
#define GL_4X_BIT_ATI 0x00000002
#define GL_8X_BIT_ATI 0x00000004
#define GL_ADD_ATI 0x8963
#define GL_BIAS_BIT_ATI 0x00000008
#define GL_BLUE_BIT_ATI 0x00000004
#define GL_CND0_ATI 0x896B
#define GL_CND_ATI 0x896A
#define GL_COLOR_ALPHA_PAIRING_ATI 0x8975
#define GL_COMP_BIT_ATI 0x00000002
#define GL_CON_0_ATI 0x8941
#define GL_CON_10_ATI 0x894B
#define GL_CON_11_ATI 0x894C
#define GL_CON_12_ATI 0x894D
#define GL_CON_13_ATI 0x894E
#define GL_CON_14_ATI 0x894F
#define GL_CON_15_ATI 0x8950
#define GL_CON_16_ATI 0x8951
#define GL_CON_17_ATI 0x8952
#define GL_CON_18_ATI 0x8953
#define GL_CON_19_ATI 0x8954
#define GL_CON_1_ATI 0x8942
#define GL_CON_20_ATI 0x8955
#define GL_CON_21_ATI 0x8956
#define GL_CON_22_ATI 0x8957
#define GL_CON_23_ATI 0x8958
#define GL_CON_24_ATI 0x8959
#define GL_CON_25_ATI 0x895A
#define GL_CON_26_ATI 0x895B
#define GL_CON_27_ATI 0x895C
#define GL_CON_28_ATI 0x895D
#define GL_CON_29_ATI 0x895E
#define GL_CON_2_ATI 0x8943
#define GL_CON_30_ATI 0x895F
#define GL_CON_31_ATI 0x8960
#define GL_CON_3_ATI 0x8944
#define GL_CON_4_ATI 0x8945
#define GL_CON_5_ATI 0x8946
#define GL_CON_6_ATI 0x8947
#define GL_CON_7_ATI 0x8948
#define GL_CON_8_ATI 0x8949
#define GL_CON_9_ATI 0x894A
#define GL_DOT2_ADD_ATI 0x896C
#define GL_DOT3_ATI 0x8966
#define GL_DOT4_ATI 0x8967
#define GL_EIGHTH_BIT_ATI 0x00000020
#define GL_FRAGMENT_SHADER_ATI 0x8920
#define GL_GREEN_BIT_ATI 0x00000002
#define GL_HALF_BIT_ATI 0x00000008
#define GL_LERP_ATI 0x8969
#define GL_MAD_ATI 0x8968
#define GL_MOV_ATI 0x8961
#define GL_MUL_ATI 0x8964
#define GL_NEGATE_BIT_ATI 0x00000004
#define GL_NUM_FRAGMENT_CONSTANTS_ATI 0x896F
#define GL_NUM_FRAGMENT_REGISTERS_ATI 0x896E
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI 0x8973
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI 0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI 0x8972
#define GL_NUM_LOOPBACK_COMPONENTS_ATI 0x8974
#define GL_NUM_PASSES_ATI 0x8970
#define GL_QUARTER_BIT_ATI 0x00000010
#define GL_RED_BIT_ATI 0x00000001
#define GL_REG_0_ATI 0x8921
#define GL_REG_10_ATI 0x892B
#define GL_REG_11_ATI 0x892C
#define GL_REG_12_ATI 0x892D
#define GL_REG_13_ATI 0x892E
#define GL_REG_14_ATI 0x892F
#define GL_REG_15_ATI 0x8930
#define GL_REG_16_ATI 0x8931
#define GL_REG_17_ATI 0x8932
#define GL_REG_18_ATI 0x8933
#define GL_REG_19_ATI 0x8934
#define GL_REG_1_ATI 0x8922
#define GL_REG_20_ATI 0x8935
#define GL_REG_21_ATI 0x8936
#define GL_REG_22_ATI 0x8937
#define GL_REG_23_ATI 0x8938
#define GL_REG_24_ATI 0x8939
#define GL_REG_25_ATI 0x893A
#define GL_REG_26_ATI 0x893B
#define GL_REG_27_ATI 0x893C
#define GL_REG_28_ATI 0x893D
#define GL_REG_29_ATI 0x893E
#define GL_REG_2_ATI 0x8923
#define GL_REG_30_ATI 0x893F
#define GL_REG_31_ATI 0x8940
#define GL_REG_3_ATI 0x8924
#define GL_REG_4_ATI 0x8925
#define GL_REG_5_ATI 0x8926
#define GL_REG_6_ATI 0x8927
#define GL_REG_7_ATI 0x8928
#define GL_REG_8_ATI 0x8929
#define GL_REG_9_ATI 0x892A
#define GL_SATURATE_BIT_ATI 0x00000040
#define GL_SECONDARY_INTERPOLATOR_ATI 0x896D
#define GL_SUB_ATI 0x8965
#define GL_SWIZZLE_STQ_ATI 0x8977
#define GL_SWIZZLE_STQ_DQ_ATI 0x8979
#define GL_SWIZZLE_STRQ_ATI 0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI 0x897B
#define GL_SWIZZLE_STR_ATI 0x8976
#define GL_SWIZZLE_STR_DR_ATI 0x8978

#define GL_RENDERBUFFER_FREE_MEMORY_ATI 0x87FD
#define GL_TEXTURE_FREE_MEMORY_ATI 0x87FC
#define GL_VBO_FREE_MEMORY_ATI 0x87FB

#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835
#define GL_RGBA_FLOAT_MODE_ATI 0x8820

#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F1
#define GL_PN_TRIANGLES_ATI 0x87F0
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI 0x87F3
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI 0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI 0x87F8
#define GL_PN_TRIANGLES_POINT_MODE_ATI 0x87F2
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI 0x87F6
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI 0x87F5
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F4

#define GL_STENCIL_BACK_FAIL_ATI 0x8801
#define GL_STENCIL_BACK_FUNC_ATI 0x8800
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI 0x8803

#define GL_TEXT_FRAGMENT_SHADER_ATI 0x8200

#define GL_MODULATE_ADD_ATI 0x8744
#define GL_MODULATE_SIGNED_ADD_ATI 0x8745
#define GL_MODULATE_SUBTRACT_ATI 0x8746

#define GL_ALPHA_FLOAT16_ATI 0x881C
#define GL_ALPHA_FLOAT32_ATI 0x8816
#define GL_INTENSITY_FLOAT16_ATI 0x881D
#define GL_INTENSITY_FLOAT32_ATI 0x8817
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI 0x881F
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI 0x8819
#define GL_LUMINANCE_FLOAT16_ATI 0x881E
#define GL_LUMINANCE_FLOAT32_ATI 0x8818
#define GL_RGBA_FLOAT16_ATI 0x881A
#define GL_RGBA_FLOAT32_ATI 0x8814
#define GL_RGB_FLOAT16_ATI 0x881B
#define GL_RGB_FLOAT32_ATI 0x8815

#define GL_MIRROR_CLAMP_ATI 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI 0x8743

#define GL_ARRAY_OBJECT_BUFFER_ATI 0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI 0x8767
#define GL_DISCARD_ATI 0x8763
#define GL_DYNAMIC_ATI 0x8761
#define GL_OBJECT_BUFFER_SIZE_ATI 0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI 0x8765
#define GL_PRESERVE_ATI 0x8762
#define GL_STATIC_ATI 0x8760

#define GL_MAX_VERTEX_STREAMS_ATI 0x876B
#define GL_VERTEX_SOURCE_ATI 0x8774
#define GL_VERTEX_STREAM0_ATI 0x876C
#define GL_VERTEX_STREAM1_ATI 0x876D
#define GL_VERTEX_STREAM2_ATI 0x876E
#define GL_VERTEX_STREAM3_ATI 0x876F
#define GL_VERTEX_STREAM4_ATI 0x8770
#define GL_VERTEX_STREAM5_ATI 0x8771
#define GL_VERTEX_STREAM6_ATI 0x8772
#define GL_VERTEX_STREAM7_ATI 0x8773

#define GL_422_AVERAGE_EXT 0x80CE
#define GL_422_EXT 0x80CC
#define GL_422_REV_AVERAGE_EXT 0x80CF
#define GL_422_REV_EXT 0x80CD

#define GL_ABGR_EXT 0x8000

#define GL_BGRA_EXT 0x80E1
#define GL_BGR_EXT 0x80E0

#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT 0x8DED
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_UNIFORM_BUFFER_BINDING_EXT 0x8DEF
#define GL_UNIFORM_BUFFER_EXT 0x8DEE

#define GL_BLEND_COLOR_EXT 0x8005
#define GL_CONSTANT_ALPHA_EXT 0x8003
#define GL_CONSTANT_COLOR_EXT 0x8001
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT 0x8004
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT 0x8002

#define GL_BLEND_EQUATION_ALPHA_EXT 0x883D
#define GL_BLEND_EQUATION_RGB_EXT 0x8009

#define GL_BLEND_DST_ALPHA_EXT 0x80CA
#define GL_BLEND_DST_RGB_EXT 0x80C8
#define GL_BLEND_SRC_ALPHA_EXT 0x80CB
#define GL_BLEND_SRC_RGB_EXT 0x80C9

#define GL_BLEND_EQUATION_EXT 0x8009
#define GL_FUNC_ADD_EXT 0x8006
#define GL_MAX_EXT 0x8008
#define GL_MIN_EXT 0x8007

#define GL_FUNC_REVERSE_SUBTRACT_EXT 0x800B
#define GL_FUNC_SUBTRACT_EXT 0x800A

#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT 0x80F0

#define GL_CMYKA_EXT 0x800D
#define GL_CMYK_EXT 0x800C
#define GL_PACK_CMYK_HINT_EXT 0x800E
#define GL_UNPACK_CMYK_HINT_EXT 0x800F

#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9
#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8

#define GL_CONVOLUTION_1D_EXT 0x8010
#define GL_CONVOLUTION_2D_EXT 0x8011
#define GL_CONVOLUTION_BORDER_MODE_EXT 0x8013
#define GL_CONVOLUTION_FILTER_BIAS_EXT 0x8015
#define GL_CONVOLUTION_FILTER_SCALE_EXT 0x8014
#define GL_CONVOLUTION_FORMAT_EXT 0x8017
#define GL_CONVOLUTION_HEIGHT_EXT 0x8019
#define GL_CONVOLUTION_WIDTH_EXT 0x8018
#define GL_MAX_CONVOLUTION_HEIGHT_EXT 0x801B
#define GL_MAX_CONVOLUTION_WIDTH_EXT 0x801A
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT 0x8023
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT 0x8022
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT 0x801E
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT 0x8021
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_POST_CONVOLUTION_RED_BIAS_EXT 0x8020
#define GL_POST_CONVOLUTION_RED_SCALE_EXT 0x801C
#define GL_REDUCE_EXT 0x8016
#define GL_SEPARABLE_2D_EXT 0x8012

#define GL_BINORMAL_ARRAY_EXT 0x843A
#define GL_BINORMAL_ARRAY_POINTER_EXT 0x8443
#define GL_BINORMAL_ARRAY_STRIDE_EXT 0x8441
#define GL_BINORMAL_ARRAY_TYPE_EXT 0x8440
#define GL_CURRENT_BINORMAL_EXT 0x843C
#define GL_CURRENT_TANGENT_EXT 0x843B
#define GL_MAP1_BINORMAL_EXT 0x8446
#define GL_MAP1_TANGENT_EXT 0x8444
#define GL_MAP2_BINORMAL_EXT 0x8447
#define GL_MAP2_TANGENT_EXT 0x8445
#define GL_TANGENT_ARRAY_EXT 0x8439
#define GL_TANGENT_ARRAY_POINTER_EXT 0x8442
#define GL_TANGENT_ARRAY_STRIDE_EXT 0x843F
#define GL_TANGENT_ARRAY_TYPE_EXT 0x843E

#define GL_CULL_VERTEX_EXT 0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT 0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT 0x81AC

#define GL_DEPTH_BOUNDS_EXT 0x8891
#define GL_DEPTH_BOUNDS_TEST_EXT 0x8890

#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E

#define GL_MAX_ELEMENTS_INDICES_EXT 0x80E9
#define GL_MAX_ELEMENTS_VERTICES_EXT 0x80E8

#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_FRAGMENT_DEPTH_EXT 0x8452

#define GL_DRAW_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING_EXT 0x8CAA
#define GL_READ_FRAMEBUFFER_EXT 0x8CA8

#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x8D56
#define GL_MAX_SAMPLES_EXT 0x8D57
#define GL_RENDERBUFFER_SAMPLES_EXT 0x8CAB

#define GL_SCALED_RESOLVE_FASTEST_EXT 0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT 0x90BB

#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT 0x8D53
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_RENDERBUFFER_BLUE_SIZE_EXT 0x8D52
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT 0x8D54
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_RENDERBUFFER_GREEN_SIZE_EXT 0x8D51
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_RENDERBUFFER_RED_SIZE_EXT 0x8D50
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT 0x8D55
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_STENCIL_INDEX16_EXT 0x8D49
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_STENCIL_INDEX8_EXT 0x8D48

#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x8DBA
#define GL_FRAMEBUFFER_SRGB_EXT 0x8DB9

#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_GEOMETRY_SHADER_EXT 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_LINES_ADJACENCY_EXT 0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT 0x000B
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_MAX_VARYING_COMPONENTS_EXT 0x8B4B
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642
#define GL_TRIANGLES_ADJACENCY_EXT 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0x000D

#define GL_INT_SAMPLER_1D_ARRAY_EXT 0x8DCE
#define GL_INT_SAMPLER_1D_EXT 0x8DC9
#define GL_INT_SAMPLER_2D_ARRAY_EXT 0x8DCF
#define GL_INT_SAMPLER_2D_EXT 0x8DCA
#define GL_INT_SAMPLER_2D_RECT_EXT 0x8DCD
#define GL_INT_SAMPLER_3D_EXT 0x8DCB
#define GL_INT_SAMPLER_BUFFER_EXT 0x8DD0
#define GL_INT_SAMPLER_CUBE_EXT 0x8DCC
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT 0x8905
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT 0x8904
#define GL_SAMPLER_1D_ARRAY_EXT 0x8DC0
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT 0x8DC3
#define GL_SAMPLER_2D_ARRAY_EXT 0x8DC1
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT 0x8DC4
#define GL_SAMPLER_BUFFER_EXT 0x8DC2
#define GL_SAMPLER_CUBE_SHADOW_EXT 0x8DC5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT 0x8DD4
#define GL_UNSIGNED_INT_VEC2_EXT 0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT 0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT 0x8DC8
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT 0x88FD

#define GL_HISTOGRAM_ALPHA_SIZE_EXT 0x802B
#define GL_HISTOGRAM_BLUE_SIZE_EXT 0x802A
#define GL_HISTOGRAM_EXT 0x8024
#define GL_HISTOGRAM_FORMAT_EXT 0x8027
#define GL_HISTOGRAM_GREEN_SIZE_EXT 0x8029
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT 0x802C
#define GL_HISTOGRAM_RED_SIZE_EXT 0x8028
#define GL_HISTOGRAM_SINK_EXT 0x802D
#define GL_HISTOGRAM_WIDTH_EXT 0x8026
#define GL_MINMAX_EXT 0x802E
#define GL_MINMAX_FORMAT_EXT 0x802F
#define GL_MINMAX_SINK_EXT 0x8030
#define GL_PROXY_HISTOGRAM_EXT 0x8025
#define GL_TABLE_TOO_LARGE_EXT 0x8031

#define GL_IUI_N3F_V2F_EXT 0x81AF
#define GL_IUI_N3F_V3F_EXT 0x81B0
#define GL_IUI_V2F_EXT 0x81AD
#define GL_IUI_V3F_EXT 0x81AE
#define GL_T2F_IUI_N3F_V2F_EXT 0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT 0x81B4
#define GL_T2F_IUI_V2F_EXT 0x81B1
#define GL_T2F_IUI_V3F_EXT 0x81B2

#define GL_INDEX_TEST_EXT 0x81B5
#define GL_INDEX_TEST_FUNC_EXT 0x81B6
#define GL_INDEX_TEST_REF_EXT 0x81B7

#define GL_INDEX_MATERIAL_EXT 0x81B8
#define GL_INDEX_MATERIAL_FACE_EXT 0x81BA
#define GL_INDEX_MATERIAL_PARAMETER_EXT 0x81B9

#define GL_ATTENUATION_EXT 0x834D
#define GL_FRAGMENT_COLOR_EXT 0x834C
/*Copied GL_FRAGMENT_DEPTH_EXT From: EXT_fog_coord*/
#define GL_FRAGMENT_MATERIAL_EXT 0x8349
#define GL_FRAGMENT_NORMAL_EXT 0x834A
#define GL_SHADOW_ATTENUATION_EXT 0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT 0x834F
#define GL_TEXTURE_LIGHT_EXT 0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT 0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352

#define GL_1PASS_EXT 0x80A1
#define GL_2PASS_0_EXT 0x80A2
#define GL_2PASS_1_EXT 0x80A3
#define GL_4PASS_0_EXT 0x80A4
#define GL_4PASS_1_EXT 0x80A5
#define GL_4PASS_2_EXT 0x80A6
#define GL_4PASS_3_EXT 0x80A7
#define GL_MULTISAMPLE_BIT_EXT 0x20000000
#define GL_MULTISAMPLE_EXT 0x809D
#define GL_SAMPLES_EXT 0x80A9
#define GL_SAMPLE_ALPHA_TO_MASK_EXT 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT 0x809F
#define GL_SAMPLE_BUFFERS_EXT 0x80A8
#define GL_SAMPLE_MASK_EXT 0x80A0
#define GL_SAMPLE_MASK_INVERT_EXT 0x80AB
#define GL_SAMPLE_MASK_VALUE_EXT 0x80AA
#define GL_SAMPLE_PATTERN_EXT 0x80AC

#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA

#define GL_R11F_G11F_B10F_EXT 0x8C3A
#define GL_RGBA_SIGNED_COMPONENTS_EXT 0x8C3C
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B

#define GL_UNSIGNED_BYTE_3_3_2_EXT 0x8032
#define GL_UNSIGNED_INT_10_10_10_2_EXT 0x8036
#define GL_UNSIGNED_INT_8_8_8_8_EXT 0x8035
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT 0x8034

#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_TEXTURE_INDEX_SIZE_EXT 0x80ED

#define GL_PIXEL_PACK_BUFFER_BINDING_EXT 0x88ED
#define GL_PIXEL_PACK_BUFFER_EXT 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF
#define GL_PIXEL_UNPACK_BUFFER_EXT 0x88EC

#define GL_AVERAGE_EXT 0x8335
#define GL_CUBIC_EXT 0x8334
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
#define GL_PIXEL_CUBIC_WEIGHT_EXT 0x8333
#define GL_PIXEL_MAG_FILTER_EXT 0x8331
#define GL_PIXEL_MIN_FILTER_EXT 0x8332
#define GL_PIXEL_TRANSFORM_2D_EXT 0x8330
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT 0x8338
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336

#define GL_DISTANCE_ATTENUATION_EXT 0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT 0x8128
#define GL_POINT_SIZE_MAX_EXT 0x8127
#define GL_POINT_SIZE_MIN_EXT 0x8126

#define GL_POLYGON_OFFSET_BIAS_EXT 0x8039
#define GL_POLYGON_OFFSET_EXT 0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT 0x8038

#define GL_FIRST_VERTEX_CONVENTION_EXT 0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT 0x8E4E
#define GL_PROVOKING_VERTEX_EXT 0x8E4F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT 0x8E4C

#define GL_RESCALE_NORMAL_EXT 0x803A

#define GL_COLOR_SUM_EXT 0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
#define GL_SECONDARY_COLOR_ARRAY_EXT 0x845E
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B

#define GL_ACTIVE_PROGRAM_EXT 0x8B8D

#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA
#define GL_SINGLE_COLOR_EXT 0x81F9

#define GL_ALL_BARRIER_BITS_EXT 0xFFFFFFFF
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT 0x00001000
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT 0x00000200
#define GL_COMMAND_BARRIER_BIT_EXT 0x00000040
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT 0x00000002
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT 0x00000400
#define GL_IMAGE_1D_ARRAY_EXT 0x9052
#define GL_IMAGE_1D_EXT 0x904C
#define GL_IMAGE_2D_ARRAY_EXT 0x9053
#define GL_IMAGE_2D_EXT 0x904D
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9056
#define GL_IMAGE_2D_MULTISAMPLE_EXT 0x9055
#define GL_IMAGE_2D_RECT_EXT 0x904F
#define GL_IMAGE_3D_EXT 0x904E
#define GL_IMAGE_BINDING_ACCESS_EXT 0x8F3E
#define GL_IMAGE_BINDING_FORMAT_EXT 0x906E
#define GL_IMAGE_BINDING_LAYERED_EXT 0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT 0x8F3D
#define GL_IMAGE_BINDING_LEVEL_EXT 0x8F3B
#define GL_IMAGE_BINDING_NAME_EXT 0x8F3A
#define GL_IMAGE_BUFFER_EXT 0x9051
#define GL_IMAGE_CUBE_EXT 0x9050
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT 0x9054
#define GL_INT_IMAGE_1D_ARRAY_EXT 0x905D
#define GL_INT_IMAGE_1D_EXT 0x9057
#define GL_INT_IMAGE_2D_ARRAY_EXT 0x905E
#define GL_INT_IMAGE_2D_EXT 0x9058
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9061
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT 0x9060
#define GL_INT_IMAGE_2D_RECT_EXT 0x905A
#define GL_INT_IMAGE_3D_EXT 0x9059
#define GL_INT_IMAGE_BUFFER_EXT 0x905C
#define GL_INT_IMAGE_CUBE_EXT 0x905B
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x905F
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_MAX_IMAGE_SAMPLES_EXT 0x906D
#define GL_MAX_IMAGE_UNITS_EXT 0x8F38
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT 0x00000080
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT 0x00000020
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT 0x00000008
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT 0x00000100
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT 0x00000800
#define GL_UNIFORM_BARRIER_BIT_EXT 0x00000004
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT 0x9068
#define GL_UNSIGNED_INT_IMAGE_1D_EXT 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT 0x9069
#define GL_UNSIGNED_INT_IMAGE_2D_EXT 0x9063
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x906C
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT 0x9065
#define GL_UNSIGNED_INT_IMAGE_3D_EXT 0x9064
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT 0x9067
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT 0x9066
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x906A
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT 0x00000001

#define GL_SHARED_TEXTURE_PALETTE_EXT 0x81FB

#define GL_STENCIL_CLEAR_TAG_VALUE_EXT 0x88F3
#define GL_STENCIL_TAG_BITS_EXT 0x88F2

#define GL_ACTIVE_STENCIL_FACE_EXT 0x8911
#define GL_STENCIL_TEST_TWO_SIDE_EXT 0x8910

#define GL_DECR_WRAP_EXT 0x8508
#define GL_INCR_WRAP_EXT 0x8507

#define GL_ALPHA12_EXT 0x803D
#define GL_ALPHA16_EXT 0x803E
#define GL_ALPHA4_EXT 0x803B
#define GL_ALPHA8_EXT 0x803C
#define GL_INTENSITY12_EXT 0x804C
#define GL_INTENSITY16_EXT 0x804D
#define GL_INTENSITY4_EXT 0x804A
#define GL_INTENSITY8_EXT 0x804B
#define GL_INTENSITY_EXT 0x8049
#define GL_LUMINANCE12_ALPHA12_EXT 0x8047
#define GL_LUMINANCE12_ALPHA4_EXT 0x8046
#define GL_LUMINANCE12_EXT 0x8041
#define GL_LUMINANCE16_ALPHA16_EXT 0x8048
#define GL_LUMINANCE16_EXT 0x8042
#define GL_LUMINANCE4_ALPHA4_EXT 0x8043
#define GL_LUMINANCE4_EXT 0x803F
#define GL_LUMINANCE6_ALPHA2_EXT 0x8044
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_LUMINANCE8_EXT 0x8040
#define GL_PROXY_TEXTURE_1D_EXT 0x8063
#define GL_PROXY_TEXTURE_2D_EXT 0x8064
#define GL_REPLACE_EXT 0x8062
#define GL_RGB10_A2_EXT 0x8059
#define GL_RGB10_EXT 0x8052
#define GL_RGB12_EXT 0x8053
#define GL_RGB16_EXT 0x8054
#define GL_RGB2_EXT 0x804E
#define GL_RGB4_EXT 0x804F
#define GL_RGB5_A1_EXT 0x8057
#define GL_RGB5_EXT 0x8050
#define GL_RGB8_EXT 0x8051
#define GL_RGBA12_EXT 0x805A
#define GL_RGBA16_EXT 0x805B
#define GL_RGBA2_EXT 0x8055
#define GL_RGBA4_EXT 0x8056
#define GL_RGBA8_EXT 0x8058
#define GL_TEXTURE_ALPHA_SIZE_EXT 0x805F
#define GL_TEXTURE_BLUE_SIZE_EXT 0x805E
#define GL_TEXTURE_GREEN_SIZE_EXT 0x805D
#define GL_TEXTURE_INTENSITY_SIZE_EXT 0x8061
#define GL_TEXTURE_LUMINANCE_SIZE_EXT 0x8060
#define GL_TEXTURE_RED_SIZE_EXT 0x805C
#define GL_TEXTURE_TOO_LARGE_EXT 0x8065

#define GL_MAX_3D_TEXTURE_SIZE_EXT 0x8073
#define GL_PACK_IMAGE_HEIGHT_EXT 0x806C
#define GL_PACK_SKIP_IMAGES_EXT 0x806B
#define GL_PROXY_TEXTURE_3D_EXT 0x8070
#define GL_TEXTURE_3D_EXT 0x806F
#define GL_TEXTURE_DEPTH_EXT 0x8071
#define GL_TEXTURE_WRAP_R_EXT 0x8072
#define GL_UNPACK_IMAGE_HEIGHT_EXT 0x806E
#define GL_UNPACK_SKIP_IMAGES_EXT 0x806D

#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT From: EXT_geometry_shader4*/
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT 0x88FF
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT 0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT 0x8C1B
#define GL_TEXTURE_1D_ARRAY_EXT 0x8C18
#define GL_TEXTURE_2D_ARRAY_EXT 0x8C1A
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT 0x8C1D

#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_TEXTURE_BUFFER_FORMAT_EXT 0x8C2E

#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71

#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_COMPRESSED_RED_RGTC1_EXT 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC

#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0

#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT 0x851C
#define GL_NORMAL_MAP_EXT 0x8511
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT 0x851B
#define GL_REFLECTION_MAP_EXT 0x8512
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT 0x8514
#define GL_TEXTURE_CUBE_MAP_EXT 0x8513
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519

#define GL_ADD_SIGNED_EXT 0x8574
#define GL_COMBINE_ALPHA_EXT 0x8572
#define GL_COMBINE_EXT 0x8570
#define GL_COMBINE_RGB_EXT 0x8571
#define GL_CONSTANT_EXT 0x8576
#define GL_INTERPOLATE_EXT 0x8575
#define GL_OPERAND0_ALPHA_EXT 0x8598
#define GL_OPERAND0_RGB_EXT 0x8590
#define GL_OPERAND1_ALPHA_EXT 0x8599
#define GL_OPERAND1_RGB_EXT 0x8591
#define GL_OPERAND2_ALPHA_EXT 0x859A
#define GL_OPERAND2_RGB_EXT 0x8592
#define GL_PREVIOUS_EXT 0x8578
#define GL_PRIMARY_COLOR_EXT 0x8577
#define GL_RGB_SCALE_EXT 0x8573
#define GL_SOURCE0_ALPHA_EXT 0x8588
#define GL_SOURCE0_RGB_EXT 0x8580
#define GL_SOURCE1_ALPHA_EXT 0x8589
#define GL_SOURCE1_RGB_EXT 0x8581
#define GL_SOURCE2_ALPHA_EXT 0x858A
#define GL_SOURCE2_RGB_EXT 0x8582

#define GL_DOT3_RGBA_EXT 0x8741
#define GL_DOT3_RGB_EXT 0x8740

#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE

#define GL_ALPHA16I_EXT 0x8D8A
#define GL_ALPHA16UI_EXT 0x8D78
#define GL_ALPHA32I_EXT 0x8D84
#define GL_ALPHA32UI_EXT 0x8D72
#define GL_ALPHA8I_EXT 0x8D90
#define GL_ALPHA8UI_EXT 0x8D7E
#define GL_ALPHA_INTEGER_EXT 0x8D97
#define GL_BGRA_INTEGER_EXT 0x8D9B
#define GL_BGR_INTEGER_EXT 0x8D9A
#define GL_BLUE_INTEGER_EXT 0x8D96
#define GL_GREEN_INTEGER_EXT 0x8D95
#define GL_INTENSITY16I_EXT 0x8D8B
#define GL_INTENSITY16UI_EXT 0x8D79
#define GL_INTENSITY32I_EXT 0x8D85
#define GL_INTENSITY32UI_EXT 0x8D73
#define GL_INTENSITY8I_EXT 0x8D91
#define GL_INTENSITY8UI_EXT 0x8D7F
#define GL_LUMINANCE16I_EXT 0x8D8C
#define GL_LUMINANCE16UI_EXT 0x8D7A
#define GL_LUMINANCE32I_EXT 0x8D86
#define GL_LUMINANCE32UI_EXT 0x8D74
#define GL_LUMINANCE8I_EXT 0x8D92
#define GL_LUMINANCE8UI_EXT 0x8D80
#define GL_LUMINANCE_ALPHA16I_EXT 0x8D8D
#define GL_LUMINANCE_ALPHA16UI_EXT 0x8D7B
#define GL_LUMINANCE_ALPHA32I_EXT 0x8D87
#define GL_LUMINANCE_ALPHA32UI_EXT 0x8D75
#define GL_LUMINANCE_ALPHA8I_EXT 0x8D93
#define GL_LUMINANCE_ALPHA8UI_EXT 0x8D81
#define GL_LUMINANCE_ALPHA_INTEGER_EXT 0x8D9D
#define GL_LUMINANCE_INTEGER_EXT 0x8D9C
#define GL_RED_INTEGER_EXT 0x8D94
#define GL_RGB16I_EXT 0x8D89
#define GL_RGB16UI_EXT 0x8D77
#define GL_RGB32I_EXT 0x8D83
#define GL_RGB32UI_EXT 0x8D71
#define GL_RGB8I_EXT 0x8D8F
#define GL_RGB8UI_EXT 0x8D7D
#define GL_RGBA16I_EXT 0x8D88
#define GL_RGBA16UI_EXT 0x8D76
#define GL_RGBA32I_EXT 0x8D82
#define GL_RGBA32UI_EXT 0x8D70
#define GL_RGBA8I_EXT 0x8D8E
#define GL_RGBA8UI_EXT 0x8D7C
#define GL_RGBA_INTEGER_EXT 0x8D99
#define GL_RGBA_INTEGER_MODE_EXT 0x8D9E
#define GL_RGB_INTEGER_EXT 0x8D98

#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501

#define GL_MIRROR_CLAMP_EXT 0x8742
#define GL_MIRROR_CLAMP_TO_BORDER_EXT 0x8912
#define GL_MIRROR_CLAMP_TO_EDGE_EXT 0x8743

#define GL_TEXTURE_1D_BINDING_EXT 0x8068
#define GL_TEXTURE_2D_BINDING_EXT 0x8069
#define GL_TEXTURE_3D_BINDING_EXT 0x806A
#define GL_TEXTURE_PRIORITY_EXT 0x8066
#define GL_TEXTURE_RESIDENT_EXT 0x8067

#define GL_PERTURB_EXT 0x85AE
#define GL_TEXTURE_NORMAL_EXT 0x85AF

#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_COMPRESSED_SLUMINANCE_EXT 0x8C4A
#define GL_COMPRESSED_SRGB_ALPHA_EXT 0x8C49
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
#define GL_COMPRESSED_SRGB_EXT 0x8C48
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_SLUMINANCE8_ALPHA8_EXT 0x8C45
#define GL_SLUMINANCE8_EXT 0x8C47
#define GL_SLUMINANCE_ALPHA_EXT 0x8C44
#define GL_SLUMINANCE_EXT 0x8C46
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_SRGB8_EXT 0x8C41
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_SRGB_EXT 0x8C40

#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A
#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48

#define GL_RGB9_E5_EXT 0x8C3D
#define GL_TEXTURE_SHARED_SIZE_EXT 0x8C3F
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT 0x8C3E

#define GL_ALPHA16_SNORM 0x9018
#define GL_ALPHA8_SNORM 0x9014
#define GL_ALPHA_SNORM 0x9010
#define GL_INTENSITY16_SNORM 0x901B
#define GL_INTENSITY8_SNORM 0x9017
#define GL_INTENSITY_SNORM 0x9013
#define GL_LUMINANCE16_ALPHA16_SNORM 0x901A
#define GL_LUMINANCE16_SNORM 0x9019
#define GL_LUMINANCE8_ALPHA8_SNORM 0x9016
#define GL_LUMINANCE8_SNORM 0x9015
#define GL_LUMINANCE_ALPHA_SNORM 0x9012
#define GL_LUMINANCE_SNORM 0x9011
#define GL_R16_SNORM 0x8F98
#define GL_R8_SNORM 0x8F94
#define GL_RED_SNORM 0x8F90
#define GL_RG16_SNORM 0x8F99
#define GL_RG8_SNORM 0x8F95
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA16_SNORM 0x8F9B
#define GL_RGBA8_SNORM 0x8F97
#define GL_RGBA_SNORM 0x8F93
#define GL_RGB_SNORM 0x8F92
#define GL_RG_SNORM 0x8F91
#define GL_SIGNED_NORMALIZED 0x8F9C

#define GL_TEXTURE_SWIZZLE_A_EXT 0x8E45
#define GL_TEXTURE_SWIZZLE_B_EXT 0x8E44
#define GL_TEXTURE_SWIZZLE_G_EXT 0x8E43
#define GL_TEXTURE_SWIZZLE_RGBA_EXT 0x8E46
#define GL_TEXTURE_SWIZZLE_R_EXT 0x8E42

#define GL_TIME_ELAPSED_EXT 0x88BF

#define GL_INTERLEAVED_ATTRIBS_EXT 0x8C8C
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT 0x8C80
#define GL_PRIMITIVES_GENERATED_EXT 0x8C87
#define GL_RASTERIZER_DISCARD_EXT 0x8C89
#define GL_SEPARATE_ATTRIBS_EXT 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT 0x8C8F
#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT 0x8C7F
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT 0x8C84
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT 0x8C88
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT 0x8C83
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT 0x8C76

#define GL_COLOR_ARRAY_COUNT_EXT 0x8084
#define GL_COLOR_ARRAY_EXT 0x8076
#define GL_COLOR_ARRAY_POINTER_EXT 0x8090
#define GL_COLOR_ARRAY_SIZE_EXT 0x8081
#define GL_COLOR_ARRAY_STRIDE_EXT 0x8083
#define GL_COLOR_ARRAY_TYPE_EXT 0x8082
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT 0x808D
#define GL_EDGE_FLAG_ARRAY_EXT 0x8079
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT 0x8093
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT 0x808C
#define GL_INDEX_ARRAY_COUNT_EXT 0x8087
#define GL_INDEX_ARRAY_EXT 0x8077
#define GL_INDEX_ARRAY_POINTER_EXT 0x8091
#define GL_INDEX_ARRAY_STRIDE_EXT 0x8086
#define GL_INDEX_ARRAY_TYPE_EXT 0x8085
#define GL_NORMAL_ARRAY_COUNT_EXT 0x8080
#define GL_NORMAL_ARRAY_EXT 0x8075
#define GL_NORMAL_ARRAY_POINTER_EXT 0x808F
#define GL_NORMAL_ARRAY_STRIDE_EXT 0x807F
#define GL_NORMAL_ARRAY_TYPE_EXT 0x807E
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT 0x808B
#define GL_TEXTURE_COORD_ARRAY_EXT 0x8078
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT 0x8088
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT 0x8089
#define GL_VERTEX_ARRAY_COUNT_EXT 0x807D
#define GL_VERTEX_ARRAY_EXT 0x8074
#define GL_VERTEX_ARRAY_POINTER_EXT 0x808E
#define GL_VERTEX_ARRAY_SIZE_EXT 0x807A
#define GL_VERTEX_ARRAY_STRIDE_EXT 0x807C
#define GL_VERTEX_ARRAY_TYPE_EXT 0x807B

/*Copied GL_BGRA From: ARB_vertex_array_bgra*/

/*Copied GL_DOUBLE From: ARB_gpu_shader_fp64*/
#define GL_DOUBLE_MAT2_EXT 0x8F46
#define GL_DOUBLE_MAT2x3_EXT 0x8F49
#define GL_DOUBLE_MAT2x4_EXT 0x8F4A
#define GL_DOUBLE_MAT3_EXT 0x8F47
#define GL_DOUBLE_MAT3x2_EXT 0x8F4B
#define GL_DOUBLE_MAT3x4_EXT 0x8F4C
#define GL_DOUBLE_MAT4_EXT 0x8F48
#define GL_DOUBLE_MAT4x2_EXT 0x8F4D
#define GL_DOUBLE_MAT4x3_EXT 0x8F4E
#define GL_DOUBLE_VEC2_EXT 0x8FFC
#define GL_DOUBLE_VEC3_EXT 0x8FFD
#define GL_DOUBLE_VEC4_EXT 0x8FFE

#define GL_CURRENT_VERTEX_EXT 0x87E2
#define GL_FULL_RANGE_EXT 0x87E1
#define GL_INVARIANT_DATATYPE_EXT 0x87EB
#define GL_INVARIANT_EXT 0x87C2
#define GL_INVARIANT_VALUE_EXT 0x87EA
#define GL_LOCAL_CONSTANT_DATATYPE_EXT 0x87ED
#define GL_LOCAL_CONSTANT_EXT 0x87C3
#define GL_LOCAL_CONSTANT_VALUE_EXT 0x87EC
#define GL_LOCAL_EXT 0x87C4
#define GL_MATRIX_EXT 0x87C0
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT 0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT 0x87CE
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT 0x87CB
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87C5
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT 0x87C7
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT 0x87C9
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87C8
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT 0x87C6
#define GL_MVP_MATRIX_EXT 0x87E3
#define GL_NEGATIVE_ONE_EXT 0x87DF
#define GL_NEGATIVE_W_EXT 0x87DC
#define GL_NEGATIVE_X_EXT 0x87D9
#define GL_NEGATIVE_Y_EXT 0x87DA
#define GL_NEGATIVE_Z_EXT 0x87DB
#define GL_NORMALIZED_RANGE_EXT 0x87E0
#define GL_ONE_EXT 0x87DE
#define GL_OP_ADD_EXT 0x8787
#define GL_OP_CLAMP_EXT 0x878E
#define GL_OP_CROSS_PRODUCT_EXT 0x8797
#define GL_OP_DOT3_EXT 0x8784
#define GL_OP_DOT4_EXT 0x8785
#define GL_OP_EXP_BASE_2_EXT 0x8791
#define GL_OP_FLOOR_EXT 0x878F
#define GL_OP_FRAC_EXT 0x8789
#define GL_OP_INDEX_EXT 0x8782
#define GL_OP_LOG_BASE_2_EXT 0x8792
#define GL_OP_MADD_EXT 0x8788
#define GL_OP_MAX_EXT 0x878A
#define GL_OP_MIN_EXT 0x878B
#define GL_OP_MOV_EXT 0x8799
#define GL_OP_MULTIPLY_MATRIX_EXT 0x8798
#define GL_OP_MUL_EXT 0x8786
#define GL_OP_NEGATE_EXT 0x8783
#define GL_OP_POWER_EXT 0x8793
#define GL_OP_RECIP_EXT 0x8794
#define GL_OP_RECIP_SQRT_EXT 0x8795
#define GL_OP_ROUND_EXT 0x8790
#define GL_OP_SET_GE_EXT 0x878C
#define GL_OP_SET_LT_EXT 0x878D
#define GL_OP_SUB_EXT 0x8796
#define GL_OUTPUT_COLOR0_EXT 0x879B
#define GL_OUTPUT_COLOR1_EXT 0x879C
#define GL_OUTPUT_FOG_EXT 0x87BD
#define GL_OUTPUT_TEXTURE_COORD0_EXT 0x879D
#define GL_OUTPUT_TEXTURE_COORD10_EXT 0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT 0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT 0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT 0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT 0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT 0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT 0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT 0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT 0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT 0x87B0
#define GL_OUTPUT_TEXTURE_COORD1_EXT 0x879E
#define GL_OUTPUT_TEXTURE_COORD20_EXT 0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT 0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT 0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT 0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT 0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT 0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT 0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT 0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT 0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT 0x87BA
#define GL_OUTPUT_TEXTURE_COORD2_EXT 0x879F
#define GL_OUTPUT_TEXTURE_COORD30_EXT 0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT 0x87BC
#define GL_OUTPUT_TEXTURE_COORD3_EXT 0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT 0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT 0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT 0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT 0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT 0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT 0x87A6
#define GL_OUTPUT_VERTEX_EXT 0x879A
#define GL_SCALAR_EXT 0x87BE
#define GL_VARIANT_ARRAY_EXT 0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT 0x87E9
#define GL_VARIANT_ARRAY_STRIDE_EXT 0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT 0x87E7
#define GL_VARIANT_DATATYPE_EXT 0x87E5
#define GL_VARIANT_EXT 0x87C1
#define GL_VARIANT_VALUE_EXT 0x87E4
#define GL_VECTOR_EXT 0x87BF
#define GL_VERTEX_SHADER_BINDING_EXT 0x8781
#define GL_VERTEX_SHADER_EXT 0x8780
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CF
#define GL_VERTEX_SHADER_INVARIANTS_EXT 0x87D1
#define GL_VERTEX_SHADER_LOCALS_EXT 0x87D3
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87D2
#define GL_VERTEX_SHADER_OPTIMIZED_EXT 0x87D4
#define GL_VERTEX_SHADER_VARIANTS_EXT 0x87D0
#define GL_W_EXT 0x87D8
#define GL_X_EXT 0x87D5
#define GL_Y_EXT 0x87D6
#define GL_ZERO_EXT 0x87DD
#define GL_Z_EXT 0x87D7

#define GL_CURRENT_VERTEX_WEIGHT_EXT 0x850B
#define GL_MODELVIEW0_EXT 0x1700
#define GL_MODELVIEW0_MATRIX_EXT 0x0BA6
#define GL_MODELVIEW0_STACK_DEPTH_EXT 0x0BA3
#define GL_MODELVIEW1_EXT 0x850A
#define GL_MODELVIEW1_MATRIX_EXT 0x8506
#define GL_MODELVIEW1_STACK_DEPTH_EXT 0x8502
#define GL_VERTEX_WEIGHTING_EXT 0x8509
#define GL_VERTEX_WEIGHT_ARRAY_EXT 0x850C
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT 0x8510
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT 0x850D
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT 0x850F
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT 0x850E

#define GL_SYNC_X11_FENCE_EXT 0x90E1

#define GL_CONSTANT_BORDER_HP 0x8151
#define GL_CONVOLUTION_BORDER_COLOR_HP 0x8154
#define GL_IGNORE_BORDER_HP 0x8150
#define GL_REPLICATE_BORDER_HP 0x8153

#define GL_AVERAGE_HP 0x8160
#define GL_CUBIC_HP 0x815F
#define GL_IMAGE_CUBIC_WEIGHT_HP 0x815E
#define GL_IMAGE_MAG_FILTER_HP 0x815C
#define GL_IMAGE_MIN_FILTER_HP 0x815D
#define GL_IMAGE_ROTATE_ANGLE_HP 0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP 0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP 0x815B
#define GL_IMAGE_SCALE_X_HP 0x8155
#define GL_IMAGE_SCALE_Y_HP 0x8156
#define GL_IMAGE_TRANSFORM_2D_HP 0x8161
#define GL_IMAGE_TRANSLATE_X_HP 0x8157
#define GL_IMAGE_TRANSLATE_Y_HP 0x8158
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8163

#define GL_OCCLUSION_TEST_HP 0x8165
#define GL_OCCLUSION_TEST_RESULT_HP 0x8166

#define GL_TEXTURE_LIGHTING_MODE_HP 0x8167
#define GL_TEXTURE_POST_SPECULAR_HP 0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP 0x8169

#define GL_CULL_VERTEX_IBM 103050

#define GL_RASTER_POSITION_UNCLIPPED_IBM 0x19262

#define GL_ALL_STATIC_DATA_IBM 103060
#define GL_STATIC_VERTEX_ARRAY_IBM 103061

#define GL_MIRRORED_REPEAT_IBM 0x8370

#define GL_COLOR_ARRAY_LIST_IBM 103072
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM 103082
#define GL_EDGE_FLAG_ARRAY_LIST_IBM 103075
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM 103085
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM 103076
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM 103086
#define GL_INDEX_ARRAY_LIST_IBM 103073
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM 103083
#define GL_NORMAL_ARRAY_LIST_IBM 103071
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM 103081
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM 103077
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM 103087
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM 103074
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM 103084
#define GL_VERTEX_ARRAY_LIST_IBM 103070
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM 103080

#define GL_ALPHA_MAX_CLAMP_INGR 0x8567
#define GL_ALPHA_MIN_CLAMP_INGR 0x8563
#define GL_BLUE_MAX_CLAMP_INGR 0x8566
#define GL_BLUE_MIN_CLAMP_INGR 0x8562
#define GL_GREEN_MAX_CLAMP_INGR 0x8565
#define GL_GREEN_MIN_CLAMP_INGR 0x8561
#define GL_RED_MAX_CLAMP_INGR 0x8564
#define GL_RED_MIN_CLAMP_INGR 0x8560

#define GL_INTERLACE_READ_INGR 0x8568

#define GL_LAYOUT_DEFAULT_INTEL 0
#define GL_LAYOUT_LINEAR_CPU_CACHED_INTEL 2
#define GL_LAYOUT_LINEAR_INTEL 1
#define GL_TEXTURE_MEMORY_LAYOUT_INTEL 0x83FF

#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL 0x83F7
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL 0x83F6
#define GL_PARALLEL_ARRAYS_INTEL 0x83F4
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL 0x83F8
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL 0x83F5

#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR 0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR 0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR 0x93BA
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR 0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR 0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR 0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR 0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR 0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR 0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR 0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR 0x93B7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7

#define GL_PROXY_TEXTURE_1D_STACK_MESAX 0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX 0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX 0x875D
#define GL_TEXTURE_1D_STACK_MESAX 0x8759
#define GL_TEXTURE_2D_STACK_BINDING_MESAX 0x875E
#define GL_TEXTURE_2D_STACK_MESAX 0x875A

#define GL_PACK_INVERT_MESA 0x8758

#define GL_UNSIGNED_SHORT_8_8_MESA 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA 0x85BB
#define GL_YCBCR_MESA 0x8757

#define GL_BLEND_ADVANCED_COHERENT_NV 0x9285
#define GL_BLEND_OVERLAP_NV 0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV 0x9280
/*Copied GL_BLUE From: AMD_interleaved_elements*/
#define GL_COLORBURN_NV 0x929A
#define GL_COLORDODGE_NV 0x9299
#define GL_CONJOINT_NV 0x9284
#define GL_CONTRAST_NV 0x92A1
#define GL_DARKEN_NV 0x9297
#define GL_DIFFERENCE_NV 0x929E
#define GL_DISJOINT_NV 0x9283
#define GL_DST_ATOP_NV 0x928F
#define GL_DST_IN_NV 0x928B
#define GL_DST_NV 0x9287
#define GL_DST_OUT_NV 0x928D
#define GL_DST_OVER_NV 0x9289
#define GL_EXCLUSION_NV 0x92A0
/*Copied GL_GREEN From: AMD_interleaved_elements*/
#define GL_HARDLIGHT_NV 0x929B
#define GL_HARDMIX_NV 0x92A9
#define GL_HSL_COLOR_NV 0x92AF
#define GL_HSL_HUE_NV 0x92AD
#define GL_HSL_LUMINOSITY_NV 0x92B0
#define GL_HSL_SATURATION_NV 0x92AE
#define GL_INVERT 0x150A
#define GL_INVERT_OVG_NV 0x92B4
#define GL_INVERT_RGB_NV 0x92A3
#define GL_LIGHTEN_NV 0x9298
#define GL_LINEARBURN_NV 0x92A5
#define GL_LINEARDODGE_NV 0x92A4
#define GL_LINEARLIGHT_NV 0x92A7
#define GL_MINUS_CLAMPED_NV 0x92B3
#define GL_MINUS_NV 0x929F
#define GL_MULTIPLY_NV 0x9294
#define GL_OVERLAY_NV 0x9296
#define GL_PINLIGHT_NV 0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV 0x92B2
#define GL_PLUS_CLAMPED_NV 0x92B1
#define GL_PLUS_DARKER_NV 0x9292
#define GL_PLUS_NV 0x9291
/*Copied GL_RED From: AMD_interleaved_elements*/
#define GL_SCREEN_NV 0x9295
#define GL_SOFTLIGHT_NV 0x929C
#define GL_SRC_ATOP_NV 0x928E
#define GL_SRC_IN_NV 0x928A
#define GL_SRC_NV 0x9286
#define GL_SRC_OUT_NV 0x928C
#define GL_SRC_OVER_NV 0x9288
#define GL_UNCORRELATED_NV 0x9282
#define GL_VIVIDLIGHT_NV 0x92A6
#define GL_XOR 0x1506
#define GL_ZERO 0

#define GL_COMPUTE_PROGRAM_NV 0x90FB
#define GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV 0x90FC

#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_QUERY_WAIT_NV 0x8E13

#define GL_DEPTH_STENCIL_TO_BGRA_NV 0x886F
#define GL_DEPTH_STENCIL_TO_RGBA_NV 0x886E

#define GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV 0x90D1
#define GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV 0x90D0

#define GL_DEPTH32F_STENCIL8_NV 0x8DAC
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV 0x8DAF
#define GL_DEPTH_COMPONENT32F_NV 0x8DAB
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD

#define GL_DEPTH_CLAMP_NV 0x864F

#define GL_EVAL_2D_NV 0x86C0
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV 0x86C5
#define GL_EVAL_TRIANGULAR_2D_NV 0x86C1
#define GL_EVAL_VERTEX_ATTRIB0_NV 0x86C6
#define GL_EVAL_VERTEX_ATTRIB10_NV 0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV 0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV 0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV 0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV 0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV 0x86D5
#define GL_EVAL_VERTEX_ATTRIB1_NV 0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV 0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV 0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV 0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV 0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV 0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV 0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV 0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV 0x86CF
#define GL_MAP_ATTRIB_U_ORDER_NV 0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV 0x86C4
#define GL_MAP_TESSELLATION_NV 0x86C2
#define GL_MAX_MAP_TESSELLATION_NV 0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV 0x86D7

#define GL_INT_SAMPLER_RENDERBUFFER_NV 0x8E57
#define GL_MAX_SAMPLE_MASK_WORDS_NV 0x8E59
#define GL_SAMPLER_RENDERBUFFER_NV 0x8E56
#define GL_SAMPLE_MASK_NV 0x8E51
#define GL_SAMPLE_MASK_VALUE_NV 0x8E52
#define GL_SAMPLE_POSITION_NV 0x8E50
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV 0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV 0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV 0x8E55
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV 0x8E58

#define GL_ALL_COMPLETED_NV 0x84F2
#define GL_FENCE_CONDITION_NV 0x84F4
#define GL_FENCE_STATUS_NV 0x84F3

#define GL_FLOAT_CLEAR_COLOR_VALUE_NV 0x888D
#define GL_FLOAT_R16_NV 0x8884
#define GL_FLOAT_R32_NV 0x8885
#define GL_FLOAT_RG16_NV 0x8886
#define GL_FLOAT_RG32_NV 0x8887
#define GL_FLOAT_RGB16_NV 0x8888
#define GL_FLOAT_RGB32_NV 0x8889
#define GL_FLOAT_RGBA16_NV 0x888A
#define GL_FLOAT_RGBA32_NV 0x888B
#define GL_FLOAT_RGBA_MODE_NV 0x888E
#define GL_FLOAT_RGBA_NV 0x8883
#define GL_FLOAT_RGB_NV 0x8882
#define GL_FLOAT_RG_NV 0x8881
#define GL_FLOAT_R_NV 0x8880
#define GL_TEXTURE_FLOAT_COMPONENTS_NV 0x888C

#define GL_EYE_PLANE 0x2502
#define GL_EYE_PLANE_ABSOLUTE_NV 0x855C
#define GL_EYE_RADIAL_NV 0x855B
#define GL_FOG_DISTANCE_MODE_NV 0x855A

#define GL_FRAGMENT_PROGRAM_BINDING_NV 0x8873
#define GL_FRAGMENT_PROGRAM_NV 0x8870
#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868
#define GL_MAX_TEXTURE_COORDS_NV 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV 0x8872
#define GL_PROGRAM_ERROR_STRING_NV 0x8874

#define GL_MAX_PROGRAM_CALL_DEPTH_NV 0x88F5
#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_IF_DEPTH_NV 0x88F6
#define GL_MAX_PROGRAM_LOOP_COUNT_NV 0x88F8
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV 0x88F7

#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB

/*Copied GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT From: EXT_geometry_shader4*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT From: EXT_texture_array*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT From: EXT_geometry_shader4*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT From: EXT_geometry_shader4*/
/*Copied GL_GEOMETRY_INPUT_TYPE_EXT From: EXT_geometry_shader4*/
/*Copied GL_GEOMETRY_OUTPUT_TYPE_EXT From: EXT_geometry_shader4*/
#define GL_GEOMETRY_PROGRAM_NV 0x8C26
/*Copied GL_GEOMETRY_VERTICES_OUT_EXT From: EXT_geometry_shader4*/
/*Copied GL_LINES_ADJACENCY_EXT From: EXT_geometry_shader4*/
/*Copied GL_LINE_STRIP_ADJACENCY_EXT From: EXT_geometry_shader4*/
/*Copied GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT From: EXT_geometry_shader4*/
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV 0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV 0x8C28
/*Copied GL_PROGRAM_POINT_SIZE_EXT From: EXT_geometry_shader4*/
/*Copied GL_TRIANGLES_ADJACENCY_EXT From: EXT_geometry_shader4*/
/*Copied GL_TRIANGLE_STRIP_ADJACENCY_EXT From: EXT_geometry_shader4*/

#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV 0x8908
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV 0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV 0x8DA6
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV 0x8909
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV 0x8905
#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV 0x8904
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV 0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV 0x8907

#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV 0x8E5D
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5C
#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV 0x8E5A
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV 0x8F45
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV 0x8F44
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5F
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5B
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5E

#define GL_FLOAT16_NV 0x8FF8
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_FLOAT16_VEC4_NV 0x8FFB
#define GL_INT16_NV 0x8FE4
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_INT64_NV 0x140E
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_INT8_NV 0x8FE0
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_INT8_VEC4_NV 0x8FE3
/*Copied GL_PATCHES From: ARB_tessellation_shader*/
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF

#define GL_HALF_FLOAT_NV 0x140B

#define GL_MAX_SHININESS_NV 0x8504
#define GL_MAX_SPOT_EXPONENT_NV 0x8505

#define GL_COLOR_SAMPLES_NV 0x8E20
/*Copied GL_SAMPLES_ARB From: ARB_multisample*/

#define GL_MULTISAMPLE_FILTER_HINT_NV 0x8534

#define GL_CURRENT_OCCLUSION_QUERY_ID_NV 0x8865
#define GL_PIXEL_COUNTER_BITS_NV 0x8864
#define GL_PIXEL_COUNT_AVAILABLE_NV 0x8867
#define GL_PIXEL_COUNT_NV 0x8866

#define GL_DEPTH_STENCIL_NV 0x84F9
#define GL_UNSIGNED_INT_24_8_NV 0x84FA

#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV 0x8DA4
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV 0x8DA3
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV 0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV 0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV 0x8DA2

#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_AFFINE_2D_NV 0x9092
#define GL_AFFINE_3D_NV 0x9094
#define GL_ARC_TO_NV 0xFE
#define GL_BEVEL_NV 0x90A6
#define GL_BOLD_BIT_NV 0x01
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_CLOSE_PATH_NV 0x00
#define GL_CONVEX_HULL_NV 0x908B
#define GL_COUNT_DOWN_NV 0x9089
#define GL_COUNT_UP_NV 0x9088
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_FILE_NAME_NV 0x9074
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_FONT_ASCENDER_BIT_NV 0x00200000
#define GL_FONT_DESCENDER_BIT_NV 0x00400000
#define GL_FONT_HAS_KERNING_BIT_NV 0x10000000
#define GL_FONT_HEIGHT_BIT_NV 0x00800000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV 0x01000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_UNITS_PER_EM_BIT_NV 0x00100000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV 0x00040000
#define GL_FONT_X_MIN_BOUNDS_BIT_NV 0x00010000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV 0x00080000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV 0x00020000
#define GL_GLYPH_HAS_KERNING_BIT_NV 0x100
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_ITALIC_BIT_NV 0x02
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_LINE_TO_NV 0x04
#define GL_MITER_REVERT_NV 0x90A7
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_MOVE_TO_NV 0x02
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_PATH_FOG_GEN_MODE_NV 0x90AC
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_PATH_GEN_COLOR_FORMAT_NV 0x90B2
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_PRIMARY_COLOR 0x8577
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_RECT_NV 0xF6
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_RESTART_PATH_NV 0xF0
#define GL_ROUND_NV 0x90A4
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_SQUARE_NV 0x90A3
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_TRANSLATE_X_NV 0x908E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_TRIANGULAR_NV 0x90A5
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_UTF16_NV 0x909B
#define GL_UTF8_NV 0x909A
#define GL_VERTICAL_LINE_TO_NV 0x08

#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV 0x887B
#define GL_READ_PIXEL_DATA_RANGE_NV 0x8879
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV 0x887D
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV 0x887A
#define GL_WRITE_PIXEL_DATA_RANGE_NV 0x8878
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV 0x887C

#define GL_COORD_REPLACE_NV 0x8862
#define GL_POINT_SPRITE_NV 0x8861
#define GL_POINT_SPRITE_R_MODE_NV 0x8863

#define GL_CURRENT_TIME_NV 0x8E28
#define GL_FIELDS_NV 0x8E27
#define GL_FRAME_NV 0x8E26
#define GL_NUM_FILL_STREAMS_NV 0x8E29
#define GL_PRESENT_DURATION_NV 0x8E2B
#define GL_PRESENT_TIME_NV 0x8E2A

#define GL_PRIMITIVE_RESTART_INDEX_NV 0x8559
#define GL_PRIMITIVE_RESTART_NV 0x8558

#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_COMBINER0_NV 0x8550
#define GL_COMBINER1_NV 0x8551
#define GL_COMBINER2_NV 0x8552
#define GL_COMBINER3_NV 0x8553
#define GL_COMBINER4_NV 0x8554
#define GL_COMBINER5_NV 0x8555
#define GL_COMBINER6_NV 0x8556
#define GL_COMBINER7_NV 0x8557
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_DISCARD_NV 0x8530
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_E_TIMES_F_NV 0x8531
#define GL_FOG 0x0B60
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
#define GL_NONE 0
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
/*Copied GL_PRIMARY_COLOR_NV From: NV_path_rendering*/
#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_SCALE_BY_TWO_NV 0x853E
/*Copied GL_SECONDARY_COLOR_NV From: NV_path_rendering*/
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_SPARE0_NV 0x852E
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_SPARE1_NV 0x852F
/*Copied GL_TEXTURE0_ARB From: ARB_multitexture*/
/*Copied GL_TEXTURE1_ARB From: ARB_multitexture*/
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_VARIABLE_A_NV 0x8523
#define GL_VARIABLE_B_NV 0x8524
#define GL_VARIABLE_C_NV 0x8525
#define GL_VARIABLE_D_NV 0x8526
#define GL_VARIABLE_E_NV 0x8527
#define GL_VARIABLE_F_NV 0x8528
#define GL_VARIABLE_G_NV 0x8529
/*Copied GL_ZERO From: NV_blend_equation_advanced*/

#define GL_PER_STAGE_CONSTANTS_NV 0x8535

#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35

#define GL_READ_WRITE 0x88BA
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#define GL_WRITE_ONLY 0x88B9

#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV 0x86D8
#define GL_TESS_CONTROL_PROGRAM_NV 0x891E
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV 0x8C74
#define GL_TESS_EVALUATION_PROGRAM_NV 0x891F
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV 0x8C75

#define GL_EMBOSS_CONSTANT_NV 0x855E
#define GL_EMBOSS_LIGHT_NV 0x855D
#define GL_EMBOSS_MAP_NV 0x855F

#define GL_NORMAL_MAP_NV 0x8511
#define GL_REFLECTION_MAP_NV 0x8512

#define GL_COMBINE4_NV 0x8503
#define GL_OPERAND3_ALPHA_NV 0x859B
#define GL_OPERAND3_RGB_NV 0x8593
#define GL_SOURCE3_ALPHA_NV 0x858B
#define GL_SOURCE3_RGB_NV 0x8583

#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV 0x888F

#define GL_TEXTURE_COLOR_SAMPLES_NV 0x9046
#define GL_TEXTURE_COVERAGE_SAMPLES_NV 0x9045

#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV 0x84F8
#define GL_PROXY_TEXTURE_RECTANGLE_NV 0x84F7
#define GL_TEXTURE_BINDING_RECTANGLE_NV 0x84F6
#define GL_TEXTURE_RECTANGLE_NV 0x84F5

#define GL_CONST_EYE_NV 0x86E5
#define GL_CULL_FRAGMENT_NV 0x86E7
#define GL_CULL_MODES_NV 0x86E0
#define GL_DEPENDENT_AR_TEXTURE_2D_NV 0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV 0x86EA
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV 0x86ED
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
#define GL_DOT_PRODUCT_NV 0x86EC
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
#define GL_DOT_PRODUCT_TEXTURE_2D_NV 0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
#define GL_DSDT8_MAG8_INTENSITY8_NV 0x870B
#define GL_DSDT8_MAG8_NV 0x870A
#define GL_DSDT8_NV 0x8709
#define GL_DSDT_MAG_INTENSITY_NV 0x86DC
#define GL_DSDT_MAG_NV 0x86F6
#define GL_DSDT_MAG_VIB_NV 0x86F7
#define GL_DSDT_NV 0x86F5
#define GL_DS_BIAS_NV 0x8716
#define GL_DS_SCALE_NV 0x8710
#define GL_DT_BIAS_NV 0x8717
#define GL_DT_SCALE_NV 0x8711
#define GL_HILO16_NV 0x86F8
#define GL_HILO_NV 0x86F4
#define GL_HI_BIAS_NV 0x8714
#define GL_HI_SCALE_NV 0x870E
#define GL_LO_BIAS_NV 0x8715
#define GL_LO_SCALE_NV 0x870F
#define GL_MAGNITUDE_BIAS_NV 0x8718
#define GL_MAGNITUDE_SCALE_NV 0x8712
#define GL_OFFSET_TEXTURE_2D_BIAS_NV 0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_2D_NV 0x86E8
#define GL_OFFSET_TEXTURE_2D_SCALE_NV 0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV 0x86E3
#define GL_OFFSET_TEXTURE_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_RECTANGLE_NV 0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
#define GL_OFFSET_TEXTURE_SCALE_NV 0x86E2
#define GL_PASS_THROUGH_NV 0x86E6
#define GL_PREVIOUS_TEXTURE_INPUT_NV 0x86E4
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
#define GL_SHADER_CONSISTENT_NV 0x86DD
#define GL_SHADER_OPERATION_NV 0x86DF
#define GL_SIGNED_ALPHA8_NV 0x8706
#define GL_SIGNED_ALPHA_NV 0x8705
#define GL_SIGNED_HILO16_NV 0x86FA
#define GL_SIGNED_HILO_NV 0x86F9
#define GL_SIGNED_INTENSITY8_NV 0x8708
#define GL_SIGNED_INTENSITY_NV 0x8707
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV 0x8704
#define GL_SIGNED_LUMINANCE8_NV 0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV 0x8703
#define GL_SIGNED_LUMINANCE_NV 0x8701
#define GL_SIGNED_RGB8_NV 0x86FF
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
#define GL_SIGNED_RGBA8_NV 0x86FC
#define GL_SIGNED_RGBA_NV 0x86FB
#define GL_SIGNED_RGB_NV 0x86FE
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV 0x870C
#define GL_TEXTURE_BORDER_VALUES_NV 0x871A
#define GL_TEXTURE_DS_SIZE_NV 0x871D
#define GL_TEXTURE_DT_SIZE_NV 0x871E
#define GL_TEXTURE_HI_SIZE_NV 0x871B
#define GL_TEXTURE_LO_SIZE_NV 0x871C
#define GL_TEXTURE_MAG_SIZE_NV 0x871F
#define GL_TEXTURE_SHADER_NV 0x86DE
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV 0x86DB
#define GL_UNSIGNED_INT_S8_S8_8_8_NV 0x86DA
#define GL_VIBRANCE_BIAS_NV 0x8719
#define GL_VIBRANCE_SCALE_NV 0x8713

#define GL_DOT_PRODUCT_TEXTURE_3D_NV 0x86EF

#define GL_DEPENDENT_HILO_TEXTURE_2D_NV 0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV 0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV 0x885A
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV 0x885D
#define GL_DOT_PRODUCT_PASS_THROUGH_NV 0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV 0x885C
#define GL_FORCE_BLUE_TO_ONE_NV 0x8860
#define GL_HILO8_NV 0x885E
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV 0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8857
#define GL_OFFSET_HILO_TEXTURE_2D_NV 0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV 0x8855
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV 0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_SIGNED_HILO8_NV 0x885F

#define GL_ACTIVE_VARYINGS_NV 0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV 0x8C82
#define GL_BACK_PRIMARY_COLOR_NV 0x8C77
#define GL_BACK_SECONDARY_COLOR_NV 0x8C78
#define GL_CLIP_DISTANCE_NV 0x8C7A
#define GL_GENERIC_ATTRIB_NV 0x8C7D
#define GL_INTERLEAVED_ATTRIBS_NV 0x8C8C
#define GL_LAYER_NV 0x8DAA
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV 0x8C80
#define GL_NEXT_BUFFER_NV -2
#define GL_PRIMITIVES_GENERATED_NV 0x8C87
#define GL_PRIMITIVE_ID_NV 0x8C7C
#define GL_RASTERIZER_DISCARD_NV 0x8C89
#define GL_SEPARATE_ATTRIBS_NV 0x8C8D
#define GL_SKIP_COMPONENTS1_NV -6
#define GL_SKIP_COMPONENTS2_NV -5
#define GL_SKIP_COMPONENTS3_NV -4
#define GL_SKIP_COMPONENTS4_NV -3
#define GL_TEXTURE_COORD_NV 0x8C79
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV 0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV 0x8C8F
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV 0x8C7F
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV 0x8C84
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV 0x8C88
#define GL_TRANSFORM_FEEDBACK_RECORD_NV 0x8C86
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV 0x8C83
#define GL_VERTEX_ID_NV 0x8C7B

#define GL_TRANSFORM_FEEDBACK_BINDING_NV 0x8E25
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV 0x8E24
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV 0x8E23
#define GL_TRANSFORM_FEEDBACK_NV 0x8E22

#define GL_SURFACE_MAPPED_NV 0x8700
#define GL_SURFACE_REGISTERED_NV 0x86FD
#define GL_SURFACE_STATE_NV 0x86EB
#define GL_WRITE_DISCARD_NV 0x88BE

#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV 0x851E
#define GL_VERTEX_ARRAY_RANGE_NV 0x851D
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV 0x8521
#define GL_VERTEX_ARRAY_RANGE_VALID_NV 0x851F

#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533

/*Copied GL_INT64_NV From: NV_gpu_shader5*/
/*Copied GL_UNSIGNED_INT64_NV From: NV_gpu_shader5*/

#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E

#define GL_ATTRIB_ARRAY_POINTER_NV 0x8645
#define GL_ATTRIB_ARRAY_SIZE_NV 0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV 0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV 0x8625
#define GL_CURRENT_ATTRIB_NV 0x8626
#define GL_CURRENT_MATRIX_NV 0x8641
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV 0x8640
#define GL_IDENTITY_NV 0x862A
#define GL_INVERSE_NV 0x862B
#define GL_INVERSE_TRANSPOSE_NV 0x862D
#define GL_MAP1_VERTEX_ATTRIB0_4_NV 0x8660
#define GL_MAP1_VERTEX_ATTRIB10_4_NV 0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV 0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV 0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV 0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV 0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV 0x866F
#define GL_MAP1_VERTEX_ATTRIB1_4_NV 0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV 0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV 0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV 0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV 0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV 0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV 0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV 0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV 0x8669
#define GL_MAP2_VERTEX_ATTRIB0_4_NV 0x8670
#define GL_MAP2_VERTEX_ATTRIB10_4_NV 0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV 0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV 0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV 0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV 0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV 0x867F
#define GL_MAP2_VERTEX_ATTRIB1_4_NV 0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV 0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV 0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV 0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV 0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV 0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV 0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV 0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV 0x8679
#define GL_MATRIX0_NV 0x8630
#define GL_MATRIX1_NV 0x8631
#define GL_MATRIX2_NV 0x8632
#define GL_MATRIX3_NV 0x8633
#define GL_MATRIX4_NV 0x8634
#define GL_MATRIX5_NV 0x8635
#define GL_MATRIX6_NV 0x8636
#define GL_MATRIX7_NV 0x8637
#define GL_MAX_TRACK_MATRICES_NV 0x862F
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
#define GL_MODELVIEW_PROJECTION_NV 0x8629
#define GL_PROGRAM_ERROR_POSITION_NV 0x864B
#define GL_PROGRAM_LENGTH_NV 0x8627
#define GL_PROGRAM_PARAMETER_NV 0x8644
#define GL_PROGRAM_RESIDENT_NV 0x8647
#define GL_PROGRAM_STRING_NV 0x8628
#define GL_PROGRAM_TARGET_NV 0x8646
#define GL_TRACK_MATRIX_NV 0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV 0x8649
#define GL_TRANSPOSE_NV 0x862C
#define GL_VERTEX_ATTRIB_ARRAY0_NV 0x8650
#define GL_VERTEX_ATTRIB_ARRAY10_NV 0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV 0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV 0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV 0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV 0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV 0x865F
#define GL_VERTEX_ATTRIB_ARRAY1_NV 0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV 0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV 0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV 0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV 0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV 0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV 0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV 0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV 0x8659
#define GL_VERTEX_PROGRAM_BINDING_NV 0x864A
#define GL_VERTEX_PROGRAM_NV 0x8620
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV 0x8643
#define GL_VERTEX_STATE_PROGRAM_NV 0x8621

/*Copied GL_MAX_PROGRAM_CALL_DEPTH_NV From: NV_fragment_program2*/
/*Copied GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV From: NV_fragment_program2*/

/*Copied GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB From: ARB_vertex_shader*/

#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV 0x88FD

#define GL_FAILURE_NV 0x9030
#define GL_FIELD_LOWER_NV 0x9023
#define GL_FIELD_UPPER_NV 0x9022
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV 0x9027
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV 0x9025
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV 0x9024
#define GL_PARTIAL_SUCCESS_NV 0x902E
#define GL_SUCCESS_NV 0x902F
#define GL_VIDEO_BUFFER_BINDING_NV 0x9021
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV 0x902D
#define GL_VIDEO_BUFFER_NV 0x9020
#define GL_VIDEO_BUFFER_PITCH_NV 0x9028
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV 0x903B
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV 0x903A
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV 0x9039
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV 0x9038
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV 0x903C
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV 0x9026
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV 0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV 0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV 0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV 0x902C
#define GL_YCBAYCR8A_4224_NV 0x9032
#define GL_YCBYCR8_422_NV 0x9031
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV 0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV 0x9037
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV 0x9035
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV 0x9034
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV 0x9033

#define GL_PALETTE4_R5_G6_B5_OES 0x8B92
#define GL_PALETTE4_RGB5_A1_OES 0x8B94
#define GL_PALETTE4_RGB8_OES 0x8B90
#define GL_PALETTE4_RGBA4_OES 0x8B93
#define GL_PALETTE4_RGBA8_OES 0x8B91
#define GL_PALETTE8_R5_G6_B5_OES 0x8B97
#define GL_PALETTE8_RGB5_A1_OES 0x8B99
#define GL_PALETTE8_RGB8_OES 0x8B95
#define GL_PALETTE8_RGBA4_OES 0x8B98
#define GL_PALETTE8_RGBA8_OES 0x8B96

#define GL_FIXED_OES 0x140C

#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES 0x8B9B
#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES 0x8B9A

#define GL_INTERLACE_OML 0x8980
#define GL_INTERLACE_READ_OML 0x8981

#define GL_PACK_RESAMPLE_OML 0x8984
#define GL_RESAMPLE_AVERAGE_OML 0x8988
#define GL_RESAMPLE_DECIMATE_OML 0x8989
#define GL_RESAMPLE_REPLICATE_OML 0x8986
#define GL_RESAMPLE_ZERO_FILL_OML 0x8987
#define GL_UNPACK_RESAMPLE_OML 0x8985

#define GL_FORMAT_SUBSAMPLE_244_244_OML 0x8983
#define GL_FORMAT_SUBSAMPLE_24_24_OML 0x8982

#define GL_ALLOW_DRAW_FRG_HINT_PGI 0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI 0x1A211
#define GL_ALLOW_DRAW_OBJ_HINT_PGI 0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI 0x1A20F
#define GL_ALWAYS_FAST_HINT_PGI 0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI 0x1A20D
#define GL_BACK_NORMALS_HINT_PGI 0x1A223
#define GL_CLIP_FAR_HINT_PGI 0x1A221
#define GL_CLIP_NEAR_HINT_PGI 0x1A220
#define GL_CONSERVE_MEMORY_HINT_PGI 0x1A1FD
#define GL_FULL_STIPPLE_HINT_PGI 0x1A219
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI 0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI 0x1A204
#define GL_NATIVE_GRAPHICS_HANDLE_PGI 0x1A202
#define GL_PREFER_DOUBLEBUFFER_HINT_PGI 0x1A1F8
#define GL_RECLAIM_MEMORY_HINT_PGI 0x1A1FE
#define GL_STRICT_DEPTHFUNC_HINT_PGI 0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI 0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI 0x1A218
#define GL_WIDE_LINE_HINT_PGI 0x1A222

#define GL_COLOR3_BIT_PGI 0x00010000
#define GL_COLOR4_BIT_PGI 0x00020000
#define GL_EDGEFLAG_BIT_PGI 0x00040000
#define GL_INDEX_BIT_PGI 0x00080000
#define GL_MATERIAL_SIDE_HINT_PGI 0x1A22C
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI 0x00200000
#define GL_MAT_AMBIENT_BIT_PGI 0x00100000
#define GL_MAT_COLOR_INDEXES_BIT_PGI 0x01000000
#define GL_MAT_DIFFUSE_BIT_PGI 0x00400000
#define GL_MAT_EMISSION_BIT_PGI 0x00800000
#define GL_MAT_SHININESS_BIT_PGI 0x02000000
#define GL_MAT_SPECULAR_BIT_PGI 0x04000000
#define GL_MAX_VERTEX_HINT_PGI 0x1A22D
#define GL_NORMAL_BIT_PGI 0x08000000
#define GL_TEXCOORD1_BIT_PGI 0x10000000
#define GL_TEXCOORD2_BIT_PGI 0x20000000
#define GL_TEXCOORD3_BIT_PGI 0x40000000
#define GL_TEXCOORD4_BIT_PGI 0x80000000
#define GL_VERTEX23_BIT_PGI 0x00000004
#define GL_VERTEX4_BIT_PGI 0x00000008
#define GL_VERTEX_CONSISTENT_HINT_PGI 0x1A22B
#define GL_VERTEX_DATA_HINT_PGI 0x1A22A

#define GL_INVERTED_SCREEN_W_REND 0x8491
#define GL_SCREEN_COORDINATES_REND 0x8490

#define GL_RGB4_S3TC 0x83A1
#define GL_RGBA4_DXT5_S3TC 0x83A5
#define GL_RGBA4_S3TC 0x83A3
#define GL_RGBA_DXT5_S3TC 0x83A4
#define GL_RGBA_S3TC 0x83A2
#define GL_RGB_S3TC 0x83A0

#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS 0x8096
#define GL_DETAIL_TEXTURE_2D_SGIS 0x8095
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS 0x809C
#define GL_DETAIL_TEXTURE_LEVEL_SGIS 0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS 0x809B
#define GL_LINEAR_DETAIL_ALPHA_SGIS 0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS 0x8099
#define GL_LINEAR_DETAIL_SGIS 0x8097

#define GL_FOG_FUNC_POINTS_SGIS 0x812B
#define GL_FOG_FUNC_SGIS 0x812A
#define GL_MAX_FOG_FUNC_POINTS_SGIS 0x812C

#define GL_GENERATE_MIPMAP_HINT_SGIS 0x8192
#define GL_GENERATE_MIPMAP_SGIS 0x8191

#define GL_1PASS_SGIS 0x80A1
#define GL_2PASS_0_SGIS 0x80A2
#define GL_2PASS_1_SGIS 0x80A3
#define GL_4PASS_0_SGIS 0x80A4
#define GL_4PASS_1_SGIS 0x80A5
#define GL_4PASS_2_SGIS 0x80A6
#define GL_4PASS_3_SGIS 0x80A7
#define GL_MULTISAMPLE_SGIS 0x809D
#define GL_SAMPLES_SGIS 0x80A9
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS 0x809F
#define GL_SAMPLE_BUFFERS_SGIS 0x80A8
#define GL_SAMPLE_MASK_INVERT_SGIS 0x80AB
#define GL_SAMPLE_MASK_SGIS 0x80A0
#define GL_SAMPLE_MASK_VALUE_SGIS 0x80AA
#define GL_SAMPLE_PATTERN_SGIS 0x80AC

#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS 0x8354
#define GL_PIXEL_GROUP_COLOR_SGIS 0x8356
#define GL_PIXEL_TEXTURE_SGIS 0x8353

#define GL_EYE_DISTANCE_TO_LINE_SGIS 0x81F2
#define GL_EYE_DISTANCE_TO_POINT_SGIS 0x81F0
#define GL_EYE_LINE_SGIS 0x81F6
#define GL_EYE_POINT_SGIS 0x81F4
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS 0x81F3
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS 0x81F1
#define GL_OBJECT_LINE_SGIS 0x81F7
#define GL_OBJECT_POINT_SGIS 0x81F5

#define GL_DISTANCE_ATTENUATION_SGIS 0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS 0x8128
#define GL_POINT_SIZE_MAX_SGIS 0x8127
#define GL_POINT_SIZE_MIN_SGIS 0x8126

#define GL_LINEAR_SHARPEN_ALPHA_SGIS 0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS 0x80AF
#define GL_LINEAR_SHARPEN_SGIS 0x80AD
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0

#define GL_MAX_4D_TEXTURE_SIZE_SGIS 0x8138
#define GL_PACK_IMAGE_DEPTH_SGIS 0x8131
#define GL_PACK_SKIP_VOLUMES_SGIS 0x8130
#define GL_PROXY_TEXTURE_4D_SGIS 0x8135
#define GL_TEXTURE_4DSIZE_SGIS 0x8136
#define GL_TEXTURE_4D_BINDING_SGIS 0x814F
#define GL_TEXTURE_4D_SGIS 0x8134
#define GL_TEXTURE_WRAP_Q_SGIS 0x8137
#define GL_UNPACK_IMAGE_DEPTH_SGIS 0x8133
#define GL_UNPACK_SKIP_VOLUMES_SGIS 0x8132

#define GL_CLAMP_TO_BORDER_SGIS 0x812D

#define GL_TEXTURE_COLOR_WRITEMASK_SGIS 0x81EF

#define GL_CLAMP_TO_EDGE_SGIS 0x812F

#define GL_FILTER4_SGIS 0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS 0x8147

#define GL_TEXTURE_BASE_LEVEL_SGIS 0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS 0x813D
#define GL_TEXTURE_MAX_LOD_SGIS 0x813B
#define GL_TEXTURE_MIN_LOD_SGIS 0x813A

#define GL_DUAL_ALPHA12_SGIS 0x8112
#define GL_DUAL_ALPHA16_SGIS 0x8113
#define GL_DUAL_ALPHA4_SGIS 0x8110
#define GL_DUAL_ALPHA8_SGIS 0x8111
#define GL_DUAL_INTENSITY12_SGIS 0x811A
#define GL_DUAL_INTENSITY16_SGIS 0x811B
#define GL_DUAL_INTENSITY4_SGIS 0x8118
#define GL_DUAL_INTENSITY8_SGIS 0x8119
#define GL_DUAL_LUMINANCE12_SGIS 0x8116
#define GL_DUAL_LUMINANCE16_SGIS 0x8117
#define GL_DUAL_LUMINANCE4_SGIS 0x8114
#define GL_DUAL_LUMINANCE8_SGIS 0x8115
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS 0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS 0x811D
#define GL_DUAL_TEXTURE_SELECT_SGIS 0x8124
#define GL_QUAD_ALPHA4_SGIS 0x811E
#define GL_QUAD_ALPHA8_SGIS 0x811F
#define GL_QUAD_INTENSITY4_SGIS 0x8122
#define GL_QUAD_INTENSITY8_SGIS 0x8123
#define GL_QUAD_LUMINANCE4_SGIS 0x8120
#define GL_QUAD_LUMINANCE8_SGIS 0x8121
#define GL_QUAD_TEXTURE_SELECT_SGIS 0x8125

#define GL_ASYNC_MARKER_SGIX 0x8329

#define GL_ASYNC_HISTOGRAM_SGIX 0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX 0x832D

#define GL_ASYNC_DRAW_PIXELS_SGIX 0x835D
#define GL_ASYNC_READ_PIXELS_SGIX 0x835E
#define GL_ASYNC_TEX_IMAGE_SGIX 0x835C
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX 0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX 0x8361
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX 0x835F

#define GL_ALPHA_MAX_SGIX 0x8321
#define GL_ALPHA_MIN_SGIX 0x8320

#define GL_CALLIGRAPHIC_FRAGMENT_SGIX 0x8183

#define GL_LINEAR_CLIPMAP_LINEAR_SGIX 0x8170
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX 0x844F
#define GL_MAX_CLIPMAP_DEPTH_SGIX 0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8178
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX 0x844E
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX 0x844D
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX 0x8171
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX 0x8176
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX 0x8172
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX 0x8175
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX 0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174

#define GL_CONVOLUTION_HINT_SGIX 0x8316

#define GL_DEPTH_COMPONENT16_SGIX 0x81A5
#define GL_DEPTH_COMPONENT24_SGIX 0x81A6
#define GL_DEPTH_COMPONENT32_SGIX 0x81A7

#define GL_FOG_OFFSET_SGIX 0x8198
#define GL_FOG_OFFSET_VALUE_SGIX 0x8199

#define GL_CURRENT_RASTER_NORMAL_SGIX 0x8406
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX 0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX 0x8403
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX 0x8401
#define GL_FRAGMENT_LIGHT0_SGIX 0x840C
#define GL_FRAGMENT_LIGHT1_SGIX 0x840D
#define GL_FRAGMENT_LIGHT2_SGIX 0x840E
#define GL_FRAGMENT_LIGHT3_SGIX 0x840F
#define GL_FRAGMENT_LIGHT4_SGIX 0x8410
#define GL_FRAGMENT_LIGHT5_SGIX 0x8411
#define GL_FRAGMENT_LIGHT6_SGIX 0x8412
#define GL_FRAGMENT_LIGHT7_SGIX 0x8413
#define GL_FRAGMENT_LIGHTING_SGIX 0x8400
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX 0x840A
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX 0x8408
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX 0x840B
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX 0x8409
#define GL_LIGHT_ENV_MODE_SGIX 0x8407
#define GL_MAX_ACTIVE_LIGHTS_SGIX 0x8405
#define GL_MAX_FRAGMENT_LIGHTS_SGIX 0x8404

#define GL_FRAMEZOOM_FACTOR_SGIX 0x818C
#define GL_FRAMEZOOM_SGIX 0x818B
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX 0x818D

#define GL_INSTRUMENT_BUFFER_POINTER_SGIX 0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX 0x8181

#define GL_INTERLACE_SGIX 0x8094

#define GL_IR_INSTRUMENT1_SGIX 0x817F

#define GL_LIST_PRIORITY_SGIX 0x8182

#define GL_PIXEL_TEX_GEN_MODE_SGIX 0x832B
#define GL_PIXEL_TEX_GEN_SGIX 0x8139

#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX 0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX 0x813F
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX 0x8145
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX 0x8144
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX 0x8143
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX 0x8142
#define GL_PIXEL_TILE_HEIGHT_SGIX 0x8141
#define GL_PIXEL_TILE_WIDTH_SGIX 0x8140

#define GL_DEFORMATIONS_MASK_SGIX 0x8196
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX 0x00000002
#define GL_GEOMETRY_DEFORMATION_SGIX 0x8194
#define GL_MAX_DEFORMATION_ORDER_SGIX 0x8197
#define GL_TEXTURE_DEFORMATION_BIT_SGIX 0x00000001
#define GL_TEXTURE_DEFORMATION_SGIX 0x8195

#define GL_REFERENCE_PLANE_EQUATION_SGIX 0x817E
#define GL_REFERENCE_PLANE_SGIX 0x817D

#define GL_PACK_RESAMPLE_SGIX 0x842C
#define GL_RESAMPLE_DECIMATE_SGIX 0x8430
#define GL_RESAMPLE_REPLICATE_SGIX 0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX 0x842F
#define GL_UNPACK_RESAMPLE_SGIX 0x842D

#define GL_SCALEBIAS_HINT_SGIX 0x8322

#define GL_TEXTURE_COMPARE_OPERATOR_SGIX 0x819B
#define GL_TEXTURE_COMPARE_SGIX 0x819A
#define GL_TEXTURE_GEQUAL_R_SGIX 0x819D
#define GL_TEXTURE_LEQUAL_R_SGIX 0x819C

#define GL_SHADOW_AMBIENT_SGIX 0x80BF

#define GL_SPRITE_AXIAL_SGIX 0x814C
#define GL_SPRITE_AXIS_SGIX 0x814A
#define GL_SPRITE_EYE_ALIGNED_SGIX 0x814E
#define GL_SPRITE_MODE_SGIX 0x8149
#define GL_SPRITE_OBJECT_ALIGNED_SGIX 0x814D
#define GL_SPRITE_SGIX 0x8148
#define GL_SPRITE_TRANSLATION_SGIX 0x814B

#define GL_PACK_SUBSAMPLE_RATE_SGIX 0x85A0
#define GL_PIXEL_SUBSAMPLE_2424_SGIX 0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX 0x85A4
#define GL_PIXEL_SUBSAMPLE_4444_SGIX 0x85A2
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX 0x85A1

#define GL_TEXTURE_ENV_BIAS_SGIX 0x80BE

#define GL_TEXTURE_MAX_CLAMP_R_SGIX 0x836B
#define GL_TEXTURE_MAX_CLAMP_S_SGIX 0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX 0x836A

#define GL_TEXTURE_LOD_BIAS_R_SGIX 0x8190
#define GL_TEXTURE_LOD_BIAS_S_SGIX 0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX 0x818F

#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX 0x812E

#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
#define GL_POST_TEXTURE_FILTER_BIAS_SGIX 0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX 0x817A

#define GL_VERTEX_PRECLIP_HINT_SGIX 0x83EF
#define GL_VERTEX_PRECLIP_SGIX 0x83EE

#define GL_YCRCB_422_SGIX 0x81BB
#define GL_YCRCB_444_SGIX 0x81BC

#define GL_YCRCBA_SGIX 0x8319
#define GL_YCRCB_SGIX 0x8318

#define GL_COLOR_MATRIX_SGI 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B3
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI 0x80BB
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI 0x80B7
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI 0x80BA
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI 0x80B6
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI 0x80B9
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI 0x80B5
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI 0x80B8
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI 0x80B4

#define GL_COLOR_TABLE_ALPHA_SIZE_SGI 0x80DD
#define GL_COLOR_TABLE_BIAS_SGI 0x80D7
#define GL_COLOR_TABLE_BLUE_SIZE_SGI 0x80DC
#define GL_COLOR_TABLE_FORMAT_SGI 0x80D8
#define GL_COLOR_TABLE_GREEN_SIZE_SGI 0x80DB
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI 0x80DF
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI 0x80DE
#define GL_COLOR_TABLE_RED_SIZE_SGI 0x80DA
#define GL_COLOR_TABLE_SCALE_SGI 0x80D6
#define GL_COLOR_TABLE_SGI 0x80D0
#define GL_COLOR_TABLE_WIDTH_SGI 0x80D9
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D2
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D1
#define GL_PROXY_COLOR_TABLE_SGI 0x80D3
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D5
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D4

#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI 0x80BD
#define GL_TEXTURE_COLOR_TABLE_SGI 0x80BC

#define GL_TEXTURE_CONSTANT_DATA_SUNX 0x81D6
#define GL_UNPACK_CONSTANT_DATA_SUNX 0x81D5

#define GL_WRAP_BORDER_SUN 0x81D4

#define GL_GLOBAL_ALPHA_FACTOR_SUN 0x81DA
#define GL_GLOBAL_ALPHA_SUN 0x81D9

#define GL_QUAD_MESH_SUN 0x8614
#define GL_TRIANGLE_MESH_SUN 0x8615

#define GL_SLICE_ACCUM_SUN 0x85CC

#define GL_R1UI_C3F_V3F_SUN 0x85C6
#define GL_R1UI_C4F_N3F_V3F_SUN 0x85C8
#define GL_R1UI_C4UB_V3F_SUN 0x85C5
#define GL_R1UI_N3F_V3F_SUN 0x85C7
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN 0x85CB
#define GL_R1UI_T2F_N3F_V3F_SUN 0x85CA
#define GL_R1UI_T2F_V3F_SUN 0x85C9
#define GL_R1UI_V3F_SUN 0x85C4
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN 0x85C3
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN 0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_SUN 0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN 0x85C1
#define GL_REPLACEMENT_CODE_SUN 0x81D8
#define GL_REPLACE_MIDDLE_SUN 0x0002
#define GL_REPLACE_OLDEST_SUN 0x0003
#define GL_RESTART_SUN 0x0001
#define GL_TRIANGLE_LIST_SUN 0x81D7

#define GL_PHONG_HINT_WIN 0x80EB
#define GL_PHONG_WIN 0x80EA

#define GL_FOG_SPECULAR_TEXTURE_WIN 0x80EC

#define GL_2D 0x0600
#define GL_2_BYTES 0x1407
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_3_BYTES 0x1408
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_4_BYTES 0x1409
#define GL_ACCUM 0x0100
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ADD 0x0104
#define GL_ALL_ATTRIB_BITS 0xFFFFFFFF
/*Copied GL_ALPHA From: AMD_interleaved_elements*/
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_ALPHA_BITS 0x0D55
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_ALWAYS 0x0207
#define GL_AMBIENT 0x1200
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_AND 0x1501
#define GL_AND_INVERTED 0x1504
#define GL_AND_REVERSE 0x1502
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_AUTO_NORMAL 0x0D80
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_AUX_BUFFERS 0x0C00
#define GL_BACK 0x0405
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_BITMAP 0x1A00
#define GL_BITMAP_TOKEN 0x0704
#define GL_BLEND 0x0BE2
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
/*Copied GL_BLUE From: NV_blend_equation_advanced*/
#define GL_BLUE_BIAS 0x0D1B
#define GL_BLUE_BITS 0x0D54
#define GL_BLUE_SCALE 0x0D1A
#define GL_BYTE 0x1400
#define GL_C3F_V3F 0x2A24
#define GL_C4F_N3F_V3F 0x2A26
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
/*Copied GL_CCW From: ARB_tessellation_shader*/
#define GL_CLAMP 0x2900
#define GL_CLEAR 0x1500
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_COEFF 0x0A00
#define GL_COLOR 0x1800
#define GL_COLOR_ARRAY 0x8076
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_INDEX 0x1900
#define GL_COLOR_INDEXES 0x1603
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_COLOR_MATERIAL 0x0B57
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_COPY 0x1503
#define GL_COPY_INVERTED 0x150C
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_CURRENT_BIT 0x00000001
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
/*Copied GL_CW From: ARB_tessellation_shader*/
#define GL_DECAL 0x2101
#define GL_DECR 0x1E03
#define GL_DEPTH 0x1801
#define GL_DEPTH_BIAS 0x0D1F
#define GL_DEPTH_BITS 0x0D56
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_COMPONENT 0x1902
#define GL_DEPTH_FUNC 0x0B74
/*Copied GL_DEPTH_RANGE From: ARB_viewport_array*/
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DIFFUSE 0x1201
#define GL_DITHER 0x0BD0
#define GL_DOMAIN 0x0A02
#define GL_DONT_CARE 0x1100
/*Copied GL_DOUBLE From: EXT_vertex_attrib_64bit*/
#define GL_DOUBLEBUFFER 0x0C32
#define GL_DRAW_BUFFER 0x0C01
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_DST_ALPHA 0x0304
#define GL_DST_COLOR 0x0306
#define GL_EDGE_FLAG 0x0B43
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_EMISSION 0x1600
#define GL_ENABLE_BIT 0x00002000
/*Copied GL_EQUAL From: ARB_tessellation_shader*/
#define GL_EQUIV 0x1509
#define GL_EVAL_BIT 0x00010000
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_EXTENSIONS 0x1F03
#define GL_EYE_LINEAR 0x2400
/*Copied GL_EYE_PLANE From: NV_fog_distance*/
#define GL_FALSE 0
#define GL_FASTEST 0x1101
#define GL_FEEDBACK 0x1C01
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_FILL 0x1B02
#define GL_FLAT 0x1D00
#define GL_FLOAT 0x1406
/*Copied GL_FOG From: NV_register_combiners*/
#define GL_FOG_BIT 0x00000080
#define GL_FOG_COLOR 0x0B66
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_END 0x0B64
#define GL_FOG_HINT 0x0C54
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_MODE 0x0B65
#define GL_FOG_START 0x0B63
#define GL_FRONT 0x0404
#define GL_FRONT_AND_BACK 0x0408
#define GL_FRONT_FACE 0x0B46
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_GEQUAL 0x0206
#define GL_GREATER 0x0204
/*Copied GL_GREEN From: NV_blend_equation_advanced*/
#define GL_GREEN_BIAS 0x0D19
#define GL_GREEN_BITS 0x0D53
#define GL_GREEN_SCALE 0x0D18
#define GL_HINT_BIT 0x00008000
#define GL_INCR 0x1E02
#define GL_INDEX_ARRAY 0x8077
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_BITS 0x0D51
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_INDEX_MODE 0x0C30
#define GL_INDEX_OFFSET 0x0D13
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_INT 0x1404
#define GL_INTENSITY 0x8049
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_OPERATION 0x0502
#define GL_INVALID_VALUE 0x0501
/*Copied GL_INVERT From: NV_blend_equation_advanced*/
#define GL_KEEP 0x1E00
#define GL_LEFT 0x0406
#define GL_LEQUAL 0x0203
#define GL_LESS 0x0201
#define GL_LIGHT0 0x4000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
#define GL_LIGHTING 0x0B50
#define GL_LIGHTING_BIT 0x00000040
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LINE 0x1B01
#define GL_LINEAR 0x2601
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_LINES 0x0001
#define GL_LINE_BIT 0x00000004
#define GL_LINE_LOOP 0x0002
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LINE_STRIP 0x0003
#define GL_LINE_TOKEN 0x0702
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LIST_BASE 0x0B32
#define GL_LIST_BIT 0x00020000
#define GL_LIST_INDEX 0x0B33
#define GL_LIST_MODE 0x0B30
#define GL_LOAD 0x0101
#define GL_LOGIC_OP 0x0BF1
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_MATRIX_MODE 0x0BA0
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_MODELVIEW 0x1700
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_MODULATE 0x2100
#define GL_MULT 0x0103
#define GL_N3F_V3F 0x2A25
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_NAND 0x150E
#define GL_NEAREST 0x2600
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_NEVER 0x0200
#define GL_NICEST 0x1102
/*Copied GL_NONE From: NV_register_combiners*/
#define GL_NOOP 0x1505
#define GL_NOR 0x1508
#define GL_NORMALIZE 0x0BA1
#define GL_NORMAL_ARRAY 0x8075
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NOTEQUAL 0x0205
/*Copied GL_NO_ERROR From: ARB_robustness*/
#define GL_OBJECT_LINEAR 0x2401
#define GL_OBJECT_PLANE 0x2501
#define GL_ONE 1
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_OR 0x1507
#define GL_ORDER 0x0A01
#define GL_OR_INVERTED 0x150D
#define GL_OR_REVERSE 0x150B
#define GL_OUT_OF_MEMORY 0x0505
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_POINT 0x1B00
#define GL_POINTS 0x0000
#define GL_POINT_BIT 0x00000002
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SMOOTH 0x0B10
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_POINT_TOKEN 0x0701
#define GL_POLYGON 0x0009
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_POLYGON_TOKEN 0x0703
#define GL_POSITION 0x1203
#define GL_PROJECTION 0x1701
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_Q 0x2003
#define GL_QUADRATIC_ATTENUATION 0x1209
/*Copied GL_QUADS From: ARB_tessellation_shader*/
#define GL_QUAD_STRIP 0x0008
#define GL_R 0x2002
#define GL_R3_G3_B2 0x2A10
#define GL_READ_BUFFER 0x0C02
/*Copied GL_RED From: NV_blend_equation_advanced*/
#define GL_RED_BIAS 0x0D15
#define GL_RED_BITS 0x0D52
#define GL_RED_SCALE 0x0D14
#define GL_RENDER 0x1C00
#define GL_RENDERER 0x1F01
#define GL_RENDER_MODE 0x0C40
#define GL_REPEAT 0x2901
#define GL_REPLACE 0x1E01
#define GL_RETURN 0x0102
#define GL_RGB 0x1907
#define GL_RGB10 0x8052
#define GL_RGB10_A2 0x8059
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB5_A1 0x8057
#define GL_RGB8 0x8051
#define GL_RGBA 0x1908
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGBA8 0x8058
#define GL_RGBA_MODE 0x0C31
#define GL_RIGHT 0x0407
#define GL_S 0x2000
#define GL_SCISSOR_BIT 0x00080000
/*Copied GL_SCISSOR_BOX From: ARB_viewport_array*/
/*Copied GL_SCISSOR_TEST From: ARB_viewport_array*/
#define GL_SELECT 0x1C02
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_SET 0x150F
#define GL_SHADE_MODEL 0x0B54
#define GL_SHININESS 0x1601
#define GL_SHORT 0x1402
#define GL_SMOOTH 0x1D01
#define GL_SPECULAR 0x1202
#define GL_SPHERE_MAP 0x2402
#define GL_SPOT_CUTOFF 0x1206
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SRC_ALPHA 0x0302
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_SRC_COLOR 0x0300
/*Copied GL_STACK_OVERFLOW From: KHR_debug*/
/*Copied GL_STACK_UNDERFLOW From: KHR_debug*/
#define GL_STENCIL 0x1802
#define GL_STENCIL_BITS 0x0D57
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_FUNC 0x0B92
/*Copied GL_STENCIL_INDEX From: ARB_texture_stencil8*/
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_STEREO 0x0C33
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_T 0x2001
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_V3F 0x2A27
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_T4F_V4F 0x2A28
#define GL_TEXTURE 0x1702
/*Copied GL_TEXTURE_1D From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_2D From: ARB_internalformat_query2*/
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_BIT 0x00040000
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_BORDER 0x1005
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_ENV 0x2300
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_TRANSFORM_BIT 0x00001000
/*Copied GL_TRIANGLES From: ARB_tessellation_shader*/
#define GL_TRIANGLE_FAN 0x0006
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRUE 1
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT 0x1405
#define GL_UNSIGNED_SHORT 0x1403
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_VENDOR 0x1F00
#define GL_VERSION 0x1F02
/*Copied GL_VERTEX_ARRAY From: KHR_debug*/
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_VERTEX_ARRAY_TYPE 0x807B
/*Copied GL_VIEWPORT From: ARB_viewport_array*/
#define GL_VIEWPORT_BIT 0x00000800
/*Copied GL_XOR From: NV_blend_equation_advanced*/
/*Copied GL_ZERO From: NV_register_combiners*/
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17

#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_BGR 0x80E0
/*Copied GL_BGRA From: EXT_vertex_array_bgra*/
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_RESCALE_NORMAL 0x803A
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_SINGLE_COLOR 0x81F9
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
/*Copied GL_TEXTURE_3D From: ARB_internalformat_query2*/
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
/*Copied GL_UNSIGNED_INT_2_10_10_10_REV From: ARB_vertex_type_2_10_10_10_rev*/
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364

#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_ADD_SIGNED 0x8574
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_COMBINE 0x8570
#define GL_COMBINE_ALPHA 0x8572
#define GL_COMBINE_RGB 0x8571
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CONSTANT 0x8576
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
#define GL_INTERPOLATE 0x8575
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_MULTISAMPLE 0x809D
#define GL_MULTISAMPLE_BIT 0x20000000
#define GL_NORMAL_MAP 0x8511
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_ALPHA 0x859A
#define GL_OPERAND2_RGB 0x8592
#define GL_PREVIOUS 0x8578
/*Copied GL_PRIMARY_COLOR From: NV_path_rendering*/
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_REFLECTION_MAP 0x8512
#define GL_RGB_SCALE 0x8573
/*Copied GL_SAMPLES From: ARB_internalformat_query2*/
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_ALPHA 0x858A
#define GL_SOURCE2_RGB 0x8582
#define GL_SUBTRACT 0x84E7
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
/*Copied GL_TEXTURE_COMPRESSED From: ARB_internalformat_query2*/
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
/*Copied GL_TEXTURE_CUBE_MAP From: ARB_internalformat_query2*/
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5

/*Copied GL_BLEND_COLOR From: ARB_imaging*/
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_DST_RGB 0x80C8
/*Copied GL_BLEND_EQUATION From: ARB_imaging*/
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_COLOR_SUM 0x8458
#define GL_COMPARE_R_TO_TEXTURE 0x884E
/*Copied GL_CONSTANT_ALPHA From: ARB_imaging*/
/*Copied GL_CONSTANT_COLOR From: ARB_imaging*/
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_DECR_WRAP 0x8508
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_FOG_COORDINATE 0x8451
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FRAGMENT_DEPTH 0x8452
/*Copied GL_FUNC_ADD From: ARB_imaging*/
/*Copied GL_FUNC_REVERSE_SUBTRACT From: ARB_imaging*/
/*Copied GL_FUNC_SUBTRACT From: ARB_imaging*/
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_INCR_WRAP 0x8507
/*Copied GL_MAX From: ARB_imaging*/
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
/*Copied GL_MIN From: ARB_imaging*/
#define GL_MIRRORED_REPEAT 0x8370
/*Copied GL_ONE_MINUS_CONSTANT_ALPHA From: ARB_imaging*/
/*Copied GL_ONE_MINUS_CONSTANT_COLOR From: ARB_imaging*/
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_SIZE_MIN 0x8126
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_TEXTURE_LOD_BIAS 0x8501

#define GL_ARRAY_BUFFER 0x8892
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_CURRENT_FOG_COORD 0x8453
#define GL_CURRENT_QUERY 0x8865
#define GL_DYNAMIC_COPY 0x88EA
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_FOG_COORD 0x8451
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_FOG_COORD_ARRAY 0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define GL_FOG_COORD_ARRAY_POINTER 0x8456
#define GL_FOG_COORD_ARRAY_STRIDE 0x8455
#define GL_FOG_COORD_ARRAY_TYPE 0x8454
#define GL_FOG_COORD_SRC 0x8450
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_READ_ONLY 0x88B8
/*Copied GL_READ_WRITE From: NV_shader_buffer_store*/
#define GL_SAMPLES_PASSED 0x8914
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_SRC0_ALPHA 0x8588
#define GL_SRC0_RGB 0x8580
/*Copied GL_SRC1_ALPHA From: ARB_blend_func_extended*/
#define GL_SRC1_RGB 0x8581
#define GL_SRC2_ALPHA 0x858A
#define GL_SRC2_RGB 0x8582
#define GL_STATIC_COPY 0x88E6
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STREAM_COPY 0x88E2
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
/*Copied GL_WRITE_ONLY From: NV_shader_buffer_store*/

#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_COMPILE_STATUS 0x8B81
#define GL_COORD_REPLACE 0x8862
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_DELETE_STATUS 0x8B80
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_LINK_STATUS 0x8B82
#define GL_LOWER_LEFT 0x8CA1
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_POINT_SPRITE 0x8861
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_SHADER_TYPE 0x8B4F
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_UPPER_LEFT 0x8CA2
#define GL_VALIDATE_STATUS 0x8B83
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_VERTEX_SHADER 0x8B31

#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_SRGB_ALPHA 0x8C42

#define GL_ALPHA_INTEGER 0x8D97
#define GL_BGRA_INTEGER 0x8D9B
#define GL_BGR_INTEGER 0x8D9A
#define GL_BLUE_INTEGER 0x8D96
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
/*Copied GL_COLOR_ATTACHMENT0 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT1 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT10 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT11 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT12 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT13 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT14 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT15 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT2 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT3 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT4 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT5 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT6 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT7 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT8 From: ARB_framebuffer_object*/
/*Copied GL_COLOR_ATTACHMENT9 From: ARB_framebuffer_object*/
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_COMPRESSED_RED 0x8225
/*Copied GL_COMPRESSED_RED_RGTC1 From: ARB_texture_compression_rgtc*/
#define GL_COMPRESSED_RG 0x8226
/*Copied GL_COMPRESSED_RG_RGTC2 From: ARB_texture_compression_rgtc*/
/*Copied GL_COMPRESSED_SIGNED_RED_RGTC1 From: ARB_texture_compression_rgtc*/
/*Copied GL_COMPRESSED_SIGNED_RG_RGTC2 From: ARB_texture_compression_rgtc*/
#define GL_CONTEXT_FLAGS 0x821E
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
/*Copied GL_DEPTH24_STENCIL8 From: ARB_framebuffer_object*/
/*Copied GL_DEPTH32F_STENCIL8 From: ARB_depth_buffer_float*/
/*Copied GL_DEPTH_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_DEPTH_COMPONENT32F From: ARB_depth_buffer_float*/
/*Copied GL_DEPTH_STENCIL From: ARB_framebuffer_object*/
/*Copied GL_DEPTH_STENCIL_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_DRAW_FRAMEBUFFER From: ARB_framebuffer_object*/
/*Copied GL_DRAW_FRAMEBUFFER_BINDING From: ARB_framebuffer_object*/
#define GL_FIXED_ONLY 0x891D
/*Copied GL_FLOAT_32_UNSIGNED_INT_24_8_REV From: ARB_depth_buffer_float*/
/*Copied GL_FRAMEBUFFER From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER From: ARB_geometry_shader4*/
/*Copied GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_BINDING From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_COMPLETE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_DEFAULT From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_SRGB From: ARB_framebuffer_sRGB*/
/*Copied GL_FRAMEBUFFER_UNDEFINED From: ARB_framebuffer_object*/
/*Copied GL_FRAMEBUFFER_UNSUPPORTED From: ARB_framebuffer_object*/
#define GL_GREEN_INTEGER 0x8D95
/*Copied GL_HALF_FLOAT From: ARB_half_float_vertex*/
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
/*Copied GL_INVALID_FRAMEBUFFER_OPERATION From: ARB_framebuffer_object*/
#define GL_MAJOR_VERSION 0x821B
/*Copied GL_MAP_FLUSH_EXPLICIT_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_INVALIDATE_BUFFER_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_INVALIDATE_RANGE_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_READ_BIT From: ARB_buffer_storage*/
/*Copied GL_MAP_UNSYNCHRONIZED_BIT From: ARB_map_buffer_range*/
/*Copied GL_MAP_WRITE_BIT From: ARB_buffer_storage*/
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MAX_CLIP_DISTANCES 0x0D32
/*Copied GL_MAX_COLOR_ATTACHMENTS From: ARB_framebuffer_object*/
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
/*Copied GL_MAX_RENDERBUFFER_SIZE From: ARB_framebuffer_object*/
/*Copied GL_MAX_SAMPLES From: ARB_framebuffer_object*/
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
/*Copied GL_MAX_VARYING_COMPONENTS From: ARB_geometry_shader4*/
#define GL_MINOR_VERSION 0x821C
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_NUM_EXTENSIONS 0x821D
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_WAIT 0x8E13
#define GL_R11F_G11F_B10F 0x8C3A
/*Copied GL_R16 From: ARB_texture_rg*/
/*Copied GL_R16F From: ARB_texture_rg*/
/*Copied GL_R16I From: ARB_texture_rg*/
/*Copied GL_R16UI From: ARB_texture_rg*/
/*Copied GL_R32F From: ARB_texture_rg*/
/*Copied GL_R32I From: ARB_texture_rg*/
/*Copied GL_R32UI From: ARB_texture_rg*/
/*Copied GL_R8 From: ARB_texture_rg*/
/*Copied GL_R8I From: ARB_texture_rg*/
/*Copied GL_R8UI From: ARB_texture_rg*/
#define GL_RASTERIZER_DISCARD 0x8C89
/*Copied GL_READ_FRAMEBUFFER From: ARB_framebuffer_object*/
/*Copied GL_READ_FRAMEBUFFER_BINDING From: ARB_framebuffer_object*/
#define GL_RED_INTEGER 0x8D94
/*Copied GL_RENDERBUFFER From: ARB_internalformat_query2*/
/*Copied GL_RENDERBUFFER_ALPHA_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_BINDING From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_BLUE_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_DEPTH_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_GREEN_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_HEIGHT From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_INTERNAL_FORMAT From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_RED_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_SAMPLES From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_STENCIL_SIZE From: ARB_framebuffer_object*/
/*Copied GL_RENDERBUFFER_WIDTH From: ARB_framebuffer_object*/
/*Copied GL_RG From: ARB_texture_rg*/
/*Copied GL_RG16 From: ARB_texture_rg*/
/*Copied GL_RG16F From: ARB_texture_rg*/
/*Copied GL_RG16I From: ARB_texture_rg*/
/*Copied GL_RG16UI From: AMD_interleaved_elements*/
/*Copied GL_RG32F From: ARB_texture_rg*/
/*Copied GL_RG32I From: ARB_texture_rg*/
/*Copied GL_RG32UI From: ARB_texture_rg*/
/*Copied GL_RG8 From: ARB_texture_rg*/
/*Copied GL_RG8I From: ARB_texture_rg*/
/*Copied GL_RG8UI From: AMD_interleaved_elements*/
#define GL_RGB16F 0x881B
#define GL_RGB16I 0x8D89
#define GL_RGB16UI 0x8D77
/*Copied GL_RGB32F From: ARB_texture_buffer_object_rgb32*/
/*Copied GL_RGB32I From: ARB_texture_buffer_object_rgb32*/
/*Copied GL_RGB32UI From: ARB_texture_buffer_object_rgb32*/
#define GL_RGB8I 0x8D8F
#define GL_RGB8UI 0x8D7D
#define GL_RGB9_E5 0x8C3D
#define GL_RGBA16F 0x881A
#define GL_RGBA16I 0x8D88
#define GL_RGBA16UI 0x8D76
#define GL_RGBA32F 0x8814
#define GL_RGBA32I 0x8D82
#define GL_RGBA32UI 0x8D70
#define GL_RGBA8I 0x8D8E
/*Copied GL_RGBA8UI From: AMD_interleaved_elements*/
#define GL_RGBA_INTEGER 0x8D99
#define GL_RGB_INTEGER 0x8D98
/*Copied GL_RG_INTEGER From: ARB_texture_rg*/
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_SEPARATE_ATTRIBS 0x8C8D
/*Copied GL_STENCIL_ATTACHMENT From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX1 From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX16 From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX4 From: ARB_framebuffer_object*/
/*Copied GL_STENCIL_INDEX8 From: ARB_texture_stencil8*/
/*Copied GL_TEXTURE_1D_ARRAY From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_2D_ARRAY From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_ALPHA_TYPE From: ARB_framebuffer_object*/
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
/*Copied GL_TEXTURE_BLUE_TYPE From: ARB_framebuffer_object*/
/*Copied GL_TEXTURE_DEPTH_TYPE From: ARB_framebuffer_object*/
/*Copied GL_TEXTURE_GREEN_TYPE From: ARB_framebuffer_object*/
/*Copied GL_TEXTURE_RED_TYPE From: ARB_framebuffer_object*/
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
/*Copied GL_TEXTURE_STENCIL_SIZE From: ARB_framebuffer_object*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER From: ARB_enhanced_layouts*/
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
/*Copied GL_UNSIGNED_INT_10F_11F_11F_REV From: ARB_vertex_type_10f_11f_11f_rev*/
/*Copied GL_UNSIGNED_INT_24_8 From: ARB_framebuffer_object*/
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
/*Copied GL_UNSIGNED_NORMALIZED From: ARB_framebuffer_object*/
/*Copied GL_VERTEX_ARRAY_BINDING From: ARB_vertex_array_object*/
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD

/*Copied GL_ACTIVE_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
/*Copied GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH From: ARB_uniform_buffer_object*/
/*Copied GL_COPY_READ_BUFFER From: ARB_copy_buffer*/
/*Copied GL_COPY_WRITE_BUFFER From: ARB_copy_buffer*/
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
/*Copied GL_INVALID_INDEX From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_COMBINED_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_FRAGMENT_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
/*Copied GL_MAX_UNIFORM_BLOCK_SIZE From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_UNIFORM_BUFFER_BINDINGS From: ARB_uniform_buffer_object*/
/*Copied GL_MAX_VERTEX_UNIFORM_BLOCKS From: ARB_uniform_buffer_object*/
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
/*Copied GL_R16_SNORM From: EXT_texture_snorm*/
/*Copied GL_R8_SNORM From: EXT_texture_snorm*/
/*Copied GL_RG16_SNORM From: EXT_texture_snorm*/
/*Copied GL_RG8_SNORM From: EXT_texture_snorm*/
/*Copied GL_RGB16_SNORM From: EXT_texture_snorm*/
/*Copied GL_RGB8_SNORM From: EXT_texture_snorm*/
/*Copied GL_RGBA16_SNORM From: EXT_texture_snorm*/
/*Copied GL_RGBA8_SNORM From: EXT_texture_snorm*/
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
/*Copied GL_SIGNED_NORMALIZED From: EXT_texture_snorm*/
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
/*Copied GL_TEXTURE_BUFFER From: ARB_internalformat_query2*/
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
/*Copied GL_TEXTURE_RECTANGLE From: ARB_internalformat_query2*/
/*Copied GL_UNIFORM_ARRAY_STRIDE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_BINDING From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_DATA_SIZE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_INDEX From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_NAME_LENGTH From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_BINDING From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_SIZE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_BUFFER_START From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_IS_ROW_MAJOR From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_MATRIX_STRIDE From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_NAME_LENGTH From: ARB_shader_subroutine*/
/*Copied GL_UNIFORM_OFFSET From: ARB_uniform_buffer_object*/
/*Copied GL_UNIFORM_SIZE From: ARB_shader_subroutine*/
/*Copied GL_UNIFORM_TYPE From: ARB_uniform_buffer_object*/
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8

/*Copied GL_ALREADY_SIGNALED From: ARB_sync*/
/*Copied GL_CONDITION_SATISFIED From: ARB_sync*/
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_PROFILE_MASK 0x9126
/*Copied GL_DEPTH_CLAMP From: ARB_depth_clamp*/
/*Copied GL_FIRST_VERTEX_CONVENTION From: ARB_viewport_array*/
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT 0x8916
/*Copied GL_INT_SAMPLER_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_LAST_VERTEX_CONVENTION From: ARB_viewport_array*/
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
/*Copied GL_MAX_COLOR_TEXTURE_SAMPLES From: ARB_texture_multisample*/
/*Copied GL_MAX_DEPTH_TEXTURE_SAMPLES From: ARB_texture_multisample*/
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
/*Copied GL_MAX_INTEGER_SAMPLES From: ARB_texture_multisample*/
/*Copied GL_MAX_SAMPLE_MASK_WORDS From: ARB_texture_multisample*/
/*Copied GL_MAX_SERVER_WAIT_TIMEOUT From: ARB_sync*/
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
/*Copied GL_OBJECT_TYPE From: ARB_sync*/
#define GL_PROGRAM_POINT_SIZE 0x8642
/*Copied GL_PROVOKING_VERTEX From: ARB_viewport_array*/
/*Copied GL_PROXY_TEXTURE_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION From: ARB_provoking_vertex*/
/*Copied GL_SAMPLER_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_SAMPLER_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_SAMPLE_MASK From: ARB_texture_multisample*/
/*Copied GL_SAMPLE_MASK_VALUE From: ARB_texture_multisample*/
/*Copied GL_SAMPLE_POSITION From: ARB_texture_multisample*/
/*Copied GL_SIGNALED From: ARB_sync*/
/*Copied GL_SYNC_CONDITION From: ARB_sync*/
/*Copied GL_SYNC_FENCE From: ARB_sync*/
/*Copied GL_SYNC_FLAGS From: ARB_sync*/
/*Copied GL_SYNC_FLUSH_COMMANDS_BIT From: ARB_sync*/
/*Copied GL_SYNC_GPU_COMMANDS_COMPLETE From: ARB_sync*/
/*Copied GL_SYNC_STATUS From: ARB_sync*/
/*Copied GL_TEXTURE_2D_MULTISAMPLE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_2D_MULTISAMPLE_ARRAY From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_BINDING_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_CUBE_MAP_SEAMLESS From: ARB_seamless_cubemap_per_texture*/
/*Copied GL_TEXTURE_FIXED_SAMPLE_LOCATIONS From: ARB_texture_multisample*/
/*Copied GL_TEXTURE_SAMPLES From: ARB_texture_multisample*/
/*Copied GL_TIMEOUT_EXPIRED From: ARB_sync*/
/*Copied GL_TIMEOUT_IGNORED From: ARB_sync*/
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
/*Copied GL_UNSIGNALED From: ARB_sync*/
/*Copied GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE From: ARB_texture_multisample*/
/*Copied GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY From: ARB_texture_multisample*/
/*Copied GL_WAIT_FAILED From: ARB_sync*/

/*Copied GL_ANY_SAMPLES_PASSED From: ARB_occlusion_query2*/
/*Copied GL_INT_2_10_10_10_REV From: ARB_vertex_type_2_10_10_10_rev*/
/*Copied GL_MAX_DUAL_SOURCE_DRAW_BUFFERS From: ARB_blend_func_extended*/
/*Copied GL_ONE_MINUS_SRC1_ALPHA From: ARB_blend_func_extended*/
/*Copied GL_ONE_MINUS_SRC1_COLOR From: ARB_blend_func_extended*/
/*Copied GL_RGB10_A2UI From: ARB_texture_rgb10_a2ui*/
/*Copied GL_SAMPLER_BINDING From: ARB_sampler_objects*/
/*Copied GL_SRC1_COLOR From: ARB_blend_func_extended*/
/*Copied GL_TEXTURE_SWIZZLE_A From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_B From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_G From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_R From: ARB_texture_swizzle*/
/*Copied GL_TEXTURE_SWIZZLE_RGBA From: ARB_texture_swizzle*/
/*Copied GL_TIMESTAMP From: ARB_timer_query*/
/*Copied GL_TIME_ELAPSED From: ARB_timer_query*/
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE

/*Copied GL_ACTIVE_SUBROUTINES From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_MAX_LENGTH From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_UNIFORMS From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS From: ARB_shader_subroutine*/
/*Copied GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH From: ARB_shader_subroutine*/
/*Copied GL_COMPATIBLE_SUBROUTINES From: ARB_program_interface_query*/
/*Copied GL_DOUBLE_MAT2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT2x3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT2x4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT3x2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT3x4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT4x2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_MAT4x3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_VEC2 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_VEC3 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DOUBLE_VEC4 From: ARB_vertex_attrib_64bit*/
/*Copied GL_DRAW_INDIRECT_BUFFER From: ARB_draw_indirect*/
/*Copied GL_DRAW_INDIRECT_BUFFER_BINDING From: ARB_draw_indirect*/
/*Copied GL_FRACTIONAL_EVEN From: ARB_tessellation_shader*/
/*Copied GL_FRACTIONAL_ODD From: ARB_tessellation_shader*/
/*Copied GL_FRAGMENT_INTERPOLATION_OFFSET_BITS From: ARB_gpu_shader5*/
/*Copied GL_GEOMETRY_SHADER_INVOCATIONS From: ARB_gpu_shader5*/
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
/*Copied GL_ISOLINES From: ARB_tessellation_shader*/
/*Copied GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_FRAGMENT_INTERPOLATION_OFFSET From: ARB_gpu_shader5*/
/*Copied GL_MAX_GEOMETRY_SHADER_INVOCATIONS From: ARB_gpu_shader5*/
/*Copied GL_MAX_PATCH_VERTICES From: ARB_tessellation_shader*/
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
/*Copied GL_MAX_SUBROUTINES From: ARB_shader_subroutine*/
/*Copied GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS From: ARB_shader_subroutine*/
/*Copied GL_MAX_TESS_CONTROL_INPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_GEN_LEVEL From: ARB_tessellation_shader*/
/*Copied GL_MAX_TESS_PATCH_COMPONENTS From: ARB_tessellation_shader*/
/*Copied GL_MAX_TRANSFORM_FEEDBACK_BUFFERS From: ARB_transform_feedback3*/
/*Copied GL_MAX_VERTEX_STREAMS From: ARB_transform_feedback3*/
/*Copied GL_MIN_FRAGMENT_INTERPOLATION_OFFSET From: ARB_gpu_shader5*/
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
/*Copied GL_NUM_COMPATIBLE_SUBROUTINES From: ARB_program_interface_query*/
/*Copied GL_PATCHES From: NV_gpu_shader5*/
/*Copied GL_PATCH_DEFAULT_INNER_LEVEL From: ARB_tessellation_shader*/
/*Copied GL_PATCH_DEFAULT_OUTER_LEVEL From: ARB_tessellation_shader*/
/*Copied GL_PATCH_VERTICES From: ARB_tessellation_shader*/
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_SAMPLE_SHADING 0x8C36
/*Copied GL_TESS_CONTROL_OUTPUT_VERTICES From: ARB_tessellation_shader*/
/*Copied GL_TESS_CONTROL_SHADER From: ARB_tessellation_shader*/
/*Copied GL_TESS_EVALUATION_SHADER From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_MODE From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_POINT_MODE From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_SPACING From: ARB_tessellation_shader*/
/*Copied GL_TESS_GEN_VERTEX_ORDER From: ARB_tessellation_shader*/
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
/*Copied GL_TEXTURE_CUBE_MAP_ARRAY From: ARB_internalformat_query2*/
/*Copied GL_TRANSFORM_FEEDBACK From: ARB_transform_feedback2*/
/*Copied GL_TRANSFORM_FEEDBACK_BINDING From: ARB_transform_feedback2*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE From: ARB_transform_feedback2*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED From: ARB_transform_feedback2*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER From: ARB_tessellation_shader*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER From: ARB_tessellation_shader*/
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

/*Copied GL_ACTIVE_PROGRAM From: ARB_separate_shader_objects*/
/*Copied GL_ALL_SHADER_BITS From: ARB_separate_shader_objects*/
/*Copied GL_FIXED From: ARB_ES2_compatibility*/
/*Copied GL_FRAGMENT_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_GEOMETRY_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_HIGH_FLOAT From: ARB_ES2_compatibility*/
/*Copied GL_HIGH_INT From: ARB_ES2_compatibility*/
/*Copied GL_IMPLEMENTATION_COLOR_READ_FORMAT From: ARB_ES2_compatibility*/
/*Copied GL_IMPLEMENTATION_COLOR_READ_TYPE From: ARB_ES2_compatibility*/
/*Copied GL_LAYER_PROVOKING_VERTEX From: ARB_viewport_array*/
/*Copied GL_LOW_FLOAT From: ARB_ES2_compatibility*/
/*Copied GL_LOW_INT From: ARB_ES2_compatibility*/
/*Copied GL_MAX_FRAGMENT_UNIFORM_VECTORS From: ARB_ES2_compatibility*/
/*Copied GL_MAX_VARYING_VECTORS From: ARB_ES2_compatibility*/
/*Copied GL_MAX_VERTEX_UNIFORM_VECTORS From: ARB_ES2_compatibility*/
/*Copied GL_MAX_VIEWPORTS From: ARB_viewport_array*/
/*Copied GL_MEDIUM_FLOAT From: ARB_ES2_compatibility*/
/*Copied GL_MEDIUM_INT From: ARB_ES2_compatibility*/
/*Copied GL_NUM_PROGRAM_BINARY_FORMATS From: ARB_get_program_binary*/
/*Copied GL_NUM_SHADER_BINARY_FORMATS From: ARB_ES2_compatibility*/
/*Copied GL_PROGRAM_BINARY_FORMATS From: ARB_get_program_binary*/
/*Copied GL_PROGRAM_BINARY_LENGTH From: ARB_get_program_binary*/
/*Copied GL_PROGRAM_BINARY_RETRIEVABLE_HINT From: ARB_get_program_binary*/
/*Copied GL_PROGRAM_PIPELINE_BINDING From: ARB_separate_shader_objects*/
/*Copied GL_PROGRAM_SEPARABLE From: ARB_separate_shader_objects*/
/*Copied GL_RGB565 From: ARB_ES2_compatibility*/
/*Copied GL_SHADER_BINARY_FORMATS From: ARB_ES2_compatibility*/
/*Copied GL_SHADER_COMPILER From: ARB_ES2_compatibility*/
/*Copied GL_TESS_CONTROL_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_TESS_EVALUATION_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_UNDEFINED_VERTEX From: ARB_viewport_array*/
/*Copied GL_VERTEX_SHADER_BIT From: ARB_separate_shader_objects*/
/*Copied GL_VIEWPORT_BOUNDS_RANGE From: ARB_viewport_array*/
/*Copied GL_VIEWPORT_INDEX_PROVOKING_VERTEX From: ARB_viewport_array*/
/*Copied GL_VIEWPORT_SUBPIXEL_BITS From: ARB_viewport_array*/

/*Copied GL_ACTIVE_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_ALL_BARRIER_BITS From: ARB_shader_image_load_store*/
/*Copied GL_ATOMIC_COUNTER_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_ATOMIC_COUNTER_BUFFER From: ARB_program_interface_query*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_BINDING From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_SIZE From: ARB_shader_atomic_counters*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_START From: ARB_shader_atomic_counters*/
/*Copied GL_BUFFER_UPDATE_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_COMMAND_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_ELEMENT_ARRAY_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_FRAMEBUFFER_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_1D From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_1D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_MULTISAMPLE From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_MULTISAMPLE_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_2D_RECT From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_3D From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_ACCESS From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_FORMAT From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_LAYER From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_LAYERED From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_LEVEL From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BINDING_NAME From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_BUFFER From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_CUBE From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_CUBE_MAP_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE From: ARB_shader_image_load_store*/
/*Copied GL_IMAGE_FORMAT_COMPATIBILITY_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INT_IMAGE_1D From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_1D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_MULTISAMPLE From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_2D_RECT From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_3D From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_BUFFER From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_CUBE From: ARB_shader_image_load_store*/
/*Copied GL_INT_IMAGE_CUBE_MAP_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_COMBINED_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_COMBINED_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_FRAGMENT_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_FRAGMENT_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_GEOMETRY_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_GEOMETRY_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_IMAGE_SAMPLES From: ARB_shader_image_load_store*/
/*Copied GL_MAX_IMAGE_UNITS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MAX_VERTEX_ATOMIC_COUNTERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS From: ARB_shader_atomic_counters*/
/*Copied GL_MAX_VERTEX_IMAGE_UNIFORMS From: ARB_shader_image_load_store*/
/*Copied GL_MIN_MAP_BUFFER_ALIGNMENT From: ARB_map_buffer_alignment*/
/*Copied GL_NUM_SAMPLE_COUNTS From: ARB_internalformat_query2*/
/*Copied GL_PACK_COMPRESSED_BLOCK_DEPTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PACK_COMPRESSED_BLOCK_HEIGHT From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PACK_COMPRESSED_BLOCK_SIZE From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PACK_COMPRESSED_BLOCK_WIDTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_PIXEL_BUFFER_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_SHADER_IMAGE_ACCESS_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_TEXTURE_FETCH_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_TEXTURE_IMMUTABLE_FORMAT From: ARB_texture_storage*/
/*Copied GL_TEXTURE_UPDATE_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_TRANSFORM_FEEDBACK_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX From: ARB_shader_atomic_counters*/
/*Copied GL_UNIFORM_BARRIER_BIT From: ARB_shader_image_load_store*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_DEPTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_HEIGHT From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_SIZE From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNPACK_COMPRESSED_BLOCK_WIDTH From: ARB_compressed_texture_pixel_storage*/
/*Copied GL_UNSIGNED_INT_ATOMIC_COUNTER From: ARB_shader_atomic_counters*/
/*Copied GL_UNSIGNED_INT_IMAGE_1D From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_1D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_2D_RECT From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_3D From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_BUFFER From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_CUBE From: ARB_shader_image_load_store*/
/*Copied GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY From: ARB_shader_image_load_store*/
/*Copied GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT From: ARB_shader_image_load_store*/

/*Copied GL_ACTIVE_RESOURCES From: ARB_program_interface_query*/
/*Copied GL_ACTIVE_VARIABLES From: ARB_program_interface_query*/
/*Copied GL_ANY_SAMPLES_PASSED_CONSERVATIVE From: ARB_ES3_compatibility*/
/*Copied GL_ARRAY_SIZE From: ARB_program_interface_query*/
/*Copied GL_ARRAY_STRIDE From: ARB_program_interface_query*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_INDEX From: ARB_program_interface_query*/
/*Copied GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER From: ARB_compute_shader*/
/*Copied GL_AUTO_GENERATE_MIPMAP From: ARB_internalformat_query2*/
/*Copied GL_BLOCK_INDEX From: ARB_program_interface_query*/
/*Copied GL_BUFFER From: KHR_debug*/
/*Copied GL_BUFFER_BINDING From: ARB_program_interface_query*/
/*Copied GL_BUFFER_DATA_SIZE From: ARB_program_interface_query*/
/*Copied GL_BUFFER_VARIABLE From: ARB_program_interface_query*/
/*Copied GL_CAVEAT_SUPPORT From: ARB_internalformat_query2*/
/*Copied GL_CLEAR_BUFFER From: ARB_internalformat_query2*/
/*Copied GL_COLOR_COMPONENTS From: ARB_internalformat_query2*/
/*Copied GL_COLOR_ENCODING From: ARB_internalformat_query2*/
/*Copied GL_COLOR_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_COMPRESSED_R11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RG11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RGB8_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_RGBA8_ETC2_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SIGNED_R11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SIGNED_RG11_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SRGB8_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 From: ARB_ES3_compatibility*/
/*Copied GL_COMPUTE_LOCAL_WORK_SIZE From: ARB_compute_shader*/
/*Copied GL_COMPUTE_SHADER From: ARB_compute_shader*/
/*Copied GL_COMPUTE_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_COMPUTE_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_COMPUTE_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_CONTEXT_FLAG_DEBUG_BIT From: KHR_debug*/
/*Copied GL_DEBUG_CALLBACK_FUNCTION From: KHR_debug*/
/*Copied GL_DEBUG_CALLBACK_USER_PARAM From: KHR_debug*/
/*Copied GL_DEBUG_GROUP_STACK_DEPTH From: KHR_debug*/
/*Copied GL_DEBUG_LOGGED_MESSAGES From: KHR_debug*/
/*Copied GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH From: KHR_debug*/
/*Copied GL_DEBUG_OUTPUT From: KHR_debug*/
/*Copied GL_DEBUG_OUTPUT_SYNCHRONOUS From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_HIGH From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_LOW From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_MEDIUM From: KHR_debug*/
/*Copied GL_DEBUG_SEVERITY_NOTIFICATION From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_API From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_APPLICATION From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_OTHER From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_SHADER_COMPILER From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_THIRD_PARTY From: KHR_debug*/
/*Copied GL_DEBUG_SOURCE_WINDOW_SYSTEM From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_ERROR From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_MARKER From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_OTHER From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_PERFORMANCE From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_POP_GROUP From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_PORTABILITY From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_PUSH_GROUP From: KHR_debug*/
/*Copied GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR From: KHR_debug*/
/*Copied GL_DEPTH_COMPONENTS From: ARB_internalformat_query2*/
/*Copied GL_DEPTH_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_DEPTH_STENCIL_TEXTURE_MODE From: ARB_stencil_texturing*/
/*Copied GL_DISPATCH_INDIRECT_BUFFER From: ARB_compute_shader*/
/*Copied GL_DISPATCH_INDIRECT_BUFFER_BINDING From: ARB_compute_shader*/
/*Copied GL_FILTER From: ARB_internalformat_query2*/
/*Copied GL_FRAGMENT_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_FRAGMENT_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_FRAGMENT_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_FRAMEBUFFER_BLEND From: ARB_internalformat_query2*/
/*Copied GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_HEIGHT From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_LAYERS From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_SAMPLES From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_DEFAULT_WIDTH From: ARB_framebuffer_no_attachments*/
/*Copied GL_FRAMEBUFFER_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_FRAMEBUFFER_RENDERABLE_LAYERED From: ARB_internalformat_query2*/
/*Copied GL_FULL_SUPPORT From: ARB_internalformat_query2*/
/*Copied GL_GEOMETRY_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_GEOMETRY_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_GEOMETRY_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_GET_TEXTURE_IMAGE_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_GET_TEXTURE_IMAGE_TYPE From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_10_10_10_2 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_11_11_10 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_1_X_16 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_1_X_32 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_1_X_8 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_2_X_16 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_2_X_32 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_2_X_8 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_4_X_16 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_4_X_32 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_CLASS_4_X_8 From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_COMPATIBILITY_CLASS From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_PIXEL_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_PIXEL_TYPE From: ARB_internalformat_query2*/
/*Copied GL_IMAGE_TEXEL_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_ALPHA_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_ALPHA_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_BLUE_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_BLUE_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_DEPTH_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_DEPTH_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_GREEN_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_GREEN_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_PREFERRED From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_RED_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_RED_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_SHARED_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_STENCIL_SIZE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_STENCIL_TYPE From: ARB_internalformat_query2*/
/*Copied GL_INTERNALFORMAT_SUPPORTED From: ARB_internalformat_query2*/
/*Copied GL_IS_PER_PATCH From: ARB_program_interface_query*/
/*Copied GL_IS_ROW_MAJOR From: ARB_program_interface_query*/
/*Copied GL_LOCATION From: ARB_program_interface_query*/
/*Copied GL_LOCATION_INDEX From: ARB_program_interface_query*/
/*Copied GL_MANUAL_GENERATE_MIPMAP From: ARB_internalformat_query2*/
/*Copied GL_MATRIX_STRIDE From: ARB_program_interface_query*/
/*Copied GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS From: ARB_compute_shader*/
/*Copied GL_MAX_COMBINED_DIMENSIONS From: ARB_internalformat_query2*/
/*Copied GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_COMPUTE_ATOMIC_COUNTERS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_IMAGE_UNIFORMS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_LOCAL_INVOCATIONS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_COMPUTE_SHARED_MEMORY_SIZE From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_UNIFORM_BLOCKS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_UNIFORM_COMPONENTS From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_WORK_GROUP_COUNT From: ARB_compute_shader*/
/*Copied GL_MAX_COMPUTE_WORK_GROUP_SIZE From: ARB_compute_shader*/
/*Copied GL_MAX_DEBUG_GROUP_STACK_DEPTH From: KHR_debug*/
/*Copied GL_MAX_DEBUG_LOGGED_MESSAGES From: KHR_debug*/
/*Copied GL_MAX_DEBUG_MESSAGE_LENGTH From: KHR_debug*/
/*Copied GL_MAX_DEPTH From: ARB_internalformat_query2*/
/*Copied GL_MAX_ELEMENT_INDEX From: ARB_ES3_compatibility*/
/*Copied GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_FRAMEBUFFER_HEIGHT From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_FRAMEBUFFER_LAYERS From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_FRAMEBUFFER_SAMPLES From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_FRAMEBUFFER_WIDTH From: ARB_framebuffer_no_attachments*/
/*Copied GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_HEIGHT From: ARB_internalformat_query2*/
/*Copied GL_MAX_LABEL_LENGTH From: KHR_debug*/
/*Copied GL_MAX_LAYERS From: ARB_internalformat_query2*/
/*Copied GL_MAX_NAME_LENGTH From: ARB_program_interface_query*/
/*Copied GL_MAX_NUM_ACTIVE_VARIABLES From: ARB_program_interface_query*/
/*Copied GL_MAX_NUM_COMPATIBLE_SUBROUTINES From: ARB_program_interface_query*/
/*Copied GL_MAX_SHADER_STORAGE_BLOCK_SIZE From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_UNIFORM_LOCATIONS From: ARB_explicit_uniform_location*/
/*Copied GL_MAX_VERTEX_ATTRIB_BINDINGS From: ARB_vertex_attrib_binding*/
/*Copied GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET From: ARB_vertex_attrib_binding*/
/*Copied GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS From: ARB_shader_storage_buffer_object*/
/*Copied GL_MAX_WIDTH From: ARB_internalformat_query2*/
/*Copied GL_MIPMAP From: ARB_internalformat_query2*/
/*Copied GL_NAME_LENGTH From: ARB_program_interface_query*/
/*Copied GL_NUM_ACTIVE_VARIABLES From: ARB_program_interface_query*/
#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
/*Copied GL_OFFSET From: ARB_program_interface_query*/
/*Copied GL_PRIMITIVE_RESTART_FIXED_INDEX From: ARB_ES3_compatibility*/
/*Copied GL_PROGRAM From: KHR_debug*/
/*Copied GL_PROGRAM_INPUT From: ARB_program_interface_query*/
/*Copied GL_PROGRAM_OUTPUT From: ARB_program_interface_query*/
/*Copied GL_PROGRAM_PIPELINE From: KHR_debug*/
/*Copied GL_QUERY From: KHR_debug*/
/*Copied GL_READ_PIXELS From: ARB_internalformat_query2*/
/*Copied GL_READ_PIXELS_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_READ_PIXELS_TYPE From: ARB_internalformat_query2*/
/*Copied GL_REFERENCED_BY_COMPUTE_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_FRAGMENT_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_GEOMETRY_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_TESS_CONTROL_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_TESS_EVALUATION_SHADER From: ARB_program_interface_query*/
/*Copied GL_REFERENCED_BY_VERTEX_SHADER From: ARB_program_interface_query*/
/*Copied GL_SAMPLER From: KHR_debug*/
/*Copied GL_SHADER From: KHR_debug*/
/*Copied GL_SHADER_IMAGE_ATOMIC From: ARB_internalformat_query2*/
/*Copied GL_SHADER_IMAGE_LOAD From: ARB_internalformat_query2*/
/*Copied GL_SHADER_IMAGE_STORE From: ARB_internalformat_query2*/
/*Copied GL_SHADER_STORAGE_BARRIER_BIT From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BLOCK From: ARB_program_interface_query*/
/*Copied GL_SHADER_STORAGE_BUFFER From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_BINDING From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_SIZE From: ARB_shader_storage_buffer_object*/
/*Copied GL_SHADER_STORAGE_BUFFER_START From: ARB_shader_storage_buffer_object*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST From: ARB_internalformat_query2*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE From: ARB_internalformat_query2*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST From: ARB_internalformat_query2*/
/*Copied GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE From: ARB_internalformat_query2*/
/*Copied GL_SRGB_READ From: ARB_internalformat_query2*/
/*Copied GL_SRGB_WRITE From: ARB_internalformat_query2*/
/*Copied GL_STENCIL_COMPONENTS From: ARB_internalformat_query2*/
/*Copied GL_STENCIL_RENDERABLE From: ARB_internalformat_query2*/
/*Copied GL_TESS_CONTROL_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_TESS_CONTROL_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_TESS_CONTROL_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_TESS_EVALUATION_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_TESS_EVALUATION_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_TESS_EVALUATION_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_BUFFER_OFFSET From: ARB_texture_buffer_range*/
/*Copied GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT From: ARB_texture_buffer_range*/
/*Copied GL_TEXTURE_BUFFER_SIZE From: ARB_texture_buffer_range*/
/*Copied GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_COMPRESSED_BLOCK_SIZE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_COMPRESSED_BLOCK_WIDTH From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_GATHER From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_GATHER_SHADOW From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_IMAGE_FORMAT From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_IMAGE_TYPE From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_IMMUTABLE_LEVELS From: ARB_texture_view*/
/*Copied GL_TEXTURE_SHADOW From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_VIEW From: ARB_internalformat_query2*/
/*Copied GL_TEXTURE_VIEW_MIN_LAYER From: ARB_texture_view*/
/*Copied GL_TEXTURE_VIEW_MIN_LEVEL From: ARB_texture_view*/
/*Copied GL_TEXTURE_VIEW_NUM_LAYERS From: ARB_texture_view*/
/*Copied GL_TEXTURE_VIEW_NUM_LEVELS From: ARB_texture_view*/
/*Copied GL_TOP_LEVEL_ARRAY_SIZE From: ARB_program_interface_query*/
/*Copied GL_TOP_LEVEL_ARRAY_STRIDE From: ARB_program_interface_query*/
/*Copied GL_TRANSFORM_FEEDBACK_VARYING From: ARB_program_interface_query*/
/*Copied GL_TYPE From: ARB_program_interface_query*/
/*Copied GL_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_UNIFORM_BLOCK From: ARB_program_interface_query*/
/*Copied GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER From: ARB_compute_shader*/
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
/*Copied GL_VERTEX_ATTRIB_BINDING From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_ATTRIB_RELATIVE_OFFSET From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_BINDING_DIVISOR From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_BINDING_OFFSET From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_BINDING_STRIDE From: ARB_vertex_attrib_binding*/
/*Copied GL_VERTEX_SUBROUTINE From: ARB_program_interface_query*/
/*Copied GL_VERTEX_SUBROUTINE_UNIFORM From: ARB_program_interface_query*/
/*Copied GL_VERTEX_TEXTURE From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_128_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_16_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_24_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_32_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_48_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_64_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_8_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_96_BITS From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_BPTC_FLOAT From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_BPTC_UNORM From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_RGTC1_RED From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_RGTC2_RG From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT1_RGB From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT1_RGBA From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT3_RGBA From: ARB_internalformat_query2*/
/*Copied GL_VIEW_CLASS_S3TC_DXT5_RGBA From: ARB_internalformat_query2*/
/*Copied GL_VIEW_COMPATIBILITY_CLASS From: ARB_internalformat_query2*/

/*Copied GL_BUFFER_IMMUTABLE_STORAGE From: ARB_buffer_storage*/
/*Copied GL_BUFFER_STORAGE_FLAGS From: ARB_buffer_storage*/
/*Copied GL_CLEAR_TEXTURE From: ARB_clear_texture*/
/*Copied GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT From: ARB_buffer_storage*/
/*Copied GL_CLIENT_STORAGE_BIT From: ARB_buffer_storage*/
/*Copied GL_DYNAMIC_STORAGE_BIT From: ARB_buffer_storage*/
/*Copied GL_LOCATION_COMPONENT From: ARB_enhanced_layouts*/
/*Copied GL_MAP_COHERENT_BIT From: ARB_buffer_storage*/
/*Copied GL_MAP_PERSISTENT_BIT From: ARB_buffer_storage*/
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
/*Copied GL_MIRROR_CLAMP_TO_EDGE From: ARB_texture_mirror_clamp_to_edge*/
/*Copied GL_QUERY_BUFFER From: ARB_query_buffer_object*/
/*Copied GL_QUERY_BUFFER_BARRIER_BIT From: ARB_query_buffer_object*/
/*Copied GL_QUERY_BUFFER_BINDING From: ARB_query_buffer_object*/
/*Copied GL_QUERY_RESULT_NO_WAIT From: ARB_query_buffer_object*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_INDEX From: ARB_enhanced_layouts*/
/*Copied GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE From: ARB_enhanced_layouts*/

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorSubTable)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glColorSubTable _ptrc_glColorSubTable
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTable)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
#define glColorTable _ptrc_glColorTable
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterfv)(GLenum, GLenum, const GLfloat *);
#define glColorTableParameterfv _ptrc_glColorTableParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameteriv)(GLenum, GLenum, const GLint *);
#define glColorTableParameteriv _ptrc_glColorTableParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter1D)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
#define glConvolutionFilter1D _ptrc_glConvolutionFilter1D
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter2D)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glConvolutionFilter2D _ptrc_glConvolutionFilter2D
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterf)(GLenum, GLenum, GLfloat);
#define glConvolutionParameterf _ptrc_glConvolutionParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfv)(GLenum, GLenum, const GLfloat *);
#define glConvolutionParameterfv _ptrc_glConvolutionParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteri)(GLenum, GLenum, GLint);
#define glConvolutionParameteri _ptrc_glConvolutionParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteriv)(GLenum, GLenum, const GLint *);
#define glConvolutionParameteriv _ptrc_glConvolutionParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyColorSubTable)(GLenum, GLsizei, GLint, GLint, GLsizei);
#define glCopyColorSubTable _ptrc_glCopyColorSubTable
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyColorTable)(GLenum, GLenum, GLint, GLint, GLsizei);
#define glCopyColorTable _ptrc_glCopyColorTable
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter1D)(GLenum, GLenum, GLint, GLint, GLsizei);
#define glCopyConvolutionFilter1D _ptrc_glCopyConvolutionFilter1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter2D)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
#define glCopyConvolutionFilter2D _ptrc_glCopyConvolutionFilter2D
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTable)(GLenum, GLenum, GLenum, GLvoid *);
#define glGetColorTable _ptrc_glGetColorTable
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfv)(GLenum, GLenum, GLfloat *);
#define glGetColorTableParameterfv _ptrc_glGetColorTableParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameteriv)(GLenum, GLenum, GLint *);
#define glGetColorTableParameteriv _ptrc_glGetColorTableParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionFilter)(GLenum, GLenum, GLenum, GLvoid *);
#define glGetConvolutionFilter _ptrc_glGetConvolutionFilter
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterfv)(GLenum, GLenum, GLfloat *);
#define glGetConvolutionParameterfv _ptrc_glGetConvolutionParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameteriv)(GLenum, GLenum, GLint *);
#define glGetConvolutionParameteriv _ptrc_glGetConvolutionParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogram)(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
#define glGetHistogram _ptrc_glGetHistogram
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterfv)(GLenum, GLenum, GLfloat *);
#define glGetHistogramParameterfv _ptrc_glGetHistogramParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameteriv)(GLenum, GLenum, GLint *);
#define glGetHistogramParameteriv _ptrc_glGetHistogramParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmax)(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
#define glGetMinmax _ptrc_glGetMinmax
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterfv)(GLenum, GLenum, GLfloat *);
#define glGetMinmaxParameterfv _ptrc_glGetMinmaxParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameteriv)(GLenum, GLenum, GLint *);
#define glGetMinmaxParameteriv _ptrc_glGetMinmaxParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSeparableFilter)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *);
#define glGetSeparableFilter _ptrc_glGetSeparableFilter
extern void (CODEGEN_FUNCPTR *_ptrc_glHistogram)(GLenum, GLsizei, GLenum, GLboolean);
#define glHistogram _ptrc_glHistogram
extern void (CODEGEN_FUNCPTR *_ptrc_glMinmax)(GLenum, GLenum, GLboolean);
#define glMinmax _ptrc_glMinmax
extern void (CODEGEN_FUNCPTR *_ptrc_glResetHistogram)(GLenum);
#define glResetHistogram _ptrc_glResetHistogram
extern void (CODEGEN_FUNCPTR *_ptrc_glResetMinmax)(GLenum);
#define glResetMinmax _ptrc_glResetMinmax
extern void (CODEGEN_FUNCPTR *_ptrc_glSeparableFilter2D)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *);
#define glSeparableFilter2D _ptrc_glSeparableFilter2D
#endif /*GL_ARB_imaging*/ 

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArray)(GLuint);
#define glBindVertexArray _ptrc_glBindVertexArray
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArrays)(GLsizei, const GLuint *);
#define glDeleteVertexArrays _ptrc_glDeleteVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArrays)(GLsizei, GLuint *);
#define glGenVertexArrays _ptrc_glGenVertexArrays
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArray)(GLuint);
#define glIsVertexArray _ptrc_glIsVertexArray
#endif /*GL_ARB_vertex_array_object*/ 



#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRange)(GLenum, GLintptr, GLsizeiptr);
#define glFlushMappedBufferRange _ptrc_glFlushMappedBufferRange
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferRange)(GLenum, GLintptr, GLsizeiptr, GLbitfield);
#define glMapBufferRange _ptrc_glMapBufferRange
#endif /*GL_ARB_map_buffer_range*/ 



#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFramebuffer)(GLenum, GLuint);
#define glBindFramebuffer _ptrc_glBindFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbuffer)(GLenum, GLuint);
#define glBindRenderbuffer _ptrc_glBindRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebuffer)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
#define glBlitFramebuffer _ptrc_glBlitFramebuffer
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatus)(GLenum);
#define glCheckFramebufferStatus _ptrc_glCheckFramebufferStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffers)(GLsizei, const GLuint *);
#define glDeleteFramebuffers _ptrc_glDeleteFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffers)(GLsizei, const GLuint *);
#define glDeleteRenderbuffers _ptrc_glDeleteRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint);
#define glFramebufferRenderbuffer _ptrc_glFramebufferRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1D)(GLenum, GLenum, GLenum, GLuint, GLint);
#define glFramebufferTexture1D _ptrc_glFramebufferTexture1D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint);
#define glFramebufferTexture2D _ptrc_glFramebufferTexture2D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3D)(GLenum, GLenum, GLenum, GLuint, GLint, GLint);
#define glFramebufferTexture3D _ptrc_glFramebufferTexture3D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayer)(GLenum, GLenum, GLuint, GLint, GLint);
#define glFramebufferTextureLayer _ptrc_glFramebufferTextureLayer
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffers)(GLsizei, GLuint *);
#define glGenFramebuffers _ptrc_glGenFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffers)(GLsizei, GLuint *);
#define glGenRenderbuffers _ptrc_glGenRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmap)(GLenum);
#define glGenerateMipmap _ptrc_glGenerateMipmap
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *);
#define glGetFramebufferAttachmentParameteriv _ptrc_glGetFramebufferAttachmentParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameteriv)(GLenum, GLenum, GLint *);
#define glGetRenderbufferParameteriv _ptrc_glGetRenderbufferParameteriv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebuffer)(GLuint);
#define glIsFramebuffer _ptrc_glIsFramebuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbuffer)(GLuint);
#define glIsRenderbuffer _ptrc_glIsRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei);
#define glRenderbufferStorage _ptrc_glRenderbufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define glRenderbufferStorageMultisample _ptrc_glRenderbufferStorageMultisample
#endif /*GL_ARB_framebuffer_object*/ 


#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveUniformBlockName _ptrc_glGetActiveUniformBlockName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockiv)(GLuint, GLuint, GLenum, GLint *);
#define glGetActiveUniformBlockiv _ptrc_glGetActiveUniformBlockiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveUniformName _ptrc_glGetActiveUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformsiv)(GLuint, GLsizei, const GLuint *, GLenum, GLint *);
#define glGetActiveUniformsiv _ptrc_glGetActiveUniformsiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBlockIndex)(GLuint, const GLchar *);
#define glGetUniformBlockIndex _ptrc_glGetUniformBlockIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformIndices)(GLuint, GLsizei, const GLchar *const*, GLuint *);
#define glGetUniformIndices _ptrc_glGetUniformIndices
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformBlockBinding)(GLuint, GLuint, GLuint);
#define glUniformBlockBinding _ptrc_glUniformBlockBinding
#endif /*GL_ARB_uniform_buffer_object*/ 

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyBufferSubData)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr);
#define glCopyBufferSubData _ptrc_glCopyBufferSubData
#endif /*GL_ARB_copy_buffer*/ 


#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLint);
#define glDrawElementsBaseVertex _ptrc_glDrawElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint);
#define glDrawElementsInstancedBaseVertex _ptrc_glDrawElementsInstancedBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsBaseVertex)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint);
#define glDrawRangeElementsBaseVertex _ptrc_glDrawRangeElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsBaseVertex)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, const GLint *);
#define glMultiDrawElementsBaseVertex _ptrc_glMultiDrawElementsBaseVertex
#endif /*GL_ARB_draw_elements_base_vertex*/ 


#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertex)(GLenum);
#define glProvokingVertex _ptrc_glProvokingVertex
#endif /*GL_ARB_provoking_vertex*/ 


#ifndef GL_ARB_sync
#define GL_ARB_sync 1
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glClientWaitSync)(GLsync, GLbitfield, GLuint64);
#define glClientWaitSync _ptrc_glClientWaitSync
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSync)(GLsync);
#define glDeleteSync _ptrc_glDeleteSync
extern GLsync (CODEGEN_FUNCPTR *_ptrc_glFenceSync)(GLenum, GLbitfield);
#define glFenceSync _ptrc_glFenceSync
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64v)(GLenum, GLint64 *);
#define glGetInteger64v _ptrc_glGetInteger64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSynciv)(GLsync, GLenum, GLsizei, GLsizei *, GLint *);
#define glGetSynciv _ptrc_glGetSynciv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSync)(GLsync);
#define glIsSync _ptrc_glIsSync
extern void (CODEGEN_FUNCPTR *_ptrc_glWaitSync)(GLsync, GLbitfield, GLuint64);
#define glWaitSync _ptrc_glWaitSync
#endif /*GL_ARB_sync*/ 

#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefv)(GLenum, GLuint, GLfloat *);
#define glGetMultisamplefv _ptrc_glGetMultisamplefv
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaski)(GLuint, GLbitfield);
#define glSampleMaski _ptrc_glSampleMaski
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisample)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean);
#define glTexImage2DMultisample _ptrc_glTexImage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisample)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTexImage3DMultisample _ptrc_glTexImage3DMultisample
#endif /*GL_ARB_texture_multisample*/ 




#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64v)(GLuint, GLenum, GLint64 *);
#define glGetQueryObjecti64v _ptrc_glGetQueryObjecti64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64v)(GLuint, GLenum, GLuint64 *);
#define glGetQueryObjectui64v _ptrc_glGetQueryObjectui64v
extern void (CODEGEN_FUNCPTR *_ptrc_glQueryCounter)(GLuint, GLenum);
#define glQueryCounter _ptrc_glQueryCounter
#endif /*GL_ARB_timer_query*/ 

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP3ui)(GLenum, GLuint);
#define glColorP3ui _ptrc_glColorP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP3uiv)(GLenum, const GLuint *);
#define glColorP3uiv _ptrc_glColorP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP4ui)(GLenum, GLuint);
#define glColorP4ui _ptrc_glColorP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glColorP4uiv)(GLenum, const GLuint *);
#define glColorP4uiv _ptrc_glColorP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1ui)(GLenum, GLenum, GLuint);
#define glMultiTexCoordP1ui _ptrc_glMultiTexCoordP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1uiv)(GLenum, GLenum, const GLuint *);
#define glMultiTexCoordP1uiv _ptrc_glMultiTexCoordP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2ui)(GLenum, GLenum, GLuint);
#define glMultiTexCoordP2ui _ptrc_glMultiTexCoordP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2uiv)(GLenum, GLenum, const GLuint *);
#define glMultiTexCoordP2uiv _ptrc_glMultiTexCoordP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3ui)(GLenum, GLenum, GLuint);
#define glMultiTexCoordP3ui _ptrc_glMultiTexCoordP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3uiv)(GLenum, GLenum, const GLuint *);
#define glMultiTexCoordP3uiv _ptrc_glMultiTexCoordP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4ui)(GLenum, GLenum, GLuint);
#define glMultiTexCoordP4ui _ptrc_glMultiTexCoordP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4uiv)(GLenum, GLenum, const GLuint *);
#define glMultiTexCoordP4uiv _ptrc_glMultiTexCoordP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalP3ui)(GLenum, GLuint);
#define glNormalP3ui _ptrc_glNormalP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalP3uiv)(GLenum, const GLuint *);
#define glNormalP3uiv _ptrc_glNormalP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3ui)(GLenum, GLuint);
#define glSecondaryColorP3ui _ptrc_glSecondaryColorP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3uiv)(GLenum, const GLuint *);
#define glSecondaryColorP3uiv _ptrc_glSecondaryColorP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1ui)(GLenum, GLuint);
#define glTexCoordP1ui _ptrc_glTexCoordP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1uiv)(GLenum, const GLuint *);
#define glTexCoordP1uiv _ptrc_glTexCoordP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2ui)(GLenum, GLuint);
#define glTexCoordP2ui _ptrc_glTexCoordP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2uiv)(GLenum, const GLuint *);
#define glTexCoordP2uiv _ptrc_glTexCoordP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3ui)(GLenum, GLuint);
#define glTexCoordP3ui _ptrc_glTexCoordP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3uiv)(GLenum, const GLuint *);
#define glTexCoordP3uiv _ptrc_glTexCoordP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4ui)(GLenum, GLuint);
#define glTexCoordP4ui _ptrc_glTexCoordP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4uiv)(GLenum, const GLuint *);
#define glTexCoordP4uiv _ptrc_glTexCoordP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP1ui _ptrc_glVertexAttribP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP1uiv _ptrc_glVertexAttribP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP2ui _ptrc_glVertexAttribP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP2uiv _ptrc_glVertexAttribP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP3ui _ptrc_glVertexAttribP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP3uiv _ptrc_glVertexAttribP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP4ui _ptrc_glVertexAttribP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP4uiv _ptrc_glVertexAttribP4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP2ui)(GLenum, GLuint);
#define glVertexP2ui _ptrc_glVertexP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP2uiv)(GLenum, const GLuint *);
#define glVertexP2uiv _ptrc_glVertexP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP3ui)(GLenum, GLuint);
#define glVertexP3ui _ptrc_glVertexP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP3uiv)(GLenum, const GLuint *);
#define glVertexP3uiv _ptrc_glVertexP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP4ui)(GLenum, GLuint);
#define glVertexP4ui _ptrc_glVertexP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexP4uiv)(GLenum, const GLuint *);
#define glVertexP4uiv _ptrc_glVertexP4uiv
#endif /*GL_ARB_vertex_type_2_10_10_10_rev*/ 

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationIndexed)(GLuint, GLuint, GLuint, const GLchar *);
#define glBindFragDataLocationIndexed _ptrc_glBindFragDataLocationIndexed
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataIndex)(GLuint, const GLchar *);
#define glGetFragDataIndex _ptrc_glGetFragDataIndex
#endif /*GL_ARB_blend_func_extended*/ 


#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSampler)(GLuint, GLuint);
#define glBindSampler _ptrc_glBindSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSamplers)(GLsizei, const GLuint *);
#define glDeleteSamplers _ptrc_glDeleteSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenSamplers)(GLsizei, GLuint *);
#define glGenSamplers _ptrc_glGenSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIiv)(GLuint, GLenum, GLint *);
#define glGetSamplerParameterIiv _ptrc_glGetSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIuiv)(GLuint, GLenum, GLuint *);
#define glGetSamplerParameterIuiv _ptrc_glGetSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterfv)(GLuint, GLenum, GLfloat *);
#define glGetSamplerParameterfv _ptrc_glGetSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameteriv)(GLuint, GLenum, GLint *);
#define glGetSamplerParameteriv _ptrc_glGetSamplerParameteriv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSampler)(GLuint);
#define glIsSampler _ptrc_glIsSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIiv)(GLuint, GLenum, const GLint *);
#define glSamplerParameterIiv _ptrc_glSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIuiv)(GLuint, GLenum, const GLuint *);
#define glSamplerParameterIuiv _ptrc_glSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterf)(GLuint, GLenum, GLfloat);
#define glSamplerParameterf _ptrc_glSamplerParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterfv)(GLuint, GLenum, const GLfloat *);
#define glSamplerParameterfv _ptrc_glSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteri)(GLuint, GLenum, GLint);
#define glSamplerParameteri _ptrc_glSamplerParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteriv)(GLuint, GLenum, const GLint *);
#define glSamplerParameteriv _ptrc_glSamplerParameteriv
#endif /*GL_ARB_sampler_objects*/ 

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysIndirect)(GLenum, const GLvoid *);
#define glDrawArraysIndirect _ptrc_glDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsIndirect)(GLenum, GLenum, const GLvoid *);
#define glDrawElementsIndirect _ptrc_glDrawElementsIndirect
#endif /*GL_ARB_draw_indirect*/ 


#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformdv)(GLuint, GLint, GLdouble *);
#define glGetUniformdv _ptrc_glGetUniformdv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1d)(GLint, GLdouble);
#define glUniform1d _ptrc_glUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1dv)(GLint, GLsizei, const GLdouble *);
#define glUniform1dv _ptrc_glUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2d)(GLint, GLdouble, GLdouble);
#define glUniform2d _ptrc_glUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2dv)(GLint, GLsizei, const GLdouble *);
#define glUniform2dv _ptrc_glUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3d)(GLint, GLdouble, GLdouble, GLdouble);
#define glUniform3d _ptrc_glUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3dv)(GLint, GLsizei, const GLdouble *);
#define glUniform3dv _ptrc_glUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4d)(GLint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glUniform4d _ptrc_glUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4dv)(GLint, GLsizei, const GLdouble *);
#define glUniform4dv _ptrc_glUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix2dv _ptrc_glUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix2x3dv _ptrc_glUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix2x4dv _ptrc_glUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix3dv _ptrc_glUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix3x2dv _ptrc_glUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix3x4dv _ptrc_glUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix4dv _ptrc_glUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix4x2dv _ptrc_glUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix4x3dv _ptrc_glUniformMatrix4x3dv
#endif /*GL_ARB_gpu_shader_fp64*/ 

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveSubroutineName _ptrc_glGetActiveSubroutineName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveSubroutineUniformName _ptrc_glGetActiveSubroutineUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformiv)(GLuint, GLenum, GLuint, GLenum, GLint *);
#define glGetActiveSubroutineUniformiv _ptrc_glGetActiveSubroutineUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStageiv)(GLuint, GLenum, GLenum, GLint *);
#define glGetProgramStageiv _ptrc_glGetProgramStageiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineIndex)(GLuint, GLenum, const GLchar *);
#define glGetSubroutineIndex _ptrc_glGetSubroutineIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineUniformLocation)(GLuint, GLenum, const GLchar *);
#define glGetSubroutineUniformLocation _ptrc_glGetSubroutineUniformLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformSubroutineuiv)(GLenum, GLint, GLuint *);
#define glGetUniformSubroutineuiv _ptrc_glGetUniformSubroutineuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformSubroutinesuiv)(GLenum, GLsizei, const GLuint *);
#define glUniformSubroutinesuiv _ptrc_glUniformSubroutinesuiv
#endif /*GL_ARB_shader_subroutine*/ 

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameterfv)(GLenum, const GLfloat *);
#define glPatchParameterfv _ptrc_glPatchParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameteri)(GLenum, GLint);
#define glPatchParameteri _ptrc_glPatchParameteri
#endif /*GL_ARB_tessellation_shader*/ 

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedback)(GLenum, GLuint);
#define glBindTransformFeedback _ptrc_glBindTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacks)(GLsizei, const GLuint *);
#define glDeleteTransformFeedbacks _ptrc_glDeleteTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedback)(GLenum, GLuint);
#define glDrawTransformFeedback _ptrc_glDrawTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacks)(GLsizei, GLuint *);
#define glGenTransformFeedbacks _ptrc_glGenTransformFeedbacks
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedback)(GLuint);
#define glIsTransformFeedback _ptrc_glIsTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedback)();
#define glPauseTransformFeedback _ptrc_glPauseTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedback)();
#define glResumeTransformFeedback _ptrc_glResumeTransformFeedback
#endif /*GL_ARB_transform_feedback2*/ 

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryIndexed)(GLenum, GLuint, GLuint);
#define glBeginQueryIndexed _ptrc_glBeginQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStream)(GLenum, GLuint, GLuint);
#define glDrawTransformFeedbackStream _ptrc_glDrawTransformFeedbackStream
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQueryIndexed)(GLenum, GLuint);
#define glEndQueryIndexed _ptrc_glEndQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryIndexediv)(GLenum, GLuint, GLenum, GLint *);
#define glGetQueryIndexediv _ptrc_glGetQueryIndexediv
#endif /*GL_ARB_transform_feedback3*/ 

#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthf)(GLfloat);
#define glClearDepthf _ptrc_glClearDepthf
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangef)(GLfloat, GLfloat);
#define glDepthRangef _ptrc_glDepthRangef
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderPrecisionFormat)(GLenum, GLenum, GLint *, GLint *);
#define glGetShaderPrecisionFormat _ptrc_glGetShaderPrecisionFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glReleaseShaderCompiler)();
#define glReleaseShaderCompiler _ptrc_glReleaseShaderCompiler
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderBinary)(GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei);
#define glShaderBinary _ptrc_glShaderBinary
#endif /*GL_ARB_ES2_compatibility*/ 

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramBinary)(GLuint, GLsizei, GLsizei *, GLenum *, GLvoid *);
#define glGetProgramBinary _ptrc_glGetProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBinary)(GLuint, GLenum, const GLvoid *, GLsizei);
#define glProgramBinary _ptrc_glProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteri)(GLuint, GLenum, GLint);
#define glProgramParameteri _ptrc_glProgramParameteri
#endif /*GL_ARB_get_program_binary*/ 

#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveShaderProgram)(GLuint, GLuint);
#define glActiveShaderProgram _ptrc_glActiveShaderProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramPipeline)(GLuint);
#define glBindProgramPipeline _ptrc_glBindProgramPipeline
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramv)(GLenum, GLsizei, const GLchar *const*);
#define glCreateShaderProgramv _ptrc_glCreateShaderProgramv
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramPipelines)(GLsizei, const GLuint *);
#define glDeleteProgramPipelines _ptrc_glDeleteProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramPipelines)(GLsizei, GLuint *);
#define glGenProgramPipelines _ptrc_glGenProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetProgramPipelineInfoLog _ptrc_glGetProgramPipelineInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineiv)(GLuint, GLenum, GLint *);
#define glGetProgramPipelineiv _ptrc_glGetProgramPipelineiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramPipeline)(GLuint);
#define glIsProgramPipeline _ptrc_glIsProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1d)(GLuint, GLint, GLdouble);
#define glProgramUniform1d _ptrc_glProgramUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform1dv _ptrc_glProgramUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1f)(GLuint, GLint, GLfloat);
#define glProgramUniform1f _ptrc_glProgramUniform1f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform1fv _ptrc_glProgramUniform1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i)(GLuint, GLint, GLint);
#define glProgramUniform1i _ptrc_glProgramUniform1i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform1iv _ptrc_glProgramUniform1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui)(GLuint, GLint, GLuint);
#define glProgramUniform1ui _ptrc_glProgramUniform1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform1uiv _ptrc_glProgramUniform1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2d)(GLuint, GLint, GLdouble, GLdouble);
#define glProgramUniform2d _ptrc_glProgramUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform2dv _ptrc_glProgramUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2f)(GLuint, GLint, GLfloat, GLfloat);
#define glProgramUniform2f _ptrc_glProgramUniform2f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform2fv _ptrc_glProgramUniform2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i)(GLuint, GLint, GLint, GLint);
#define glProgramUniform2i _ptrc_glProgramUniform2i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform2iv _ptrc_glProgramUniform2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui)(GLuint, GLint, GLuint, GLuint);
#define glProgramUniform2ui _ptrc_glProgramUniform2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform2uiv _ptrc_glProgramUniform2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3d)(GLuint, GLint, GLdouble, GLdouble, GLdouble);
#define glProgramUniform3d _ptrc_glProgramUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform3dv _ptrc_glProgramUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3f)(GLuint, GLint, GLfloat, GLfloat, GLfloat);
#define glProgramUniform3f _ptrc_glProgramUniform3f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform3fv _ptrc_glProgramUniform3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i)(GLuint, GLint, GLint, GLint, GLint);
#define glProgramUniform3i _ptrc_glProgramUniform3i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform3iv _ptrc_glProgramUniform3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui)(GLuint, GLint, GLuint, GLuint, GLuint);
#define glProgramUniform3ui _ptrc_glProgramUniform3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform3uiv _ptrc_glProgramUniform3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4d)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramUniform4d _ptrc_glProgramUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform4dv _ptrc_glProgramUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4f)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramUniform4f _ptrc_glProgramUniform4f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform4fv _ptrc_glProgramUniform4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i)(GLuint, GLint, GLint, GLint, GLint, GLint);
#define glProgramUniform4i _ptrc_glProgramUniform4i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform4iv _ptrc_glProgramUniform4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
#define glProgramUniform4ui _ptrc_glProgramUniform4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform4uiv _ptrc_glProgramUniform4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2dv _ptrc_glProgramUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2fv _ptrc_glProgramUniformMatrix2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2x3dv _ptrc_glProgramUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2x3fv _ptrc_glProgramUniformMatrix2x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2x4dv _ptrc_glProgramUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2x4fv _ptrc_glProgramUniformMatrix2x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3dv _ptrc_glProgramUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3fv _ptrc_glProgramUniformMatrix3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3x2dv _ptrc_glProgramUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3x2fv _ptrc_glProgramUniformMatrix3x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3x4dv _ptrc_glProgramUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3x4fv _ptrc_glProgramUniformMatrix3x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4dv _ptrc_glProgramUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4fv _ptrc_glProgramUniformMatrix4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4x2dv _ptrc_glProgramUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4x2fv _ptrc_glProgramUniformMatrix4x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4x3dv _ptrc_glProgramUniformMatrix4x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4x3fv _ptrc_glProgramUniformMatrix4x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgramStages)(GLuint, GLbitfield, GLuint);
#define glUseProgramStages _ptrc_glUseProgramStages
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramPipeline)(GLuint);
#define glValidateProgramPipeline _ptrc_glValidateProgramPipeline
#endif /*GL_ARB_separate_shader_objects*/ 

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdv)(GLuint, GLenum, GLdouble *);
#define glGetVertexAttribLdv _ptrc_glGetVertexAttribLdv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1d)(GLuint, GLdouble);
#define glVertexAttribL1d _ptrc_glVertexAttribL1d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dv)(GLuint, const GLdouble *);
#define glVertexAttribL1dv _ptrc_glVertexAttribL1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2d)(GLuint, GLdouble, GLdouble);
#define glVertexAttribL2d _ptrc_glVertexAttribL2d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dv)(GLuint, const GLdouble *);
#define glVertexAttribL2dv _ptrc_glVertexAttribL2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3d)(GLuint, GLdouble, GLdouble, GLdouble);
#define glVertexAttribL3d _ptrc_glVertexAttribL3d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dv)(GLuint, const GLdouble *);
#define glVertexAttribL3dv _ptrc_glVertexAttribL3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertexAttribL4d _ptrc_glVertexAttribL4d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dv)(GLuint, const GLdouble *);
#define glVertexAttribL4dv _ptrc_glVertexAttribL4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointer)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexAttribLPointer _ptrc_glVertexAttribLPointer
#endif /*GL_ARB_vertex_attrib_64bit*/ 

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeArrayv)(GLuint, GLsizei, const GLdouble *);
#define glDepthRangeArrayv _ptrc_glDepthRangeArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeIndexed)(GLuint, GLdouble, GLdouble);
#define glDepthRangeIndexed _ptrc_glDepthRangeIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_v)(GLenum, GLuint, GLdouble *);
#define glGetDoublei_v _ptrc_glGetDoublei_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_v)(GLenum, GLuint, GLfloat *);
#define glGetFloati_v _ptrc_glGetFloati_v
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorArrayv)(GLuint, GLsizei, const GLint *);
#define glScissorArrayv _ptrc_glScissorArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexed)(GLuint, GLint, GLint, GLsizei, GLsizei);
#define glScissorIndexed _ptrc_glScissorIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexedv)(GLuint, const GLint *);
#define glScissorIndexedv _ptrc_glScissorIndexedv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportArrayv)(GLuint, GLsizei, const GLfloat *);
#define glViewportArrayv _ptrc_glViewportArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedf)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glViewportIndexedf _ptrc_glViewportIndexedf
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedfv)(GLuint, const GLfloat *);
#define glViewportIndexedfv _ptrc_glViewportIndexedfv
#endif /*GL_ARB_viewport_array*/ 

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedBaseInstance)(GLenum, GLint, GLsizei, GLsizei, GLuint);
#define glDrawArraysInstancedBaseInstance _ptrc_glDrawArraysInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseInstance)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint);
#define glDrawElementsInstancedBaseInstance _ptrc_glDrawElementsInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint);
#define glDrawElementsInstancedBaseVertexBaseInstance _ptrc_glDrawElementsInstancedBaseVertexBaseInstance
#endif /*GL_ARB_base_instance*/ 


#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackInstanced)(GLenum, GLuint, GLsizei);
#define glDrawTransformFeedbackInstanced _ptrc_glDrawTransformFeedbackInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStreamInstanced)(GLenum, GLuint, GLuint, GLsizei);
#define glDrawTransformFeedbackStreamInstanced _ptrc_glDrawTransformFeedbackStreamInstanced
#endif /*GL_ARB_transform_feedback_instanced*/ 



#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformativ)(GLenum, GLenum, GLenum, GLsizei, GLint *);
#define glGetInternalformativ _ptrc_glGetInternalformativ
#endif /*GL_ARB_internalformat_query*/ 


#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAtomicCounterBufferiv)(GLuint, GLuint, GLenum, GLint *);
#define glGetActiveAtomicCounterBufferiv _ptrc_glGetActiveAtomicCounterBufferiv
#endif /*GL_ARB_shader_atomic_counters*/ 

#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTexture)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum);
#define glBindImageTexture _ptrc_glBindImageTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrier)(GLbitfield);
#define glMemoryBarrier _ptrc_glMemoryBarrier
#endif /*GL_ARB_shader_image_load_store*/ 


#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage1D)(GLenum, GLsizei, GLenum, GLsizei);
#define glTexStorage1D _ptrc_glTexStorage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define glTexStorage2D _ptrc_glTexStorage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
#define glTexStorage3D _ptrc_glTexStorage3D
#endif /*GL_ARB_texture_storage*/ 

#ifndef GL_KHR_debug
#define GL_KHR_debug 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallback)(GLDEBUGPROC, const void *);
#define glDebugMessageCallback _ptrc_glDebugMessageCallback
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControl)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean);
#define glDebugMessageControl _ptrc_glDebugMessageControl
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsert)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *);
#define glDebugMessageInsert _ptrc_glDebugMessageInsert
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLog)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);
#define glGetDebugMessageLog _ptrc_glGetDebugMessageLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectLabel)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetObjectLabel _ptrc_glGetObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectPtrLabel)(const void *, GLsizei, GLsizei *, GLchar *);
#define glGetObjectPtrLabel _ptrc_glGetObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointerv)(GLenum, GLvoid **);
#define glGetPointerv _ptrc_glGetPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectLabel)(GLenum, GLuint, GLsizei, const GLchar *);
#define glObjectLabel _ptrc_glObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectPtrLabel)(const void *, GLsizei, const GLchar *);
#define glObjectPtrLabel _ptrc_glObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glPopDebugGroup)();
#define glPopDebugGroup _ptrc_glPopDebugGroup
extern void (CODEGEN_FUNCPTR *_ptrc_glPushDebugGroup)(GLenum, GLuint, GLsizei, const GLchar *);
#define glPushDebugGroup _ptrc_glPushDebugGroup
#endif /*GL_KHR_debug*/ 


#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferData)(GLenum, GLenum, GLenum, GLenum, const void *);
#define glClearBufferData _ptrc_glClearBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferSubData)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *);
#define glClearBufferSubData _ptrc_glClearBufferSubData
#endif /*GL_ARB_clear_buffer_object*/ 

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchCompute)(GLuint, GLuint, GLuint);
#define glDispatchCompute _ptrc_glDispatchCompute
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeIndirect)(GLintptr);
#define glDispatchComputeIndirect _ptrc_glDispatchComputeIndirect
#endif /*GL_ARB_compute_shader*/ 

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubData)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
#define glCopyImageSubData _ptrc_glCopyImageSubData
#endif /*GL_ARB_copy_image*/ 




#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferParameteri)(GLenum, GLenum, GLint);
#define glFramebufferParameteri _ptrc_glFramebufferParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameteriv)(GLenum, GLenum, GLint *);
#define glGetFramebufferParameteriv _ptrc_glGetFramebufferParameteriv
#endif /*GL_ARB_framebuffer_no_attachments*/ 

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformati64v)(GLenum, GLenum, GLenum, GLsizei, GLint64 *);
#define glGetInternalformati64v _ptrc_glGetInternalformati64v
#endif /*GL_ARB_internalformat_query2*/ 

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferData)(GLuint);
#define glInvalidateBufferData _ptrc_glInvalidateBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferSubData)(GLuint, GLintptr, GLsizeiptr);
#define glInvalidateBufferSubData _ptrc_glInvalidateBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateFramebuffer)(GLenum, GLsizei, const GLenum *);
#define glInvalidateFramebuffer _ptrc_glInvalidateFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateSubFramebuffer)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei);
#define glInvalidateSubFramebuffer _ptrc_glInvalidateSubFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexImage)(GLuint, GLint);
#define glInvalidateTexImage _ptrc_glInvalidateTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
#define glInvalidateTexSubImage _ptrc_glInvalidateTexSubImage
#endif /*GL_ARB_invalidate_subdata*/ 

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirect)(GLenum, const void *, GLsizei, GLsizei);
#define glMultiDrawArraysIndirect _ptrc_glMultiDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirect)(GLenum, GLenum, const void *, GLsizei, GLsizei);
#define glMultiDrawElementsIndirect _ptrc_glMultiDrawElementsIndirect
#endif /*GL_ARB_multi_draw_indirect*/ 

#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInterfaceiv)(GLuint, GLenum, GLenum, GLint *);
#define glGetProgramInterfaceiv _ptrc_glGetProgramInterfaceiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceIndex)(GLuint, GLenum, const GLchar *);
#define glGetProgramResourceIndex _ptrc_glGetProgramResourceIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocation)(GLuint, GLenum, const GLchar *);
#define glGetProgramResourceLocation _ptrc_glGetProgramResourceLocation
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocationIndex)(GLuint, GLenum, const GLchar *);
#define glGetProgramResourceLocationIndex _ptrc_glGetProgramResourceLocationIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetProgramResourceName _ptrc_glGetProgramResourceName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceiv)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *);
#define glGetProgramResourceiv _ptrc_glGetProgramResourceiv
#endif /*GL_ARB_program_interface_query*/ 


#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderStorageBlockBinding)(GLuint, GLuint, GLuint);
#define glShaderStorageBlockBinding _ptrc_glShaderStorageBlockBinding
#endif /*GL_ARB_shader_storage_buffer_object*/ 


#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferRange)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr);
#define glTexBufferRange _ptrc_glTexBufferRange
#endif /*GL_ARB_texture_buffer_range*/ 


#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
#define glTexStorage2DMultisample _ptrc_glTexStorage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTexStorage3DMultisample _ptrc_glTexStorage3DMultisample
#endif /*GL_ARB_texture_storage_multisample*/ 

#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureView)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint);
#define glTextureView _ptrc_glTextureView
#endif /*GL_ARB_texture_view*/ 

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffer)(GLuint, GLuint, GLintptr, GLsizei);
#define glBindVertexBuffer _ptrc_glBindVertexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribBinding)(GLuint, GLuint);
#define glVertexAttribBinding _ptrc_glVertexAttribBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormat)(GLuint, GLint, GLenum, GLboolean, GLuint);
#define glVertexAttribFormat _ptrc_glVertexAttribFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormat)(GLuint, GLint, GLenum, GLuint);
#define glVertexAttribIFormat _ptrc_glVertexAttribIFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormat)(GLuint, GLint, GLenum, GLuint);
#define glVertexAttribLFormat _ptrc_glVertexAttribLFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexBindingDivisor)(GLuint, GLuint);
#define glVertexBindingDivisor _ptrc_glVertexBindingDivisor
#endif /*GL_ARB_vertex_attrib_binding*/ 

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferStorage)(GLenum, GLsizeiptr, const void *, GLbitfield);
#define glBufferStorage _ptrc_glBufferStorage
#endif /*GL_ARB_buffer_storage*/ 

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexImage)(GLuint, GLint, GLenum, GLenum, const void *);
#define glClearTexImage _ptrc_glClearTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
#define glClearTexSubImage _ptrc_glClearTexSubImage
#endif /*GL_ARB_clear_texture*/ 


#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersBase)(GLenum, GLuint, GLsizei, const GLuint *);
#define glBindBuffersBase _ptrc_glBindBuffersBase
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersRange)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *);
#define glBindBuffersRange _ptrc_glBindBuffersRange
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextures)(GLuint, GLsizei, const GLuint *);
#define glBindImageTextures _ptrc_glBindImageTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSamplers)(GLuint, GLsizei, const GLuint *);
#define glBindSamplers _ptrc_glBindSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextures)(GLuint, GLsizei, const GLuint *);
#define glBindTextures _ptrc_glBindTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffers)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *);
#define glBindVertexBuffers _ptrc_glBindVertexBuffers
#endif /*GL_ARB_multi_bind*/ 






#ifndef GL_3DFX_tbuffer
#define GL_3DFX_tbuffer 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTbufferMask3DFX)(GLuint);
#define glTbufferMask3DFX _ptrc_glTbufferMask3DFX
#endif /*GL_3DFX_tbuffer*/ 




#ifndef GL_AMD_debug_output
#define GL_AMD_debug_output 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallbackAMD)(GLDEBUGPROCAMD, void *);
#define glDebugMessageCallbackAMD _ptrc_glDebugMessageCallbackAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageEnableAMD)(GLenum, GLenum, GLsizei, const GLuint *, GLboolean);
#define glDebugMessageEnableAMD _ptrc_glDebugMessageEnableAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsertAMD)(GLenum, GLenum, GLuint, GLsizei, const GLchar *);
#define glDebugMessageInsertAMD _ptrc_glDebugMessageInsertAMD
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLogAMD)(GLuint, GLsizei, GLenum *, GLuint *, GLuint *, GLsizei *, GLchar *);
#define glGetDebugMessageLogAMD _ptrc_glGetDebugMessageLogAMD
#endif /*GL_AMD_debug_output*/ 


#ifndef GL_AMD_draw_buffers_blend
#define GL_AMD_draw_buffers_blend 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationIndexedAMD)(GLuint, GLenum);
#define glBlendEquationIndexedAMD _ptrc_glBlendEquationIndexedAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateIndexedAMD)(GLuint, GLenum, GLenum);
#define glBlendEquationSeparateIndexedAMD _ptrc_glBlendEquationSeparateIndexedAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncIndexedAMD)(GLuint, GLenum, GLenum);
#define glBlendFuncIndexedAMD _ptrc_glBlendFuncIndexedAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateIndexedAMD)(GLuint, GLenum, GLenum, GLenum, GLenum);
#define glBlendFuncSeparateIndexedAMD _ptrc_glBlendFuncSeparateIndexedAMD
#endif /*GL_AMD_draw_buffers_blend*/ 

#ifndef GL_AMD_interleaved_elements
#define GL_AMD_interleaved_elements 1
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribParameteriAMD)(GLuint, GLenum, GLint);
#define glVertexAttribParameteriAMD _ptrc_glVertexAttribParameteriAMD
#endif /*GL_AMD_interleaved_elements*/ 

#ifndef GL_AMD_multi_draw_indirect
#define GL_AMD_multi_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectAMD)(GLenum, const GLvoid *, GLsizei, GLsizei);
#define glMultiDrawArraysIndirectAMD _ptrc_glMultiDrawArraysIndirectAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectAMD)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei);
#define glMultiDrawElementsIndirectAMD _ptrc_glMultiDrawElementsIndirectAMD
#endif /*GL_AMD_multi_draw_indirect*/ 

#ifndef GL_AMD_name_gen_delete
#define GL_AMD_name_gen_delete 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteNamesAMD)(GLenum, GLuint, const GLuint *);
#define glDeleteNamesAMD _ptrc_glDeleteNamesAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGenNamesAMD)(GLenum, GLuint, GLuint *);
#define glGenNamesAMD _ptrc_glGenNamesAMD
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNameAMD)(GLenum, GLuint);
#define glIsNameAMD _ptrc_glIsNameAMD
#endif /*GL_AMD_name_gen_delete*/ 

#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginPerfMonitorAMD)(GLuint);
#define glBeginPerfMonitorAMD _ptrc_glBeginPerfMonitorAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glDeletePerfMonitorsAMD)(GLsizei, GLuint *);
#define glDeletePerfMonitorsAMD _ptrc_glDeletePerfMonitorsAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glEndPerfMonitorAMD)(GLuint);
#define glEndPerfMonitorAMD _ptrc_glEndPerfMonitorAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGenPerfMonitorsAMD)(GLsizei, GLuint *);
#define glGenPerfMonitorsAMD _ptrc_glGenPerfMonitorsAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCounterDataAMD)(GLuint, GLenum, GLsizei, GLuint *, GLint *);
#define glGetPerfMonitorCounterDataAMD _ptrc_glGetPerfMonitorCounterDataAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCounterInfoAMD)(GLuint, GLuint, GLenum, GLvoid *);
#define glGetPerfMonitorCounterInfoAMD _ptrc_glGetPerfMonitorCounterInfoAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCounterStringAMD)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetPerfMonitorCounterStringAMD _ptrc_glGetPerfMonitorCounterStringAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCountersAMD)(GLuint, GLint *, GLint *, GLsizei, GLuint *);
#define glGetPerfMonitorCountersAMD _ptrc_glGetPerfMonitorCountersAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorGroupStringAMD)(GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetPerfMonitorGroupStringAMD _ptrc_glGetPerfMonitorGroupStringAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorGroupsAMD)(GLint *, GLsizei, GLuint *);
#define glGetPerfMonitorGroupsAMD _ptrc_glGetPerfMonitorGroupsAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glSelectPerfMonitorCountersAMD)(GLuint, GLboolean, GLuint, GLint, GLuint *);
#define glSelectPerfMonitorCountersAMD _ptrc_glSelectPerfMonitorCountersAMD
#endif /*GL_AMD_performance_monitor*/ 



#ifndef GL_AMD_sample_positions
#define GL_AMD_sample_positions 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSetMultisamplefvAMD)(GLenum, GLuint, const GLfloat *);
#define glSetMultisamplefvAMD _ptrc_glSetMultisamplefvAMD
#endif /*GL_AMD_sample_positions*/ 




#ifndef GL_AMD_sparse_texture
#define GL_AMD_sparse_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorageSparseAMD)(GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield);
#define glTexStorageSparseAMD _ptrc_glTexStorageSparseAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorageSparseAMD)(GLuint, GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield);
#define glTextureStorageSparseAMD _ptrc_glTextureStorageSparseAMD
#endif /*GL_AMD_sparse_texture*/ 

#ifndef GL_AMD_stencil_operation_extended
#define GL_AMD_stencil_operation_extended 1
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilOpValueAMD)(GLenum, GLuint);
#define glStencilOpValueAMD _ptrc_glStencilOpValueAMD
#endif /*GL_AMD_stencil_operation_extended*/ 




#ifndef GL_AMD_vertex_shader_tessellator
#define GL_AMD_vertex_shader_tessellator 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTessellationFactorAMD)(GLfloat);
#define glTessellationFactorAMD _ptrc_glTessellationFactorAMD
extern void (CODEGEN_FUNCPTR *_ptrc_glTessellationModeAMD)(GLenum);
#define glTessellationModeAMD _ptrc_glTessellationModeAMD
#endif /*GL_AMD_vertex_shader_tessellator*/ 




#ifndef GL_APPLE_element_array
#define GL_APPLE_element_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementArrayAPPLE)(GLenum, GLint, GLsizei);
#define glDrawElementArrayAPPLE _ptrc_glDrawElementArrayAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementArrayAPPLE)(GLenum, GLuint, GLuint, GLint, GLsizei);
#define glDrawRangeElementArrayAPPLE _ptrc_glDrawRangeElementArrayAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glElementPointerAPPLE)(GLenum, const GLvoid *);
#define glElementPointerAPPLE _ptrc_glElementPointerAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementArrayAPPLE)(GLenum, const GLint *, const GLsizei *, GLsizei);
#define glMultiDrawElementArrayAPPLE _ptrc_glMultiDrawElementArrayAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawRangeElementArrayAPPLE)(GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei);
#define glMultiDrawRangeElementArrayAPPLE _ptrc_glMultiDrawRangeElementArrayAPPLE
#endif /*GL_APPLE_element_array*/ 

#ifndef GL_APPLE_fence
#define GL_APPLE_fence 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFencesAPPLE)(GLsizei, const GLuint *);
#define glDeleteFencesAPPLE _ptrc_glDeleteFencesAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glFinishFenceAPPLE)(GLuint);
#define glFinishFenceAPPLE _ptrc_glFinishFenceAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glFinishObjectAPPLE)(GLenum, GLint);
#define glFinishObjectAPPLE _ptrc_glFinishObjectAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFencesAPPLE)(GLsizei, GLuint *);
#define glGenFencesAPPLE _ptrc_glGenFencesAPPLE
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFenceAPPLE)(GLuint);
#define glIsFenceAPPLE _ptrc_glIsFenceAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glSetFenceAPPLE)(GLuint);
#define glSetFenceAPPLE _ptrc_glSetFenceAPPLE
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestFenceAPPLE)(GLuint);
#define glTestFenceAPPLE _ptrc_glTestFenceAPPLE
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestObjectAPPLE)(GLenum, GLuint);
#define glTestObjectAPPLE _ptrc_glTestObjectAPPLE
#endif /*GL_APPLE_fence*/ 


#ifndef GL_APPLE_flush_buffer_range
#define GL_APPLE_flush_buffer_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferParameteriAPPLE)(GLenum, GLenum, GLint);
#define glBufferParameteriAPPLE _ptrc_glBufferParameteriAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRangeAPPLE)(GLenum, GLintptr, GLsizeiptr);
#define glFlushMappedBufferRangeAPPLE _ptrc_glFlushMappedBufferRangeAPPLE
#endif /*GL_APPLE_flush_buffer_range*/ 

#ifndef GL_APPLE_object_purgeable
#define GL_APPLE_object_purgeable 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterivAPPLE)(GLenum, GLuint, GLenum, GLint *);
#define glGetObjectParameterivAPPLE _ptrc_glGetObjectParameterivAPPLE
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glObjectPurgeableAPPLE)(GLenum, GLuint, GLenum);
#define glObjectPurgeableAPPLE _ptrc_glObjectPurgeableAPPLE
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glObjectUnpurgeableAPPLE)(GLenum, GLuint, GLenum);
#define glObjectUnpurgeableAPPLE _ptrc_glObjectUnpurgeableAPPLE
#endif /*GL_APPLE_object_purgeable*/ 




#ifndef GL_APPLE_texture_range
#define GL_APPLE_texture_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterPointervAPPLE)(GLenum, GLenum, GLvoid **);
#define glGetTexParameterPointervAPPLE _ptrc_glGetTexParameterPointervAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureRangeAPPLE)(GLenum, GLsizei, const GLvoid *);
#define glTextureRangeAPPLE _ptrc_glTextureRangeAPPLE
#endif /*GL_APPLE_texture_range*/ 


#ifndef GL_APPLE_vertex_array_object
#define GL_APPLE_vertex_array_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArrayAPPLE)(GLuint);
#define glBindVertexArrayAPPLE _ptrc_glBindVertexArrayAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArraysAPPLE)(GLsizei, const GLuint *);
#define glDeleteVertexArraysAPPLE _ptrc_glDeleteVertexArraysAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArraysAPPLE)(GLsizei, GLuint *);
#define glGenVertexArraysAPPLE _ptrc_glGenVertexArraysAPPLE
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArrayAPPLE)(GLuint);
#define glIsVertexArrayAPPLE _ptrc_glIsVertexArrayAPPLE
#endif /*GL_APPLE_vertex_array_object*/ 

#ifndef GL_APPLE_vertex_array_range
#define GL_APPLE_vertex_array_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushVertexArrayRangeAPPLE)(GLsizei, GLvoid *);
#define glFlushVertexArrayRangeAPPLE _ptrc_glFlushVertexArrayRangeAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayParameteriAPPLE)(GLenum, GLint);
#define glVertexArrayParameteriAPPLE _ptrc_glVertexArrayParameteriAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayRangeAPPLE)(GLsizei, GLvoid *);
#define glVertexArrayRangeAPPLE _ptrc_glVertexArrayRangeAPPLE
#endif /*GL_APPLE_vertex_array_range*/ 

#ifndef GL_APPLE_vertex_program_evaluators
#define GL_APPLE_vertex_program_evaluators 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribAPPLE)(GLuint, GLenum);
#define glDisableVertexAttribAPPLE _ptrc_glDisableVertexAttribAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribAPPLE)(GLuint, GLenum);
#define glEnableVertexAttribAPPLE _ptrc_glEnableVertexAttribAPPLE
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexAttribEnabledAPPLE)(GLuint, GLenum);
#define glIsVertexAttribEnabledAPPLE _ptrc_glIsVertexAttribEnabledAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib1dAPPLE)(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
#define glMapVertexAttrib1dAPPLE _ptrc_glMapVertexAttrib1dAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib1fAPPLE)(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
#define glMapVertexAttrib1fAPPLE _ptrc_glMapVertexAttrib1fAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib2dAPPLE)(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
#define glMapVertexAttrib2dAPPLE _ptrc_glMapVertexAttrib2dAPPLE
extern void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib2fAPPLE)(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
#define glMapVertexAttrib2fAPPLE _ptrc_glMapVertexAttrib2fAPPLE
#endif /*GL_APPLE_vertex_program_evaluators*/ 


#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1
extern GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetImageHandleARB)(GLuint, GLint, GLboolean, GLint, GLenum);
#define glGetImageHandleARB _ptrc_glGetImageHandleARB
extern GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureHandleARB)(GLuint);
#define glGetTextureHandleARB _ptrc_glGetTextureHandleARB
extern GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureSamplerHandleARB)(GLuint, GLuint);
#define glGetTextureSamplerHandleARB _ptrc_glGetTextureSamplerHandleARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLui64vARB)(GLuint, GLenum, GLuint64EXT *);
#define glGetVertexAttribLui64vARB _ptrc_glGetVertexAttribLui64vARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsImageHandleResidentARB)(GLuint64);
#define glIsImageHandleResidentARB _ptrc_glIsImageHandleResidentARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureHandleResidentARB)(GLuint64);
#define glIsTextureHandleResidentARB _ptrc_glIsTextureHandleResidentARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleNonResidentARB)(GLuint64);
#define glMakeImageHandleNonResidentARB _ptrc_glMakeImageHandleNonResidentARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleResidentARB)(GLuint64, GLenum);
#define glMakeImageHandleResidentARB _ptrc_glMakeImageHandleResidentARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleNonResidentARB)(GLuint64);
#define glMakeTextureHandleNonResidentARB _ptrc_glMakeTextureHandleNonResidentARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleResidentARB)(GLuint64);
#define glMakeTextureHandleResidentARB _ptrc_glMakeTextureHandleResidentARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64ARB)(GLuint, GLint, GLuint64);
#define glProgramUniformHandleui64ARB _ptrc_glProgramUniformHandleui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64vARB)(GLuint, GLint, GLsizei, const GLuint64 *);
#define glProgramUniformHandleui64vARB _ptrc_glProgramUniformHandleui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64ARB)(GLint, GLuint64);
#define glUniformHandleui64ARB _ptrc_glUniformHandleui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64vARB)(GLint, GLsizei, const GLuint64 *);
#define glUniformHandleui64vARB _ptrc_glUniformHandleui64vARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64ARB)(GLuint, GLuint64EXT);
#define glVertexAttribL1ui64ARB _ptrc_glVertexAttribL1ui64ARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64vARB)(GLuint, const GLuint64EXT *);
#define glVertexAttribL1ui64vARB _ptrc_glVertexAttribL1ui64vARB
#endif /*GL_ARB_bindless_texture*/ 

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1
extern GLsync (CODEGEN_FUNCPTR *_ptrc_glCreateSyncFromCLeventARB)(struct _cl_context *, struct _cl_event *, GLbitfield);
#define glCreateSyncFromCLeventARB _ptrc_glCreateSyncFromCLeventARB
#endif /*GL_ARB_cl_event*/ 

#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClampColorARB)(GLenum, GLenum);
#define glClampColorARB _ptrc_glClampColorARB
#endif /*GL_ARB_color_buffer_float*/ 


#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeGroupSizeARB)(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glDispatchComputeGroupSizeARB _ptrc_glDispatchComputeGroupSizeARB
#endif /*GL_ARB_compute_variable_group_size*/ 

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallbackARB)(GLDEBUGPROCARB, const void *);
#define glDebugMessageCallbackARB _ptrc_glDebugMessageCallbackARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControlARB)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean);
#define glDebugMessageControlARB _ptrc_glDebugMessageControlARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsertARB)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *);
#define glDebugMessageInsertARB _ptrc_glDebugMessageInsertARB
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLogARB)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);
#define glGetDebugMessageLogARB _ptrc_glGetDebugMessageLogARB
#endif /*GL_ARB_debug_output*/ 


#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersARB)(GLsizei, const GLenum *);
#define glDrawBuffersARB _ptrc_glDrawBuffersARB
#endif /*GL_ARB_draw_buffers*/ 

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateiARB)(GLuint, GLenum, GLenum);
#define glBlendEquationSeparateiARB _ptrc_glBlendEquationSeparateiARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationiARB)(GLuint, GLenum);
#define glBlendEquationiARB _ptrc_glBlendEquationiARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateiARB)(GLuint, GLenum, GLenum, GLenum, GLenum);
#define glBlendFuncSeparateiARB _ptrc_glBlendFuncSeparateiARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFunciARB)(GLuint, GLenum, GLenum);
#define glBlendFunciARB _ptrc_glBlendFunciARB
#endif /*GL_ARB_draw_buffers_blend*/ 

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedARB)(GLenum, GLint, GLsizei, GLsizei);
#define glDrawArraysInstancedARB _ptrc_glDrawArraysInstancedARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedARB)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei);
#define glDrawElementsInstancedARB _ptrc_glDrawElementsInstancedARB
#endif /*GL_ARB_draw_instanced*/ 


#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramARB)(GLenum, GLuint);
#define glBindProgramARB _ptrc_glBindProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsARB)(GLsizei, const GLuint *);
#define glDeleteProgramsARB _ptrc_glDeleteProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsARB)(GLsizei, GLuint *);
#define glGenProgramsARB _ptrc_glGenProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterdvARB)(GLenum, GLuint, GLdouble *);
#define glGetProgramEnvParameterdvARB _ptrc_glGetProgramEnvParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterfvARB)(GLenum, GLuint, GLfloat *);
#define glGetProgramEnvParameterfvARB _ptrc_glGetProgramEnvParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterdvARB)(GLenum, GLuint, GLdouble *);
#define glGetProgramLocalParameterdvARB _ptrc_glGetProgramLocalParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterfvARB)(GLenum, GLuint, GLfloat *);
#define glGetProgramLocalParameterfvARB _ptrc_glGetProgramLocalParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringARB)(GLenum, GLenum, GLvoid *);
#define glGetProgramStringARB _ptrc_glGetProgramStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivARB)(GLenum, GLenum, GLint *);
#define glGetProgramivARB _ptrc_glGetProgramivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramARB)(GLuint);
#define glIsProgramARB _ptrc_glIsProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramEnvParameter4dARB _ptrc_glProgramEnvParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dvARB)(GLenum, GLuint, const GLdouble *);
#define glProgramEnvParameter4dvARB _ptrc_glProgramEnvParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramEnvParameter4fARB _ptrc_glProgramEnvParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fvARB)(GLenum, GLuint, const GLfloat *);
#define glProgramEnvParameter4fvARB _ptrc_glProgramEnvParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramLocalParameter4dARB _ptrc_glProgramLocalParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dvARB)(GLenum, GLuint, const GLdouble *);
#define glProgramLocalParameter4dvARB _ptrc_glProgramLocalParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramLocalParameter4fARB _ptrc_glProgramLocalParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fvARB)(GLenum, GLuint, const GLfloat *);
#define glProgramLocalParameter4fvARB _ptrc_glProgramLocalParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramStringARB)(GLenum, GLenum, GLsizei, const GLvoid *);
#define glProgramStringARB _ptrc_glProgramStringARB
#endif /*GL_ARB_fragment_program*/ 



#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureARB)(GLenum, GLenum, GLuint, GLint);
#define glFramebufferTextureARB _ptrc_glFramebufferTextureARB
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureFaceARB)(GLenum, GLenum, GLuint, GLint, GLenum);
#define glFramebufferTextureFaceARB _ptrc_glFramebufferTextureFaceARB
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerARB)(GLenum, GLenum, GLuint, GLint, GLint);
#define glFramebufferTextureLayerARB _ptrc_glFramebufferTextureLayerARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriARB)(GLuint, GLenum, GLint);
#define glProgramParameteriARB _ptrc_glProgramParameteriARB
#endif /*GL_ARB_geometry_shader4*/ 


#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectCountARB)(GLenum, GLintptr, GLintptr, GLsizei, GLsizei);
#define glMultiDrawArraysIndirectCountARB _ptrc_glMultiDrawArraysIndirectCountARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectCountARB)(GLenum, GLenum, GLintptr, GLintptr, GLsizei, GLsizei);
#define glMultiDrawElementsIndirectCountARB _ptrc_glMultiDrawElementsIndirectCountARB
#endif /*GL_ARB_indirect_parameters*/ 

#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisorARB)(GLuint, GLuint);
#define glVertexAttribDivisorARB _ptrc_glVertexAttribDivisorARB
#endif /*GL_ARB_instanced_arrays*/ 

#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCurrentPaletteMatrixARB)(GLint);
#define glCurrentPaletteMatrixARB _ptrc_glCurrentPaletteMatrixARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexPointerARB)(GLint, GLenum, GLsizei, const GLvoid *);
#define glMatrixIndexPointerARB _ptrc_glMatrixIndexPointerARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexubvARB)(GLint, const GLubyte *);
#define glMatrixIndexubvARB _ptrc_glMatrixIndexubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexuivARB)(GLint, const GLuint *);
#define glMatrixIndexuivARB _ptrc_glMatrixIndexuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexusvARB)(GLint, const GLushort *);
#define glMatrixIndexusvARB _ptrc_glMatrixIndexusvARB
#endif /*GL_ARB_matrix_palette*/ 

#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverageARB)(GLfloat, GLboolean);
#define glSampleCoverageARB _ptrc_glSampleCoverageARB
#endif /*GL_ARB_multisample*/ 

#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveTextureARB)(GLenum);
#define glActiveTextureARB _ptrc_glActiveTextureARB
extern void (CODEGEN_FUNCPTR *_ptrc_glClientActiveTextureARB)(GLenum);
#define glClientActiveTextureARB _ptrc_glClientActiveTextureARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dARB)(GLenum, GLdouble);
#define glMultiTexCoord1dARB _ptrc_glMultiTexCoord1dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dvARB)(GLenum, const GLdouble *);
#define glMultiTexCoord1dvARB _ptrc_glMultiTexCoord1dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fARB)(GLenum, GLfloat);
#define glMultiTexCoord1fARB _ptrc_glMultiTexCoord1fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fvARB)(GLenum, const GLfloat *);
#define glMultiTexCoord1fvARB _ptrc_glMultiTexCoord1fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1iARB)(GLenum, GLint);
#define glMultiTexCoord1iARB _ptrc_glMultiTexCoord1iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1ivARB)(GLenum, const GLint *);
#define glMultiTexCoord1ivARB _ptrc_glMultiTexCoord1ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1sARB)(GLenum, GLshort);
#define glMultiTexCoord1sARB _ptrc_glMultiTexCoord1sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1svARB)(GLenum, const GLshort *);
#define glMultiTexCoord1svARB _ptrc_glMultiTexCoord1svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dARB)(GLenum, GLdouble, GLdouble);
#define glMultiTexCoord2dARB _ptrc_glMultiTexCoord2dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dvARB)(GLenum, const GLdouble *);
#define glMultiTexCoord2dvARB _ptrc_glMultiTexCoord2dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fARB)(GLenum, GLfloat, GLfloat);
#define glMultiTexCoord2fARB _ptrc_glMultiTexCoord2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fvARB)(GLenum, const GLfloat *);
#define glMultiTexCoord2fvARB _ptrc_glMultiTexCoord2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2iARB)(GLenum, GLint, GLint);
#define glMultiTexCoord2iARB _ptrc_glMultiTexCoord2iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2ivARB)(GLenum, const GLint *);
#define glMultiTexCoord2ivARB _ptrc_glMultiTexCoord2ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2sARB)(GLenum, GLshort, GLshort);
#define glMultiTexCoord2sARB _ptrc_glMultiTexCoord2sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2svARB)(GLenum, const GLshort *);
#define glMultiTexCoord2svARB _ptrc_glMultiTexCoord2svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dARB)(GLenum, GLdouble, GLdouble, GLdouble);
#define glMultiTexCoord3dARB _ptrc_glMultiTexCoord3dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dvARB)(GLenum, const GLdouble *);
#define glMultiTexCoord3dvARB _ptrc_glMultiTexCoord3dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fARB)(GLenum, GLfloat, GLfloat, GLfloat);
#define glMultiTexCoord3fARB _ptrc_glMultiTexCoord3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fvARB)(GLenum, const GLfloat *);
#define glMultiTexCoord3fvARB _ptrc_glMultiTexCoord3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3iARB)(GLenum, GLint, GLint, GLint);
#define glMultiTexCoord3iARB _ptrc_glMultiTexCoord3iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3ivARB)(GLenum, const GLint *);
#define glMultiTexCoord3ivARB _ptrc_glMultiTexCoord3ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3sARB)(GLenum, GLshort, GLshort, GLshort);
#define glMultiTexCoord3sARB _ptrc_glMultiTexCoord3sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3svARB)(GLenum, const GLshort *);
#define glMultiTexCoord3svARB _ptrc_glMultiTexCoord3svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dARB)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
#define glMultiTexCoord4dARB _ptrc_glMultiTexCoord4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dvARB)(GLenum, const GLdouble *);
#define glMultiTexCoord4dvARB _ptrc_glMultiTexCoord4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fARB)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
#define glMultiTexCoord4fARB _ptrc_glMultiTexCoord4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fvARB)(GLenum, const GLfloat *);
#define glMultiTexCoord4fvARB _ptrc_glMultiTexCoord4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4iARB)(GLenum, GLint, GLint, GLint, GLint);
#define glMultiTexCoord4iARB _ptrc_glMultiTexCoord4iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4ivARB)(GLenum, const GLint *);
#define glMultiTexCoord4ivARB _ptrc_glMultiTexCoord4ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4sARB)(GLenum, GLshort, GLshort, GLshort, GLshort);
#define glMultiTexCoord4sARB _ptrc_glMultiTexCoord4sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4svARB)(GLenum, const GLshort *);
#define glMultiTexCoord4svARB _ptrc_glMultiTexCoord4svARB
#endif /*GL_ARB_multitexture*/ 

#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryARB)(GLenum, GLuint);
#define glBeginQueryARB _ptrc_glBeginQueryARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueriesARB)(GLsizei, const GLuint *);
#define glDeleteQueriesARB _ptrc_glDeleteQueriesARB
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQueryARB)(GLenum);
#define glEndQueryARB _ptrc_glEndQueryARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenQueriesARB)(GLsizei, GLuint *);
#define glGenQueriesARB _ptrc_glGenQueriesARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectivARB)(GLuint, GLenum, GLint *);
#define glGetQueryObjectivARB _ptrc_glGetQueryObjectivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuivARB)(GLuint, GLenum, GLuint *);
#define glGetQueryObjectuivARB _ptrc_glGetQueryObjectuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryivARB)(GLenum, GLenum, GLint *);
#define glGetQueryivARB _ptrc_glGetQueryivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQueryARB)(GLuint);
#define glIsQueryARB _ptrc_glIsQueryARB
#endif /*GL_ARB_occlusion_query*/ 


#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfARB)(GLenum, GLfloat);
#define glPointParameterfARB _ptrc_glPointParameterfARB
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvARB)(GLenum, const GLfloat *);
#define glPointParameterfvARB _ptrc_glPointParameterfvARB
#endif /*GL_ARB_point_parameters*/ 



#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glGetGraphicsResetStatusARB)();
#define glGetGraphicsResetStatusARB _ptrc_glGetGraphicsResetStatusARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnColorTableARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *);
#define glGetnColorTableARB _ptrc_glGetnColorTableARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnCompressedTexImageARB)(GLenum, GLint, GLsizei, GLvoid *);
#define glGetnCompressedTexImageARB _ptrc_glGetnCompressedTexImageARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnConvolutionFilterARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *);
#define glGetnConvolutionFilterARB _ptrc_glGetnConvolutionFilterARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnHistogramARB)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *);
#define glGetnHistogramARB _ptrc_glGetnHistogramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMapdvARB)(GLenum, GLenum, GLsizei, GLdouble *);
#define glGetnMapdvARB _ptrc_glGetnMapdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMapfvARB)(GLenum, GLenum, GLsizei, GLfloat *);
#define glGetnMapfvARB _ptrc_glGetnMapfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMapivARB)(GLenum, GLenum, GLsizei, GLint *);
#define glGetnMapivARB _ptrc_glGetnMapivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnMinmaxARB)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *);
#define glGetnMinmaxARB _ptrc_glGetnMinmaxARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapfvARB)(GLenum, GLsizei, GLfloat *);
#define glGetnPixelMapfvARB _ptrc_glGetnPixelMapfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapuivARB)(GLenum, GLsizei, GLuint *);
#define glGetnPixelMapuivARB _ptrc_glGetnPixelMapuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapusvARB)(GLenum, GLsizei, GLushort *);
#define glGetnPixelMapusvARB _ptrc_glGetnPixelMapusvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnPolygonStippleARB)(GLsizei, GLubyte *);
#define glGetnPolygonStippleARB _ptrc_glGetnPolygonStippleARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnSeparableFilterARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *, GLsizei, GLvoid *, GLvoid *);
#define glGetnSeparableFilterARB _ptrc_glGetnSeparableFilterARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnTexImageARB)(GLenum, GLint, GLenum, GLenum, GLsizei, GLvoid *);
#define glGetnTexImageARB _ptrc_glGetnTexImageARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformdvARB)(GLuint, GLint, GLsizei, GLdouble *);
#define glGetnUniformdvARB _ptrc_glGetnUniformdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformfvARB)(GLuint, GLint, GLsizei, GLfloat *);
#define glGetnUniformfvARB _ptrc_glGetnUniformfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformivARB)(GLuint, GLint, GLsizei, GLint *);
#define glGetnUniformivARB _ptrc_glGetnUniformivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformuivARB)(GLuint, GLint, GLsizei, GLuint *);
#define glGetnUniformuivARB _ptrc_glGetnUniformuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glReadnPixelsARB)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid *);
#define glReadnPixelsARB _ptrc_glReadnPixelsARB
#endif /*GL_ARB_robustness*/ 


#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShadingARB)(GLfloat);
#define glMinSampleShadingARB _ptrc_glMinSampleShadingARB
#endif /*GL_ARB_sample_shading*/ 





#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glAttachObjectARB)(GLhandleARB, GLhandleARB);
#define glAttachObjectARB _ptrc_glAttachObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderARB)(GLhandleARB);
#define glCompileShaderARB _ptrc_glCompileShaderARB
extern GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateProgramObjectARB)();
#define glCreateProgramObjectARB _ptrc_glCreateProgramObjectARB
extern GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateShaderObjectARB)(GLenum);
#define glCreateShaderObjectARB _ptrc_glCreateShaderObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteObjectARB)(GLhandleARB);
#define glDeleteObjectARB _ptrc_glDeleteObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDetachObjectARB)(GLhandleARB, GLhandleARB);
#define glDetachObjectARB _ptrc_glDetachObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformARB)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *);
#define glGetActiveUniformARB _ptrc_glGetActiveUniformARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedObjectsARB)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *);
#define glGetAttachedObjectsARB _ptrc_glGetAttachedObjectsARB
extern GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glGetHandleARB)(GLenum);
#define glGetHandleARB _ptrc_glGetHandleARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInfoLogARB)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *);
#define glGetInfoLogARB _ptrc_glGetInfoLogARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterfvARB)(GLhandleARB, GLenum, GLfloat *);
#define glGetObjectParameterfvARB _ptrc_glGetObjectParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterivARB)(GLhandleARB, GLenum, GLint *);
#define glGetObjectParameterivARB _ptrc_glGetObjectParameterivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSourceARB)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *);
#define glGetShaderSourceARB _ptrc_glGetShaderSourceARB
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocationARB)(GLhandleARB, const GLcharARB *);
#define glGetUniformLocationARB _ptrc_glGetUniformLocationARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfvARB)(GLhandleARB, GLint, GLfloat *);
#define glGetUniformfvARB _ptrc_glGetUniformfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformivARB)(GLhandleARB, GLint, GLint *);
#define glGetUniformivARB _ptrc_glGetUniformivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glLinkProgramARB)(GLhandleARB);
#define glLinkProgramARB _ptrc_glLinkProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderSourceARB)(GLhandleARB, GLsizei, const GLcharARB **, const GLint *);
#define glShaderSourceARB _ptrc_glShaderSourceARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1fARB)(GLint, GLfloat);
#define glUniform1fARB _ptrc_glUniform1fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1fvARB)(GLint, GLsizei, const GLfloat *);
#define glUniform1fvARB _ptrc_glUniform1fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1iARB)(GLint, GLint);
#define glUniform1iARB _ptrc_glUniform1iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ivARB)(GLint, GLsizei, const GLint *);
#define glUniform1ivARB _ptrc_glUniform1ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2fARB)(GLint, GLfloat, GLfloat);
#define glUniform2fARB _ptrc_glUniform2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2fvARB)(GLint, GLsizei, const GLfloat *);
#define glUniform2fvARB _ptrc_glUniform2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2iARB)(GLint, GLint, GLint);
#define glUniform2iARB _ptrc_glUniform2iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ivARB)(GLint, GLsizei, const GLint *);
#define glUniform2ivARB _ptrc_glUniform2ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3fARB)(GLint, GLfloat, GLfloat, GLfloat);
#define glUniform3fARB _ptrc_glUniform3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3fvARB)(GLint, GLsizei, const GLfloat *);
#define glUniform3fvARB _ptrc_glUniform3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3iARB)(GLint, GLint, GLint, GLint);
#define glUniform3iARB _ptrc_glUniform3iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ivARB)(GLint, GLsizei, const GLint *);
#define glUniform3ivARB _ptrc_glUniform3ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4fARB)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glUniform4fARB _ptrc_glUniform4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4fvARB)(GLint, GLsizei, const GLfloat *);
#define glUniform4fvARB _ptrc_glUniform4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4iARB)(GLint, GLint, GLint, GLint, GLint);
#define glUniform4iARB _ptrc_glUniform4iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ivARB)(GLint, GLsizei, const GLint *);
#define glUniform4ivARB _ptrc_glUniform4ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fvARB)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix2fvARB _ptrc_glUniformMatrix2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fvARB)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix3fvARB _ptrc_glUniformMatrix3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fvARB)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix4fvARB _ptrc_glUniformMatrix4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgramObjectARB)(GLhandleARB);
#define glUseProgramObjectARB _ptrc_glUseProgramObjectARB
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramARB)(GLhandleARB);
#define glValidateProgramARB _ptrc_glValidateProgramARB
#endif /*GL_ARB_shader_objects*/ 





#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderIncludeARB)(GLuint, GLsizei, const GLchar *const*, const GLint *);
#define glCompileShaderIncludeARB _ptrc_glCompileShaderIncludeARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteNamedStringARB)(GLint, const GLchar *);
#define glDeleteNamedStringARB _ptrc_glDeleteNamedStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringARB)(GLint, const GLchar *, GLsizei, GLint *, GLchar *);
#define glGetNamedStringARB _ptrc_glGetNamedStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringivARB)(GLint, const GLchar *, GLenum, GLint *);
#define glGetNamedStringivARB _ptrc_glGetNamedStringivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedStringARB)(GLint, const GLchar *);
#define glIsNamedStringARB _ptrc_glIsNamedStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedStringARB)(GLenum, GLint, const GLchar *, GLint, const GLchar *);
#define glNamedStringARB _ptrc_glNamedStringARB
#endif /*GL_ARB_shading_language_include*/ 



#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexPageCommitmentARB)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTexPageCommitmentARB _ptrc_glTexPageCommitmentARB
#endif /*GL_ARB_sparse_texture*/ 


#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferARB)(GLenum, GLenum, GLuint);
#define glTexBufferARB _ptrc_glTexBufferARB
#endif /*GL_ARB_texture_buffer_object*/ 


#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1DARB)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTexImage1DARB _ptrc_glCompressedTexImage1DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2DARB)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTexImage2DARB _ptrc_glCompressedTexImage2DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3DARB)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTexImage3DARB _ptrc_glCompressedTexImage3DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1DARB)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTexSubImage1DARB _ptrc_glCompressedTexSubImage1DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2DARB)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTexSubImage2DARB _ptrc_glCompressedTexSubImage2DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3DARB)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTexSubImage3DARB _ptrc_glCompressedTexSubImage3DARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImageARB)(GLenum, GLint, GLvoid *);
#define glGetCompressedTexImageARB _ptrc_glGetCompressedTexImageARB
#endif /*GL_ARB_texture_compression*/ 














#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixdARB)(const GLdouble *);
#define glLoadTransposeMatrixdARB _ptrc_glLoadTransposeMatrixdARB
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixfARB)(const GLfloat *);
#define glLoadTransposeMatrixfARB _ptrc_glLoadTransposeMatrixfARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixdARB)(const GLdouble *);
#define glMultTransposeMatrixdARB _ptrc_glMultTransposeMatrixdARB
extern void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixfARB)(const GLfloat *);
#define glMultTransposeMatrixfARB _ptrc_glMultTransposeMatrixfARB
#endif /*GL_ARB_transpose_matrix*/ 

#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend 1
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexBlendARB)(GLint);
#define glVertexBlendARB _ptrc_glVertexBlendARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightPointerARB)(GLint, GLenum, GLsizei, const GLvoid *);
#define glWeightPointerARB _ptrc_glWeightPointerARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightbvARB)(GLint, const GLbyte *);
#define glWeightbvARB _ptrc_glWeightbvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightdvARB)(GLint, const GLdouble *);
#define glWeightdvARB _ptrc_glWeightdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightfvARB)(GLint, const GLfloat *);
#define glWeightfvARB _ptrc_glWeightfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightivARB)(GLint, const GLint *);
#define glWeightivARB _ptrc_glWeightivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightsvARB)(GLint, const GLshort *);
#define glWeightsvARB _ptrc_glWeightsvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightubvARB)(GLint, const GLubyte *);
#define glWeightubvARB _ptrc_glWeightubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightuivARB)(GLint, const GLuint *);
#define glWeightuivARB _ptrc_glWeightuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightusvARB)(GLint, const GLushort *);
#define glWeightusvARB _ptrc_glWeightusvARB
#endif /*GL_ARB_vertex_blend*/ 

#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferARB)(GLenum, GLuint);
#define glBindBufferARB _ptrc_glBindBufferARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferDataARB)(GLenum, GLsizeiptrARB, const GLvoid *, GLenum);
#define glBufferDataARB _ptrc_glBufferDataARB
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferSubDataARB)(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid *);
#define glBufferSubDataARB _ptrc_glBufferSubDataARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffersARB)(GLsizei, const GLuint *);
#define glDeleteBuffersARB _ptrc_glDeleteBuffersARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenBuffersARB)(GLsizei, GLuint *);
#define glGenBuffersARB _ptrc_glGenBuffersARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterivARB)(GLenum, GLenum, GLint *);
#define glGetBufferParameterivARB _ptrc_glGetBufferParameterivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointervARB)(GLenum, GLenum, GLvoid **);
#define glGetBufferPointervARB _ptrc_glGetBufferPointervARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubDataARB)(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid *);
#define glGetBufferSubDataARB _ptrc_glGetBufferSubDataARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferARB)(GLuint);
#define glIsBufferARB _ptrc_glIsBufferARB
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferARB)(GLenum, GLenum);
#define glMapBufferARB _ptrc_glMapBufferARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBufferARB)(GLenum);
#define glUnmapBufferARB _ptrc_glUnmapBufferARB
#endif /*GL_ARB_vertex_buffer_object*/ 

#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramARB)(GLenum, GLuint);
#define glBindProgramARB _ptrc_glBindProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsARB)(GLsizei, const GLuint *);
#define glDeleteProgramsARB _ptrc_glDeleteProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArrayARB)(GLuint);
#define glDisableVertexAttribArrayARB _ptrc_glDisableVertexAttribArrayARB
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArrayARB)(GLuint);
#define glEnableVertexAttribArrayARB _ptrc_glEnableVertexAttribArrayARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsARB)(GLsizei, GLuint *);
#define glGenProgramsARB _ptrc_glGenProgramsARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterdvARB)(GLenum, GLuint, GLdouble *);
#define glGetProgramEnvParameterdvARB _ptrc_glGetProgramEnvParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterfvARB)(GLenum, GLuint, GLfloat *);
#define glGetProgramEnvParameterfvARB _ptrc_glGetProgramEnvParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterdvARB)(GLenum, GLuint, GLdouble *);
#define glGetProgramLocalParameterdvARB _ptrc_glGetProgramLocalParameterdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterfvARB)(GLenum, GLuint, GLfloat *);
#define glGetProgramLocalParameterfvARB _ptrc_glGetProgramLocalParameterfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringARB)(GLenum, GLenum, GLvoid *);
#define glGetProgramStringARB _ptrc_glGetProgramStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivARB)(GLenum, GLenum, GLint *);
#define glGetProgramivARB _ptrc_glGetProgramivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervARB)(GLuint, GLenum, GLvoid **);
#define glGetVertexAttribPointervARB _ptrc_glGetVertexAttribPointervARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvARB)(GLuint, GLenum, GLdouble *);
#define glGetVertexAttribdvARB _ptrc_glGetVertexAttribdvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvARB)(GLuint, GLenum, GLfloat *);
#define glGetVertexAttribfvARB _ptrc_glGetVertexAttribfvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivARB)(GLuint, GLenum, GLint *);
#define glGetVertexAttribivARB _ptrc_glGetVertexAttribivARB
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramARB)(GLuint);
#define glIsProgramARB _ptrc_glIsProgramARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramEnvParameter4dARB _ptrc_glProgramEnvParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dvARB)(GLenum, GLuint, const GLdouble *);
#define glProgramEnvParameter4dvARB _ptrc_glProgramEnvParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramEnvParameter4fARB _ptrc_glProgramEnvParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fvARB)(GLenum, GLuint, const GLfloat *);
#define glProgramEnvParameter4fvARB _ptrc_glProgramEnvParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramLocalParameter4dARB _ptrc_glProgramLocalParameter4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dvARB)(GLenum, GLuint, const GLdouble *);
#define glProgramLocalParameter4dvARB _ptrc_glProgramLocalParameter4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramLocalParameter4fARB _ptrc_glProgramLocalParameter4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fvARB)(GLenum, GLuint, const GLfloat *);
#define glProgramLocalParameter4fvARB _ptrc_glProgramLocalParameter4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramStringARB)(GLenum, GLenum, GLsizei, const GLvoid *);
#define glProgramStringARB _ptrc_glProgramStringARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dARB)(GLuint, GLdouble);
#define glVertexAttrib1dARB _ptrc_glVertexAttrib1dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvARB)(GLuint, const GLdouble *);
#define glVertexAttrib1dvARB _ptrc_glVertexAttrib1dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fARB)(GLuint, GLfloat);
#define glVertexAttrib1fARB _ptrc_glVertexAttrib1fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvARB)(GLuint, const GLfloat *);
#define glVertexAttrib1fvARB _ptrc_glVertexAttrib1fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sARB)(GLuint, GLshort);
#define glVertexAttrib1sARB _ptrc_glVertexAttrib1sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svARB)(GLuint, const GLshort *);
#define glVertexAttrib1svARB _ptrc_glVertexAttrib1svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dARB)(GLuint, GLdouble, GLdouble);
#define glVertexAttrib2dARB _ptrc_glVertexAttrib2dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvARB)(GLuint, const GLdouble *);
#define glVertexAttrib2dvARB _ptrc_glVertexAttrib2dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fARB)(GLuint, GLfloat, GLfloat);
#define glVertexAttrib2fARB _ptrc_glVertexAttrib2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvARB)(GLuint, const GLfloat *);
#define glVertexAttrib2fvARB _ptrc_glVertexAttrib2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sARB)(GLuint, GLshort, GLshort);
#define glVertexAttrib2sARB _ptrc_glVertexAttrib2sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svARB)(GLuint, const GLshort *);
#define glVertexAttrib2svARB _ptrc_glVertexAttrib2svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dARB)(GLuint, GLdouble, GLdouble, GLdouble);
#define glVertexAttrib3dARB _ptrc_glVertexAttrib3dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvARB)(GLuint, const GLdouble *);
#define glVertexAttrib3dvARB _ptrc_glVertexAttrib3dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fARB)(GLuint, GLfloat, GLfloat, GLfloat);
#define glVertexAttrib3fARB _ptrc_glVertexAttrib3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvARB)(GLuint, const GLfloat *);
#define glVertexAttrib3fvARB _ptrc_glVertexAttrib3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sARB)(GLuint, GLshort, GLshort, GLshort);
#define glVertexAttrib3sARB _ptrc_glVertexAttrib3sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svARB)(GLuint, const GLshort *);
#define glVertexAttrib3svARB _ptrc_glVertexAttrib3svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NbvARB)(GLuint, const GLbyte *);
#define glVertexAttrib4NbvARB _ptrc_glVertexAttrib4NbvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NivARB)(GLuint, const GLint *);
#define glVertexAttrib4NivARB _ptrc_glVertexAttrib4NivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NsvARB)(GLuint, const GLshort *);
#define glVertexAttrib4NsvARB _ptrc_glVertexAttrib4NsvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubARB)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
#define glVertexAttrib4NubARB _ptrc_glVertexAttrib4NubARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubvARB)(GLuint, const GLubyte *);
#define glVertexAttrib4NubvARB _ptrc_glVertexAttrib4NubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NuivARB)(GLuint, const GLuint *);
#define glVertexAttrib4NuivARB _ptrc_glVertexAttrib4NuivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NusvARB)(GLuint, const GLushort *);
#define glVertexAttrib4NusvARB _ptrc_glVertexAttrib4NusvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bvARB)(GLuint, const GLbyte *);
#define glVertexAttrib4bvARB _ptrc_glVertexAttrib4bvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dARB)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertexAttrib4dARB _ptrc_glVertexAttrib4dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvARB)(GLuint, const GLdouble *);
#define glVertexAttrib4dvARB _ptrc_glVertexAttrib4dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fARB)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glVertexAttrib4fARB _ptrc_glVertexAttrib4fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvARB)(GLuint, const GLfloat *);
#define glVertexAttrib4fvARB _ptrc_glVertexAttrib4fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ivARB)(GLuint, const GLint *);
#define glVertexAttrib4ivARB _ptrc_glVertexAttrib4ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sARB)(GLuint, GLshort, GLshort, GLshort, GLshort);
#define glVertexAttrib4sARB _ptrc_glVertexAttrib4sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svARB)(GLuint, const GLshort *);
#define glVertexAttrib4svARB _ptrc_glVertexAttrib4svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvARB)(GLuint, const GLubyte *);
#define glVertexAttrib4ubvARB _ptrc_glVertexAttrib4ubvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uivARB)(GLuint, const GLuint *);
#define glVertexAttrib4uivARB _ptrc_glVertexAttrib4uivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usvARB)(GLuint, const GLushort *);
#define glVertexAttrib4usvARB _ptrc_glVertexAttrib4usvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerARB)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *);
#define glVertexAttribPointerARB _ptrc_glVertexAttribPointerARB
#endif /*GL_ARB_vertex_program*/ 

#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocationARB)(GLhandleARB, GLuint, const GLcharARB *);
#define glBindAttribLocationARB _ptrc_glBindAttribLocationARB
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttribARB)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *);
#define glGetActiveAttribARB _ptrc_glGetActiveAttribARB
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocationARB)(GLhandleARB, const GLcharARB *);
#define glGetAttribLocationARB _ptrc_glGetAttribLocationARB
#endif /*GL_ARB_vertex_shader*/ 

#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dARB)(GLdouble, GLdouble);
#define glWindowPos2dARB _ptrc_glWindowPos2dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dvARB)(const GLdouble *);
#define glWindowPos2dvARB _ptrc_glWindowPos2dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fARB)(GLfloat, GLfloat);
#define glWindowPos2fARB _ptrc_glWindowPos2fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fvARB)(const GLfloat *);
#define glWindowPos2fvARB _ptrc_glWindowPos2fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iARB)(GLint, GLint);
#define glWindowPos2iARB _ptrc_glWindowPos2iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2ivARB)(const GLint *);
#define glWindowPos2ivARB _ptrc_glWindowPos2ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sARB)(GLshort, GLshort);
#define glWindowPos2sARB _ptrc_glWindowPos2sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2svARB)(const GLshort *);
#define glWindowPos2svARB _ptrc_glWindowPos2svARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dARB)(GLdouble, GLdouble, GLdouble);
#define glWindowPos3dARB _ptrc_glWindowPos3dARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dvARB)(const GLdouble *);
#define glWindowPos3dvARB _ptrc_glWindowPos3dvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fARB)(GLfloat, GLfloat, GLfloat);
#define glWindowPos3fARB _ptrc_glWindowPos3fARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fvARB)(const GLfloat *);
#define glWindowPos3fvARB _ptrc_glWindowPos3fvARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iARB)(GLint, GLint, GLint);
#define glWindowPos3iARB _ptrc_glWindowPos3iARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3ivARB)(const GLint *);
#define glWindowPos3ivARB _ptrc_glWindowPos3ivARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sARB)(GLshort, GLshort, GLshort);
#define glWindowPos3sARB _ptrc_glWindowPos3sARB
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3svARB)(const GLshort *);
#define glWindowPos3svARB _ptrc_glWindowPos3svARB
#endif /*GL_ARB_window_pos*/ 

#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersATI)(GLsizei, const GLenum *);
#define glDrawBuffersATI _ptrc_glDrawBuffersATI
#endif /*GL_ATI_draw_buffers*/ 

#ifndef GL_ATI_element_array
#define GL_ATI_element_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementArrayATI)(GLenum, GLsizei);
#define glDrawElementArrayATI _ptrc_glDrawElementArrayATI
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementArrayATI)(GLenum, GLuint, GLuint, GLsizei);
#define glDrawRangeElementArrayATI _ptrc_glDrawRangeElementArrayATI
extern void (CODEGEN_FUNCPTR *_ptrc_glElementPointerATI)(GLenum, const GLvoid *);
#define glElementPointerATI _ptrc_glElementPointerATI
#endif /*GL_ATI_element_array*/ 

#ifndef GL_ATI_envmap_bumpmap
#define GL_ATI_envmap_bumpmap 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexBumpParameterfvATI)(GLenum, GLfloat *);
#define glGetTexBumpParameterfvATI _ptrc_glGetTexBumpParameterfvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexBumpParameterivATI)(GLenum, GLint *);
#define glGetTexBumpParameterivATI _ptrc_glGetTexBumpParameterivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBumpParameterfvATI)(GLenum, const GLfloat *);
#define glTexBumpParameterfvATI _ptrc_glTexBumpParameterfvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBumpParameterivATI)(GLenum, const GLint *);
#define glTexBumpParameterivATI _ptrc_glTexBumpParameterivATI
#endif /*GL_ATI_envmap_bumpmap*/ 

#ifndef GL_ATI_fragment_shader
#define GL_ATI_fragment_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glAlphaFragmentOp1ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glAlphaFragmentOp1ATI _ptrc_glAlphaFragmentOp1ATI
extern void (CODEGEN_FUNCPTR *_ptrc_glAlphaFragmentOp2ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glAlphaFragmentOp2ATI _ptrc_glAlphaFragmentOp2ATI
extern void (CODEGEN_FUNCPTR *_ptrc_glAlphaFragmentOp3ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glAlphaFragmentOp3ATI _ptrc_glAlphaFragmentOp3ATI
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginFragmentShaderATI)();
#define glBeginFragmentShaderATI _ptrc_glBeginFragmentShaderATI
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragmentShaderATI)(GLuint);
#define glBindFragmentShaderATI _ptrc_glBindFragmentShaderATI
extern void (CODEGEN_FUNCPTR *_ptrc_glColorFragmentOp1ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glColorFragmentOp1ATI _ptrc_glColorFragmentOp1ATI
extern void (CODEGEN_FUNCPTR *_ptrc_glColorFragmentOp2ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glColorFragmentOp2ATI _ptrc_glColorFragmentOp2ATI
extern void (CODEGEN_FUNCPTR *_ptrc_glColorFragmentOp3ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glColorFragmentOp3ATI _ptrc_glColorFragmentOp3ATI
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFragmentShaderATI)(GLuint);
#define glDeleteFragmentShaderATI _ptrc_glDeleteFragmentShaderATI
extern void (CODEGEN_FUNCPTR *_ptrc_glEndFragmentShaderATI)();
#define glEndFragmentShaderATI _ptrc_glEndFragmentShaderATI
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGenFragmentShadersATI)(GLuint);
#define glGenFragmentShadersATI _ptrc_glGenFragmentShadersATI
extern void (CODEGEN_FUNCPTR *_ptrc_glPassTexCoordATI)(GLuint, GLuint, GLenum);
#define glPassTexCoordATI _ptrc_glPassTexCoordATI
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMapATI)(GLuint, GLuint, GLenum);
#define glSampleMapATI _ptrc_glSampleMapATI
extern void (CODEGEN_FUNCPTR *_ptrc_glSetFragmentShaderConstantATI)(GLuint, const GLfloat *);
#define glSetFragmentShaderConstantATI _ptrc_glSetFragmentShaderConstantATI
#endif /*GL_ATI_fragment_shader*/ 

#ifndef GL_ATI_map_object_buffer
#define GL_ATI_map_object_buffer 1
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapObjectBufferATI)(GLuint);
#define glMapObjectBufferATI _ptrc_glMapObjectBufferATI
extern void (CODEGEN_FUNCPTR *_ptrc_glUnmapObjectBufferATI)(GLuint);
#define glUnmapObjectBufferATI _ptrc_glUnmapObjectBufferATI
#endif /*GL_ATI_map_object_buffer*/ 



#ifndef GL_ATI_pn_triangles
#define GL_ATI_pn_triangles 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPNTrianglesfATI)(GLenum, GLfloat);
#define glPNTrianglesfATI _ptrc_glPNTrianglesfATI
extern void (CODEGEN_FUNCPTR *_ptrc_glPNTrianglesiATI)(GLenum, GLint);
#define glPNTrianglesiATI _ptrc_glPNTrianglesiATI
#endif /*GL_ATI_pn_triangles*/ 

#ifndef GL_ATI_separate_stencil
#define GL_ATI_separate_stencil 1
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFuncSeparateATI)(GLenum, GLenum, GLint, GLuint);
#define glStencilFuncSeparateATI _ptrc_glStencilFuncSeparateATI
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilOpSeparateATI)(GLenum, GLenum, GLenum, GLenum);
#define glStencilOpSeparateATI _ptrc_glStencilOpSeparateATI
#endif /*GL_ATI_separate_stencil*/ 





#ifndef GL_ATI_vertex_array_object
#define GL_ATI_vertex_array_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glArrayObjectATI)(GLenum, GLint, GLenum, GLsizei, GLuint, GLuint);
#define glArrayObjectATI _ptrc_glArrayObjectATI
extern void (CODEGEN_FUNCPTR *_ptrc_glFreeObjectBufferATI)(GLuint);
#define glFreeObjectBufferATI _ptrc_glFreeObjectBufferATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetArrayObjectfvATI)(GLenum, GLenum, GLfloat *);
#define glGetArrayObjectfvATI _ptrc_glGetArrayObjectfvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetArrayObjectivATI)(GLenum, GLenum, GLint *);
#define glGetArrayObjectivATI _ptrc_glGetArrayObjectivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectBufferfvATI)(GLuint, GLenum, GLfloat *);
#define glGetObjectBufferfvATI _ptrc_glGetObjectBufferfvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectBufferivATI)(GLuint, GLenum, GLint *);
#define glGetObjectBufferivATI _ptrc_glGetObjectBufferivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVariantArrayObjectfvATI)(GLuint, GLenum, GLfloat *);
#define glGetVariantArrayObjectfvATI _ptrc_glGetVariantArrayObjectfvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVariantArrayObjectivATI)(GLuint, GLenum, GLint *);
#define glGetVariantArrayObjectivATI _ptrc_glGetVariantArrayObjectivATI
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsObjectBufferATI)(GLuint);
#define glIsObjectBufferATI _ptrc_glIsObjectBufferATI
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glNewObjectBufferATI)(GLsizei, const GLvoid *, GLenum);
#define glNewObjectBufferATI _ptrc_glNewObjectBufferATI
extern void (CODEGEN_FUNCPTR *_ptrc_glUpdateObjectBufferATI)(GLuint, GLuint, GLsizei, const GLvoid *, GLenum);
#define glUpdateObjectBufferATI _ptrc_glUpdateObjectBufferATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantArrayObjectATI)(GLuint, GLenum, GLsizei, GLuint, GLuint);
#define glVariantArrayObjectATI _ptrc_glVariantArrayObjectATI
#endif /*GL_ATI_vertex_array_object*/ 

#ifndef GL_ATI_vertex_attrib_array_object
#define GL_ATI_vertex_attrib_array_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribArrayObjectfvATI)(GLuint, GLenum, GLfloat *);
#define glGetVertexAttribArrayObjectfvATI _ptrc_glGetVertexAttribArrayObjectfvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribArrayObjectivATI)(GLuint, GLenum, GLint *);
#define glGetVertexAttribArrayObjectivATI _ptrc_glGetVertexAttribArrayObjectivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribArrayObjectATI)(GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint);
#define glVertexAttribArrayObjectATI _ptrc_glVertexAttribArrayObjectATI
#endif /*GL_ATI_vertex_attrib_array_object*/ 

#ifndef GL_ATI_vertex_streams
#define GL_ATI_vertex_streams 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClientActiveVertexStreamATI)(GLenum);
#define glClientActiveVertexStreamATI _ptrc_glClientActiveVertexStreamATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3bATI)(GLenum, GLbyte, GLbyte, GLbyte);
#define glNormalStream3bATI _ptrc_glNormalStream3bATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3bvATI)(GLenum, const GLbyte *);
#define glNormalStream3bvATI _ptrc_glNormalStream3bvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3dATI)(GLenum, GLdouble, GLdouble, GLdouble);
#define glNormalStream3dATI _ptrc_glNormalStream3dATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3dvATI)(GLenum, const GLdouble *);
#define glNormalStream3dvATI _ptrc_glNormalStream3dvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3fATI)(GLenum, GLfloat, GLfloat, GLfloat);
#define glNormalStream3fATI _ptrc_glNormalStream3fATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3fvATI)(GLenum, const GLfloat *);
#define glNormalStream3fvATI _ptrc_glNormalStream3fvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3iATI)(GLenum, GLint, GLint, GLint);
#define glNormalStream3iATI _ptrc_glNormalStream3iATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3ivATI)(GLenum, const GLint *);
#define glNormalStream3ivATI _ptrc_glNormalStream3ivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3sATI)(GLenum, GLshort, GLshort, GLshort);
#define glNormalStream3sATI _ptrc_glNormalStream3sATI
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3svATI)(GLenum, const GLshort *);
#define glNormalStream3svATI _ptrc_glNormalStream3svATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexBlendEnvfATI)(GLenum, GLfloat);
#define glVertexBlendEnvfATI _ptrc_glVertexBlendEnvfATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexBlendEnviATI)(GLenum, GLint);
#define glVertexBlendEnviATI _ptrc_glVertexBlendEnviATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1dATI)(GLenum, GLdouble);
#define glVertexStream1dATI _ptrc_glVertexStream1dATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1dvATI)(GLenum, const GLdouble *);
#define glVertexStream1dvATI _ptrc_glVertexStream1dvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1fATI)(GLenum, GLfloat);
#define glVertexStream1fATI _ptrc_glVertexStream1fATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1fvATI)(GLenum, const GLfloat *);
#define glVertexStream1fvATI _ptrc_glVertexStream1fvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1iATI)(GLenum, GLint);
#define glVertexStream1iATI _ptrc_glVertexStream1iATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1ivATI)(GLenum, const GLint *);
#define glVertexStream1ivATI _ptrc_glVertexStream1ivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1sATI)(GLenum, GLshort);
#define glVertexStream1sATI _ptrc_glVertexStream1sATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1svATI)(GLenum, const GLshort *);
#define glVertexStream1svATI _ptrc_glVertexStream1svATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2dATI)(GLenum, GLdouble, GLdouble);
#define glVertexStream2dATI _ptrc_glVertexStream2dATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2dvATI)(GLenum, const GLdouble *);
#define glVertexStream2dvATI _ptrc_glVertexStream2dvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2fATI)(GLenum, GLfloat, GLfloat);
#define glVertexStream2fATI _ptrc_glVertexStream2fATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2fvATI)(GLenum, const GLfloat *);
#define glVertexStream2fvATI _ptrc_glVertexStream2fvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2iATI)(GLenum, GLint, GLint);
#define glVertexStream2iATI _ptrc_glVertexStream2iATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2ivATI)(GLenum, const GLint *);
#define glVertexStream2ivATI _ptrc_glVertexStream2ivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2sATI)(GLenum, GLshort, GLshort);
#define glVertexStream2sATI _ptrc_glVertexStream2sATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2svATI)(GLenum, const GLshort *);
#define glVertexStream2svATI _ptrc_glVertexStream2svATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3dATI)(GLenum, GLdouble, GLdouble, GLdouble);
#define glVertexStream3dATI _ptrc_glVertexStream3dATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3dvATI)(GLenum, const GLdouble *);
#define glVertexStream3dvATI _ptrc_glVertexStream3dvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3fATI)(GLenum, GLfloat, GLfloat, GLfloat);
#define glVertexStream3fATI _ptrc_glVertexStream3fATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3fvATI)(GLenum, const GLfloat *);
#define glVertexStream3fvATI _ptrc_glVertexStream3fvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3iATI)(GLenum, GLint, GLint, GLint);
#define glVertexStream3iATI _ptrc_glVertexStream3iATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3ivATI)(GLenum, const GLint *);
#define glVertexStream3ivATI _ptrc_glVertexStream3ivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3sATI)(GLenum, GLshort, GLshort, GLshort);
#define glVertexStream3sATI _ptrc_glVertexStream3sATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3svATI)(GLenum, const GLshort *);
#define glVertexStream3svATI _ptrc_glVertexStream3svATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4dATI)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertexStream4dATI _ptrc_glVertexStream4dATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4dvATI)(GLenum, const GLdouble *);
#define glVertexStream4dvATI _ptrc_glVertexStream4dvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4fATI)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
#define glVertexStream4fATI _ptrc_glVertexStream4fATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4fvATI)(GLenum, const GLfloat *);
#define glVertexStream4fvATI _ptrc_glVertexStream4fvATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4iATI)(GLenum, GLint, GLint, GLint, GLint);
#define glVertexStream4iATI _ptrc_glVertexStream4iATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4ivATI)(GLenum, const GLint *);
#define glVertexStream4ivATI _ptrc_glVertexStream4ivATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4sATI)(GLenum, GLshort, GLshort, GLshort, GLshort);
#define glVertexStream4sATI _ptrc_glVertexStream4sATI
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4svATI)(GLenum, const GLshort *);
#define glVertexStream4svATI _ptrc_glVertexStream4svATI
#endif /*GL_ATI_vertex_streams*/ 




#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBufferSizeEXT)(GLuint, GLint);
#define glGetUniformBufferSizeEXT _ptrc_glGetUniformBufferSizeEXT
extern GLintptr (CODEGEN_FUNCPTR *_ptrc_glGetUniformOffsetEXT)(GLuint, GLint);
#define glGetUniformOffsetEXT _ptrc_glGetUniformOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformBufferEXT)(GLuint, GLint, GLuint);
#define glUniformBufferEXT _ptrc_glUniformBufferEXT
#endif /*GL_EXT_bindable_uniform*/ 

#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendColorEXT)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glBlendColorEXT _ptrc_glBlendColorEXT
#endif /*GL_EXT_blend_color*/ 

#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateEXT)(GLenum, GLenum);
#define glBlendEquationSeparateEXT _ptrc_glBlendEquationSeparateEXT
#endif /*GL_EXT_blend_equation_separate*/ 

#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateEXT)(GLenum, GLenum, GLenum, GLenum);
#define glBlendFuncSeparateEXT _ptrc_glBlendFuncSeparateEXT
#endif /*GL_EXT_blend_func_separate*/ 


#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationEXT)(GLenum);
#define glBlendEquationEXT _ptrc_glBlendEquationEXT
#endif /*GL_EXT_blend_minmax*/ 




#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorSubTableEXT)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glColorSubTableEXT _ptrc_glColorSubTableEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyColorSubTableEXT)(GLenum, GLsizei, GLint, GLint, GLsizei);
#define glCopyColorSubTableEXT _ptrc_glCopyColorSubTableEXT
#endif /*GL_EXT_color_subtable*/ 

#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glLockArraysEXT)(GLint, GLsizei);
#define glLockArraysEXT _ptrc_glLockArraysEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUnlockArraysEXT)();
#define glUnlockArraysEXT _ptrc_glUnlockArraysEXT
#endif /*GL_EXT_compiled_vertex_array*/ 

#ifndef GL_EXT_convolution
#define GL_EXT_convolution 1
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter1DEXT)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
#define glConvolutionFilter1DEXT _ptrc_glConvolutionFilter1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter2DEXT)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glConvolutionFilter2DEXT _ptrc_glConvolutionFilter2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfEXT)(GLenum, GLenum, GLfloat);
#define glConvolutionParameterfEXT _ptrc_glConvolutionParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfvEXT)(GLenum, GLenum, const GLfloat *);
#define glConvolutionParameterfvEXT _ptrc_glConvolutionParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteriEXT)(GLenum, GLenum, GLint);
#define glConvolutionParameteriEXT _ptrc_glConvolutionParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterivEXT)(GLenum, GLenum, const GLint *);
#define glConvolutionParameterivEXT _ptrc_glConvolutionParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei);
#define glCopyConvolutionFilter1DEXT _ptrc_glCopyConvolutionFilter1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter2DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei);
#define glCopyConvolutionFilter2DEXT _ptrc_glCopyConvolutionFilter2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionFilterEXT)(GLenum, GLenum, GLenum, GLvoid *);
#define glGetConvolutionFilterEXT _ptrc_glGetConvolutionFilterEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterfvEXT)(GLenum, GLenum, GLfloat *);
#define glGetConvolutionParameterfvEXT _ptrc_glGetConvolutionParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterivEXT)(GLenum, GLenum, GLint *);
#define glGetConvolutionParameterivEXT _ptrc_glGetConvolutionParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSeparableFilterEXT)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *);
#define glGetSeparableFilterEXT _ptrc_glGetSeparableFilterEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSeparableFilter2DEXT)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *);
#define glSeparableFilter2DEXT _ptrc_glSeparableFilter2DEXT
#endif /*GL_EXT_convolution*/ 

#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3bEXT)(GLbyte, GLbyte, GLbyte);
#define glBinormal3bEXT _ptrc_glBinormal3bEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3bvEXT)(const GLbyte *);
#define glBinormal3bvEXT _ptrc_glBinormal3bvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3dEXT)(GLdouble, GLdouble, GLdouble);
#define glBinormal3dEXT _ptrc_glBinormal3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3dvEXT)(const GLdouble *);
#define glBinormal3dvEXT _ptrc_glBinormal3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3fEXT)(GLfloat, GLfloat, GLfloat);
#define glBinormal3fEXT _ptrc_glBinormal3fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3fvEXT)(const GLfloat *);
#define glBinormal3fvEXT _ptrc_glBinormal3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3iEXT)(GLint, GLint, GLint);
#define glBinormal3iEXT _ptrc_glBinormal3iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3ivEXT)(const GLint *);
#define glBinormal3ivEXT _ptrc_glBinormal3ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3sEXT)(GLshort, GLshort, GLshort);
#define glBinormal3sEXT _ptrc_glBinormal3sEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormal3svEXT)(const GLshort *);
#define glBinormal3svEXT _ptrc_glBinormal3svEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBinormalPointerEXT)(GLenum, GLsizei, const GLvoid *);
#define glBinormalPointerEXT _ptrc_glBinormalPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3bEXT)(GLbyte, GLbyte, GLbyte);
#define glTangent3bEXT _ptrc_glTangent3bEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3bvEXT)(const GLbyte *);
#define glTangent3bvEXT _ptrc_glTangent3bvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3dEXT)(GLdouble, GLdouble, GLdouble);
#define glTangent3dEXT _ptrc_glTangent3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3dvEXT)(const GLdouble *);
#define glTangent3dvEXT _ptrc_glTangent3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3fEXT)(GLfloat, GLfloat, GLfloat);
#define glTangent3fEXT _ptrc_glTangent3fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3fvEXT)(const GLfloat *);
#define glTangent3fvEXT _ptrc_glTangent3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3iEXT)(GLint, GLint, GLint);
#define glTangent3iEXT _ptrc_glTangent3iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3ivEXT)(const GLint *);
#define glTangent3ivEXT _ptrc_glTangent3ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3sEXT)(GLshort, GLshort, GLshort);
#define glTangent3sEXT _ptrc_glTangent3sEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangent3svEXT)(const GLshort *);
#define glTangent3svEXT _ptrc_glTangent3svEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTangentPointerEXT)(GLenum, GLsizei, const GLvoid *);
#define glTangentPointerEXT _ptrc_glTangentPointerEXT
#endif /*GL_EXT_coordinate_frame*/ 

#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage1DEXT)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
#define glCopyTexImage1DEXT _ptrc_glCopyTexImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage2DEXT)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
#define glCopyTexImage2DEXT _ptrc_glCopyTexImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage1DEXT)(GLenum, GLint, GLint, GLint, GLint, GLsizei);
#define glCopyTexSubImage1DEXT _ptrc_glCopyTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage2DEXT)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyTexSubImage2DEXT _ptrc_glCopyTexSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage3DEXT)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyTexSubImage3DEXT _ptrc_glCopyTexSubImage3DEXT
#endif /*GL_EXT_copy_texture*/ 

#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCullParameterdvEXT)(GLenum, GLdouble *);
#define glCullParameterdvEXT _ptrc_glCullParameterdvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCullParameterfvEXT)(GLenum, GLfloat *);
#define glCullParameterfvEXT _ptrc_glCullParameterfvEXT
#endif /*GL_EXT_cull_vertex*/ 

#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsEXT)(GLclampd, GLclampd);
#define glDepthBoundsEXT _ptrc_glDepthBoundsEXT
#endif /*GL_EXT_depth_bounds_test*/ 

#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindMultiTextureEXT)(GLenum, GLenum, GLuint);
#define glBindMultiTextureEXT _ptrc_glBindMultiTextureEXT
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckNamedFramebufferStatusEXT)(GLuint, GLenum);
#define glCheckNamedFramebufferStatusEXT _ptrc_glCheckNamedFramebufferStatusEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferDataEXT)(GLuint, GLenum, GLenum, GLenum, const void *);
#define glClearNamedBufferDataEXT _ptrc_glClearNamedBufferDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferSubDataEXT)(GLuint, GLenum, GLenum, GLenum, GLsizeiptr, GLsizeiptr, const void *);
#define glClearNamedBufferSubDataEXT _ptrc_glClearNamedBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClientAttribDefaultEXT)(GLbitfield);
#define glClientAttribDefaultEXT _ptrc_glClientAttribDefaultEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage1DEXT)(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedMultiTexImage1DEXT _ptrc_glCompressedMultiTexImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage2DEXT)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedMultiTexImage2DEXT _ptrc_glCompressedMultiTexImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage3DEXT)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedMultiTexImage3DEXT _ptrc_glCompressedMultiTexImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedMultiTexSubImage1DEXT _ptrc_glCompressedMultiTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage2DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedMultiTexSubImage2DEXT _ptrc_glCompressedMultiTexSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage3DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedMultiTexSubImage3DEXT _ptrc_glCompressedMultiTexSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage1DEXT)(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTextureImage1DEXT _ptrc_glCompressedTextureImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage2DEXT)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTextureImage2DEXT _ptrc_glCompressedTextureImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage3DEXT)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTextureImage3DEXT _ptrc_glCompressedTextureImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage1DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTextureSubImage1DEXT _ptrc_glCompressedTextureSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage2DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTextureSubImage2DEXT _ptrc_glCompressedTextureSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage3DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTextureSubImage3DEXT _ptrc_glCompressedTextureSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage1DEXT)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
#define glCopyMultiTexImage1DEXT _ptrc_glCopyMultiTexImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage2DEXT)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
#define glCopyMultiTexImage2DEXT _ptrc_glCopyMultiTexImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage1DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei);
#define glCopyMultiTexSubImage1DEXT _ptrc_glCopyMultiTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage2DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyMultiTexSubImage2DEXT _ptrc_glCopyMultiTexSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage3DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyMultiTexSubImage3DEXT _ptrc_glCopyMultiTexSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage1DEXT)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
#define glCopyTextureImage1DEXT _ptrc_glCopyTextureImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage2DEXT)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
#define glCopyTextureImage2DEXT _ptrc_glCopyTextureImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage1DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei);
#define glCopyTextureSubImage1DEXT _ptrc_glCopyTextureSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage2DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyTextureSubImage2DEXT _ptrc_glCopyTextureSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage3DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyTextureSubImage3DEXT _ptrc_glCopyTextureSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateIndexedEXT)(GLenum, GLuint);
#define glDisableClientStateIndexedEXT _ptrc_glDisableClientStateIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateiEXT)(GLenum, GLuint);
#define glDisableClientStateiEXT _ptrc_glDisableClientStateiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableIndexedEXT)(GLenum, GLuint);
#define glDisableIndexedEXT _ptrc_glDisableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayAttribEXT)(GLuint, GLuint);
#define glDisableVertexArrayAttribEXT _ptrc_glDisableVertexArrayAttribEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayEXT)(GLuint, GLenum);
#define glDisableVertexArrayEXT _ptrc_glDisableVertexArrayEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateIndexedEXT)(GLenum, GLuint);
#define glEnableClientStateIndexedEXT _ptrc_glEnableClientStateIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateiEXT)(GLenum, GLuint);
#define glEnableClientStateiEXT _ptrc_glEnableClientStateiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableIndexedEXT)(GLenum, GLuint);
#define glEnableIndexedEXT _ptrc_glEnableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayAttribEXT)(GLuint, GLuint);
#define glEnableVertexArrayAttribEXT _ptrc_glEnableVertexArrayAttribEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayEXT)(GLuint, GLenum);
#define glEnableVertexArrayEXT _ptrc_glEnableVertexArrayEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedNamedBufferRangeEXT)(GLuint, GLintptr, GLsizeiptr);
#define glFlushMappedNamedBufferRangeEXT _ptrc_glFlushMappedNamedBufferRangeEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBufferEXT)(GLuint, GLenum);
#define glFramebufferDrawBufferEXT _ptrc_glFramebufferDrawBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBuffersEXT)(GLuint, GLsizei, const GLenum *);
#define glFramebufferDrawBuffersEXT _ptrc_glFramebufferDrawBuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferReadBufferEXT)(GLuint, GLenum);
#define glFramebufferReadBufferEXT _ptrc_glFramebufferReadBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMultiTexMipmapEXT)(GLenum, GLenum);
#define glGenerateMultiTexMipmapEXT _ptrc_glGenerateMultiTexMipmapEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateTextureMipmapEXT)(GLuint, GLenum);
#define glGenerateTextureMipmapEXT _ptrc_glGenerateTextureMipmapEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanIndexedvEXT)(GLenum, GLuint, GLboolean *);
#define glGetBooleanIndexedvEXT _ptrc_glGetBooleanIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedMultiTexImageEXT)(GLenum, GLenum, GLint, GLvoid *);
#define glGetCompressedMultiTexImageEXT _ptrc_glGetCompressedMultiTexImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureImageEXT)(GLuint, GLenum, GLint, GLvoid *);
#define glGetCompressedTextureImageEXT _ptrc_glGetCompressedTextureImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoubleIndexedvEXT)(GLenum, GLuint, GLdouble *);
#define glGetDoubleIndexedvEXT _ptrc_glGetDoubleIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_vEXT)(GLenum, GLuint, GLdouble *);
#define glGetDoublei_vEXT _ptrc_glGetDoublei_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloatIndexedvEXT)(GLenum, GLuint, GLfloat *);
#define glGetFloatIndexedvEXT _ptrc_glGetFloatIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_vEXT)(GLenum, GLuint, GLfloat *);
#define glGetFloati_vEXT _ptrc_glGetFloati_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameterivEXT)(GLuint, GLenum, GLint *);
#define glGetFramebufferParameterivEXT _ptrc_glGetFramebufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerIndexedvEXT)(GLenum, GLuint, GLint *);
#define glGetIntegerIndexedvEXT _ptrc_glGetIntegerIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvfvEXT)(GLenum, GLenum, GLenum, GLfloat *);
#define glGetMultiTexEnvfvEXT _ptrc_glGetMultiTexEnvfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvivEXT)(GLenum, GLenum, GLenum, GLint *);
#define glGetMultiTexEnvivEXT _ptrc_glGetMultiTexEnvivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGendvEXT)(GLenum, GLenum, GLenum, GLdouble *);
#define glGetMultiTexGendvEXT _ptrc_glGetMultiTexGendvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenfvEXT)(GLenum, GLenum, GLenum, GLfloat *);
#define glGetMultiTexGenfvEXT _ptrc_glGetMultiTexGenfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenivEXT)(GLenum, GLenum, GLenum, GLint *);
#define glGetMultiTexGenivEXT _ptrc_glGetMultiTexGenivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexImageEXT)(GLenum, GLenum, GLint, GLenum, GLenum, GLvoid *);
#define glGetMultiTexImageEXT _ptrc_glGetMultiTexImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterfvEXT)(GLenum, GLenum, GLint, GLenum, GLfloat *);
#define glGetMultiTexLevelParameterfvEXT _ptrc_glGetMultiTexLevelParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterivEXT)(GLenum, GLenum, GLint, GLenum, GLint *);
#define glGetMultiTexLevelParameterivEXT _ptrc_glGetMultiTexLevelParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIivEXT)(GLenum, GLenum, GLenum, GLint *);
#define glGetMultiTexParameterIivEXT _ptrc_glGetMultiTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIuivEXT)(GLenum, GLenum, GLenum, GLuint *);
#define glGetMultiTexParameterIuivEXT _ptrc_glGetMultiTexParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterfvEXT)(GLenum, GLenum, GLenum, GLfloat *);
#define glGetMultiTexParameterfvEXT _ptrc_glGetMultiTexParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterivEXT)(GLenum, GLenum, GLenum, GLint *);
#define glGetMultiTexParameterivEXT _ptrc_glGetMultiTexParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterivEXT)(GLuint, GLenum, GLint *);
#define glGetNamedBufferParameterivEXT _ptrc_glGetNamedBufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferPointervEXT)(GLuint, GLenum, GLvoid **);
#define glGetNamedBufferPointervEXT _ptrc_glGetNamedBufferPointervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferSubDataEXT)(GLuint, GLintptr, GLsizeiptr, GLvoid *);
#define glGetNamedBufferSubDataEXT _ptrc_glGetNamedBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferAttachmentParameterivEXT)(GLuint, GLenum, GLenum, GLint *);
#define glGetNamedFramebufferAttachmentParameterivEXT _ptrc_glGetNamedFramebufferAttachmentParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferParameterivEXT)(GLuint, GLenum, GLint *);
#define glGetNamedFramebufferParameterivEXT _ptrc_glGetNamedFramebufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIivEXT)(GLuint, GLenum, GLuint, GLint *);
#define glGetNamedProgramLocalParameterIivEXT _ptrc_glGetNamedProgramLocalParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIuivEXT)(GLuint, GLenum, GLuint, GLuint *);
#define glGetNamedProgramLocalParameterIuivEXT _ptrc_glGetNamedProgramLocalParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterdvEXT)(GLuint, GLenum, GLuint, GLdouble *);
#define glGetNamedProgramLocalParameterdvEXT _ptrc_glGetNamedProgramLocalParameterdvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterfvEXT)(GLuint, GLenum, GLuint, GLfloat *);
#define glGetNamedProgramLocalParameterfvEXT _ptrc_glGetNamedProgramLocalParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramStringEXT)(GLuint, GLenum, GLenum, GLvoid *);
#define glGetNamedProgramStringEXT _ptrc_glGetNamedProgramStringEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramivEXT)(GLuint, GLenum, GLenum, GLint *);
#define glGetNamedProgramivEXT _ptrc_glGetNamedProgramivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedRenderbufferParameterivEXT)(GLuint, GLenum, GLint *);
#define glGetNamedRenderbufferParameterivEXT _ptrc_glGetNamedRenderbufferParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointerIndexedvEXT)(GLenum, GLuint, GLvoid **);
#define glGetPointerIndexedvEXT _ptrc_glGetPointerIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointeri_vEXT)(GLenum, GLuint, GLvoid **);
#define glGetPointeri_vEXT _ptrc_glGetPointeri_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureImageEXT)(GLuint, GLenum, GLint, GLenum, GLenum, GLvoid *);
#define glGetTextureImageEXT _ptrc_glGetTextureImageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterfvEXT)(GLuint, GLenum, GLint, GLenum, GLfloat *);
#define glGetTextureLevelParameterfvEXT _ptrc_glGetTextureLevelParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterivEXT)(GLuint, GLenum, GLint, GLenum, GLint *);
#define glGetTextureLevelParameterivEXT _ptrc_glGetTextureLevelParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIivEXT)(GLuint, GLenum, GLenum, GLint *);
#define glGetTextureParameterIivEXT _ptrc_glGetTextureParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIuivEXT)(GLuint, GLenum, GLenum, GLuint *);
#define glGetTextureParameterIuivEXT _ptrc_glGetTextureParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterfvEXT)(GLuint, GLenum, GLenum, GLfloat *);
#define glGetTextureParameterfvEXT _ptrc_glGetTextureParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterivEXT)(GLuint, GLenum, GLenum, GLint *);
#define glGetTextureParameterivEXT _ptrc_glGetTextureParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegeri_vEXT)(GLuint, GLuint, GLenum, GLint *);
#define glGetVertexArrayIntegeri_vEXT _ptrc_glGetVertexArrayIntegeri_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegervEXT)(GLuint, GLenum, GLint *);
#define glGetVertexArrayIntegervEXT _ptrc_glGetVertexArrayIntegervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointeri_vEXT)(GLuint, GLuint, GLenum, GLvoid **);
#define glGetVertexArrayPointeri_vEXT _ptrc_glGetVertexArrayPointeri_vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointervEXT)(GLuint, GLenum, GLvoid **);
#define glGetVertexArrayPointervEXT _ptrc_glGetVertexArrayPointervEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledIndexedEXT)(GLenum, GLuint);
#define glIsEnabledIndexedEXT _ptrc_glIsEnabledIndexedEXT
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferEXT)(GLuint, GLenum);
#define glMapNamedBufferEXT _ptrc_glMapNamedBufferEXT
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferRangeEXT)(GLuint, GLintptr, GLsizeiptr, GLbitfield);
#define glMapNamedBufferRangeEXT _ptrc_glMapNamedBufferRangeEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixFrustumEXT)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
#define glMatrixFrustumEXT _ptrc_glMatrixFrustumEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadIdentityEXT)(GLenum);
#define glMatrixLoadIdentityEXT _ptrc_glMatrixLoadIdentityEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposedEXT)(GLenum, const GLdouble *);
#define glMatrixLoadTransposedEXT _ptrc_glMatrixLoadTransposedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposefEXT)(GLenum, const GLfloat *);
#define glMatrixLoadTransposefEXT _ptrc_glMatrixLoadTransposefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoaddEXT)(GLenum, const GLdouble *);
#define glMatrixLoaddEXT _ptrc_glMatrixLoaddEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadfEXT)(GLenum, const GLfloat *);
#define glMatrixLoadfEXT _ptrc_glMatrixLoadfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposedEXT)(GLenum, const GLdouble *);
#define glMatrixMultTransposedEXT _ptrc_glMatrixMultTransposedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposefEXT)(GLenum, const GLfloat *);
#define glMatrixMultTransposefEXT _ptrc_glMatrixMultTransposefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultdEXT)(GLenum, const GLdouble *);
#define glMatrixMultdEXT _ptrc_glMatrixMultdEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultfEXT)(GLenum, const GLfloat *);
#define glMatrixMultfEXT _ptrc_glMatrixMultfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixOrthoEXT)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
#define glMatrixOrthoEXT _ptrc_glMatrixOrthoEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixPopEXT)(GLenum);
#define glMatrixPopEXT _ptrc_glMatrixPopEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixPushEXT)(GLenum);
#define glMatrixPushEXT _ptrc_glMatrixPushEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatedEXT)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
#define glMatrixRotatedEXT _ptrc_glMatrixRotatedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatefEXT)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
#define glMatrixRotatefEXT _ptrc_glMatrixRotatefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixScaledEXT)(GLenum, GLdouble, GLdouble, GLdouble);
#define glMatrixScaledEXT _ptrc_glMatrixScaledEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixScalefEXT)(GLenum, GLfloat, GLfloat, GLfloat);
#define glMatrixScalefEXT _ptrc_glMatrixScalefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatedEXT)(GLenum, GLdouble, GLdouble, GLdouble);
#define glMatrixTranslatedEXT _ptrc_glMatrixTranslatedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatefEXT)(GLenum, GLfloat, GLfloat, GLfloat);
#define glMatrixTranslatefEXT _ptrc_glMatrixTranslatefEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexBufferEXT)(GLenum, GLenum, GLenum, GLuint);
#define glMultiTexBufferEXT _ptrc_glMultiTexBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordPointerEXT)(GLenum, GLint, GLenum, GLsizei, const GLvoid *);
#define glMultiTexCoordPointerEXT _ptrc_glMultiTexCoordPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfEXT)(GLenum, GLenum, GLenum, GLfloat);
#define glMultiTexEnvfEXT _ptrc_glMultiTexEnvfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfvEXT)(GLenum, GLenum, GLenum, const GLfloat *);
#define glMultiTexEnvfvEXT _ptrc_glMultiTexEnvfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnviEXT)(GLenum, GLenum, GLenum, GLint);
#define glMultiTexEnviEXT _ptrc_glMultiTexEnviEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvivEXT)(GLenum, GLenum, GLenum, const GLint *);
#define glMultiTexEnvivEXT _ptrc_glMultiTexEnvivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendEXT)(GLenum, GLenum, GLenum, GLdouble);
#define glMultiTexGendEXT _ptrc_glMultiTexGendEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendvEXT)(GLenum, GLenum, GLenum, const GLdouble *);
#define glMultiTexGendvEXT _ptrc_glMultiTexGendvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfEXT)(GLenum, GLenum, GLenum, GLfloat);
#define glMultiTexGenfEXT _ptrc_glMultiTexGenfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfvEXT)(GLenum, GLenum, GLenum, const GLfloat *);
#define glMultiTexGenfvEXT _ptrc_glMultiTexGenfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGeniEXT)(GLenum, GLenum, GLenum, GLint);
#define glMultiTexGeniEXT _ptrc_glMultiTexGeniEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenivEXT)(GLenum, GLenum, GLenum, const GLint *);
#define glMultiTexGenivEXT _ptrc_glMultiTexGenivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glMultiTexImage1DEXT _ptrc_glMultiTexImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage2DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glMultiTexImage2DEXT _ptrc_glMultiTexImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage3DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glMultiTexImage3DEXT _ptrc_glMultiTexImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIivEXT)(GLenum, GLenum, GLenum, const GLint *);
#define glMultiTexParameterIivEXT _ptrc_glMultiTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIuivEXT)(GLenum, GLenum, GLenum, const GLuint *);
#define glMultiTexParameterIuivEXT _ptrc_glMultiTexParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfEXT)(GLenum, GLenum, GLenum, GLfloat);
#define glMultiTexParameterfEXT _ptrc_glMultiTexParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfvEXT)(GLenum, GLenum, GLenum, const GLfloat *);
#define glMultiTexParameterfvEXT _ptrc_glMultiTexParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameteriEXT)(GLenum, GLenum, GLenum, GLint);
#define glMultiTexParameteriEXT _ptrc_glMultiTexParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterivEXT)(GLenum, GLenum, GLenum, const GLint *);
#define glMultiTexParameterivEXT _ptrc_glMultiTexParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexRenderbufferEXT)(GLenum, GLenum, GLuint);
#define glMultiTexRenderbufferEXT _ptrc_glMultiTexRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
#define glMultiTexSubImage1DEXT _ptrc_glMultiTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage2DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glMultiTexSubImage2DEXT _ptrc_glMultiTexSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage3DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glMultiTexSubImage3DEXT _ptrc_glMultiTexSubImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferDataEXT)(GLuint, GLsizeiptr, const GLvoid *, GLenum);
#define glNamedBufferDataEXT _ptrc_glNamedBufferDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferSubDataEXT)(GLuint, GLintptr, GLsizeiptr, const GLvoid *);
#define glNamedBufferSubDataEXT _ptrc_glNamedBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedCopyBufferSubDataEXT)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr);
#define glNamedCopyBufferSubDataEXT _ptrc_glNamedCopyBufferSubDataEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferParameteriEXT)(GLuint, GLenum, GLint);
#define glNamedFramebufferParameteriEXT _ptrc_glNamedFramebufferParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferRenderbufferEXT)(GLuint, GLenum, GLenum, GLuint);
#define glNamedFramebufferRenderbufferEXT _ptrc_glNamedFramebufferRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture1DEXT)(GLuint, GLenum, GLenum, GLuint, GLint);
#define glNamedFramebufferTexture1DEXT _ptrc_glNamedFramebufferTexture1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture2DEXT)(GLuint, GLenum, GLenum, GLuint, GLint);
#define glNamedFramebufferTexture2DEXT _ptrc_glNamedFramebufferTexture2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture3DEXT)(GLuint, GLenum, GLenum, GLuint, GLint, GLint);
#define glNamedFramebufferTexture3DEXT _ptrc_glNamedFramebufferTexture3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureEXT)(GLuint, GLenum, GLuint, GLint);
#define glNamedFramebufferTextureEXT _ptrc_glNamedFramebufferTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureFaceEXT)(GLuint, GLenum, GLuint, GLint, GLenum);
#define glNamedFramebufferTextureFaceEXT _ptrc_glNamedFramebufferTextureFaceEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureLayerEXT)(GLuint, GLenum, GLuint, GLint, GLint);
#define glNamedFramebufferTextureLayerEXT _ptrc_glNamedFramebufferTextureLayerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dEXT)(GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glNamedProgramLocalParameter4dEXT _ptrc_glNamedProgramLocalParameter4dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dvEXT)(GLuint, GLenum, GLuint, const GLdouble *);
#define glNamedProgramLocalParameter4dvEXT _ptrc_glNamedProgramLocalParameter4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fEXT)(GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glNamedProgramLocalParameter4fEXT _ptrc_glNamedProgramLocalParameter4fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fvEXT)(GLuint, GLenum, GLuint, const GLfloat *);
#define glNamedProgramLocalParameter4fvEXT _ptrc_glNamedProgramLocalParameter4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4iEXT)(GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint);
#define glNamedProgramLocalParameterI4iEXT _ptrc_glNamedProgramLocalParameterI4iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4ivEXT)(GLuint, GLenum, GLuint, const GLint *);
#define glNamedProgramLocalParameterI4ivEXT _ptrc_glNamedProgramLocalParameterI4ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uiEXT)(GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glNamedProgramLocalParameterI4uiEXT _ptrc_glNamedProgramLocalParameterI4uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uivEXT)(GLuint, GLenum, GLuint, const GLuint *);
#define glNamedProgramLocalParameterI4uivEXT _ptrc_glNamedProgramLocalParameterI4uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameters4fvEXT)(GLuint, GLenum, GLuint, GLsizei, const GLfloat *);
#define glNamedProgramLocalParameters4fvEXT _ptrc_glNamedProgramLocalParameters4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4ivEXT)(GLuint, GLenum, GLuint, GLsizei, const GLint *);
#define glNamedProgramLocalParametersI4ivEXT _ptrc_glNamedProgramLocalParametersI4ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4uivEXT)(GLuint, GLenum, GLuint, GLsizei, const GLuint *);
#define glNamedProgramLocalParametersI4uivEXT _ptrc_glNamedProgramLocalParametersI4uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramStringEXT)(GLuint, GLenum, GLenum, GLsizei, const GLvoid *);
#define glNamedProgramStringEXT _ptrc_glNamedProgramStringEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageEXT)(GLuint, GLenum, GLsizei, GLsizei);
#define glNamedRenderbufferStorageEXT _ptrc_glNamedRenderbufferStorageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT)(GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei);
#define glNamedRenderbufferStorageMultisampleCoverageEXT _ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleEXT)(GLuint, GLsizei, GLenum, GLsizei, GLsizei);
#define glNamedRenderbufferStorageMultisampleEXT _ptrc_glNamedRenderbufferStorageMultisampleEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dEXT)(GLuint, GLint, GLdouble);
#define glProgramUniform1dEXT _ptrc_glProgramUniform1dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dvEXT)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform1dvEXT _ptrc_glProgramUniform1dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fEXT)(GLuint, GLint, GLfloat);
#define glProgramUniform1fEXT _ptrc_glProgramUniform1fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fvEXT)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform1fvEXT _ptrc_glProgramUniform1fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iEXT)(GLuint, GLint, GLint);
#define glProgramUniform1iEXT _ptrc_glProgramUniform1iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ivEXT)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform1ivEXT _ptrc_glProgramUniform1ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiEXT)(GLuint, GLint, GLuint);
#define glProgramUniform1uiEXT _ptrc_glProgramUniform1uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uivEXT)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform1uivEXT _ptrc_glProgramUniform1uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dEXT)(GLuint, GLint, GLdouble, GLdouble);
#define glProgramUniform2dEXT _ptrc_glProgramUniform2dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dvEXT)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform2dvEXT _ptrc_glProgramUniform2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fEXT)(GLuint, GLint, GLfloat, GLfloat);
#define glProgramUniform2fEXT _ptrc_glProgramUniform2fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fvEXT)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform2fvEXT _ptrc_glProgramUniform2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iEXT)(GLuint, GLint, GLint, GLint);
#define glProgramUniform2iEXT _ptrc_glProgramUniform2iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ivEXT)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform2ivEXT _ptrc_glProgramUniform2ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiEXT)(GLuint, GLint, GLuint, GLuint);
#define glProgramUniform2uiEXT _ptrc_glProgramUniform2uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uivEXT)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform2uivEXT _ptrc_glProgramUniform2uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dEXT)(GLuint, GLint, GLdouble, GLdouble, GLdouble);
#define glProgramUniform3dEXT _ptrc_glProgramUniform3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dvEXT)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform3dvEXT _ptrc_glProgramUniform3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fEXT)(GLuint, GLint, GLfloat, GLfloat, GLfloat);
#define glProgramUniform3fEXT _ptrc_glProgramUniform3fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fvEXT)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform3fvEXT _ptrc_glProgramUniform3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iEXT)(GLuint, GLint, GLint, GLint, GLint);
#define glProgramUniform3iEXT _ptrc_glProgramUniform3iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ivEXT)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform3ivEXT _ptrc_glProgramUniform3ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiEXT)(GLuint, GLint, GLuint, GLuint, GLuint);
#define glProgramUniform3uiEXT _ptrc_glProgramUniform3uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uivEXT)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform3uivEXT _ptrc_glProgramUniform3uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dEXT)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramUniform4dEXT _ptrc_glProgramUniform4dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dvEXT)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform4dvEXT _ptrc_glProgramUniform4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fEXT)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramUniform4fEXT _ptrc_glProgramUniform4fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fvEXT)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform4fvEXT _ptrc_glProgramUniform4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iEXT)(GLuint, GLint, GLint, GLint, GLint, GLint);
#define glProgramUniform4iEXT _ptrc_glProgramUniform4iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ivEXT)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform4ivEXT _ptrc_glProgramUniform4ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiEXT)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
#define glProgramUniform4uiEXT _ptrc_glProgramUniform4uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uivEXT)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform4uivEXT _ptrc_glProgramUniform4uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2dvEXT _ptrc_glProgramUniformMatrix2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2fvEXT _ptrc_glProgramUniformMatrix2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2x3dvEXT _ptrc_glProgramUniformMatrix2x3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2x3fvEXT _ptrc_glProgramUniformMatrix2x3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2x4dvEXT _ptrc_glProgramUniformMatrix2x4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2x4fvEXT _ptrc_glProgramUniformMatrix2x4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3dvEXT _ptrc_glProgramUniformMatrix3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3fvEXT _ptrc_glProgramUniformMatrix3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3x2dvEXT _ptrc_glProgramUniformMatrix3x2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3x2fvEXT _ptrc_glProgramUniformMatrix3x2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3x4dvEXT _ptrc_glProgramUniformMatrix3x4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3x4fvEXT _ptrc_glProgramUniformMatrix3x4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4dvEXT _ptrc_glProgramUniformMatrix4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4fvEXT _ptrc_glProgramUniformMatrix4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4x2dvEXT _ptrc_glProgramUniformMatrix4x2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4x2fvEXT _ptrc_glProgramUniformMatrix4x2fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4x3dvEXT _ptrc_glProgramUniformMatrix4x3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4x3fvEXT _ptrc_glProgramUniformMatrix4x3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPushClientAttribDefaultEXT)(GLbitfield);
#define glPushClientAttribDefaultEXT _ptrc_glPushClientAttribDefaultEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferEXT)(GLuint, GLenum, GLenum, GLuint);
#define glTextureBufferEXT _ptrc_glTextureBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferRangeEXT)(GLuint, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr);
#define glTextureBufferRangeEXT _ptrc_glTextureBufferRangeEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage1DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTextureImage1DEXT _ptrc_glTextureImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTextureImage2DEXT _ptrc_glTextureImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTextureImage3DEXT _ptrc_glTextureImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexturePageCommitmentEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTexturePageCommitmentEXT _ptrc_glTexturePageCommitmentEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIivEXT)(GLuint, GLenum, GLenum, const GLint *);
#define glTextureParameterIivEXT _ptrc_glTextureParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIuivEXT)(GLuint, GLenum, GLenum, const GLuint *);
#define glTextureParameterIuivEXT _ptrc_glTextureParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfEXT)(GLuint, GLenum, GLenum, GLfloat);
#define glTextureParameterfEXT _ptrc_glTextureParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfvEXT)(GLuint, GLenum, GLenum, const GLfloat *);
#define glTextureParameterfvEXT _ptrc_glTextureParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteriEXT)(GLuint, GLenum, GLenum, GLint);
#define glTextureParameteriEXT _ptrc_glTextureParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterivEXT)(GLuint, GLenum, GLenum, const GLint *);
#define glTextureParameterivEXT _ptrc_glTextureParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureRenderbufferEXT)(GLuint, GLenum, GLuint);
#define glTextureRenderbufferEXT _ptrc_glTextureRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage1DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei);
#define glTextureStorage1DEXT _ptrc_glTextureStorage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define glTextureStorage2DEXT _ptrc_glTextureStorage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DMultisampleEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
#define glTextureStorage2DMultisampleEXT _ptrc_glTextureStorage2DMultisampleEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
#define glTextureStorage3DEXT _ptrc_glTextureStorage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DMultisampleEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTextureStorage3DMultisampleEXT _ptrc_glTextureStorage3DMultisampleEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage1DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTextureSubImage1DEXT _ptrc_glTextureSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage2DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTextureSubImage2DEXT _ptrc_glTextureSubImage2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage3DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTextureSubImage3DEXT _ptrc_glTextureSubImage3DEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapNamedBufferEXT)(GLuint);
#define glUnmapNamedBufferEXT _ptrc_glUnmapNamedBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayBindVertexBufferEXT)(GLuint, GLuint, GLuint, GLintptr, GLsizei);
#define glVertexArrayBindVertexBufferEXT _ptrc_glVertexArrayBindVertexBufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayColorOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr);
#define glVertexArrayColorOffsetEXT _ptrc_glVertexArrayColorOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayEdgeFlagOffsetEXT)(GLuint, GLuint, GLsizei, GLintptr);
#define glVertexArrayEdgeFlagOffsetEXT _ptrc_glVertexArrayEdgeFlagOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayFogCoordOffsetEXT)(GLuint, GLuint, GLenum, GLsizei, GLintptr);
#define glVertexArrayFogCoordOffsetEXT _ptrc_glVertexArrayFogCoordOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayIndexOffsetEXT)(GLuint, GLuint, GLenum, GLsizei, GLintptr);
#define glVertexArrayIndexOffsetEXT _ptrc_glVertexArrayIndexOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayMultiTexCoordOffsetEXT)(GLuint, GLuint, GLenum, GLint, GLenum, GLsizei, GLintptr);
#define glVertexArrayMultiTexCoordOffsetEXT _ptrc_glVertexArrayMultiTexCoordOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayNormalOffsetEXT)(GLuint, GLuint, GLenum, GLsizei, GLintptr);
#define glVertexArrayNormalOffsetEXT _ptrc_glVertexArrayNormalOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArraySecondaryColorOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr);
#define glVertexArraySecondaryColorOffsetEXT _ptrc_glVertexArraySecondaryColorOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayTexCoordOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr);
#define glVertexArrayTexCoordOffsetEXT _ptrc_glVertexArrayTexCoordOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribBindingEXT)(GLuint, GLuint, GLuint);
#define glVertexArrayVertexAttribBindingEXT _ptrc_glVertexArrayVertexAttribBindingEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribFormatEXT)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint);
#define glVertexArrayVertexAttribFormatEXT _ptrc_glVertexArrayVertexAttribFormatEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIFormatEXT)(GLuint, GLuint, GLint, GLenum, GLuint);
#define glVertexArrayVertexAttribIFormatEXT _ptrc_glVertexArrayVertexAttribIFormatEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIOffsetEXT)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr);
#define glVertexArrayVertexAttribIOffsetEXT _ptrc_glVertexArrayVertexAttribIOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLFormatEXT)(GLuint, GLuint, GLint, GLenum, GLuint);
#define glVertexArrayVertexAttribLFormatEXT _ptrc_glVertexArrayVertexAttribLFormatEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLOffsetEXT)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr);
#define glVertexArrayVertexAttribLOffsetEXT _ptrc_glVertexArrayVertexAttribLOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribOffsetEXT)(GLuint, GLuint, GLuint, GLint, GLenum, GLboolean, GLsizei, GLintptr);
#define glVertexArrayVertexAttribOffsetEXT _ptrc_glVertexArrayVertexAttribOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBindingDivisorEXT)(GLuint, GLuint, GLuint);
#define glVertexArrayVertexBindingDivisorEXT _ptrc_glVertexArrayVertexBindingDivisorEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr);
#define glVertexArrayVertexOffsetEXT _ptrc_glVertexArrayVertexOffsetEXT
#endif /*GL_EXT_direct_state_access*/ 

#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorMaskIndexedEXT)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
#define glColorMaskIndexedEXT _ptrc_glColorMaskIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableIndexedEXT)(GLenum, GLuint);
#define glDisableIndexedEXT _ptrc_glDisableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableIndexedEXT)(GLenum, GLuint);
#define glEnableIndexedEXT _ptrc_glEnableIndexedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanIndexedvEXT)(GLenum, GLuint, GLboolean *);
#define glGetBooleanIndexedvEXT _ptrc_glGetBooleanIndexedvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerIndexedvEXT)(GLenum, GLuint, GLint *);
#define glGetIntegerIndexedvEXT _ptrc_glGetIntegerIndexedvEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledIndexedEXT)(GLenum, GLuint);
#define glIsEnabledIndexedEXT _ptrc_glIsEnabledIndexedEXT
#endif /*GL_EXT_draw_buffers2*/ 

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedEXT)(GLenum, GLint, GLsizei, GLsizei);
#define glDrawArraysInstancedEXT _ptrc_glDrawArraysInstancedEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedEXT)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei);
#define glDrawElementsInstancedEXT _ptrc_glDrawElementsInstancedEXT
#endif /*GL_EXT_draw_instanced*/ 

#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsEXT)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *);
#define glDrawRangeElementsEXT _ptrc_glDrawRangeElementsEXT
#endif /*GL_EXT_draw_range_elements*/ 

#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointerEXT)(GLenum, GLsizei, const GLvoid *);
#define glFogCoordPointerEXT _ptrc_glFogCoordPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddEXT)(GLdouble);
#define glFogCoorddEXT _ptrc_glFogCoorddEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddvEXT)(const GLdouble *);
#define glFogCoorddvEXT _ptrc_glFogCoorddvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfEXT)(GLfloat);
#define glFogCoordfEXT _ptrc_glFogCoordfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfvEXT)(const GLfloat *);
#define glFogCoordfvEXT _ptrc_glFogCoordfvEXT
#endif /*GL_EXT_fog_coord*/ 

#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebufferEXT)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
#define glBlitFramebufferEXT _ptrc_glBlitFramebufferEXT
#endif /*GL_EXT_framebuffer_blit*/ 

#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleEXT)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define glRenderbufferStorageMultisampleEXT _ptrc_glRenderbufferStorageMultisampleEXT
#endif /*GL_EXT_framebuffer_multisample*/ 


#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFramebufferEXT)(GLenum, GLuint);
#define glBindFramebufferEXT _ptrc_glBindFramebufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbufferEXT)(GLenum, GLuint);
#define glBindRenderbufferEXT _ptrc_glBindRenderbufferEXT
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatusEXT)(GLenum);
#define glCheckFramebufferStatusEXT _ptrc_glCheckFramebufferStatusEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffersEXT)(GLsizei, const GLuint *);
#define glDeleteFramebuffersEXT _ptrc_glDeleteFramebuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffersEXT)(GLsizei, const GLuint *);
#define glDeleteRenderbuffersEXT _ptrc_glDeleteRenderbuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbufferEXT)(GLenum, GLenum, GLenum, GLuint);
#define glFramebufferRenderbufferEXT _ptrc_glFramebufferRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1DEXT)(GLenum, GLenum, GLenum, GLuint, GLint);
#define glFramebufferTexture1DEXT _ptrc_glFramebufferTexture1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2DEXT)(GLenum, GLenum, GLenum, GLuint, GLint);
#define glFramebufferTexture2DEXT _ptrc_glFramebufferTexture2DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3DEXT)(GLenum, GLenum, GLenum, GLuint, GLint, GLint);
#define glFramebufferTexture3DEXT _ptrc_glFramebufferTexture3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffersEXT)(GLsizei, GLuint *);
#define glGenFramebuffersEXT _ptrc_glGenFramebuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffersEXT)(GLsizei, GLuint *);
#define glGenRenderbuffersEXT _ptrc_glGenRenderbuffersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmapEXT)(GLenum);
#define glGenerateMipmapEXT _ptrc_glGenerateMipmapEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameterivEXT)(GLenum, GLenum, GLenum, GLint *);
#define glGetFramebufferAttachmentParameterivEXT _ptrc_glGetFramebufferAttachmentParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameterivEXT)(GLenum, GLenum, GLint *);
#define glGetRenderbufferParameterivEXT _ptrc_glGetRenderbufferParameterivEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebufferEXT)(GLuint);
#define glIsFramebufferEXT _ptrc_glIsFramebufferEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbufferEXT)(GLuint);
#define glIsRenderbufferEXT _ptrc_glIsRenderbufferEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageEXT)(GLenum, GLenum, GLsizei, GLsizei);
#define glRenderbufferStorageEXT _ptrc_glRenderbufferStorageEXT
#endif /*GL_EXT_framebuffer_object*/ 


#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriEXT)(GLuint, GLenum, GLint);
#define glProgramParameteriEXT _ptrc_glProgramParameteriEXT
#endif /*GL_EXT_geometry_shader4*/ 

#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameters4fvEXT)(GLenum, GLuint, GLsizei, const GLfloat *);
#define glProgramEnvParameters4fvEXT _ptrc_glProgramEnvParameters4fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameters4fvEXT)(GLenum, GLuint, GLsizei, const GLfloat *);
#define glProgramLocalParameters4fvEXT _ptrc_glProgramLocalParameters4fvEXT
#endif /*GL_EXT_gpu_program_parameters*/ 

#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationEXT)(GLuint, GLuint, const GLchar *);
#define glBindFragDataLocationEXT _ptrc_glBindFragDataLocationEXT
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocationEXT)(GLuint, const GLchar *);
#define glGetFragDataLocationEXT _ptrc_glGetFragDataLocationEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuivEXT)(GLuint, GLint, GLuint *);
#define glGetUniformuivEXT _ptrc_glGetUniformuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiEXT)(GLint, GLuint);
#define glUniform1uiEXT _ptrc_glUniform1uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1uivEXT)(GLint, GLsizei, const GLuint *);
#define glUniform1uivEXT _ptrc_glUniform1uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiEXT)(GLint, GLuint, GLuint);
#define glUniform2uiEXT _ptrc_glUniform2uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2uivEXT)(GLint, GLsizei, const GLuint *);
#define glUniform2uivEXT _ptrc_glUniform2uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiEXT)(GLint, GLuint, GLuint, GLuint);
#define glUniform3uiEXT _ptrc_glUniform3uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3uivEXT)(GLint, GLsizei, const GLuint *);
#define glUniform3uivEXT _ptrc_glUniform3uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiEXT)(GLint, GLuint, GLuint, GLuint, GLuint);
#define glUniform4uiEXT _ptrc_glUniform4uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4uivEXT)(GLint, GLsizei, const GLuint *);
#define glUniform4uivEXT _ptrc_glUniform4uivEXT
#endif /*GL_EXT_gpu_shader4*/ 

#ifndef GL_EXT_histogram
#define GL_EXT_histogram 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramEXT)(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
#define glGetHistogramEXT _ptrc_glGetHistogramEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterfvEXT)(GLenum, GLenum, GLfloat *);
#define glGetHistogramParameterfvEXT _ptrc_glGetHistogramParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterivEXT)(GLenum, GLenum, GLint *);
#define glGetHistogramParameterivEXT _ptrc_glGetHistogramParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxEXT)(GLenum, GLboolean, GLenum, GLenum, GLvoid *);
#define glGetMinmaxEXT _ptrc_glGetMinmaxEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterfvEXT)(GLenum, GLenum, GLfloat *);
#define glGetMinmaxParameterfvEXT _ptrc_glGetMinmaxParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterivEXT)(GLenum, GLenum, GLint *);
#define glGetMinmaxParameterivEXT _ptrc_glGetMinmaxParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glHistogramEXT)(GLenum, GLsizei, GLenum, GLboolean);
#define glHistogramEXT _ptrc_glHistogramEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMinmaxEXT)(GLenum, GLenum, GLboolean);
#define glMinmaxEXT _ptrc_glMinmaxEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glResetHistogramEXT)(GLenum);
#define glResetHistogramEXT _ptrc_glResetHistogramEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glResetMinmaxEXT)(GLenum);
#define glResetMinmaxEXT _ptrc_glResetMinmaxEXT
#endif /*GL_EXT_histogram*/ 


#ifndef GL_EXT_index_func
#define GL_EXT_index_func 1
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexFuncEXT)(GLenum, GLclampf);
#define glIndexFuncEXT _ptrc_glIndexFuncEXT
#endif /*GL_EXT_index_func*/ 

#ifndef GL_EXT_index_material
#define GL_EXT_index_material 1
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexMaterialEXT)(GLenum, GLenum);
#define glIndexMaterialEXT _ptrc_glIndexMaterialEXT
#endif /*GL_EXT_index_material*/ 


#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glApplyTextureEXT)(GLenum);
#define glApplyTextureEXT _ptrc_glApplyTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureLightEXT)(GLenum);
#define glTextureLightEXT _ptrc_glTextureLightEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureMaterialEXT)(GLenum, GLenum);
#define glTextureMaterialEXT _ptrc_glTextureMaterialEXT
#endif /*GL_EXT_light_texture*/ 


#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysEXT)(GLenum, const GLint *, const GLsizei *, GLsizei);
#define glMultiDrawArraysEXT _ptrc_glMultiDrawArraysEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsEXT)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei);
#define glMultiDrawElementsEXT _ptrc_glMultiDrawElementsEXT
#endif /*GL_EXT_multi_draw_arrays*/ 

#ifndef GL_EXT_multisample
#define GL_EXT_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskEXT)(GLclampf, GLboolean);
#define glSampleMaskEXT _ptrc_glSampleMaskEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplePatternEXT)(GLenum);
#define glSamplePatternEXT _ptrc_glSamplePatternEXT
#endif /*GL_EXT_multisample*/ 




#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableEXT)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
#define glColorTableEXT _ptrc_glColorTableEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableEXT)(GLenum, GLenum, GLenum, GLvoid *);
#define glGetColorTableEXT _ptrc_glGetColorTableEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfvEXT)(GLenum, GLenum, GLfloat *);
#define glGetColorTableParameterfvEXT _ptrc_glGetColorTableParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterivEXT)(GLenum, GLenum, GLint *);
#define glGetColorTableParameterivEXT _ptrc_glGetColorTableParameterivEXT
#endif /*GL_EXT_paletted_texture*/ 


#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTransformParameterfvEXT)(GLenum, GLenum, GLfloat *);
#define glGetPixelTransformParameterfvEXT _ptrc_glGetPixelTransformParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTransformParameterivEXT)(GLenum, GLenum, GLint *);
#define glGetPixelTransformParameterivEXT _ptrc_glGetPixelTransformParameterivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameterfEXT)(GLenum, GLenum, GLfloat);
#define glPixelTransformParameterfEXT _ptrc_glPixelTransformParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameterfvEXT)(GLenum, GLenum, const GLfloat *);
#define glPixelTransformParameterfvEXT _ptrc_glPixelTransformParameterfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameteriEXT)(GLenum, GLenum, GLint);
#define glPixelTransformParameteriEXT _ptrc_glPixelTransformParameteriEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameterivEXT)(GLenum, GLenum, const GLint *);
#define glPixelTransformParameterivEXT _ptrc_glPixelTransformParameterivEXT
#endif /*GL_EXT_pixel_transform*/ 


#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfEXT)(GLenum, GLfloat);
#define glPointParameterfEXT _ptrc_glPointParameterfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvEXT)(GLenum, const GLfloat *);
#define glPointParameterfvEXT _ptrc_glPointParameterfvEXT
#endif /*GL_EXT_point_parameters*/ 

#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffsetEXT)(GLfloat, GLfloat);
#define glPolygonOffsetEXT _ptrc_glPolygonOffsetEXT
#endif /*GL_EXT_polygon_offset*/ 

#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertexEXT)(GLenum);
#define glProvokingVertexEXT _ptrc_glProvokingVertexEXT
#endif /*GL_EXT_provoking_vertex*/ 


#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bEXT)(GLbyte, GLbyte, GLbyte);
#define glSecondaryColor3bEXT _ptrc_glSecondaryColor3bEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bvEXT)(const GLbyte *);
#define glSecondaryColor3bvEXT _ptrc_glSecondaryColor3bvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dEXT)(GLdouble, GLdouble, GLdouble);
#define glSecondaryColor3dEXT _ptrc_glSecondaryColor3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dvEXT)(const GLdouble *);
#define glSecondaryColor3dvEXT _ptrc_glSecondaryColor3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fEXT)(GLfloat, GLfloat, GLfloat);
#define glSecondaryColor3fEXT _ptrc_glSecondaryColor3fEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fvEXT)(const GLfloat *);
#define glSecondaryColor3fvEXT _ptrc_glSecondaryColor3fvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3iEXT)(GLint, GLint, GLint);
#define glSecondaryColor3iEXT _ptrc_glSecondaryColor3iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ivEXT)(const GLint *);
#define glSecondaryColor3ivEXT _ptrc_glSecondaryColor3ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3sEXT)(GLshort, GLshort, GLshort);
#define glSecondaryColor3sEXT _ptrc_glSecondaryColor3sEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3svEXT)(const GLshort *);
#define glSecondaryColor3svEXT _ptrc_glSecondaryColor3svEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubEXT)(GLubyte, GLubyte, GLubyte);
#define glSecondaryColor3ubEXT _ptrc_glSecondaryColor3ubEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubvEXT)(const GLubyte *);
#define glSecondaryColor3ubvEXT _ptrc_glSecondaryColor3ubvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uiEXT)(GLuint, GLuint, GLuint);
#define glSecondaryColor3uiEXT _ptrc_glSecondaryColor3uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uivEXT)(const GLuint *);
#define glSecondaryColor3uivEXT _ptrc_glSecondaryColor3uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usEXT)(GLushort, GLushort, GLushort);
#define glSecondaryColor3usEXT _ptrc_glSecondaryColor3usEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usvEXT)(const GLushort *);
#define glSecondaryColor3usvEXT _ptrc_glSecondaryColor3usvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointerEXT)(GLint, GLenum, GLsizei, const GLvoid *);
#define glSecondaryColorPointerEXT _ptrc_glSecondaryColorPointerEXT
#endif /*GL_EXT_secondary_color*/ 

#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveProgramEXT)(GLuint);
#define glActiveProgramEXT _ptrc_glActiveProgramEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramEXT)(GLenum, const GLchar *);
#define glCreateShaderProgramEXT _ptrc_glCreateShaderProgramEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glUseShaderProgramEXT)(GLenum, GLuint);
#define glUseShaderProgramEXT _ptrc_glUseShaderProgramEXT
#endif /*GL_EXT_separate_shader_objects*/ 


#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextureEXT)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLint);
#define glBindImageTextureEXT _ptrc_glBindImageTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrierEXT)(GLbitfield);
#define glMemoryBarrierEXT _ptrc_glMemoryBarrierEXT
#endif /*GL_EXT_shader_image_load_store*/ 



#ifndef GL_EXT_stencil_clear_tag
#define GL_EXT_stencil_clear_tag 1
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilClearTagEXT)(GLsizei, GLuint);
#define glStencilClearTagEXT _ptrc_glStencilClearTagEXT
#endif /*GL_EXT_stencil_clear_tag*/ 

#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveStencilFaceEXT)(GLenum);
#define glActiveStencilFaceEXT _ptrc_glActiveStencilFaceEXT
#endif /*GL_EXT_stencil_two_side*/ 


#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage1DEXT)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTexSubImage1DEXT _ptrc_glTexSubImage1DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage2DEXT)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTexSubImage2DEXT _ptrc_glTexSubImage2DEXT
#endif /*GL_EXT_subtexture*/ 


#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DEXT)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTexImage3DEXT _ptrc_glTexImage3DEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3DEXT)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTexSubImage3DEXT _ptrc_glTexSubImage3DEXT
#endif /*GL_EXT_texture3D*/ 


#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferEXT)(GLenum, GLenum, GLuint);
#define glTexBufferEXT _ptrc_glTexBufferEXT
#endif /*GL_EXT_texture_buffer_object*/ 









#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearColorIiEXT)(GLint, GLint, GLint, GLint);
#define glClearColorIiEXT _ptrc_glClearColorIiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glClearColorIuiEXT)(GLuint, GLuint, GLuint, GLuint);
#define glClearColorIuiEXT _ptrc_glClearColorIuiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIivEXT)(GLenum, GLenum, GLint *);
#define glGetTexParameterIivEXT _ptrc_glGetTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuivEXT)(GLenum, GLenum, GLuint *);
#define glGetTexParameterIuivEXT _ptrc_glGetTexParameterIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIivEXT)(GLenum, GLenum, const GLint *);
#define glTexParameterIivEXT _ptrc_glTexParameterIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuivEXT)(GLenum, GLenum, const GLuint *);
#define glTexParameterIuivEXT _ptrc_glTexParameterIuivEXT
#endif /*GL_EXT_texture_integer*/ 



#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreTexturesResidentEXT)(GLsizei, const GLuint *, GLboolean *);
#define glAreTexturesResidentEXT _ptrc_glAreTexturesResidentEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextureEXT)(GLenum, GLuint);
#define glBindTextureEXT _ptrc_glBindTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTexturesEXT)(GLsizei, const GLuint *);
#define glDeleteTexturesEXT _ptrc_glDeleteTexturesEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTexturesEXT)(GLsizei, GLuint *);
#define glGenTexturesEXT _ptrc_glGenTexturesEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureEXT)(GLuint);
#define glIsTextureEXT _ptrc_glIsTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTexturesEXT)(GLsizei, const GLuint *, const GLclampf *);
#define glPrioritizeTexturesEXT _ptrc_glPrioritizeTexturesEXT
#endif /*GL_EXT_texture_object*/ 

#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureNormalEXT)(GLenum);
#define glTextureNormalEXT _ptrc_glTextureNormalEXT
#endif /*GL_EXT_texture_perturb_normal*/ 






#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64vEXT)(GLuint, GLenum, GLint64 *);
#define glGetQueryObjecti64vEXT _ptrc_glGetQueryObjecti64vEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64vEXT)(GLuint, GLenum, GLuint64 *);
#define glGetQueryObjectui64vEXT _ptrc_glGetQueryObjectui64vEXT
#endif /*GL_EXT_timer_query*/ 

#ifndef GL_EXT_transform_feedback
#define GL_EXT_transform_feedback 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedbackEXT)(GLenum);
#define glBeginTransformFeedbackEXT _ptrc_glBeginTransformFeedbackEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBaseEXT)(GLenum, GLuint, GLuint);
#define glBindBufferBaseEXT _ptrc_glBindBufferBaseEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferOffsetEXT)(GLenum, GLuint, GLuint, GLintptr);
#define glBindBufferOffsetEXT _ptrc_glBindBufferOffsetEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRangeEXT)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
#define glBindBufferRangeEXT _ptrc_glBindBufferRangeEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedbackEXT)();
#define glEndTransformFeedbackEXT _ptrc_glEndTransformFeedbackEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVaryingEXT)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
#define glGetTransformFeedbackVaryingEXT _ptrc_glGetTransformFeedbackVaryingEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryingsEXT)(GLuint, GLsizei, const GLchar *const*, GLenum);
#define glTransformFeedbackVaryingsEXT _ptrc_glTransformFeedbackVaryingsEXT
#endif /*GL_EXT_transform_feedback*/ 

#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glArrayElementEXT)(GLint);
#define glArrayElementEXT _ptrc_glArrayElementEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glColorPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
#define glColorPointerEXT _ptrc_glColorPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysEXT)(GLenum, GLint, GLsizei);
#define glDrawArraysEXT _ptrc_glDrawArraysEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointerEXT)(GLsizei, GLsizei, const GLboolean *);
#define glEdgeFlagPointerEXT _ptrc_glEdgeFlagPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointervEXT)(GLenum, GLvoid **);
#define glGetPointervEXT _ptrc_glGetPointervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexPointerEXT)(GLenum, GLsizei, GLsizei, const GLvoid *);
#define glIndexPointerEXT _ptrc_glIndexPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalPointerEXT)(GLenum, GLsizei, GLsizei, const GLvoid *);
#define glNormalPointerEXT _ptrc_glNormalPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
#define glTexCoordPointerEXT _ptrc_glTexCoordPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *);
#define glVertexPointerEXT _ptrc_glVertexPointerEXT
#endif /*GL_EXT_vertex_array*/ 


#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdvEXT)(GLuint, GLenum, GLdouble *);
#define glGetVertexAttribLdvEXT _ptrc_glGetVertexAttribLdvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dEXT)(GLuint, GLdouble);
#define glVertexAttribL1dEXT _ptrc_glVertexAttribL1dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dvEXT)(GLuint, const GLdouble *);
#define glVertexAttribL1dvEXT _ptrc_glVertexAttribL1dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dEXT)(GLuint, GLdouble, GLdouble);
#define glVertexAttribL2dEXT _ptrc_glVertexAttribL2dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dvEXT)(GLuint, const GLdouble *);
#define glVertexAttribL2dvEXT _ptrc_glVertexAttribL2dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dEXT)(GLuint, GLdouble, GLdouble, GLdouble);
#define glVertexAttribL3dEXT _ptrc_glVertexAttribL3dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dvEXT)(GLuint, const GLdouble *);
#define glVertexAttribL3dvEXT _ptrc_glVertexAttribL3dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dEXT)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertexAttribL4dEXT _ptrc_glVertexAttribL4dEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dvEXT)(GLuint, const GLdouble *);
#define glVertexAttribL4dvEXT _ptrc_glVertexAttribL4dvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointerEXT)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexAttribLPointerEXT _ptrc_glVertexAttribLPointerEXT
#endif /*GL_EXT_vertex_attrib_64bit*/ 

#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginVertexShaderEXT)();
#define glBeginVertexShaderEXT _ptrc_glBeginVertexShaderEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glBindLightParameterEXT)(GLenum, GLenum);
#define glBindLightParameterEXT _ptrc_glBindLightParameterEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glBindMaterialParameterEXT)(GLenum, GLenum);
#define glBindMaterialParameterEXT _ptrc_glBindMaterialParameterEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glBindParameterEXT)(GLenum);
#define glBindParameterEXT _ptrc_glBindParameterEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glBindTexGenParameterEXT)(GLenum, GLenum, GLenum);
#define glBindTexGenParameterEXT _ptrc_glBindTexGenParameterEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glBindTextureUnitParameterEXT)(GLenum, GLenum);
#define glBindTextureUnitParameterEXT _ptrc_glBindTextureUnitParameterEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexShaderEXT)(GLuint);
#define glBindVertexShaderEXT _ptrc_glBindVertexShaderEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexShaderEXT)(GLuint);
#define glDeleteVertexShaderEXT _ptrc_glDeleteVertexShaderEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVariantClientStateEXT)(GLuint);
#define glDisableVariantClientStateEXT _ptrc_glDisableVariantClientStateEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVariantClientStateEXT)(GLuint);
#define glEnableVariantClientStateEXT _ptrc_glEnableVariantClientStateEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glEndVertexShaderEXT)();
#define glEndVertexShaderEXT _ptrc_glEndVertexShaderEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glExtractComponentEXT)(GLuint, GLuint, GLuint);
#define glExtractComponentEXT _ptrc_glExtractComponentEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGenSymbolsEXT)(GLenum, GLenum, GLenum, GLuint);
#define glGenSymbolsEXT _ptrc_glGenSymbolsEXT
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGenVertexShadersEXT)(GLuint);
#define glGenVertexShadersEXT _ptrc_glGenVertexShadersEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInvariantBooleanvEXT)(GLuint, GLenum, GLboolean *);
#define glGetInvariantBooleanvEXT _ptrc_glGetInvariantBooleanvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInvariantFloatvEXT)(GLuint, GLenum, GLfloat *);
#define glGetInvariantFloatvEXT _ptrc_glGetInvariantFloatvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInvariantIntegervEXT)(GLuint, GLenum, GLint *);
#define glGetInvariantIntegervEXT _ptrc_glGetInvariantIntegervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetLocalConstantBooleanvEXT)(GLuint, GLenum, GLboolean *);
#define glGetLocalConstantBooleanvEXT _ptrc_glGetLocalConstantBooleanvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetLocalConstantFloatvEXT)(GLuint, GLenum, GLfloat *);
#define glGetLocalConstantFloatvEXT _ptrc_glGetLocalConstantFloatvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetLocalConstantIntegervEXT)(GLuint, GLenum, GLint *);
#define glGetLocalConstantIntegervEXT _ptrc_glGetLocalConstantIntegervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVariantBooleanvEXT)(GLuint, GLenum, GLboolean *);
#define glGetVariantBooleanvEXT _ptrc_glGetVariantBooleanvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVariantFloatvEXT)(GLuint, GLenum, GLfloat *);
#define glGetVariantFloatvEXT _ptrc_glGetVariantFloatvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVariantIntegervEXT)(GLuint, GLenum, GLint *);
#define glGetVariantIntegervEXT _ptrc_glGetVariantIntegervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVariantPointervEXT)(GLuint, GLenum, GLvoid **);
#define glGetVariantPointervEXT _ptrc_glGetVariantPointervEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glInsertComponentEXT)(GLuint, GLuint, GLuint);
#define glInsertComponentEXT _ptrc_glInsertComponentEXT
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVariantEnabledEXT)(GLuint, GLenum);
#define glIsVariantEnabledEXT _ptrc_glIsVariantEnabledEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSetInvariantEXT)(GLuint, GLenum, const GLvoid *);
#define glSetInvariantEXT _ptrc_glSetInvariantEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSetLocalConstantEXT)(GLuint, GLenum, const GLvoid *);
#define glSetLocalConstantEXT _ptrc_glSetLocalConstantEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderOp1EXT)(GLenum, GLuint, GLuint);
#define glShaderOp1EXT _ptrc_glShaderOp1EXT
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderOp2EXT)(GLenum, GLuint, GLuint, GLuint);
#define glShaderOp2EXT _ptrc_glShaderOp2EXT
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderOp3EXT)(GLenum, GLuint, GLuint, GLuint, GLuint);
#define glShaderOp3EXT _ptrc_glShaderOp3EXT
extern void (CODEGEN_FUNCPTR *_ptrc_glSwizzleEXT)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum);
#define glSwizzleEXT _ptrc_glSwizzleEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantPointerEXT)(GLuint, GLenum, GLuint, const GLvoid *);
#define glVariantPointerEXT _ptrc_glVariantPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantbvEXT)(GLuint, const GLbyte *);
#define glVariantbvEXT _ptrc_glVariantbvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantdvEXT)(GLuint, const GLdouble *);
#define glVariantdvEXT _ptrc_glVariantdvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantfvEXT)(GLuint, const GLfloat *);
#define glVariantfvEXT _ptrc_glVariantfvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantivEXT)(GLuint, const GLint *);
#define glVariantivEXT _ptrc_glVariantivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantsvEXT)(GLuint, const GLshort *);
#define glVariantsvEXT _ptrc_glVariantsvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantubvEXT)(GLuint, const GLubyte *);
#define glVariantubvEXT _ptrc_glVariantubvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantuivEXT)(GLuint, const GLuint *);
#define glVariantuivEXT _ptrc_glVariantuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVariantusvEXT)(GLuint, const GLushort *);
#define glVariantusvEXT _ptrc_glVariantusvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glWriteMaskEXT)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum);
#define glWriteMaskEXT _ptrc_glWriteMaskEXT
#endif /*GL_EXT_vertex_shader*/ 

#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting 1
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexWeightPointerEXT)(GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexWeightPointerEXT _ptrc_glVertexWeightPointerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexWeightfEXT)(GLfloat);
#define glVertexWeightfEXT _ptrc_glVertexWeightfEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexWeightfvEXT)(const GLfloat *);
#define glVertexWeightfvEXT _ptrc_glVertexWeightfvEXT
#endif /*GL_EXT_vertex_weighting*/ 

#ifndef GL_EXT_x11_sync_object
#define GL_EXT_x11_sync_object 1
extern GLsync (CODEGEN_FUNCPTR *_ptrc_glImportSyncEXT)(GLenum, GLintptr, GLbitfield);
#define glImportSyncEXT _ptrc_glImportSyncEXT
#endif /*GL_EXT_x11_sync_object*/ 

#ifndef GL_GREMEDY_frame_terminator
#define GL_GREMEDY_frame_terminator 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFrameTerminatorGREMEDY)();
#define glFrameTerminatorGREMEDY _ptrc_glFrameTerminatorGREMEDY
#endif /*GL_GREMEDY_frame_terminator*/ 

#ifndef GL_GREMEDY_string_marker
#define GL_GREMEDY_string_marker 1
extern void (CODEGEN_FUNCPTR *_ptrc_glStringMarkerGREMEDY)(GLsizei, const GLvoid *);
#define glStringMarkerGREMEDY _ptrc_glStringMarkerGREMEDY
#endif /*GL_GREMEDY_string_marker*/ 


#ifndef GL_HP_image_transform
#define GL_HP_image_transform 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetImageTransformParameterfvHP)(GLenum, GLenum, GLfloat *);
#define glGetImageTransformParameterfvHP _ptrc_glGetImageTransformParameterfvHP
extern void (CODEGEN_FUNCPTR *_ptrc_glGetImageTransformParameterivHP)(GLenum, GLenum, GLint *);
#define glGetImageTransformParameterivHP _ptrc_glGetImageTransformParameterivHP
extern void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameterfHP)(GLenum, GLenum, GLfloat);
#define glImageTransformParameterfHP _ptrc_glImageTransformParameterfHP
extern void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameterfvHP)(GLenum, GLenum, const GLfloat *);
#define glImageTransformParameterfvHP _ptrc_glImageTransformParameterfvHP
extern void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameteriHP)(GLenum, GLenum, GLint);
#define glImageTransformParameteriHP _ptrc_glImageTransformParameteriHP
extern void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameterivHP)(GLenum, GLenum, const GLint *);
#define glImageTransformParameterivHP _ptrc_glImageTransformParameterivHP
#endif /*GL_HP_image_transform*/ 




#ifndef GL_IBM_multimode_draw_arrays
#define GL_IBM_multimode_draw_arrays 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiModeDrawArraysIBM)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint);
#define glMultiModeDrawArraysIBM _ptrc_glMultiModeDrawArraysIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiModeDrawElementsIBM)(const GLenum *, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, GLint);
#define glMultiModeDrawElementsIBM _ptrc_glMultiModeDrawElementsIBM
#endif /*GL_IBM_multimode_draw_arrays*/ 


#ifndef GL_IBM_static_data
#define GL_IBM_static_data 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushStaticDataIBM)(GLenum);
#define glFlushStaticDataIBM _ptrc_glFlushStaticDataIBM
#endif /*GL_IBM_static_data*/ 


#ifndef GL_IBM_vertex_array_lists
#define GL_IBM_vertex_array_lists 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint);
#define glColorPointerListIBM _ptrc_glColorPointerListIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointerListIBM)(GLint, const GLboolean **, GLint);
#define glEdgeFlagPointerListIBM _ptrc_glEdgeFlagPointerListIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointerListIBM)(GLenum, GLint, const GLvoid **, GLint);
#define glFogCoordPointerListIBM _ptrc_glFogCoordPointerListIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexPointerListIBM)(GLenum, GLint, const GLvoid **, GLint);
#define glIndexPointerListIBM _ptrc_glIndexPointerListIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalPointerListIBM)(GLenum, GLint, const GLvoid **, GLint);
#define glNormalPointerListIBM _ptrc_glNormalPointerListIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint);
#define glSecondaryColorPointerListIBM _ptrc_glSecondaryColorPointerListIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint);
#define glTexCoordPointerListIBM _ptrc_glTexCoordPointerListIBM
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint);
#define glVertexPointerListIBM _ptrc_glVertexPointerListIBM
#endif /*GL_IBM_vertex_array_lists*/ 

#ifndef GL_INGR_blend_func_separate
#define GL_INGR_blend_func_separate 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateINGR)(GLenum, GLenum, GLenum, GLenum);
#define glBlendFuncSeparateINGR _ptrc_glBlendFuncSeparateINGR
#endif /*GL_INGR_blend_func_separate*/ 



#ifndef GL_INTEL_map_texture
#define GL_INTEL_map_texture 1
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapTexture2DINTEL)(GLuint, GLint, GLbitfield, const GLint *, const GLenum *);
#define glMapTexture2DINTEL _ptrc_glMapTexture2DINTEL
extern void (CODEGEN_FUNCPTR *_ptrc_glSyncTextureINTEL)(GLuint);
#define glSyncTextureINTEL _ptrc_glSyncTextureINTEL
extern void (CODEGEN_FUNCPTR *_ptrc_glUnmapTexture2DINTEL)(GLuint, GLint);
#define glUnmapTexture2DINTEL _ptrc_glUnmapTexture2DINTEL
#endif /*GL_INTEL_map_texture*/ 

#ifndef GL_INTEL_parallel_arrays
#define GL_INTEL_parallel_arrays 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorPointervINTEL)(GLint, GLenum, const GLvoid **);
#define glColorPointervINTEL _ptrc_glColorPointervINTEL
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalPointervINTEL)(GLenum, const GLvoid **);
#define glNormalPointervINTEL _ptrc_glNormalPointervINTEL
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointervINTEL)(GLint, GLenum, const GLvoid **);
#define glTexCoordPointervINTEL _ptrc_glTexCoordPointervINTEL
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexPointervINTEL)(GLint, GLenum, const GLvoid **);
#define glVertexPointervINTEL _ptrc_glVertexPointervINTEL
#endif /*GL_INTEL_parallel_arrays*/ 




#ifndef GL_MESA_resize_buffers
#define GL_MESA_resize_buffers 1
extern void (CODEGEN_FUNCPTR *_ptrc_glResizeBuffersMESA)();
#define glResizeBuffersMESA _ptrc_glResizeBuffersMESA
#endif /*GL_MESA_resize_buffers*/ 

#ifndef GL_MESA_window_pos
#define GL_MESA_window_pos 1
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dMESA)(GLdouble, GLdouble);
#define glWindowPos2dMESA _ptrc_glWindowPos2dMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dvMESA)(const GLdouble *);
#define glWindowPos2dvMESA _ptrc_glWindowPos2dvMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fMESA)(GLfloat, GLfloat);
#define glWindowPos2fMESA _ptrc_glWindowPos2fMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fvMESA)(const GLfloat *);
#define glWindowPos2fvMESA _ptrc_glWindowPos2fvMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iMESA)(GLint, GLint);
#define glWindowPos2iMESA _ptrc_glWindowPos2iMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2ivMESA)(const GLint *);
#define glWindowPos2ivMESA _ptrc_glWindowPos2ivMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sMESA)(GLshort, GLshort);
#define glWindowPos2sMESA _ptrc_glWindowPos2sMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2svMESA)(const GLshort *);
#define glWindowPos2svMESA _ptrc_glWindowPos2svMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dMESA)(GLdouble, GLdouble, GLdouble);
#define glWindowPos3dMESA _ptrc_glWindowPos3dMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dvMESA)(const GLdouble *);
#define glWindowPos3dvMESA _ptrc_glWindowPos3dvMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fMESA)(GLfloat, GLfloat, GLfloat);
#define glWindowPos3fMESA _ptrc_glWindowPos3fMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fvMESA)(const GLfloat *);
#define glWindowPos3fvMESA _ptrc_glWindowPos3fvMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iMESA)(GLint, GLint, GLint);
#define glWindowPos3iMESA _ptrc_glWindowPos3iMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3ivMESA)(const GLint *);
#define glWindowPos3ivMESA _ptrc_glWindowPos3ivMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sMESA)(GLshort, GLshort, GLshort);
#define glWindowPos3sMESA _ptrc_glWindowPos3sMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3svMESA)(const GLshort *);
#define glWindowPos3svMESA _ptrc_glWindowPos3svMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4dMESA)(GLdouble, GLdouble, GLdouble, GLdouble);
#define glWindowPos4dMESA _ptrc_glWindowPos4dMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4dvMESA)(const GLdouble *);
#define glWindowPos4dvMESA _ptrc_glWindowPos4dvMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4fMESA)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glWindowPos4fMESA _ptrc_glWindowPos4fMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4fvMESA)(const GLfloat *);
#define glWindowPos4fvMESA _ptrc_glWindowPos4fvMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4iMESA)(GLint, GLint, GLint, GLint);
#define glWindowPos4iMESA _ptrc_glWindowPos4iMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4ivMESA)(const GLint *);
#define glWindowPos4ivMESA _ptrc_glWindowPos4ivMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4sMESA)(GLshort, GLshort, GLshort, GLshort);
#define glWindowPos4sMESA _ptrc_glWindowPos4sMESA
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4svMESA)(const GLshort *);
#define glWindowPos4svMESA _ptrc_glWindowPos4svMESA
#endif /*GL_MESA_window_pos*/ 


#ifndef GL_NVX_conditional_render
#define GL_NVX_conditional_render 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNVX)(GLuint);
#define glBeginConditionalRenderNVX _ptrc_glBeginConditionalRenderNVX
extern void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNVX)();
#define glEndConditionalRenderNVX _ptrc_glEndConditionalRenderNVX
#endif /*GL_NVX_conditional_render*/ 

#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectBindlessNV)(GLenum, const GLvoid *, GLsizei, GLsizei, GLint);
#define glMultiDrawArraysIndirectBindlessNV _ptrc_glMultiDrawArraysIndirectBindlessNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectBindlessNV)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei, GLint);
#define glMultiDrawElementsIndirectBindlessNV _ptrc_glMultiDrawElementsIndirectBindlessNV
#endif /*GL_NV_bindless_multi_draw_indirect*/ 

#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1
extern GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetImageHandleNV)(GLuint, GLint, GLboolean, GLint, GLenum);
#define glGetImageHandleNV _ptrc_glGetImageHandleNV
extern GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureHandleNV)(GLuint);
#define glGetTextureHandleNV _ptrc_glGetTextureHandleNV
extern GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureSamplerHandleNV)(GLuint, GLuint);
#define glGetTextureSamplerHandleNV _ptrc_glGetTextureSamplerHandleNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsImageHandleResidentNV)(GLuint64);
#define glIsImageHandleResidentNV _ptrc_glIsImageHandleResidentNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureHandleResidentNV)(GLuint64);
#define glIsTextureHandleResidentNV _ptrc_glIsTextureHandleResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleNonResidentNV)(GLuint64);
#define glMakeImageHandleNonResidentNV _ptrc_glMakeImageHandleNonResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleResidentNV)(GLuint64, GLenum);
#define glMakeImageHandleResidentNV _ptrc_glMakeImageHandleResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleNonResidentNV)(GLuint64);
#define glMakeTextureHandleNonResidentNV _ptrc_glMakeTextureHandleNonResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleResidentNV)(GLuint64);
#define glMakeTextureHandleResidentNV _ptrc_glMakeTextureHandleResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64NV)(GLuint, GLint, GLuint64);
#define glProgramUniformHandleui64NV _ptrc_glProgramUniformHandleui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64vNV)(GLuint, GLint, GLsizei, const GLuint64 *);
#define glProgramUniformHandleui64vNV _ptrc_glProgramUniformHandleui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64NV)(GLint, GLuint64);
#define glUniformHandleui64NV _ptrc_glUniformHandleui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64vNV)(GLint, GLsizei, const GLuint64 *);
#define glUniformHandleui64vNV _ptrc_glUniformHandleui64vNV
#endif /*GL_NV_bindless_texture*/ 

#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendBarrierNV)();
#define glBlendBarrierNV _ptrc_glBlendBarrierNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendParameteriNV)(GLenum, GLint);
#define glBlendParameteriNV _ptrc_glBlendParameteriNV
#endif /*GL_NV_blend_equation_advanced*/ 




#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNV)(GLuint, GLenum);
#define glBeginConditionalRenderNV _ptrc_glBeginConditionalRenderNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNV)();
#define glEndConditionalRenderNV _ptrc_glEndConditionalRenderNV
#endif /*GL_NV_conditional_render*/ 


#ifndef GL_NV_copy_image
#define GL_NV_copy_image 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubDataNV)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
#define glCopyImageSubDataNV _ptrc_glCopyImageSubDataNV
#endif /*GL_NV_copy_image*/ 


#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthdNV)(GLdouble);
#define glClearDepthdNV _ptrc_glClearDepthdNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsdNV)(GLdouble, GLdouble);
#define glDepthBoundsdNV _ptrc_glDepthBoundsdNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangedNV)(GLdouble, GLdouble);
#define glDepthRangedNV _ptrc_glDepthRangedNV
#endif /*GL_NV_depth_buffer_float*/ 


#ifndef GL_NV_draw_texture
#define GL_NV_draw_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTextureNV)(GLuint, GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glDrawTextureNV _ptrc_glDrawTextureNV
#endif /*GL_NV_draw_texture*/ 

#ifndef GL_NV_evaluators
#define GL_NV_evaluators 1
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalMapsNV)(GLenum, GLenum);
#define glEvalMapsNV _ptrc_glEvalMapsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapAttribParameterfvNV)(GLenum, GLuint, GLenum, GLfloat *);
#define glGetMapAttribParameterfvNV _ptrc_glGetMapAttribParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapAttribParameterivNV)(GLenum, GLuint, GLenum, GLint *);
#define glGetMapAttribParameterivNV _ptrc_glGetMapAttribParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapControlPointsNV)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid *);
#define glGetMapControlPointsNV _ptrc_glGetMapControlPointsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapParameterfvNV)(GLenum, GLenum, GLfloat *);
#define glGetMapParameterfvNV _ptrc_glGetMapParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapParameterivNV)(GLenum, GLenum, GLint *);
#define glGetMapParameterivNV _ptrc_glGetMapParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMapControlPointsNV)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid *);
#define glMapControlPointsNV _ptrc_glMapControlPointsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMapParameterfvNV)(GLenum, GLenum, const GLfloat *);
#define glMapParameterfvNV _ptrc_glMapParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMapParameterivNV)(GLenum, GLenum, const GLint *);
#define glMapParameterivNV _ptrc_glMapParameterivNV
#endif /*GL_NV_evaluators*/ 

#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefvNV)(GLenum, GLuint, GLfloat *);
#define glGetMultisamplefvNV _ptrc_glGetMultisamplefvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskIndexedNV)(GLuint, GLbitfield);
#define glSampleMaskIndexedNV _ptrc_glSampleMaskIndexedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexRenderbufferNV)(GLenum, GLuint);
#define glTexRenderbufferNV _ptrc_glTexRenderbufferNV
#endif /*GL_NV_explicit_multisample*/ 

#ifndef GL_NV_fence
#define GL_NV_fence 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFencesNV)(GLsizei, const GLuint *);
#define glDeleteFencesNV _ptrc_glDeleteFencesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFinishFenceNV)(GLuint);
#define glFinishFenceNV _ptrc_glFinishFenceNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFencesNV)(GLsizei, GLuint *);
#define glGenFencesNV _ptrc_glGenFencesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFenceivNV)(GLuint, GLenum, GLint *);
#define glGetFenceivNV _ptrc_glGetFenceivNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFenceNV)(GLuint);
#define glIsFenceNV _ptrc_glIsFenceNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSetFenceNV)(GLuint, GLenum);
#define glSetFenceNV _ptrc_glSetFenceNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestFenceNV)(GLuint);
#define glTestFenceNV _ptrc_glTestFenceNV
#endif /*GL_NV_fence*/ 



#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterdvNV)(GLuint, GLsizei, const GLubyte *, GLdouble *);
#define glGetProgramNamedParameterdvNV _ptrc_glGetProgramNamedParameterdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterfvNV)(GLuint, GLsizei, const GLubyte *, GLfloat *);
#define glGetProgramNamedParameterfvNV _ptrc_glGetProgramNamedParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dNV)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramNamedParameter4dNV _ptrc_glProgramNamedParameter4dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dvNV)(GLuint, GLsizei, const GLubyte *, const GLdouble *);
#define glProgramNamedParameter4dvNV _ptrc_glProgramNamedParameter4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fNV)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramNamedParameter4fNV _ptrc_glProgramNamedParameter4fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fvNV)(GLuint, GLsizei, const GLubyte *, const GLfloat *);
#define glProgramNamedParameter4fvNV _ptrc_glProgramNamedParameter4fvNV
#endif /*GL_NV_fragment_program*/ 




#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleCoverageNV)(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei);
#define glRenderbufferStorageMultisampleCoverageNV _ptrc_glRenderbufferStorageMultisampleCoverageNV
#endif /*GL_NV_framebuffer_multisample_coverage*/ 

#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureEXT)(GLenum, GLenum, GLuint, GLint);
#define glFramebufferTextureEXT _ptrc_glFramebufferTextureEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureFaceEXT)(GLenum, GLenum, GLuint, GLint, GLenum);
#define glFramebufferTextureFaceEXT _ptrc_glFramebufferTextureFaceEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerEXT)(GLenum, GLenum, GLuint, GLint, GLint);
#define glFramebufferTextureLayerEXT _ptrc_glFramebufferTextureLayerEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramVertexLimitNV)(GLenum, GLint);
#define glProgramVertexLimitNV _ptrc_glProgramVertexLimitNV
#endif /*GL_NV_geometry_program4*/ 


#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIivNV)(GLenum, GLuint, GLint *);
#define glGetProgramEnvParameterIivNV _ptrc_glGetProgramEnvParameterIivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIuivNV)(GLenum, GLuint, GLuint *);
#define glGetProgramEnvParameterIuivNV _ptrc_glGetProgramEnvParameterIuivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIivNV)(GLenum, GLuint, GLint *);
#define glGetProgramLocalParameterIivNV _ptrc_glGetProgramLocalParameterIivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIuivNV)(GLenum, GLuint, GLuint *);
#define glGetProgramLocalParameterIuivNV _ptrc_glGetProgramLocalParameterIuivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4iNV)(GLenum, GLuint, GLint, GLint, GLint, GLint);
#define glProgramEnvParameterI4iNV _ptrc_glProgramEnvParameterI4iNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4ivNV)(GLenum, GLuint, const GLint *);
#define glProgramEnvParameterI4ivNV _ptrc_glProgramEnvParameterI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uiNV)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glProgramEnvParameterI4uiNV _ptrc_glProgramEnvParameterI4uiNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uivNV)(GLenum, GLuint, const GLuint *);
#define glProgramEnvParameterI4uivNV _ptrc_glProgramEnvParameterI4uivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4ivNV)(GLenum, GLuint, GLsizei, const GLint *);
#define glProgramEnvParametersI4ivNV _ptrc_glProgramEnvParametersI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4uivNV)(GLenum, GLuint, GLsizei, const GLuint *);
#define glProgramEnvParametersI4uivNV _ptrc_glProgramEnvParametersI4uivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4iNV)(GLenum, GLuint, GLint, GLint, GLint, GLint);
#define glProgramLocalParameterI4iNV _ptrc_glProgramLocalParameterI4iNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4ivNV)(GLenum, GLuint, const GLint *);
#define glProgramLocalParameterI4ivNV _ptrc_glProgramLocalParameterI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uiNV)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint);
#define glProgramLocalParameterI4uiNV _ptrc_glProgramLocalParameterI4uiNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uivNV)(GLenum, GLuint, const GLuint *);
#define glProgramLocalParameterI4uivNV _ptrc_glProgramLocalParameterI4uivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4ivNV)(GLenum, GLuint, GLsizei, const GLint *);
#define glProgramLocalParametersI4ivNV _ptrc_glProgramLocalParametersI4ivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4uivNV)(GLenum, GLuint, GLsizei, const GLuint *);
#define glProgramLocalParametersI4uivNV _ptrc_glProgramLocalParametersI4uivNV
#endif /*GL_NV_gpu_program4*/ 

#ifndef GL_NV_gpu_program5
#define GL_NV_gpu_program5 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramSubroutineParameteruivNV)(GLenum, GLuint, GLuint *);
#define glGetProgramSubroutineParameteruivNV _ptrc_glGetProgramSubroutineParameteruivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramSubroutineParametersuivNV)(GLenum, GLsizei, const GLuint *);
#define glProgramSubroutineParametersuivNV _ptrc_glProgramSubroutineParametersuivNV
#endif /*GL_NV_gpu_program5*/ 


#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformi64vNV)(GLuint, GLint, GLint64EXT *);
#define glGetUniformi64vNV _ptrc_glGetUniformi64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64NV)(GLuint, GLint, GLint64EXT);
#define glProgramUniform1i64NV _ptrc_glProgramUniform1i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *);
#define glProgramUniform1i64vNV _ptrc_glProgramUniform1i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64NV)(GLuint, GLint, GLuint64EXT);
#define glProgramUniform1ui64NV _ptrc_glProgramUniform1ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *);
#define glProgramUniform1ui64vNV _ptrc_glProgramUniform1ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64NV)(GLuint, GLint, GLint64EXT, GLint64EXT);
#define glProgramUniform2i64NV _ptrc_glProgramUniform2i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *);
#define glProgramUniform2i64vNV _ptrc_glProgramUniform2i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64NV)(GLuint, GLint, GLuint64EXT, GLuint64EXT);
#define glProgramUniform2ui64NV _ptrc_glProgramUniform2ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *);
#define glProgramUniform2ui64vNV _ptrc_glProgramUniform2ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64NV)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT);
#define glProgramUniform3i64NV _ptrc_glProgramUniform3i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *);
#define glProgramUniform3i64vNV _ptrc_glProgramUniform3i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64NV)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT);
#define glProgramUniform3ui64NV _ptrc_glProgramUniform3ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *);
#define glProgramUniform3ui64vNV _ptrc_glProgramUniform3ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64NV)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT);
#define glProgramUniform4i64NV _ptrc_glProgramUniform4i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *);
#define glProgramUniform4i64vNV _ptrc_glProgramUniform4i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64NV)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT);
#define glProgramUniform4ui64NV _ptrc_glProgramUniform4ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *);
#define glProgramUniform4ui64vNV _ptrc_glProgramUniform4ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64NV)(GLint, GLint64EXT);
#define glUniform1i64NV _ptrc_glUniform1i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64vNV)(GLint, GLsizei, const GLint64EXT *);
#define glUniform1i64vNV _ptrc_glUniform1i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64NV)(GLint, GLuint64EXT);
#define glUniform1ui64NV _ptrc_glUniform1ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64vNV)(GLint, GLsizei, const GLuint64EXT *);
#define glUniform1ui64vNV _ptrc_glUniform1ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64NV)(GLint, GLint64EXT, GLint64EXT);
#define glUniform2i64NV _ptrc_glUniform2i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64vNV)(GLint, GLsizei, const GLint64EXT *);
#define glUniform2i64vNV _ptrc_glUniform2i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64NV)(GLint, GLuint64EXT, GLuint64EXT);
#define glUniform2ui64NV _ptrc_glUniform2ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64vNV)(GLint, GLsizei, const GLuint64EXT *);
#define glUniform2ui64vNV _ptrc_glUniform2ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64NV)(GLint, GLint64EXT, GLint64EXT, GLint64EXT);
#define glUniform3i64NV _ptrc_glUniform3i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64vNV)(GLint, GLsizei, const GLint64EXT *);
#define glUniform3i64vNV _ptrc_glUniform3i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64NV)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT);
#define glUniform3ui64NV _ptrc_glUniform3ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64vNV)(GLint, GLsizei, const GLuint64EXT *);
#define glUniform3ui64vNV _ptrc_glUniform3ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64NV)(GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT);
#define glUniform4i64NV _ptrc_glUniform4i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64vNV)(GLint, GLsizei, const GLint64EXT *);
#define glUniform4i64vNV _ptrc_glUniform4i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64NV)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT);
#define glUniform4ui64NV _ptrc_glUniform4ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64vNV)(GLint, GLsizei, const GLuint64EXT *);
#define glUniform4ui64vNV _ptrc_glUniform4ui64vNV
#endif /*GL_NV_gpu_shader5*/ 

#ifndef GL_NV_half_float
#define GL_NV_half_float 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3hNV)(GLhalfNV, GLhalfNV, GLhalfNV);
#define glColor3hNV _ptrc_glColor3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3hvNV)(const GLhalfNV *);
#define glColor3hvNV _ptrc_glColor3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4hNV)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
#define glColor4hNV _ptrc_glColor4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4hvNV)(const GLhalfNV *);
#define glColor4hvNV _ptrc_glColor4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhNV)(GLhalfNV);
#define glFogCoordhNV _ptrc_glFogCoordhNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhvNV)(const GLhalfNV *);
#define glFogCoordhvNV _ptrc_glFogCoordhvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hNV)(GLenum, GLhalfNV);
#define glMultiTexCoord1hNV _ptrc_glMultiTexCoord1hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hvNV)(GLenum, const GLhalfNV *);
#define glMultiTexCoord1hvNV _ptrc_glMultiTexCoord1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hNV)(GLenum, GLhalfNV, GLhalfNV);
#define glMultiTexCoord2hNV _ptrc_glMultiTexCoord2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hvNV)(GLenum, const GLhalfNV *);
#define glMultiTexCoord2hvNV _ptrc_glMultiTexCoord2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hNV)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV);
#define glMultiTexCoord3hNV _ptrc_glMultiTexCoord3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hvNV)(GLenum, const GLhalfNV *);
#define glMultiTexCoord3hvNV _ptrc_glMultiTexCoord3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hNV)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
#define glMultiTexCoord4hNV _ptrc_glMultiTexCoord4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hvNV)(GLenum, const GLhalfNV *);
#define glMultiTexCoord4hvNV _ptrc_glMultiTexCoord4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3hNV)(GLhalfNV, GLhalfNV, GLhalfNV);
#define glNormal3hNV _ptrc_glNormal3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3hvNV)(const GLhalfNV *);
#define glNormal3hvNV _ptrc_glNormal3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hNV)(GLhalfNV, GLhalfNV, GLhalfNV);
#define glSecondaryColor3hNV _ptrc_glSecondaryColor3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hvNV)(const GLhalfNV *);
#define glSecondaryColor3hvNV _ptrc_glSecondaryColor3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hNV)(GLhalfNV);
#define glTexCoord1hNV _ptrc_glTexCoord1hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hvNV)(const GLhalfNV *);
#define glTexCoord1hvNV _ptrc_glTexCoord1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hNV)(GLhalfNV, GLhalfNV);
#define glTexCoord2hNV _ptrc_glTexCoord2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hvNV)(const GLhalfNV *);
#define glTexCoord2hvNV _ptrc_glTexCoord2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hNV)(GLhalfNV, GLhalfNV, GLhalfNV);
#define glTexCoord3hNV _ptrc_glTexCoord3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hvNV)(const GLhalfNV *);
#define glTexCoord3hvNV _ptrc_glTexCoord3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hNV)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
#define glTexCoord4hNV _ptrc_glTexCoord4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hvNV)(const GLhalfNV *);
#define glTexCoord4hvNV _ptrc_glTexCoord4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2hNV)(GLhalfNV, GLhalfNV);
#define glVertex2hNV _ptrc_glVertex2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2hvNV)(const GLhalfNV *);
#define glVertex2hvNV _ptrc_glVertex2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3hNV)(GLhalfNV, GLhalfNV, GLhalfNV);
#define glVertex3hNV _ptrc_glVertex3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3hvNV)(const GLhalfNV *);
#define glVertex3hvNV _ptrc_glVertex3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4hNV)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
#define glVertex4hNV _ptrc_glVertex4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4hvNV)(const GLhalfNV *);
#define glVertex4hvNV _ptrc_glVertex4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hNV)(GLuint, GLhalfNV);
#define glVertexAttrib1hNV _ptrc_glVertexAttrib1hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hvNV)(GLuint, const GLhalfNV *);
#define glVertexAttrib1hvNV _ptrc_glVertexAttrib1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hNV)(GLuint, GLhalfNV, GLhalfNV);
#define glVertexAttrib2hNV _ptrc_glVertexAttrib2hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hvNV)(GLuint, const GLhalfNV *);
#define glVertexAttrib2hvNV _ptrc_glVertexAttrib2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hNV)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV);
#define glVertexAttrib3hNV _ptrc_glVertexAttrib3hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hvNV)(GLuint, const GLhalfNV *);
#define glVertexAttrib3hvNV _ptrc_glVertexAttrib3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hNV)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV);
#define glVertexAttrib4hNV _ptrc_glVertexAttrib4hNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hvNV)(GLuint, const GLhalfNV *);
#define glVertexAttrib4hvNV _ptrc_glVertexAttrib4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1hvNV)(GLuint, GLsizei, const GLhalfNV *);
#define glVertexAttribs1hvNV _ptrc_glVertexAttribs1hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2hvNV)(GLuint, GLsizei, const GLhalfNV *);
#define glVertexAttribs2hvNV _ptrc_glVertexAttribs2hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3hvNV)(GLuint, GLsizei, const GLhalfNV *);
#define glVertexAttribs3hvNV _ptrc_glVertexAttribs3hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4hvNV)(GLuint, GLsizei, const GLhalfNV *);
#define glVertexAttribs4hvNV _ptrc_glVertexAttribs4hvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthNV)(GLhalfNV);
#define glVertexWeighthNV _ptrc_glVertexWeighthNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthvNV)(const GLhalfNV *);
#define glVertexWeighthvNV _ptrc_glVertexWeighthvNV
#endif /*GL_NV_half_float*/ 




#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginOcclusionQueryNV)(GLuint);
#define glBeginOcclusionQueryNV _ptrc_glBeginOcclusionQueryNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteOcclusionQueriesNV)(GLsizei, const GLuint *);
#define glDeleteOcclusionQueriesNV _ptrc_glDeleteOcclusionQueriesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndOcclusionQueryNV)();
#define glEndOcclusionQueryNV _ptrc_glEndOcclusionQueryNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenOcclusionQueriesNV)(GLsizei, GLuint *);
#define glGenOcclusionQueriesNV _ptrc_glGenOcclusionQueriesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryivNV)(GLuint, GLenum, GLint *);
#define glGetOcclusionQueryivNV _ptrc_glGetOcclusionQueryivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryuivNV)(GLuint, GLenum, GLuint *);
#define glGetOcclusionQueryuivNV _ptrc_glGetOcclusionQueryuivNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsOcclusionQueryNV)(GLuint);
#define glIsOcclusionQueryNV _ptrc_glIsOcclusionQueryNV
#endif /*GL_NV_occlusion_query*/ 


#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIivNV)(GLenum, GLuint, GLuint, GLsizei, const GLint *);
#define glProgramBufferParametersIivNV _ptrc_glProgramBufferParametersIivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIuivNV)(GLenum, GLuint, GLuint, GLsizei, const GLuint *);
#define glProgramBufferParametersIuivNV _ptrc_glProgramBufferParametersIuivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersfvNV)(GLenum, GLuint, GLuint, GLsizei, const GLfloat *);
#define glProgramBufferParametersfvNV _ptrc_glProgramBufferParametersfvNV
#endif /*GL_NV_parameter_buffer_object*/ 


#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyPathNV)(GLuint, GLuint);
#define glCopyPathNV _ptrc_glCopyPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat *);
#define glCoverFillPathInstancedNV _ptrc_glCoverFillPathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathNV)(GLuint, GLenum);
#define glCoverFillPathNV _ptrc_glCoverFillPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat *);
#define glCoverStrokePathInstancedNV _ptrc_glCoverStrokePathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathNV)(GLuint, GLenum);
#define glCoverStrokePathNV _ptrc_glCoverStrokePathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeletePathsNV)(GLuint, GLsizei);
#define glDeletePathsNV _ptrc_glDeletePathsNV
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGenPathsNV)(GLsizei);
#define glGenPathsNV _ptrc_glGenPathsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenfvNV)(GLenum, GLenum, GLfloat *);
#define glGetPathColorGenfvNV _ptrc_glGetPathColorGenfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenivNV)(GLenum, GLenum, GLint *);
#define glGetPathColorGenivNV _ptrc_glGetPathColorGenivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathCommandsNV)(GLuint, GLubyte *);
#define glGetPathCommandsNV _ptrc_glGetPathCommandsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathCoordsNV)(GLuint, GLfloat *);
#define glGetPathCoordsNV _ptrc_glGetPathCoordsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathDashArrayNV)(GLuint, GLfloat *);
#define glGetPathDashArrayNV _ptrc_glGetPathDashArrayNV
extern GLfloat (CODEGEN_FUNCPTR *_ptrc_glGetPathLengthNV)(GLuint, GLsizei, GLsizei);
#define glGetPathLengthNV _ptrc_glGetPathLengthNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricRangeNV)(GLbitfield, GLuint, GLsizei, GLsizei, GLfloat *);
#define glGetPathMetricRangeNV _ptrc_glGetPathMetricRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricsNV)(GLbitfield, GLsizei, GLenum, const GLvoid *, GLuint, GLsizei, GLfloat *);
#define glGetPathMetricsNV _ptrc_glGetPathMetricsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterfvNV)(GLuint, GLenum, GLfloat *);
#define glGetPathParameterfvNV _ptrc_glGetPathParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterivNV)(GLuint, GLenum, GLint *);
#define glGetPathParameterivNV _ptrc_glGetPathParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathSpacingNV)(GLenum, GLsizei, GLenum, const GLvoid *, GLuint, GLfloat, GLfloat, GLenum, GLfloat *);
#define glGetPathSpacingNV _ptrc_glGetPathSpacingNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenfvNV)(GLenum, GLenum, GLfloat *);
#define glGetPathTexGenfvNV _ptrc_glGetPathTexGenfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenivNV)(GLenum, GLenum, GLint *);
#define glGetPathTexGenivNV _ptrc_glGetPathTexGenivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glInterpolatePathsNV)(GLuint, GLuint, GLuint, GLfloat);
#define glInterpolatePathsNV _ptrc_glInterpolatePathsNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPathNV)(GLuint);
#define glIsPathNV _ptrc_glIsPathNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInFillPathNV)(GLuint, GLuint, GLfloat, GLfloat);
#define glIsPointInFillPathNV _ptrc_glIsPointInFillPathNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInStrokePathNV)(GLuint, GLfloat, GLfloat);
#define glIsPointInStrokePathNV _ptrc_glIsPointInStrokePathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathColorGenNV)(GLenum, GLenum, GLenum, const GLfloat *);
#define glPathColorGenNV _ptrc_glPathColorGenNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathCommandsNV)(GLuint, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid *);
#define glPathCommandsNV _ptrc_glPathCommandsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathCoordsNV)(GLuint, GLsizei, GLenum, const GLvoid *);
#define glPathCoordsNV _ptrc_glPathCoordsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathCoverDepthFuncNV)(GLenum);
#define glPathCoverDepthFuncNV _ptrc_glPathCoverDepthFuncNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathDashArrayNV)(GLuint, GLsizei, const GLfloat *);
#define glPathDashArrayNV _ptrc_glPathDashArrayNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathFogGenNV)(GLenum);
#define glPathFogGenNV _ptrc_glPathFogGenNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphRangeNV)(GLuint, GLenum, const GLvoid *, GLbitfield, GLuint, GLsizei, GLenum, GLuint, GLfloat);
#define glPathGlyphRangeNV _ptrc_glPathGlyphRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphsNV)(GLuint, GLenum, const GLvoid *, GLbitfield, GLsizei, GLenum, const GLvoid *, GLenum, GLuint, GLfloat);
#define glPathGlyphsNV _ptrc_glPathGlyphsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfNV)(GLuint, GLenum, GLfloat);
#define glPathParameterfNV _ptrc_glPathParameterfNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfvNV)(GLuint, GLenum, const GLfloat *);
#define glPathParameterfvNV _ptrc_glPathParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameteriNV)(GLuint, GLenum, GLint);
#define glPathParameteriNV _ptrc_glPathParameteriNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathParameterivNV)(GLuint, GLenum, const GLint *);
#define glPathParameterivNV _ptrc_glPathParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathStencilDepthOffsetNV)(GLfloat, GLfloat);
#define glPathStencilDepthOffsetNV _ptrc_glPathStencilDepthOffsetNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathStencilFuncNV)(GLenum, GLint, GLuint);
#define glPathStencilFuncNV _ptrc_glPathStencilFuncNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathStringNV)(GLuint, GLenum, GLsizei, const GLvoid *);
#define glPathStringNV _ptrc_glPathStringNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathSubCommandsNV)(GLuint, GLsizei, GLsizei, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid *);
#define glPathSubCommandsNV _ptrc_glPathSubCommandsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathSubCoordsNV)(GLuint, GLsizei, GLsizei, GLenum, const GLvoid *);
#define glPathSubCoordsNV _ptrc_glPathSubCoordsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPathTexGenNV)(GLenum, GLenum, GLint, const GLfloat *);
#define glPathTexGenNV _ptrc_glPathTexGenNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glPointAlongPathNV)(GLuint, GLsizei, GLsizei, GLfloat, GLfloat *, GLfloat *, GLfloat *, GLfloat *);
#define glPointAlongPathNV _ptrc_glPointAlongPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLuint, GLenum, const GLfloat *);
#define glStencilFillPathInstancedNV _ptrc_glStencilFillPathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathNV)(GLuint, GLenum, GLuint);
#define glStencilFillPathNV _ptrc_glStencilFillPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLint, GLuint, GLenum, const GLfloat *);
#define glStencilStrokePathInstancedNV _ptrc_glStencilStrokePathInstancedNV
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathNV)(GLuint, GLint, GLuint);
#define glStencilStrokePathNV _ptrc_glStencilStrokePathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformPathNV)(GLuint, GLuint, GLenum, const GLfloat *);
#define glTransformPathNV _ptrc_glTransformPathNV
extern void (CODEGEN_FUNCPTR *_ptrc_glWeightPathsNV)(GLuint, GLsizei, const GLuint *, const GLfloat *);
#define glWeightPathsNV _ptrc_glWeightPathsNV
#endif /*GL_NV_path_rendering*/ 

#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushPixelDataRangeNV)(GLenum);
#define glFlushPixelDataRangeNV _ptrc_glFlushPixelDataRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelDataRangeNV)(GLenum, GLsizei, const GLvoid *);
#define glPixelDataRangeNV _ptrc_glPixelDataRangeNV
#endif /*GL_NV_pixel_data_range*/ 

#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriNV)(GLenum, GLint);
#define glPointParameteriNV _ptrc_glPointParameteriNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterivNV)(GLenum, const GLint *);
#define glPointParameterivNV _ptrc_glPointParameterivNV
#endif /*GL_NV_point_sprite*/ 

#ifndef GL_NV_present_video
#define GL_NV_present_video 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoi64vNV)(GLuint, GLenum, GLint64EXT *);
#define glGetVideoi64vNV _ptrc_glGetVideoi64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoivNV)(GLuint, GLenum, GLint *);
#define glGetVideoivNV _ptrc_glGetVideoivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoui64vNV)(GLuint, GLenum, GLuint64EXT *);
#define glGetVideoui64vNV _ptrc_glGetVideoui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideouivNV)(GLuint, GLenum, GLuint *);
#define glGetVideouivNV _ptrc_glGetVideouivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPresentFrameDualFillNV)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint);
#define glPresentFrameDualFillNV _ptrc_glPresentFrameDualFillNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPresentFrameKeyedNV)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLuint, GLenum, GLuint, GLuint);
#define glPresentFrameKeyedNV _ptrc_glPresentFrameKeyedNV
#endif /*GL_NV_present_video*/ 

#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndexNV)(GLuint);
#define glPrimitiveRestartIndexNV _ptrc_glPrimitiveRestartIndexNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartNV)();
#define glPrimitiveRestartNV _ptrc_glPrimitiveRestartNV
#endif /*GL_NV_primitive_restart*/ 

#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerInputNV)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum);
#define glCombinerInputNV _ptrc_glCombinerInputNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerOutputNV)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean);
#define glCombinerOutputNV _ptrc_glCombinerOutputNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfNV)(GLenum, GLfloat);
#define glCombinerParameterfNV _ptrc_glCombinerParameterfNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfvNV)(GLenum, const GLfloat *);
#define glCombinerParameterfvNV _ptrc_glCombinerParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameteriNV)(GLenum, GLint);
#define glCombinerParameteriNV _ptrc_glCombinerParameteriNV
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterivNV)(GLenum, const GLint *);
#define glCombinerParameterivNV _ptrc_glCombinerParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFinalCombinerInputNV)(GLenum, GLenum, GLenum, GLenum);
#define glFinalCombinerInputNV _ptrc_glFinalCombinerInputNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterfvNV)(GLenum, GLenum, GLenum, GLenum, GLfloat *);
#define glGetCombinerInputParameterfvNV _ptrc_glGetCombinerInputParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterivNV)(GLenum, GLenum, GLenum, GLenum, GLint *);
#define glGetCombinerInputParameterivNV _ptrc_glGetCombinerInputParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterfvNV)(GLenum, GLenum, GLenum, GLfloat *);
#define glGetCombinerOutputParameterfvNV _ptrc_glGetCombinerOutputParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterivNV)(GLenum, GLenum, GLenum, GLint *);
#define glGetCombinerOutputParameterivNV _ptrc_glGetCombinerOutputParameterivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterfvNV)(GLenum, GLenum, GLfloat *);
#define glGetFinalCombinerInputParameterfvNV _ptrc_glGetFinalCombinerInputParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterivNV)(GLenum, GLenum, GLint *);
#define glGetFinalCombinerInputParameterivNV _ptrc_glGetFinalCombinerInputParameterivNV
#endif /*GL_NV_register_combiners*/ 

#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glCombinerStageParameterfvNV)(GLenum, GLenum, const GLfloat *);
#define glCombinerStageParameterfvNV _ptrc_glCombinerStageParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerStageParameterfvNV)(GLenum, GLenum, GLfloat *);
#define glGetCombinerStageParameterfvNV _ptrc_glGetCombinerStageParameterfvNV
#endif /*GL_NV_register_combiners2*/ 



#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterui64vNV)(GLenum, GLenum, GLuint64EXT *);
#define glGetBufferParameterui64vNV _ptrc_glGetBufferParameterui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64vNV)(GLenum, GLuint64EXT *);
#define glGetIntegerui64vNV _ptrc_glGetIntegerui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterui64vNV)(GLuint, GLenum, GLuint64EXT *);
#define glGetNamedBufferParameterui64vNV _ptrc_glGetNamedBufferParameterui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformui64vNV)(GLuint, GLint, GLuint64EXT *);
#define glGetUniformui64vNV _ptrc_glGetUniformui64vNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferResidentNV)(GLenum);
#define glIsBufferResidentNV _ptrc_glIsBufferResidentNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedBufferResidentNV)(GLuint);
#define glIsNamedBufferResidentNV _ptrc_glIsNamedBufferResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferNonResidentNV)(GLenum);
#define glMakeBufferNonResidentNV _ptrc_glMakeBufferNonResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferResidentNV)(GLenum, GLenum);
#define glMakeBufferResidentNV _ptrc_glMakeBufferResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferNonResidentNV)(GLuint);
#define glMakeNamedBufferNonResidentNV _ptrc_glMakeNamedBufferNonResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferResidentNV)(GLuint, GLenum);
#define glMakeNamedBufferResidentNV _ptrc_glMakeNamedBufferResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64NV)(GLuint, GLint, GLuint64EXT);
#define glProgramUniformui64NV _ptrc_glProgramUniformui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *);
#define glProgramUniformui64vNV _ptrc_glProgramUniformui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformui64NV)(GLint, GLuint64EXT);
#define glUniformui64NV _ptrc_glUniformui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformui64vNV)(GLint, GLsizei, const GLuint64EXT *);
#define glUniformui64vNV _ptrc_glUniformui64vNV
#endif /*GL_NV_shader_buffer_load*/ 






#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureBarrierNV)();
#define glTextureBarrierNV _ptrc_glTextureBarrierNV
#endif /*GL_NV_texture_barrier*/ 




#ifndef GL_NV_texture_multisample
#define GL_NV_texture_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisampleCoverageNV)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean);
#define glTexImage2DMultisampleCoverageNV _ptrc_glTexImage2DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisampleCoverageNV)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTexImage3DMultisampleCoverageNV _ptrc_glTexImage3DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleCoverageNV)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean);
#define glTextureImage2DMultisampleCoverageNV _ptrc_glTextureImage2DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleNV)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean);
#define glTextureImage2DMultisampleNV _ptrc_glTextureImage2DMultisampleNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleCoverageNV)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTextureImage3DMultisampleCoverageNV _ptrc_glTextureImage3DMultisampleCoverageNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleNV)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTextureImage3DMultisampleNV _ptrc_glTextureImage3DMultisampleNV
#endif /*GL_NV_texture_multisample*/ 





#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1
extern void (CODEGEN_FUNCPTR *_ptrc_glActiveVaryingNV)(GLuint, const GLchar *);
#define glActiveVaryingNV _ptrc_glActiveVaryingNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedbackNV)(GLenum);
#define glBeginTransformFeedbackNV _ptrc_glBeginTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBaseNV)(GLenum, GLuint, GLuint);
#define glBindBufferBaseNV _ptrc_glBindBufferBaseNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferOffsetNV)(GLenum, GLuint, GLuint, GLintptr);
#define glBindBufferOffsetNV _ptrc_glBindBufferOffsetNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRangeNV)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
#define glBindBufferRangeNV _ptrc_glBindBufferRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedbackNV)();
#define glEndTransformFeedbackNV _ptrc_glEndTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveVaryingNV)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
#define glGetActiveVaryingNV _ptrc_glGetActiveVaryingNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVaryingNV)(GLuint, GLuint, GLint *);
#define glGetTransformFeedbackVaryingNV _ptrc_glGetTransformFeedbackVaryingNV
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetVaryingLocationNV)(GLuint, const GLchar *);
#define glGetVaryingLocationNV _ptrc_glGetVaryingLocationNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackAttribsNV)(GLuint, const GLint *, GLenum);
#define glTransformFeedbackAttribsNV _ptrc_glTransformFeedbackAttribsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackStreamAttribsNV)(GLsizei, const GLint *, GLsizei, const GLint *, GLenum);
#define glTransformFeedbackStreamAttribsNV _ptrc_glTransformFeedbackStreamAttribsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryingsNV)(GLuint, GLsizei, const GLint *, GLenum);
#define glTransformFeedbackVaryingsNV _ptrc_glTransformFeedbackVaryingsNV
#endif /*GL_NV_transform_feedback*/ 

#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedbackNV)(GLenum, GLuint);
#define glBindTransformFeedbackNV _ptrc_glBindTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacksNV)(GLsizei, const GLuint *);
#define glDeleteTransformFeedbacksNV _ptrc_glDeleteTransformFeedbacksNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackNV)(GLenum, GLuint);
#define glDrawTransformFeedbackNV _ptrc_glDrawTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacksNV)(GLsizei, GLuint *);
#define glGenTransformFeedbacksNV _ptrc_glGenTransformFeedbacksNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedbackNV)(GLuint);
#define glIsTransformFeedbackNV _ptrc_glIsTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedbackNV)();
#define glPauseTransformFeedbackNV _ptrc_glPauseTransformFeedbackNV
extern void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedbackNV)();
#define glResumeTransformFeedbackNV _ptrc_glResumeTransformFeedbackNV
#endif /*GL_NV_transform_feedback2*/ 

#ifndef GL_NV_vdpau_interop
#define GL_NV_vdpau_interop 1
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUFiniNV)();
#define glVDPAUFiniNV _ptrc_glVDPAUFiniNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUGetSurfaceivNV)(GLvdpauSurfaceNV, GLenum, GLsizei, GLsizei *, GLint *);
#define glVDPAUGetSurfaceivNV _ptrc_glVDPAUGetSurfaceivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUInitNV)(const GLvoid *, const GLvoid *);
#define glVDPAUInitNV _ptrc_glVDPAUInitNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUIsSurfaceNV)(GLvdpauSurfaceNV);
#define glVDPAUIsSurfaceNV _ptrc_glVDPAUIsSurfaceNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUMapSurfacesNV)(GLsizei, const GLvdpauSurfaceNV *);
#define glVDPAUMapSurfacesNV _ptrc_glVDPAUMapSurfacesNV
extern GLvdpauSurfaceNV (CODEGEN_FUNCPTR *_ptrc_glVDPAURegisterOutputSurfaceNV)(const GLvoid *, GLenum, GLsizei, const GLuint *);
#define glVDPAURegisterOutputSurfaceNV _ptrc_glVDPAURegisterOutputSurfaceNV
extern GLvdpauSurfaceNV (CODEGEN_FUNCPTR *_ptrc_glVDPAURegisterVideoSurfaceNV)(const GLvoid *, GLenum, GLsizei, const GLuint *);
#define glVDPAURegisterVideoSurfaceNV _ptrc_glVDPAURegisterVideoSurfaceNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUSurfaceAccessNV)(GLvdpauSurfaceNV, GLenum);
#define glVDPAUSurfaceAccessNV _ptrc_glVDPAUSurfaceAccessNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUUnmapSurfacesNV)(GLsizei, const GLvdpauSurfaceNV *);
#define glVDPAUUnmapSurfacesNV _ptrc_glVDPAUUnmapSurfacesNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVDPAUUnregisterSurfaceNV)(GLvdpauSurfaceNV);
#define glVDPAUUnregisterSurfaceNV _ptrc_glVDPAUUnregisterSurfaceNV
#endif /*GL_NV_vdpau_interop*/ 

#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushVertexArrayRangeNV)();
#define glFlushVertexArrayRangeNV _ptrc_glFlushVertexArrayRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayRangeNV)(GLsizei, const GLvoid *);
#define glVertexArrayRangeNV _ptrc_glVertexArrayRangeNV
#endif /*GL_NV_vertex_array_range*/ 


#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLi64vNV)(GLuint, GLenum, GLint64EXT *);
#define glGetVertexAttribLi64vNV _ptrc_glGetVertexAttribLi64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLui64vNV)(GLuint, GLenum, GLuint64EXT *);
#define glGetVertexAttribLui64vNV _ptrc_glGetVertexAttribLui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64NV)(GLuint, GLint64EXT);
#define glVertexAttribL1i64NV _ptrc_glVertexAttribL1i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64vNV)(GLuint, const GLint64EXT *);
#define glVertexAttribL1i64vNV _ptrc_glVertexAttribL1i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64NV)(GLuint, GLuint64EXT);
#define glVertexAttribL1ui64NV _ptrc_glVertexAttribL1ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64vNV)(GLuint, const GLuint64EXT *);
#define glVertexAttribL1ui64vNV _ptrc_glVertexAttribL1ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64NV)(GLuint, GLint64EXT, GLint64EXT);
#define glVertexAttribL2i64NV _ptrc_glVertexAttribL2i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64vNV)(GLuint, const GLint64EXT *);
#define glVertexAttribL2i64vNV _ptrc_glVertexAttribL2i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64NV)(GLuint, GLuint64EXT, GLuint64EXT);
#define glVertexAttribL2ui64NV _ptrc_glVertexAttribL2ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64vNV)(GLuint, const GLuint64EXT *);
#define glVertexAttribL2ui64vNV _ptrc_glVertexAttribL2ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64NV)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT);
#define glVertexAttribL3i64NV _ptrc_glVertexAttribL3i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64vNV)(GLuint, const GLint64EXT *);
#define glVertexAttribL3i64vNV _ptrc_glVertexAttribL3i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64NV)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT);
#define glVertexAttribL3ui64NV _ptrc_glVertexAttribL3ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64vNV)(GLuint, const GLuint64EXT *);
#define glVertexAttribL3ui64vNV _ptrc_glVertexAttribL3ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64NV)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT);
#define glVertexAttribL4i64NV _ptrc_glVertexAttribL4i64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64vNV)(GLuint, const GLint64EXT *);
#define glVertexAttribL4i64vNV _ptrc_glVertexAttribL4i64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64NV)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT);
#define glVertexAttribL4ui64NV _ptrc_glVertexAttribL4ui64NV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64vNV)(GLuint, const GLuint64EXT *);
#define glVertexAttribL4ui64vNV _ptrc_glVertexAttribL4ui64vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormatNV)(GLuint, GLint, GLenum, GLsizei);
#define glVertexAttribLFormatNV _ptrc_glVertexAttribLFormatNV
#endif /*GL_NV_vertex_attrib_integer_64bit*/ 

#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferAddressRangeNV)(GLenum, GLuint, GLuint64EXT, GLsizeiptr);
#define glBufferAddressRangeNV _ptrc_glBufferAddressRangeNV
extern void (CODEGEN_FUNCPTR *_ptrc_glColorFormatNV)(GLint, GLenum, GLsizei);
#define glColorFormatNV _ptrc_glColorFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagFormatNV)(GLsizei);
#define glEdgeFlagFormatNV _ptrc_glEdgeFlagFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordFormatNV)(GLenum, GLsizei);
#define glFogCoordFormatNV _ptrc_glFogCoordFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64i_vNV)(GLenum, GLuint, GLuint64EXT *);
#define glGetIntegerui64i_vNV _ptrc_glGetIntegerui64i_vNV
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexFormatNV)(GLenum, GLsizei);
#define glIndexFormatNV _ptrc_glIndexFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalFormatNV)(GLenum, GLsizei);
#define glNormalFormatNV _ptrc_glNormalFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorFormatNV)(GLint, GLenum, GLsizei);
#define glSecondaryColorFormatNV _ptrc_glSecondaryColorFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordFormatNV)(GLint, GLenum, GLsizei);
#define glTexCoordFormatNV _ptrc_glTexCoordFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormatNV)(GLuint, GLint, GLenum, GLboolean, GLsizei);
#define glVertexAttribFormatNV _ptrc_glVertexAttribFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormatNV)(GLuint, GLint, GLenum, GLsizei);
#define glVertexAttribIFormatNV _ptrc_glVertexAttribIFormatNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexFormatNV)(GLint, GLenum, GLsizei);
#define glVertexFormatNV _ptrc_glVertexFormatNV
#endif /*GL_NV_vertex_buffer_unified_memory*/ 

#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreProgramsResidentNV)(GLsizei, const GLuint *, GLboolean *);
#define glAreProgramsResidentNV _ptrc_glAreProgramsResidentNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramNV)(GLenum, GLuint);
#define glBindProgramNV _ptrc_glBindProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsNV)(GLsizei, const GLuint *);
#define glDeleteProgramsNV _ptrc_glDeleteProgramsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glExecuteProgramNV)(GLenum, GLuint, const GLfloat *);
#define glExecuteProgramNV _ptrc_glExecuteProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsNV)(GLsizei, GLuint *);
#define glGenProgramsNV _ptrc_glGenProgramsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterdvNV)(GLenum, GLuint, GLenum, GLdouble *);
#define glGetProgramParameterdvNV _ptrc_glGetProgramParameterdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterfvNV)(GLenum, GLuint, GLenum, GLfloat *);
#define glGetProgramParameterfvNV _ptrc_glGetProgramParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringNV)(GLuint, GLenum, GLubyte *);
#define glGetProgramStringNV _ptrc_glGetProgramStringNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivNV)(GLuint, GLenum, GLint *);
#define glGetProgramivNV _ptrc_glGetProgramivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTrackMatrixivNV)(GLenum, GLuint, GLenum, GLint *);
#define glGetTrackMatrixivNV _ptrc_glGetTrackMatrixivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervNV)(GLuint, GLenum, GLvoid **);
#define glGetVertexAttribPointervNV _ptrc_glGetVertexAttribPointervNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvNV)(GLuint, GLenum, GLdouble *);
#define glGetVertexAttribdvNV _ptrc_glGetVertexAttribdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvNV)(GLuint, GLenum, GLfloat *);
#define glGetVertexAttribfvNV _ptrc_glGetVertexAttribfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivNV)(GLuint, GLenum, GLint *);
#define glGetVertexAttribivNV _ptrc_glGetVertexAttribivNV
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramNV)(GLuint);
#define glIsProgramNV _ptrc_glIsProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadProgramNV)(GLenum, GLuint, GLsizei, const GLubyte *);
#define glLoadProgramNV _ptrc_glLoadProgramNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dNV)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramParameter4dNV _ptrc_glProgramParameter4dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dvNV)(GLenum, GLuint, const GLdouble *);
#define glProgramParameter4dvNV _ptrc_glProgramParameter4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fNV)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramParameter4fNV _ptrc_glProgramParameter4fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fvNV)(GLenum, GLuint, const GLfloat *);
#define glProgramParameter4fvNV _ptrc_glProgramParameter4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4dvNV)(GLenum, GLuint, GLsizei, const GLdouble *);
#define glProgramParameters4dvNV _ptrc_glProgramParameters4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4fvNV)(GLenum, GLuint, GLsizei, const GLfloat *);
#define glProgramParameters4fvNV _ptrc_glProgramParameters4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glRequestResidentProgramsNV)(GLsizei, const GLuint *);
#define glRequestResidentProgramsNV _ptrc_glRequestResidentProgramsNV
extern void (CODEGEN_FUNCPTR *_ptrc_glTrackMatrixNV)(GLenum, GLuint, GLenum, GLenum);
#define glTrackMatrixNV _ptrc_glTrackMatrixNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dNV)(GLuint, GLdouble);
#define glVertexAttrib1dNV _ptrc_glVertexAttrib1dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvNV)(GLuint, const GLdouble *);
#define glVertexAttrib1dvNV _ptrc_glVertexAttrib1dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fNV)(GLuint, GLfloat);
#define glVertexAttrib1fNV _ptrc_glVertexAttrib1fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvNV)(GLuint, const GLfloat *);
#define glVertexAttrib1fvNV _ptrc_glVertexAttrib1fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sNV)(GLuint, GLshort);
#define glVertexAttrib1sNV _ptrc_glVertexAttrib1sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svNV)(GLuint, const GLshort *);
#define glVertexAttrib1svNV _ptrc_glVertexAttrib1svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dNV)(GLuint, GLdouble, GLdouble);
#define glVertexAttrib2dNV _ptrc_glVertexAttrib2dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvNV)(GLuint, const GLdouble *);
#define glVertexAttrib2dvNV _ptrc_glVertexAttrib2dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fNV)(GLuint, GLfloat, GLfloat);
#define glVertexAttrib2fNV _ptrc_glVertexAttrib2fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvNV)(GLuint, const GLfloat *);
#define glVertexAttrib2fvNV _ptrc_glVertexAttrib2fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sNV)(GLuint, GLshort, GLshort);
#define glVertexAttrib2sNV _ptrc_glVertexAttrib2sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svNV)(GLuint, const GLshort *);
#define glVertexAttrib2svNV _ptrc_glVertexAttrib2svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dNV)(GLuint, GLdouble, GLdouble, GLdouble);
#define glVertexAttrib3dNV _ptrc_glVertexAttrib3dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvNV)(GLuint, const GLdouble *);
#define glVertexAttrib3dvNV _ptrc_glVertexAttrib3dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fNV)(GLuint, GLfloat, GLfloat, GLfloat);
#define glVertexAttrib3fNV _ptrc_glVertexAttrib3fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvNV)(GLuint, const GLfloat *);
#define glVertexAttrib3fvNV _ptrc_glVertexAttrib3fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sNV)(GLuint, GLshort, GLshort, GLshort);
#define glVertexAttrib3sNV _ptrc_glVertexAttrib3sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svNV)(GLuint, const GLshort *);
#define glVertexAttrib3svNV _ptrc_glVertexAttrib3svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dNV)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertexAttrib4dNV _ptrc_glVertexAttrib4dNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvNV)(GLuint, const GLdouble *);
#define glVertexAttrib4dvNV _ptrc_glVertexAttrib4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fNV)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glVertexAttrib4fNV _ptrc_glVertexAttrib4fNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvNV)(GLuint, const GLfloat *);
#define glVertexAttrib4fvNV _ptrc_glVertexAttrib4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sNV)(GLuint, GLshort, GLshort, GLshort, GLshort);
#define glVertexAttrib4sNV _ptrc_glVertexAttrib4sNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svNV)(GLuint, const GLshort *);
#define glVertexAttrib4svNV _ptrc_glVertexAttrib4svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubNV)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
#define glVertexAttrib4ubNV _ptrc_glVertexAttrib4ubNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvNV)(GLuint, const GLubyte *);
#define glVertexAttrib4ubvNV _ptrc_glVertexAttrib4ubvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerNV)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexAttribPointerNV _ptrc_glVertexAttribPointerNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1dvNV)(GLuint, GLsizei, const GLdouble *);
#define glVertexAttribs1dvNV _ptrc_glVertexAttribs1dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1fvNV)(GLuint, GLsizei, const GLfloat *);
#define glVertexAttribs1fvNV _ptrc_glVertexAttribs1fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1svNV)(GLuint, GLsizei, const GLshort *);
#define glVertexAttribs1svNV _ptrc_glVertexAttribs1svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2dvNV)(GLuint, GLsizei, const GLdouble *);
#define glVertexAttribs2dvNV _ptrc_glVertexAttribs2dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2fvNV)(GLuint, GLsizei, const GLfloat *);
#define glVertexAttribs2fvNV _ptrc_glVertexAttribs2fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2svNV)(GLuint, GLsizei, const GLshort *);
#define glVertexAttribs2svNV _ptrc_glVertexAttribs2svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3dvNV)(GLuint, GLsizei, const GLdouble *);
#define glVertexAttribs3dvNV _ptrc_glVertexAttribs3dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3fvNV)(GLuint, GLsizei, const GLfloat *);
#define glVertexAttribs3fvNV _ptrc_glVertexAttribs3fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3svNV)(GLuint, GLsizei, const GLshort *);
#define glVertexAttribs3svNV _ptrc_glVertexAttribs3svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4dvNV)(GLuint, GLsizei, const GLdouble *);
#define glVertexAttribs4dvNV _ptrc_glVertexAttribs4dvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4fvNV)(GLuint, GLsizei, const GLfloat *);
#define glVertexAttribs4fvNV _ptrc_glVertexAttribs4fvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4svNV)(GLuint, GLsizei, const GLshort *);
#define glVertexAttribs4svNV _ptrc_glVertexAttribs4svNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4ubvNV)(GLuint, GLsizei, const GLubyte *);
#define glVertexAttribs4ubvNV _ptrc_glVertexAttribs4ubvNV
#endif /*GL_NV_vertex_program*/ 





#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIivEXT)(GLuint, GLenum, GLint *);
#define glGetVertexAttribIivEXT _ptrc_glGetVertexAttribIivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIuivEXT)(GLuint, GLenum, GLuint *);
#define glGetVertexAttribIuivEXT _ptrc_glGetVertexAttribIuivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1iEXT)(GLuint, GLint);
#define glVertexAttribI1iEXT _ptrc_glVertexAttribI1iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1ivEXT)(GLuint, const GLint *);
#define glVertexAttribI1ivEXT _ptrc_glVertexAttribI1ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uiEXT)(GLuint, GLuint);
#define glVertexAttribI1uiEXT _ptrc_glVertexAttribI1uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uivEXT)(GLuint, const GLuint *);
#define glVertexAttribI1uivEXT _ptrc_glVertexAttribI1uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2iEXT)(GLuint, GLint, GLint);
#define glVertexAttribI2iEXT _ptrc_glVertexAttribI2iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2ivEXT)(GLuint, const GLint *);
#define glVertexAttribI2ivEXT _ptrc_glVertexAttribI2ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uiEXT)(GLuint, GLuint, GLuint);
#define glVertexAttribI2uiEXT _ptrc_glVertexAttribI2uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uivEXT)(GLuint, const GLuint *);
#define glVertexAttribI2uivEXT _ptrc_glVertexAttribI2uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3iEXT)(GLuint, GLint, GLint, GLint);
#define glVertexAttribI3iEXT _ptrc_glVertexAttribI3iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3ivEXT)(GLuint, const GLint *);
#define glVertexAttribI3ivEXT _ptrc_glVertexAttribI3ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uiEXT)(GLuint, GLuint, GLuint, GLuint);
#define glVertexAttribI3uiEXT _ptrc_glVertexAttribI3uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uivEXT)(GLuint, const GLuint *);
#define glVertexAttribI3uivEXT _ptrc_glVertexAttribI3uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4bvEXT)(GLuint, const GLbyte *);
#define glVertexAttribI4bvEXT _ptrc_glVertexAttribI4bvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4iEXT)(GLuint, GLint, GLint, GLint, GLint);
#define glVertexAttribI4iEXT _ptrc_glVertexAttribI4iEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ivEXT)(GLuint, const GLint *);
#define glVertexAttribI4ivEXT _ptrc_glVertexAttribI4ivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4svEXT)(GLuint, const GLshort *);
#define glVertexAttribI4svEXT _ptrc_glVertexAttribI4svEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ubvEXT)(GLuint, const GLubyte *);
#define glVertexAttribI4ubvEXT _ptrc_glVertexAttribI4ubvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uiEXT)(GLuint, GLuint, GLuint, GLuint, GLuint);
#define glVertexAttribI4uiEXT _ptrc_glVertexAttribI4uiEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uivEXT)(GLuint, const GLuint *);
#define glVertexAttribI4uivEXT _ptrc_glVertexAttribI4uivEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4usvEXT)(GLuint, const GLushort *);
#define glVertexAttribI4usvEXT _ptrc_glVertexAttribI4usvEXT
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIPointerEXT)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexAttribIPointerEXT _ptrc_glVertexAttribIPointerEXT
#endif /*GL_NV_vertex_program4*/ 

#ifndef GL_NV_video_capture
#define GL_NV_video_capture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginVideoCaptureNV)(GLuint);
#define glBeginVideoCaptureNV _ptrc_glBeginVideoCaptureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamBufferNV)(GLuint, GLuint, GLenum, GLintptrARB);
#define glBindVideoCaptureStreamBufferNV _ptrc_glBindVideoCaptureStreamBufferNV
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamTextureNV)(GLuint, GLuint, GLenum, GLenum, GLuint);
#define glBindVideoCaptureStreamTextureNV _ptrc_glBindVideoCaptureStreamTextureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glEndVideoCaptureNV)(GLuint);
#define glEndVideoCaptureNV _ptrc_glEndVideoCaptureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamdvNV)(GLuint, GLuint, GLenum, GLdouble *);
#define glGetVideoCaptureStreamdvNV _ptrc_glGetVideoCaptureStreamdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamfvNV)(GLuint, GLuint, GLenum, GLfloat *);
#define glGetVideoCaptureStreamfvNV _ptrc_glGetVideoCaptureStreamfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamivNV)(GLuint, GLuint, GLenum, GLint *);
#define glGetVideoCaptureStreamivNV _ptrc_glGetVideoCaptureStreamivNV
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureivNV)(GLuint, GLenum, GLint *);
#define glGetVideoCaptureivNV _ptrc_glGetVideoCaptureivNV
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureNV)(GLuint, GLuint *, GLuint64EXT *);
#define glVideoCaptureNV _ptrc_glVideoCaptureNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterdvNV)(GLuint, GLuint, GLenum, const GLdouble *);
#define glVideoCaptureStreamParameterdvNV _ptrc_glVideoCaptureStreamParameterdvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterfvNV)(GLuint, GLuint, GLenum, const GLfloat *);
#define glVideoCaptureStreamParameterfvNV _ptrc_glVideoCaptureStreamParameterfvNV
extern void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterivNV)(GLuint, GLuint, GLenum, const GLint *);
#define glVideoCaptureStreamParameterivNV _ptrc_glVideoCaptureStreamParameterivNV
#endif /*GL_NV_video_capture*/ 

#ifndef GL_OES_byte_coordinates
#define GL_OES_byte_coordinates 1
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1bOES)(GLenum, GLbyte);
#define glMultiTexCoord1bOES _ptrc_glMultiTexCoord1bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1bvOES)(GLenum, const GLbyte *);
#define glMultiTexCoord1bvOES _ptrc_glMultiTexCoord1bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2bOES)(GLenum, GLbyte, GLbyte);
#define glMultiTexCoord2bOES _ptrc_glMultiTexCoord2bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2bvOES)(GLenum, const GLbyte *);
#define glMultiTexCoord2bvOES _ptrc_glMultiTexCoord2bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3bOES)(GLenum, GLbyte, GLbyte, GLbyte);
#define glMultiTexCoord3bOES _ptrc_glMultiTexCoord3bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3bvOES)(GLenum, const GLbyte *);
#define glMultiTexCoord3bvOES _ptrc_glMultiTexCoord3bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4bOES)(GLenum, GLbyte, GLbyte, GLbyte, GLbyte);
#define glMultiTexCoord4bOES _ptrc_glMultiTexCoord4bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4bvOES)(GLenum, const GLbyte *);
#define glMultiTexCoord4bvOES _ptrc_glMultiTexCoord4bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1bOES)(GLbyte);
#define glTexCoord1bOES _ptrc_glTexCoord1bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1bvOES)(const GLbyte *);
#define glTexCoord1bvOES _ptrc_glTexCoord1bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2bOES)(GLbyte, GLbyte);
#define glTexCoord2bOES _ptrc_glTexCoord2bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2bvOES)(const GLbyte *);
#define glTexCoord2bvOES _ptrc_glTexCoord2bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3bOES)(GLbyte, GLbyte, GLbyte);
#define glTexCoord3bOES _ptrc_glTexCoord3bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3bvOES)(const GLbyte *);
#define glTexCoord3bvOES _ptrc_glTexCoord3bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4bOES)(GLbyte, GLbyte, GLbyte, GLbyte);
#define glTexCoord4bOES _ptrc_glTexCoord4bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4bvOES)(const GLbyte *);
#define glTexCoord4bvOES _ptrc_glTexCoord4bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2bOES)(GLbyte);
#define glVertex2bOES _ptrc_glVertex2bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2bvOES)(const GLbyte *);
#define glVertex2bvOES _ptrc_glVertex2bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3bOES)(GLbyte, GLbyte);
#define glVertex3bOES _ptrc_glVertex3bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3bvOES)(const GLbyte *);
#define glVertex3bvOES _ptrc_glVertex3bvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4bOES)(GLbyte, GLbyte, GLbyte);
#define glVertex4bOES _ptrc_glVertex4bOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4bvOES)(const GLbyte *);
#define glVertex4bvOES _ptrc_glVertex4bvOES
#endif /*GL_OES_byte_coordinates*/ 


#ifndef GL_OES_fixed_point
#define GL_OES_fixed_point 1
extern void (CODEGEN_FUNCPTR *_ptrc_glAccumxOES)(GLenum, GLfixed);
#define glAccumxOES _ptrc_glAccumxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glAlphaFuncxOES)(GLenum, GLfixed);
#define glAlphaFuncxOES _ptrc_glAlphaFuncxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glBitmapxOES)(GLsizei, GLsizei, GLfixed, GLfixed, GLfixed, GLfixed, const GLubyte *);
#define glBitmapxOES _ptrc_glBitmapxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendColorxOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glBlendColorxOES _ptrc_glBlendColorxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glClearAccumxOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glClearAccumxOES _ptrc_glClearAccumxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glClearColorxOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glClearColorxOES _ptrc_glClearColorxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthxOES)(GLfixed);
#define glClearDepthxOES _ptrc_glClearDepthxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glClipPlanexOES)(GLenum, const GLfixed *);
#define glClipPlanexOES _ptrc_glClipPlanexOES
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3xOES)(GLfixed, GLfixed, GLfixed);
#define glColor3xOES _ptrc_glColor3xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3xvOES)(const GLfixed *);
#define glColor3xvOES _ptrc_glColor3xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4xOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glColor4xOES _ptrc_glColor4xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4xvOES)(const GLfixed *);
#define glColor4xvOES _ptrc_glColor4xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterxOES)(GLenum, GLenum, GLfixed);
#define glConvolutionParameterxOES _ptrc_glConvolutionParameterxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterxvOES)(GLenum, GLenum, const GLfixed *);
#define glConvolutionParameterxvOES _ptrc_glConvolutionParameterxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangexOES)(GLfixed, GLfixed);
#define glDepthRangexOES _ptrc_glDepthRangexOES
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1xOES)(GLfixed);
#define glEvalCoord1xOES _ptrc_glEvalCoord1xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1xvOES)(const GLfixed *);
#define glEvalCoord1xvOES _ptrc_glEvalCoord1xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2xOES)(GLfixed, GLfixed);
#define glEvalCoord2xOES _ptrc_glEvalCoord2xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2xvOES)(const GLfixed *);
#define glEvalCoord2xvOES _ptrc_glEvalCoord2xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glFeedbackBufferxOES)(GLsizei, GLenum, const GLfixed *);
#define glFeedbackBufferxOES _ptrc_glFeedbackBufferxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glFogxOES)(GLenum, GLfixed);
#define glFogxOES _ptrc_glFogxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glFogxvOES)(GLenum, const GLfixed *);
#define glFogxvOES _ptrc_glFogxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glFrustumxOES)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed);
#define glFrustumxOES _ptrc_glFrustumxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetClipPlanexOES)(GLenum, GLfixed *);
#define glGetClipPlanexOES _ptrc_glGetClipPlanexOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterxvOES)(GLenum, GLenum, GLfixed *);
#define glGetConvolutionParameterxvOES _ptrc_glGetConvolutionParameterxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFixedvOES)(GLenum, GLfixed *);
#define glGetFixedvOES _ptrc_glGetFixedvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterxvOES)(GLenum, GLenum, GLfixed *);
#define glGetHistogramParameterxvOES _ptrc_glGetHistogramParameterxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetLightxOES)(GLenum, GLenum, GLfixed *);
#define glGetLightxOES _ptrc_glGetLightxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapxvOES)(GLenum, GLenum, GLfixed *);
#define glGetMapxvOES _ptrc_glGetMapxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMaterialxOES)(GLenum, GLenum, GLfixed);
#define glGetMaterialxOES _ptrc_glGetMaterialxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapxv)(GLenum, GLint, GLfixed *);
#define glGetPixelMapxv _ptrc_glGetPixelMapxv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexEnvxvOES)(GLenum, GLenum, GLfixed *);
#define glGetTexEnvxvOES _ptrc_glGetTexEnvxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexGenxvOES)(GLenum, GLenum, GLfixed *);
#define glGetTexGenxvOES _ptrc_glGetTexGenxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameterxvOES)(GLenum, GLint, GLenum, GLfixed *);
#define glGetTexLevelParameterxvOES _ptrc_glGetTexLevelParameterxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterxvOES)(GLenum, GLenum, GLfixed *);
#define glGetTexParameterxvOES _ptrc_glGetTexParameterxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexxOES)(GLfixed);
#define glIndexxOES _ptrc_glIndexxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexxvOES)(const GLfixed *);
#define glIndexxvOES _ptrc_glIndexxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glLightModelxOES)(GLenum, GLfixed);
#define glLightModelxOES _ptrc_glLightModelxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glLightModelxvOES)(GLenum, const GLfixed *);
#define glLightModelxvOES _ptrc_glLightModelxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glLightxOES)(GLenum, GLenum, GLfixed);
#define glLightxOES _ptrc_glLightxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glLightxvOES)(GLenum, GLenum, const GLfixed *);
#define glLightxvOES _ptrc_glLightxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glLineWidthxOES)(GLfixed);
#define glLineWidthxOES _ptrc_glLineWidthxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadMatrixxOES)(const GLfixed *);
#define glLoadMatrixxOES _ptrc_glLoadMatrixxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixxOES)(const GLfixed *);
#define glLoadTransposeMatrixxOES _ptrc_glLoadTransposeMatrixxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMap1xOES)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed);
#define glMap1xOES _ptrc_glMap1xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMap2xOES)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed, GLfixed, GLint, GLint, GLfixed);
#define glMap2xOES _ptrc_glMap2xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMapGrid1xOES)(GLint, GLfixed, GLfixed);
#define glMapGrid1xOES _ptrc_glMapGrid1xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMapGrid2xOES)(GLint, GLfixed, GLfixed, GLfixed, GLfixed);
#define glMapGrid2xOES _ptrc_glMapGrid2xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMaterialxOES)(GLenum, GLenum, GLfixed);
#define glMaterialxOES _ptrc_glMaterialxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMaterialxvOES)(GLenum, GLenum, const GLfixed *);
#define glMaterialxvOES _ptrc_glMaterialxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultMatrixxOES)(const GLfixed *);
#define glMultMatrixxOES _ptrc_glMultMatrixxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixxOES)(const GLfixed *);
#define glMultTransposeMatrixxOES _ptrc_glMultTransposeMatrixxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1xOES)(GLenum, GLfixed);
#define glMultiTexCoord1xOES _ptrc_glMultiTexCoord1xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1xvOES)(GLenum, const GLfixed *);
#define glMultiTexCoord1xvOES _ptrc_glMultiTexCoord1xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2xOES)(GLenum, GLfixed, GLfixed);
#define glMultiTexCoord2xOES _ptrc_glMultiTexCoord2xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2xvOES)(GLenum, const GLfixed *);
#define glMultiTexCoord2xvOES _ptrc_glMultiTexCoord2xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3xOES)(GLenum, GLfixed, GLfixed, GLfixed);
#define glMultiTexCoord3xOES _ptrc_glMultiTexCoord3xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3xvOES)(GLenum, const GLfixed *);
#define glMultiTexCoord3xvOES _ptrc_glMultiTexCoord3xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4xOES)(GLenum, GLfixed, GLfixed, GLfixed, GLfixed);
#define glMultiTexCoord4xOES _ptrc_glMultiTexCoord4xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4xvOES)(GLenum, const GLfixed *);
#define glMultiTexCoord4xvOES _ptrc_glMultiTexCoord4xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3xOES)(GLfixed, GLfixed, GLfixed);
#define glNormal3xOES _ptrc_glNormal3xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3xvOES)(const GLfixed *);
#define glNormal3xvOES _ptrc_glNormal3xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glOrthoxOES)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed);
#define glOrthoxOES _ptrc_glOrthoxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glPassThroughxOES)(GLfixed);
#define glPassThroughxOES _ptrc_glPassThroughxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelMapx)(GLenum, GLint, const GLfixed *);
#define glPixelMapx _ptrc_glPixelMapx
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelStorex)(GLenum, GLfixed);
#define glPixelStorex _ptrc_glPixelStorex
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTransferxOES)(GLenum, GLfixed);
#define glPixelTransferxOES _ptrc_glPixelTransferxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelZoomxOES)(GLfixed, GLfixed);
#define glPixelZoomxOES _ptrc_glPixelZoomxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterxvOES)(GLenum, const GLfixed *);
#define glPointParameterxvOES _ptrc_glPointParameterxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glPointSizexOES)(GLfixed);
#define glPointSizexOES _ptrc_glPointSizexOES
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffsetxOES)(GLfixed, GLfixed);
#define glPolygonOffsetxOES _ptrc_glPolygonOffsetxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTexturesxOES)(GLsizei, const GLuint *, const GLfixed *);
#define glPrioritizeTexturesxOES _ptrc_glPrioritizeTexturesxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2xOES)(GLfixed, GLfixed);
#define glRasterPos2xOES _ptrc_glRasterPos2xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2xvOES)(const GLfixed *);
#define glRasterPos2xvOES _ptrc_glRasterPos2xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3xOES)(GLfixed, GLfixed, GLfixed);
#define glRasterPos3xOES _ptrc_glRasterPos3xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3xvOES)(const GLfixed *);
#define glRasterPos3xvOES _ptrc_glRasterPos3xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4xOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glRasterPos4xOES _ptrc_glRasterPos4xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4xvOES)(const GLfixed *);
#define glRasterPos4xvOES _ptrc_glRasterPos4xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRectxOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glRectxOES _ptrc_glRectxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRectxvOES)(const GLfixed *, const GLfixed *);
#define glRectxvOES _ptrc_glRectxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glRotatexOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glRotatexOES _ptrc_glRotatexOES
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverageOES)(GLfixed, GLboolean);
#define glSampleCoverageOES _ptrc_glSampleCoverageOES
extern void (CODEGEN_FUNCPTR *_ptrc_glScalexOES)(GLfixed, GLfixed, GLfixed);
#define glScalexOES _ptrc_glScalexOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1xOES)(GLfixed);
#define glTexCoord1xOES _ptrc_glTexCoord1xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1xvOES)(const GLfixed *);
#define glTexCoord1xvOES _ptrc_glTexCoord1xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2xOES)(GLfixed, GLfixed);
#define glTexCoord2xOES _ptrc_glTexCoord2xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2xvOES)(const GLfixed *);
#define glTexCoord2xvOES _ptrc_glTexCoord2xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3xOES)(GLfixed, GLfixed, GLfixed);
#define glTexCoord3xOES _ptrc_glTexCoord3xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3xvOES)(const GLfixed *);
#define glTexCoord3xvOES _ptrc_glTexCoord3xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4xOES)(GLfixed, GLfixed, GLfixed, GLfixed);
#define glTexCoord4xOES _ptrc_glTexCoord4xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4xvOES)(const GLfixed *);
#define glTexCoord4xvOES _ptrc_glTexCoord4xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexEnvxOES)(GLenum, GLenum, GLfixed);
#define glTexEnvxOES _ptrc_glTexEnvxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexEnvxvOES)(GLenum, GLenum, const GLfixed *);
#define glTexEnvxvOES _ptrc_glTexEnvxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGenxOES)(GLenum, GLenum, GLfixed);
#define glTexGenxOES _ptrc_glTexGenxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGenxvOES)(GLenum, GLenum, const GLfixed *);
#define glTexGenxvOES _ptrc_glTexGenxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterxOES)(GLenum, GLenum, GLfixed);
#define glTexParameterxOES _ptrc_glTexParameterxOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterxvOES)(GLenum, GLenum, const GLfixed *);
#define glTexParameterxvOES _ptrc_glTexParameterxvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glTranslatexOES)(GLfixed, GLfixed, GLfixed);
#define glTranslatexOES _ptrc_glTranslatexOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2xOES)(GLfixed);
#define glVertex2xOES _ptrc_glVertex2xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2xvOES)(const GLfixed *);
#define glVertex2xvOES _ptrc_glVertex2xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3xOES)(GLfixed, GLfixed);
#define glVertex3xOES _ptrc_glVertex3xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3xvOES)(const GLfixed *);
#define glVertex3xvOES _ptrc_glVertex3xvOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4xOES)(GLfixed, GLfixed, GLfixed);
#define glVertex4xOES _ptrc_glVertex4xOES
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4xvOES)(const GLfixed *);
#define glVertex4xvOES _ptrc_glVertex4xvOES
#endif /*GL_OES_fixed_point*/ 

#ifndef GL_OES_query_matrix
#define GL_OES_query_matrix 1
extern GLbitfield (CODEGEN_FUNCPTR *_ptrc_glQueryMatrixxOES)(GLfixed *, GLint *);
#define glQueryMatrixxOES _ptrc_glQueryMatrixxOES
#endif /*GL_OES_query_matrix*/ 


#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthfOES)(GLclampf);
#define glClearDepthfOES _ptrc_glClearDepthfOES
extern void (CODEGEN_FUNCPTR *_ptrc_glClipPlanefOES)(GLenum, const GLfloat *);
#define glClipPlanefOES _ptrc_glClipPlanefOES
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangefOES)(GLclampf, GLclampf);
#define glDepthRangefOES _ptrc_glDepthRangefOES
extern void (CODEGEN_FUNCPTR *_ptrc_glFrustumfOES)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glFrustumfOES _ptrc_glFrustumfOES
extern void (CODEGEN_FUNCPTR *_ptrc_glGetClipPlanefOES)(GLenum, GLfloat *);
#define glGetClipPlanefOES _ptrc_glGetClipPlanefOES
extern void (CODEGEN_FUNCPTR *_ptrc_glOrthofOES)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glOrthofOES _ptrc_glOrthofOES
#endif /*GL_OES_single_precision*/ 




#ifndef GL_PGI_misc_hints
#define GL_PGI_misc_hints 1
extern void (CODEGEN_FUNCPTR *_ptrc_glHintPGI)(GLenum, GLint);
#define glHintPGI _ptrc_glHintPGI
#endif /*GL_PGI_misc_hints*/ 




#ifndef GL_SGIS_detail_texture
#define GL_SGIS_detail_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDetailTexFuncSGIS)(GLenum, GLsizei, const GLfloat *);
#define glDetailTexFuncSGIS _ptrc_glDetailTexFuncSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDetailTexFuncSGIS)(GLenum, GLfloat *);
#define glGetDetailTexFuncSGIS _ptrc_glGetDetailTexFuncSGIS
#endif /*GL_SGIS_detail_texture*/ 

#ifndef GL_SGIS_fog_function
#define GL_SGIS_fog_function 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFogFuncSGIS)(GLsizei, const GLfloat *);
#define glFogFuncSGIS _ptrc_glFogFuncSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFogFuncSGIS)(GLfloat *);
#define glGetFogFuncSGIS _ptrc_glGetFogFuncSGIS
#endif /*GL_SGIS_fog_function*/ 


#ifndef GL_SGIS_multisample
#define GL_SGIS_multisample 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskSGIS)(GLclampf, GLboolean);
#define glSampleMaskSGIS _ptrc_glSampleMaskSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplePatternSGIS)(GLenum);
#define glSamplePatternSGIS _ptrc_glSamplePatternSGIS
#endif /*GL_SGIS_multisample*/ 

#ifndef GL_SGIS_pixel_texture
#define GL_SGIS_pixel_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTexGenParameterfvSGIS)(GLenum, GLfloat *);
#define glGetPixelTexGenParameterfvSGIS _ptrc_glGetPixelTexGenParameterfvSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTexGenParameterivSGIS)(GLenum, GLint *);
#define glGetPixelTexGenParameterivSGIS _ptrc_glGetPixelTexGenParameterivSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameterfSGIS)(GLenum, GLfloat);
#define glPixelTexGenParameterfSGIS _ptrc_glPixelTexGenParameterfSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameterfvSGIS)(GLenum, const GLfloat *);
#define glPixelTexGenParameterfvSGIS _ptrc_glPixelTexGenParameterfvSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameteriSGIS)(GLenum, GLint);
#define glPixelTexGenParameteriSGIS _ptrc_glPixelTexGenParameteriSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameterivSGIS)(GLenum, const GLint *);
#define glPixelTexGenParameterivSGIS _ptrc_glPixelTexGenParameterivSGIS
#endif /*GL_SGIS_pixel_texture*/ 


#ifndef GL_SGIS_point_parameters
#define GL_SGIS_point_parameters 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfSGIS)(GLenum, GLfloat);
#define glPointParameterfSGIS _ptrc_glPointParameterfSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvSGIS)(GLenum, const GLfloat *);
#define glPointParameterfvSGIS _ptrc_glPointParameterfvSGIS
#endif /*GL_SGIS_point_parameters*/ 

#ifndef GL_SGIS_sharpen_texture
#define GL_SGIS_sharpen_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSharpenTexFuncSGIS)(GLenum, GLfloat *);
#define glGetSharpenTexFuncSGIS _ptrc_glGetSharpenTexFuncSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glSharpenTexFuncSGIS)(GLenum, GLsizei, const GLfloat *);
#define glSharpenTexFuncSGIS _ptrc_glSharpenTexFuncSGIS
#endif /*GL_SGIS_sharpen_texture*/ 

#ifndef GL_SGIS_texture4D
#define GL_SGIS_texture4D 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage4DSGIS)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTexImage4DSGIS _ptrc_glTexImage4DSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage4DSGIS)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTexSubImage4DSGIS _ptrc_glTexSubImage4DSGIS
#endif /*GL_SGIS_texture4D*/ 


#ifndef GL_SGIS_texture_color_mask
#define GL_SGIS_texture_color_mask 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureColorMaskSGIS)(GLboolean, GLboolean, GLboolean, GLboolean);
#define glTextureColorMaskSGIS _ptrc_glTextureColorMaskSGIS
#endif /*GL_SGIS_texture_color_mask*/ 


#ifndef GL_SGIS_texture_filter4
#define GL_SGIS_texture_filter4 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexFilterFuncSGIS)(GLenum, GLenum, GLfloat *);
#define glGetTexFilterFuncSGIS _ptrc_glGetTexFilterFuncSGIS
extern void (CODEGEN_FUNCPTR *_ptrc_glTexFilterFuncSGIS)(GLenum, GLenum, GLsizei, const GLfloat *);
#define glTexFilterFuncSGIS _ptrc_glTexFilterFuncSGIS
#endif /*GL_SGIS_texture_filter4*/ 



#ifndef GL_SGIX_async
#define GL_SGIX_async 1
extern void (CODEGEN_FUNCPTR *_ptrc_glAsyncMarkerSGIX)(GLuint);
#define glAsyncMarkerSGIX _ptrc_glAsyncMarkerSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteAsyncMarkersSGIX)(GLuint, GLsizei);
#define glDeleteAsyncMarkersSGIX _ptrc_glDeleteAsyncMarkersSGIX
extern GLint (CODEGEN_FUNCPTR *_ptrc_glFinishAsyncSGIX)(GLuint *);
#define glFinishAsyncSGIX _ptrc_glFinishAsyncSGIX
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGenAsyncMarkersSGIX)(GLsizei);
#define glGenAsyncMarkersSGIX _ptrc_glGenAsyncMarkersSGIX
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsAsyncMarkerSGIX)(GLuint);
#define glIsAsyncMarkerSGIX _ptrc_glIsAsyncMarkerSGIX
extern GLint (CODEGEN_FUNCPTR *_ptrc_glPollAsyncSGIX)(GLuint *);
#define glPollAsyncSGIX _ptrc_glPollAsyncSGIX
#endif /*GL_SGIX_async*/ 









#ifndef GL_SGIX_flush_raster
#define GL_SGIX_flush_raster 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushRasterSGIX)();
#define glFlushRasterSGIX _ptrc_glFlushRasterSGIX
#endif /*GL_SGIX_flush_raster*/ 


#ifndef GL_SGIX_fragment_lighting
#define GL_SGIX_fragment_lighting 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentColorMaterialSGIX)(GLenum, GLenum);
#define glFragmentColorMaterialSGIX _ptrc_glFragmentColorMaterialSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModelfSGIX)(GLenum, GLfloat);
#define glFragmentLightModelfSGIX _ptrc_glFragmentLightModelfSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModelfvSGIX)(GLenum, const GLfloat *);
#define glFragmentLightModelfvSGIX _ptrc_glFragmentLightModelfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModeliSGIX)(GLenum, GLint);
#define glFragmentLightModeliSGIX _ptrc_glFragmentLightModeliSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModelivSGIX)(GLenum, const GLint *);
#define glFragmentLightModelivSGIX _ptrc_glFragmentLightModelivSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightfSGIX)(GLenum, GLenum, GLfloat);
#define glFragmentLightfSGIX _ptrc_glFragmentLightfSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightfvSGIX)(GLenum, GLenum, const GLfloat *);
#define glFragmentLightfvSGIX _ptrc_glFragmentLightfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightiSGIX)(GLenum, GLenum, GLint);
#define glFragmentLightiSGIX _ptrc_glFragmentLightiSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightivSGIX)(GLenum, GLenum, const GLint *);
#define glFragmentLightivSGIX _ptrc_glFragmentLightivSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialfSGIX)(GLenum, GLenum, GLfloat);
#define glFragmentMaterialfSGIX _ptrc_glFragmentMaterialfSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialfvSGIX)(GLenum, GLenum, const GLfloat *);
#define glFragmentMaterialfvSGIX _ptrc_glFragmentMaterialfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialiSGIX)(GLenum, GLenum, GLint);
#define glFragmentMaterialiSGIX _ptrc_glFragmentMaterialiSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialivSGIX)(GLenum, GLenum, const GLint *);
#define glFragmentMaterialivSGIX _ptrc_glFragmentMaterialivSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentLightfvSGIX)(GLenum, GLenum, GLfloat *);
#define glGetFragmentLightfvSGIX _ptrc_glGetFragmentLightfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentLightivSGIX)(GLenum, GLenum, GLint *);
#define glGetFragmentLightivSGIX _ptrc_glGetFragmentLightivSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentMaterialfvSGIX)(GLenum, GLenum, GLfloat *);
#define glGetFragmentMaterialfvSGIX _ptrc_glGetFragmentMaterialfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentMaterialivSGIX)(GLenum, GLenum, GLint *);
#define glGetFragmentMaterialivSGIX _ptrc_glGetFragmentMaterialivSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glLightEnviSGIX)(GLenum, GLint);
#define glLightEnviSGIX _ptrc_glLightEnviSGIX
#endif /*GL_SGIX_fragment_lighting*/ 

#ifndef GL_SGIX_framezoom
#define GL_SGIX_framezoom 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFrameZoomSGIX)(GLint);
#define glFrameZoomSGIX _ptrc_glFrameZoomSGIX
#endif /*GL_SGIX_framezoom*/ 

#ifndef GL_SGIX_igloo_interface
#define GL_SGIX_igloo_interface 1
extern void (CODEGEN_FUNCPTR *_ptrc_glIglooInterfaceSGIX)(GLenum, const GLvoid *);
#define glIglooInterfaceSGIX _ptrc_glIglooInterfaceSGIX
#endif /*GL_SGIX_igloo_interface*/ 

#ifndef GL_SGIX_instruments
#define GL_SGIX_instruments 1
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetInstrumentsSGIX)();
#define glGetInstrumentsSGIX _ptrc_glGetInstrumentsSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glInstrumentsBufferSGIX)(GLsizei, GLint *);
#define glInstrumentsBufferSGIX _ptrc_glInstrumentsBufferSGIX
extern GLint (CODEGEN_FUNCPTR *_ptrc_glPollInstrumentsSGIX)(GLint *);
#define glPollInstrumentsSGIX _ptrc_glPollInstrumentsSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glReadInstrumentsSGIX)(GLint);
#define glReadInstrumentsSGIX _ptrc_glReadInstrumentsSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glStartInstrumentsSGIX)();
#define glStartInstrumentsSGIX _ptrc_glStartInstrumentsSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glStopInstrumentsSGIX)(GLint);
#define glStopInstrumentsSGIX _ptrc_glStopInstrumentsSGIX
#endif /*GL_SGIX_instruments*/ 



#ifndef GL_SGIX_list_priority
#define GL_SGIX_list_priority 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGetListParameterfvSGIX)(GLuint, GLenum, GLfloat *);
#define glGetListParameterfvSGIX _ptrc_glGetListParameterfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glGetListParameterivSGIX)(GLuint, GLenum, GLint *);
#define glGetListParameterivSGIX _ptrc_glGetListParameterivSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glListParameterfSGIX)(GLuint, GLenum, GLfloat);
#define glListParameterfSGIX _ptrc_glListParameterfSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glListParameterfvSGIX)(GLuint, GLenum, const GLfloat *);
#define glListParameterfvSGIX _ptrc_glListParameterfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glListParameteriSGIX)(GLuint, GLenum, GLint);
#define glListParameteriSGIX _ptrc_glListParameteriSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glListParameterivSGIX)(GLuint, GLenum, const GLint *);
#define glListParameterivSGIX _ptrc_glListParameterivSGIX
#endif /*GL_SGIX_list_priority*/ 

#ifndef GL_SGIX_pixel_texture
#define GL_SGIX_pixel_texture 1
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenSGIX)(GLenum);
#define glPixelTexGenSGIX _ptrc_glPixelTexGenSGIX
#endif /*GL_SGIX_pixel_texture*/ 


#ifndef GL_SGIX_polynomial_ffd
#define GL_SGIX_polynomial_ffd 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDeformSGIX)(GLbitfield);
#define glDeformSGIX _ptrc_glDeformSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glDeformationMap3dSGIX)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
#define glDeformationMap3dSGIX _ptrc_glDeformationMap3dSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glDeformationMap3fSGIX)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
#define glDeformationMap3fSGIX _ptrc_glDeformationMap3fSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadIdentityDeformationMapSGIX)(GLbitfield);
#define glLoadIdentityDeformationMapSGIX _ptrc_glLoadIdentityDeformationMapSGIX
#endif /*GL_SGIX_polynomial_ffd*/ 

#ifndef GL_SGIX_reference_plane
#define GL_SGIX_reference_plane 1
extern void (CODEGEN_FUNCPTR *_ptrc_glReferencePlaneSGIX)(const GLdouble *);
#define glReferencePlaneSGIX _ptrc_glReferencePlaneSGIX
#endif /*GL_SGIX_reference_plane*/ 





#ifndef GL_SGIX_sprite
#define GL_SGIX_sprite 1
extern void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameterfSGIX)(GLenum, GLfloat);
#define glSpriteParameterfSGIX _ptrc_glSpriteParameterfSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameterfvSGIX)(GLenum, const GLfloat *);
#define glSpriteParameterfvSGIX _ptrc_glSpriteParameterfvSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameteriSGIX)(GLenum, GLint);
#define glSpriteParameteriSGIX _ptrc_glSpriteParameteriSGIX
extern void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameterivSGIX)(GLenum, const GLint *);
#define glSpriteParameterivSGIX _ptrc_glSpriteParameterivSGIX
#endif /*GL_SGIX_sprite*/ 


#ifndef GL_SGIX_tag_sample_buffer
#define GL_SGIX_tag_sample_buffer 1
extern void (CODEGEN_FUNCPTR *_ptrc_glTagSampleBufferSGIX)();
#define glTagSampleBufferSGIX _ptrc_glTagSampleBufferSGIX
#endif /*GL_SGIX_tag_sample_buffer*/ 











#ifndef GL_SGI_color_table
#define GL_SGI_color_table 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterfvSGI)(GLenum, GLenum, const GLfloat *);
#define glColorTableParameterfvSGI _ptrc_glColorTableParameterfvSGI
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterivSGI)(GLenum, GLenum, const GLint *);
#define glColorTableParameterivSGI _ptrc_glColorTableParameterivSGI
extern void (CODEGEN_FUNCPTR *_ptrc_glColorTableSGI)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *);
#define glColorTableSGI _ptrc_glColorTableSGI
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyColorTableSGI)(GLenum, GLenum, GLint, GLint, GLsizei);
#define glCopyColorTableSGI _ptrc_glCopyColorTableSGI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfvSGI)(GLenum, GLenum, GLfloat *);
#define glGetColorTableParameterfvSGI _ptrc_glGetColorTableParameterfvSGI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterivSGI)(GLenum, GLenum, GLint *);
#define glGetColorTableParameterivSGI _ptrc_glGetColorTableParameterivSGI
extern void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableSGI)(GLenum, GLenum, GLenum, GLvoid *);
#define glGetColorTableSGI _ptrc_glGetColorTableSGI
#endif /*GL_SGI_color_table*/ 


#ifndef GL_SUNX_constant_data
#define GL_SUNX_constant_data 1
extern void (CODEGEN_FUNCPTR *_ptrc_glFinishTextureSUNX)();
#define glFinishTextureSUNX _ptrc_glFinishTextureSUNX
#endif /*GL_SUNX_constant_data*/ 


#ifndef GL_SUN_global_alpha
#define GL_SUN_global_alpha 1
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorbSUN)(GLbyte);
#define glGlobalAlphaFactorbSUN _ptrc_glGlobalAlphaFactorbSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactordSUN)(GLdouble);
#define glGlobalAlphaFactordSUN _ptrc_glGlobalAlphaFactordSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorfSUN)(GLfloat);
#define glGlobalAlphaFactorfSUN _ptrc_glGlobalAlphaFactorfSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactoriSUN)(GLint);
#define glGlobalAlphaFactoriSUN _ptrc_glGlobalAlphaFactoriSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorsSUN)(GLshort);
#define glGlobalAlphaFactorsSUN _ptrc_glGlobalAlphaFactorsSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorubSUN)(GLubyte);
#define glGlobalAlphaFactorubSUN _ptrc_glGlobalAlphaFactorubSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactoruiSUN)(GLuint);
#define glGlobalAlphaFactoruiSUN _ptrc_glGlobalAlphaFactoruiSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorusSUN)(GLushort);
#define glGlobalAlphaFactorusSUN _ptrc_glGlobalAlphaFactorusSUN
#endif /*GL_SUN_global_alpha*/ 

#ifndef GL_SUN_mesh_array
#define GL_SUN_mesh_array 1
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawMeshArraysSUN)(GLenum, GLint, GLsizei, GLsizei);
#define glDrawMeshArraysSUN _ptrc_glDrawMeshArraysSUN
#endif /*GL_SUN_mesh_array*/ 


#ifndef GL_SUN_triangle_list
#define GL_SUN_triangle_list 1
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodePointerSUN)(GLenum, GLsizei, const GLvoid **);
#define glReplacementCodePointerSUN _ptrc_glReplacementCodePointerSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeubSUN)(GLubyte);
#define glReplacementCodeubSUN _ptrc_glReplacementCodeubSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeubvSUN)(const GLubyte *);
#define glReplacementCodeubvSUN _ptrc_glReplacementCodeubvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiSUN)(GLuint);
#define glReplacementCodeuiSUN _ptrc_glReplacementCodeuiSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuivSUN)(const GLuint *);
#define glReplacementCodeuivSUN _ptrc_glReplacementCodeuivSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeusSUN)(GLushort);
#define glReplacementCodeusSUN _ptrc_glReplacementCodeusSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeusvSUN)(const GLushort *);
#define glReplacementCodeusvSUN _ptrc_glReplacementCodeusvSUN
#endif /*GL_SUN_triangle_list*/ 

#ifndef GL_SUN_vertex
#define GL_SUN_vertex 1
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glColor3fVertex3fSUN _ptrc_glColor3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3fVertex3fvSUN)(const GLfloat *, const GLfloat *);
#define glColor3fVertex3fvSUN _ptrc_glColor3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4fNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glColor4fNormal3fVertex3fSUN _ptrc_glColor4fNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4fNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *);
#define glColor4fNormal3fVertex3fvSUN _ptrc_glColor4fNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex2fSUN)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat);
#define glColor4ubVertex2fSUN _ptrc_glColor4ubVertex2fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex2fvSUN)(const GLubyte *, const GLfloat *);
#define glColor4ubVertex2fvSUN _ptrc_glColor4ubVertex2fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex3fSUN)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
#define glColor4ubVertex3fSUN _ptrc_glColor4ubVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex3fvSUN)(const GLubyte *, const GLfloat *);
#define glColor4ubVertex3fvSUN _ptrc_glColor4ubVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glNormal3fVertex3fSUN _ptrc_glNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *);
#define glNormal3fVertex3fvSUN _ptrc_glNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiColor3fVertex3fSUN _ptrc_glReplacementCodeuiColor3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *);
#define glReplacementCodeuiColor3fVertex3fvSUN _ptrc_glReplacementCodeuiColor3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiColor4fNormal3fVertex3fSUN _ptrc_glReplacementCodeuiColor4fNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *);
#define glReplacementCodeuiColor4fNormal3fVertex3fvSUN _ptrc_glReplacementCodeuiColor4fNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4ubVertex3fSUN)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiColor4ubVertex3fSUN _ptrc_glReplacementCodeuiColor4ubVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4ubVertex3fvSUN)(const GLuint *, const GLubyte *, const GLfloat *);
#define glReplacementCodeuiColor4ubVertex3fvSUN _ptrc_glReplacementCodeuiColor4ubVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiNormal3fVertex3fSUN _ptrc_glReplacementCodeuiNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *);
#define glReplacementCodeuiNormal3fVertex3fvSUN _ptrc_glReplacementCodeuiNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN _ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN _ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN _ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *);
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN _ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiTexCoord2fVertex3fSUN _ptrc_glReplacementCodeuiTexCoord2fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *);
#define glReplacementCodeuiTexCoord2fVertex3fvSUN _ptrc_glReplacementCodeuiTexCoord2fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat);
#define glReplacementCodeuiVertex3fSUN _ptrc_glReplacementCodeuiVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiVertex3fvSUN)(const GLuint *, const GLfloat *);
#define glReplacementCodeuiVertex3fvSUN _ptrc_glReplacementCodeuiVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glTexCoord2fColor3fVertex3fSUN _ptrc_glTexCoord2fColor3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *);
#define glTexCoord2fColor3fVertex3fvSUN _ptrc_glTexCoord2fColor3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4fNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glTexCoord2fColor4fNormal3fVertex3fSUN _ptrc_glTexCoord2fColor4fNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
#define glTexCoord2fColor4fNormal3fVertex3fvSUN _ptrc_glTexCoord2fColor4fNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4ubVertex3fSUN)(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat);
#define glTexCoord2fColor4ubVertex3fSUN _ptrc_glTexCoord2fColor4ubVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4ubVertex3fvSUN)(const GLfloat *, const GLubyte *, const GLfloat *);
#define glTexCoord2fColor4ubVertex3fvSUN _ptrc_glTexCoord2fColor4ubVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glTexCoord2fNormal3fVertex3fSUN _ptrc_glTexCoord2fNormal3fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *);
#define glTexCoord2fNormal3fVertex3fvSUN _ptrc_glTexCoord2fNormal3fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glTexCoord2fVertex3fSUN _ptrc_glTexCoord2fVertex3fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fVertex3fvSUN)(const GLfloat *, const GLfloat *);
#define glTexCoord2fVertex3fvSUN _ptrc_glTexCoord2fVertex3fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fColor4fNormal3fVertex4fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glTexCoord4fColor4fNormal3fVertex4fSUN _ptrc_glTexCoord4fColor4fNormal3fVertex4fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fColor4fNormal3fVertex4fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
#define glTexCoord4fColor4fNormal3fVertex4fvSUN _ptrc_glTexCoord4fColor4fNormal3fVertex4fvSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fVertex4fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
#define glTexCoord4fVertex4fSUN _ptrc_glTexCoord4fVertex4fSUN
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fVertex4fvSUN)(const GLfloat *, const GLfloat *);
#define glTexCoord4fVertex4fvSUN _ptrc_glTexCoord4fVertex4fvSUN
#endif /*GL_SUN_vertex*/ 



extern void (CODEGEN_FUNCPTR *_ptrc_glAccum)(GLenum, GLfloat);
#define glAccum _ptrc_glAccum
extern void (CODEGEN_FUNCPTR *_ptrc_glAlphaFunc)(GLenum, GLfloat);
#define glAlphaFunc _ptrc_glAlphaFunc
extern void (CODEGEN_FUNCPTR *_ptrc_glBegin)(GLenum);
#define glBegin _ptrc_glBegin
extern void (CODEGEN_FUNCPTR *_ptrc_glBitmap)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *);
#define glBitmap _ptrc_glBitmap
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFunc)(GLenum, GLenum);
#define glBlendFunc _ptrc_glBlendFunc
extern void (CODEGEN_FUNCPTR *_ptrc_glCallList)(GLuint);
#define glCallList _ptrc_glCallList
extern void (CODEGEN_FUNCPTR *_ptrc_glCallLists)(GLsizei, GLenum, const GLvoid *);
#define glCallLists _ptrc_glCallLists
extern void (CODEGEN_FUNCPTR *_ptrc_glClear)(GLbitfield);
#define glClear _ptrc_glClear
extern void (CODEGEN_FUNCPTR *_ptrc_glClearAccum)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glClearAccum _ptrc_glClearAccum
extern void (CODEGEN_FUNCPTR *_ptrc_glClearColor)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glClearColor _ptrc_glClearColor
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepth)(GLdouble);
#define glClearDepth _ptrc_glClearDepth
extern void (CODEGEN_FUNCPTR *_ptrc_glClearIndex)(GLfloat);
#define glClearIndex _ptrc_glClearIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glClearStencil)(GLint);
#define glClearStencil _ptrc_glClearStencil
extern void (CODEGEN_FUNCPTR *_ptrc_glClipPlane)(GLenum, const GLdouble *);
#define glClipPlane _ptrc_glClipPlane
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3b)(GLbyte, GLbyte, GLbyte);
#define glColor3b _ptrc_glColor3b
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3bv)(const GLbyte *);
#define glColor3bv _ptrc_glColor3bv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3d)(GLdouble, GLdouble, GLdouble);
#define glColor3d _ptrc_glColor3d
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3dv)(const GLdouble *);
#define glColor3dv _ptrc_glColor3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3f)(GLfloat, GLfloat, GLfloat);
#define glColor3f _ptrc_glColor3f
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3fv)(const GLfloat *);
#define glColor3fv _ptrc_glColor3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3i)(GLint, GLint, GLint);
#define glColor3i _ptrc_glColor3i
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3iv)(const GLint *);
#define glColor3iv _ptrc_glColor3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3s)(GLshort, GLshort, GLshort);
#define glColor3s _ptrc_glColor3s
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3sv)(const GLshort *);
#define glColor3sv _ptrc_glColor3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3ub)(GLubyte, GLubyte, GLubyte);
#define glColor3ub _ptrc_glColor3ub
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3ubv)(const GLubyte *);
#define glColor3ubv _ptrc_glColor3ubv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3ui)(GLuint, GLuint, GLuint);
#define glColor3ui _ptrc_glColor3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3uiv)(const GLuint *);
#define glColor3uiv _ptrc_glColor3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3us)(GLushort, GLushort, GLushort);
#define glColor3us _ptrc_glColor3us
extern void (CODEGEN_FUNCPTR *_ptrc_glColor3usv)(const GLushort *);
#define glColor3usv _ptrc_glColor3usv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4b)(GLbyte, GLbyte, GLbyte, GLbyte);
#define glColor4b _ptrc_glColor4b
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4bv)(const GLbyte *);
#define glColor4bv _ptrc_glColor4bv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define glColor4d _ptrc_glColor4d
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4dv)(const GLdouble *);
#define glColor4dv _ptrc_glColor4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glColor4f _ptrc_glColor4f
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4fv)(const GLfloat *);
#define glColor4fv _ptrc_glColor4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4i)(GLint, GLint, GLint, GLint);
#define glColor4i _ptrc_glColor4i
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4iv)(const GLint *);
#define glColor4iv _ptrc_glColor4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4s)(GLshort, GLshort, GLshort, GLshort);
#define glColor4s _ptrc_glColor4s
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4sv)(const GLshort *);
#define glColor4sv _ptrc_glColor4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4ub)(GLubyte, GLubyte, GLubyte, GLubyte);
#define glColor4ub _ptrc_glColor4ub
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4ubv)(const GLubyte *);
#define glColor4ubv _ptrc_glColor4ubv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4ui)(GLuint, GLuint, GLuint, GLuint);
#define glColor4ui _ptrc_glColor4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4uiv)(const GLuint *);
#define glColor4uiv _ptrc_glColor4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4us)(GLushort, GLushort, GLushort, GLushort);
#define glColor4us _ptrc_glColor4us
extern void (CODEGEN_FUNCPTR *_ptrc_glColor4usv)(const GLushort *);
#define glColor4usv _ptrc_glColor4usv
extern void (CODEGEN_FUNCPTR *_ptrc_glColorMask)(GLboolean, GLboolean, GLboolean, GLboolean);
#define glColorMask _ptrc_glColorMask
extern void (CODEGEN_FUNCPTR *_ptrc_glColorMaterial)(GLenum, GLenum);
#define glColorMaterial _ptrc_glColorMaterial
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyPixels)(GLint, GLint, GLsizei, GLsizei, GLenum);
#define glCopyPixels _ptrc_glCopyPixels
extern void (CODEGEN_FUNCPTR *_ptrc_glCullFace)(GLenum);
#define glCullFace _ptrc_glCullFace
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteLists)(GLuint, GLsizei);
#define glDeleteLists _ptrc_glDeleteLists
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthFunc)(GLenum);
#define glDepthFunc _ptrc_glDepthFunc
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthMask)(GLboolean);
#define glDepthMask _ptrc_glDepthMask
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRange)(GLdouble, GLdouble);
#define glDepthRange _ptrc_glDepthRange
extern void (CODEGEN_FUNCPTR *_ptrc_glDisable)(GLenum);
#define glDisable _ptrc_glDisable
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffer)(GLenum);
#define glDrawBuffer _ptrc_glDrawBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawPixels)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glDrawPixels _ptrc_glDrawPixels
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlag)(GLboolean);
#define glEdgeFlag _ptrc_glEdgeFlag
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagv)(const GLboolean *);
#define glEdgeFlagv _ptrc_glEdgeFlagv
extern void (CODEGEN_FUNCPTR *_ptrc_glEnable)(GLenum);
#define glEnable _ptrc_glEnable
extern void (CODEGEN_FUNCPTR *_ptrc_glEnd)();
#define glEnd _ptrc_glEnd
extern void (CODEGEN_FUNCPTR *_ptrc_glEndList)();
#define glEndList _ptrc_glEndList
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1d)(GLdouble);
#define glEvalCoord1d _ptrc_glEvalCoord1d
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1dv)(const GLdouble *);
#define glEvalCoord1dv _ptrc_glEvalCoord1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1f)(GLfloat);
#define glEvalCoord1f _ptrc_glEvalCoord1f
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1fv)(const GLfloat *);
#define glEvalCoord1fv _ptrc_glEvalCoord1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2d)(GLdouble, GLdouble);
#define glEvalCoord2d _ptrc_glEvalCoord2d
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2dv)(const GLdouble *);
#define glEvalCoord2dv _ptrc_glEvalCoord2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2f)(GLfloat, GLfloat);
#define glEvalCoord2f _ptrc_glEvalCoord2f
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2fv)(const GLfloat *);
#define glEvalCoord2fv _ptrc_glEvalCoord2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalMesh1)(GLenum, GLint, GLint);
#define glEvalMesh1 _ptrc_glEvalMesh1
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalMesh2)(GLenum, GLint, GLint, GLint, GLint);
#define glEvalMesh2 _ptrc_glEvalMesh2
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalPoint1)(GLint);
#define glEvalPoint1 _ptrc_glEvalPoint1
extern void (CODEGEN_FUNCPTR *_ptrc_glEvalPoint2)(GLint, GLint);
#define glEvalPoint2 _ptrc_glEvalPoint2
extern void (CODEGEN_FUNCPTR *_ptrc_glFeedbackBuffer)(GLsizei, GLenum, GLfloat *);
#define glFeedbackBuffer _ptrc_glFeedbackBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glFinish)();
#define glFinish _ptrc_glFinish
extern void (CODEGEN_FUNCPTR *_ptrc_glFlush)();
#define glFlush _ptrc_glFlush
extern void (CODEGEN_FUNCPTR *_ptrc_glFogf)(GLenum, GLfloat);
#define glFogf _ptrc_glFogf
extern void (CODEGEN_FUNCPTR *_ptrc_glFogfv)(GLenum, const GLfloat *);
#define glFogfv _ptrc_glFogfv
extern void (CODEGEN_FUNCPTR *_ptrc_glFogi)(GLenum, GLint);
#define glFogi _ptrc_glFogi
extern void (CODEGEN_FUNCPTR *_ptrc_glFogiv)(GLenum, const GLint *);
#define glFogiv _ptrc_glFogiv
extern void (CODEGEN_FUNCPTR *_ptrc_glFrontFace)(GLenum);
#define glFrontFace _ptrc_glFrontFace
extern void (CODEGEN_FUNCPTR *_ptrc_glFrustum)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
#define glFrustum _ptrc_glFrustum
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGenLists)(GLsizei);
#define glGenLists _ptrc_glGenLists
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanv)(GLenum, GLboolean *);
#define glGetBooleanv _ptrc_glGetBooleanv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetClipPlane)(GLenum, GLdouble *);
#define glGetClipPlane _ptrc_glGetClipPlane
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublev)(GLenum, GLdouble *);
#define glGetDoublev _ptrc_glGetDoublev
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glGetError)();
#define glGetError _ptrc_glGetError
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloatv)(GLenum, GLfloat *);
#define glGetFloatv _ptrc_glGetFloatv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerv)(GLenum, GLint *);
#define glGetIntegerv _ptrc_glGetIntegerv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetLightfv)(GLenum, GLenum, GLfloat *);
#define glGetLightfv _ptrc_glGetLightfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetLightiv)(GLenum, GLenum, GLint *);
#define glGetLightiv _ptrc_glGetLightiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapdv)(GLenum, GLenum, GLdouble *);
#define glGetMapdv _ptrc_glGetMapdv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapfv)(GLenum, GLenum, GLfloat *);
#define glGetMapfv _ptrc_glGetMapfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMapiv)(GLenum, GLenum, GLint *);
#define glGetMapiv _ptrc_glGetMapiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMaterialfv)(GLenum, GLenum, GLfloat *);
#define glGetMaterialfv _ptrc_glGetMaterialfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMaterialiv)(GLenum, GLenum, GLint *);
#define glGetMaterialiv _ptrc_glGetMaterialiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapfv)(GLenum, GLfloat *);
#define glGetPixelMapfv _ptrc_glGetPixelMapfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapuiv)(GLenum, GLuint *);
#define glGetPixelMapuiv _ptrc_glGetPixelMapuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapusv)(GLenum, GLushort *);
#define glGetPixelMapusv _ptrc_glGetPixelMapusv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPolygonStipple)(GLubyte *);
#define glGetPolygonStipple _ptrc_glGetPolygonStipple
extern const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetString)(GLenum);
#define glGetString _ptrc_glGetString
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexEnvfv)(GLenum, GLenum, GLfloat *);
#define glGetTexEnvfv _ptrc_glGetTexEnvfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexEnviv)(GLenum, GLenum, GLint *);
#define glGetTexEnviv _ptrc_glGetTexEnviv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexGendv)(GLenum, GLenum, GLdouble *);
#define glGetTexGendv _ptrc_glGetTexGendv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexGenfv)(GLenum, GLenum, GLfloat *);
#define glGetTexGenfv _ptrc_glGetTexGenfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexGeniv)(GLenum, GLenum, GLint *);
#define glGetTexGeniv _ptrc_glGetTexGeniv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexImage)(GLenum, GLint, GLenum, GLenum, GLvoid *);
#define glGetTexImage _ptrc_glGetTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameterfv)(GLenum, GLint, GLenum, GLfloat *);
#define glGetTexLevelParameterfv _ptrc_glGetTexLevelParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameteriv)(GLenum, GLint, GLenum, GLint *);
#define glGetTexLevelParameteriv _ptrc_glGetTexLevelParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterfv)(GLenum, GLenum, GLfloat *);
#define glGetTexParameterfv _ptrc_glGetTexParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameteriv)(GLenum, GLenum, GLint *);
#define glGetTexParameteriv _ptrc_glGetTexParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glHint)(GLenum, GLenum);
#define glHint _ptrc_glHint
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexMask)(GLuint);
#define glIndexMask _ptrc_glIndexMask
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexd)(GLdouble);
#define glIndexd _ptrc_glIndexd
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexdv)(const GLdouble *);
#define glIndexdv _ptrc_glIndexdv
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexf)(GLfloat);
#define glIndexf _ptrc_glIndexf
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexfv)(const GLfloat *);
#define glIndexfv _ptrc_glIndexfv
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexi)(GLint);
#define glIndexi _ptrc_glIndexi
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexiv)(const GLint *);
#define glIndexiv _ptrc_glIndexiv
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexs)(GLshort);
#define glIndexs _ptrc_glIndexs
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexsv)(const GLshort *);
#define glIndexsv _ptrc_glIndexsv
extern void (CODEGEN_FUNCPTR *_ptrc_glInitNames)();
#define glInitNames _ptrc_glInitNames
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabled)(GLenum);
#define glIsEnabled _ptrc_glIsEnabled
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsList)(GLuint);
#define glIsList _ptrc_glIsList
extern void (CODEGEN_FUNCPTR *_ptrc_glLightModelf)(GLenum, GLfloat);
#define glLightModelf _ptrc_glLightModelf
extern void (CODEGEN_FUNCPTR *_ptrc_glLightModelfv)(GLenum, const GLfloat *);
#define glLightModelfv _ptrc_glLightModelfv
extern void (CODEGEN_FUNCPTR *_ptrc_glLightModeli)(GLenum, GLint);
#define glLightModeli _ptrc_glLightModeli
extern void (CODEGEN_FUNCPTR *_ptrc_glLightModeliv)(GLenum, const GLint *);
#define glLightModeliv _ptrc_glLightModeliv
extern void (CODEGEN_FUNCPTR *_ptrc_glLightf)(GLenum, GLenum, GLfloat);
#define glLightf _ptrc_glLightf
extern void (CODEGEN_FUNCPTR *_ptrc_glLightfv)(GLenum, GLenum, const GLfloat *);
#define glLightfv _ptrc_glLightfv
extern void (CODEGEN_FUNCPTR *_ptrc_glLighti)(GLenum, GLenum, GLint);
#define glLighti _ptrc_glLighti
extern void (CODEGEN_FUNCPTR *_ptrc_glLightiv)(GLenum, GLenum, const GLint *);
#define glLightiv _ptrc_glLightiv
extern void (CODEGEN_FUNCPTR *_ptrc_glLineStipple)(GLint, GLushort);
#define glLineStipple _ptrc_glLineStipple
extern void (CODEGEN_FUNCPTR *_ptrc_glLineWidth)(GLfloat);
#define glLineWidth _ptrc_glLineWidth
extern void (CODEGEN_FUNCPTR *_ptrc_glListBase)(GLuint);
#define glListBase _ptrc_glListBase
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadIdentity)();
#define glLoadIdentity _ptrc_glLoadIdentity
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadMatrixd)(const GLdouble *);
#define glLoadMatrixd _ptrc_glLoadMatrixd
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadMatrixf)(const GLfloat *);
#define glLoadMatrixf _ptrc_glLoadMatrixf
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadName)(GLuint);
#define glLoadName _ptrc_glLoadName
extern void (CODEGEN_FUNCPTR *_ptrc_glLogicOp)(GLenum);
#define glLogicOp _ptrc_glLogicOp
extern void (CODEGEN_FUNCPTR *_ptrc_glMap1d)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
#define glMap1d _ptrc_glMap1d
extern void (CODEGEN_FUNCPTR *_ptrc_glMap1f)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
#define glMap1f _ptrc_glMap1f
extern void (CODEGEN_FUNCPTR *_ptrc_glMap2d)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
#define glMap2d _ptrc_glMap2d
extern void (CODEGEN_FUNCPTR *_ptrc_glMap2f)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
#define glMap2f _ptrc_glMap2f
extern void (CODEGEN_FUNCPTR *_ptrc_glMapGrid1d)(GLint, GLdouble, GLdouble);
#define glMapGrid1d _ptrc_glMapGrid1d
extern void (CODEGEN_FUNCPTR *_ptrc_glMapGrid1f)(GLint, GLfloat, GLfloat);
#define glMapGrid1f _ptrc_glMapGrid1f
extern void (CODEGEN_FUNCPTR *_ptrc_glMapGrid2d)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
#define glMapGrid2d _ptrc_glMapGrid2d
extern void (CODEGEN_FUNCPTR *_ptrc_glMapGrid2f)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
#define glMapGrid2f _ptrc_glMapGrid2f
extern void (CODEGEN_FUNCPTR *_ptrc_glMaterialf)(GLenum, GLenum, GLfloat);
#define glMaterialf _ptrc_glMaterialf
extern void (CODEGEN_FUNCPTR *_ptrc_glMaterialfv)(GLenum, GLenum, const GLfloat *);
#define glMaterialfv _ptrc_glMaterialfv
extern void (CODEGEN_FUNCPTR *_ptrc_glMateriali)(GLenum, GLenum, GLint);
#define glMateriali _ptrc_glMateriali
extern void (CODEGEN_FUNCPTR *_ptrc_glMaterialiv)(GLenum, GLenum, const GLint *);
#define glMaterialiv _ptrc_glMaterialiv
extern void (CODEGEN_FUNCPTR *_ptrc_glMatrixMode)(GLenum);
#define glMatrixMode _ptrc_glMatrixMode
extern void (CODEGEN_FUNCPTR *_ptrc_glMultMatrixd)(const GLdouble *);
#define glMultMatrixd _ptrc_glMultMatrixd
extern void (CODEGEN_FUNCPTR *_ptrc_glMultMatrixf)(const GLfloat *);
#define glMultMatrixf _ptrc_glMultMatrixf
extern void (CODEGEN_FUNCPTR *_ptrc_glNewList)(GLuint, GLenum);
#define glNewList _ptrc_glNewList
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3b)(GLbyte, GLbyte, GLbyte);
#define glNormal3b _ptrc_glNormal3b
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3bv)(const GLbyte *);
#define glNormal3bv _ptrc_glNormal3bv
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3d)(GLdouble, GLdouble, GLdouble);
#define glNormal3d _ptrc_glNormal3d
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3dv)(const GLdouble *);
#define glNormal3dv _ptrc_glNormal3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3f)(GLfloat, GLfloat, GLfloat);
#define glNormal3f _ptrc_glNormal3f
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3fv)(const GLfloat *);
#define glNormal3fv _ptrc_glNormal3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3i)(GLint, GLint, GLint);
#define glNormal3i _ptrc_glNormal3i
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3iv)(const GLint *);
#define glNormal3iv _ptrc_glNormal3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3s)(GLshort, GLshort, GLshort);
#define glNormal3s _ptrc_glNormal3s
extern void (CODEGEN_FUNCPTR *_ptrc_glNormal3sv)(const GLshort *);
#define glNormal3sv _ptrc_glNormal3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glOrtho)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
#define glOrtho _ptrc_glOrtho
extern void (CODEGEN_FUNCPTR *_ptrc_glPassThrough)(GLfloat);
#define glPassThrough _ptrc_glPassThrough
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelMapfv)(GLenum, GLsizei, const GLfloat *);
#define glPixelMapfv _ptrc_glPixelMapfv
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelMapuiv)(GLenum, GLsizei, const GLuint *);
#define glPixelMapuiv _ptrc_glPixelMapuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelMapusv)(GLenum, GLsizei, const GLushort *);
#define glPixelMapusv _ptrc_glPixelMapusv
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelStoref)(GLenum, GLfloat);
#define glPixelStoref _ptrc_glPixelStoref
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelStorei)(GLenum, GLint);
#define glPixelStorei _ptrc_glPixelStorei
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTransferf)(GLenum, GLfloat);
#define glPixelTransferf _ptrc_glPixelTransferf
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelTransferi)(GLenum, GLint);
#define glPixelTransferi _ptrc_glPixelTransferi
extern void (CODEGEN_FUNCPTR *_ptrc_glPixelZoom)(GLfloat, GLfloat);
#define glPixelZoom _ptrc_glPixelZoom
extern void (CODEGEN_FUNCPTR *_ptrc_glPointSize)(GLfloat);
#define glPointSize _ptrc_glPointSize
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonMode)(GLenum, GLenum);
#define glPolygonMode _ptrc_glPolygonMode
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonStipple)(const GLubyte *);
#define glPolygonStipple _ptrc_glPolygonStipple
extern void (CODEGEN_FUNCPTR *_ptrc_glPopAttrib)();
#define glPopAttrib _ptrc_glPopAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glPopMatrix)();
#define glPopMatrix _ptrc_glPopMatrix
extern void (CODEGEN_FUNCPTR *_ptrc_glPopName)();
#define glPopName _ptrc_glPopName
extern void (CODEGEN_FUNCPTR *_ptrc_glPushAttrib)(GLbitfield);
#define glPushAttrib _ptrc_glPushAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glPushMatrix)();
#define glPushMatrix _ptrc_glPushMatrix
extern void (CODEGEN_FUNCPTR *_ptrc_glPushName)(GLuint);
#define glPushName _ptrc_glPushName
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2d)(GLdouble, GLdouble);
#define glRasterPos2d _ptrc_glRasterPos2d
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2dv)(const GLdouble *);
#define glRasterPos2dv _ptrc_glRasterPos2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2f)(GLfloat, GLfloat);
#define glRasterPos2f _ptrc_glRasterPos2f
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2fv)(const GLfloat *);
#define glRasterPos2fv _ptrc_glRasterPos2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2i)(GLint, GLint);
#define glRasterPos2i _ptrc_glRasterPos2i
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2iv)(const GLint *);
#define glRasterPos2iv _ptrc_glRasterPos2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2s)(GLshort, GLshort);
#define glRasterPos2s _ptrc_glRasterPos2s
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2sv)(const GLshort *);
#define glRasterPos2sv _ptrc_glRasterPos2sv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3d)(GLdouble, GLdouble, GLdouble);
#define glRasterPos3d _ptrc_glRasterPos3d
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3dv)(const GLdouble *);
#define glRasterPos3dv _ptrc_glRasterPos3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3f)(GLfloat, GLfloat, GLfloat);
#define glRasterPos3f _ptrc_glRasterPos3f
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3fv)(const GLfloat *);
#define glRasterPos3fv _ptrc_glRasterPos3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3i)(GLint, GLint, GLint);
#define glRasterPos3i _ptrc_glRasterPos3i
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3iv)(const GLint *);
#define glRasterPos3iv _ptrc_glRasterPos3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3s)(GLshort, GLshort, GLshort);
#define glRasterPos3s _ptrc_glRasterPos3s
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3sv)(const GLshort *);
#define glRasterPos3sv _ptrc_glRasterPos3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define glRasterPos4d _ptrc_glRasterPos4d
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4dv)(const GLdouble *);
#define glRasterPos4dv _ptrc_glRasterPos4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glRasterPos4f _ptrc_glRasterPos4f
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4fv)(const GLfloat *);
#define glRasterPos4fv _ptrc_glRasterPos4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4i)(GLint, GLint, GLint, GLint);
#define glRasterPos4i _ptrc_glRasterPos4i
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4iv)(const GLint *);
#define glRasterPos4iv _ptrc_glRasterPos4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4s)(GLshort, GLshort, GLshort, GLshort);
#define glRasterPos4s _ptrc_glRasterPos4s
extern void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4sv)(const GLshort *);
#define glRasterPos4sv _ptrc_glRasterPos4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glReadBuffer)(GLenum);
#define glReadBuffer _ptrc_glReadBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
#define glReadPixels _ptrc_glReadPixels
extern void (CODEGEN_FUNCPTR *_ptrc_glRectd)(GLdouble, GLdouble, GLdouble, GLdouble);
#define glRectd _ptrc_glRectd
extern void (CODEGEN_FUNCPTR *_ptrc_glRectdv)(const GLdouble *, const GLdouble *);
#define glRectdv _ptrc_glRectdv
extern void (CODEGEN_FUNCPTR *_ptrc_glRectf)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glRectf _ptrc_glRectf
extern void (CODEGEN_FUNCPTR *_ptrc_glRectfv)(const GLfloat *, const GLfloat *);
#define glRectfv _ptrc_glRectfv
extern void (CODEGEN_FUNCPTR *_ptrc_glRecti)(GLint, GLint, GLint, GLint);
#define glRecti _ptrc_glRecti
extern void (CODEGEN_FUNCPTR *_ptrc_glRectiv)(const GLint *, const GLint *);
#define glRectiv _ptrc_glRectiv
extern void (CODEGEN_FUNCPTR *_ptrc_glRects)(GLshort, GLshort, GLshort, GLshort);
#define glRects _ptrc_glRects
extern void (CODEGEN_FUNCPTR *_ptrc_glRectsv)(const GLshort *, const GLshort *);
#define glRectsv _ptrc_glRectsv
extern GLint (CODEGEN_FUNCPTR *_ptrc_glRenderMode)(GLenum);
#define glRenderMode _ptrc_glRenderMode
extern void (CODEGEN_FUNCPTR *_ptrc_glRotated)(GLdouble, GLdouble, GLdouble, GLdouble);
#define glRotated _ptrc_glRotated
extern void (CODEGEN_FUNCPTR *_ptrc_glRotatef)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glRotatef _ptrc_glRotatef
extern void (CODEGEN_FUNCPTR *_ptrc_glScaled)(GLdouble, GLdouble, GLdouble);
#define glScaled _ptrc_glScaled
extern void (CODEGEN_FUNCPTR *_ptrc_glScalef)(GLfloat, GLfloat, GLfloat);
#define glScalef _ptrc_glScalef
extern void (CODEGEN_FUNCPTR *_ptrc_glScissor)(GLint, GLint, GLsizei, GLsizei);
#define glScissor _ptrc_glScissor
extern void (CODEGEN_FUNCPTR *_ptrc_glSelectBuffer)(GLsizei, GLuint *);
#define glSelectBuffer _ptrc_glSelectBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glShadeModel)(GLenum);
#define glShadeModel _ptrc_glShadeModel
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFunc)(GLenum, GLint, GLuint);
#define glStencilFunc _ptrc_glStencilFunc
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilMask)(GLuint);
#define glStencilMask _ptrc_glStencilMask
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilOp)(GLenum, GLenum, GLenum);
#define glStencilOp _ptrc_glStencilOp
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1d)(GLdouble);
#define glTexCoord1d _ptrc_glTexCoord1d
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1dv)(const GLdouble *);
#define glTexCoord1dv _ptrc_glTexCoord1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1f)(GLfloat);
#define glTexCoord1f _ptrc_glTexCoord1f
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1fv)(const GLfloat *);
#define glTexCoord1fv _ptrc_glTexCoord1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1i)(GLint);
#define glTexCoord1i _ptrc_glTexCoord1i
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1iv)(const GLint *);
#define glTexCoord1iv _ptrc_glTexCoord1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1s)(GLshort);
#define glTexCoord1s _ptrc_glTexCoord1s
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1sv)(const GLshort *);
#define glTexCoord1sv _ptrc_glTexCoord1sv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2d)(GLdouble, GLdouble);
#define glTexCoord2d _ptrc_glTexCoord2d
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2dv)(const GLdouble *);
#define glTexCoord2dv _ptrc_glTexCoord2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2f)(GLfloat, GLfloat);
#define glTexCoord2f _ptrc_glTexCoord2f
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fv)(const GLfloat *);
#define glTexCoord2fv _ptrc_glTexCoord2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2i)(GLint, GLint);
#define glTexCoord2i _ptrc_glTexCoord2i
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2iv)(const GLint *);
#define glTexCoord2iv _ptrc_glTexCoord2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2s)(GLshort, GLshort);
#define glTexCoord2s _ptrc_glTexCoord2s
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2sv)(const GLshort *);
#define glTexCoord2sv _ptrc_glTexCoord2sv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3d)(GLdouble, GLdouble, GLdouble);
#define glTexCoord3d _ptrc_glTexCoord3d
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3dv)(const GLdouble *);
#define glTexCoord3dv _ptrc_glTexCoord3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3f)(GLfloat, GLfloat, GLfloat);
#define glTexCoord3f _ptrc_glTexCoord3f
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3fv)(const GLfloat *);
#define glTexCoord3fv _ptrc_glTexCoord3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3i)(GLint, GLint, GLint);
#define glTexCoord3i _ptrc_glTexCoord3i
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3iv)(const GLint *);
#define glTexCoord3iv _ptrc_glTexCoord3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3s)(GLshort, GLshort, GLshort);
#define glTexCoord3s _ptrc_glTexCoord3s
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3sv)(const GLshort *);
#define glTexCoord3sv _ptrc_glTexCoord3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define glTexCoord4d _ptrc_glTexCoord4d
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4dv)(const GLdouble *);
#define glTexCoord4dv _ptrc_glTexCoord4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glTexCoord4f _ptrc_glTexCoord4f
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fv)(const GLfloat *);
#define glTexCoord4fv _ptrc_glTexCoord4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4i)(GLint, GLint, GLint, GLint);
#define glTexCoord4i _ptrc_glTexCoord4i
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4iv)(const GLint *);
#define glTexCoord4iv _ptrc_glTexCoord4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4s)(GLshort, GLshort, GLshort, GLshort);
#define glTexCoord4s _ptrc_glTexCoord4s
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4sv)(const GLshort *);
#define glTexCoord4sv _ptrc_glTexCoord4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexEnvf)(GLenum, GLenum, GLfloat);
#define glTexEnvf _ptrc_glTexEnvf
extern void (CODEGEN_FUNCPTR *_ptrc_glTexEnvfv)(GLenum, GLenum, const GLfloat *);
#define glTexEnvfv _ptrc_glTexEnvfv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexEnvi)(GLenum, GLenum, GLint);
#define glTexEnvi _ptrc_glTexEnvi
extern void (CODEGEN_FUNCPTR *_ptrc_glTexEnviv)(GLenum, GLenum, const GLint *);
#define glTexEnviv _ptrc_glTexEnviv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGend)(GLenum, GLenum, GLdouble);
#define glTexGend _ptrc_glTexGend
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGendv)(GLenum, GLenum, const GLdouble *);
#define glTexGendv _ptrc_glTexGendv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGenf)(GLenum, GLenum, GLfloat);
#define glTexGenf _ptrc_glTexGenf
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGenfv)(GLenum, GLenum, const GLfloat *);
#define glTexGenfv _ptrc_glTexGenfv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGeni)(GLenum, GLenum, GLint);
#define glTexGeni _ptrc_glTexGeni
extern void (CODEGEN_FUNCPTR *_ptrc_glTexGeniv)(GLenum, GLenum, const GLint *);
#define glTexGeniv _ptrc_glTexGeniv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage1D)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTexImage1D _ptrc_glTexImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTexImage2D _ptrc_glTexImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterf)(GLenum, GLenum, GLfloat);
#define glTexParameterf _ptrc_glTexParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterfv)(GLenum, GLenum, const GLfloat *);
#define glTexParameterfv _ptrc_glTexParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameteri)(GLenum, GLenum, GLint);
#define glTexParameteri _ptrc_glTexParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameteriv)(GLenum, GLenum, const GLint *);
#define glTexParameteriv _ptrc_glTexParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glTranslated)(GLdouble, GLdouble, GLdouble);
#define glTranslated _ptrc_glTranslated
extern void (CODEGEN_FUNCPTR *_ptrc_glTranslatef)(GLfloat, GLfloat, GLfloat);
#define glTranslatef _ptrc_glTranslatef
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2d)(GLdouble, GLdouble);
#define glVertex2d _ptrc_glVertex2d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2dv)(const GLdouble *);
#define glVertex2dv _ptrc_glVertex2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2f)(GLfloat, GLfloat);
#define glVertex2f _ptrc_glVertex2f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2fv)(const GLfloat *);
#define glVertex2fv _ptrc_glVertex2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2i)(GLint, GLint);
#define glVertex2i _ptrc_glVertex2i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2iv)(const GLint *);
#define glVertex2iv _ptrc_glVertex2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2s)(GLshort, GLshort);
#define glVertex2s _ptrc_glVertex2s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex2sv)(const GLshort *);
#define glVertex2sv _ptrc_glVertex2sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3d)(GLdouble, GLdouble, GLdouble);
#define glVertex3d _ptrc_glVertex3d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3dv)(const GLdouble *);
#define glVertex3dv _ptrc_glVertex3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3f)(GLfloat, GLfloat, GLfloat);
#define glVertex3f _ptrc_glVertex3f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3fv)(const GLfloat *);
#define glVertex3fv _ptrc_glVertex3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3i)(GLint, GLint, GLint);
#define glVertex3i _ptrc_glVertex3i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3iv)(const GLint *);
#define glVertex3iv _ptrc_glVertex3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3s)(GLshort, GLshort, GLshort);
#define glVertex3s _ptrc_glVertex3s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex3sv)(const GLshort *);
#define glVertex3sv _ptrc_glVertex3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4d)(GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertex4d _ptrc_glVertex4d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4dv)(const GLdouble *);
#define glVertex4dv _ptrc_glVertex4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4f)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glVertex4f _ptrc_glVertex4f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4fv)(const GLfloat *);
#define glVertex4fv _ptrc_glVertex4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4i)(GLint, GLint, GLint, GLint);
#define glVertex4i _ptrc_glVertex4i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4iv)(const GLint *);
#define glVertex4iv _ptrc_glVertex4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4s)(GLshort, GLshort, GLshort, GLshort);
#define glVertex4s _ptrc_glVertex4s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertex4sv)(const GLshort *);
#define glVertex4sv _ptrc_glVertex4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewport)(GLint, GLint, GLsizei, GLsizei);
#define glViewport _ptrc_glViewport

extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreTexturesResident)(GLsizei, const GLuint *, GLboolean *);
#define glAreTexturesResident _ptrc_glAreTexturesResident
extern void (CODEGEN_FUNCPTR *_ptrc_glArrayElement)(GLint);
#define glArrayElement _ptrc_glArrayElement
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTexture)(GLenum, GLuint);
#define glBindTexture _ptrc_glBindTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glColorPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define glColorPointer _ptrc_glColorPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage1D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
#define glCopyTexImage1D _ptrc_glCopyTexImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage2D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
#define glCopyTexImage2D _ptrc_glCopyTexImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage1D)(GLenum, GLint, GLint, GLint, GLint, GLsizei);
#define glCopyTexSubImage1D _ptrc_glCopyTexSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyTexSubImage2D _ptrc_glCopyTexSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTextures)(GLsizei, const GLuint *);
#define glDeleteTextures _ptrc_glDeleteTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableClientState)(GLenum);
#define glDisableClientState _ptrc_glDisableClientState
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArrays)(GLenum, GLint, GLsizei);
#define glDrawArrays _ptrc_glDrawArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElements)(GLenum, GLsizei, GLenum, const GLvoid *);
#define glDrawElements _ptrc_glDrawElements
extern void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointer)(GLsizei, const GLvoid *);
#define glEdgeFlagPointer _ptrc_glEdgeFlagPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableClientState)(GLenum);
#define glEnableClientState _ptrc_glEnableClientState
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTextures)(GLsizei, GLuint *);
#define glGenTextures _ptrc_glGenTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glGetPointerv)(GLenum, GLvoid **);
#define glGetPointerv _ptrc_glGetPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexPointer)(GLenum, GLsizei, const GLvoid *);
#define glIndexPointer _ptrc_glIndexPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexub)(GLubyte);
#define glIndexub _ptrc_glIndexub
extern void (CODEGEN_FUNCPTR *_ptrc_glIndexubv)(const GLubyte *);
#define glIndexubv _ptrc_glIndexubv
extern void (CODEGEN_FUNCPTR *_ptrc_glInterleavedArrays)(GLenum, GLsizei, const GLvoid *);
#define glInterleavedArrays _ptrc_glInterleavedArrays
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTexture)(GLuint);
#define glIsTexture _ptrc_glIsTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glNormalPointer)(GLenum, GLsizei, const GLvoid *);
#define glNormalPointer _ptrc_glNormalPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffset)(GLfloat, GLfloat);
#define glPolygonOffset _ptrc_glPolygonOffset
extern void (CODEGEN_FUNCPTR *_ptrc_glPopClientAttrib)();
#define glPopClientAttrib _ptrc_glPopClientAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTextures)(GLsizei, const GLuint *, const GLfloat *);
#define glPrioritizeTextures _ptrc_glPrioritizeTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glPushClientAttrib)(GLbitfield);
#define glPushClientAttrib _ptrc_glPushClientAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define glTexCoordPointer _ptrc_glTexCoordPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTexSubImage1D _ptrc_glTexSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTexSubImage2D _ptrc_glTexSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexPointer _ptrc_glVertexPointer

extern void (CODEGEN_FUNCPTR *_ptrc_glBlendColor)(GLfloat, GLfloat, GLfloat, GLfloat);
#define glBlendColor _ptrc_glBlendColor
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquation)(GLenum);
#define glBlendEquation _ptrc_glBlendEquation
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
#define glCopyTexSubImage3D _ptrc_glCopyTexSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElements)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *);
#define glDrawRangeElements _ptrc_glDrawRangeElements
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
#define glTexImage3D _ptrc_glTexImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
#define glTexSubImage3D _ptrc_glTexSubImage3D

extern void (CODEGEN_FUNCPTR *_ptrc_glActiveTexture)(GLenum);
#define glActiveTexture _ptrc_glActiveTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glClientActiveTexture)(GLenum);
#define glClientActiveTexture _ptrc_glClientActiveTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1D)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTexImage1D _ptrc_glCompressedTexImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTexImage2D _ptrc_glCompressedTexImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *);
#define glCompressedTexImage3D _ptrc_glCompressedTexImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTexSubImage1D _ptrc_glCompressedTexSubImage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTexSubImage2D _ptrc_glCompressedTexSubImage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *);
#define glCompressedTexSubImage3D _ptrc_glCompressedTexSubImage3D
extern void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImage)(GLenum, GLint, GLvoid *);
#define glGetCompressedTexImage _ptrc_glGetCompressedTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixd)(const GLdouble *);
#define glLoadTransposeMatrixd _ptrc_glLoadTransposeMatrixd
extern void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixf)(const GLfloat *);
#define glLoadTransposeMatrixf _ptrc_glLoadTransposeMatrixf
extern void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixd)(const GLdouble *);
#define glMultTransposeMatrixd _ptrc_glMultTransposeMatrixd
extern void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixf)(const GLfloat *);
#define glMultTransposeMatrixf _ptrc_glMultTransposeMatrixf
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1d)(GLenum, GLdouble);
#define glMultiTexCoord1d _ptrc_glMultiTexCoord1d
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dv)(GLenum, const GLdouble *);
#define glMultiTexCoord1dv _ptrc_glMultiTexCoord1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1f)(GLenum, GLfloat);
#define glMultiTexCoord1f _ptrc_glMultiTexCoord1f
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fv)(GLenum, const GLfloat *);
#define glMultiTexCoord1fv _ptrc_glMultiTexCoord1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1i)(GLenum, GLint);
#define glMultiTexCoord1i _ptrc_glMultiTexCoord1i
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1iv)(GLenum, const GLint *);
#define glMultiTexCoord1iv _ptrc_glMultiTexCoord1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1s)(GLenum, GLshort);
#define glMultiTexCoord1s _ptrc_glMultiTexCoord1s
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1sv)(GLenum, const GLshort *);
#define glMultiTexCoord1sv _ptrc_glMultiTexCoord1sv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2d)(GLenum, GLdouble, GLdouble);
#define glMultiTexCoord2d _ptrc_glMultiTexCoord2d
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dv)(GLenum, const GLdouble *);
#define glMultiTexCoord2dv _ptrc_glMultiTexCoord2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2f)(GLenum, GLfloat, GLfloat);
#define glMultiTexCoord2f _ptrc_glMultiTexCoord2f
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fv)(GLenum, const GLfloat *);
#define glMultiTexCoord2fv _ptrc_glMultiTexCoord2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2i)(GLenum, GLint, GLint);
#define glMultiTexCoord2i _ptrc_glMultiTexCoord2i
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2iv)(GLenum, const GLint *);
#define glMultiTexCoord2iv _ptrc_glMultiTexCoord2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2s)(GLenum, GLshort, GLshort);
#define glMultiTexCoord2s _ptrc_glMultiTexCoord2s
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2sv)(GLenum, const GLshort *);
#define glMultiTexCoord2sv _ptrc_glMultiTexCoord2sv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3d)(GLenum, GLdouble, GLdouble, GLdouble);
#define glMultiTexCoord3d _ptrc_glMultiTexCoord3d
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dv)(GLenum, const GLdouble *);
#define glMultiTexCoord3dv _ptrc_glMultiTexCoord3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3f)(GLenum, GLfloat, GLfloat, GLfloat);
#define glMultiTexCoord3f _ptrc_glMultiTexCoord3f
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fv)(GLenum, const GLfloat *);
#define glMultiTexCoord3fv _ptrc_glMultiTexCoord3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3i)(GLenum, GLint, GLint, GLint);
#define glMultiTexCoord3i _ptrc_glMultiTexCoord3i
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3iv)(GLenum, const GLint *);
#define glMultiTexCoord3iv _ptrc_glMultiTexCoord3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3s)(GLenum, GLshort, GLshort, GLshort);
#define glMultiTexCoord3s _ptrc_glMultiTexCoord3s
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3sv)(GLenum, const GLshort *);
#define glMultiTexCoord3sv _ptrc_glMultiTexCoord3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4d)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
#define glMultiTexCoord4d _ptrc_glMultiTexCoord4d
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dv)(GLenum, const GLdouble *);
#define glMultiTexCoord4dv _ptrc_glMultiTexCoord4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4f)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
#define glMultiTexCoord4f _ptrc_glMultiTexCoord4f
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fv)(GLenum, const GLfloat *);
#define glMultiTexCoord4fv _ptrc_glMultiTexCoord4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4i)(GLenum, GLint, GLint, GLint, GLint);
#define glMultiTexCoord4i _ptrc_glMultiTexCoord4i
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4iv)(GLenum, const GLint *);
#define glMultiTexCoord4iv _ptrc_glMultiTexCoord4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4s)(GLenum, GLshort, GLshort, GLshort, GLshort);
#define glMultiTexCoord4s _ptrc_glMultiTexCoord4s
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4sv)(GLenum, const GLshort *);
#define glMultiTexCoord4sv _ptrc_glMultiTexCoord4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverage)(GLfloat, GLboolean);
#define glSampleCoverage _ptrc_glSampleCoverage

extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum);
#define glBlendFuncSeparate _ptrc_glBlendFuncSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointer)(GLenum, GLsizei, const GLvoid *);
#define glFogCoordPointer _ptrc_glFogCoordPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordd)(GLdouble);
#define glFogCoordd _ptrc_glFogCoordd
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddv)(const GLdouble *);
#define glFogCoorddv _ptrc_glFogCoorddv
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordf)(GLfloat);
#define glFogCoordf _ptrc_glFogCoordf
extern void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfv)(const GLfloat *);
#define glFogCoordfv _ptrc_glFogCoordfv
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArrays)(GLenum, const GLint *, const GLsizei *, GLsizei);
#define glMultiDrawArrays _ptrc_glMultiDrawArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElements)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei);
#define glMultiDrawElements _ptrc_glMultiDrawElements
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterf)(GLenum, GLfloat);
#define glPointParameterf _ptrc_glPointParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfv)(GLenum, const GLfloat *);
#define glPointParameterfv _ptrc_glPointParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameteri)(GLenum, GLint);
#define glPointParameteri _ptrc_glPointParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriv)(GLenum, const GLint *);
#define glPointParameteriv _ptrc_glPointParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3b)(GLbyte, GLbyte, GLbyte);
#define glSecondaryColor3b _ptrc_glSecondaryColor3b
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bv)(const GLbyte *);
#define glSecondaryColor3bv _ptrc_glSecondaryColor3bv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3d)(GLdouble, GLdouble, GLdouble);
#define glSecondaryColor3d _ptrc_glSecondaryColor3d
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dv)(const GLdouble *);
#define glSecondaryColor3dv _ptrc_glSecondaryColor3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3f)(GLfloat, GLfloat, GLfloat);
#define glSecondaryColor3f _ptrc_glSecondaryColor3f
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fv)(const GLfloat *);
#define glSecondaryColor3fv _ptrc_glSecondaryColor3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3i)(GLint, GLint, GLint);
#define glSecondaryColor3i _ptrc_glSecondaryColor3i
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3iv)(const GLint *);
#define glSecondaryColor3iv _ptrc_glSecondaryColor3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3s)(GLshort, GLshort, GLshort);
#define glSecondaryColor3s _ptrc_glSecondaryColor3s
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3sv)(const GLshort *);
#define glSecondaryColor3sv _ptrc_glSecondaryColor3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ub)(GLubyte, GLubyte, GLubyte);
#define glSecondaryColor3ub _ptrc_glSecondaryColor3ub
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubv)(const GLubyte *);
#define glSecondaryColor3ubv _ptrc_glSecondaryColor3ubv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ui)(GLuint, GLuint, GLuint);
#define glSecondaryColor3ui _ptrc_glSecondaryColor3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uiv)(const GLuint *);
#define glSecondaryColor3uiv _ptrc_glSecondaryColor3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3us)(GLushort, GLushort, GLushort);
#define glSecondaryColor3us _ptrc_glSecondaryColor3us
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usv)(const GLushort *);
#define glSecondaryColor3usv _ptrc_glSecondaryColor3usv
extern void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointer)(GLint, GLenum, GLsizei, const GLvoid *);
#define glSecondaryColorPointer _ptrc_glSecondaryColorPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2d)(GLdouble, GLdouble);
#define glWindowPos2d _ptrc_glWindowPos2d
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dv)(const GLdouble *);
#define glWindowPos2dv _ptrc_glWindowPos2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2f)(GLfloat, GLfloat);
#define glWindowPos2f _ptrc_glWindowPos2f
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fv)(const GLfloat *);
#define glWindowPos2fv _ptrc_glWindowPos2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2i)(GLint, GLint);
#define glWindowPos2i _ptrc_glWindowPos2i
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iv)(const GLint *);
#define glWindowPos2iv _ptrc_glWindowPos2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2s)(GLshort, GLshort);
#define glWindowPos2s _ptrc_glWindowPos2s
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sv)(const GLshort *);
#define glWindowPos2sv _ptrc_glWindowPos2sv
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3d)(GLdouble, GLdouble, GLdouble);
#define glWindowPos3d _ptrc_glWindowPos3d
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dv)(const GLdouble *);
#define glWindowPos3dv _ptrc_glWindowPos3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3f)(GLfloat, GLfloat, GLfloat);
#define glWindowPos3f _ptrc_glWindowPos3f
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fv)(const GLfloat *);
#define glWindowPos3fv _ptrc_glWindowPos3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3i)(GLint, GLint, GLint);
#define glWindowPos3i _ptrc_glWindowPos3i
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iv)(const GLint *);
#define glWindowPos3iv _ptrc_glWindowPos3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3s)(GLshort, GLshort, GLshort);
#define glWindowPos3s _ptrc_glWindowPos3s
extern void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sv)(const GLshort *);
#define glWindowPos3sv _ptrc_glWindowPos3sv

extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQuery)(GLenum, GLuint);
#define glBeginQuery _ptrc_glBeginQuery
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffer)(GLenum, GLuint);
#define glBindBuffer _ptrc_glBindBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferData)(GLenum, GLsizeiptr, const GLvoid *, GLenum);
#define glBufferData _ptrc_glBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferSubData)(GLenum, GLintptr, GLsizeiptr, const GLvoid *);
#define glBufferSubData _ptrc_glBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffers)(GLsizei, const GLuint *);
#define glDeleteBuffers _ptrc_glDeleteBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueries)(GLsizei, const GLuint *);
#define glDeleteQueries _ptrc_glDeleteQueries
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQuery)(GLenum);
#define glEndQuery _ptrc_glEndQuery
extern void (CODEGEN_FUNCPTR *_ptrc_glGenBuffers)(GLsizei, GLuint *);
#define glGenBuffers _ptrc_glGenBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenQueries)(GLsizei, GLuint *);
#define glGenQueries _ptrc_glGenQueries
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteriv)(GLenum, GLenum, GLint *);
#define glGetBufferParameteriv _ptrc_glGetBufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointerv)(GLenum, GLenum, GLvoid **);
#define glGetBufferPointerv _ptrc_glGetBufferPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubData)(GLenum, GLintptr, GLsizeiptr, GLvoid *);
#define glGetBufferSubData _ptrc_glGetBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectiv)(GLuint, GLenum, GLint *);
#define glGetQueryObjectiv _ptrc_glGetQueryObjectiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuiv)(GLuint, GLenum, GLuint *);
#define glGetQueryObjectuiv _ptrc_glGetQueryObjectuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryiv)(GLenum, GLenum, GLint *);
#define glGetQueryiv _ptrc_glGetQueryiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBuffer)(GLuint);
#define glIsBuffer _ptrc_glIsBuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQuery)(GLuint);
#define glIsQuery _ptrc_glIsQuery
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBuffer)(GLenum, GLenum);
#define glMapBuffer _ptrc_glMapBuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBuffer)(GLenum);
#define glUnmapBuffer _ptrc_glUnmapBuffer

extern void (CODEGEN_FUNCPTR *_ptrc_glAttachShader)(GLuint, GLuint);
#define glAttachShader _ptrc_glAttachShader
extern void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocation)(GLuint, GLuint, const GLchar *);
#define glBindAttribLocation _ptrc_glBindAttribLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparate)(GLenum, GLenum);
#define glBlendEquationSeparate _ptrc_glBlendEquationSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glCompileShader)(GLuint);
#define glCompileShader _ptrc_glCompileShader
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateProgram)();
#define glCreateProgram _ptrc_glCreateProgram
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShader)(GLenum);
#define glCreateShader _ptrc_glCreateShader
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgram)(GLuint);
#define glDeleteProgram _ptrc_glDeleteProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteShader)(GLuint);
#define glDeleteShader _ptrc_glDeleteShader
extern void (CODEGEN_FUNCPTR *_ptrc_glDetachShader)(GLuint, GLuint);
#define glDetachShader _ptrc_glDetachShader
extern void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArray)(GLuint);
#define glDisableVertexAttribArray _ptrc_glDisableVertexAttribArray
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffers)(GLsizei, const GLenum *);
#define glDrawBuffers _ptrc_glDrawBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArray)(GLuint);
#define glEnableVertexAttribArray _ptrc_glEnableVertexAttribArray
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttrib)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
#define glGetActiveAttrib _ptrc_glGetActiveAttrib
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniform)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
#define glGetActiveUniform _ptrc_glGetActiveUniform
extern void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedShaders)(GLuint, GLsizei, GLsizei *, GLuint *);
#define glGetAttachedShaders _ptrc_glGetAttachedShaders
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocation)(GLuint, const GLchar *);
#define glGetAttribLocation _ptrc_glGetAttribLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetProgramInfoLog _ptrc_glGetProgramInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramiv)(GLuint, GLenum, GLint *);
#define glGetProgramiv _ptrc_glGetProgramiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetShaderInfoLog _ptrc_glGetShaderInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSource)(GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetShaderSource _ptrc_glGetShaderSource
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderiv)(GLuint, GLenum, GLint *);
#define glGetShaderiv _ptrc_glGetShaderiv
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocation)(GLuint, const GLchar *);
#define glGetUniformLocation _ptrc_glGetUniformLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfv)(GLuint, GLint, GLfloat *);
#define glGetUniformfv _ptrc_glGetUniformfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformiv)(GLuint, GLint, GLint *);
#define glGetUniformiv _ptrc_glGetUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointerv)(GLuint, GLenum, GLvoid **);
#define glGetVertexAttribPointerv _ptrc_glGetVertexAttribPointerv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdv)(GLuint, GLenum, GLdouble *);
#define glGetVertexAttribdv _ptrc_glGetVertexAttribdv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfv)(GLuint, GLenum, GLfloat *);
#define glGetVertexAttribfv _ptrc_glGetVertexAttribfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribiv)(GLuint, GLenum, GLint *);
#define glGetVertexAttribiv _ptrc_glGetVertexAttribiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgram)(GLuint);
#define glIsProgram _ptrc_glIsProgram
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsShader)(GLuint);
#define glIsShader _ptrc_glIsShader
extern void (CODEGEN_FUNCPTR *_ptrc_glLinkProgram)(GLuint);
#define glLinkProgram _ptrc_glLinkProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderSource)(GLuint, GLsizei, const GLchar *const*, const GLint *);
#define glShaderSource _ptrc_glShaderSource
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilFuncSeparate)(GLenum, GLenum, GLint, GLuint);
#define glStencilFuncSeparate _ptrc_glStencilFuncSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilMaskSeparate)(GLenum, GLuint);
#define glStencilMaskSeparate _ptrc_glStencilMaskSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glStencilOpSeparate)(GLenum, GLenum, GLenum, GLenum);
#define glStencilOpSeparate _ptrc_glStencilOpSeparate
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1f)(GLint, GLfloat);
#define glUniform1f _ptrc_glUniform1f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1fv)(GLint, GLsizei, const GLfloat *);
#define glUniform1fv _ptrc_glUniform1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1i)(GLint, GLint);
#define glUniform1i _ptrc_glUniform1i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1iv)(GLint, GLsizei, const GLint *);
#define glUniform1iv _ptrc_glUniform1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2f)(GLint, GLfloat, GLfloat);
#define glUniform2f _ptrc_glUniform2f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2fv)(GLint, GLsizei, const GLfloat *);
#define glUniform2fv _ptrc_glUniform2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2i)(GLint, GLint, GLint);
#define glUniform2i _ptrc_glUniform2i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2iv)(GLint, GLsizei, const GLint *);
#define glUniform2iv _ptrc_glUniform2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3f)(GLint, GLfloat, GLfloat, GLfloat);
#define glUniform3f _ptrc_glUniform3f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3fv)(GLint, GLsizei, const GLfloat *);
#define glUniform3fv _ptrc_glUniform3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3i)(GLint, GLint, GLint, GLint);
#define glUniform3i _ptrc_glUniform3i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3iv)(GLint, GLsizei, const GLint *);
#define glUniform3iv _ptrc_glUniform3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glUniform4f _ptrc_glUniform4f
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4fv)(GLint, GLsizei, const GLfloat *);
#define glUniform4fv _ptrc_glUniform4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4i)(GLint, GLint, GLint, GLint, GLint);
#define glUniform4i _ptrc_glUniform4i
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4iv)(GLint, GLsizei, const GLint *);
#define glUniform4iv _ptrc_glUniform4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix2fv _ptrc_glUniformMatrix2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix3fv _ptrc_glUniformMatrix3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix4fv _ptrc_glUniformMatrix4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgram)(GLuint);
#define glUseProgram _ptrc_glUseProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgram)(GLuint);
#define glValidateProgram _ptrc_glValidateProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1d)(GLuint, GLdouble);
#define glVertexAttrib1d _ptrc_glVertexAttrib1d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dv)(GLuint, const GLdouble *);
#define glVertexAttrib1dv _ptrc_glVertexAttrib1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1f)(GLuint, GLfloat);
#define glVertexAttrib1f _ptrc_glVertexAttrib1f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fv)(GLuint, const GLfloat *);
#define glVertexAttrib1fv _ptrc_glVertexAttrib1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1s)(GLuint, GLshort);
#define glVertexAttrib1s _ptrc_glVertexAttrib1s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sv)(GLuint, const GLshort *);
#define glVertexAttrib1sv _ptrc_glVertexAttrib1sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2d)(GLuint, GLdouble, GLdouble);
#define glVertexAttrib2d _ptrc_glVertexAttrib2d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dv)(GLuint, const GLdouble *);
#define glVertexAttrib2dv _ptrc_glVertexAttrib2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2f)(GLuint, GLfloat, GLfloat);
#define glVertexAttrib2f _ptrc_glVertexAttrib2f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fv)(GLuint, const GLfloat *);
#define glVertexAttrib2fv _ptrc_glVertexAttrib2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2s)(GLuint, GLshort, GLshort);
#define glVertexAttrib2s _ptrc_glVertexAttrib2s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sv)(GLuint, const GLshort *);
#define glVertexAttrib2sv _ptrc_glVertexAttrib2sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3d)(GLuint, GLdouble, GLdouble, GLdouble);
#define glVertexAttrib3d _ptrc_glVertexAttrib3d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dv)(GLuint, const GLdouble *);
#define glVertexAttrib3dv _ptrc_glVertexAttrib3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3f)(GLuint, GLfloat, GLfloat, GLfloat);
#define glVertexAttrib3f _ptrc_glVertexAttrib3f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fv)(GLuint, const GLfloat *);
#define glVertexAttrib3fv _ptrc_glVertexAttrib3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3s)(GLuint, GLshort, GLshort, GLshort);
#define glVertexAttrib3s _ptrc_glVertexAttrib3s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sv)(GLuint, const GLshort *);
#define glVertexAttrib3sv _ptrc_glVertexAttrib3sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nbv)(GLuint, const GLbyte *);
#define glVertexAttrib4Nbv _ptrc_glVertexAttrib4Nbv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Niv)(GLuint, const GLint *);
#define glVertexAttrib4Niv _ptrc_glVertexAttrib4Niv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nsv)(GLuint, const GLshort *);
#define glVertexAttrib4Nsv _ptrc_glVertexAttrib4Nsv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nub)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
#define glVertexAttrib4Nub _ptrc_glVertexAttrib4Nub
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nubv)(GLuint, const GLubyte *);
#define glVertexAttrib4Nubv _ptrc_glVertexAttrib4Nubv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nuiv)(GLuint, const GLuint *);
#define glVertexAttrib4Nuiv _ptrc_glVertexAttrib4Nuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nusv)(GLuint, const GLushort *);
#define glVertexAttrib4Nusv _ptrc_glVertexAttrib4Nusv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bv)(GLuint, const GLbyte *);
#define glVertexAttrib4bv _ptrc_glVertexAttrib4bv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertexAttrib4d _ptrc_glVertexAttrib4d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dv)(GLuint, const GLdouble *);
#define glVertexAttrib4dv _ptrc_glVertexAttrib4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4f)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glVertexAttrib4f _ptrc_glVertexAttrib4f
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fv)(GLuint, const GLfloat *);
#define glVertexAttrib4fv _ptrc_glVertexAttrib4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4iv)(GLuint, const GLint *);
#define glVertexAttrib4iv _ptrc_glVertexAttrib4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4s)(GLuint, GLshort, GLshort, GLshort, GLshort);
#define glVertexAttrib4s _ptrc_glVertexAttrib4s
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sv)(GLuint, const GLshort *);
#define glVertexAttrib4sv _ptrc_glVertexAttrib4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubv)(GLuint, const GLubyte *);
#define glVertexAttrib4ubv _ptrc_glVertexAttrib4ubv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uiv)(GLuint, const GLuint *);
#define glVertexAttrib4uiv _ptrc_glVertexAttrib4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usv)(GLuint, const GLushort *);
#define glVertexAttrib4usv _ptrc_glVertexAttrib4usv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *);
#define glVertexAttribPointer _ptrc_glVertexAttribPointer

extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix2x3fv _ptrc_glUniformMatrix2x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix2x4fv _ptrc_glUniformMatrix2x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix3x2fv _ptrc_glUniformMatrix3x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix3x4fv _ptrc_glUniformMatrix3x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix4x2fv _ptrc_glUniformMatrix4x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3fv)(GLint, GLsizei, GLboolean, const GLfloat *);
#define glUniformMatrix4x3fv _ptrc_glUniformMatrix4x3fv

extern void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRender)(GLuint, GLenum);
#define glBeginConditionalRender _ptrc_glBeginConditionalRender
extern void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedback)(GLenum);
#define glBeginTransformFeedback _ptrc_glBeginTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBase)(GLenum, GLuint, GLuint);
#define glBindBufferBase _ptrc_glBindBufferBase
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRange)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
#define glBindBufferRange _ptrc_glBindBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocation)(GLuint, GLuint, const GLchar *);
#define glBindFragDataLocation _ptrc_glBindFragDataLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glBindFramebuffer)(GLenum, GLuint);
#define glBindFramebuffer _ptrc_glBindFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbuffer)(GLenum, GLuint);
#define glBindRenderbuffer _ptrc_glBindRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArray)(GLuint);
#define glBindVertexArray _ptrc_glBindVertexArray
extern void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebuffer)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
#define glBlitFramebuffer _ptrc_glBlitFramebuffer
extern GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatus)(GLenum);
#define glCheckFramebufferStatus _ptrc_glCheckFramebufferStatus
extern void (CODEGEN_FUNCPTR *_ptrc_glClampColor)(GLenum, GLenum);
#define glClampColor _ptrc_glClampColor
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfi)(GLenum, GLint, GLfloat, GLint);
#define glClearBufferfi _ptrc_glClearBufferfi
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfv)(GLenum, GLint, const GLfloat *);
#define glClearBufferfv _ptrc_glClearBufferfv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferiv)(GLenum, GLint, const GLint *);
#define glClearBufferiv _ptrc_glClearBufferiv
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferuiv)(GLenum, GLint, const GLuint *);
#define glClearBufferuiv _ptrc_glClearBufferuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glColorMaski)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
#define glColorMaski _ptrc_glColorMaski
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffers)(GLsizei, const GLuint *);
#define glDeleteFramebuffers _ptrc_glDeleteFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffers)(GLsizei, const GLuint *);
#define glDeleteRenderbuffers _ptrc_glDeleteRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArrays)(GLsizei, const GLuint *);
#define glDeleteVertexArrays _ptrc_glDeleteVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glDisablei)(GLenum, GLuint);
#define glDisablei _ptrc_glDisablei
extern void (CODEGEN_FUNCPTR *_ptrc_glEnablei)(GLenum, GLuint);
#define glEnablei _ptrc_glEnablei
extern void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRender)();
#define glEndConditionalRender _ptrc_glEndConditionalRender
extern void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedback)();
#define glEndTransformFeedback _ptrc_glEndTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRange)(GLenum, GLintptr, GLsizeiptr);
#define glFlushMappedBufferRange _ptrc_glFlushMappedBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint);
#define glFramebufferRenderbuffer _ptrc_glFramebufferRenderbuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1D)(GLenum, GLenum, GLenum, GLuint, GLint);
#define glFramebufferTexture1D _ptrc_glFramebufferTexture1D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint);
#define glFramebufferTexture2D _ptrc_glFramebufferTexture2D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3D)(GLenum, GLenum, GLenum, GLuint, GLint, GLint);
#define glFramebufferTexture3D _ptrc_glFramebufferTexture3D
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayer)(GLenum, GLenum, GLuint, GLint, GLint);
#define glFramebufferTextureLayer _ptrc_glFramebufferTextureLayer
extern void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffers)(GLsizei, GLuint *);
#define glGenFramebuffers _ptrc_glGenFramebuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffers)(GLsizei, GLuint *);
#define glGenRenderbuffers _ptrc_glGenRenderbuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArrays)(GLsizei, GLuint *);
#define glGenVertexArrays _ptrc_glGenVertexArrays
extern void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmap)(GLenum);
#define glGenerateMipmap _ptrc_glGenerateMipmap
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBooleani_v)(GLenum, GLuint, GLboolean *);
#define glGetBooleani_v _ptrc_glGetBooleani_v
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocation)(GLuint, const GLchar *);
#define glGetFragDataLocation _ptrc_glGetFragDataLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *);
#define glGetFramebufferAttachmentParameteriv _ptrc_glGetFramebufferAttachmentParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetIntegeri_v)(GLenum, GLuint, GLint *);
#define glGetIntegeri_v _ptrc_glGetIntegeri_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameteriv)(GLenum, GLenum, GLint *);
#define glGetRenderbufferParameteriv _ptrc_glGetRenderbufferParameteriv
extern const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetStringi)(GLenum, GLuint);
#define glGetStringi _ptrc_glGetStringi
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIiv)(GLenum, GLenum, GLint *);
#define glGetTexParameterIiv _ptrc_glGetTexParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuiv)(GLenum, GLenum, GLuint *);
#define glGetTexParameterIuiv _ptrc_glGetTexParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVarying)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
#define glGetTransformFeedbackVarying _ptrc_glGetTransformFeedbackVarying
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuiv)(GLuint, GLint, GLuint *);
#define glGetUniformuiv _ptrc_glGetUniformuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIiv)(GLuint, GLenum, GLint *);
#define glGetVertexAttribIiv _ptrc_glGetVertexAttribIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIuiv)(GLuint, GLenum, GLuint *);
#define glGetVertexAttribIuiv _ptrc_glGetVertexAttribIuiv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledi)(GLenum, GLuint);
#define glIsEnabledi _ptrc_glIsEnabledi
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebuffer)(GLuint);
#define glIsFramebuffer _ptrc_glIsFramebuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbuffer)(GLuint);
#define glIsRenderbuffer _ptrc_glIsRenderbuffer
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArray)(GLuint);
#define glIsVertexArray _ptrc_glIsVertexArray
extern void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferRange)(GLenum, GLintptr, GLsizeiptr, GLbitfield);
#define glMapBufferRange _ptrc_glMapBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei);
#define glRenderbufferStorage _ptrc_glRenderbufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define glRenderbufferStorageMultisample _ptrc_glRenderbufferStorageMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIiv)(GLenum, GLenum, const GLint *);
#define glTexParameterIiv _ptrc_glTexParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuiv)(GLenum, GLenum, const GLuint *);
#define glTexParameterIuiv _ptrc_glTexParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryings)(GLuint, GLsizei, const GLchar *const*, GLenum);
#define glTransformFeedbackVaryings _ptrc_glTransformFeedbackVaryings
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui)(GLint, GLuint);
#define glUniform1ui _ptrc_glUniform1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiv)(GLint, GLsizei, const GLuint *);
#define glUniform1uiv _ptrc_glUniform1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui)(GLint, GLuint, GLuint);
#define glUniform2ui _ptrc_glUniform2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiv)(GLint, GLsizei, const GLuint *);
#define glUniform2uiv _ptrc_glUniform2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui)(GLint, GLuint, GLuint, GLuint);
#define glUniform3ui _ptrc_glUniform3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiv)(GLint, GLsizei, const GLuint *);
#define glUniform3uiv _ptrc_glUniform3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui)(GLint, GLuint, GLuint, GLuint, GLuint);
#define glUniform4ui _ptrc_glUniform4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiv)(GLint, GLsizei, const GLuint *);
#define glUniform4uiv _ptrc_glUniform4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1i)(GLuint, GLint);
#define glVertexAttribI1i _ptrc_glVertexAttribI1i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1iv)(GLuint, const GLint *);
#define glVertexAttribI1iv _ptrc_glVertexAttribI1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1ui)(GLuint, GLuint);
#define glVertexAttribI1ui _ptrc_glVertexAttribI1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uiv)(GLuint, const GLuint *);
#define glVertexAttribI1uiv _ptrc_glVertexAttribI1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2i)(GLuint, GLint, GLint);
#define glVertexAttribI2i _ptrc_glVertexAttribI2i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2iv)(GLuint, const GLint *);
#define glVertexAttribI2iv _ptrc_glVertexAttribI2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2ui)(GLuint, GLuint, GLuint);
#define glVertexAttribI2ui _ptrc_glVertexAttribI2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uiv)(GLuint, const GLuint *);
#define glVertexAttribI2uiv _ptrc_glVertexAttribI2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3i)(GLuint, GLint, GLint, GLint);
#define glVertexAttribI3i _ptrc_glVertexAttribI3i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3iv)(GLuint, const GLint *);
#define glVertexAttribI3iv _ptrc_glVertexAttribI3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3ui)(GLuint, GLuint, GLuint, GLuint);
#define glVertexAttribI3ui _ptrc_glVertexAttribI3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uiv)(GLuint, const GLuint *);
#define glVertexAttribI3uiv _ptrc_glVertexAttribI3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4bv)(GLuint, const GLbyte *);
#define glVertexAttribI4bv _ptrc_glVertexAttribI4bv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4i)(GLuint, GLint, GLint, GLint, GLint);
#define glVertexAttribI4i _ptrc_glVertexAttribI4i
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4iv)(GLuint, const GLint *);
#define glVertexAttribI4iv _ptrc_glVertexAttribI4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4sv)(GLuint, const GLshort *);
#define glVertexAttribI4sv _ptrc_glVertexAttribI4sv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ubv)(GLuint, const GLubyte *);
#define glVertexAttribI4ubv _ptrc_glVertexAttribI4ubv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ui)(GLuint, GLuint, GLuint, GLuint, GLuint);
#define glVertexAttribI4ui _ptrc_glVertexAttribI4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uiv)(GLuint, const GLuint *);
#define glVertexAttribI4uiv _ptrc_glVertexAttribI4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4usv)(GLuint, const GLushort *);
#define glVertexAttribI4usv _ptrc_glVertexAttribI4usv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIPointer)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexAttribIPointer _ptrc_glVertexAttribIPointer

extern void (CODEGEN_FUNCPTR *_ptrc_glCopyBufferSubData)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr);
#define glCopyBufferSubData _ptrc_glCopyBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstanced)(GLenum, GLint, GLsizei, GLsizei);
#define glDrawArraysInstanced _ptrc_glDrawArraysInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstanced)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei);
#define glDrawElementsInstanced _ptrc_glDrawElementsInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveUniformBlockName _ptrc_glGetActiveUniformBlockName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockiv)(GLuint, GLuint, GLenum, GLint *);
#define glGetActiveUniformBlockiv _ptrc_glGetActiveUniformBlockiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveUniformName _ptrc_glGetActiveUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformsiv)(GLuint, GLsizei, const GLuint *, GLenum, GLint *);
#define glGetActiveUniformsiv _ptrc_glGetActiveUniformsiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBlockIndex)(GLuint, const GLchar *);
#define glGetUniformBlockIndex _ptrc_glGetUniformBlockIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformIndices)(GLuint, GLsizei, const GLchar *const*, GLuint *);
#define glGetUniformIndices _ptrc_glGetUniformIndices
extern void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndex)(GLuint);
#define glPrimitiveRestartIndex _ptrc_glPrimitiveRestartIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBuffer)(GLenum, GLenum, GLuint);
#define glTexBuffer _ptrc_glTexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformBlockBinding)(GLuint, GLuint, GLuint);
#define glUniformBlockBinding _ptrc_glUniformBlockBinding

extern GLenum (CODEGEN_FUNCPTR *_ptrc_glClientWaitSync)(GLsync, GLbitfield, GLuint64);
#define glClientWaitSync _ptrc_glClientWaitSync
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSync)(GLsync);
#define glDeleteSync _ptrc_glDeleteSync
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLint);
#define glDrawElementsBaseVertex _ptrc_glDrawElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint);
#define glDrawElementsInstancedBaseVertex _ptrc_glDrawElementsInstancedBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsBaseVertex)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint);
#define glDrawRangeElementsBaseVertex _ptrc_glDrawRangeElementsBaseVertex
extern GLsync (CODEGEN_FUNCPTR *_ptrc_glFenceSync)(GLenum, GLbitfield);
#define glFenceSync _ptrc_glFenceSync
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture)(GLenum, GLenum, GLuint, GLint);
#define glFramebufferTexture _ptrc_glFramebufferTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteri64v)(GLenum, GLenum, GLint64 *);
#define glGetBufferParameteri64v _ptrc_glGetBufferParameteri64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64i_v)(GLenum, GLuint, GLint64 *);
#define glGetInteger64i_v _ptrc_glGetInteger64i_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64v)(GLenum, GLint64 *);
#define glGetInteger64v _ptrc_glGetInteger64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefv)(GLenum, GLuint, GLfloat *);
#define glGetMultisamplefv _ptrc_glGetMultisamplefv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSynciv)(GLsync, GLenum, GLsizei, GLsizei *, GLint *);
#define glGetSynciv _ptrc_glGetSynciv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSync)(GLsync);
#define glIsSync _ptrc_glIsSync
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsBaseVertex)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, const GLint *);
#define glMultiDrawElementsBaseVertex _ptrc_glMultiDrawElementsBaseVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertex)(GLenum);
#define glProvokingVertex _ptrc_glProvokingVertex
extern void (CODEGEN_FUNCPTR *_ptrc_glSampleMaski)(GLuint, GLbitfield);
#define glSampleMaski _ptrc_glSampleMaski
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisample)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean);
#define glTexImage2DMultisample _ptrc_glTexImage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisample)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTexImage3DMultisample _ptrc_glTexImage3DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glWaitSync)(GLsync, GLbitfield, GLuint64);
#define glWaitSync _ptrc_glWaitSync

extern void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationIndexed)(GLuint, GLuint, GLuint, const GLchar *);
#define glBindFragDataLocationIndexed _ptrc_glBindFragDataLocationIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSampler)(GLuint, GLuint);
#define glBindSampler _ptrc_glBindSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteSamplers)(GLsizei, const GLuint *);
#define glDeleteSamplers _ptrc_glDeleteSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glGenSamplers)(GLsizei, GLuint *);
#define glGenSamplers _ptrc_glGenSamplers
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataIndex)(GLuint, const GLchar *);
#define glGetFragDataIndex _ptrc_glGetFragDataIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64v)(GLuint, GLenum, GLint64 *);
#define glGetQueryObjecti64v _ptrc_glGetQueryObjecti64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64v)(GLuint, GLenum, GLuint64 *);
#define glGetQueryObjectui64v _ptrc_glGetQueryObjectui64v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIiv)(GLuint, GLenum, GLint *);
#define glGetSamplerParameterIiv _ptrc_glGetSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIuiv)(GLuint, GLenum, GLuint *);
#define glGetSamplerParameterIuiv _ptrc_glGetSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterfv)(GLuint, GLenum, GLfloat *);
#define glGetSamplerParameterfv _ptrc_glGetSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameteriv)(GLuint, GLenum, GLint *);
#define glGetSamplerParameteriv _ptrc_glGetSamplerParameteriv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSampler)(GLuint);
#define glIsSampler _ptrc_glIsSampler
extern void (CODEGEN_FUNCPTR *_ptrc_glQueryCounter)(GLuint, GLenum);
#define glQueryCounter _ptrc_glQueryCounter
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIiv)(GLuint, GLenum, const GLint *);
#define glSamplerParameterIiv _ptrc_glSamplerParameterIiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIuiv)(GLuint, GLenum, const GLuint *);
#define glSamplerParameterIuiv _ptrc_glSamplerParameterIuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterf)(GLuint, GLenum, GLfloat);
#define glSamplerParameterf _ptrc_glSamplerParameterf
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterfv)(GLuint, GLenum, const GLfloat *);
#define glSamplerParameterfv _ptrc_glSamplerParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteri)(GLuint, GLenum, GLint);
#define glSamplerParameteri _ptrc_glSamplerParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteriv)(GLuint, GLenum, const GLint *);
#define glSamplerParameteriv _ptrc_glSamplerParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisor)(GLuint, GLuint);
#define glVertexAttribDivisor _ptrc_glVertexAttribDivisor
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP1ui _ptrc_glVertexAttribP1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP1uiv _ptrc_glVertexAttribP1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP2ui _ptrc_glVertexAttribP2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP2uiv _ptrc_glVertexAttribP2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP3ui _ptrc_glVertexAttribP3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP3uiv _ptrc_glVertexAttribP3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4ui)(GLuint, GLenum, GLboolean, GLuint);
#define glVertexAttribP4ui _ptrc_glVertexAttribP4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4uiv)(GLuint, GLenum, GLboolean, const GLuint *);
#define glVertexAttribP4uiv _ptrc_glVertexAttribP4uiv

extern void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryIndexed)(GLenum, GLuint, GLuint);
#define glBeginQueryIndexed _ptrc_glBeginQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedback)(GLenum, GLuint);
#define glBindTransformFeedback _ptrc_glBindTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparatei)(GLuint, GLenum, GLenum);
#define glBlendEquationSeparatei _ptrc_glBlendEquationSeparatei
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationi)(GLuint, GLenum);
#define glBlendEquationi _ptrc_glBlendEquationi
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparatei)(GLuint, GLenum, GLenum, GLenum, GLenum);
#define glBlendFuncSeparatei _ptrc_glBlendFuncSeparatei
extern void (CODEGEN_FUNCPTR *_ptrc_glBlendFunci)(GLuint, GLenum, GLenum);
#define glBlendFunci _ptrc_glBlendFunci
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacks)(GLsizei, const GLuint *);
#define glDeleteTransformFeedbacks _ptrc_glDeleteTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysIndirect)(GLenum, const GLvoid *);
#define glDrawArraysIndirect _ptrc_glDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsIndirect)(GLenum, GLenum, const GLvoid *);
#define glDrawElementsIndirect _ptrc_glDrawElementsIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedback)(GLenum, GLuint);
#define glDrawTransformFeedback _ptrc_glDrawTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStream)(GLenum, GLuint, GLuint);
#define glDrawTransformFeedbackStream _ptrc_glDrawTransformFeedbackStream
extern void (CODEGEN_FUNCPTR *_ptrc_glEndQueryIndexed)(GLenum, GLuint);
#define glEndQueryIndexed _ptrc_glEndQueryIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacks)(GLsizei, GLuint *);
#define glGenTransformFeedbacks _ptrc_glGenTransformFeedbacks
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveSubroutineName _ptrc_glGetActiveSubroutineName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetActiveSubroutineUniformName _ptrc_glGetActiveSubroutineUniformName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformiv)(GLuint, GLenum, GLuint, GLenum, GLint *);
#define glGetActiveSubroutineUniformiv _ptrc_glGetActiveSubroutineUniformiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStageiv)(GLuint, GLenum, GLenum, GLint *);
#define glGetProgramStageiv _ptrc_glGetProgramStageiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetQueryIndexediv)(GLenum, GLuint, GLenum, GLint *);
#define glGetQueryIndexediv _ptrc_glGetQueryIndexediv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineIndex)(GLuint, GLenum, const GLchar *);
#define glGetSubroutineIndex _ptrc_glGetSubroutineIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineUniformLocation)(GLuint, GLenum, const GLchar *);
#define glGetSubroutineUniformLocation _ptrc_glGetSubroutineUniformLocation
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformSubroutineuiv)(GLenum, GLint, GLuint *);
#define glGetUniformSubroutineuiv _ptrc_glGetUniformSubroutineuiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetUniformdv)(GLuint, GLint, GLdouble *);
#define glGetUniformdv _ptrc_glGetUniformdv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedback)(GLuint);
#define glIsTransformFeedback _ptrc_glIsTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShading)(GLfloat);
#define glMinSampleShading _ptrc_glMinSampleShading
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameterfv)(GLenum, const GLfloat *);
#define glPatchParameterfv _ptrc_glPatchParameterfv
extern void (CODEGEN_FUNCPTR *_ptrc_glPatchParameteri)(GLenum, GLint);
#define glPatchParameteri _ptrc_glPatchParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedback)();
#define glPauseTransformFeedback _ptrc_glPauseTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedback)();
#define glResumeTransformFeedback _ptrc_glResumeTransformFeedback
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1d)(GLint, GLdouble);
#define glUniform1d _ptrc_glUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform1dv)(GLint, GLsizei, const GLdouble *);
#define glUniform1dv _ptrc_glUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2d)(GLint, GLdouble, GLdouble);
#define glUniform2d _ptrc_glUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform2dv)(GLint, GLsizei, const GLdouble *);
#define glUniform2dv _ptrc_glUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3d)(GLint, GLdouble, GLdouble, GLdouble);
#define glUniform3d _ptrc_glUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform3dv)(GLint, GLsizei, const GLdouble *);
#define glUniform3dv _ptrc_glUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4d)(GLint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glUniform4d _ptrc_glUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glUniform4dv)(GLint, GLsizei, const GLdouble *);
#define glUniform4dv _ptrc_glUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix2dv _ptrc_glUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix2x3dv _ptrc_glUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix2x4dv _ptrc_glUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix3dv _ptrc_glUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix3x2dv _ptrc_glUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix3x4dv _ptrc_glUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix4dv _ptrc_glUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix4x2dv _ptrc_glUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3dv)(GLint, GLsizei, GLboolean, const GLdouble *);
#define glUniformMatrix4x3dv _ptrc_glUniformMatrix4x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glUniformSubroutinesuiv)(GLenum, GLsizei, const GLuint *);
#define glUniformSubroutinesuiv _ptrc_glUniformSubroutinesuiv

extern void (CODEGEN_FUNCPTR *_ptrc_glActiveShaderProgram)(GLuint, GLuint);
#define glActiveShaderProgram _ptrc_glActiveShaderProgram
extern void (CODEGEN_FUNCPTR *_ptrc_glBindProgramPipeline)(GLuint);
#define glBindProgramPipeline _ptrc_glBindProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glClearDepthf)(GLfloat);
#define glClearDepthf _ptrc_glClearDepthf
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramv)(GLenum, GLsizei, const GLchar *const*);
#define glCreateShaderProgramv _ptrc_glCreateShaderProgramv
extern void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramPipelines)(GLsizei, const GLuint *);
#define glDeleteProgramPipelines _ptrc_glDeleteProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeArrayv)(GLuint, GLsizei, const GLdouble *);
#define glDepthRangeArrayv _ptrc_glDepthRangeArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeIndexed)(GLuint, GLdouble, GLdouble);
#define glDepthRangeIndexed _ptrc_glDepthRangeIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glDepthRangef)(GLfloat, GLfloat);
#define glDepthRangef _ptrc_glDepthRangef
extern void (CODEGEN_FUNCPTR *_ptrc_glGenProgramPipelines)(GLsizei, GLuint *);
#define glGenProgramPipelines _ptrc_glGenProgramPipelines
extern void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_v)(GLenum, GLuint, GLdouble *);
#define glGetDoublei_v _ptrc_glGetDoublei_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_v)(GLenum, GLuint, GLfloat *);
#define glGetFloati_v _ptrc_glGetFloati_v
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramBinary)(GLuint, GLsizei, GLsizei *, GLenum *, GLvoid *);
#define glGetProgramBinary _ptrc_glGetProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetProgramPipelineInfoLog _ptrc_glGetProgramPipelineInfoLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineiv)(GLuint, GLenum, GLint *);
#define glGetProgramPipelineiv _ptrc_glGetProgramPipelineiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetShaderPrecisionFormat)(GLenum, GLenum, GLint *, GLint *);
#define glGetShaderPrecisionFormat _ptrc_glGetShaderPrecisionFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdv)(GLuint, GLenum, GLdouble *);
#define glGetVertexAttribLdv _ptrc_glGetVertexAttribLdv
extern GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramPipeline)(GLuint);
#define glIsProgramPipeline _ptrc_glIsProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramBinary)(GLuint, GLenum, const GLvoid *, GLsizei);
#define glProgramBinary _ptrc_glProgramBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteri)(GLuint, GLenum, GLint);
#define glProgramParameteri _ptrc_glProgramParameteri
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1d)(GLuint, GLint, GLdouble);
#define glProgramUniform1d _ptrc_glProgramUniform1d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform1dv _ptrc_glProgramUniform1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1f)(GLuint, GLint, GLfloat);
#define glProgramUniform1f _ptrc_glProgramUniform1f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform1fv _ptrc_glProgramUniform1fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i)(GLuint, GLint, GLint);
#define glProgramUniform1i _ptrc_glProgramUniform1i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform1iv _ptrc_glProgramUniform1iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui)(GLuint, GLint, GLuint);
#define glProgramUniform1ui _ptrc_glProgramUniform1ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform1uiv _ptrc_glProgramUniform1uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2d)(GLuint, GLint, GLdouble, GLdouble);
#define glProgramUniform2d _ptrc_glProgramUniform2d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform2dv _ptrc_glProgramUniform2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2f)(GLuint, GLint, GLfloat, GLfloat);
#define glProgramUniform2f _ptrc_glProgramUniform2f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform2fv _ptrc_glProgramUniform2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i)(GLuint, GLint, GLint, GLint);
#define glProgramUniform2i _ptrc_glProgramUniform2i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform2iv _ptrc_glProgramUniform2iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui)(GLuint, GLint, GLuint, GLuint);
#define glProgramUniform2ui _ptrc_glProgramUniform2ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform2uiv _ptrc_glProgramUniform2uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3d)(GLuint, GLint, GLdouble, GLdouble, GLdouble);
#define glProgramUniform3d _ptrc_glProgramUniform3d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform3dv _ptrc_glProgramUniform3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3f)(GLuint, GLint, GLfloat, GLfloat, GLfloat);
#define glProgramUniform3f _ptrc_glProgramUniform3f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform3fv _ptrc_glProgramUniform3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i)(GLuint, GLint, GLint, GLint, GLint);
#define glProgramUniform3i _ptrc_glProgramUniform3i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform3iv _ptrc_glProgramUniform3iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui)(GLuint, GLint, GLuint, GLuint, GLuint);
#define glProgramUniform3ui _ptrc_glProgramUniform3ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform3uiv _ptrc_glProgramUniform3uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4d)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glProgramUniform4d _ptrc_glProgramUniform4d
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dv)(GLuint, GLint, GLsizei, const GLdouble *);
#define glProgramUniform4dv _ptrc_glProgramUniform4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4f)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glProgramUniform4f _ptrc_glProgramUniform4f
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fv)(GLuint, GLint, GLsizei, const GLfloat *);
#define glProgramUniform4fv _ptrc_glProgramUniform4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i)(GLuint, GLint, GLint, GLint, GLint, GLint);
#define glProgramUniform4i _ptrc_glProgramUniform4i
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iv)(GLuint, GLint, GLsizei, const GLint *);
#define glProgramUniform4iv _ptrc_glProgramUniform4iv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
#define glProgramUniform4ui _ptrc_glProgramUniform4ui
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiv)(GLuint, GLint, GLsizei, const GLuint *);
#define glProgramUniform4uiv _ptrc_glProgramUniform4uiv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2dv _ptrc_glProgramUniformMatrix2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2fv _ptrc_glProgramUniformMatrix2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2x3dv _ptrc_glProgramUniformMatrix2x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2x3fv _ptrc_glProgramUniformMatrix2x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix2x4dv _ptrc_glProgramUniformMatrix2x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix2x4fv _ptrc_glProgramUniformMatrix2x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3dv _ptrc_glProgramUniformMatrix3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3fv _ptrc_glProgramUniformMatrix3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3x2dv _ptrc_glProgramUniformMatrix3x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3x2fv _ptrc_glProgramUniformMatrix3x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix3x4dv _ptrc_glProgramUniformMatrix3x4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix3x4fv _ptrc_glProgramUniformMatrix3x4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4dv _ptrc_glProgramUniformMatrix4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4fv _ptrc_glProgramUniformMatrix4fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4x2dv _ptrc_glProgramUniformMatrix4x2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4x2fv _ptrc_glProgramUniformMatrix4x2fv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
#define glProgramUniformMatrix4x3dv _ptrc_glProgramUniformMatrix4x3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
#define glProgramUniformMatrix4x3fv _ptrc_glProgramUniformMatrix4x3fv
extern void (CODEGEN_FUNCPTR *_ptrc_glReleaseShaderCompiler)();
#define glReleaseShaderCompiler _ptrc_glReleaseShaderCompiler
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorArrayv)(GLuint, GLsizei, const GLint *);
#define glScissorArrayv _ptrc_glScissorArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexed)(GLuint, GLint, GLint, GLsizei, GLsizei);
#define glScissorIndexed _ptrc_glScissorIndexed
extern void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexedv)(GLuint, const GLint *);
#define glScissorIndexedv _ptrc_glScissorIndexedv
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderBinary)(GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei);
#define glShaderBinary _ptrc_glShaderBinary
extern void (CODEGEN_FUNCPTR *_ptrc_glUseProgramStages)(GLuint, GLbitfield, GLuint);
#define glUseProgramStages _ptrc_glUseProgramStages
extern void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramPipeline)(GLuint);
#define glValidateProgramPipeline _ptrc_glValidateProgramPipeline
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1d)(GLuint, GLdouble);
#define glVertexAttribL1d _ptrc_glVertexAttribL1d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dv)(GLuint, const GLdouble *);
#define glVertexAttribL1dv _ptrc_glVertexAttribL1dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2d)(GLuint, GLdouble, GLdouble);
#define glVertexAttribL2d _ptrc_glVertexAttribL2d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dv)(GLuint, const GLdouble *);
#define glVertexAttribL2dv _ptrc_glVertexAttribL2dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3d)(GLuint, GLdouble, GLdouble, GLdouble);
#define glVertexAttribL3d _ptrc_glVertexAttribL3d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dv)(GLuint, const GLdouble *);
#define glVertexAttribL3dv _ptrc_glVertexAttribL3dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
#define glVertexAttribL4d _ptrc_glVertexAttribL4d
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dv)(GLuint, const GLdouble *);
#define glVertexAttribL4dv _ptrc_glVertexAttribL4dv
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointer)(GLuint, GLint, GLenum, GLsizei, const GLvoid *);
#define glVertexAttribLPointer _ptrc_glVertexAttribLPointer
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportArrayv)(GLuint, GLsizei, const GLfloat *);
#define glViewportArrayv _ptrc_glViewportArrayv
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedf)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
#define glViewportIndexedf _ptrc_glViewportIndexedf
extern void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedfv)(GLuint, const GLfloat *);
#define glViewportIndexedfv _ptrc_glViewportIndexedfv

extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTexture)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum);
#define glBindImageTexture _ptrc_glBindImageTexture
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedBaseInstance)(GLenum, GLint, GLsizei, GLsizei, GLuint);
#define glDrawArraysInstancedBaseInstance _ptrc_glDrawArraysInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseInstance)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint);
#define glDrawElementsInstancedBaseInstance _ptrc_glDrawElementsInstancedBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint);
#define glDrawElementsInstancedBaseVertexBaseInstance _ptrc_glDrawElementsInstancedBaseVertexBaseInstance
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackInstanced)(GLenum, GLuint, GLsizei);
#define glDrawTransformFeedbackInstanced _ptrc_glDrawTransformFeedbackInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStreamInstanced)(GLenum, GLuint, GLuint, GLsizei);
#define glDrawTransformFeedbackStreamInstanced _ptrc_glDrawTransformFeedbackStreamInstanced
extern void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAtomicCounterBufferiv)(GLuint, GLuint, GLenum, GLint *);
#define glGetActiveAtomicCounterBufferiv _ptrc_glGetActiveAtomicCounterBufferiv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformati64v)(GLenum, GLenum, GLenum, GLsizei, GLint64 *);
#define glGetInternalformati64v _ptrc_glGetInternalformati64v
extern void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrier)(GLbitfield);
#define glMemoryBarrier _ptrc_glMemoryBarrier
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage1D)(GLenum, GLsizei, GLenum, GLsizei);
#define glTexStorage1D _ptrc_glTexStorage1D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
#define glTexStorage2D _ptrc_glTexStorage2D
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
#define glTexStorage3D _ptrc_glTexStorage3D

extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffer)(GLuint, GLuint, GLintptr, GLsizei);
#define glBindVertexBuffer _ptrc_glBindVertexBuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferData)(GLenum, GLenum, GLenum, GLenum, const void *);
#define glClearBufferData _ptrc_glClearBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glClearBufferSubData)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *);
#define glClearBufferSubData _ptrc_glClearBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubData)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
#define glCopyImageSubData _ptrc_glCopyImageSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallback)(GLDEBUGPROC, const void *);
#define glDebugMessageCallback _ptrc_glDebugMessageCallback
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControl)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean);
#define glDebugMessageControl _ptrc_glDebugMessageControl
extern void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsert)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *);
#define glDebugMessageInsert _ptrc_glDebugMessageInsert
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchCompute)(GLuint, GLuint, GLuint);
#define glDispatchCompute _ptrc_glDispatchCompute
extern void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeIndirect)(GLintptr);
#define glDispatchComputeIndirect _ptrc_glDispatchComputeIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glFramebufferParameteri)(GLenum, GLenum, GLint);
#define glFramebufferParameteri _ptrc_glFramebufferParameteri
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLog)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);
#define glGetDebugMessageLog _ptrc_glGetDebugMessageLog
extern void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameteriv)(GLenum, GLenum, GLint *);
#define glGetFramebufferParameteriv _ptrc_glGetFramebufferParameteriv
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectLabel)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetObjectLabel _ptrc_glGetObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetObjectPtrLabel)(const void *, GLsizei, GLsizei *, GLchar *);
#define glGetObjectPtrLabel _ptrc_glGetObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInterfaceiv)(GLuint, GLenum, GLenum, GLint *);
#define glGetProgramInterfaceiv _ptrc_glGetProgramInterfaceiv
extern GLuint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceIndex)(GLuint, GLenum, const GLchar *);
#define glGetProgramResourceIndex _ptrc_glGetProgramResourceIndex
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocation)(GLuint, GLenum, const GLchar *);
#define glGetProgramResourceLocation _ptrc_glGetProgramResourceLocation
extern GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocationIndex)(GLuint, GLenum, const GLchar *);
#define glGetProgramResourceLocationIndex _ptrc_glGetProgramResourceLocationIndex
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
#define glGetProgramResourceName _ptrc_glGetProgramResourceName
extern void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceiv)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *);
#define glGetProgramResourceiv _ptrc_glGetProgramResourceiv
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferData)(GLuint);
#define glInvalidateBufferData _ptrc_glInvalidateBufferData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferSubData)(GLuint, GLintptr, GLsizeiptr);
#define glInvalidateBufferSubData _ptrc_glInvalidateBufferSubData
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateFramebuffer)(GLenum, GLsizei, const GLenum *);
#define glInvalidateFramebuffer _ptrc_glInvalidateFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateSubFramebuffer)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei);
#define glInvalidateSubFramebuffer _ptrc_glInvalidateSubFramebuffer
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexImage)(GLuint, GLint);
#define glInvalidateTexImage _ptrc_glInvalidateTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
#define glInvalidateTexSubImage _ptrc_glInvalidateTexSubImage
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirect)(GLenum, const void *, GLsizei, GLsizei);
#define glMultiDrawArraysIndirect _ptrc_glMultiDrawArraysIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirect)(GLenum, GLenum, const void *, GLsizei, GLsizei);
#define glMultiDrawElementsIndirect _ptrc_glMultiDrawElementsIndirect
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectLabel)(GLenum, GLuint, GLsizei, const GLchar *);
#define glObjectLabel _ptrc_glObjectLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glObjectPtrLabel)(const void *, GLsizei, const GLchar *);
#define glObjectPtrLabel _ptrc_glObjectPtrLabel
extern void (CODEGEN_FUNCPTR *_ptrc_glPopDebugGroup)();
#define glPopDebugGroup _ptrc_glPopDebugGroup
extern void (CODEGEN_FUNCPTR *_ptrc_glPushDebugGroup)(GLenum, GLuint, GLsizei, const GLchar *);
#define glPushDebugGroup _ptrc_glPushDebugGroup
extern void (CODEGEN_FUNCPTR *_ptrc_glShaderStorageBlockBinding)(GLuint, GLuint, GLuint);
#define glShaderStorageBlockBinding _ptrc_glShaderStorageBlockBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glTexBufferRange)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr);
#define glTexBufferRange _ptrc_glTexBufferRange
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
#define glTexStorage2DMultisample _ptrc_glTexStorage2DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
#define glTexStorage3DMultisample _ptrc_glTexStorage3DMultisample
extern void (CODEGEN_FUNCPTR *_ptrc_glTextureView)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint);
#define glTextureView _ptrc_glTextureView
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribBinding)(GLuint, GLuint);
#define glVertexAttribBinding _ptrc_glVertexAttribBinding
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormat)(GLuint, GLint, GLenum, GLboolean, GLuint);
#define glVertexAttribFormat _ptrc_glVertexAttribFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormat)(GLuint, GLint, GLenum, GLuint);
#define glVertexAttribIFormat _ptrc_glVertexAttribIFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormat)(GLuint, GLint, GLenum, GLuint);
#define glVertexAttribLFormat _ptrc_glVertexAttribLFormat
extern void (CODEGEN_FUNCPTR *_ptrc_glVertexBindingDivisor)(GLuint, GLuint);
#define glVertexBindingDivisor _ptrc_glVertexBindingDivisor

extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersBase)(GLenum, GLuint, GLsizei, const GLuint *);
#define glBindBuffersBase _ptrc_glBindBuffersBase
extern void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersRange)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *);
#define glBindBuffersRange _ptrc_glBindBuffersRange
extern void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextures)(GLuint, GLsizei, const GLuint *);
#define glBindImageTextures _ptrc_glBindImageTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindSamplers)(GLuint, GLsizei, const GLuint *);
#define glBindSamplers _ptrc_glBindSamplers
extern void (CODEGEN_FUNCPTR *_ptrc_glBindTextures)(GLuint, GLsizei, const GLuint *);
#define glBindTextures _ptrc_glBindTextures
extern void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffers)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *);
#define glBindVertexBuffers _ptrc_glBindVertexBuffers
extern void (CODEGEN_FUNCPTR *_ptrc_glBufferStorage)(GLenum, GLsizeiptr, const void *, GLbitfield);
#define glBufferStorage _ptrc_glBufferStorage
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexImage)(GLuint, GLint, GLenum, GLenum, const void *);
#define glClearTexImage _ptrc_glClearTexImage
extern void (CODEGEN_FUNCPTR *_ptrc_glClearTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
#define glClearTexSubImage _ptrc_glClearTexSubImage

enum ogl_LoadStatus
{
	ogl_LOAD_FAILED = 0,
	ogl_LOAD_SUCCEEDED = 1,
};

int ogl_LoadFunctions();

int ogl_GetMinorVersion();
int ogl_GetMajorVersion();
int ogl_IsVersionGEQ(int majorVersion, int minorVersion);

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif //POINTER_C_GENERATED_HEADER_OPENGL_H
