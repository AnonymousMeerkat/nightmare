#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "gl_compat_4_4.h"

#if defined(__APPLE__)
#include <mach-o/dyld.h>

static void* AppleGLGetProcAddress (const GLubyte *name)
{
  static const struct mach_header* image = NULL;
  NSSymbol symbol;
  char* symbolName;
  if (NULL == image)
  {
    image = NSAddImage("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", NSADDIMAGE_OPTION_RETURN_ON_ERROR);
  }
  /* prepend a '_' for the Unix C symbol mangling convention */
  symbolName = malloc(strlen((const char*)name) + 2);
  strcpy(symbolName+1, (const char*)name);
  symbolName[0] = '_';
  symbol = NULL;
  /* if (NSIsSymbolNameDefined(symbolName))
	 symbol = NSLookupAndBindSymbol(symbolName); */
  symbol = image ? NSLookupSymbolInImage(image, symbolName, NSLOOKUPSYMBOLINIMAGE_OPTION_BIND | NSLOOKUPSYMBOLINIMAGE_OPTION_RETURN_ON_ERROR) : NULL;
  free(symbolName);
  return symbol ? NSAddressOfSymbol(symbol) : NULL;
}
#endif /* __APPLE__ */

#if defined(__sgi) || defined (__sun)
#include <dlfcn.h>
#include <stdio.h>

static void* SunGetProcAddress (const GLubyte* name)
{
  static void* h = NULL;
  static void* gpa;

  if (h == NULL)
  {
    if ((h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL)) == NULL) return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void*(*)(const GLubyte*))gpa)(name);
  else
    return dlsym(h, (const char*)name);
}
#endif /* __sgi || __sun */

#if defined(_WIN32)

#ifdef _MSC_VER
#pragma warning(disable: 4055)
#pragma warning(disable: 4054)
#endif

static int TestPointer(const PROC pTest)
{
	ptrdiff_t iTest;
	if(!pTest) return 0;
	iTest = (ptrdiff_t)pTest;
	
	if(iTest == 1 || iTest == 2 || iTest == 3 || iTest == -1) return 0;
	
	return 1;
}

static PROC WinGetProcAddress(const char *name)
{
	HMODULE glMod = NULL;
	PROC pFunc = wglGetProcAddress((LPCSTR)name);
	if(TestPointer(pFunc))
	{
		return pFunc;
	}
	glMod = GetModuleHandleA("OpenGL32.dll");
	return (PROC)GetProcAddress(glMod, (LPCSTR)name);
}
	
#define IntGetProcAddress(name) WinGetProcAddress(name)
#else
	#if defined(__APPLE__)
		#define IntGetProcAddress(name) AppleGLGetProcAddress(name)
	#else
		#if defined(__sgi) || defined(__sun)
			#define IntGetProcAddress(name) SunGetProcAddress(name)
		#else /* GLX */
		    #include <GL/glx.h>

			#define IntGetProcAddress(name) (*glXGetProcAddressARB)((const GLubyte*)name)
		#endif
	#endif
#endif

int ogl_ext_ARB_imaging = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_array_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_rg = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_compression_rgtc = ogl_LOAD_FAILED;
int ogl_ext_ARB_map_buffer_range = ogl_LOAD_FAILED;
int ogl_ext_ARB_half_float_vertex = ogl_LOAD_FAILED;
int ogl_ext_ARB_framebuffer_sRGB = ogl_LOAD_FAILED;
int ogl_ext_ARB_framebuffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_depth_buffer_float = ogl_LOAD_FAILED;
int ogl_ext_ARB_uniform_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_copy_buffer = ogl_LOAD_FAILED;
int ogl_ext_ARB_depth_clamp = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_elements_base_vertex = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_coord_conventions = ogl_LOAD_FAILED;
int ogl_ext_ARB_provoking_vertex = ogl_LOAD_FAILED;
int ogl_ext_ARB_seamless_cube_map = ogl_LOAD_FAILED;
int ogl_ext_ARB_sync = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_multisample = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_array_bgra = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_rgb10_a2ui = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_swizzle = ogl_LOAD_FAILED;
int ogl_ext_ARB_timer_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_type_2_10_10_10_rev = ogl_LOAD_FAILED;
int ogl_ext_ARB_blend_func_extended = ogl_LOAD_FAILED;
int ogl_ext_ARB_occlusion_query2 = ogl_LOAD_FAILED;
int ogl_ext_ARB_sampler_objects = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_ARB_gpu_shader5 = ogl_LOAD_FAILED;
int ogl_ext_ARB_gpu_shader_fp64 = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_subroutine = ogl_LOAD_FAILED;
int ogl_ext_ARB_tessellation_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_transform_feedback2 = ogl_LOAD_FAILED;
int ogl_ext_ARB_transform_feedback3 = ogl_LOAD_FAILED;
int ogl_ext_ARB_ES2_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_get_program_binary = ogl_LOAD_FAILED;
int ogl_ext_ARB_separate_shader_objects = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_attrib_64bit = ogl_LOAD_FAILED;
int ogl_ext_ARB_viewport_array = ogl_LOAD_FAILED;
int ogl_ext_ARB_base_instance = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_420pack = ogl_LOAD_FAILED;
int ogl_ext_ARB_transform_feedback_instanced = ogl_LOAD_FAILED;
int ogl_ext_ARB_compressed_texture_pixel_storage = ogl_LOAD_FAILED;
int ogl_ext_ARB_conservative_depth = ogl_LOAD_FAILED;
int ogl_ext_ARB_internalformat_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_map_buffer_alignment = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_atomic_counters = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_image_load_store = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_packing = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_storage = ogl_LOAD_FAILED;
int ogl_ext_KHR_debug = ogl_LOAD_FAILED;
int ogl_ext_ARB_arrays_of_arrays = ogl_LOAD_FAILED;
int ogl_ext_ARB_clear_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_compute_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_copy_image = ogl_LOAD_FAILED;
int ogl_ext_ARB_ES3_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_explicit_uniform_location = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_layer_viewport = ogl_LOAD_FAILED;
int ogl_ext_ARB_framebuffer_no_attachments = ogl_LOAD_FAILED;
int ogl_ext_ARB_internalformat_query2 = ogl_LOAD_FAILED;
int ogl_ext_ARB_invalidate_subdata = ogl_LOAD_FAILED;
int ogl_ext_ARB_multi_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_ARB_program_interface_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_image_size = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_storage_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_stencil_texturing = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_buffer_range = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_query_levels = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_storage_multisample = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_view = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_attrib_binding = ogl_LOAD_FAILED;
int ogl_ext_ARB_buffer_storage = ogl_LOAD_FAILED;
int ogl_ext_ARB_clear_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_enhanced_layouts = ogl_LOAD_FAILED;
int ogl_ext_ARB_multi_bind = ogl_LOAD_FAILED;
int ogl_ext_ARB_query_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_mirror_clamp_to_edge = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_stencil8 = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_type_10f_11f_11f_rev = ogl_LOAD_FAILED;
int ogl_ext_3DFX_multisample = ogl_LOAD_FAILED;
int ogl_ext_3DFX_tbuffer = ogl_LOAD_FAILED;
int ogl_ext_3DFX_texture_compression_FXT1 = ogl_LOAD_FAILED;
int ogl_ext_AMD_blend_minmax_factor = ogl_LOAD_FAILED;
int ogl_ext_AMD_conservative_depth = ogl_LOAD_FAILED;
int ogl_ext_AMD_debug_output = ogl_LOAD_FAILED;
int ogl_ext_AMD_depth_clamp_separate = ogl_LOAD_FAILED;
int ogl_ext_AMD_draw_buffers_blend = ogl_LOAD_FAILED;
int ogl_ext_AMD_interleaved_elements = ogl_LOAD_FAILED;
int ogl_ext_AMD_multi_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_AMD_name_gen_delete = ogl_LOAD_FAILED;
int ogl_ext_AMD_performance_monitor = ogl_LOAD_FAILED;
int ogl_ext_AMD_pinned_memory = ogl_LOAD_FAILED;
int ogl_ext_AMD_query_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_AMD_sample_positions = ogl_LOAD_FAILED;
int ogl_ext_AMD_seamless_cubemap_per_texture = ogl_LOAD_FAILED;
int ogl_ext_AMD_shader_stencil_export = ogl_LOAD_FAILED;
int ogl_ext_AMD_shader_trinary_minmax = ogl_LOAD_FAILED;
int ogl_ext_AMD_sparse_texture = ogl_LOAD_FAILED;
int ogl_ext_AMD_stencil_operation_extended = ogl_LOAD_FAILED;
int ogl_ext_AMD_texture_texture4 = ogl_LOAD_FAILED;
int ogl_ext_AMD_transform_feedback3_lines_triangles = ogl_LOAD_FAILED;
int ogl_ext_AMD_vertex_shader_layer = ogl_LOAD_FAILED;
int ogl_ext_AMD_vertex_shader_tessellator = ogl_LOAD_FAILED;
int ogl_ext_AMD_vertex_shader_viewport_index = ogl_LOAD_FAILED;
int ogl_ext_APPLE_aux_depth_stencil = ogl_LOAD_FAILED;
int ogl_ext_APPLE_client_storage = ogl_LOAD_FAILED;
int ogl_ext_APPLE_element_array = ogl_LOAD_FAILED;
int ogl_ext_APPLE_fence = ogl_LOAD_FAILED;
int ogl_ext_APPLE_float_pixels = ogl_LOAD_FAILED;
int ogl_ext_APPLE_flush_buffer_range = ogl_LOAD_FAILED;
int ogl_ext_APPLE_object_purgeable = ogl_LOAD_FAILED;
int ogl_ext_APPLE_rgb_422 = ogl_LOAD_FAILED;
int ogl_ext_APPLE_row_bytes = ogl_LOAD_FAILED;
int ogl_ext_APPLE_specular_vector = ogl_LOAD_FAILED;
int ogl_ext_APPLE_texture_range = ogl_LOAD_FAILED;
int ogl_ext_APPLE_transform_hint = ogl_LOAD_FAILED;
int ogl_ext_APPLE_vertex_array_object = ogl_LOAD_FAILED;
int ogl_ext_APPLE_vertex_array_range = ogl_LOAD_FAILED;
int ogl_ext_APPLE_vertex_program_evaluators = ogl_LOAD_FAILED;
int ogl_ext_APPLE_ycbcr_422 = ogl_LOAD_FAILED;
int ogl_ext_ARB_bindless_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_cl_event = ogl_LOAD_FAILED;
int ogl_ext_ARB_color_buffer_float = ogl_LOAD_FAILED;
int ogl_ext_ARB_compatibility = ogl_LOAD_FAILED;
int ogl_ext_ARB_compute_variable_group_size = ogl_LOAD_FAILED;
int ogl_ext_ARB_debug_output = ogl_LOAD_FAILED;
int ogl_ext_ARB_depth_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_buffers = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_buffers_blend = ogl_LOAD_FAILED;
int ogl_ext_ARB_draw_instanced = ogl_LOAD_FAILED;
int ogl_ext_ARB_explicit_attrib_location = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_program = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_program_shadow = ogl_LOAD_FAILED;
int ogl_ext_ARB_fragment_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_geometry_shader4 = ogl_LOAD_FAILED;
int ogl_ext_ARB_half_float_pixel = ogl_LOAD_FAILED;
int ogl_ext_ARB_indirect_parameters = ogl_LOAD_FAILED;
int ogl_ext_ARB_instanced_arrays = ogl_LOAD_FAILED;
int ogl_ext_ARB_matrix_palette = ogl_LOAD_FAILED;
int ogl_ext_ARB_multisample = ogl_LOAD_FAILED;
int ogl_ext_ARB_multitexture = ogl_LOAD_FAILED;
int ogl_ext_ARB_occlusion_query = ogl_LOAD_FAILED;
int ogl_ext_ARB_pixel_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_point_parameters = ogl_LOAD_FAILED;
int ogl_ext_ARB_point_sprite = ogl_LOAD_FAILED;
int ogl_ext_ARB_robust_buffer_access_behavior = ogl_LOAD_FAILED;
int ogl_ext_ARB_robustness = ogl_LOAD_FAILED;
int ogl_ext_ARB_robustness_isolation = ogl_LOAD_FAILED;
int ogl_ext_ARB_sample_shading = ogl_LOAD_FAILED;
int ogl_ext_ARB_seamless_cubemap_per_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_bit_encoding = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_draw_parameters = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_group_vote = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_objects = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_precision = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_stencil_export = ogl_LOAD_FAILED;
int ogl_ext_ARB_shader_texture_lod = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_100 = ogl_LOAD_FAILED;
int ogl_ext_ARB_shading_language_include = ogl_LOAD_FAILED;
int ogl_ext_ARB_shadow = ogl_LOAD_FAILED;
int ogl_ext_ARB_shadow_ambient = ogl_LOAD_FAILED;
int ogl_ext_ARB_sparse_texture = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_border_clamp = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_buffer_object_rgb32 = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_compression = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_compression_bptc = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_cube_map = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_cube_map_array = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_add = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_combine = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_crossbar = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_env_dot3 = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_float = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_gather = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_mirrored_repeat = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_non_power_of_two = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_query_lod = ogl_LOAD_FAILED;
int ogl_ext_ARB_texture_rectangle = ogl_LOAD_FAILED;
int ogl_ext_ARB_transpose_matrix = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_blend = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_program = ogl_LOAD_FAILED;
int ogl_ext_ARB_vertex_shader = ogl_LOAD_FAILED;
int ogl_ext_ARB_window_pos = ogl_LOAD_FAILED;
int ogl_ext_ATI_draw_buffers = ogl_LOAD_FAILED;
int ogl_ext_ATI_element_array = ogl_LOAD_FAILED;
int ogl_ext_ATI_envmap_bumpmap = ogl_LOAD_FAILED;
int ogl_ext_ATI_fragment_shader = ogl_LOAD_FAILED;
int ogl_ext_ATI_map_object_buffer = ogl_LOAD_FAILED;
int ogl_ext_ATI_meminfo = ogl_LOAD_FAILED;
int ogl_ext_ATI_pixel_format_float = ogl_LOAD_FAILED;
int ogl_ext_ATI_pn_triangles = ogl_LOAD_FAILED;
int ogl_ext_ATI_separate_stencil = ogl_LOAD_FAILED;
int ogl_ext_ATI_text_fragment_shader = ogl_LOAD_FAILED;
int ogl_ext_ATI_texture_env_combine3 = ogl_LOAD_FAILED;
int ogl_ext_ATI_texture_float = ogl_LOAD_FAILED;
int ogl_ext_ATI_texture_mirror_once = ogl_LOAD_FAILED;
int ogl_ext_ATI_vertex_array_object = ogl_LOAD_FAILED;
int ogl_ext_ATI_vertex_attrib_array_object = ogl_LOAD_FAILED;
int ogl_ext_ATI_vertex_streams = ogl_LOAD_FAILED;
int ogl_ext_EXT_422_pixels = ogl_LOAD_FAILED;
int ogl_ext_EXT_abgr = ogl_LOAD_FAILED;
int ogl_ext_EXT_bgra = ogl_LOAD_FAILED;
int ogl_ext_EXT_bindable_uniform = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_color = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_equation_separate = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_func_separate = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_logic_op = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_minmax = ogl_LOAD_FAILED;
int ogl_ext_EXT_blend_subtract = ogl_LOAD_FAILED;
int ogl_ext_EXT_clip_volume_hint = ogl_LOAD_FAILED;
int ogl_ext_EXT_cmyka = ogl_LOAD_FAILED;
int ogl_ext_EXT_color_subtable = ogl_LOAD_FAILED;
int ogl_ext_EXT_compiled_vertex_array = ogl_LOAD_FAILED;
int ogl_ext_EXT_convolution = ogl_LOAD_FAILED;
int ogl_ext_EXT_coordinate_frame = ogl_LOAD_FAILED;
int ogl_ext_EXT_copy_texture = ogl_LOAD_FAILED;
int ogl_ext_EXT_cull_vertex = ogl_LOAD_FAILED;
int ogl_ext_EXT_depth_bounds_test = ogl_LOAD_FAILED;
int ogl_ext_EXT_direct_state_access = ogl_LOAD_FAILED;
int ogl_ext_EXT_draw_buffers2 = ogl_LOAD_FAILED;
int ogl_ext_EXT_draw_instanced = ogl_LOAD_FAILED;
int ogl_ext_EXT_draw_range_elements = ogl_LOAD_FAILED;
int ogl_ext_EXT_fog_coord = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_blit = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_multisample = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_multisample_blit_scaled = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_framebuffer_sRGB = ogl_LOAD_FAILED;
int ogl_ext_EXT_geometry_shader4 = ogl_LOAD_FAILED;
int ogl_ext_EXT_gpu_program_parameters = ogl_LOAD_FAILED;
int ogl_ext_EXT_gpu_shader4 = ogl_LOAD_FAILED;
int ogl_ext_EXT_histogram = ogl_LOAD_FAILED;
int ogl_ext_EXT_index_array_formats = ogl_LOAD_FAILED;
int ogl_ext_EXT_index_func = ogl_LOAD_FAILED;
int ogl_ext_EXT_index_material = ogl_LOAD_FAILED;
int ogl_ext_EXT_index_texture = ogl_LOAD_FAILED;
int ogl_ext_EXT_light_texture = ogl_LOAD_FAILED;
int ogl_ext_EXT_misc_attribute = ogl_LOAD_FAILED;
int ogl_ext_EXT_multi_draw_arrays = ogl_LOAD_FAILED;
int ogl_ext_EXT_multisample = ogl_LOAD_FAILED;
int ogl_ext_EXT_packed_depth_stencil = ogl_LOAD_FAILED;
int ogl_ext_EXT_packed_float = ogl_LOAD_FAILED;
int ogl_ext_EXT_packed_pixels = ogl_LOAD_FAILED;
int ogl_ext_EXT_paletted_texture = ogl_LOAD_FAILED;
int ogl_ext_EXT_pixel_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_pixel_transform = ogl_LOAD_FAILED;
int ogl_ext_EXT_pixel_transform_color_table = ogl_LOAD_FAILED;
int ogl_ext_EXT_point_parameters = ogl_LOAD_FAILED;
int ogl_ext_EXT_polygon_offset = ogl_LOAD_FAILED;
int ogl_ext_EXT_provoking_vertex = ogl_LOAD_FAILED;
int ogl_ext_EXT_rescale_normal = ogl_LOAD_FAILED;
int ogl_ext_EXT_secondary_color = ogl_LOAD_FAILED;
int ogl_ext_EXT_separate_shader_objects = ogl_LOAD_FAILED;
int ogl_ext_EXT_separate_specular_color = ogl_LOAD_FAILED;
int ogl_ext_EXT_shader_image_load_store = ogl_LOAD_FAILED;
int ogl_ext_EXT_shadow_funcs = ogl_LOAD_FAILED;
int ogl_ext_EXT_shared_texture_palette = ogl_LOAD_FAILED;
int ogl_ext_EXT_stencil_clear_tag = ogl_LOAD_FAILED;
int ogl_ext_EXT_stencil_two_side = ogl_LOAD_FAILED;
int ogl_ext_EXT_stencil_wrap = ogl_LOAD_FAILED;
int ogl_ext_EXT_subtexture = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture3D = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_array = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_compression_latc = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_compression_rgtc = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_compression_s3tc = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_cube_map = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_env_add = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_env_combine = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_env_dot3 = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_filter_anisotropic = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_integer = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_lod_bias = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_mirror_clamp = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_object = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_perturb_normal = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_sRGB = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_sRGB_decode = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_shared_exponent = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_snorm = ogl_LOAD_FAILED;
int ogl_ext_EXT_texture_swizzle = ogl_LOAD_FAILED;
int ogl_ext_EXT_timer_query = ogl_LOAD_FAILED;
int ogl_ext_EXT_transform_feedback = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_array = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_array_bgra = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_attrib_64bit = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_shader = ogl_LOAD_FAILED;
int ogl_ext_EXT_vertex_weighting = ogl_LOAD_FAILED;
int ogl_ext_EXT_x11_sync_object = ogl_LOAD_FAILED;
int ogl_ext_GREMEDY_frame_terminator = ogl_LOAD_FAILED;
int ogl_ext_GREMEDY_string_marker = ogl_LOAD_FAILED;
int ogl_ext_HP_convolution_border_modes = ogl_LOAD_FAILED;
int ogl_ext_HP_image_transform = ogl_LOAD_FAILED;
int ogl_ext_HP_occlusion_test = ogl_LOAD_FAILED;
int ogl_ext_HP_texture_lighting = ogl_LOAD_FAILED;
int ogl_ext_IBM_cull_vertex = ogl_LOAD_FAILED;
int ogl_ext_IBM_multimode_draw_arrays = ogl_LOAD_FAILED;
int ogl_ext_IBM_rasterpos_clip = ogl_LOAD_FAILED;
int ogl_ext_IBM_static_data = ogl_LOAD_FAILED;
int ogl_ext_IBM_texture_mirrored_repeat = ogl_LOAD_FAILED;
int ogl_ext_IBM_vertex_array_lists = ogl_LOAD_FAILED;
int ogl_ext_INGR_blend_func_separate = ogl_LOAD_FAILED;
int ogl_ext_INGR_color_clamp = ogl_LOAD_FAILED;
int ogl_ext_INGR_interlace_read = ogl_LOAD_FAILED;
int ogl_ext_INTEL_map_texture = ogl_LOAD_FAILED;
int ogl_ext_INTEL_parallel_arrays = ogl_LOAD_FAILED;
int ogl_ext_KHR_texture_compression_astc_ldr = ogl_LOAD_FAILED;
int ogl_ext_MESAX_texture_stack = ogl_LOAD_FAILED;
int ogl_ext_MESA_pack_invert = ogl_LOAD_FAILED;
int ogl_ext_MESA_resize_buffers = ogl_LOAD_FAILED;
int ogl_ext_MESA_window_pos = ogl_LOAD_FAILED;
int ogl_ext_MESA_ycbcr_texture = ogl_LOAD_FAILED;
int ogl_ext_NVX_conditional_render = ogl_LOAD_FAILED;
int ogl_ext_NV_bindless_multi_draw_indirect = ogl_LOAD_FAILED;
int ogl_ext_NV_bindless_texture = ogl_LOAD_FAILED;
int ogl_ext_NV_blend_equation_advanced = ogl_LOAD_FAILED;
int ogl_ext_NV_blend_equation_advanced_coherent = ogl_LOAD_FAILED;
int ogl_ext_NV_blend_square = ogl_LOAD_FAILED;
int ogl_ext_NV_compute_program5 = ogl_LOAD_FAILED;
int ogl_ext_NV_conditional_render = ogl_LOAD_FAILED;
int ogl_ext_NV_copy_depth_to_color = ogl_LOAD_FAILED;
int ogl_ext_NV_copy_image = ogl_LOAD_FAILED;
int ogl_ext_NV_deep_texture3D = ogl_LOAD_FAILED;
int ogl_ext_NV_depth_buffer_float = ogl_LOAD_FAILED;
int ogl_ext_NV_depth_clamp = ogl_LOAD_FAILED;
int ogl_ext_NV_draw_texture = ogl_LOAD_FAILED;
int ogl_ext_NV_evaluators = ogl_LOAD_FAILED;
int ogl_ext_NV_explicit_multisample = ogl_LOAD_FAILED;
int ogl_ext_NV_fence = ogl_LOAD_FAILED;
int ogl_ext_NV_float_buffer = ogl_LOAD_FAILED;
int ogl_ext_NV_fog_distance = ogl_LOAD_FAILED;
int ogl_ext_NV_fragment_program = ogl_LOAD_FAILED;
int ogl_ext_NV_fragment_program2 = ogl_LOAD_FAILED;
int ogl_ext_NV_fragment_program4 = ogl_LOAD_FAILED;
int ogl_ext_NV_fragment_program_option = ogl_LOAD_FAILED;
int ogl_ext_NV_framebuffer_multisample_coverage = ogl_LOAD_FAILED;
int ogl_ext_NV_geometry_program4 = ogl_LOAD_FAILED;
int ogl_ext_NV_geometry_shader4 = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_program4 = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_program5 = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_program5_mem_extended = ogl_LOAD_FAILED;
int ogl_ext_NV_gpu_shader5 = ogl_LOAD_FAILED;
int ogl_ext_NV_half_float = ogl_LOAD_FAILED;
int ogl_ext_NV_light_max_exponent = ogl_LOAD_FAILED;
int ogl_ext_NV_multisample_coverage = ogl_LOAD_FAILED;
int ogl_ext_NV_multisample_filter_hint = ogl_LOAD_FAILED;
int ogl_ext_NV_occlusion_query = ogl_LOAD_FAILED;
int ogl_ext_NV_packed_depth_stencil = ogl_LOAD_FAILED;
int ogl_ext_NV_parameter_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_NV_parameter_buffer_object2 = ogl_LOAD_FAILED;
int ogl_ext_NV_path_rendering = ogl_LOAD_FAILED;
int ogl_ext_NV_pixel_data_range = ogl_LOAD_FAILED;
int ogl_ext_NV_point_sprite = ogl_LOAD_FAILED;
int ogl_ext_NV_present_video = ogl_LOAD_FAILED;
int ogl_ext_NV_primitive_restart = ogl_LOAD_FAILED;
int ogl_ext_NV_register_combiners = ogl_LOAD_FAILED;
int ogl_ext_NV_register_combiners2 = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_atomic_counters = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_atomic_float = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_buffer_load = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_buffer_store = ogl_LOAD_FAILED;
int ogl_ext_NV_shader_storage_buffer_object = ogl_LOAD_FAILED;
int ogl_ext_NV_tessellation_program5 = ogl_LOAD_FAILED;
int ogl_ext_NV_texgen_emboss = ogl_LOAD_FAILED;
int ogl_ext_NV_texgen_reflection = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_barrier = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_compression_vtc = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_env_combine4 = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_expand_normal = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_multisample = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_rectangle = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_shader = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_shader2 = ogl_LOAD_FAILED;
int ogl_ext_NV_texture_shader3 = ogl_LOAD_FAILED;
int ogl_ext_NV_transform_feedback = ogl_LOAD_FAILED;
int ogl_ext_NV_transform_feedback2 = ogl_LOAD_FAILED;
int ogl_ext_NV_vdpau_interop = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_array_range = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_array_range2 = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_attrib_integer_64bit = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_buffer_unified_memory = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program1_1 = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program2 = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program2_option = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program3 = ogl_LOAD_FAILED;
int ogl_ext_NV_vertex_program4 = ogl_LOAD_FAILED;
int ogl_ext_NV_video_capture = ogl_LOAD_FAILED;
int ogl_ext_OES_byte_coordinates = ogl_LOAD_FAILED;
int ogl_ext_OES_compressed_paletted_texture = ogl_LOAD_FAILED;
int ogl_ext_OES_fixed_point = ogl_LOAD_FAILED;
int ogl_ext_OES_query_matrix = ogl_LOAD_FAILED;
int ogl_ext_OES_read_format = ogl_LOAD_FAILED;
int ogl_ext_OES_single_precision = ogl_LOAD_FAILED;
int ogl_ext_OML_interlace = ogl_LOAD_FAILED;
int ogl_ext_OML_resample = ogl_LOAD_FAILED;
int ogl_ext_OML_subsample = ogl_LOAD_FAILED;
int ogl_ext_PGI_misc_hints = ogl_LOAD_FAILED;
int ogl_ext_PGI_vertex_hints = ogl_LOAD_FAILED;
int ogl_ext_REND_screen_coordinates = ogl_LOAD_FAILED;
int ogl_ext_S3_s3tc = ogl_LOAD_FAILED;
int ogl_ext_SGIS_detail_texture = ogl_LOAD_FAILED;
int ogl_ext_SGIS_fog_function = ogl_LOAD_FAILED;
int ogl_ext_SGIS_generate_mipmap = ogl_LOAD_FAILED;
int ogl_ext_SGIS_multisample = ogl_LOAD_FAILED;
int ogl_ext_SGIS_pixel_texture = ogl_LOAD_FAILED;
int ogl_ext_SGIS_point_line_texgen = ogl_LOAD_FAILED;
int ogl_ext_SGIS_point_parameters = ogl_LOAD_FAILED;
int ogl_ext_SGIS_sharpen_texture = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture4D = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture_border_clamp = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture_color_mask = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture_edge_clamp = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture_filter4 = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture_lod = ogl_LOAD_FAILED;
int ogl_ext_SGIS_texture_select = ogl_LOAD_FAILED;
int ogl_ext_SGIX_async = ogl_LOAD_FAILED;
int ogl_ext_SGIX_async_histogram = ogl_LOAD_FAILED;
int ogl_ext_SGIX_async_pixel = ogl_LOAD_FAILED;
int ogl_ext_SGIX_blend_alpha_minmax = ogl_LOAD_FAILED;
int ogl_ext_SGIX_calligraphic_fragment = ogl_LOAD_FAILED;
int ogl_ext_SGIX_clipmap = ogl_LOAD_FAILED;
int ogl_ext_SGIX_convolution_accuracy = ogl_LOAD_FAILED;
int ogl_ext_SGIX_depth_pass_instrument = ogl_LOAD_FAILED;
int ogl_ext_SGIX_depth_texture = ogl_LOAD_FAILED;
int ogl_ext_SGIX_flush_raster = ogl_LOAD_FAILED;
int ogl_ext_SGIX_fog_offset = ogl_LOAD_FAILED;
int ogl_ext_SGIX_fragment_lighting = ogl_LOAD_FAILED;
int ogl_ext_SGIX_framezoom = ogl_LOAD_FAILED;
int ogl_ext_SGIX_igloo_interface = ogl_LOAD_FAILED;
int ogl_ext_SGIX_instruments = ogl_LOAD_FAILED;
int ogl_ext_SGIX_interlace = ogl_LOAD_FAILED;
int ogl_ext_SGIX_ir_instrument1 = ogl_LOAD_FAILED;
int ogl_ext_SGIX_list_priority = ogl_LOAD_FAILED;
int ogl_ext_SGIX_pixel_texture = ogl_LOAD_FAILED;
int ogl_ext_SGIX_pixel_tiles = ogl_LOAD_FAILED;
int ogl_ext_SGIX_polynomial_ffd = ogl_LOAD_FAILED;
int ogl_ext_SGIX_reference_plane = ogl_LOAD_FAILED;
int ogl_ext_SGIX_resample = ogl_LOAD_FAILED;
int ogl_ext_SGIX_scalebias_hint = ogl_LOAD_FAILED;
int ogl_ext_SGIX_shadow = ogl_LOAD_FAILED;
int ogl_ext_SGIX_shadow_ambient = ogl_LOAD_FAILED;
int ogl_ext_SGIX_sprite = ogl_LOAD_FAILED;
int ogl_ext_SGIX_subsample = ogl_LOAD_FAILED;
int ogl_ext_SGIX_tag_sample_buffer = ogl_LOAD_FAILED;
int ogl_ext_SGIX_texture_add_env = ogl_LOAD_FAILED;
int ogl_ext_SGIX_texture_coordinate_clamp = ogl_LOAD_FAILED;
int ogl_ext_SGIX_texture_lod_bias = ogl_LOAD_FAILED;
int ogl_ext_SGIX_texture_multi_buffer = ogl_LOAD_FAILED;
int ogl_ext_SGIX_texture_scale_bias = ogl_LOAD_FAILED;
int ogl_ext_SGIX_vertex_preclip = ogl_LOAD_FAILED;
int ogl_ext_SGIX_ycrcb = ogl_LOAD_FAILED;
int ogl_ext_SGIX_ycrcb_subsample = ogl_LOAD_FAILED;
int ogl_ext_SGIX_ycrcba = ogl_LOAD_FAILED;
int ogl_ext_SGI_color_matrix = ogl_LOAD_FAILED;
int ogl_ext_SGI_color_table = ogl_LOAD_FAILED;
int ogl_ext_SGI_texture_color_table = ogl_LOAD_FAILED;
int ogl_ext_SUNX_constant_data = ogl_LOAD_FAILED;
int ogl_ext_SUN_convolution_border_modes = ogl_LOAD_FAILED;
int ogl_ext_SUN_global_alpha = ogl_LOAD_FAILED;
int ogl_ext_SUN_mesh_array = ogl_LOAD_FAILED;
int ogl_ext_SUN_slice_accum = ogl_LOAD_FAILED;
int ogl_ext_SUN_triangle_list = ogl_LOAD_FAILED;
int ogl_ext_SUN_vertex = ogl_LOAD_FAILED;
int ogl_ext_WIN_phong_shading = ogl_LOAD_FAILED;
int ogl_ext_WIN_specular_fog = ogl_LOAD_FAILED;

void (CODEGEN_FUNCPTR *_ptrc_glColorSubTable)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTable)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterfv)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameteriv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter1D)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter2D)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterf)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfv)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteri)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteriv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyColorSubTable)(GLenum, GLsizei, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyColorTable)(GLenum, GLenum, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter1D)(GLenum, GLenum, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter2D)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTable)(GLenum, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameteriv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionFilter)(GLenum, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameteriv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogram)(GLenum, GLboolean, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameteriv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmax)(GLenum, GLboolean, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameteriv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSeparableFilter)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glHistogram)(GLenum, GLsizei, GLenum, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMinmax)(GLenum, GLenum, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResetHistogram)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResetMinmax)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSeparableFilter2D)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *) = NULL;

static int Load_ARB_imaging()
{
	int numFailed = 0;
	_ptrc_glColorSubTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glColorSubTable");
	if(!_ptrc_glColorSubTable) numFailed++;
	_ptrc_glColorTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glColorTable");
	if(!_ptrc_glColorTable) numFailed++;
	_ptrc_glColorTableParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glColorTableParameterfv");
	if(!_ptrc_glColorTableParameterfv) numFailed++;
	_ptrc_glColorTableParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glColorTableParameteriv");
	if(!_ptrc_glColorTableParameteriv) numFailed++;
	_ptrc_glConvolutionFilter1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glConvolutionFilter1D");
	if(!_ptrc_glConvolutionFilter1D) numFailed++;
	_ptrc_glConvolutionFilter2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glConvolutionFilter2D");
	if(!_ptrc_glConvolutionFilter2D) numFailed++;
	_ptrc_glConvolutionParameterf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glConvolutionParameterf");
	if(!_ptrc_glConvolutionParameterf) numFailed++;
	_ptrc_glConvolutionParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glConvolutionParameterfv");
	if(!_ptrc_glConvolutionParameterfv) numFailed++;
	_ptrc_glConvolutionParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glConvolutionParameteri");
	if(!_ptrc_glConvolutionParameteri) numFailed++;
	_ptrc_glConvolutionParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glConvolutionParameteriv");
	if(!_ptrc_glConvolutionParameteriv) numFailed++;
	_ptrc_glCopyColorSubTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLint, GLint, GLsizei))IntGetProcAddress("glCopyColorSubTable");
	if(!_ptrc_glCopyColorSubTable) numFailed++;
	_ptrc_glCopyColorTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei))IntGetProcAddress("glCopyColorTable");
	if(!_ptrc_glCopyColorTable) numFailed++;
	_ptrc_glCopyConvolutionFilter1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei))IntGetProcAddress("glCopyConvolutionFilter1D");
	if(!_ptrc_glCopyConvolutionFilter1D) numFailed++;
	_ptrc_glCopyConvolutionFilter2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyConvolutionFilter2D");
	if(!_ptrc_glCopyConvolutionFilter2D) numFailed++;
	_ptrc_glGetColorTable = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetColorTable");
	if(!_ptrc_glGetColorTable) numFailed++;
	_ptrc_glGetColorTableParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetColorTableParameterfv");
	if(!_ptrc_glGetColorTableParameterfv) numFailed++;
	_ptrc_glGetColorTableParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetColorTableParameteriv");
	if(!_ptrc_glGetColorTableParameteriv) numFailed++;
	_ptrc_glGetConvolutionFilter = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetConvolutionFilter");
	if(!_ptrc_glGetConvolutionFilter) numFailed++;
	_ptrc_glGetConvolutionParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetConvolutionParameterfv");
	if(!_ptrc_glGetConvolutionParameterfv) numFailed++;
	_ptrc_glGetConvolutionParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetConvolutionParameteriv");
	if(!_ptrc_glGetConvolutionParameteriv) numFailed++;
	_ptrc_glGetHistogram = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetHistogram");
	if(!_ptrc_glGetHistogram) numFailed++;
	_ptrc_glGetHistogramParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetHistogramParameterfv");
	if(!_ptrc_glGetHistogramParameterfv) numFailed++;
	_ptrc_glGetHistogramParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetHistogramParameteriv");
	if(!_ptrc_glGetHistogramParameteriv) numFailed++;
	_ptrc_glGetMinmax = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetMinmax");
	if(!_ptrc_glGetMinmax) numFailed++;
	_ptrc_glGetMinmaxParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMinmaxParameterfv");
	if(!_ptrc_glGetMinmaxParameterfv) numFailed++;
	_ptrc_glGetMinmaxParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetMinmaxParameteriv");
	if(!_ptrc_glGetMinmaxParameteriv) numFailed++;
	_ptrc_glGetSeparableFilter = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *))IntGetProcAddress("glGetSeparableFilter");
	if(!_ptrc_glGetSeparableFilter) numFailed++;
	_ptrc_glHistogram = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLboolean))IntGetProcAddress("glHistogram");
	if(!_ptrc_glHistogram) numFailed++;
	_ptrc_glMinmax = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLboolean))IntGetProcAddress("glMinmax");
	if(!_ptrc_glMinmax) numFailed++;
	_ptrc_glResetHistogram = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glResetHistogram");
	if(!_ptrc_glResetHistogram) numFailed++;
	_ptrc_glResetMinmax = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glResetMinmax");
	if(!_ptrc_glResetMinmax) numFailed++;
	_ptrc_glSeparableFilter2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *))IntGetProcAddress("glSeparableFilter2D");
	if(!_ptrc_glSeparableFilter2D) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArray)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArrays)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArrays)(GLsizei, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArray)(GLuint) = NULL;

static int Load_ARB_vertex_array_object()
{
	int numFailed = 0;
	_ptrc_glBindVertexArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindVertexArray");
	if(!_ptrc_glBindVertexArray) numFailed++;
	_ptrc_glDeleteVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteVertexArrays");
	if(!_ptrc_glDeleteVertexArrays) numFailed++;
	_ptrc_glGenVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenVertexArrays");
	if(!_ptrc_glGenVertexArrays) numFailed++;
	_ptrc_glIsVertexArray = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsVertexArray");
	if(!_ptrc_glIsVertexArray) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRange)(GLenum, GLintptr, GLsizeiptr) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferRange)(GLenum, GLintptr, GLsizeiptr, GLbitfield) = NULL;

static int Load_ARB_map_buffer_range()
{
	int numFailed = 0;
	_ptrc_glFlushMappedBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedBufferRange");
	if(!_ptrc_glFlushMappedBufferRange) numFailed++;
	_ptrc_glMapBufferRange = (void * (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapBufferRange");
	if(!_ptrc_glMapBufferRange) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFramebuffer)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbuffer)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebuffer)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatus)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffers)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffers)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1D)(GLenum, GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3D)(GLenum, GLenum, GLenum, GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayer)(GLenum, GLenum, GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffers)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffers)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmap)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameteriv)(GLenum, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebuffer)(GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbuffer)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei) = NULL;

static int Load_ARB_framebuffer_object()
{
	int numFailed = 0;
	_ptrc_glBindFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindFramebuffer");
	if(!_ptrc_glBindFramebuffer) numFailed++;
	_ptrc_glBindRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindRenderbuffer");
	if(!_ptrc_glBindRenderbuffer) numFailed++;
	_ptrc_glBlitFramebuffer = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitFramebuffer");
	if(!_ptrc_glBlitFramebuffer) numFailed++;
	_ptrc_glCheckFramebufferStatus = (GLenum (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCheckFramebufferStatus");
	if(!_ptrc_glCheckFramebufferStatus) numFailed++;
	_ptrc_glDeleteFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFramebuffers");
	if(!_ptrc_glDeleteFramebuffers) numFailed++;
	_ptrc_glDeleteRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteRenderbuffers");
	if(!_ptrc_glDeleteRenderbuffers) numFailed++;
	_ptrc_glFramebufferRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glFramebufferRenderbuffer");
	if(!_ptrc_glFramebufferRenderbuffer) numFailed++;
	_ptrc_glFramebufferTexture1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture1D");
	if(!_ptrc_glFramebufferTexture1D) numFailed++;
	_ptrc_glFramebufferTexture2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture2D");
	if(!_ptrc_glFramebufferTexture2D) numFailed++;
	_ptrc_glFramebufferTexture3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTexture3D");
	if(!_ptrc_glFramebufferTexture3D) numFailed++;
	_ptrc_glFramebufferTextureLayer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayer");
	if(!_ptrc_glFramebufferTextureLayer) numFailed++;
	_ptrc_glGenFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFramebuffers");
	if(!_ptrc_glGenFramebuffers) numFailed++;
	_ptrc_glGenRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenRenderbuffers");
	if(!_ptrc_glGenRenderbuffers) numFailed++;
	_ptrc_glGenerateMipmap = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGenerateMipmap");
	if(!_ptrc_glGenerateMipmap) numFailed++;
	_ptrc_glGetFramebufferAttachmentParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!_ptrc_glGetFramebufferAttachmentParameteriv) numFailed++;
	_ptrc_glGetRenderbufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetRenderbufferParameteriv");
	if(!_ptrc_glGetRenderbufferParameteriv) numFailed++;
	_ptrc_glIsFramebuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFramebuffer");
	if(!_ptrc_glIsFramebuffer) numFailed++;
	_ptrc_glIsRenderbuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsRenderbuffer");
	if(!_ptrc_glIsRenderbuffer) numFailed++;
	_ptrc_glRenderbufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorage");
	if(!_ptrc_glRenderbufferStorage) numFailed++;
	_ptrc_glRenderbufferStorageMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisample");
	if(!_ptrc_glRenderbufferStorageMultisample) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformBlockiv)(GLuint, GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformsiv)(GLuint, GLsizei, const GLuint *, GLenum, GLint *) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBlockIndex)(GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformIndices)(GLuint, GLsizei, const GLchar *const*, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformBlockBinding)(GLuint, GLuint, GLuint) = NULL;

static int Load_ARB_uniform_buffer_object()
{
	int numFailed = 0;
	_ptrc_glGetActiveUniformBlockName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformBlockName");
	if(!_ptrc_glGetActiveUniformBlockName) numFailed++;
	_ptrc_glGetActiveUniformBlockiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformBlockiv");
	if(!_ptrc_glGetActiveUniformBlockiv) numFailed++;
	_ptrc_glGetActiveUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformName");
	if(!_ptrc_glGetActiveUniformName) numFailed++;
	_ptrc_glGetActiveUniformsiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformsiv");
	if(!_ptrc_glGetActiveUniformsiv) numFailed++;
	_ptrc_glGetUniformBlockIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetUniformBlockIndex");
	if(!_ptrc_glGetUniformBlockIndex) numFailed++;
	_ptrc_glGetUniformIndices = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, GLuint *))IntGetProcAddress("glGetUniformIndices");
	if(!_ptrc_glGetUniformIndices) numFailed++;
	_ptrc_glUniformBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glUniformBlockBinding");
	if(!_ptrc_glUniformBlockBinding) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyBufferSubData)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr) = NULL;

static int Load_ARB_copy_buffer()
{
	int numFailed = 0;
	_ptrc_glCopyBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glCopyBufferSubData");
	if(!_ptrc_glCopyBufferSubData) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertex)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsBaseVertex)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsBaseVertex)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, const GLint *) = NULL;

static int Load_ARB_draw_elements_base_vertex()
{
	int numFailed = 0;
	_ptrc_glDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLint))IntGetProcAddress("glDrawElementsBaseVertex");
	if(!_ptrc_glDrawElementsBaseVertex) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint))IntGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!_ptrc_glDrawElementsInstancedBaseVertex) numFailed++;
	_ptrc_glDrawRangeElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint))IntGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!_ptrc_glDrawRangeElementsBaseVertex) numFailed++;
	_ptrc_glMultiDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, const GLint *))IntGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!_ptrc_glMultiDrawElementsBaseVertex) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertex)(GLenum) = NULL;

static int Load_ARB_provoking_vertex()
{
	int numFailed = 0;
	_ptrc_glProvokingVertex = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glProvokingVertex");
	if(!_ptrc_glProvokingVertex) numFailed++;
	return numFailed;
}

GLenum (CODEGEN_FUNCPTR *_ptrc_glClientWaitSync)(GLsync, GLbitfield, GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteSync)(GLsync) = NULL;
GLsync (CODEGEN_FUNCPTR *_ptrc_glFenceSync)(GLenum, GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64v)(GLenum, GLint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSynciv)(GLsync, GLenum, GLsizei, GLsizei *, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSync)(GLsync) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWaitSync)(GLsync, GLbitfield, GLuint64) = NULL;

static int Load_ARB_sync()
{
	int numFailed = 0;
	_ptrc_glClientWaitSync = (GLenum (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glClientWaitSync");
	if(!_ptrc_glClientWaitSync) numFailed++;
	_ptrc_glDeleteSync = (void (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glDeleteSync");
	if(!_ptrc_glDeleteSync) numFailed++;
	_ptrc_glFenceSync = (GLsync (CODEGEN_FUNCPTR *)(GLenum, GLbitfield))IntGetProcAddress("glFenceSync");
	if(!_ptrc_glFenceSync) numFailed++;
	_ptrc_glGetInteger64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLint64 *))IntGetProcAddress("glGetInteger64v");
	if(!_ptrc_glGetInteger64v) numFailed++;
	_ptrc_glGetSynciv = (void (CODEGEN_FUNCPTR *)(GLsync, GLenum, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetSynciv");
	if(!_ptrc_glGetSynciv) numFailed++;
	_ptrc_glIsSync = (GLboolean (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glIsSync");
	if(!_ptrc_glIsSync) numFailed++;
	_ptrc_glWaitSync = (void (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glWaitSync");
	if(!_ptrc_glWaitSync) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefv)(GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleMaski)(GLuint, GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisample)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisample)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;

static int Load_ARB_texture_multisample()
{
	int numFailed = 0;
	_ptrc_glGetMultisamplefv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetMultisamplefv");
	if(!_ptrc_glGetMultisamplefv) numFailed++;
	_ptrc_glSampleMaski = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield))IntGetProcAddress("glSampleMaski");
	if(!_ptrc_glSampleMaski) numFailed++;
	_ptrc_glTexImage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage2DMultisample");
	if(!_ptrc_glTexImage2DMultisample) numFailed++;
	_ptrc_glTexImage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage3DMultisample");
	if(!_ptrc_glTexImage3DMultisample) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64v)(GLuint, GLenum, GLint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64v)(GLuint, GLenum, GLuint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glQueryCounter)(GLuint, GLenum) = NULL;

static int Load_ARB_timer_query()
{
	int numFailed = 0;
	_ptrc_glGetQueryObjecti64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetQueryObjecti64v");
	if(!_ptrc_glGetQueryObjecti64v) numFailed++;
	_ptrc_glGetQueryObjectui64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64 *))IntGetProcAddress("glGetQueryObjectui64v");
	if(!_ptrc_glGetQueryObjectui64v) numFailed++;
	_ptrc_glQueryCounter = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glQueryCounter");
	if(!_ptrc_glQueryCounter) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorP3ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorP3uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorP4ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorP4uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1ui)(GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP1uiv)(GLenum, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2ui)(GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP2uiv)(GLenum, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3ui)(GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP3uiv)(GLenum, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4ui)(GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordP4uiv)(GLenum, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalP3ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalP3uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorP3uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP1uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP2uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP3uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordP4uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1ui)(GLuint, GLenum, GLboolean, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP1uiv)(GLuint, GLenum, GLboolean, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2ui)(GLuint, GLenum, GLboolean, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP2uiv)(GLuint, GLenum, GLboolean, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3ui)(GLuint, GLenum, GLboolean, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP3uiv)(GLuint, GLenum, GLboolean, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4ui)(GLuint, GLenum, GLboolean, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribP4uiv)(GLuint, GLenum, GLboolean, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP2ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP2uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP3ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP3uiv)(GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP4ui)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexP4uiv)(GLenum, const GLuint *) = NULL;

static int Load_ARB_vertex_type_2_10_10_10_rev()
{
	int numFailed = 0;
	_ptrc_glColorP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glColorP3ui");
	if(!_ptrc_glColorP3ui) numFailed++;
	_ptrc_glColorP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glColorP3uiv");
	if(!_ptrc_glColorP3uiv) numFailed++;
	_ptrc_glColorP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glColorP4ui");
	if(!_ptrc_glColorP4ui) numFailed++;
	_ptrc_glColorP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glColorP4uiv");
	if(!_ptrc_glColorP4uiv) numFailed++;
	_ptrc_glMultiTexCoordP1ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP1ui");
	if(!_ptrc_glMultiTexCoordP1ui) numFailed++;
	_ptrc_glMultiTexCoordP1uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP1uiv");
	if(!_ptrc_glMultiTexCoordP1uiv) numFailed++;
	_ptrc_glMultiTexCoordP2ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP2ui");
	if(!_ptrc_glMultiTexCoordP2ui) numFailed++;
	_ptrc_glMultiTexCoordP2uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP2uiv");
	if(!_ptrc_glMultiTexCoordP2uiv) numFailed++;
	_ptrc_glMultiTexCoordP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP3ui");
	if(!_ptrc_glMultiTexCoordP3ui) numFailed++;
	_ptrc_glMultiTexCoordP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP3uiv");
	if(!_ptrc_glMultiTexCoordP3uiv) numFailed++;
	_ptrc_glMultiTexCoordP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexCoordP4ui");
	if(!_ptrc_glMultiTexCoordP4ui) numFailed++;
	_ptrc_glMultiTexCoordP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexCoordP4uiv");
	if(!_ptrc_glMultiTexCoordP4uiv) numFailed++;
	_ptrc_glNormalP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glNormalP3ui");
	if(!_ptrc_glNormalP3ui) numFailed++;
	_ptrc_glNormalP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glNormalP3uiv");
	if(!_ptrc_glNormalP3uiv) numFailed++;
	_ptrc_glSecondaryColorP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glSecondaryColorP3ui");
	if(!_ptrc_glSecondaryColorP3ui) numFailed++;
	_ptrc_glSecondaryColorP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glSecondaryColorP3uiv");
	if(!_ptrc_glSecondaryColorP3uiv) numFailed++;
	_ptrc_glTexCoordP1ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP1ui");
	if(!_ptrc_glTexCoordP1ui) numFailed++;
	_ptrc_glTexCoordP1uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP1uiv");
	if(!_ptrc_glTexCoordP1uiv) numFailed++;
	_ptrc_glTexCoordP2ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP2ui");
	if(!_ptrc_glTexCoordP2ui) numFailed++;
	_ptrc_glTexCoordP2uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP2uiv");
	if(!_ptrc_glTexCoordP2uiv) numFailed++;
	_ptrc_glTexCoordP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP3ui");
	if(!_ptrc_glTexCoordP3ui) numFailed++;
	_ptrc_glTexCoordP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP3uiv");
	if(!_ptrc_glTexCoordP3uiv) numFailed++;
	_ptrc_glTexCoordP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexCoordP4ui");
	if(!_ptrc_glTexCoordP4ui) numFailed++;
	_ptrc_glTexCoordP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glTexCoordP4uiv");
	if(!_ptrc_glTexCoordP4uiv) numFailed++;
	_ptrc_glVertexAttribP1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP1ui");
	if(!_ptrc_glVertexAttribP1ui) numFailed++;
	_ptrc_glVertexAttribP1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP1uiv");
	if(!_ptrc_glVertexAttribP1uiv) numFailed++;
	_ptrc_glVertexAttribP2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP2ui");
	if(!_ptrc_glVertexAttribP2ui) numFailed++;
	_ptrc_glVertexAttribP2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP2uiv");
	if(!_ptrc_glVertexAttribP2uiv) numFailed++;
	_ptrc_glVertexAttribP3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP3ui");
	if(!_ptrc_glVertexAttribP3ui) numFailed++;
	_ptrc_glVertexAttribP3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP3uiv");
	if(!_ptrc_glVertexAttribP3uiv) numFailed++;
	_ptrc_glVertexAttribP4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP4ui");
	if(!_ptrc_glVertexAttribP4ui) numFailed++;
	_ptrc_glVertexAttribP4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP4uiv");
	if(!_ptrc_glVertexAttribP4uiv) numFailed++;
	_ptrc_glVertexP2ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glVertexP2ui");
	if(!_ptrc_glVertexP2ui) numFailed++;
	_ptrc_glVertexP2uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glVertexP2uiv");
	if(!_ptrc_glVertexP2uiv) numFailed++;
	_ptrc_glVertexP3ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glVertexP3ui");
	if(!_ptrc_glVertexP3ui) numFailed++;
	_ptrc_glVertexP3uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glVertexP3uiv");
	if(!_ptrc_glVertexP3uiv) numFailed++;
	_ptrc_glVertexP4ui = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glVertexP4ui");
	if(!_ptrc_glVertexP4ui) numFailed++;
	_ptrc_glVertexP4uiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLuint *))IntGetProcAddress("glVertexP4uiv");
	if(!_ptrc_glVertexP4uiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationIndexed)(GLuint, GLuint, GLuint, const GLchar *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataIndex)(GLuint, const GLchar *) = NULL;

static int Load_ARB_blend_func_extended()
{
	int numFailed = 0;
	_ptrc_glBindFragDataLocationIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocationIndexed");
	if(!_ptrc_glBindFragDataLocationIndexed) numFailed++;
	_ptrc_glGetFragDataIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataIndex");
	if(!_ptrc_glGetFragDataIndex) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindSampler)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteSamplers)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenSamplers)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIiv)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterIuiv)(GLuint, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameterfv)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSamplerParameteriv)(GLuint, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsSampler)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIiv)(GLuint, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterIuiv)(GLuint, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterf)(GLuint, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameterfv)(GLuint, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteri)(GLuint, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplerParameteriv)(GLuint, GLenum, const GLint *) = NULL;

static int Load_ARB_sampler_objects()
{
	int numFailed = 0;
	_ptrc_glBindSampler = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glBindSampler");
	if(!_ptrc_glBindSampler) numFailed++;
	_ptrc_glDeleteSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteSamplers");
	if(!_ptrc_glDeleteSamplers) numFailed++;
	_ptrc_glGenSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenSamplers");
	if(!_ptrc_glGenSamplers) numFailed++;
	_ptrc_glGetSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameterIiv");
	if(!_ptrc_glGetSamplerParameterIiv) numFailed++;
	_ptrc_glGetSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetSamplerParameterIuiv");
	if(!_ptrc_glGetSamplerParameterIuiv) numFailed++;
	_ptrc_glGetSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetSamplerParameterfv");
	if(!_ptrc_glGetSamplerParameterfv) numFailed++;
	_ptrc_glGetSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameteriv");
	if(!_ptrc_glGetSamplerParameteriv) numFailed++;
	_ptrc_glIsSampler = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsSampler");
	if(!_ptrc_glIsSampler) numFailed++;
	_ptrc_glSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameterIiv");
	if(!_ptrc_glSamplerParameterIiv) numFailed++;
	_ptrc_glSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLuint *))IntGetProcAddress("glSamplerParameterIuiv");
	if(!_ptrc_glSamplerParameterIuiv) numFailed++;
	_ptrc_glSamplerParameterf = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glSamplerParameterf");
	if(!_ptrc_glSamplerParameterf) numFailed++;
	_ptrc_glSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glSamplerParameterfv");
	if(!_ptrc_glSamplerParameterfv) numFailed++;
	_ptrc_glSamplerParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glSamplerParameteri");
	if(!_ptrc_glSamplerParameteri) numFailed++;
	_ptrc_glSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameteriv");
	if(!_ptrc_glSamplerParameteriv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysIndirect)(GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsIndirect)(GLenum, GLenum, const GLvoid *) = NULL;

static int Load_ARB_draw_indirect()
{
	int numFailed = 0;
	_ptrc_glDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid *))IntGetProcAddress("glDrawArraysIndirect");
	if(!_ptrc_glDrawArraysIndirect) numFailed++;
	_ptrc_glDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLvoid *))IntGetProcAddress("glDrawElementsIndirect");
	if(!_ptrc_glDrawElementsIndirect) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetUniformdv)(GLuint, GLint, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1d)(GLint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1dv)(GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2d)(GLint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2dv)(GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3d)(GLint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3dv)(GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4d)(GLint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4dv)(GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3dv)(GLint, GLsizei, GLboolean, const GLdouble *) = NULL;

static int Load_ARB_gpu_shader_fp64()
{
	int numFailed = 0;
	_ptrc_glGetUniformdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble *))IntGetProcAddress("glGetUniformdv");
	if(!_ptrc_glGetUniformdv) numFailed++;
	_ptrc_glUniform1d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble))IntGetProcAddress("glUniform1d");
	if(!_ptrc_glUniform1d) numFailed++;
	_ptrc_glUniform1dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform1dv");
	if(!_ptrc_glUniform1dv) numFailed++;
	_ptrc_glUniform2d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble))IntGetProcAddress("glUniform2d");
	if(!_ptrc_glUniform2d) numFailed++;
	_ptrc_glUniform2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform2dv");
	if(!_ptrc_glUniform2dv) numFailed++;
	_ptrc_glUniform3d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform3d");
	if(!_ptrc_glUniform3d) numFailed++;
	_ptrc_glUniform3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform3dv");
	if(!_ptrc_glUniform3dv) numFailed++;
	_ptrc_glUniform4d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform4d");
	if(!_ptrc_glUniform4d) numFailed++;
	_ptrc_glUniform4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform4dv");
	if(!_ptrc_glUniform4dv) numFailed++;
	_ptrc_glUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2dv");
	if(!_ptrc_glUniformMatrix2dv) numFailed++;
	_ptrc_glUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x3dv");
	if(!_ptrc_glUniformMatrix2x3dv) numFailed++;
	_ptrc_glUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x4dv");
	if(!_ptrc_glUniformMatrix2x4dv) numFailed++;
	_ptrc_glUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3dv");
	if(!_ptrc_glUniformMatrix3dv) numFailed++;
	_ptrc_glUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x2dv");
	if(!_ptrc_glUniformMatrix3x2dv) numFailed++;
	_ptrc_glUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x4dv");
	if(!_ptrc_glUniformMatrix3x4dv) numFailed++;
	_ptrc_glUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4dv");
	if(!_ptrc_glUniformMatrix4dv) numFailed++;
	_ptrc_glUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x2dv");
	if(!_ptrc_glUniformMatrix4x2dv) numFailed++;
	_ptrc_glUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x3dv");
	if(!_ptrc_glUniformMatrix4x3dv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveSubroutineUniformiv)(GLuint, GLenum, GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStageiv)(GLuint, GLenum, GLenum, GLint *) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineIndex)(GLuint, GLenum, const GLchar *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetSubroutineUniformLocation)(GLuint, GLenum, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformSubroutineuiv)(GLenum, GLint, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformSubroutinesuiv)(GLenum, GLsizei, const GLuint *) = NULL;

static int Load_ARB_shader_subroutine()
{
	int numFailed = 0;
	_ptrc_glGetActiveSubroutineName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineName");
	if(!_ptrc_glGetActiveSubroutineName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineUniformName");
	if(!_ptrc_glGetActiveSubroutineUniformName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveSubroutineUniformiv");
	if(!_ptrc_glGetActiveSubroutineUniformiv) numFailed++;
	_ptrc_glGetProgramStageiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramStageiv");
	if(!_ptrc_glGetProgramStageiv) numFailed++;
	_ptrc_glGetSubroutineIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineIndex");
	if(!_ptrc_glGetSubroutineIndex) numFailed++;
	_ptrc_glGetSubroutineUniformLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineUniformLocation");
	if(!_ptrc_glGetSubroutineUniformLocation) numFailed++;
	_ptrc_glGetUniformSubroutineuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint *))IntGetProcAddress("glGetUniformSubroutineuiv");
	if(!_ptrc_glGetUniformSubroutineuiv) numFailed++;
	_ptrc_glUniformSubroutinesuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLuint *))IntGetProcAddress("glUniformSubroutinesuiv");
	if(!_ptrc_glUniformSubroutinesuiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPatchParameterfv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPatchParameteri)(GLenum, GLint) = NULL;

static int Load_ARB_tessellation_shader()
{
	int numFailed = 0;
	_ptrc_glPatchParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPatchParameterfv");
	if(!_ptrc_glPatchParameterfv) numFailed++;
	_ptrc_glPatchParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPatchParameteri");
	if(!_ptrc_glPatchParameteri) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedback)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacks)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedback)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacks)(GLsizei, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedback)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedback)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedback)() = NULL;

static int Load_ARB_transform_feedback2()
{
	int numFailed = 0;
	_ptrc_glBindTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTransformFeedback");
	if(!_ptrc_glBindTransformFeedback) numFailed++;
	_ptrc_glDeleteTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTransformFeedbacks");
	if(!_ptrc_glDeleteTransformFeedbacks) numFailed++;
	_ptrc_glDrawTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDrawTransformFeedback");
	if(!_ptrc_glDrawTransformFeedback) numFailed++;
	_ptrc_glGenTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTransformFeedbacks");
	if(!_ptrc_glGenTransformFeedbacks) numFailed++;
	_ptrc_glIsTransformFeedback = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTransformFeedback");
	if(!_ptrc_glIsTransformFeedback) numFailed++;
	_ptrc_glPauseTransformFeedback = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPauseTransformFeedback");
	if(!_ptrc_glPauseTransformFeedback) numFailed++;
	_ptrc_glResumeTransformFeedback = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glResumeTransformFeedback");
	if(!_ptrc_glResumeTransformFeedback) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryIndexed)(GLenum, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStream)(GLenum, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndQueryIndexed)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryIndexediv)(GLenum, GLuint, GLenum, GLint *) = NULL;

static int Load_ARB_transform_feedback3()
{
	int numFailed = 0;
	_ptrc_glBeginQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBeginQueryIndexed");
	if(!_ptrc_glBeginQueryIndexed) numFailed++;
	_ptrc_glDrawTransformFeedbackStream = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glDrawTransformFeedbackStream");
	if(!_ptrc_glDrawTransformFeedbackStream) numFailed++;
	_ptrc_glEndQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEndQueryIndexed");
	if(!_ptrc_glEndQueryIndexed) numFailed++;
	_ptrc_glGetQueryIndexediv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryIndexediv");
	if(!_ptrc_glGetQueryIndexediv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearDepthf)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangef)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderPrecisionFormat)(GLenum, GLenum, GLint *, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReleaseShaderCompiler)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderBinary)(GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei) = NULL;

static int Load_ARB_ES2_compatibility()
{
	int numFailed = 0;
	_ptrc_glClearDepthf = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glClearDepthf");
	if(!_ptrc_glClearDepthf) numFailed++;
	_ptrc_glDepthRangef = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glDepthRangef");
	if(!_ptrc_glDepthRangef) numFailed++;
	_ptrc_glGetShaderPrecisionFormat = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *, GLint *))IntGetProcAddress("glGetShaderPrecisionFormat");
	if(!_ptrc_glGetShaderPrecisionFormat) numFailed++;
	_ptrc_glReleaseShaderCompiler = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glReleaseShaderCompiler");
	if(!_ptrc_glReleaseShaderCompiler) numFailed++;
	_ptrc_glShaderBinary = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei))IntGetProcAddress("glShaderBinary");
	if(!_ptrc_glShaderBinary) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramBinary)(GLuint, GLsizei, GLsizei *, GLenum *, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramBinary)(GLuint, GLenum, const GLvoid *, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteri)(GLuint, GLenum, GLint) = NULL;

static int Load_ARB_get_program_binary()
{
	int numFailed = 0;
	_ptrc_glGetProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLenum *, GLvoid *))IntGetProcAddress("glGetProgramBinary");
	if(!_ptrc_glGetProgramBinary) numFailed++;
	_ptrc_glProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLvoid *, GLsizei))IntGetProcAddress("glProgramBinary");
	if(!_ptrc_glProgramBinary) numFailed++;
	_ptrc_glProgramParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteri");
	if(!_ptrc_glProgramParameteri) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveShaderProgram)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindProgramPipeline)(GLuint) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramv)(GLenum, GLsizei, const GLchar *const*) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramPipelines)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenProgramPipelines)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramPipelineiv)(GLuint, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramPipeline)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1d)(GLuint, GLint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dv)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1f)(GLuint, GLint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fv)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i)(GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iv)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui)(GLuint, GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiv)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2d)(GLuint, GLint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dv)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2f)(GLuint, GLint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fv)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i)(GLuint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iv)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui)(GLuint, GLint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiv)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3d)(GLuint, GLint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dv)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3f)(GLuint, GLint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fv)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i)(GLuint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iv)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui)(GLuint, GLint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiv)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4d)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dv)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4f)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fv)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i)(GLuint, GLint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iv)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiv)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dv)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fv)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseProgramStages)(GLuint, GLbitfield, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramPipeline)(GLuint) = NULL;

static int Load_ARB_separate_shader_objects()
{
	int numFailed = 0;
	_ptrc_glActiveShaderProgram = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glActiveShaderProgram");
	if(!_ptrc_glActiveShaderProgram) numFailed++;
	_ptrc_glBindProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindProgramPipeline");
	if(!_ptrc_glBindProgramPipeline) numFailed++;
	_ptrc_glCreateShaderProgramv = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLchar *const*))IntGetProcAddress("glCreateShaderProgramv");
	if(!_ptrc_glCreateShaderProgramv) numFailed++;
	_ptrc_glDeleteProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramPipelines");
	if(!_ptrc_glDeleteProgramPipelines) numFailed++;
	_ptrc_glGenProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramPipelines");
	if(!_ptrc_glGenProgramPipelines) numFailed++;
	_ptrc_glGetProgramPipelineInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramPipelineInfoLog");
	if(!_ptrc_glGetProgramPipelineInfoLog) numFailed++;
	_ptrc_glGetProgramPipelineiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramPipelineiv");
	if(!_ptrc_glGetProgramPipelineiv) numFailed++;
	_ptrc_glIsProgramPipeline = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramPipeline");
	if(!_ptrc_glIsProgramPipeline) numFailed++;
	_ptrc_glProgramUniform1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble))IntGetProcAddress("glProgramUniform1d");
	if(!_ptrc_glProgramUniform1d) numFailed++;
	_ptrc_glProgramUniform1dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform1dv");
	if(!_ptrc_glProgramUniform1dv) numFailed++;
	_ptrc_glProgramUniform1f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat))IntGetProcAddress("glProgramUniform1f");
	if(!_ptrc_glProgramUniform1f) numFailed++;
	_ptrc_glProgramUniform1fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform1fv");
	if(!_ptrc_glProgramUniform1fv) numFailed++;
	_ptrc_glProgramUniform1i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glProgramUniform1i");
	if(!_ptrc_glProgramUniform1i) numFailed++;
	_ptrc_glProgramUniform1iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform1iv");
	if(!_ptrc_glProgramUniform1iv) numFailed++;
	_ptrc_glProgramUniform1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glProgramUniform1ui");
	if(!_ptrc_glProgramUniform1ui) numFailed++;
	_ptrc_glProgramUniform1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform1uiv");
	if(!_ptrc_glProgramUniform1uiv) numFailed++;
	_ptrc_glProgramUniform2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform2d");
	if(!_ptrc_glProgramUniform2d) numFailed++;
	_ptrc_glProgramUniform2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform2dv");
	if(!_ptrc_glProgramUniform2dv) numFailed++;
	_ptrc_glProgramUniform2f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform2f");
	if(!_ptrc_glProgramUniform2f) numFailed++;
	_ptrc_glProgramUniform2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform2fv");
	if(!_ptrc_glProgramUniform2fv) numFailed++;
	_ptrc_glProgramUniform2i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform2i");
	if(!_ptrc_glProgramUniform2i) numFailed++;
	_ptrc_glProgramUniform2iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform2iv");
	if(!_ptrc_glProgramUniform2iv) numFailed++;
	_ptrc_glProgramUniform2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint))IntGetProcAddress("glProgramUniform2ui");
	if(!_ptrc_glProgramUniform2ui) numFailed++;
	_ptrc_glProgramUniform2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform2uiv");
	if(!_ptrc_glProgramUniform2uiv) numFailed++;
	_ptrc_glProgramUniform3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform3d");
	if(!_ptrc_glProgramUniform3d) numFailed++;
	_ptrc_glProgramUniform3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform3dv");
	if(!_ptrc_glProgramUniform3dv) numFailed++;
	_ptrc_glProgramUniform3f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform3f");
	if(!_ptrc_glProgramUniform3f) numFailed++;
	_ptrc_glProgramUniform3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform3fv");
	if(!_ptrc_glProgramUniform3fv) numFailed++;
	_ptrc_glProgramUniform3i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform3i");
	if(!_ptrc_glProgramUniform3i) numFailed++;
	_ptrc_glProgramUniform3iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform3iv");
	if(!_ptrc_glProgramUniform3iv) numFailed++;
	_ptrc_glProgramUniform3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform3ui");
	if(!_ptrc_glProgramUniform3ui) numFailed++;
	_ptrc_glProgramUniform3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform3uiv");
	if(!_ptrc_glProgramUniform3uiv) numFailed++;
	_ptrc_glProgramUniform4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform4d");
	if(!_ptrc_glProgramUniform4d) numFailed++;
	_ptrc_glProgramUniform4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform4dv");
	if(!_ptrc_glProgramUniform4dv) numFailed++;
	_ptrc_glProgramUniform4f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform4f");
	if(!_ptrc_glProgramUniform4f) numFailed++;
	_ptrc_glProgramUniform4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform4fv");
	if(!_ptrc_glProgramUniform4fv) numFailed++;
	_ptrc_glProgramUniform4i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform4i");
	if(!_ptrc_glProgramUniform4i) numFailed++;
	_ptrc_glProgramUniform4iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform4iv");
	if(!_ptrc_glProgramUniform4iv) numFailed++;
	_ptrc_glProgramUniform4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform4ui");
	if(!_ptrc_glProgramUniform4ui) numFailed++;
	_ptrc_glProgramUniform4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform4uiv");
	if(!_ptrc_glProgramUniform4uiv) numFailed++;
	_ptrc_glProgramUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2dv");
	if(!_ptrc_glProgramUniformMatrix2dv) numFailed++;
	_ptrc_glProgramUniformMatrix2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2fv");
	if(!_ptrc_glProgramUniformMatrix2fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x3dv");
	if(!_ptrc_glProgramUniformMatrix2x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x3fv");
	if(!_ptrc_glProgramUniformMatrix2x3fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x4dv");
	if(!_ptrc_glProgramUniformMatrix2x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x4fv");
	if(!_ptrc_glProgramUniformMatrix2x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3dv");
	if(!_ptrc_glProgramUniformMatrix3dv) numFailed++;
	_ptrc_glProgramUniformMatrix3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3fv");
	if(!_ptrc_glProgramUniformMatrix3fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x2dv");
	if(!_ptrc_glProgramUniformMatrix3x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x2fv");
	if(!_ptrc_glProgramUniformMatrix3x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x4dv");
	if(!_ptrc_glProgramUniformMatrix3x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x4fv");
	if(!_ptrc_glProgramUniformMatrix3x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4dv");
	if(!_ptrc_glProgramUniformMatrix4dv) numFailed++;
	_ptrc_glProgramUniformMatrix4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4fv");
	if(!_ptrc_glProgramUniformMatrix4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x2dv");
	if(!_ptrc_glProgramUniformMatrix4x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x2fv");
	if(!_ptrc_glProgramUniformMatrix4x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x3dv");
	if(!_ptrc_glProgramUniformMatrix4x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x3fv");
	if(!_ptrc_glProgramUniformMatrix4x3fv) numFailed++;
	_ptrc_glUseProgramStages = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield, GLuint))IntGetProcAddress("glUseProgramStages");
	if(!_ptrc_glUseProgramStages) numFailed++;
	_ptrc_glValidateProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glValidateProgramPipeline");
	if(!_ptrc_glValidateProgramPipeline) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdv)(GLuint, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1d)(GLuint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2d)(GLuint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3d)(GLuint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointer)(GLuint, GLint, GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_ARB_vertex_attrib_64bit()
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribLdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribLdv");
	if(!_ptrc_glGetVertexAttribLdv) numFailed++;
	_ptrc_glVertexAttribL1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttribL1d");
	if(!_ptrc_glVertexAttribL1d) numFailed++;
	_ptrc_glVertexAttribL1dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL1dv");
	if(!_ptrc_glVertexAttribL1dv) numFailed++;
	_ptrc_glVertexAttribL2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL2d");
	if(!_ptrc_glVertexAttribL2d) numFailed++;
	_ptrc_glVertexAttribL2dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL2dv");
	if(!_ptrc_glVertexAttribL2dv) numFailed++;
	_ptrc_glVertexAttribL3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL3d");
	if(!_ptrc_glVertexAttribL3d) numFailed++;
	_ptrc_glVertexAttribL3dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL3dv");
	if(!_ptrc_glVertexAttribL3dv) numFailed++;
	_ptrc_glVertexAttribL4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL4d");
	if(!_ptrc_glVertexAttribL4d) numFailed++;
	_ptrc_glVertexAttribL4dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL4dv");
	if(!_ptrc_glVertexAttribL4dv) numFailed++;
	_ptrc_glVertexAttribLPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribLPointer");
	if(!_ptrc_glVertexAttribLPointer) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeArrayv)(GLuint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangeIndexed)(GLuint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_v)(GLenum, GLuint, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_v)(GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissorArrayv)(GLuint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexed)(GLuint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissorIndexedv)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewportArrayv)(GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedf)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewportIndexedfv)(GLuint, const GLfloat *) = NULL;

static int Load_ARB_viewport_array()
{
	int numFailed = 0;
	_ptrc_glDepthRangeArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glDepthRangeArrayv");
	if(!_ptrc_glDepthRangeArrayv) numFailed++;
	_ptrc_glDepthRangeIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glDepthRangeIndexed");
	if(!_ptrc_glDepthRangeIndexed) numFailed++;
	_ptrc_glGetDoublei_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoublei_v");
	if(!_ptrc_glGetDoublei_v) numFailed++;
	_ptrc_glGetFloati_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloati_v");
	if(!_ptrc_glGetFloati_v) numFailed++;
	_ptrc_glScissorArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLint *))IntGetProcAddress("glScissorArrayv");
	if(!_ptrc_glScissorArrayv) numFailed++;
	_ptrc_glScissorIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glScissorIndexed");
	if(!_ptrc_glScissorIndexed) numFailed++;
	_ptrc_glScissorIndexedv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glScissorIndexedv");
	if(!_ptrc_glScissorIndexedv) numFailed++;
	_ptrc_glViewportArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glViewportArrayv");
	if(!_ptrc_glViewportArrayv) numFailed++;
	_ptrc_glViewportIndexedf = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glViewportIndexedf");
	if(!_ptrc_glViewportIndexedf) numFailed++;
	_ptrc_glViewportIndexedfv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glViewportIndexedfv");
	if(!_ptrc_glViewportIndexedfv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedBaseInstance)(GLenum, GLint, GLsizei, GLsizei, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseInstance)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedBaseVertexBaseInstance)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint) = NULL;

static int Load_ARB_base_instance()
{
	int numFailed = 0;
	_ptrc_glDrawArraysInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei, GLuint))IntGetProcAddress("glDrawArraysInstancedBaseInstance");
	if(!_ptrc_glDrawArraysInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertexBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseVertexBaseInstance) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackInstanced)(GLenum, GLuint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackStreamInstanced)(GLenum, GLuint, GLuint, GLsizei) = NULL;

static int Load_ARB_transform_feedback_instanced()
{
	int numFailed = 0;
	_ptrc_glDrawTransformFeedbackInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackInstanced");
	if(!_ptrc_glDrawTransformFeedbackInstanced) numFailed++;
	_ptrc_glDrawTransformFeedbackStreamInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	if(!_ptrc_glDrawTransformFeedbackStreamInstanced) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformativ)(GLenum, GLenum, GLenum, GLsizei, GLint *) = NULL;

static int Load_ARB_internalformat_query()
{
	int numFailed = 0;
	_ptrc_glGetInternalformativ = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLint *))IntGetProcAddress("glGetInternalformativ");
	if(!_ptrc_glGetInternalformativ) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAtomicCounterBufferiv)(GLuint, GLuint, GLenum, GLint *) = NULL;

static int Load_ARB_shader_atomic_counters()
{
	int numFailed = 0;
	_ptrc_glGetActiveAtomicCounterBufferiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveAtomicCounterBufferiv");
	if(!_ptrc_glGetActiveAtomicCounterBufferiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindImageTexture)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrier)(GLbitfield) = NULL;

static int Load_ARB_shader_image_load_store()
{
	int numFailed = 0;
	_ptrc_glBindImageTexture = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum))IntGetProcAddress("glBindImageTexture");
	if(!_ptrc_glBindImageTexture) numFailed++;
	_ptrc_glMemoryBarrier = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrier");
	if(!_ptrc_glMemoryBarrier) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexStorage1D)(GLenum, GLsizei, GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3D)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei) = NULL;

static int Load_ARB_texture_storage()
{
	int numFailed = 0;
	_ptrc_glTexStorage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTexStorage1D");
	if(!_ptrc_glTexStorage1D) numFailed++;
	_ptrc_glTexStorage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTexStorage2D");
	if(!_ptrc_glTexStorage2D) numFailed++;
	_ptrc_glTexStorage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTexStorage3D");
	if(!_ptrc_glTexStorage3D) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallback)(GLDEBUGPROC, const void *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControl)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsert)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLog)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectLabel)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectPtrLabel)(const void *, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointerv)(GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glObjectLabel)(GLenum, GLuint, GLsizei, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glObjectPtrLabel)(const void *, GLsizei, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPopDebugGroup)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushDebugGroup)(GLenum, GLuint, GLsizei, const GLchar *) = NULL;

static int Load_KHR_debug()
{
	int numFailed = 0;
	_ptrc_glDebugMessageCallback = (void (CODEGEN_FUNCPTR *)(GLDEBUGPROC, const void *))IntGetProcAddress("glDebugMessageCallback");
	if(!_ptrc_glDebugMessageCallback) numFailed++;
	_ptrc_glDebugMessageControl = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean))IntGetProcAddress("glDebugMessageControl");
	if(!_ptrc_glDebugMessageControl) numFailed++;
	_ptrc_glDebugMessageInsert = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *))IntGetProcAddress("glDebugMessageInsert");
	if(!_ptrc_glDebugMessageInsert) numFailed++;
	_ptrc_glGetDebugMessageLog = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *))IntGetProcAddress("glGetDebugMessageLog");
	if(!_ptrc_glGetDebugMessageLog) numFailed++;
	_ptrc_glGetObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectLabel");
	if(!_ptrc_glGetObjectLabel) numFailed++;
	_ptrc_glGetObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectPtrLabel");
	if(!_ptrc_glGetObjectPtrLabel) numFailed++;
	_ptrc_glGetPointerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLvoid **))IntGetProcAddress("glGetPointerv");
	if(!_ptrc_glGetPointerv) numFailed++;
	_ptrc_glObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glObjectLabel");
	if(!_ptrc_glObjectLabel) numFailed++;
	_ptrc_glObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, const GLchar *))IntGetProcAddress("glObjectPtrLabel");
	if(!_ptrc_glObjectPtrLabel) numFailed++;
	_ptrc_glPopDebugGroup = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPopDebugGroup");
	if(!_ptrc_glPopDebugGroup) numFailed++;
	_ptrc_glPushDebugGroup = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glPushDebugGroup");
	if(!_ptrc_glPushDebugGroup) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearBufferData)(GLenum, GLenum, GLenum, GLenum, const void *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferSubData)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *) = NULL;

static int Load_ARB_clear_buffer_object()
{
	int numFailed = 0;
	_ptrc_glClearBufferData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferData");
	if(!_ptrc_glClearBufferData) numFailed++;
	_ptrc_glClearBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferSubData");
	if(!_ptrc_glClearBufferSubData) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDispatchCompute)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeIndirect)(GLintptr) = NULL;

static int Load_ARB_compute_shader()
{
	int numFailed = 0;
	_ptrc_glDispatchCompute = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glDispatchCompute");
	if(!_ptrc_glDispatchCompute) numFailed++;
	_ptrc_glDispatchComputeIndirect = (void (CODEGEN_FUNCPTR *)(GLintptr))IntGetProcAddress("glDispatchComputeIndirect");
	if(!_ptrc_glDispatchComputeIndirect) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubData)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei) = NULL;

static int Load_ARB_copy_image()
{
	int numFailed = 0;
	_ptrc_glCopyImageSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glCopyImageSubData");
	if(!_ptrc_glCopyImageSubData) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferParameteri)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameteriv)(GLenum, GLenum, GLint *) = NULL;

static int Load_ARB_framebuffer_no_attachments()
{
	int numFailed = 0;
	_ptrc_glFramebufferParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glFramebufferParameteri");
	if(!_ptrc_glFramebufferParameteri) numFailed++;
	_ptrc_glGetFramebufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferParameteriv");
	if(!_ptrc_glGetFramebufferParameteriv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetInternalformati64v)(GLenum, GLenum, GLenum, GLsizei, GLint64 *) = NULL;

static int Load_ARB_internalformat_query2()
{
	int numFailed = 0;
	_ptrc_glGetInternalformati64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLint64 *))IntGetProcAddress("glGetInternalformati64v");
	if(!_ptrc_glGetInternalformati64v) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferData)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateBufferSubData)(GLuint, GLintptr, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateFramebuffer)(GLenum, GLsizei, const GLenum *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateSubFramebuffer)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexImage)(GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInvalidateTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei) = NULL;

static int Load_ARB_invalidate_subdata()
{
	int numFailed = 0;
	_ptrc_glInvalidateBufferData = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glInvalidateBufferData");
	if(!_ptrc_glInvalidateBufferData) numFailed++;
	_ptrc_glInvalidateBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glInvalidateBufferSubData");
	if(!_ptrc_glInvalidateBufferSubData) numFailed++;
	_ptrc_glInvalidateFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *))IntGetProcAddress("glInvalidateFramebuffer");
	if(!_ptrc_glInvalidateFramebuffer) numFailed++;
	_ptrc_glInvalidateSubFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glInvalidateSubFramebuffer");
	if(!_ptrc_glInvalidateSubFramebuffer) numFailed++;
	_ptrc_glInvalidateTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glInvalidateTexImage");
	if(!_ptrc_glInvalidateTexImage) numFailed++;
	_ptrc_glInvalidateTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glInvalidateTexSubImage");
	if(!_ptrc_glInvalidateTexSubImage) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirect)(GLenum, const void *, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirect)(GLenum, GLenum, const void *, GLsizei, GLsizei) = NULL;

static int Load_ARB_multi_draw_indirect()
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirect");
	if(!_ptrc_glMultiDrawArraysIndirect) numFailed++;
	_ptrc_glMultiDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirect");
	if(!_ptrc_glMultiDrawElementsIndirect) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInterfaceiv)(GLuint, GLenum, GLenum, GLint *) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceIndex)(GLuint, GLenum, const GLchar *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocation)(GLuint, GLenum, const GLchar *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceLocationIndex)(GLuint, GLenum, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceName)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramResourceiv)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *) = NULL;

static int Load_ARB_program_interface_query()
{
	int numFailed = 0;
	_ptrc_glGetProgramInterfaceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramInterfaceiv");
	if(!_ptrc_glGetProgramInterfaceiv) numFailed++;
	_ptrc_glGetProgramResourceIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceIndex");
	if(!_ptrc_glGetProgramResourceIndex) numFailed++;
	_ptrc_glGetProgramResourceLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocation");
	if(!_ptrc_glGetProgramResourceLocation) numFailed++;
	_ptrc_glGetProgramResourceLocationIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocationIndex");
	if(!_ptrc_glGetProgramResourceLocationIndex) numFailed++;
	_ptrc_glGetProgramResourceName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramResourceName");
	if(!_ptrc_glGetProgramResourceName) numFailed++;
	_ptrc_glGetProgramResourceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetProgramResourceiv");
	if(!_ptrc_glGetProgramResourceiv) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glShaderStorageBlockBinding)(GLuint, GLuint, GLuint) = NULL;

static int Load_ARB_shader_storage_buffer_object()
{
	int numFailed = 0;
	_ptrc_glShaderStorageBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glShaderStorageBlockBinding");
	if(!_ptrc_glShaderStorageBlockBinding) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexBufferRange)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr) = NULL;

static int Load_ARB_texture_buffer_range()
{
	int numFailed = 0;
	_ptrc_glTexBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTexBufferRange");
	if(!_ptrc_glTexBufferRange) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexStorage2DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexStorage3DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;

static int Load_ARB_texture_storage_multisample()
{
	int numFailed = 0;
	_ptrc_glTexStorage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage2DMultisample");
	if(!_ptrc_glTexStorage2DMultisample) numFailed++;
	_ptrc_glTexStorage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage3DMultisample");
	if(!_ptrc_glTexStorage3DMultisample) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTextureView)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint) = NULL;

static int Load_ARB_texture_view()
{
	int numFailed = 0;
	_ptrc_glTextureView = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glTextureView");
	if(!_ptrc_glTextureView) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffer)(GLuint, GLuint, GLintptr, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribBinding)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormat)(GLuint, GLint, GLenum, GLboolean, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormat)(GLuint, GLint, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormat)(GLuint, GLint, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexBindingDivisor)(GLuint, GLuint) = NULL;

static int Load_ARB_vertex_attrib_binding()
{
	int numFailed = 0;
	_ptrc_glBindVertexBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glBindVertexBuffer");
	if(!_ptrc_glBindVertexBuffer) numFailed++;
	_ptrc_glVertexAttribBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribBinding");
	if(!_ptrc_glVertexAttribBinding) numFailed++;
	_ptrc_glVertexAttribFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribFormat");
	if(!_ptrc_glVertexAttribFormat) numFailed++;
	_ptrc_glVertexAttribIFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribIFormat");
	if(!_ptrc_glVertexAttribIFormat) numFailed++;
	_ptrc_glVertexAttribLFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribLFormat");
	if(!_ptrc_glVertexAttribLFormat) numFailed++;
	_ptrc_glVertexBindingDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexBindingDivisor");
	if(!_ptrc_glVertexBindingDivisor) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBufferStorage)(GLenum, GLsizeiptr, const void *, GLbitfield) = NULL;

static int Load_ARB_buffer_storage()
{
	int numFailed = 0;
	_ptrc_glBufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptr, const void *, GLbitfield))IntGetProcAddress("glBufferStorage");
	if(!_ptrc_glBufferStorage) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearTexImage)(GLuint, GLint, GLenum, GLenum, const void *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearTexSubImage)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *) = NULL;

static int Load_ARB_clear_texture()
{
	int numFailed = 0;
	_ptrc_glClearTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexImage");
	if(!_ptrc_glClearTexImage) numFailed++;
	_ptrc_glClearTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexSubImage");
	if(!_ptrc_glClearTexSubImage) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersBase)(GLenum, GLuint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBuffersRange)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextures)(GLuint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindSamplers)(GLuint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindTextures)(GLuint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindVertexBuffers)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *) = NULL;

static int Load_ARB_multi_bind()
{
	int numFailed = 0;
	_ptrc_glBindBuffersBase = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindBuffersBase");
	if(!_ptrc_glBindBuffersBase) numFailed++;
	_ptrc_glBindBuffersRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *))IntGetProcAddress("glBindBuffersRange");
	if(!_ptrc_glBindBuffersRange) numFailed++;
	_ptrc_glBindImageTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindImageTextures");
	if(!_ptrc_glBindImageTextures) numFailed++;
	_ptrc_glBindSamplers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindSamplers");
	if(!_ptrc_glBindSamplers) numFailed++;
	_ptrc_glBindTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindTextures");
	if(!_ptrc_glBindTextures) numFailed++;
	_ptrc_glBindVertexBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *))IntGetProcAddress("glBindVertexBuffers");
	if(!_ptrc_glBindVertexBuffers) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTbufferMask3DFX)(GLuint) = NULL;

static int Load_3DFX_tbuffer()
{
	int numFailed = 0;
	_ptrc_glTbufferMask3DFX = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glTbufferMask3DFX");
	if(!_ptrc_glTbufferMask3DFX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallbackAMD)(GLDEBUGPROCAMD, void *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageEnableAMD)(GLenum, GLenum, GLsizei, const GLuint *, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsertAMD)(GLenum, GLenum, GLuint, GLsizei, const GLchar *) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLogAMD)(GLuint, GLsizei, GLenum *, GLuint *, GLuint *, GLsizei *, GLchar *) = NULL;

static int Load_AMD_debug_output()
{
	int numFailed = 0;
	_ptrc_glDebugMessageCallbackAMD = (void (CODEGEN_FUNCPTR *)(GLDEBUGPROCAMD, void *))IntGetProcAddress("glDebugMessageCallbackAMD");
	if(!_ptrc_glDebugMessageCallbackAMD) numFailed++;
	_ptrc_glDebugMessageEnableAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, const GLuint *, GLboolean))IntGetProcAddress("glDebugMessageEnableAMD");
	if(!_ptrc_glDebugMessageEnableAMD) numFailed++;
	_ptrc_glDebugMessageInsertAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glDebugMessageInsertAMD");
	if(!_ptrc_glDebugMessageInsertAMD) numFailed++;
	_ptrc_glGetDebugMessageLogAMD = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum *, GLuint *, GLuint *, GLsizei *, GLchar *))IntGetProcAddress("glGetDebugMessageLogAMD");
	if(!_ptrc_glGetDebugMessageLogAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationIndexedAMD)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateIndexedAMD)(GLuint, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncIndexedAMD)(GLuint, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateIndexedAMD)(GLuint, GLenum, GLenum, GLenum, GLenum) = NULL;

static int Load_AMD_draw_buffers_blend()
{
	int numFailed = 0;
	_ptrc_glBlendEquationIndexedAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBlendEquationIndexedAMD");
	if(!_ptrc_glBlendEquationIndexedAMD) numFailed++;
	_ptrc_glBlendEquationSeparateIndexedAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparateIndexedAMD");
	if(!_ptrc_glBlendEquationSeparateIndexedAMD) numFailed++;
	_ptrc_glBlendFuncIndexedAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendFuncIndexedAMD");
	if(!_ptrc_glBlendFuncIndexedAMD) numFailed++;
	_ptrc_glBlendFuncSeparateIndexedAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparateIndexedAMD");
	if(!_ptrc_glBlendFuncSeparateIndexedAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribParameteriAMD)(GLuint, GLenum, GLint) = NULL;

static int Load_AMD_interleaved_elements()
{
	int numFailed = 0;
	_ptrc_glVertexAttribParameteriAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glVertexAttribParameteriAMD");
	if(!_ptrc_glVertexAttribParameteriAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectAMD)(GLenum, const GLvoid *, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectAMD)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei) = NULL;

static int Load_AMD_multi_draw_indirect()
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirectAMD = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirectAMD");
	if(!_ptrc_glMultiDrawArraysIndirectAMD) numFailed++;
	_ptrc_glMultiDrawElementsIndirectAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirectAMD");
	if(!_ptrc_glMultiDrawElementsIndirectAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDeleteNamesAMD)(GLenum, GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenNamesAMD)(GLenum, GLuint, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNameAMD)(GLenum, GLuint) = NULL;

static int Load_AMD_name_gen_delete()
{
	int numFailed = 0;
	_ptrc_glDeleteNamesAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLuint *))IntGetProcAddress("glDeleteNamesAMD");
	if(!_ptrc_glDeleteNamesAMD) numFailed++;
	_ptrc_glGenNamesAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint *))IntGetProcAddress("glGenNamesAMD");
	if(!_ptrc_glGenNamesAMD) numFailed++;
	_ptrc_glIsNameAMD = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glIsNameAMD");
	if(!_ptrc_glIsNameAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginPerfMonitorAMD)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeletePerfMonitorsAMD)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndPerfMonitorAMD)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenPerfMonitorsAMD)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCounterDataAMD)(GLuint, GLenum, GLsizei, GLuint *, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCounterInfoAMD)(GLuint, GLuint, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCounterStringAMD)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorCountersAMD)(GLuint, GLint *, GLint *, GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorGroupStringAMD)(GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPerfMonitorGroupsAMD)(GLint *, GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSelectPerfMonitorCountersAMD)(GLuint, GLboolean, GLuint, GLint, GLuint *) = NULL;

static int Load_AMD_performance_monitor()
{
	int numFailed = 0;
	_ptrc_glBeginPerfMonitorAMD = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBeginPerfMonitorAMD");
	if(!_ptrc_glBeginPerfMonitorAMD) numFailed++;
	_ptrc_glDeletePerfMonitorsAMD = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glDeletePerfMonitorsAMD");
	if(!_ptrc_glDeletePerfMonitorsAMD) numFailed++;
	_ptrc_glEndPerfMonitorAMD = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEndPerfMonitorAMD");
	if(!_ptrc_glEndPerfMonitorAMD) numFailed++;
	_ptrc_glGenPerfMonitorsAMD = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenPerfMonitorsAMD");
	if(!_ptrc_glGenPerfMonitorsAMD) numFailed++;
	_ptrc_glGetPerfMonitorCounterDataAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLuint *, GLint *))IntGetProcAddress("glGetPerfMonitorCounterDataAMD");
	if(!_ptrc_glGetPerfMonitorCounterDataAMD) numFailed++;
	_ptrc_glGetPerfMonitorCounterInfoAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLvoid *))IntGetProcAddress("glGetPerfMonitorCounterInfoAMD");
	if(!_ptrc_glGetPerfMonitorCounterInfoAMD) numFailed++;
	_ptrc_glGetPerfMonitorCounterStringAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetPerfMonitorCounterStringAMD");
	if(!_ptrc_glGetPerfMonitorCounterStringAMD) numFailed++;
	_ptrc_glGetPerfMonitorCountersAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLint *, GLint *, GLsizei, GLuint *))IntGetProcAddress("glGetPerfMonitorCountersAMD");
	if(!_ptrc_glGetPerfMonitorCountersAMD) numFailed++;
	_ptrc_glGetPerfMonitorGroupStringAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetPerfMonitorGroupStringAMD");
	if(!_ptrc_glGetPerfMonitorGroupStringAMD) numFailed++;
	_ptrc_glGetPerfMonitorGroupsAMD = (void (CODEGEN_FUNCPTR *)(GLint *, GLsizei, GLuint *))IntGetProcAddress("glGetPerfMonitorGroupsAMD");
	if(!_ptrc_glGetPerfMonitorGroupsAMD) numFailed++;
	_ptrc_glSelectPerfMonitorCountersAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLboolean, GLuint, GLint, GLuint *))IntGetProcAddress("glSelectPerfMonitorCountersAMD");
	if(!_ptrc_glSelectPerfMonitorCountersAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSetMultisamplefvAMD)(GLenum, GLuint, const GLfloat *) = NULL;

static int Load_AMD_sample_positions()
{
	int numFailed = 0;
	_ptrc_glSetMultisamplefvAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glSetMultisamplefvAMD");
	if(!_ptrc_glSetMultisamplefvAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexStorageSparseAMD)(GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorageSparseAMD)(GLuint, GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield) = NULL;

static int Load_AMD_sparse_texture()
{
	int numFailed = 0;
	_ptrc_glTexStorageSparseAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield))IntGetProcAddress("glTexStorageSparseAMD");
	if(!_ptrc_glTexStorageSparseAMD) numFailed++;
	_ptrc_glTextureStorageSparseAMD = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLbitfield))IntGetProcAddress("glTextureStorageSparseAMD");
	if(!_ptrc_glTextureStorageSparseAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glStencilOpValueAMD)(GLenum, GLuint) = NULL;

static int Load_AMD_stencil_operation_extended()
{
	int numFailed = 0;
	_ptrc_glStencilOpValueAMD = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glStencilOpValueAMD");
	if(!_ptrc_glStencilOpValueAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTessellationFactorAMD)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTessellationModeAMD)(GLenum) = NULL;

static int Load_AMD_vertex_shader_tessellator()
{
	int numFailed = 0;
	_ptrc_glTessellationFactorAMD = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glTessellationFactorAMD");
	if(!_ptrc_glTessellationFactorAMD) numFailed++;
	_ptrc_glTessellationModeAMD = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glTessellationModeAMD");
	if(!_ptrc_glTessellationModeAMD) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawElementArrayAPPLE)(GLenum, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementArrayAPPLE)(GLenum, GLuint, GLuint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glElementPointerAPPLE)(GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementArrayAPPLE)(GLenum, const GLint *, const GLsizei *, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawRangeElementArrayAPPLE)(GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei) = NULL;

static int Load_APPLE_element_array()
{
	int numFailed = 0;
	_ptrc_glDrawElementArrayAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei))IntGetProcAddress("glDrawElementArrayAPPLE");
	if(!_ptrc_glDrawElementArrayAPPLE) numFailed++;
	_ptrc_glDrawRangeElementArrayAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLint, GLsizei))IntGetProcAddress("glDrawRangeElementArrayAPPLE");
	if(!_ptrc_glDrawRangeElementArrayAPPLE) numFailed++;
	_ptrc_glElementPointerAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid *))IntGetProcAddress("glElementPointerAPPLE");
	if(!_ptrc_glElementPointerAPPLE) numFailed++;
	_ptrc_glMultiDrawElementArrayAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *, const GLsizei *, GLsizei))IntGetProcAddress("glMultiDrawElementArrayAPPLE");
	if(!_ptrc_glMultiDrawElementArrayAPPLE) numFailed++;
	_ptrc_glMultiDrawRangeElementArrayAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, const GLint *, const GLsizei *, GLsizei))IntGetProcAddress("glMultiDrawRangeElementArrayAPPLE");
	if(!_ptrc_glMultiDrawRangeElementArrayAPPLE) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDeleteFencesAPPLE)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinishFenceAPPLE)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinishObjectAPPLE)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenFencesAPPLE)(GLsizei, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFenceAPPLE)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSetFenceAPPLE)(GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestFenceAPPLE)(GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestObjectAPPLE)(GLenum, GLuint) = NULL;

static int Load_APPLE_fence()
{
	int numFailed = 0;
	_ptrc_glDeleteFencesAPPLE = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFencesAPPLE");
	if(!_ptrc_glDeleteFencesAPPLE) numFailed++;
	_ptrc_glFinishFenceAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glFinishFenceAPPLE");
	if(!_ptrc_glFinishFenceAPPLE) numFailed++;
	_ptrc_glFinishObjectAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glFinishObjectAPPLE");
	if(!_ptrc_glFinishObjectAPPLE) numFailed++;
	_ptrc_glGenFencesAPPLE = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFencesAPPLE");
	if(!_ptrc_glGenFencesAPPLE) numFailed++;
	_ptrc_glIsFenceAPPLE = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFenceAPPLE");
	if(!_ptrc_glIsFenceAPPLE) numFailed++;
	_ptrc_glSetFenceAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glSetFenceAPPLE");
	if(!_ptrc_glSetFenceAPPLE) numFailed++;
	_ptrc_glTestFenceAPPLE = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glTestFenceAPPLE");
	if(!_ptrc_glTestFenceAPPLE) numFailed++;
	_ptrc_glTestObjectAPPLE = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTestObjectAPPLE");
	if(!_ptrc_glTestObjectAPPLE) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBufferParameteriAPPLE)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedBufferRangeAPPLE)(GLenum, GLintptr, GLsizeiptr) = NULL;

static int Load_APPLE_flush_buffer_range()
{
	int numFailed = 0;
	_ptrc_glBufferParameteriAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glBufferParameteriAPPLE");
	if(!_ptrc_glBufferParameteriAPPLE) numFailed++;
	_ptrc_glFlushMappedBufferRangeAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedBufferRangeAPPLE");
	if(!_ptrc_glFlushMappedBufferRangeAPPLE) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterivAPPLE)(GLenum, GLuint, GLenum, GLint *) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glObjectPurgeableAPPLE)(GLenum, GLuint, GLenum) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glObjectUnpurgeableAPPLE)(GLenum, GLuint, GLenum) = NULL;

static int Load_APPLE_object_purgeable()
{
	int numFailed = 0;
	_ptrc_glGetObjectParameterivAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetObjectParameterivAPPLE");
	if(!_ptrc_glGetObjectParameterivAPPLE) numFailed++;
	_ptrc_glObjectPurgeableAPPLE = (GLenum (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum))IntGetProcAddress("glObjectPurgeableAPPLE");
	if(!_ptrc_glObjectPurgeableAPPLE) numFailed++;
	_ptrc_glObjectUnpurgeableAPPLE = (GLenum (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum))IntGetProcAddress("glObjectUnpurgeableAPPLE");
	if(!_ptrc_glObjectUnpurgeableAPPLE) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterPointervAPPLE)(GLenum, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureRangeAPPLE)(GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_APPLE_texture_range()
{
	int numFailed = 0;
	_ptrc_glGetTexParameterPointervAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLvoid **))IntGetProcAddress("glGetTexParameterPointervAPPLE");
	if(!_ptrc_glGetTexParameterPointervAPPLE) numFailed++;
	_ptrc_glTextureRangeAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glTextureRangeAPPLE");
	if(!_ptrc_glTextureRangeAPPLE) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindVertexArrayAPPLE)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexArraysAPPLE)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenVertexArraysAPPLE)(GLsizei, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexArrayAPPLE)(GLuint) = NULL;

static int Load_APPLE_vertex_array_object()
{
	int numFailed = 0;
	_ptrc_glBindVertexArrayAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindVertexArrayAPPLE");
	if(!_ptrc_glBindVertexArrayAPPLE) numFailed++;
	_ptrc_glDeleteVertexArraysAPPLE = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteVertexArraysAPPLE");
	if(!_ptrc_glDeleteVertexArraysAPPLE) numFailed++;
	_ptrc_glGenVertexArraysAPPLE = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenVertexArraysAPPLE");
	if(!_ptrc_glGenVertexArraysAPPLE) numFailed++;
	_ptrc_glIsVertexArrayAPPLE = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsVertexArrayAPPLE");
	if(!_ptrc_glIsVertexArrayAPPLE) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushVertexArrayRangeAPPLE)(GLsizei, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayParameteriAPPLE)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayRangeAPPLE)(GLsizei, GLvoid *) = NULL;

static int Load_APPLE_vertex_array_range()
{
	int numFailed = 0;
	_ptrc_glFlushVertexArrayRangeAPPLE = (void (CODEGEN_FUNCPTR *)(GLsizei, GLvoid *))IntGetProcAddress("glFlushVertexArrayRangeAPPLE");
	if(!_ptrc_glFlushVertexArrayRangeAPPLE) numFailed++;
	_ptrc_glVertexArrayParameteriAPPLE = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glVertexArrayParameteriAPPLE");
	if(!_ptrc_glVertexArrayParameteriAPPLE) numFailed++;
	_ptrc_glVertexArrayRangeAPPLE = (void (CODEGEN_FUNCPTR *)(GLsizei, GLvoid *))IntGetProcAddress("glVertexArrayRangeAPPLE");
	if(!_ptrc_glVertexArrayRangeAPPLE) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribAPPLE)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribAPPLE)(GLuint, GLenum) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVertexAttribEnabledAPPLE)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib1dAPPLE)(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib1fAPPLE)(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib2dAPPLE)(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapVertexAttrib2fAPPLE)(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *) = NULL;

static int Load_APPLE_vertex_program_evaluators()
{
	int numFailed = 0;
	_ptrc_glDisableVertexAttribAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glDisableVertexAttribAPPLE");
	if(!_ptrc_glDisableVertexAttribAPPLE) numFailed++;
	_ptrc_glEnableVertexAttribAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glEnableVertexAttribAPPLE");
	if(!_ptrc_glEnableVertexAttribAPPLE) numFailed++;
	_ptrc_glIsVertexAttribEnabledAPPLE = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glIsVertexAttribEnabledAPPLE");
	if(!_ptrc_glIsVertexAttribEnabledAPPLE) numFailed++;
	_ptrc_glMapVertexAttrib1dAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, const GLdouble *))IntGetProcAddress("glMapVertexAttrib1dAPPLE");
	if(!_ptrc_glMapVertexAttrib1dAPPLE) numFailed++;
	_ptrc_glMapVertexAttrib1fAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, const GLfloat *))IntGetProcAddress("glMapVertexAttrib1fAPPLE");
	if(!_ptrc_glMapVertexAttrib1fAPPLE) numFailed++;
	_ptrc_glMapVertexAttrib2dAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *))IntGetProcAddress("glMapVertexAttrib2dAPPLE");
	if(!_ptrc_glMapVertexAttrib2dAPPLE) numFailed++;
	_ptrc_glMapVertexAttrib2fAPPLE = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *))IntGetProcAddress("glMapVertexAttrib2fAPPLE");
	if(!_ptrc_glMapVertexAttrib2fAPPLE) numFailed++;
	return numFailed;
}

GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetImageHandleARB)(GLuint, GLint, GLboolean, GLint, GLenum) = NULL;
GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureHandleARB)(GLuint) = NULL;
GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureSamplerHandleARB)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLui64vARB)(GLuint, GLenum, GLuint64EXT *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsImageHandleResidentARB)(GLuint64) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureHandleResidentARB)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleNonResidentARB)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleResidentARB)(GLuint64, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleNonResidentARB)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleResidentARB)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64ARB)(GLuint, GLint, GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64vARB)(GLuint, GLint, GLsizei, const GLuint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64ARB)(GLint, GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64vARB)(GLint, GLsizei, const GLuint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64ARB)(GLuint, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64vARB)(GLuint, const GLuint64EXT *) = NULL;

static int Load_ARB_bindless_texture()
{
	int numFailed = 0;
	_ptrc_glGetImageHandleARB = (GLuint64 (CODEGEN_FUNCPTR *)(GLuint, GLint, GLboolean, GLint, GLenum))IntGetProcAddress("glGetImageHandleARB");
	if(!_ptrc_glGetImageHandleARB) numFailed++;
	_ptrc_glGetTextureHandleARB = (GLuint64 (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glGetTextureHandleARB");
	if(!_ptrc_glGetTextureHandleARB) numFailed++;
	_ptrc_glGetTextureSamplerHandleARB = (GLuint64 (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glGetTextureSamplerHandleARB");
	if(!_ptrc_glGetTextureSamplerHandleARB) numFailed++;
	_ptrc_glGetVertexAttribLui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64EXT *))IntGetProcAddress("glGetVertexAttribLui64vARB");
	if(!_ptrc_glGetVertexAttribLui64vARB) numFailed++;
	_ptrc_glIsImageHandleResidentARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glIsImageHandleResidentARB");
	if(!_ptrc_glIsImageHandleResidentARB) numFailed++;
	_ptrc_glIsTextureHandleResidentARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glIsTextureHandleResidentARB");
	if(!_ptrc_glIsTextureHandleResidentARB) numFailed++;
	_ptrc_glMakeImageHandleNonResidentARB = (void (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glMakeImageHandleNonResidentARB");
	if(!_ptrc_glMakeImageHandleNonResidentARB) numFailed++;
	_ptrc_glMakeImageHandleResidentARB = (void (CODEGEN_FUNCPTR *)(GLuint64, GLenum))IntGetProcAddress("glMakeImageHandleResidentARB");
	if(!_ptrc_glMakeImageHandleResidentARB) numFailed++;
	_ptrc_glMakeTextureHandleNonResidentARB = (void (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glMakeTextureHandleNonResidentARB");
	if(!_ptrc_glMakeTextureHandleNonResidentARB) numFailed++;
	_ptrc_glMakeTextureHandleResidentARB = (void (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glMakeTextureHandleResidentARB");
	if(!_ptrc_glMakeTextureHandleResidentARB) numFailed++;
	_ptrc_glProgramUniformHandleui64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64))IntGetProcAddress("glProgramUniformHandleui64ARB");
	if(!_ptrc_glProgramUniformHandleui64ARB) numFailed++;
	_ptrc_glProgramUniformHandleui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glProgramUniformHandleui64vARB");
	if(!_ptrc_glProgramUniformHandleui64vARB) numFailed++;
	_ptrc_glUniformHandleui64ARB = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64))IntGetProcAddress("glUniformHandleui64ARB");
	if(!_ptrc_glUniformHandleui64ARB) numFailed++;
	_ptrc_glUniformHandleui64vARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glUniformHandleui64vARB");
	if(!_ptrc_glUniformHandleui64vARB) numFailed++;
	_ptrc_glVertexAttribL1ui64ARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT))IntGetProcAddress("glVertexAttribL1ui64ARB");
	if(!_ptrc_glVertexAttribL1ui64ARB) numFailed++;
	_ptrc_glVertexAttribL1ui64vARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL1ui64vARB");
	if(!_ptrc_glVertexAttribL1ui64vARB) numFailed++;
	return numFailed;
}

GLsync (CODEGEN_FUNCPTR *_ptrc_glCreateSyncFromCLeventARB)(struct _cl_context *, struct _cl_event *, GLbitfield) = NULL;

static int Load_ARB_cl_event()
{
	int numFailed = 0;
	_ptrc_glCreateSyncFromCLeventARB = (GLsync (CODEGEN_FUNCPTR *)(struct _cl_context *, struct _cl_event *, GLbitfield))IntGetProcAddress("glCreateSyncFromCLeventARB");
	if(!_ptrc_glCreateSyncFromCLeventARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClampColorARB)(GLenum, GLenum) = NULL;

static int Load_ARB_color_buffer_float()
{
	int numFailed = 0;
	_ptrc_glClampColorARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glClampColorARB");
	if(!_ptrc_glClampColorARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDispatchComputeGroupSizeARB)(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;

static int Load_ARB_compute_variable_group_size()
{
	int numFailed = 0;
	_ptrc_glDispatchComputeGroupSizeARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glDispatchComputeGroupSizeARB");
	if(!_ptrc_glDispatchComputeGroupSizeARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageCallbackARB)(GLDEBUGPROCARB, const void *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageControlARB)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDebugMessageInsertARB)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGetDebugMessageLogARB)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *) = NULL;

static int Load_ARB_debug_output()
{
	int numFailed = 0;
	_ptrc_glDebugMessageCallbackARB = (void (CODEGEN_FUNCPTR *)(GLDEBUGPROCARB, const void *))IntGetProcAddress("glDebugMessageCallbackARB");
	if(!_ptrc_glDebugMessageCallbackARB) numFailed++;
	_ptrc_glDebugMessageControlARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean))IntGetProcAddress("glDebugMessageControlARB");
	if(!_ptrc_glDebugMessageControlARB) numFailed++;
	_ptrc_glDebugMessageInsertARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *))IntGetProcAddress("glDebugMessageInsertARB");
	if(!_ptrc_glDebugMessageInsertARB) numFailed++;
	_ptrc_glGetDebugMessageLogARB = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *))IntGetProcAddress("glGetDebugMessageLogARB");
	if(!_ptrc_glGetDebugMessageLogARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersARB)(GLsizei, const GLenum *) = NULL;

static int Load_ARB_draw_buffers()
{
	int numFailed = 0;
	_ptrc_glDrawBuffersARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLenum *))IntGetProcAddress("glDrawBuffersARB");
	if(!_ptrc_glDrawBuffersARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateiARB)(GLuint, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationiARB)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateiARB)(GLuint, GLenum, GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFunciARB)(GLuint, GLenum, GLenum) = NULL;

static int Load_ARB_draw_buffers_blend()
{
	int numFailed = 0;
	_ptrc_glBlendEquationSeparateiARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparateiARB");
	if(!_ptrc_glBlendEquationSeparateiARB) numFailed++;
	_ptrc_glBlendEquationiARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBlendEquationiARB");
	if(!_ptrc_glBlendEquationiARB) numFailed++;
	_ptrc_glBlendFuncSeparateiARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparateiARB");
	if(!_ptrc_glBlendFuncSeparateiARB) numFailed++;
	_ptrc_glBlendFunciARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendFunciARB");
	if(!_ptrc_glBlendFunciARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedARB)(GLenum, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedARB)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei) = NULL;

static int Load_ARB_draw_instanced()
{
	int numFailed = 0;
	_ptrc_glDrawArraysInstancedARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei))IntGetProcAddress("glDrawArraysInstancedARB");
	if(!_ptrc_glDrawArraysInstancedARB) numFailed++;
	_ptrc_glDrawElementsInstancedARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei))IntGetProcAddress("glDrawElementsInstancedARB");
	if(!_ptrc_glDrawElementsInstancedARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindProgramARB)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsARB)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsARB)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterdvARB)(GLenum, GLuint, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterfvARB)(GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterdvARB)(GLenum, GLuint, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterfvARB)(GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringARB)(GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivARB)(GLenum, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramARB)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4dvARB)(GLenum, GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameter4fvARB)(GLenum, GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dARB)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4dvARB)(GLenum, GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fARB)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameter4fvARB)(GLenum, GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramStringARB)(GLenum, GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_ARB_fragment_program()
{
	int numFailed = 0;
	_ptrc_glBindProgramARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindProgramARB");
	if(!_ptrc_glBindProgramARB) numFailed++;
	_ptrc_glDeleteProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramsARB");
	if(!_ptrc_glDeleteProgramsARB) numFailed++;
	_ptrc_glGenProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramsARB");
	if(!_ptrc_glGenProgramsARB) numFailed++;
	_ptrc_glGetProgramEnvParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramEnvParameterdvARB");
	if(!_ptrc_glGetProgramEnvParameterdvARB) numFailed++;
	_ptrc_glGetProgramEnvParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramEnvParameterfvARB");
	if(!_ptrc_glGetProgramEnvParameterfvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramLocalParameterdvARB");
	if(!_ptrc_glGetProgramLocalParameterdvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramLocalParameterfvARB");
	if(!_ptrc_glGetProgramLocalParameterfvARB) numFailed++;
	_ptrc_glGetProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetProgramStringARB");
	if(!_ptrc_glGetProgramStringARB) numFailed++;
	_ptrc_glGetProgramivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramivARB");
	if(!_ptrc_glGetProgramivARB) numFailed++;
	_ptrc_glIsProgramARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramARB");
	if(!_ptrc_glIsProgramARB) numFailed++;
	_ptrc_glProgramEnvParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramEnvParameter4dARB");
	if(!_ptrc_glProgramEnvParameter4dARB) numFailed++;
	_ptrc_glProgramEnvParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramEnvParameter4dvARB");
	if(!_ptrc_glProgramEnvParameter4dvARB) numFailed++;
	_ptrc_glProgramEnvParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramEnvParameter4fARB");
	if(!_ptrc_glProgramEnvParameter4fARB) numFailed++;
	_ptrc_glProgramEnvParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramEnvParameter4fvARB");
	if(!_ptrc_glProgramEnvParameter4fvARB) numFailed++;
	_ptrc_glProgramLocalParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramLocalParameter4dARB");
	if(!_ptrc_glProgramLocalParameter4dARB) numFailed++;
	_ptrc_glProgramLocalParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramLocalParameter4dvARB");
	if(!_ptrc_glProgramLocalParameter4dvARB) numFailed++;
	_ptrc_glProgramLocalParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramLocalParameter4fARB");
	if(!_ptrc_glProgramLocalParameter4fARB) numFailed++;
	_ptrc_glProgramLocalParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramLocalParameter4fvARB");
	if(!_ptrc_glProgramLocalParameter4fvARB) numFailed++;
	_ptrc_glProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glProgramStringARB");
	if(!_ptrc_glProgramStringARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureARB)(GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureFaceARB)(GLenum, GLenum, GLuint, GLint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerARB)(GLenum, GLenum, GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriARB)(GLuint, GLenum, GLint) = NULL;

static int Load_ARB_geometry_shader4()
{
	int numFailed = 0;
	_ptrc_glFramebufferTextureARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTextureARB");
	if(!_ptrc_glFramebufferTextureARB) numFailed++;
	_ptrc_glFramebufferTextureFaceARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLenum))IntGetProcAddress("glFramebufferTextureFaceARB");
	if(!_ptrc_glFramebufferTextureFaceARB) numFailed++;
	_ptrc_glFramebufferTextureLayerARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayerARB");
	if(!_ptrc_glFramebufferTextureLayerARB) numFailed++;
	_ptrc_glProgramParameteriARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteriARB");
	if(!_ptrc_glProgramParameteriARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectCountARB)(GLenum, GLintptr, GLintptr, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectCountARB)(GLenum, GLenum, GLintptr, GLintptr, GLsizei, GLsizei) = NULL;

static int Load_ARB_indirect_parameters()
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirectCountARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLintptr, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirectCountARB");
	if(!_ptrc_glMultiDrawArraysIndirectCountARB) numFailed++;
	_ptrc_glMultiDrawElementsIndirectCountARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLintptr, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirectCountARB");
	if(!_ptrc_glMultiDrawElementsIndirectCountARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisorARB)(GLuint, GLuint) = NULL;

static int Load_ARB_instanced_arrays()
{
	int numFailed = 0;
	_ptrc_glVertexAttribDivisorARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribDivisorARB");
	if(!_ptrc_glVertexAttribDivisorARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCurrentPaletteMatrixARB)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexPointerARB)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexubvARB)(GLint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexuivARB)(GLint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixIndexusvARB)(GLint, const GLushort *) = NULL;

static int Load_ARB_matrix_palette()
{
	int numFailed = 0;
	_ptrc_glCurrentPaletteMatrixARB = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glCurrentPaletteMatrixARB");
	if(!_ptrc_glCurrentPaletteMatrixARB) numFailed++;
	_ptrc_glMatrixIndexPointerARB = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glMatrixIndexPointerARB");
	if(!_ptrc_glMatrixIndexPointerARB) numFailed++;
	_ptrc_glMatrixIndexubvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLubyte *))IntGetProcAddress("glMatrixIndexubvARB");
	if(!_ptrc_glMatrixIndexubvARB) numFailed++;
	_ptrc_glMatrixIndexuivARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLuint *))IntGetProcAddress("glMatrixIndexuivARB");
	if(!_ptrc_glMatrixIndexuivARB) numFailed++;
	_ptrc_glMatrixIndexusvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLushort *))IntGetProcAddress("glMatrixIndexusvARB");
	if(!_ptrc_glMatrixIndexusvARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverageARB)(GLfloat, GLboolean) = NULL;

static int Load_ARB_multisample()
{
	int numFailed = 0;
	_ptrc_glSampleCoverageARB = (void (CODEGEN_FUNCPTR *)(GLfloat, GLboolean))IntGetProcAddress("glSampleCoverageARB");
	if(!_ptrc_glSampleCoverageARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveTextureARB)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClientActiveTextureARB)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dARB)(GLenum, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dvARB)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fARB)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fvARB)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1iARB)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1ivARB)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1sARB)(GLenum, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1svARB)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dARB)(GLenum, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dvARB)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fARB)(GLenum, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fvARB)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2iARB)(GLenum, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2ivARB)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2sARB)(GLenum, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2svARB)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dARB)(GLenum, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dvARB)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fARB)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fvARB)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3iARB)(GLenum, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3ivARB)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3sARB)(GLenum, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3svARB)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dARB)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dvARB)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fARB)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fvARB)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4iARB)(GLenum, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4ivARB)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4sARB)(GLenum, GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4svARB)(GLenum, const GLshort *) = NULL;

static int Load_ARB_multitexture()
{
	int numFailed = 0;
	_ptrc_glActiveTextureARB = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glActiveTextureARB");
	if(!_ptrc_glActiveTextureARB) numFailed++;
	_ptrc_glClientActiveTextureARB = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glClientActiveTextureARB");
	if(!_ptrc_glClientActiveTextureARB) numFailed++;
	_ptrc_glMultiTexCoord1dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble))IntGetProcAddress("glMultiTexCoord1dARB");
	if(!_ptrc_glMultiTexCoord1dARB) numFailed++;
	_ptrc_glMultiTexCoord1dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord1dvARB");
	if(!_ptrc_glMultiTexCoord1dvARB) numFailed++;
	_ptrc_glMultiTexCoord1fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glMultiTexCoord1fARB");
	if(!_ptrc_glMultiTexCoord1fARB) numFailed++;
	_ptrc_glMultiTexCoord1fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord1fvARB");
	if(!_ptrc_glMultiTexCoord1fvARB) numFailed++;
	_ptrc_glMultiTexCoord1iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glMultiTexCoord1iARB");
	if(!_ptrc_glMultiTexCoord1iARB) numFailed++;
	_ptrc_glMultiTexCoord1ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord1ivARB");
	if(!_ptrc_glMultiTexCoord1ivARB) numFailed++;
	_ptrc_glMultiTexCoord1sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort))IntGetProcAddress("glMultiTexCoord1sARB");
	if(!_ptrc_glMultiTexCoord1sARB) numFailed++;
	_ptrc_glMultiTexCoord1svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord1svARB");
	if(!_ptrc_glMultiTexCoord1svARB) numFailed++;
	_ptrc_glMultiTexCoord2dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord2dARB");
	if(!_ptrc_glMultiTexCoord2dARB) numFailed++;
	_ptrc_glMultiTexCoord2dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord2dvARB");
	if(!_ptrc_glMultiTexCoord2dvARB) numFailed++;
	_ptrc_glMultiTexCoord2fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord2fARB");
	if(!_ptrc_glMultiTexCoord2fARB) numFailed++;
	_ptrc_glMultiTexCoord2fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord2fvARB");
	if(!_ptrc_glMultiTexCoord2fvARB) numFailed++;
	_ptrc_glMultiTexCoord2iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint))IntGetProcAddress("glMultiTexCoord2iARB");
	if(!_ptrc_glMultiTexCoord2iARB) numFailed++;
	_ptrc_glMultiTexCoord2ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord2ivARB");
	if(!_ptrc_glMultiTexCoord2ivARB) numFailed++;
	_ptrc_glMultiTexCoord2sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord2sARB");
	if(!_ptrc_glMultiTexCoord2sARB) numFailed++;
	_ptrc_glMultiTexCoord2svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord2svARB");
	if(!_ptrc_glMultiTexCoord2svARB) numFailed++;
	_ptrc_glMultiTexCoord3dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord3dARB");
	if(!_ptrc_glMultiTexCoord3dARB) numFailed++;
	_ptrc_glMultiTexCoord3dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord3dvARB");
	if(!_ptrc_glMultiTexCoord3dvARB) numFailed++;
	_ptrc_glMultiTexCoord3fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord3fARB");
	if(!_ptrc_glMultiTexCoord3fARB) numFailed++;
	_ptrc_glMultiTexCoord3fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord3fvARB");
	if(!_ptrc_glMultiTexCoord3fvARB) numFailed++;
	_ptrc_glMultiTexCoord3iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint))IntGetProcAddress("glMultiTexCoord3iARB");
	if(!_ptrc_glMultiTexCoord3iARB) numFailed++;
	_ptrc_glMultiTexCoord3ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord3ivARB");
	if(!_ptrc_glMultiTexCoord3ivARB) numFailed++;
	_ptrc_glMultiTexCoord3sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord3sARB");
	if(!_ptrc_glMultiTexCoord3sARB) numFailed++;
	_ptrc_glMultiTexCoord3svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord3svARB");
	if(!_ptrc_glMultiTexCoord3svARB) numFailed++;
	_ptrc_glMultiTexCoord4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord4dARB");
	if(!_ptrc_glMultiTexCoord4dARB) numFailed++;
	_ptrc_glMultiTexCoord4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord4dvARB");
	if(!_ptrc_glMultiTexCoord4dvARB) numFailed++;
	_ptrc_glMultiTexCoord4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord4fARB");
	if(!_ptrc_glMultiTexCoord4fARB) numFailed++;
	_ptrc_glMultiTexCoord4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord4fvARB");
	if(!_ptrc_glMultiTexCoord4fvARB) numFailed++;
	_ptrc_glMultiTexCoord4iARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint))IntGetProcAddress("glMultiTexCoord4iARB");
	if(!_ptrc_glMultiTexCoord4iARB) numFailed++;
	_ptrc_glMultiTexCoord4ivARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord4ivARB");
	if(!_ptrc_glMultiTexCoord4ivARB) numFailed++;
	_ptrc_glMultiTexCoord4sARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord4sARB");
	if(!_ptrc_glMultiTexCoord4sARB) numFailed++;
	_ptrc_glMultiTexCoord4svARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord4svARB");
	if(!_ptrc_glMultiTexCoord4svARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginQueryARB)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueriesARB)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndQueryARB)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenQueriesARB)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectivARB)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuivARB)(GLuint, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryivARB)(GLenum, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQueryARB)(GLuint) = NULL;

static int Load_ARB_occlusion_query()
{
	int numFailed = 0;
	_ptrc_glBeginQueryARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBeginQueryARB");
	if(!_ptrc_glBeginQueryARB) numFailed++;
	_ptrc_glDeleteQueriesARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteQueriesARB");
	if(!_ptrc_glDeleteQueriesARB) numFailed++;
	_ptrc_glEndQueryARB = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glEndQueryARB");
	if(!_ptrc_glEndQueryARB) numFailed++;
	_ptrc_glGenQueriesARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenQueriesARB");
	if(!_ptrc_glGenQueriesARB) numFailed++;
	_ptrc_glGetQueryObjectivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryObjectivARB");
	if(!_ptrc_glGetQueryObjectivARB) numFailed++;
	_ptrc_glGetQueryObjectuivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetQueryObjectuivARB");
	if(!_ptrc_glGetQueryObjectuivARB) numFailed++;
	_ptrc_glGetQueryivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetQueryivARB");
	if(!_ptrc_glGetQueryivARB) numFailed++;
	_ptrc_glIsQueryARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsQueryARB");
	if(!_ptrc_glIsQueryARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfARB)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvARB)(GLenum, const GLfloat *) = NULL;

static int Load_ARB_point_parameters()
{
	int numFailed = 0;
	_ptrc_glPointParameterfARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPointParameterfARB");
	if(!_ptrc_glPointParameterfARB) numFailed++;
	_ptrc_glPointParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPointParameterfvARB");
	if(!_ptrc_glPointParameterfvARB) numFailed++;
	return numFailed;
}

GLenum (CODEGEN_FUNCPTR *_ptrc_glGetGraphicsResetStatusARB)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnColorTableARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnCompressedTexImageARB)(GLenum, GLint, GLsizei, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnConvolutionFilterARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnHistogramARB)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMapdvARB)(GLenum, GLenum, GLsizei, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMapfvARB)(GLenum, GLenum, GLsizei, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMapivARB)(GLenum, GLenum, GLsizei, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnMinmaxARB)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapfvARB)(GLenum, GLsizei, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapuivARB)(GLenum, GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPixelMapusvARB)(GLenum, GLsizei, GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnPolygonStippleARB)(GLsizei, GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnSeparableFilterARB)(GLenum, GLenum, GLenum, GLsizei, GLvoid *, GLsizei, GLvoid *, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnTexImageARB)(GLenum, GLint, GLenum, GLenum, GLsizei, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformdvARB)(GLuint, GLint, GLsizei, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformfvARB)(GLuint, GLint, GLsizei, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformivARB)(GLuint, GLint, GLsizei, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetnUniformuivARB)(GLuint, GLint, GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadnPixelsARB)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid *) = NULL;

static int Load_ARB_robustness()
{
	int numFailed = 0;
	_ptrc_glGetGraphicsResetStatusARB = (GLenum (CODEGEN_FUNCPTR *)())IntGetProcAddress("glGetGraphicsResetStatusARB");
	if(!_ptrc_glGetGraphicsResetStatusARB) numFailed++;
	_ptrc_glGetnColorTableARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLvoid *))IntGetProcAddress("glGetnColorTableARB");
	if(!_ptrc_glGetnColorTableARB) numFailed++;
	_ptrc_glGetnCompressedTexImageARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLvoid *))IntGetProcAddress("glGetnCompressedTexImageARB");
	if(!_ptrc_glGetnCompressedTexImageARB) numFailed++;
	_ptrc_glGetnConvolutionFilterARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLvoid *))IntGetProcAddress("glGetnConvolutionFilterARB");
	if(!_ptrc_glGetnConvolutionFilterARB) numFailed++;
	_ptrc_glGetnHistogramARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *))IntGetProcAddress("glGetnHistogramARB");
	if(!_ptrc_glGetnHistogramARB) numFailed++;
	_ptrc_glGetnMapdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLdouble *))IntGetProcAddress("glGetnMapdvARB");
	if(!_ptrc_glGetnMapdvARB) numFailed++;
	_ptrc_glGetnMapfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLfloat *))IntGetProcAddress("glGetnMapfvARB");
	if(!_ptrc_glGetnMapfvARB) numFailed++;
	_ptrc_glGetnMapivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLint *))IntGetProcAddress("glGetnMapivARB");
	if(!_ptrc_glGetnMapivARB) numFailed++;
	_ptrc_glGetnMinmaxARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLsizei, GLvoid *))IntGetProcAddress("glGetnMinmaxARB");
	if(!_ptrc_glGetnMinmaxARB) numFailed++;
	_ptrc_glGetnPixelMapfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLfloat *))IntGetProcAddress("glGetnPixelMapfvARB");
	if(!_ptrc_glGetnPixelMapfvARB) numFailed++;
	_ptrc_glGetnPixelMapuivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLuint *))IntGetProcAddress("glGetnPixelMapuivARB");
	if(!_ptrc_glGetnPixelMapuivARB) numFailed++;
	_ptrc_glGetnPixelMapusvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLushort *))IntGetProcAddress("glGetnPixelMapusvARB");
	if(!_ptrc_glGetnPixelMapusvARB) numFailed++;
	_ptrc_glGetnPolygonStippleARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLubyte *))IntGetProcAddress("glGetnPolygonStippleARB");
	if(!_ptrc_glGetnPolygonStippleARB) numFailed++;
	_ptrc_glGetnSeparableFilterARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLvoid *, GLsizei, GLvoid *, GLvoid *))IntGetProcAddress("glGetnSeparableFilterARB");
	if(!_ptrc_glGetnSeparableFilterARB) numFailed++;
	_ptrc_glGetnTexImageARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLenum, GLsizei, GLvoid *))IntGetProcAddress("glGetnTexImageARB");
	if(!_ptrc_glGetnTexImageARB) numFailed++;
	_ptrc_glGetnUniformdvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLdouble *))IntGetProcAddress("glGetnUniformdvARB");
	if(!_ptrc_glGetnUniformdvARB) numFailed++;
	_ptrc_glGetnUniformfvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLfloat *))IntGetProcAddress("glGetnUniformfvARB");
	if(!_ptrc_glGetnUniformfvARB) numFailed++;
	_ptrc_glGetnUniformivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLint *))IntGetProcAddress("glGetnUniformivARB");
	if(!_ptrc_glGetnUniformivARB) numFailed++;
	_ptrc_glGetnUniformuivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLuint *))IntGetProcAddress("glGetnUniformuivARB");
	if(!_ptrc_glGetnUniformuivARB) numFailed++;
	_ptrc_glReadnPixelsARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, GLvoid *))IntGetProcAddress("glReadnPixelsARB");
	if(!_ptrc_glReadnPixelsARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShadingARB)(GLfloat) = NULL;

static int Load_ARB_sample_shading()
{
	int numFailed = 0;
	_ptrc_glMinSampleShadingARB = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glMinSampleShadingARB");
	if(!_ptrc_glMinSampleShadingARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glAttachObjectARB)(GLhandleARB, GLhandleARB) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderARB)(GLhandleARB) = NULL;
GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateProgramObjectARB)() = NULL;
GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glCreateShaderObjectARB)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteObjectARB)(GLhandleARB) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDetachObjectARB)(GLhandleARB, GLhandleARB) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniformARB)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedObjectsARB)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *) = NULL;
GLhandleARB (CODEGEN_FUNCPTR *_ptrc_glGetHandleARB)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInfoLogARB)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterfvARB)(GLhandleARB, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectParameterivARB)(GLhandleARB, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSourceARB)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocationARB)(GLhandleARB, const GLcharARB *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfvARB)(GLhandleARB, GLint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformivARB)(GLhandleARB, GLint, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLinkProgramARB)(GLhandleARB) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderSourceARB)(GLhandleARB, GLsizei, const GLcharARB **, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1fARB)(GLint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1fvARB)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1iARB)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ivARB)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2fARB)(GLint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2fvARB)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2iARB)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ivARB)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3fARB)(GLint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3fvARB)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3iARB)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ivARB)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4fARB)(GLint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4fvARB)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4iARB)(GLint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ivARB)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fvARB)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fvARB)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fvARB)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseProgramObjectARB)(GLhandleARB) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glValidateProgramARB)(GLhandleARB) = NULL;

static int Load_ARB_shader_objects()
{
	int numFailed = 0;
	_ptrc_glAttachObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLhandleARB))IntGetProcAddress("glAttachObjectARB");
	if(!_ptrc_glAttachObjectARB) numFailed++;
	_ptrc_glCompileShaderARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glCompileShaderARB");
	if(!_ptrc_glCompileShaderARB) numFailed++;
	_ptrc_glCreateProgramObjectARB = (GLhandleARB (CODEGEN_FUNCPTR *)())IntGetProcAddress("glCreateProgramObjectARB");
	if(!_ptrc_glCreateProgramObjectARB) numFailed++;
	_ptrc_glCreateShaderObjectARB = (GLhandleARB (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCreateShaderObjectARB");
	if(!_ptrc_glCreateShaderObjectARB) numFailed++;
	_ptrc_glDeleteObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glDeleteObjectARB");
	if(!_ptrc_glDeleteObjectARB) numFailed++;
	_ptrc_glDetachObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLhandleARB))IntGetProcAddress("glDetachObjectARB");
	if(!_ptrc_glDetachObjectARB) numFailed++;
	_ptrc_glGetActiveUniformARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *))IntGetProcAddress("glGetActiveUniformARB");
	if(!_ptrc_glGetActiveUniformARB) numFailed++;
	_ptrc_glGetAttachedObjectsARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, GLsizei *, GLhandleARB *))IntGetProcAddress("glGetAttachedObjectsARB");
	if(!_ptrc_glGetAttachedObjectsARB) numFailed++;
	_ptrc_glGetHandleARB = (GLhandleARB (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGetHandleARB");
	if(!_ptrc_glGetHandleARB) numFailed++;
	_ptrc_glGetInfoLogARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *))IntGetProcAddress("glGetInfoLogARB");
	if(!_ptrc_glGetInfoLogARB) numFailed++;
	_ptrc_glGetObjectParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLenum, GLfloat *))IntGetProcAddress("glGetObjectParameterfvARB");
	if(!_ptrc_glGetObjectParameterfvARB) numFailed++;
	_ptrc_glGetObjectParameterivARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLenum, GLint *))IntGetProcAddress("glGetObjectParameterivARB");
	if(!_ptrc_glGetObjectParameterivARB) numFailed++;
	_ptrc_glGetShaderSourceARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, GLsizei *, GLcharARB *))IntGetProcAddress("glGetShaderSourceARB");
	if(!_ptrc_glGetShaderSourceARB) numFailed++;
	_ptrc_glGetUniformLocationARB = (GLint (CODEGEN_FUNCPTR *)(GLhandleARB, const GLcharARB *))IntGetProcAddress("glGetUniformLocationARB");
	if(!_ptrc_glGetUniformLocationARB) numFailed++;
	_ptrc_glGetUniformfvARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLint, GLfloat *))IntGetProcAddress("glGetUniformfvARB");
	if(!_ptrc_glGetUniformfvARB) numFailed++;
	_ptrc_glGetUniformivARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLint, GLint *))IntGetProcAddress("glGetUniformivARB");
	if(!_ptrc_glGetUniformivARB) numFailed++;
	_ptrc_glLinkProgramARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glLinkProgramARB");
	if(!_ptrc_glLinkProgramARB) numFailed++;
	_ptrc_glShaderSourceARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLsizei, const GLcharARB **, const GLint *))IntGetProcAddress("glShaderSourceARB");
	if(!_ptrc_glShaderSourceARB) numFailed++;
	_ptrc_glUniform1fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat))IntGetProcAddress("glUniform1fARB");
	if(!_ptrc_glUniform1fARB) numFailed++;
	_ptrc_glUniform1fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform1fvARB");
	if(!_ptrc_glUniform1fvARB) numFailed++;
	_ptrc_glUniform1iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glUniform1iARB");
	if(!_ptrc_glUniform1iARB) numFailed++;
	_ptrc_glUniform1ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform1ivARB");
	if(!_ptrc_glUniform1ivARB) numFailed++;
	_ptrc_glUniform2fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat))IntGetProcAddress("glUniform2fARB");
	if(!_ptrc_glUniform2fARB) numFailed++;
	_ptrc_glUniform2fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform2fvARB");
	if(!_ptrc_glUniform2fvARB) numFailed++;
	_ptrc_glUniform2iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glUniform2iARB");
	if(!_ptrc_glUniform2iARB) numFailed++;
	_ptrc_glUniform2ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform2ivARB");
	if(!_ptrc_glUniform2ivARB) numFailed++;
	_ptrc_glUniform3fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform3fARB");
	if(!_ptrc_glUniform3fARB) numFailed++;
	_ptrc_glUniform3fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform3fvARB");
	if(!_ptrc_glUniform3fvARB) numFailed++;
	_ptrc_glUniform3iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform3iARB");
	if(!_ptrc_glUniform3iARB) numFailed++;
	_ptrc_glUniform3ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform3ivARB");
	if(!_ptrc_glUniform3ivARB) numFailed++;
	_ptrc_glUniform4fARB = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform4fARB");
	if(!_ptrc_glUniform4fARB) numFailed++;
	_ptrc_glUniform4fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform4fvARB");
	if(!_ptrc_glUniform4fvARB) numFailed++;
	_ptrc_glUniform4iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform4iARB");
	if(!_ptrc_glUniform4iARB) numFailed++;
	_ptrc_glUniform4ivARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform4ivARB");
	if(!_ptrc_glUniform4ivARB) numFailed++;
	_ptrc_glUniformMatrix2fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2fvARB");
	if(!_ptrc_glUniformMatrix2fvARB) numFailed++;
	_ptrc_glUniformMatrix3fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3fvARB");
	if(!_ptrc_glUniformMatrix3fvARB) numFailed++;
	_ptrc_glUniformMatrix4fvARB = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4fvARB");
	if(!_ptrc_glUniformMatrix4fvARB) numFailed++;
	_ptrc_glUseProgramObjectARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glUseProgramObjectARB");
	if(!_ptrc_glUseProgramObjectARB) numFailed++;
	_ptrc_glValidateProgramARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB))IntGetProcAddress("glValidateProgramARB");
	if(!_ptrc_glValidateProgramARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCompileShaderIncludeARB)(GLuint, GLsizei, const GLchar *const*, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteNamedStringARB)(GLint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringARB)(GLint, const GLchar *, GLsizei, GLint *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedStringivARB)(GLint, const GLchar *, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedStringARB)(GLint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedStringARB)(GLenum, GLint, const GLchar *, GLint, const GLchar *) = NULL;

static int Load_ARB_shading_language_include()
{
	int numFailed = 0;
	_ptrc_glCompileShaderIncludeARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, const GLint *))IntGetProcAddress("glCompileShaderIncludeARB");
	if(!_ptrc_glCompileShaderIncludeARB) numFailed++;
	_ptrc_glDeleteNamedStringARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLchar *))IntGetProcAddress("glDeleteNamedStringARB");
	if(!_ptrc_glDeleteNamedStringARB) numFailed++;
	_ptrc_glGetNamedStringARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLchar *, GLsizei, GLint *, GLchar *))IntGetProcAddress("glGetNamedStringARB");
	if(!_ptrc_glGetNamedStringARB) numFailed++;
	_ptrc_glGetNamedStringivARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLchar *, GLenum, GLint *))IntGetProcAddress("glGetNamedStringivARB");
	if(!_ptrc_glGetNamedStringivARB) numFailed++;
	_ptrc_glIsNamedStringARB = (GLboolean (CODEGEN_FUNCPTR *)(GLint, const GLchar *))IntGetProcAddress("glIsNamedStringARB");
	if(!_ptrc_glIsNamedStringARB) numFailed++;
	_ptrc_glNamedStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLchar *, GLint, const GLchar *))IntGetProcAddress("glNamedStringARB");
	if(!_ptrc_glNamedStringARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexPageCommitmentARB)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;

static int Load_ARB_sparse_texture()
{
	int numFailed = 0;
	_ptrc_glTexPageCommitmentARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexPageCommitmentARB");
	if(!_ptrc_glTexPageCommitmentARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexBufferARB)(GLenum, GLenum, GLuint) = NULL;

static int Load_ARB_texture_buffer_object()
{
	int numFailed = 0;
	_ptrc_glTexBufferARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glTexBufferARB");
	if(!_ptrc_glTexBufferARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1DARB)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2DARB)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3DARB)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1DARB)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2DARB)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3DARB)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImageARB)(GLenum, GLint, GLvoid *) = NULL;

static int Load_ARB_texture_compression()
{
	int numFailed = 0;
	_ptrc_glCompressedTexImage1DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexImage1DARB");
	if(!_ptrc_glCompressedTexImage1DARB) numFailed++;
	_ptrc_glCompressedTexImage2DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexImage2DARB");
	if(!_ptrc_glCompressedTexImage2DARB) numFailed++;
	_ptrc_glCompressedTexImage3DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexImage3DARB");
	if(!_ptrc_glCompressedTexImage3DARB) numFailed++;
	_ptrc_glCompressedTexSubImage1DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexSubImage1DARB");
	if(!_ptrc_glCompressedTexSubImage1DARB) numFailed++;
	_ptrc_glCompressedTexSubImage2DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexSubImage2DARB");
	if(!_ptrc_glCompressedTexSubImage2DARB) numFailed++;
	_ptrc_glCompressedTexSubImage3DARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexSubImage3DARB");
	if(!_ptrc_glCompressedTexSubImage3DARB) numFailed++;
	_ptrc_glGetCompressedTexImageARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLvoid *))IntGetProcAddress("glGetCompressedTexImageARB");
	if(!_ptrc_glGetCompressedTexImageARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixdARB)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixfARB)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixdARB)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixfARB)(const GLfloat *) = NULL;

static int Load_ARB_transpose_matrix()
{
	int numFailed = 0;
	_ptrc_glLoadTransposeMatrixdARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glLoadTransposeMatrixdARB");
	if(!_ptrc_glLoadTransposeMatrixdARB) numFailed++;
	_ptrc_glLoadTransposeMatrixfARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glLoadTransposeMatrixfARB");
	if(!_ptrc_glLoadTransposeMatrixfARB) numFailed++;
	_ptrc_glMultTransposeMatrixdARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glMultTransposeMatrixdARB");
	if(!_ptrc_glMultTransposeMatrixdARB) numFailed++;
	_ptrc_glMultTransposeMatrixfARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glMultTransposeMatrixfARB");
	if(!_ptrc_glMultTransposeMatrixfARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glVertexBlendARB)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightPointerARB)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightbvARB)(GLint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightdvARB)(GLint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightfvARB)(GLint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightivARB)(GLint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightsvARB)(GLint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightubvARB)(GLint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightuivARB)(GLint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightusvARB)(GLint, const GLushort *) = NULL;

static int Load_ARB_vertex_blend()
{
	int numFailed = 0;
	_ptrc_glVertexBlendARB = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glVertexBlendARB");
	if(!_ptrc_glVertexBlendARB) numFailed++;
	_ptrc_glWeightPointerARB = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glWeightPointerARB");
	if(!_ptrc_glWeightPointerARB) numFailed++;
	_ptrc_glWeightbvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLbyte *))IntGetProcAddress("glWeightbvARB");
	if(!_ptrc_glWeightbvARB) numFailed++;
	_ptrc_glWeightdvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLdouble *))IntGetProcAddress("glWeightdvARB");
	if(!_ptrc_glWeightdvARB) numFailed++;
	_ptrc_glWeightfvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLfloat *))IntGetProcAddress("glWeightfvARB");
	if(!_ptrc_glWeightfvARB) numFailed++;
	_ptrc_glWeightivARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLint *))IntGetProcAddress("glWeightivARB");
	if(!_ptrc_glWeightivARB) numFailed++;
	_ptrc_glWeightsvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLshort *))IntGetProcAddress("glWeightsvARB");
	if(!_ptrc_glWeightsvARB) numFailed++;
	_ptrc_glWeightubvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLubyte *))IntGetProcAddress("glWeightubvARB");
	if(!_ptrc_glWeightubvARB) numFailed++;
	_ptrc_glWeightuivARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLuint *))IntGetProcAddress("glWeightuivARB");
	if(!_ptrc_glWeightuivARB) numFailed++;
	_ptrc_glWeightusvARB = (void (CODEGEN_FUNCPTR *)(GLint, const GLushort *))IntGetProcAddress("glWeightusvARB");
	if(!_ptrc_glWeightusvARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindBufferARB)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferDataARB)(GLenum, GLsizeiptrARB, const GLvoid *, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferSubDataARB)(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffersARB)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenBuffersARB)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterivARB)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointervARB)(GLenum, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubDataARB)(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferARB)(GLuint) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapBufferARB)(GLenum, GLenum) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBufferARB)(GLenum) = NULL;

static int Load_ARB_vertex_buffer_object()
{
	int numFailed = 0;
	_ptrc_glBindBufferARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindBufferARB");
	if(!_ptrc_glBindBufferARB) numFailed++;
	_ptrc_glBufferDataARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptrARB, const GLvoid *, GLenum))IntGetProcAddress("glBufferDataARB");
	if(!_ptrc_glBufferDataARB) numFailed++;
	_ptrc_glBufferSubDataARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptrARB, GLsizeiptrARB, const GLvoid *))IntGetProcAddress("glBufferSubDataARB");
	if(!_ptrc_glBufferSubDataARB) numFailed++;
	_ptrc_glDeleteBuffersARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteBuffersARB");
	if(!_ptrc_glDeleteBuffersARB) numFailed++;
	_ptrc_glGenBuffersARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenBuffersARB");
	if(!_ptrc_glGenBuffersARB) numFailed++;
	_ptrc_glGetBufferParameterivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetBufferParameterivARB");
	if(!_ptrc_glGetBufferParameterivARB) numFailed++;
	_ptrc_glGetBufferPointervARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLvoid **))IntGetProcAddress("glGetBufferPointervARB");
	if(!_ptrc_glGetBufferPointervARB) numFailed++;
	_ptrc_glGetBufferSubDataARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptrARB, GLsizeiptrARB, GLvoid *))IntGetProcAddress("glGetBufferSubDataARB");
	if(!_ptrc_glGetBufferSubDataARB) numFailed++;
	_ptrc_glIsBufferARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsBufferARB");
	if(!_ptrc_glIsBufferARB) numFailed++;
	_ptrc_glMapBufferARB = (void * (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glMapBufferARB");
	if(!_ptrc_glMapBufferARB) numFailed++;
	_ptrc_glUnmapBufferARB = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glUnmapBufferARB");
	if(!_ptrc_glUnmapBufferARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArrayARB)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArrayARB)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervARB)(GLuint, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvARB)(GLuint, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvARB)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivARB)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dARB)(GLuint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvARB)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fARB)(GLuint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvARB)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sARB)(GLuint, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svARB)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dARB)(GLuint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvARB)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fARB)(GLuint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvARB)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sARB)(GLuint, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svARB)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dARB)(GLuint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvARB)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fARB)(GLuint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvARB)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sARB)(GLuint, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svARB)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NbvARB)(GLuint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NivARB)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NsvARB)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubARB)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NubvARB)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NuivARB)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4NusvARB)(GLuint, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bvARB)(GLuint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dARB)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvARB)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fARB)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvARB)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ivARB)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sARB)(GLuint, GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svARB)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvARB)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uivARB)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usvARB)(GLuint, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerARB)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *) = NULL;

static int Load_ARB_vertex_program()
{
	int numFailed = 0;
	_ptrc_glBindProgramARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindProgramARB");
	if(!_ptrc_glBindProgramARB) numFailed++;
	_ptrc_glDeleteProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramsARB");
	if(!_ptrc_glDeleteProgramsARB) numFailed++;
	_ptrc_glDisableVertexAttribArrayARB = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDisableVertexAttribArrayARB");
	if(!_ptrc_glDisableVertexAttribArrayARB) numFailed++;
	_ptrc_glEnableVertexAttribArrayARB = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEnableVertexAttribArrayARB");
	if(!_ptrc_glEnableVertexAttribArrayARB) numFailed++;
	_ptrc_glGenProgramsARB = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramsARB");
	if(!_ptrc_glGenProgramsARB) numFailed++;
	_ptrc_glGetProgramEnvParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramEnvParameterdvARB");
	if(!_ptrc_glGetProgramEnvParameterdvARB) numFailed++;
	_ptrc_glGetProgramEnvParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramEnvParameterfvARB");
	if(!_ptrc_glGetProgramEnvParameterfvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterdvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetProgramLocalParameterdvARB");
	if(!_ptrc_glGetProgramLocalParameterdvARB) numFailed++;
	_ptrc_glGetProgramLocalParameterfvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetProgramLocalParameterfvARB");
	if(!_ptrc_glGetProgramLocalParameterfvARB) numFailed++;
	_ptrc_glGetProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetProgramStringARB");
	if(!_ptrc_glGetProgramStringARB) numFailed++;
	_ptrc_glGetProgramivARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramivARB");
	if(!_ptrc_glGetProgramivARB) numFailed++;
	_ptrc_glGetVertexAttribPointervARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLvoid **))IntGetProcAddress("glGetVertexAttribPointervARB");
	if(!_ptrc_glGetVertexAttribPointervARB) numFailed++;
	_ptrc_glGetVertexAttribdvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribdvARB");
	if(!_ptrc_glGetVertexAttribdvARB) numFailed++;
	_ptrc_glGetVertexAttribfvARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribfvARB");
	if(!_ptrc_glGetVertexAttribfvARB) numFailed++;
	_ptrc_glGetVertexAttribivARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribivARB");
	if(!_ptrc_glGetVertexAttribivARB) numFailed++;
	_ptrc_glIsProgramARB = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramARB");
	if(!_ptrc_glIsProgramARB) numFailed++;
	_ptrc_glProgramEnvParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramEnvParameter4dARB");
	if(!_ptrc_glProgramEnvParameter4dARB) numFailed++;
	_ptrc_glProgramEnvParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramEnvParameter4dvARB");
	if(!_ptrc_glProgramEnvParameter4dvARB) numFailed++;
	_ptrc_glProgramEnvParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramEnvParameter4fARB");
	if(!_ptrc_glProgramEnvParameter4fARB) numFailed++;
	_ptrc_glProgramEnvParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramEnvParameter4fvARB");
	if(!_ptrc_glProgramEnvParameter4fvARB) numFailed++;
	_ptrc_glProgramLocalParameter4dARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramLocalParameter4dARB");
	if(!_ptrc_glProgramLocalParameter4dARB) numFailed++;
	_ptrc_glProgramLocalParameter4dvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramLocalParameter4dvARB");
	if(!_ptrc_glProgramLocalParameter4dvARB) numFailed++;
	_ptrc_glProgramLocalParameter4fARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramLocalParameter4fARB");
	if(!_ptrc_glProgramLocalParameter4fARB) numFailed++;
	_ptrc_glProgramLocalParameter4fvARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramLocalParameter4fvARB");
	if(!_ptrc_glProgramLocalParameter4fvARB) numFailed++;
	_ptrc_glProgramStringARB = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glProgramStringARB");
	if(!_ptrc_glProgramStringARB) numFailed++;
	_ptrc_glVertexAttrib1dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttrib1dARB");
	if(!_ptrc_glVertexAttrib1dARB) numFailed++;
	_ptrc_glVertexAttrib1dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib1dvARB");
	if(!_ptrc_glVertexAttrib1dvARB) numFailed++;
	_ptrc_glVertexAttrib1fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat))IntGetProcAddress("glVertexAttrib1fARB");
	if(!_ptrc_glVertexAttrib1fARB) numFailed++;
	_ptrc_glVertexAttrib1fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib1fvARB");
	if(!_ptrc_glVertexAttrib1fvARB) numFailed++;
	_ptrc_glVertexAttrib1sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort))IntGetProcAddress("glVertexAttrib1sARB");
	if(!_ptrc_glVertexAttrib1sARB) numFailed++;
	_ptrc_glVertexAttrib1svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib1svARB");
	if(!_ptrc_glVertexAttrib1svARB) numFailed++;
	_ptrc_glVertexAttrib2dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib2dARB");
	if(!_ptrc_glVertexAttrib2dARB) numFailed++;
	_ptrc_glVertexAttrib2dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib2dvARB");
	if(!_ptrc_glVertexAttrib2dvARB) numFailed++;
	_ptrc_glVertexAttrib2fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib2fARB");
	if(!_ptrc_glVertexAttrib2fARB) numFailed++;
	_ptrc_glVertexAttrib2fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib2fvARB");
	if(!_ptrc_glVertexAttrib2fvARB) numFailed++;
	_ptrc_glVertexAttrib2sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort))IntGetProcAddress("glVertexAttrib2sARB");
	if(!_ptrc_glVertexAttrib2sARB) numFailed++;
	_ptrc_glVertexAttrib2svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib2svARB");
	if(!_ptrc_glVertexAttrib2svARB) numFailed++;
	_ptrc_glVertexAttrib3dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib3dARB");
	if(!_ptrc_glVertexAttrib3dARB) numFailed++;
	_ptrc_glVertexAttrib3dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib3dvARB");
	if(!_ptrc_glVertexAttrib3dvARB) numFailed++;
	_ptrc_glVertexAttrib3fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib3fARB");
	if(!_ptrc_glVertexAttrib3fARB) numFailed++;
	_ptrc_glVertexAttrib3fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib3fvARB");
	if(!_ptrc_glVertexAttrib3fvARB) numFailed++;
	_ptrc_glVertexAttrib3sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib3sARB");
	if(!_ptrc_glVertexAttrib3sARB) numFailed++;
	_ptrc_glVertexAttrib3svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib3svARB");
	if(!_ptrc_glVertexAttrib3svARB) numFailed++;
	_ptrc_glVertexAttrib4NbvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4NbvARB");
	if(!_ptrc_glVertexAttrib4NbvARB) numFailed++;
	_ptrc_glVertexAttrib4NivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4NivARB");
	if(!_ptrc_glVertexAttrib4NivARB) numFailed++;
	_ptrc_glVertexAttrib4NsvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4NsvARB");
	if(!_ptrc_glVertexAttrib4NsvARB) numFailed++;
	_ptrc_glVertexAttrib4NubARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glVertexAttrib4NubARB");
	if(!_ptrc_glVertexAttrib4NubARB) numFailed++;
	_ptrc_glVertexAttrib4NubvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4NubvARB");
	if(!_ptrc_glVertexAttrib4NubvARB) numFailed++;
	_ptrc_glVertexAttrib4NuivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4NuivARB");
	if(!_ptrc_glVertexAttrib4NuivARB) numFailed++;
	_ptrc_glVertexAttrib4NusvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4NusvARB");
	if(!_ptrc_glVertexAttrib4NusvARB) numFailed++;
	_ptrc_glVertexAttrib4bvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4bvARB");
	if(!_ptrc_glVertexAttrib4bvARB) numFailed++;
	_ptrc_glVertexAttrib4dARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib4dARB");
	if(!_ptrc_glVertexAttrib4dARB) numFailed++;
	_ptrc_glVertexAttrib4dvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib4dvARB");
	if(!_ptrc_glVertexAttrib4dvARB) numFailed++;
	_ptrc_glVertexAttrib4fARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib4fARB");
	if(!_ptrc_glVertexAttrib4fARB) numFailed++;
	_ptrc_glVertexAttrib4fvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib4fvARB");
	if(!_ptrc_glVertexAttrib4fvARB) numFailed++;
	_ptrc_glVertexAttrib4ivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4ivARB");
	if(!_ptrc_glVertexAttrib4ivARB) numFailed++;
	_ptrc_glVertexAttrib4sARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib4sARB");
	if(!_ptrc_glVertexAttrib4sARB) numFailed++;
	_ptrc_glVertexAttrib4svARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4svARB");
	if(!_ptrc_glVertexAttrib4svARB) numFailed++;
	_ptrc_glVertexAttrib4ubvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4ubvARB");
	if(!_ptrc_glVertexAttrib4ubvARB) numFailed++;
	_ptrc_glVertexAttrib4uivARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4uivARB");
	if(!_ptrc_glVertexAttrib4uivARB) numFailed++;
	_ptrc_glVertexAttrib4usvARB = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4usvARB");
	if(!_ptrc_glVertexAttrib4usvARB) numFailed++;
	_ptrc_glVertexAttribPointerARB = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribPointerARB");
	if(!_ptrc_glVertexAttribPointerARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocationARB)(GLhandleARB, GLuint, const GLcharARB *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttribARB)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocationARB)(GLhandleARB, const GLcharARB *) = NULL;

static int Load_ARB_vertex_shader()
{
	int numFailed = 0;
	_ptrc_glBindAttribLocationARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLuint, const GLcharARB *))IntGetProcAddress("glBindAttribLocationARB");
	if(!_ptrc_glBindAttribLocationARB) numFailed++;
	_ptrc_glGetActiveAttribARB = (void (CODEGEN_FUNCPTR *)(GLhandleARB, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLcharARB *))IntGetProcAddress("glGetActiveAttribARB");
	if(!_ptrc_glGetActiveAttribARB) numFailed++;
	_ptrc_glGetAttribLocationARB = (GLint (CODEGEN_FUNCPTR *)(GLhandleARB, const GLcharARB *))IntGetProcAddress("glGetAttribLocationARB");
	if(!_ptrc_glGetAttribLocationARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dARB)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dvARB)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fARB)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fvARB)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iARB)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2ivARB)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sARB)(GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2svARB)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dARB)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dvARB)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fARB)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fvARB)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iARB)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3ivARB)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sARB)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3svARB)(const GLshort *) = NULL;

static int Load_ARB_window_pos()
{
	int numFailed = 0;
	_ptrc_glWindowPos2dARB = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glWindowPos2dARB");
	if(!_ptrc_glWindowPos2dARB) numFailed++;
	_ptrc_glWindowPos2dvARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos2dvARB");
	if(!_ptrc_glWindowPos2dvARB) numFailed++;
	_ptrc_glWindowPos2fARB = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glWindowPos2fARB");
	if(!_ptrc_glWindowPos2fARB) numFailed++;
	_ptrc_glWindowPos2fvARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos2fvARB");
	if(!_ptrc_glWindowPos2fvARB) numFailed++;
	_ptrc_glWindowPos2iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glWindowPos2iARB");
	if(!_ptrc_glWindowPos2iARB) numFailed++;
	_ptrc_glWindowPos2ivARB = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos2ivARB");
	if(!_ptrc_glWindowPos2ivARB) numFailed++;
	_ptrc_glWindowPos2sARB = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort))IntGetProcAddress("glWindowPos2sARB");
	if(!_ptrc_glWindowPos2sARB) numFailed++;
	_ptrc_glWindowPos2svARB = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos2svARB");
	if(!_ptrc_glWindowPos2svARB) numFailed++;
	_ptrc_glWindowPos3dARB = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glWindowPos3dARB");
	if(!_ptrc_glWindowPos3dARB) numFailed++;
	_ptrc_glWindowPos3dvARB = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos3dvARB");
	if(!_ptrc_glWindowPos3dvARB) numFailed++;
	_ptrc_glWindowPos3fARB = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glWindowPos3fARB");
	if(!_ptrc_glWindowPos3fARB) numFailed++;
	_ptrc_glWindowPos3fvARB = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos3fvARB");
	if(!_ptrc_glWindowPos3fvARB) numFailed++;
	_ptrc_glWindowPos3iARB = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glWindowPos3iARB");
	if(!_ptrc_glWindowPos3iARB) numFailed++;
	_ptrc_glWindowPos3ivARB = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos3ivARB");
	if(!_ptrc_glWindowPos3ivARB) numFailed++;
	_ptrc_glWindowPos3sARB = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glWindowPos3sARB");
	if(!_ptrc_glWindowPos3sARB) numFailed++;
	_ptrc_glWindowPos3svARB = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos3svARB");
	if(!_ptrc_glWindowPos3svARB) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffersATI)(GLsizei, const GLenum *) = NULL;

static int Load_ATI_draw_buffers()
{
	int numFailed = 0;
	_ptrc_glDrawBuffersATI = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLenum *))IntGetProcAddress("glDrawBuffersATI");
	if(!_ptrc_glDrawBuffersATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawElementArrayATI)(GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementArrayATI)(GLenum, GLuint, GLuint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glElementPointerATI)(GLenum, const GLvoid *) = NULL;

static int Load_ATI_element_array()
{
	int numFailed = 0;
	_ptrc_glDrawElementArrayATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei))IntGetProcAddress("glDrawElementArrayATI");
	if(!_ptrc_glDrawElementArrayATI) numFailed++;
	_ptrc_glDrawRangeElementArrayATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei))IntGetProcAddress("glDrawRangeElementArrayATI");
	if(!_ptrc_glDrawRangeElementArrayATI) numFailed++;
	_ptrc_glElementPointerATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid *))IntGetProcAddress("glElementPointerATI");
	if(!_ptrc_glElementPointerATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetTexBumpParameterfvATI)(GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexBumpParameterivATI)(GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexBumpParameterfvATI)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexBumpParameterivATI)(GLenum, const GLint *) = NULL;

static int Load_ATI_envmap_bumpmap()
{
	int numFailed = 0;
	_ptrc_glGetTexBumpParameterfvATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetTexBumpParameterfvATI");
	if(!_ptrc_glGetTexBumpParameterfvATI) numFailed++;
	_ptrc_glGetTexBumpParameterivATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint *))IntGetProcAddress("glGetTexBumpParameterivATI");
	if(!_ptrc_glGetTexBumpParameterivATI) numFailed++;
	_ptrc_glTexBumpParameterfvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glTexBumpParameterfvATI");
	if(!_ptrc_glTexBumpParameterfvATI) numFailed++;
	_ptrc_glTexBumpParameterivATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glTexBumpParameterivATI");
	if(!_ptrc_glTexBumpParameterivATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glAlphaFragmentOp1ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glAlphaFragmentOp2ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glAlphaFragmentOp3ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBeginFragmentShaderATI)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindFragmentShaderATI)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorFragmentOp1ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorFragmentOp2ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorFragmentOp3ATI)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteFragmentShaderATI)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndFragmentShaderATI)() = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGenFragmentShadersATI)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPassTexCoordATI)(GLuint, GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleMapATI)(GLuint, GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSetFragmentShaderConstantATI)(GLuint, const GLfloat *) = NULL;

static int Load_ATI_fragment_shader()
{
	int numFailed = 0;
	_ptrc_glAlphaFragmentOp1ATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glAlphaFragmentOp1ATI");
	if(!_ptrc_glAlphaFragmentOp1ATI) numFailed++;
	_ptrc_glAlphaFragmentOp2ATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glAlphaFragmentOp2ATI");
	if(!_ptrc_glAlphaFragmentOp2ATI) numFailed++;
	_ptrc_glAlphaFragmentOp3ATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glAlphaFragmentOp3ATI");
	if(!_ptrc_glAlphaFragmentOp3ATI) numFailed++;
	_ptrc_glBeginFragmentShaderATI = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glBeginFragmentShaderATI");
	if(!_ptrc_glBeginFragmentShaderATI) numFailed++;
	_ptrc_glBindFragmentShaderATI = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindFragmentShaderATI");
	if(!_ptrc_glBindFragmentShaderATI) numFailed++;
	_ptrc_glColorFragmentOp1ATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glColorFragmentOp1ATI");
	if(!_ptrc_glColorFragmentOp1ATI) numFailed++;
	_ptrc_glColorFragmentOp2ATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glColorFragmentOp2ATI");
	if(!_ptrc_glColorFragmentOp2ATI) numFailed++;
	_ptrc_glColorFragmentOp3ATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glColorFragmentOp3ATI");
	if(!_ptrc_glColorFragmentOp3ATI) numFailed++;
	_ptrc_glDeleteFragmentShaderATI = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDeleteFragmentShaderATI");
	if(!_ptrc_glDeleteFragmentShaderATI) numFailed++;
	_ptrc_glEndFragmentShaderATI = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndFragmentShaderATI");
	if(!_ptrc_glEndFragmentShaderATI) numFailed++;
	_ptrc_glGenFragmentShadersATI = (GLuint (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glGenFragmentShadersATI");
	if(!_ptrc_glGenFragmentShadersATI) numFailed++;
	_ptrc_glPassTexCoordATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum))IntGetProcAddress("glPassTexCoordATI");
	if(!_ptrc_glPassTexCoordATI) numFailed++;
	_ptrc_glSampleMapATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum))IntGetProcAddress("glSampleMapATI");
	if(!_ptrc_glSampleMapATI) numFailed++;
	_ptrc_glSetFragmentShaderConstantATI = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glSetFragmentShaderConstantATI");
	if(!_ptrc_glSetFragmentShaderConstantATI) numFailed++;
	return numFailed;
}

void * (CODEGEN_FUNCPTR *_ptrc_glMapObjectBufferATI)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUnmapObjectBufferATI)(GLuint) = NULL;

static int Load_ATI_map_object_buffer()
{
	int numFailed = 0;
	_ptrc_glMapObjectBufferATI = (void * (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glMapObjectBufferATI");
	if(!_ptrc_glMapObjectBufferATI) numFailed++;
	_ptrc_glUnmapObjectBufferATI = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glUnmapObjectBufferATI");
	if(!_ptrc_glUnmapObjectBufferATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPNTrianglesfATI)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPNTrianglesiATI)(GLenum, GLint) = NULL;

static int Load_ATI_pn_triangles()
{
	int numFailed = 0;
	_ptrc_glPNTrianglesfATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPNTrianglesfATI");
	if(!_ptrc_glPNTrianglesfATI) numFailed++;
	_ptrc_glPNTrianglesiATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPNTrianglesiATI");
	if(!_ptrc_glPNTrianglesiATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glStencilFuncSeparateATI)(GLenum, GLenum, GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilOpSeparateATI)(GLenum, GLenum, GLenum, GLenum) = NULL;

static int Load_ATI_separate_stencil()
{
	int numFailed = 0;
	_ptrc_glStencilFuncSeparateATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLuint))IntGetProcAddress("glStencilFuncSeparateATI");
	if(!_ptrc_glStencilFuncSeparateATI) numFailed++;
	_ptrc_glStencilOpSeparateATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glStencilOpSeparateATI");
	if(!_ptrc_glStencilOpSeparateATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glArrayObjectATI)(GLenum, GLint, GLenum, GLsizei, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFreeObjectBufferATI)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetArrayObjectfvATI)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetArrayObjectivATI)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectBufferfvATI)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetObjectBufferivATI)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVariantArrayObjectfvATI)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVariantArrayObjectivATI)(GLuint, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsObjectBufferATI)(GLuint) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glNewObjectBufferATI)(GLsizei, const GLvoid *, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUpdateObjectBufferATI)(GLuint, GLuint, GLsizei, const GLvoid *, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantArrayObjectATI)(GLuint, GLenum, GLsizei, GLuint, GLuint) = NULL;

static int Load_ATI_vertex_array_object()
{
	int numFailed = 0;
	_ptrc_glArrayObjectATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLuint, GLuint))IntGetProcAddress("glArrayObjectATI");
	if(!_ptrc_glArrayObjectATI) numFailed++;
	_ptrc_glFreeObjectBufferATI = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glFreeObjectBufferATI");
	if(!_ptrc_glFreeObjectBufferATI) numFailed++;
	_ptrc_glGetArrayObjectfvATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetArrayObjectfvATI");
	if(!_ptrc_glGetArrayObjectfvATI) numFailed++;
	_ptrc_glGetArrayObjectivATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetArrayObjectivATI");
	if(!_ptrc_glGetArrayObjectivATI) numFailed++;
	_ptrc_glGetObjectBufferfvATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetObjectBufferfvATI");
	if(!_ptrc_glGetObjectBufferfvATI) numFailed++;
	_ptrc_glGetObjectBufferivATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetObjectBufferivATI");
	if(!_ptrc_glGetObjectBufferivATI) numFailed++;
	_ptrc_glGetVariantArrayObjectfvATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVariantArrayObjectfvATI");
	if(!_ptrc_glGetVariantArrayObjectfvATI) numFailed++;
	_ptrc_glGetVariantArrayObjectivATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVariantArrayObjectivATI");
	if(!_ptrc_glGetVariantArrayObjectivATI) numFailed++;
	_ptrc_glIsObjectBufferATI = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsObjectBufferATI");
	if(!_ptrc_glIsObjectBufferATI) numFailed++;
	_ptrc_glNewObjectBufferATI = (GLuint (CODEGEN_FUNCPTR *)(GLsizei, const GLvoid *, GLenum))IntGetProcAddress("glNewObjectBufferATI");
	if(!_ptrc_glNewObjectBufferATI) numFailed++;
	_ptrc_glUpdateObjectBufferATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, const GLvoid *, GLenum))IntGetProcAddress("glUpdateObjectBufferATI");
	if(!_ptrc_glUpdateObjectBufferATI) numFailed++;
	_ptrc_glVariantArrayObjectATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLuint, GLuint))IntGetProcAddress("glVariantArrayObjectATI");
	if(!_ptrc_glVariantArrayObjectATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribArrayObjectfvATI)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribArrayObjectivATI)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribArrayObjectATI)(GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint) = NULL;

static int Load_ATI_vertex_attrib_array_object()
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribArrayObjectfvATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribArrayObjectfvATI");
	if(!_ptrc_glGetVertexAttribArrayObjectfvATI) numFailed++;
	_ptrc_glGetVertexAttribArrayObjectivATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribArrayObjectivATI");
	if(!_ptrc_glGetVertexAttribArrayObjectivATI) numFailed++;
	_ptrc_glVertexAttribArrayObjectATI = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei, GLuint, GLuint))IntGetProcAddress("glVertexAttribArrayObjectATI");
	if(!_ptrc_glVertexAttribArrayObjectATI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClientActiveVertexStreamATI)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3bATI)(GLenum, GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3bvATI)(GLenum, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3dATI)(GLenum, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3dvATI)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3fATI)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3fvATI)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3iATI)(GLenum, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3ivATI)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3sATI)(GLenum, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalStream3svATI)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexBlendEnvfATI)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexBlendEnviATI)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1dATI)(GLenum, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1dvATI)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1fATI)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1fvATI)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1iATI)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1ivATI)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1sATI)(GLenum, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream1svATI)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2dATI)(GLenum, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2dvATI)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2fATI)(GLenum, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2fvATI)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2iATI)(GLenum, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2ivATI)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2sATI)(GLenum, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream2svATI)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3dATI)(GLenum, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3dvATI)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3fATI)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3fvATI)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3iATI)(GLenum, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3ivATI)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3sATI)(GLenum, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream3svATI)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4dATI)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4dvATI)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4fATI)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4fvATI)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4iATI)(GLenum, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4ivATI)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4sATI)(GLenum, GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexStream4svATI)(GLenum, const GLshort *) = NULL;

static int Load_ATI_vertex_streams()
{
	int numFailed = 0;
	_ptrc_glClientActiveVertexStreamATI = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glClientActiveVertexStreamATI");
	if(!_ptrc_glClientActiveVertexStreamATI) numFailed++;
	_ptrc_glNormalStream3bATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLbyte, GLbyte, GLbyte))IntGetProcAddress("glNormalStream3bATI");
	if(!_ptrc_glNormalStream3bATI) numFailed++;
	_ptrc_glNormalStream3bvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLbyte *))IntGetProcAddress("glNormalStream3bvATI");
	if(!_ptrc_glNormalStream3bvATI) numFailed++;
	_ptrc_glNormalStream3dATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glNormalStream3dATI");
	if(!_ptrc_glNormalStream3dATI) numFailed++;
	_ptrc_glNormalStream3dvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glNormalStream3dvATI");
	if(!_ptrc_glNormalStream3dvATI) numFailed++;
	_ptrc_glNormalStream3fATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glNormalStream3fATI");
	if(!_ptrc_glNormalStream3fATI) numFailed++;
	_ptrc_glNormalStream3fvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glNormalStream3fvATI");
	if(!_ptrc_glNormalStream3fvATI) numFailed++;
	_ptrc_glNormalStream3iATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint))IntGetProcAddress("glNormalStream3iATI");
	if(!_ptrc_glNormalStream3iATI) numFailed++;
	_ptrc_glNormalStream3ivATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glNormalStream3ivATI");
	if(!_ptrc_glNormalStream3ivATI) numFailed++;
	_ptrc_glNormalStream3sATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort))IntGetProcAddress("glNormalStream3sATI");
	if(!_ptrc_glNormalStream3sATI) numFailed++;
	_ptrc_glNormalStream3svATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glNormalStream3svATI");
	if(!_ptrc_glNormalStream3svATI) numFailed++;
	_ptrc_glVertexBlendEnvfATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glVertexBlendEnvfATI");
	if(!_ptrc_glVertexBlendEnvfATI) numFailed++;
	_ptrc_glVertexBlendEnviATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glVertexBlendEnviATI");
	if(!_ptrc_glVertexBlendEnviATI) numFailed++;
	_ptrc_glVertexStream1dATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble))IntGetProcAddress("glVertexStream1dATI");
	if(!_ptrc_glVertexStream1dATI) numFailed++;
	_ptrc_glVertexStream1dvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glVertexStream1dvATI");
	if(!_ptrc_glVertexStream1dvATI) numFailed++;
	_ptrc_glVertexStream1fATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glVertexStream1fATI");
	if(!_ptrc_glVertexStream1fATI) numFailed++;
	_ptrc_glVertexStream1fvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glVertexStream1fvATI");
	if(!_ptrc_glVertexStream1fvATI) numFailed++;
	_ptrc_glVertexStream1iATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glVertexStream1iATI");
	if(!_ptrc_glVertexStream1iATI) numFailed++;
	_ptrc_glVertexStream1ivATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glVertexStream1ivATI");
	if(!_ptrc_glVertexStream1ivATI) numFailed++;
	_ptrc_glVertexStream1sATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort))IntGetProcAddress("glVertexStream1sATI");
	if(!_ptrc_glVertexStream1sATI) numFailed++;
	_ptrc_glVertexStream1svATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glVertexStream1svATI");
	if(!_ptrc_glVertexStream1svATI) numFailed++;
	_ptrc_glVertexStream2dATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble))IntGetProcAddress("glVertexStream2dATI");
	if(!_ptrc_glVertexStream2dATI) numFailed++;
	_ptrc_glVertexStream2dvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glVertexStream2dvATI");
	if(!_ptrc_glVertexStream2dvATI) numFailed++;
	_ptrc_glVertexStream2fATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat))IntGetProcAddress("glVertexStream2fATI");
	if(!_ptrc_glVertexStream2fATI) numFailed++;
	_ptrc_glVertexStream2fvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glVertexStream2fvATI");
	if(!_ptrc_glVertexStream2fvATI) numFailed++;
	_ptrc_glVertexStream2iATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint))IntGetProcAddress("glVertexStream2iATI");
	if(!_ptrc_glVertexStream2iATI) numFailed++;
	_ptrc_glVertexStream2ivATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glVertexStream2ivATI");
	if(!_ptrc_glVertexStream2ivATI) numFailed++;
	_ptrc_glVertexStream2sATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort))IntGetProcAddress("glVertexStream2sATI");
	if(!_ptrc_glVertexStream2sATI) numFailed++;
	_ptrc_glVertexStream2svATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glVertexStream2svATI");
	if(!_ptrc_glVertexStream2svATI) numFailed++;
	_ptrc_glVertexStream3dATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexStream3dATI");
	if(!_ptrc_glVertexStream3dATI) numFailed++;
	_ptrc_glVertexStream3dvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glVertexStream3dvATI");
	if(!_ptrc_glVertexStream3dvATI) numFailed++;
	_ptrc_glVertexStream3fATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexStream3fATI");
	if(!_ptrc_glVertexStream3fATI) numFailed++;
	_ptrc_glVertexStream3fvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glVertexStream3fvATI");
	if(!_ptrc_glVertexStream3fvATI) numFailed++;
	_ptrc_glVertexStream3iATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint))IntGetProcAddress("glVertexStream3iATI");
	if(!_ptrc_glVertexStream3iATI) numFailed++;
	_ptrc_glVertexStream3ivATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glVertexStream3ivATI");
	if(!_ptrc_glVertexStream3ivATI) numFailed++;
	_ptrc_glVertexStream3sATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexStream3sATI");
	if(!_ptrc_glVertexStream3sATI) numFailed++;
	_ptrc_glVertexStream3svATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glVertexStream3svATI");
	if(!_ptrc_glVertexStream3svATI) numFailed++;
	_ptrc_glVertexStream4dATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexStream4dATI");
	if(!_ptrc_glVertexStream4dATI) numFailed++;
	_ptrc_glVertexStream4dvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glVertexStream4dvATI");
	if(!_ptrc_glVertexStream4dvATI) numFailed++;
	_ptrc_glVertexStream4fATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexStream4fATI");
	if(!_ptrc_glVertexStream4fATI) numFailed++;
	_ptrc_glVertexStream4fvATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glVertexStream4fvATI");
	if(!_ptrc_glVertexStream4fvATI) numFailed++;
	_ptrc_glVertexStream4iATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint))IntGetProcAddress("glVertexStream4iATI");
	if(!_ptrc_glVertexStream4iATI) numFailed++;
	_ptrc_glVertexStream4ivATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glVertexStream4ivATI");
	if(!_ptrc_glVertexStream4ivATI) numFailed++;
	_ptrc_glVertexStream4sATI = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexStream4sATI");
	if(!_ptrc_glVertexStream4sATI) numFailed++;
	_ptrc_glVertexStream4svATI = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glVertexStream4svATI");
	if(!_ptrc_glVertexStream4svATI) numFailed++;
	return numFailed;
}

GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformBufferSizeEXT)(GLuint, GLint) = NULL;
GLintptr (CODEGEN_FUNCPTR *_ptrc_glGetUniformOffsetEXT)(GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformBufferEXT)(GLuint, GLint, GLuint) = NULL;

static int Load_EXT_bindable_uniform()
{
	int numFailed = 0;
	_ptrc_glGetUniformBufferSizeEXT = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glGetUniformBufferSizeEXT");
	if(!_ptrc_glGetUniformBufferSizeEXT) numFailed++;
	_ptrc_glGetUniformOffsetEXT = (GLintptr (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glGetUniformOffsetEXT");
	if(!_ptrc_glGetUniformOffsetEXT) numFailed++;
	_ptrc_glUniformBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glUniformBufferEXT");
	if(!_ptrc_glUniformBufferEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendColorEXT)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;

static int Load_EXT_blend_color()
{
	int numFailed = 0;
	_ptrc_glBlendColorEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glBlendColorEXT");
	if(!_ptrc_glBlendColorEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparateEXT)(GLenum, GLenum) = NULL;

static int Load_EXT_blend_equation_separate()
{
	int numFailed = 0;
	_ptrc_glBlendEquationSeparateEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparateEXT");
	if(!_ptrc_glBlendEquationSeparateEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateEXT)(GLenum, GLenum, GLenum, GLenum) = NULL;

static int Load_EXT_blend_func_separate()
{
	int numFailed = 0;
	_ptrc_glBlendFuncSeparateEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparateEXT");
	if(!_ptrc_glBlendFuncSeparateEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationEXT)(GLenum) = NULL;

static int Load_EXT_blend_minmax()
{
	int numFailed = 0;
	_ptrc_glBlendEquationEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBlendEquationEXT");
	if(!_ptrc_glBlendEquationEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorSubTableEXT)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyColorSubTableEXT)(GLenum, GLsizei, GLint, GLint, GLsizei) = NULL;

static int Load_EXT_color_subtable()
{
	int numFailed = 0;
	_ptrc_glColorSubTableEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glColorSubTableEXT");
	if(!_ptrc_glColorSubTableEXT) numFailed++;
	_ptrc_glCopyColorSubTableEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLint, GLint, GLsizei))IntGetProcAddress("glCopyColorSubTableEXT");
	if(!_ptrc_glCopyColorSubTableEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glLockArraysEXT)(GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUnlockArraysEXT)() = NULL;

static int Load_EXT_compiled_vertex_array()
{
	int numFailed = 0;
	_ptrc_glLockArraysEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei))IntGetProcAddress("glLockArraysEXT");
	if(!_ptrc_glLockArraysEXT) numFailed++;
	_ptrc_glUnlockArraysEXT = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glUnlockArraysEXT");
	if(!_ptrc_glUnlockArraysEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter1DEXT)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionFilter2DEXT)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfEXT)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterfvEXT)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameteriEXT)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterivEXT)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyConvolutionFilter2DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionFilterEXT)(GLenum, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterfvEXT)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterivEXT)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetSeparableFilterEXT)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSeparableFilter2DEXT)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *) = NULL;

static int Load_EXT_convolution()
{
	int numFailed = 0;
	_ptrc_glConvolutionFilter1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glConvolutionFilter1DEXT");
	if(!_ptrc_glConvolutionFilter1DEXT) numFailed++;
	_ptrc_glConvolutionFilter2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glConvolutionFilter2DEXT");
	if(!_ptrc_glConvolutionFilter2DEXT) numFailed++;
	_ptrc_glConvolutionParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glConvolutionParameterfEXT");
	if(!_ptrc_glConvolutionParameterfEXT) numFailed++;
	_ptrc_glConvolutionParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glConvolutionParameterfvEXT");
	if(!_ptrc_glConvolutionParameterfvEXT) numFailed++;
	_ptrc_glConvolutionParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glConvolutionParameteriEXT");
	if(!_ptrc_glConvolutionParameteriEXT) numFailed++;
	_ptrc_glConvolutionParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glConvolutionParameterivEXT");
	if(!_ptrc_glConvolutionParameterivEXT) numFailed++;
	_ptrc_glCopyConvolutionFilter1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei))IntGetProcAddress("glCopyConvolutionFilter1DEXT");
	if(!_ptrc_glCopyConvolutionFilter1DEXT) numFailed++;
	_ptrc_glCopyConvolutionFilter2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyConvolutionFilter2DEXT");
	if(!_ptrc_glCopyConvolutionFilter2DEXT) numFailed++;
	_ptrc_glGetConvolutionFilterEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetConvolutionFilterEXT");
	if(!_ptrc_glGetConvolutionFilterEXT) numFailed++;
	_ptrc_glGetConvolutionParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetConvolutionParameterfvEXT");
	if(!_ptrc_glGetConvolutionParameterfvEXT) numFailed++;
	_ptrc_glGetConvolutionParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetConvolutionParameterivEXT");
	if(!_ptrc_glGetConvolutionParameterivEXT) numFailed++;
	_ptrc_glGetSeparableFilterEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *))IntGetProcAddress("glGetSeparableFilterEXT");
	if(!_ptrc_glGetSeparableFilterEXT) numFailed++;
	_ptrc_glSeparableFilter2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *))IntGetProcAddress("glSeparableFilter2DEXT");
	if(!_ptrc_glSeparableFilter2DEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBinormal3bEXT)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3bvEXT)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3dEXT)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3dvEXT)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3fEXT)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3fvEXT)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3iEXT)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3ivEXT)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3sEXT)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormal3svEXT)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBinormalPointerEXT)(GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3bEXT)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3bvEXT)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3dEXT)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3dvEXT)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3fEXT)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3fvEXT)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3iEXT)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3ivEXT)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3sEXT)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangent3svEXT)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTangentPointerEXT)(GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_EXT_coordinate_frame()
{
	int numFailed = 0;
	_ptrc_glBinormal3bEXT = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glBinormal3bEXT");
	if(!_ptrc_glBinormal3bEXT) numFailed++;
	_ptrc_glBinormal3bvEXT = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glBinormal3bvEXT");
	if(!_ptrc_glBinormal3bvEXT) numFailed++;
	_ptrc_glBinormal3dEXT = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glBinormal3dEXT");
	if(!_ptrc_glBinormal3dEXT) numFailed++;
	_ptrc_glBinormal3dvEXT = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glBinormal3dvEXT");
	if(!_ptrc_glBinormal3dvEXT) numFailed++;
	_ptrc_glBinormal3fEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glBinormal3fEXT");
	if(!_ptrc_glBinormal3fEXT) numFailed++;
	_ptrc_glBinormal3fvEXT = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glBinormal3fvEXT");
	if(!_ptrc_glBinormal3fvEXT) numFailed++;
	_ptrc_glBinormal3iEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glBinormal3iEXT");
	if(!_ptrc_glBinormal3iEXT) numFailed++;
	_ptrc_glBinormal3ivEXT = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glBinormal3ivEXT");
	if(!_ptrc_glBinormal3ivEXT) numFailed++;
	_ptrc_glBinormal3sEXT = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glBinormal3sEXT");
	if(!_ptrc_glBinormal3sEXT) numFailed++;
	_ptrc_glBinormal3svEXT = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glBinormal3svEXT");
	if(!_ptrc_glBinormal3svEXT) numFailed++;
	_ptrc_glBinormalPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glBinormalPointerEXT");
	if(!_ptrc_glBinormalPointerEXT) numFailed++;
	_ptrc_glTangent3bEXT = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glTangent3bEXT");
	if(!_ptrc_glTangent3bEXT) numFailed++;
	_ptrc_glTangent3bvEXT = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glTangent3bvEXT");
	if(!_ptrc_glTangent3bvEXT) numFailed++;
	_ptrc_glTangent3dEXT = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glTangent3dEXT");
	if(!_ptrc_glTangent3dEXT) numFailed++;
	_ptrc_glTangent3dvEXT = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glTangent3dvEXT");
	if(!_ptrc_glTangent3dvEXT) numFailed++;
	_ptrc_glTangent3fEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTangent3fEXT");
	if(!_ptrc_glTangent3fEXT) numFailed++;
	_ptrc_glTangent3fvEXT = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glTangent3fvEXT");
	if(!_ptrc_glTangent3fvEXT) numFailed++;
	_ptrc_glTangent3iEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glTangent3iEXT");
	if(!_ptrc_glTangent3iEXT) numFailed++;
	_ptrc_glTangent3ivEXT = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glTangent3ivEXT");
	if(!_ptrc_glTangent3ivEXT) numFailed++;
	_ptrc_glTangent3sEXT = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glTangent3sEXT");
	if(!_ptrc_glTangent3sEXT) numFailed++;
	_ptrc_glTangent3svEXT = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glTangent3svEXT");
	if(!_ptrc_glTangent3svEXT) numFailed++;
	_ptrc_glTangentPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glTangentPointerEXT");
	if(!_ptrc_glTangentPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage1DEXT)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage2DEXT)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage1DEXT)(GLenum, GLint, GLint, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage2DEXT)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage3DEXT)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;

static int Load_EXT_copy_texture()
{
	int numFailed = 0;
	_ptrc_glCopyTexImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))IntGetProcAddress("glCopyTexImage1DEXT");
	if(!_ptrc_glCopyTexImage1DEXT) numFailed++;
	_ptrc_glCopyTexImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))IntGetProcAddress("glCopyTexImage2DEXT");
	if(!_ptrc_glCopyTexImage2DEXT) numFailed++;
	_ptrc_glCopyTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyTexSubImage1DEXT");
	if(!_ptrc_glCopyTexSubImage1DEXT) numFailed++;
	_ptrc_glCopyTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTexSubImage2DEXT");
	if(!_ptrc_glCopyTexSubImage2DEXT) numFailed++;
	_ptrc_glCopyTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTexSubImage3DEXT");
	if(!_ptrc_glCopyTexSubImage3DEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCullParameterdvEXT)(GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCullParameterfvEXT)(GLenum, GLfloat *) = NULL;

static int Load_EXT_cull_vertex()
{
	int numFailed = 0;
	_ptrc_glCullParameterdvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble *))IntGetProcAddress("glCullParameterdvEXT");
	if(!_ptrc_glCullParameterdvEXT) numFailed++;
	_ptrc_glCullParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glCullParameterfvEXT");
	if(!_ptrc_glCullParameterfvEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsEXT)(GLclampd, GLclampd) = NULL;

static int Load_EXT_depth_bounds_test()
{
	int numFailed = 0;
	_ptrc_glDepthBoundsEXT = (void (CODEGEN_FUNCPTR *)(GLclampd, GLclampd))IntGetProcAddress("glDepthBoundsEXT");
	if(!_ptrc_glDepthBoundsEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindMultiTextureEXT)(GLenum, GLenum, GLuint) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckNamedFramebufferStatusEXT)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferDataEXT)(GLuint, GLenum, GLenum, GLenum, const void *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearNamedBufferSubDataEXT)(GLuint, GLenum, GLenum, GLenum, GLsizeiptr, GLsizeiptr, const void *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClientAttribDefaultEXT)(GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage1DEXT)(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage2DEXT)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexImage3DEXT)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage2DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedMultiTexSubImage3DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage1DEXT)(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage2DEXT)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureImage3DEXT)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage1DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage2DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTextureSubImage3DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage1DEXT)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexImage2DEXT)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage1DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage2DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyMultiTexSubImage3DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage1DEXT)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureImage2DEXT)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage1DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage2DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTextureSubImage3DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateIndexedEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableClientStateiEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableIndexedEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayAttribEXT)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexArrayEXT)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateIndexedEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableClientStateiEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableIndexedEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayAttribEXT)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexArrayEXT)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFlushMappedNamedBufferRangeEXT)(GLuint, GLintptr, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBufferEXT)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferDrawBuffersEXT)(GLuint, GLsizei, const GLenum *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferReadBufferEXT)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateMultiTexMipmapEXT)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateTextureMipmapEXT)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanIndexedvEXT)(GLenum, GLuint, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedMultiTexImageEXT)(GLenum, GLenum, GLint, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTextureImageEXT)(GLuint, GLenum, GLint, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoubleIndexedvEXT)(GLenum, GLuint, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoublei_vEXT)(GLenum, GLuint, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloatIndexedvEXT)(GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloati_vEXT)(GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferParameterivEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerIndexedvEXT)(GLenum, GLuint, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvfvEXT)(GLenum, GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexEnvivEXT)(GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGendvEXT)(GLenum, GLenum, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenfvEXT)(GLenum, GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexGenivEXT)(GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexImageEXT)(GLenum, GLenum, GLint, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterfvEXT)(GLenum, GLenum, GLint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexLevelParameterivEXT)(GLenum, GLenum, GLint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIivEXT)(GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterIuivEXT)(GLenum, GLenum, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterfvEXT)(GLenum, GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMultiTexParameterivEXT)(GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterivEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferPointervEXT)(GLuint, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferSubDataEXT)(GLuint, GLintptr, GLsizeiptr, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferAttachmentParameterivEXT)(GLuint, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedFramebufferParameterivEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIivEXT)(GLuint, GLenum, GLuint, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterIuivEXT)(GLuint, GLenum, GLuint, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterdvEXT)(GLuint, GLenum, GLuint, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramLocalParameterfvEXT)(GLuint, GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramStringEXT)(GLuint, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedProgramivEXT)(GLuint, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedRenderbufferParameterivEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointerIndexedvEXT)(GLenum, GLuint, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointeri_vEXT)(GLenum, GLuint, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureImageEXT)(GLuint, GLenum, GLint, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterfvEXT)(GLuint, GLenum, GLint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureLevelParameterivEXT)(GLuint, GLenum, GLint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIivEXT)(GLuint, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterIuivEXT)(GLuint, GLenum, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterfvEXT)(GLuint, GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTextureParameterivEXT)(GLuint, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegeri_vEXT)(GLuint, GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayIntegervEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointeri_vEXT)(GLuint, GLuint, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexArrayPointervEXT)(GLuint, GLenum, GLvoid **) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledIndexedEXT)(GLenum, GLuint) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferEXT)(GLuint, GLenum) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapNamedBufferRangeEXT)(GLuint, GLintptr, GLsizeiptr, GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixFrustumEXT)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadIdentityEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposedEXT)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadTransposefEXT)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoaddEXT)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixLoadfEXT)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposedEXT)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultTransposefEXT)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultdEXT)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMultfEXT)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixOrthoEXT)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixPopEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixPushEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatedEXT)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixRotatefEXT)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixScaledEXT)(GLenum, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixScalefEXT)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatedEXT)(GLenum, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixTranslatefEXT)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexBufferEXT)(GLenum, GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoordPointerEXT)(GLenum, GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfEXT)(GLenum, GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvfvEXT)(GLenum, GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnviEXT)(GLenum, GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexEnvivEXT)(GLenum, GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendEXT)(GLenum, GLenum, GLenum, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGendvEXT)(GLenum, GLenum, GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfEXT)(GLenum, GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenfvEXT)(GLenum, GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGeniEXT)(GLenum, GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexGenivEXT)(GLenum, GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage2DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexImage3DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIivEXT)(GLenum, GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterIuivEXT)(GLenum, GLenum, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfEXT)(GLenum, GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterfvEXT)(GLenum, GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameteriEXT)(GLenum, GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexParameterivEXT)(GLenum, GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexRenderbufferEXT)(GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage1DEXT)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage2DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexSubImage3DEXT)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferDataEXT)(GLuint, GLsizeiptr, const GLvoid *, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedBufferSubDataEXT)(GLuint, GLintptr, GLsizeiptr, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedCopyBufferSubDataEXT)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferParameteriEXT)(GLuint, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferRenderbufferEXT)(GLuint, GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture1DEXT)(GLuint, GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture2DEXT)(GLuint, GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTexture3DEXT)(GLuint, GLenum, GLenum, GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureEXT)(GLuint, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureFaceEXT)(GLuint, GLenum, GLuint, GLint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedFramebufferTextureLayerEXT)(GLuint, GLenum, GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dEXT)(GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4dvEXT)(GLuint, GLenum, GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fEXT)(GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameter4fvEXT)(GLuint, GLenum, GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4iEXT)(GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4ivEXT)(GLuint, GLenum, GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uiEXT)(GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameterI4uivEXT)(GLuint, GLenum, GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParameters4fvEXT)(GLuint, GLenum, GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4ivEXT)(GLuint, GLenum, GLuint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramLocalParametersI4uivEXT)(GLuint, GLenum, GLuint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedProgramStringEXT)(GLuint, GLenum, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageEXT)(GLuint, GLenum, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT)(GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNamedRenderbufferStorageMultisampleEXT)(GLuint, GLsizei, GLenum, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dEXT)(GLuint, GLint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1dvEXT)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fEXT)(GLuint, GLint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1fvEXT)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1iEXT)(GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ivEXT)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uiEXT)(GLuint, GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1uivEXT)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dEXT)(GLuint, GLint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2dvEXT)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fEXT)(GLuint, GLint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2fvEXT)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2iEXT)(GLuint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ivEXT)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uiEXT)(GLuint, GLint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2uivEXT)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dEXT)(GLuint, GLint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3dvEXT)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fEXT)(GLuint, GLint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3fvEXT)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3iEXT)(GLuint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ivEXT)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uiEXT)(GLuint, GLint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3uivEXT)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dEXT)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4dvEXT)(GLuint, GLint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fEXT)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4fvEXT)(GLuint, GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4iEXT)(GLuint, GLint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ivEXT)(GLuint, GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uiEXT)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4uivEXT)(GLuint, GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x3fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix2x4fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x2fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix3x4fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x2fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3dvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformMatrix4x3fvEXT)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushClientAttribDefaultEXT)(GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferEXT)(GLuint, GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureBufferRangeEXT)(GLuint, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage1DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexturePageCommitmentEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIivEXT)(GLuint, GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterIuivEXT)(GLuint, GLenum, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfEXT)(GLuint, GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterfvEXT)(GLuint, GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameteriEXT)(GLuint, GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureParameterivEXT)(GLuint, GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureRenderbufferEXT)(GLuint, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage1DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage2DMultisampleEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureStorage3DMultisampleEXT)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage1DEXT)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage2DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureSubImage3DEXT)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapNamedBufferEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayBindVertexBufferEXT)(GLuint, GLuint, GLuint, GLintptr, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayColorOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayEdgeFlagOffsetEXT)(GLuint, GLuint, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayFogCoordOffsetEXT)(GLuint, GLuint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayIndexOffsetEXT)(GLuint, GLuint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayMultiTexCoordOffsetEXT)(GLuint, GLuint, GLenum, GLint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayNormalOffsetEXT)(GLuint, GLuint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArraySecondaryColorOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayTexCoordOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribBindingEXT)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribFormatEXT)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIFormatEXT)(GLuint, GLuint, GLint, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribIOffsetEXT)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLFormatEXT)(GLuint, GLuint, GLint, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribLOffsetEXT)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexAttribOffsetEXT)(GLuint, GLuint, GLuint, GLint, GLenum, GLboolean, GLsizei, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexBindingDivisorEXT)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayVertexOffsetEXT)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr) = NULL;

static int Load_EXT_direct_state_access()
{
	int numFailed = 0;
	_ptrc_glBindMultiTextureEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glBindMultiTextureEXT");
	if(!_ptrc_glBindMultiTextureEXT) numFailed++;
	_ptrc_glCheckNamedFramebufferStatusEXT = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCheckNamedFramebufferStatusEXT");
	if(!_ptrc_glCheckNamedFramebufferStatusEXT) numFailed++;
	_ptrc_glClearNamedBufferDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearNamedBufferDataEXT");
	if(!_ptrc_glClearNamedBufferDataEXT) numFailed++;
	_ptrc_glClearNamedBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, GLsizeiptr, GLsizeiptr, const void *))IntGetProcAddress("glClearNamedBufferSubDataEXT");
	if(!_ptrc_glClearNamedBufferSubDataEXT) numFailed++;
	_ptrc_glClientAttribDefaultEXT = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glClientAttribDefaultEXT");
	if(!_ptrc_glClientAttribDefaultEXT) numFailed++;
	_ptrc_glCompressedMultiTexImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedMultiTexImage1DEXT");
	if(!_ptrc_glCompressedMultiTexImage1DEXT) numFailed++;
	_ptrc_glCompressedMultiTexImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedMultiTexImage2DEXT");
	if(!_ptrc_glCompressedMultiTexImage2DEXT) numFailed++;
	_ptrc_glCompressedMultiTexImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedMultiTexImage3DEXT");
	if(!_ptrc_glCompressedMultiTexImage3DEXT) numFailed++;
	_ptrc_glCompressedMultiTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedMultiTexSubImage1DEXT");
	if(!_ptrc_glCompressedMultiTexSubImage1DEXT) numFailed++;
	_ptrc_glCompressedMultiTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedMultiTexSubImage2DEXT");
	if(!_ptrc_glCompressedMultiTexSubImage2DEXT) numFailed++;
	_ptrc_glCompressedMultiTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedMultiTexSubImage3DEXT");
	if(!_ptrc_glCompressedMultiTexSubImage3DEXT) numFailed++;
	_ptrc_glCompressedTextureImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTextureImage1DEXT");
	if(!_ptrc_glCompressedTextureImage1DEXT) numFailed++;
	_ptrc_glCompressedTextureImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTextureImage2DEXT");
	if(!_ptrc_glCompressedTextureImage2DEXT) numFailed++;
	_ptrc_glCompressedTextureImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTextureImage3DEXT");
	if(!_ptrc_glCompressedTextureImage3DEXT) numFailed++;
	_ptrc_glCompressedTextureSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTextureSubImage1DEXT");
	if(!_ptrc_glCompressedTextureSubImage1DEXT) numFailed++;
	_ptrc_glCompressedTextureSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTextureSubImage2DEXT");
	if(!_ptrc_glCompressedTextureSubImage2DEXT) numFailed++;
	_ptrc_glCompressedTextureSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTextureSubImage3DEXT");
	if(!_ptrc_glCompressedTextureSubImage3DEXT) numFailed++;
	_ptrc_glCopyMultiTexImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))IntGetProcAddress("glCopyMultiTexImage1DEXT");
	if(!_ptrc_glCopyMultiTexImage1DEXT) numFailed++;
	_ptrc_glCopyMultiTexImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))IntGetProcAddress("glCopyMultiTexImage2DEXT");
	if(!_ptrc_glCopyMultiTexImage2DEXT) numFailed++;
	_ptrc_glCopyMultiTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyMultiTexSubImage1DEXT");
	if(!_ptrc_glCopyMultiTexSubImage1DEXT) numFailed++;
	_ptrc_glCopyMultiTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyMultiTexSubImage2DEXT");
	if(!_ptrc_glCopyMultiTexSubImage2DEXT) numFailed++;
	_ptrc_glCopyMultiTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyMultiTexSubImage3DEXT");
	if(!_ptrc_glCopyMultiTexSubImage3DEXT) numFailed++;
	_ptrc_glCopyTextureImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))IntGetProcAddress("glCopyTextureImage1DEXT");
	if(!_ptrc_glCopyTextureImage1DEXT) numFailed++;
	_ptrc_glCopyTextureImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))IntGetProcAddress("glCopyTextureImage2DEXT");
	if(!_ptrc_glCopyTextureImage2DEXT) numFailed++;
	_ptrc_glCopyTextureSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyTextureSubImage1DEXT");
	if(!_ptrc_glCopyTextureSubImage1DEXT) numFailed++;
	_ptrc_glCopyTextureSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage2DEXT");
	if(!_ptrc_glCopyTextureSubImage2DEXT) numFailed++;
	_ptrc_glCopyTextureSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTextureSubImage3DEXT");
	if(!_ptrc_glCopyTextureSubImage3DEXT) numFailed++;
	_ptrc_glDisableClientStateIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableClientStateIndexedEXT");
	if(!_ptrc_glDisableClientStateIndexedEXT) numFailed++;
	_ptrc_glDisableClientStateiEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableClientStateiEXT");
	if(!_ptrc_glDisableClientStateiEXT) numFailed++;
	_ptrc_glDisableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableIndexedEXT");
	if(!_ptrc_glDisableIndexedEXT) numFailed++;
	_ptrc_glDisableVertexArrayAttribEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glDisableVertexArrayAttribEXT");
	if(!_ptrc_glDisableVertexArrayAttribEXT) numFailed++;
	_ptrc_glDisableVertexArrayEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glDisableVertexArrayEXT");
	if(!_ptrc_glDisableVertexArrayEXT) numFailed++;
	_ptrc_glEnableClientStateIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableClientStateIndexedEXT");
	if(!_ptrc_glEnableClientStateIndexedEXT) numFailed++;
	_ptrc_glEnableClientStateiEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableClientStateiEXT");
	if(!_ptrc_glEnableClientStateiEXT) numFailed++;
	_ptrc_glEnableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableIndexedEXT");
	if(!_ptrc_glEnableIndexedEXT) numFailed++;
	_ptrc_glEnableVertexArrayAttribEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glEnableVertexArrayAttribEXT");
	if(!_ptrc_glEnableVertexArrayAttribEXT) numFailed++;
	_ptrc_glEnableVertexArrayEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glEnableVertexArrayEXT");
	if(!_ptrc_glEnableVertexArrayEXT) numFailed++;
	_ptrc_glFlushMappedNamedBufferRangeEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedNamedBufferRangeEXT");
	if(!_ptrc_glFlushMappedNamedBufferRangeEXT) numFailed++;
	_ptrc_glFramebufferDrawBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glFramebufferDrawBufferEXT");
	if(!_ptrc_glFramebufferDrawBufferEXT) numFailed++;
	_ptrc_glFramebufferDrawBuffersEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLenum *))IntGetProcAddress("glFramebufferDrawBuffersEXT");
	if(!_ptrc_glFramebufferDrawBuffersEXT) numFailed++;
	_ptrc_glFramebufferReadBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glFramebufferReadBufferEXT");
	if(!_ptrc_glFramebufferReadBufferEXT) numFailed++;
	_ptrc_glGenerateMultiTexMipmapEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glGenerateMultiTexMipmapEXT");
	if(!_ptrc_glGenerateMultiTexMipmapEXT) numFailed++;
	_ptrc_glGenerateTextureMipmapEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glGenerateTextureMipmapEXT");
	if(!_ptrc_glGenerateTextureMipmapEXT) numFailed++;
	_ptrc_glGetBooleanIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLboolean *))IntGetProcAddress("glGetBooleanIndexedvEXT");
	if(!_ptrc_glGetBooleanIndexedvEXT) numFailed++;
	_ptrc_glGetCompressedMultiTexImageEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLvoid *))IntGetProcAddress("glGetCompressedMultiTexImageEXT");
	if(!_ptrc_glGetCompressedMultiTexImageEXT) numFailed++;
	_ptrc_glGetCompressedTextureImageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLvoid *))IntGetProcAddress("glGetCompressedTextureImageEXT");
	if(!_ptrc_glGetCompressedTextureImageEXT) numFailed++;
	_ptrc_glGetDoubleIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoubleIndexedvEXT");
	if(!_ptrc_glGetDoubleIndexedvEXT) numFailed++;
	_ptrc_glGetDoublei_vEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoublei_vEXT");
	if(!_ptrc_glGetDoublei_vEXT) numFailed++;
	_ptrc_glGetFloatIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloatIndexedvEXT");
	if(!_ptrc_glGetFloatIndexedvEXT) numFailed++;
	_ptrc_glGetFloati_vEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloati_vEXT");
	if(!_ptrc_glGetFloati_vEXT) numFailed++;
	_ptrc_glGetFramebufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetFramebufferParameterivEXT");
	if(!_ptrc_glGetFramebufferParameterivEXT) numFailed++;
	_ptrc_glGetIntegerIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetIntegerIndexedvEXT");
	if(!_ptrc_glGetIntegerIndexedvEXT) numFailed++;
	_ptrc_glGetMultiTexEnvfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexEnvfvEXT");
	if(!_ptrc_glGetMultiTexEnvfvEXT) numFailed++;
	_ptrc_glGetMultiTexEnvivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexEnvivEXT");
	if(!_ptrc_glGetMultiTexEnvivEXT) numFailed++;
	_ptrc_glGetMultiTexGendvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLdouble *))IntGetProcAddress("glGetMultiTexGendvEXT");
	if(!_ptrc_glGetMultiTexGendvEXT) numFailed++;
	_ptrc_glGetMultiTexGenfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexGenfvEXT");
	if(!_ptrc_glGetMultiTexGenfvEXT) numFailed++;
	_ptrc_glGetMultiTexGenivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexGenivEXT");
	if(!_ptrc_glGetMultiTexGenivEXT) numFailed++;
	_ptrc_glGetMultiTexImageEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetMultiTexImageEXT");
	if(!_ptrc_glGetMultiTexImageEXT) numFailed++;
	_ptrc_glGetMultiTexLevelParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexLevelParameterfvEXT");
	if(!_ptrc_glGetMultiTexLevelParameterfvEXT) numFailed++;
	_ptrc_glGetMultiTexLevelParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLenum, GLint *))IntGetProcAddress("glGetMultiTexLevelParameterivEXT");
	if(!_ptrc_glGetMultiTexLevelParameterivEXT) numFailed++;
	_ptrc_glGetMultiTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexParameterIivEXT");
	if(!_ptrc_glGetMultiTexParameterIivEXT) numFailed++;
	_ptrc_glGetMultiTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint *))IntGetProcAddress("glGetMultiTexParameterIuivEXT");
	if(!_ptrc_glGetMultiTexParameterIuivEXT) numFailed++;
	_ptrc_glGetMultiTexParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMultiTexParameterfvEXT");
	if(!_ptrc_glGetMultiTexParameterfvEXT) numFailed++;
	_ptrc_glGetMultiTexParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetMultiTexParameterivEXT");
	if(!_ptrc_glGetMultiTexParameterivEXT) numFailed++;
	_ptrc_glGetNamedBufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedBufferParameterivEXT");
	if(!_ptrc_glGetNamedBufferParameterivEXT) numFailed++;
	_ptrc_glGetNamedBufferPointervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLvoid **))IntGetProcAddress("glGetNamedBufferPointervEXT");
	if(!_ptrc_glGetNamedBufferPointervEXT) numFailed++;
	_ptrc_glGetNamedBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, GLvoid *))IntGetProcAddress("glGetNamedBufferSubDataEXT");
	if(!_ptrc_glGetNamedBufferSubDataEXT) numFailed++;
	_ptrc_glGetNamedFramebufferAttachmentParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferAttachmentParameterivEXT");
	if(!_ptrc_glGetNamedFramebufferAttachmentParameterivEXT) numFailed++;
	_ptrc_glGetNamedFramebufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedFramebufferParameterivEXT");
	if(!_ptrc_glGetNamedFramebufferParameterivEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint *))IntGetProcAddress("glGetNamedProgramLocalParameterIivEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterIivEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLuint *))IntGetProcAddress("glGetNamedProgramLocalParameterIuivEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterIuivEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterdvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetNamedProgramLocalParameterdvEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterdvEXT) numFailed++;
	_ptrc_glGetNamedProgramLocalParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetNamedProgramLocalParameterfvEXT");
	if(!_ptrc_glGetNamedProgramLocalParameterfvEXT) numFailed++;
	_ptrc_glGetNamedProgramStringEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetNamedProgramStringEXT");
	if(!_ptrc_glGetNamedProgramStringEXT) numFailed++;
	_ptrc_glGetNamedProgramivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetNamedProgramivEXT");
	if(!_ptrc_glGetNamedProgramivEXT) numFailed++;
	_ptrc_glGetNamedRenderbufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetNamedRenderbufferParameterivEXT");
	if(!_ptrc_glGetNamedRenderbufferParameterivEXT) numFailed++;
	_ptrc_glGetPointerIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLvoid **))IntGetProcAddress("glGetPointerIndexedvEXT");
	if(!_ptrc_glGetPointerIndexedvEXT) numFailed++;
	_ptrc_glGetPointeri_vEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLvoid **))IntGetProcAddress("glGetPointeri_vEXT");
	if(!_ptrc_glGetPointeri_vEXT) numFailed++;
	_ptrc_glGetTextureImageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetTextureImageEXT");
	if(!_ptrc_glGetTextureImageEXT) numFailed++;
	_ptrc_glGetTextureLevelParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetTextureLevelParameterfvEXT");
	if(!_ptrc_glGetTextureLevelParameterfvEXT) numFailed++;
	_ptrc_glGetTextureLevelParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLenum, GLint *))IntGetProcAddress("glGetTextureLevelParameterivEXT");
	if(!_ptrc_glGetTextureLevelParameterivEXT) numFailed++;
	_ptrc_glGetTextureParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetTextureParameterIivEXT");
	if(!_ptrc_glGetTextureParameterIivEXT) numFailed++;
	_ptrc_glGetTextureParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint *))IntGetProcAddress("glGetTextureParameterIuivEXT");
	if(!_ptrc_glGetTextureParameterIuivEXT) numFailed++;
	_ptrc_glGetTextureParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetTextureParameterfvEXT");
	if(!_ptrc_glGetTextureParameterfvEXT) numFailed++;
	_ptrc_glGetTextureParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetTextureParameterivEXT");
	if(!_ptrc_glGetTextureParameterivEXT) numFailed++;
	_ptrc_glGetVertexArrayIntegeri_vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayIntegeri_vEXT");
	if(!_ptrc_glGetVertexArrayIntegeri_vEXT) numFailed++;
	_ptrc_glGetVertexArrayIntegervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexArrayIntegervEXT");
	if(!_ptrc_glGetVertexArrayIntegervEXT) numFailed++;
	_ptrc_glGetVertexArrayPointeri_vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLvoid **))IntGetProcAddress("glGetVertexArrayPointeri_vEXT");
	if(!_ptrc_glGetVertexArrayPointeri_vEXT) numFailed++;
	_ptrc_glGetVertexArrayPointervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLvoid **))IntGetProcAddress("glGetVertexArrayPointervEXT");
	if(!_ptrc_glGetVertexArrayPointervEXT) numFailed++;
	_ptrc_glIsEnabledIndexedEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glIsEnabledIndexedEXT");
	if(!_ptrc_glIsEnabledIndexedEXT) numFailed++;
	_ptrc_glMapNamedBufferEXT = (void * (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glMapNamedBufferEXT");
	if(!_ptrc_glMapNamedBufferEXT) numFailed++;
	_ptrc_glMapNamedBufferRangeEXT = (void * (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapNamedBufferRangeEXT");
	if(!_ptrc_glMapNamedBufferRangeEXT) numFailed++;
	_ptrc_glMatrixFrustumEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixFrustumEXT");
	if(!_ptrc_glMatrixFrustumEXT) numFailed++;
	_ptrc_glMatrixLoadIdentityEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMatrixLoadIdentityEXT");
	if(!_ptrc_glMatrixLoadIdentityEXT) numFailed++;
	_ptrc_glMatrixLoadTransposedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixLoadTransposedEXT");
	if(!_ptrc_glMatrixLoadTransposedEXT) numFailed++;
	_ptrc_glMatrixLoadTransposefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixLoadTransposefEXT");
	if(!_ptrc_glMatrixLoadTransposefEXT) numFailed++;
	_ptrc_glMatrixLoaddEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixLoaddEXT");
	if(!_ptrc_glMatrixLoaddEXT) numFailed++;
	_ptrc_glMatrixLoadfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixLoadfEXT");
	if(!_ptrc_glMatrixLoadfEXT) numFailed++;
	_ptrc_glMatrixMultTransposedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixMultTransposedEXT");
	if(!_ptrc_glMatrixMultTransposedEXT) numFailed++;
	_ptrc_glMatrixMultTransposefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixMultTransposefEXT");
	if(!_ptrc_glMatrixMultTransposefEXT) numFailed++;
	_ptrc_glMatrixMultdEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMatrixMultdEXT");
	if(!_ptrc_glMatrixMultdEXT) numFailed++;
	_ptrc_glMatrixMultfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMatrixMultfEXT");
	if(!_ptrc_glMatrixMultfEXT) numFailed++;
	_ptrc_glMatrixOrthoEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixOrthoEXT");
	if(!_ptrc_glMatrixOrthoEXT) numFailed++;
	_ptrc_glMatrixPopEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMatrixPopEXT");
	if(!_ptrc_glMatrixPopEXT) numFailed++;
	_ptrc_glMatrixPushEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMatrixPushEXT");
	if(!_ptrc_glMatrixPushEXT) numFailed++;
	_ptrc_glMatrixRotatedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixRotatedEXT");
	if(!_ptrc_glMatrixRotatedEXT) numFailed++;
	_ptrc_glMatrixRotatefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMatrixRotatefEXT");
	if(!_ptrc_glMatrixRotatefEXT) numFailed++;
	_ptrc_glMatrixScaledEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixScaledEXT");
	if(!_ptrc_glMatrixScaledEXT) numFailed++;
	_ptrc_glMatrixScalefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMatrixScalefEXT");
	if(!_ptrc_glMatrixScalefEXT) numFailed++;
	_ptrc_glMatrixTranslatedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMatrixTranslatedEXT");
	if(!_ptrc_glMatrixTranslatedEXT) numFailed++;
	_ptrc_glMatrixTranslatefEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMatrixTranslatefEXT");
	if(!_ptrc_glMatrixTranslatefEXT) numFailed++;
	_ptrc_glMultiTexBufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexBufferEXT");
	if(!_ptrc_glMultiTexBufferEXT) numFailed++;
	_ptrc_glMultiTexCoordPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glMultiTexCoordPointerEXT");
	if(!_ptrc_glMultiTexCoordPointerEXT) numFailed++;
	_ptrc_glMultiTexEnvfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat))IntGetProcAddress("glMultiTexEnvfEXT");
	if(!_ptrc_glMultiTexEnvfEXT) numFailed++;
	_ptrc_glMultiTexEnvfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMultiTexEnvfvEXT");
	if(!_ptrc_glMultiTexEnvfvEXT) numFailed++;
	_ptrc_glMultiTexEnviEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint))IntGetProcAddress("glMultiTexEnviEXT");
	if(!_ptrc_glMultiTexEnviEXT) numFailed++;
	_ptrc_glMultiTexEnvivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexEnvivEXT");
	if(!_ptrc_glMultiTexEnvivEXT) numFailed++;
	_ptrc_glMultiTexGendEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLdouble))IntGetProcAddress("glMultiTexGendEXT");
	if(!_ptrc_glMultiTexGendEXT) numFailed++;
	_ptrc_glMultiTexGendvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLdouble *))IntGetProcAddress("glMultiTexGendvEXT");
	if(!_ptrc_glMultiTexGendvEXT) numFailed++;
	_ptrc_glMultiTexGenfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat))IntGetProcAddress("glMultiTexGenfEXT");
	if(!_ptrc_glMultiTexGenfEXT) numFailed++;
	_ptrc_glMultiTexGenfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMultiTexGenfvEXT");
	if(!_ptrc_glMultiTexGenfvEXT) numFailed++;
	_ptrc_glMultiTexGeniEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint))IntGetProcAddress("glMultiTexGeniEXT");
	if(!_ptrc_glMultiTexGeniEXT) numFailed++;
	_ptrc_glMultiTexGenivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexGenivEXT");
	if(!_ptrc_glMultiTexGenivEXT) numFailed++;
	_ptrc_glMultiTexImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glMultiTexImage1DEXT");
	if(!_ptrc_glMultiTexImage1DEXT) numFailed++;
	_ptrc_glMultiTexImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glMultiTexImage2DEXT");
	if(!_ptrc_glMultiTexImage2DEXT) numFailed++;
	_ptrc_glMultiTexImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glMultiTexImage3DEXT");
	if(!_ptrc_glMultiTexImage3DEXT) numFailed++;
	_ptrc_glMultiTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexParameterIivEXT");
	if(!_ptrc_glMultiTexParameterIivEXT) numFailed++;
	_ptrc_glMultiTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLuint *))IntGetProcAddress("glMultiTexParameterIuivEXT");
	if(!_ptrc_glMultiTexParameterIuivEXT) numFailed++;
	_ptrc_glMultiTexParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat))IntGetProcAddress("glMultiTexParameterfEXT");
	if(!_ptrc_glMultiTexParameterfEXT) numFailed++;
	_ptrc_glMultiTexParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMultiTexParameterfvEXT");
	if(!_ptrc_glMultiTexParameterfvEXT) numFailed++;
	_ptrc_glMultiTexParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint))IntGetProcAddress("glMultiTexParameteriEXT");
	if(!_ptrc_glMultiTexParameteriEXT) numFailed++;
	_ptrc_glMultiTexParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLint *))IntGetProcAddress("glMultiTexParameterivEXT");
	if(!_ptrc_glMultiTexParameterivEXT) numFailed++;
	_ptrc_glMultiTexRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glMultiTexRenderbufferEXT");
	if(!_ptrc_glMultiTexRenderbufferEXT) numFailed++;
	_ptrc_glMultiTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glMultiTexSubImage1DEXT");
	if(!_ptrc_glMultiTexSubImage1DEXT) numFailed++;
	_ptrc_glMultiTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glMultiTexSubImage2DEXT");
	if(!_ptrc_glMultiTexSubImage2DEXT) numFailed++;
	_ptrc_glMultiTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glMultiTexSubImage3DEXT");
	if(!_ptrc_glMultiTexSubImage3DEXT) numFailed++;
	_ptrc_glNamedBufferDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizeiptr, const GLvoid *, GLenum))IntGetProcAddress("glNamedBufferDataEXT");
	if(!_ptrc_glNamedBufferDataEXT) numFailed++;
	_ptrc_glNamedBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr, const GLvoid *))IntGetProcAddress("glNamedBufferSubDataEXT");
	if(!_ptrc_glNamedBufferSubDataEXT) numFailed++;
	_ptrc_glNamedCopyBufferSubDataEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glNamedCopyBufferSubDataEXT");
	if(!_ptrc_glNamedCopyBufferSubDataEXT) numFailed++;
	_ptrc_glNamedFramebufferParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glNamedFramebufferParameteriEXT");
	if(!_ptrc_glNamedFramebufferParameteriEXT) numFailed++;
	_ptrc_glNamedFramebufferRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glNamedFramebufferRenderbufferEXT");
	if(!_ptrc_glNamedFramebufferRenderbufferEXT) numFailed++;
	_ptrc_glNamedFramebufferTexture1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTexture1DEXT");
	if(!_ptrc_glNamedFramebufferTexture1DEXT) numFailed++;
	_ptrc_glNamedFramebufferTexture2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTexture2DEXT");
	if(!_ptrc_glNamedFramebufferTexture2DEXT) numFailed++;
	_ptrc_glNamedFramebufferTexture3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glNamedFramebufferTexture3DEXT");
	if(!_ptrc_glNamedFramebufferTexture3DEXT) numFailed++;
	_ptrc_glNamedFramebufferTextureEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint))IntGetProcAddress("glNamedFramebufferTextureEXT");
	if(!_ptrc_glNamedFramebufferTextureEXT) numFailed++;
	_ptrc_glNamedFramebufferTextureFaceEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLenum))IntGetProcAddress("glNamedFramebufferTextureFaceEXT");
	if(!_ptrc_glNamedFramebufferTextureFaceEXT) numFailed++;
	_ptrc_glNamedFramebufferTextureLayerEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glNamedFramebufferTextureLayerEXT");
	if(!_ptrc_glNamedFramebufferTextureLayerEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glNamedProgramLocalParameter4dEXT");
	if(!_ptrc_glNamedProgramLocalParameter4dEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLdouble *))IntGetProcAddress("glNamedProgramLocalParameter4dvEXT");
	if(!_ptrc_glNamedProgramLocalParameter4dvEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glNamedProgramLocalParameter4fEXT");
	if(!_ptrc_glNamedProgramLocalParameter4fEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameter4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLfloat *))IntGetProcAddress("glNamedProgramLocalParameter4fvEXT");
	if(!_ptrc_glNamedProgramLocalParameter4fvEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glNamedProgramLocalParameterI4iEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4iEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLint *))IntGetProcAddress("glNamedProgramLocalParameterI4ivEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4ivEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glNamedProgramLocalParameterI4uiEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4uiEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameterI4uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLuint *))IntGetProcAddress("glNamedProgramLocalParameterI4uivEXT");
	if(!_ptrc_glNamedProgramLocalParameterI4uivEXT) numFailed++;
	_ptrc_glNamedProgramLocalParameters4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glNamedProgramLocalParameters4fvEXT");
	if(!_ptrc_glNamedProgramLocalParameters4fvEXT) numFailed++;
	_ptrc_glNamedProgramLocalParametersI4ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLint *))IntGetProcAddress("glNamedProgramLocalParametersI4ivEXT");
	if(!_ptrc_glNamedProgramLocalParametersI4ivEXT) numFailed++;
	_ptrc_glNamedProgramLocalParametersI4uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glNamedProgramLocalParametersI4uivEXT");
	if(!_ptrc_glNamedProgramLocalParametersI4uivEXT) numFailed++;
	_ptrc_glNamedProgramStringEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glNamedProgramStringEXT");
	if(!_ptrc_glNamedProgramStringEXT) numFailed++;
	_ptrc_glNamedRenderbufferStorageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageEXT");
	if(!_ptrc_glNamedRenderbufferStorageEXT) numFailed++;
	_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageMultisampleCoverageEXT");
	if(!_ptrc_glNamedRenderbufferStorageMultisampleCoverageEXT) numFailed++;
	_ptrc_glNamedRenderbufferStorageMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glNamedRenderbufferStorageMultisampleEXT");
	if(!_ptrc_glNamedRenderbufferStorageMultisampleEXT) numFailed++;
	_ptrc_glProgramUniform1dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble))IntGetProcAddress("glProgramUniform1dEXT");
	if(!_ptrc_glProgramUniform1dEXT) numFailed++;
	_ptrc_glProgramUniform1dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform1dvEXT");
	if(!_ptrc_glProgramUniform1dvEXT) numFailed++;
	_ptrc_glProgramUniform1fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat))IntGetProcAddress("glProgramUniform1fEXT");
	if(!_ptrc_glProgramUniform1fEXT) numFailed++;
	_ptrc_glProgramUniform1fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform1fvEXT");
	if(!_ptrc_glProgramUniform1fvEXT) numFailed++;
	_ptrc_glProgramUniform1iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glProgramUniform1iEXT");
	if(!_ptrc_glProgramUniform1iEXT) numFailed++;
	_ptrc_glProgramUniform1ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform1ivEXT");
	if(!_ptrc_glProgramUniform1ivEXT) numFailed++;
	_ptrc_glProgramUniform1uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glProgramUniform1uiEXT");
	if(!_ptrc_glProgramUniform1uiEXT) numFailed++;
	_ptrc_glProgramUniform1uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform1uivEXT");
	if(!_ptrc_glProgramUniform1uivEXT) numFailed++;
	_ptrc_glProgramUniform2dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform2dEXT");
	if(!_ptrc_glProgramUniform2dEXT) numFailed++;
	_ptrc_glProgramUniform2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform2dvEXT");
	if(!_ptrc_glProgramUniform2dvEXT) numFailed++;
	_ptrc_glProgramUniform2fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform2fEXT");
	if(!_ptrc_glProgramUniform2fEXT) numFailed++;
	_ptrc_glProgramUniform2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform2fvEXT");
	if(!_ptrc_glProgramUniform2fvEXT) numFailed++;
	_ptrc_glProgramUniform2iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform2iEXT");
	if(!_ptrc_glProgramUniform2iEXT) numFailed++;
	_ptrc_glProgramUniform2ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform2ivEXT");
	if(!_ptrc_glProgramUniform2ivEXT) numFailed++;
	_ptrc_glProgramUniform2uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint))IntGetProcAddress("glProgramUniform2uiEXT");
	if(!_ptrc_glProgramUniform2uiEXT) numFailed++;
	_ptrc_glProgramUniform2uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform2uivEXT");
	if(!_ptrc_glProgramUniform2uivEXT) numFailed++;
	_ptrc_glProgramUniform3dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform3dEXT");
	if(!_ptrc_glProgramUniform3dEXT) numFailed++;
	_ptrc_glProgramUniform3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform3dvEXT");
	if(!_ptrc_glProgramUniform3dvEXT) numFailed++;
	_ptrc_glProgramUniform3fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform3fEXT");
	if(!_ptrc_glProgramUniform3fEXT) numFailed++;
	_ptrc_glProgramUniform3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform3fvEXT");
	if(!_ptrc_glProgramUniform3fvEXT) numFailed++;
	_ptrc_glProgramUniform3iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform3iEXT");
	if(!_ptrc_glProgramUniform3iEXT) numFailed++;
	_ptrc_glProgramUniform3ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform3ivEXT");
	if(!_ptrc_glProgramUniform3ivEXT) numFailed++;
	_ptrc_glProgramUniform3uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform3uiEXT");
	if(!_ptrc_glProgramUniform3uiEXT) numFailed++;
	_ptrc_glProgramUniform3uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform3uivEXT");
	if(!_ptrc_glProgramUniform3uivEXT) numFailed++;
	_ptrc_glProgramUniform4dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform4dEXT");
	if(!_ptrc_glProgramUniform4dEXT) numFailed++;
	_ptrc_glProgramUniform4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform4dvEXT");
	if(!_ptrc_glProgramUniform4dvEXT) numFailed++;
	_ptrc_glProgramUniform4fEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform4fEXT");
	if(!_ptrc_glProgramUniform4fEXT) numFailed++;
	_ptrc_glProgramUniform4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform4fvEXT");
	if(!_ptrc_glProgramUniform4fvEXT) numFailed++;
	_ptrc_glProgramUniform4iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform4iEXT");
	if(!_ptrc_glProgramUniform4iEXT) numFailed++;
	_ptrc_glProgramUniform4ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform4ivEXT");
	if(!_ptrc_glProgramUniform4ivEXT) numFailed++;
	_ptrc_glProgramUniform4uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform4uiEXT");
	if(!_ptrc_glProgramUniform4uiEXT) numFailed++;
	_ptrc_glProgramUniform4uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform4uivEXT");
	if(!_ptrc_glProgramUniform4uivEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2dvEXT");
	if(!_ptrc_glProgramUniformMatrix2dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2fvEXT");
	if(!_ptrc_glProgramUniformMatrix2fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x3dvEXT");
	if(!_ptrc_glProgramUniformMatrix2x3dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x3fvEXT");
	if(!_ptrc_glProgramUniformMatrix2x3fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x4dvEXT");
	if(!_ptrc_glProgramUniformMatrix2x4dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix2x4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x4fvEXT");
	if(!_ptrc_glProgramUniformMatrix2x4fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3dvEXT");
	if(!_ptrc_glProgramUniformMatrix3dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3fvEXT");
	if(!_ptrc_glProgramUniformMatrix3fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x2dvEXT");
	if(!_ptrc_glProgramUniformMatrix3x2dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x2fvEXT");
	if(!_ptrc_glProgramUniformMatrix3x2fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x4dvEXT");
	if(!_ptrc_glProgramUniformMatrix3x4dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix3x4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x4fvEXT");
	if(!_ptrc_glProgramUniformMatrix3x4fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4dvEXT");
	if(!_ptrc_glProgramUniformMatrix4dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4fvEXT");
	if(!_ptrc_glProgramUniformMatrix4fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x2dvEXT");
	if(!_ptrc_glProgramUniformMatrix4x2dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x2fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x2fvEXT");
	if(!_ptrc_glProgramUniformMatrix4x2fvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x3dvEXT");
	if(!_ptrc_glProgramUniformMatrix4x3dvEXT) numFailed++;
	_ptrc_glProgramUniformMatrix4x3fvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x3fvEXT");
	if(!_ptrc_glProgramUniformMatrix4x3fvEXT) numFailed++;
	_ptrc_glPushClientAttribDefaultEXT = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glPushClientAttribDefaultEXT");
	if(!_ptrc_glPushClientAttribDefaultEXT) numFailed++;
	_ptrc_glTextureBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glTextureBufferEXT");
	if(!_ptrc_glTextureBufferEXT) numFailed++;
	_ptrc_glTextureBufferRangeEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTextureBufferRangeEXT");
	if(!_ptrc_glTextureBufferRangeEXT) numFailed++;
	_ptrc_glTextureImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTextureImage1DEXT");
	if(!_ptrc_glTextureImage1DEXT) numFailed++;
	_ptrc_glTextureImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTextureImage2DEXT");
	if(!_ptrc_glTextureImage2DEXT) numFailed++;
	_ptrc_glTextureImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTextureImage3DEXT");
	if(!_ptrc_glTextureImage3DEXT) numFailed++;
	_ptrc_glTexturePageCommitmentEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexturePageCommitmentEXT");
	if(!_ptrc_glTexturePageCommitmentEXT) numFailed++;
	_ptrc_glTextureParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLint *))IntGetProcAddress("glTextureParameterIivEXT");
	if(!_ptrc_glTextureParameterIivEXT) numFailed++;
	_ptrc_glTextureParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLuint *))IntGetProcAddress("glTextureParameterIuivEXT");
	if(!_ptrc_glTextureParameterIuivEXT) numFailed++;
	_ptrc_glTextureParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLfloat))IntGetProcAddress("glTextureParameterfEXT");
	if(!_ptrc_glTextureParameterfEXT) numFailed++;
	_ptrc_glTextureParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glTextureParameterfvEXT");
	if(!_ptrc_glTextureParameterfvEXT) numFailed++;
	_ptrc_glTextureParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint))IntGetProcAddress("glTextureParameteriEXT");
	if(!_ptrc_glTextureParameteriEXT) numFailed++;
	_ptrc_glTextureParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, const GLint *))IntGetProcAddress("glTextureParameterivEXT");
	if(!_ptrc_glTextureParameterivEXT) numFailed++;
	_ptrc_glTextureRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint))IntGetProcAddress("glTextureRenderbufferEXT");
	if(!_ptrc_glTextureRenderbufferEXT) numFailed++;
	_ptrc_glTextureStorage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTextureStorage1DEXT");
	if(!_ptrc_glTextureStorage1DEXT) numFailed++;
	_ptrc_glTextureStorage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage2DEXT");
	if(!_ptrc_glTextureStorage2DEXT) numFailed++;
	_ptrc_glTextureStorage2DMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage2DMultisampleEXT");
	if(!_ptrc_glTextureStorage2DMultisampleEXT) numFailed++;
	_ptrc_glTextureStorage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTextureStorage3DEXT");
	if(!_ptrc_glTextureStorage3DEXT) numFailed++;
	_ptrc_glTextureStorage3DMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureStorage3DMultisampleEXT");
	if(!_ptrc_glTextureStorage3DMultisampleEXT) numFailed++;
	_ptrc_glTextureSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTextureSubImage1DEXT");
	if(!_ptrc_glTextureSubImage1DEXT) numFailed++;
	_ptrc_glTextureSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTextureSubImage2DEXT");
	if(!_ptrc_glTextureSubImage2DEXT) numFailed++;
	_ptrc_glTextureSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTextureSubImage3DEXT");
	if(!_ptrc_glTextureSubImage3DEXT) numFailed++;
	_ptrc_glUnmapNamedBufferEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glUnmapNamedBufferEXT");
	if(!_ptrc_glUnmapNamedBufferEXT) numFailed++;
	_ptrc_glVertexArrayBindVertexBufferEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glVertexArrayBindVertexBufferEXT");
	if(!_ptrc_glVertexArrayBindVertexBufferEXT) numFailed++;
	_ptrc_glVertexArrayColorOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayColorOffsetEXT");
	if(!_ptrc_glVertexArrayColorOffsetEXT) numFailed++;
	_ptrc_glVertexArrayEdgeFlagOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayEdgeFlagOffsetEXT");
	if(!_ptrc_glVertexArrayEdgeFlagOffsetEXT) numFailed++;
	_ptrc_glVertexArrayFogCoordOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayFogCoordOffsetEXT");
	if(!_ptrc_glVertexArrayFogCoordOffsetEXT) numFailed++;
	_ptrc_glVertexArrayIndexOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayIndexOffsetEXT");
	if(!_ptrc_glVertexArrayIndexOffsetEXT) numFailed++;
	_ptrc_glVertexArrayMultiTexCoordOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayMultiTexCoordOffsetEXT");
	if(!_ptrc_glVertexArrayMultiTexCoordOffsetEXT) numFailed++;
	_ptrc_glVertexArrayNormalOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayNormalOffsetEXT");
	if(!_ptrc_glVertexArrayNormalOffsetEXT) numFailed++;
	_ptrc_glVertexArraySecondaryColorOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArraySecondaryColorOffsetEXT");
	if(!_ptrc_glVertexArraySecondaryColorOffsetEXT) numFailed++;
	_ptrc_glVertexArrayTexCoordOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayTexCoordOffsetEXT");
	if(!_ptrc_glVertexArrayTexCoordOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribBindingEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayVertexAttribBindingEXT");
	if(!_ptrc_glVertexArrayVertexAttribBindingEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribFormatEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexArrayVertexAttribFormatEXT");
	if(!_ptrc_glVertexArrayVertexAttribFormatEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribIFormatEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayVertexAttribIFormatEXT");
	if(!_ptrc_glVertexArrayVertexAttribIFormatEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribIOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexAttribIOffsetEXT");
	if(!_ptrc_glVertexArrayVertexAttribIOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribLFormatEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexArrayVertexAttribLFormatEXT");
	if(!_ptrc_glVertexArrayVertexAttribLFormatEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribLOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexAttribLOffsetEXT");
	if(!_ptrc_glVertexArrayVertexAttribLOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexAttribOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLint, GLenum, GLboolean, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexAttribOffsetEXT");
	if(!_ptrc_glVertexArrayVertexAttribOffsetEXT) numFailed++;
	_ptrc_glVertexArrayVertexBindingDivisorEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexArrayVertexBindingDivisorEXT");
	if(!_ptrc_glVertexArrayVertexBindingDivisorEXT) numFailed++;
	_ptrc_glVertexArrayVertexOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLenum, GLsizei, GLintptr))IntGetProcAddress("glVertexArrayVertexOffsetEXT");
	if(!_ptrc_glVertexArrayVertexOffsetEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorMaskIndexedEXT)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean) = NULL;

static int Load_EXT_draw_buffers2()
{
	int numFailed = 0;
	_ptrc_glColorMaskIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glColorMaskIndexedEXT");
	if(!_ptrc_glColorMaskIndexedEXT) numFailed++;
	_ptrc_glDisableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisableIndexedEXT");
	if(!_ptrc_glDisableIndexedEXT) numFailed++;
	_ptrc_glEnableIndexedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnableIndexedEXT");
	if(!_ptrc_glEnableIndexedEXT) numFailed++;
	_ptrc_glGetBooleanIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLboolean *))IntGetProcAddress("glGetBooleanIndexedvEXT");
	if(!_ptrc_glGetBooleanIndexedvEXT) numFailed++;
	_ptrc_glGetIntegerIndexedvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetIntegerIndexedvEXT");
	if(!_ptrc_glGetIntegerIndexedvEXT) numFailed++;
	_ptrc_glIsEnabledIndexedEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glIsEnabledIndexedEXT");
	if(!_ptrc_glIsEnabledIndexedEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstancedEXT)(GLenum, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstancedEXT)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei) = NULL;

static int Load_EXT_draw_instanced()
{
	int numFailed = 0;
	_ptrc_glDrawArraysInstancedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei))IntGetProcAddress("glDrawArraysInstancedEXT");
	if(!_ptrc_glDrawArraysInstancedEXT) numFailed++;
	_ptrc_glDrawElementsInstancedEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei))IntGetProcAddress("glDrawElementsInstancedEXT");
	if(!_ptrc_glDrawElementsInstancedEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElementsEXT)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *) = NULL;

static int Load_EXT_draw_range_elements()
{
	int numFailed = 0;
	_ptrc_glDrawRangeElementsEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glDrawRangeElementsEXT");
	if(!_ptrc_glDrawRangeElementsEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointerEXT)(GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddEXT)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddvEXT)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfEXT)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfvEXT)(const GLfloat *) = NULL;

static int Load_EXT_fog_coord()
{
	int numFailed = 0;
	_ptrc_glFogCoordPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glFogCoordPointerEXT");
	if(!_ptrc_glFogCoordPointerEXT) numFailed++;
	_ptrc_glFogCoorddEXT = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glFogCoorddEXT");
	if(!_ptrc_glFogCoorddEXT) numFailed++;
	_ptrc_glFogCoorddvEXT = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glFogCoorddvEXT");
	if(!_ptrc_glFogCoorddvEXT) numFailed++;
	_ptrc_glFogCoordfEXT = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glFogCoordfEXT");
	if(!_ptrc_glFogCoordfEXT) numFailed++;
	_ptrc_glFogCoordfvEXT = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glFogCoordfvEXT");
	if(!_ptrc_glFogCoordfvEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlitFramebufferEXT)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum) = NULL;

static int Load_EXT_framebuffer_blit()
{
	int numFailed = 0;
	_ptrc_glBlitFramebufferEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitFramebufferEXT");
	if(!_ptrc_glBlitFramebufferEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleEXT)(GLenum, GLsizei, GLenum, GLsizei, GLsizei) = NULL;

static int Load_EXT_framebuffer_multisample()
{
	int numFailed = 0;
	_ptrc_glRenderbufferStorageMultisampleEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisampleEXT");
	if(!_ptrc_glRenderbufferStorageMultisampleEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFramebufferEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindRenderbufferEXT)(GLenum, GLuint) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glCheckFramebufferStatusEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteFramebuffersEXT)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteRenderbuffersEXT)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferRenderbufferEXT)(GLenum, GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture1DEXT)(GLenum, GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture2DEXT)(GLenum, GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture3DEXT)(GLenum, GLenum, GLenum, GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenFramebuffersEXT)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenRenderbuffersEXT)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenerateMipmapEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFramebufferAttachmentParameterivEXT)(GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetRenderbufferParameterivEXT)(GLenum, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFramebufferEXT)(GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsRenderbufferEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageEXT)(GLenum, GLenum, GLsizei, GLsizei) = NULL;

static int Load_EXT_framebuffer_object()
{
	int numFailed = 0;
	_ptrc_glBindFramebufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindFramebufferEXT");
	if(!_ptrc_glBindFramebufferEXT) numFailed++;
	_ptrc_glBindRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindRenderbufferEXT");
	if(!_ptrc_glBindRenderbufferEXT) numFailed++;
	_ptrc_glCheckFramebufferStatusEXT = (GLenum (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCheckFramebufferStatusEXT");
	if(!_ptrc_glCheckFramebufferStatusEXT) numFailed++;
	_ptrc_glDeleteFramebuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFramebuffersEXT");
	if(!_ptrc_glDeleteFramebuffersEXT) numFailed++;
	_ptrc_glDeleteRenderbuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteRenderbuffersEXT");
	if(!_ptrc_glDeleteRenderbuffersEXT) numFailed++;
	_ptrc_glFramebufferRenderbufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glFramebufferRenderbufferEXT");
	if(!_ptrc_glFramebufferRenderbufferEXT) numFailed++;
	_ptrc_glFramebufferTexture1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture1DEXT");
	if(!_ptrc_glFramebufferTexture1DEXT) numFailed++;
	_ptrc_glFramebufferTexture2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture2DEXT");
	if(!_ptrc_glFramebufferTexture2DEXT) numFailed++;
	_ptrc_glFramebufferTexture3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTexture3DEXT");
	if(!_ptrc_glFramebufferTexture3DEXT) numFailed++;
	_ptrc_glGenFramebuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFramebuffersEXT");
	if(!_ptrc_glGenFramebuffersEXT) numFailed++;
	_ptrc_glGenRenderbuffersEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenRenderbuffersEXT");
	if(!_ptrc_glGenRenderbuffersEXT) numFailed++;
	_ptrc_glGenerateMipmapEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGenerateMipmapEXT");
	if(!_ptrc_glGenerateMipmapEXT) numFailed++;
	_ptrc_glGetFramebufferAttachmentParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
	if(!_ptrc_glGetFramebufferAttachmentParameterivEXT) numFailed++;
	_ptrc_glGetRenderbufferParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetRenderbufferParameterivEXT");
	if(!_ptrc_glGetRenderbufferParameterivEXT) numFailed++;
	_ptrc_glIsFramebufferEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFramebufferEXT");
	if(!_ptrc_glIsFramebufferEXT) numFailed++;
	_ptrc_glIsRenderbufferEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsRenderbufferEXT");
	if(!_ptrc_glIsRenderbufferEXT) numFailed++;
	_ptrc_glRenderbufferStorageEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageEXT");
	if(!_ptrc_glRenderbufferStorageEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProgramParameteriEXT)(GLuint, GLenum, GLint) = NULL;

static int Load_EXT_geometry_shader4()
{
	int numFailed = 0;
	_ptrc_glProgramParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteriEXT");
	if(!_ptrc_glProgramParameteriEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameters4fvEXT)(GLenum, GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameters4fvEXT)(GLenum, GLuint, GLsizei, const GLfloat *) = NULL;

static int Load_EXT_gpu_program_parameters()
{
	int numFailed = 0;
	_ptrc_glProgramEnvParameters4fvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramEnvParameters4fvEXT");
	if(!_ptrc_glProgramEnvParameters4fvEXT) numFailed++;
	_ptrc_glProgramLocalParameters4fvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramLocalParameters4fvEXT");
	if(!_ptrc_glProgramLocalParameters4fvEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocationEXT)(GLuint, GLuint, const GLchar *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocationEXT)(GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuivEXT)(GLuint, GLint, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiEXT)(GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1uivEXT)(GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiEXT)(GLint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2uivEXT)(GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiEXT)(GLint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3uivEXT)(GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiEXT)(GLint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4uivEXT)(GLint, GLsizei, const GLuint *) = NULL;

static int Load_EXT_gpu_shader4()
{
	int numFailed = 0;
	_ptrc_glBindFragDataLocationEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocationEXT");
	if(!_ptrc_glBindFragDataLocationEXT) numFailed++;
	_ptrc_glGetFragDataLocationEXT = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataLocationEXT");
	if(!_ptrc_glGetFragDataLocationEXT) numFailed++;
	_ptrc_glGetUniformuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint *))IntGetProcAddress("glGetUniformuivEXT");
	if(!_ptrc_glGetUniformuivEXT) numFailed++;
	_ptrc_glUniform1uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint))IntGetProcAddress("glUniform1uiEXT");
	if(!_ptrc_glUniform1uiEXT) numFailed++;
	_ptrc_glUniform1uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform1uivEXT");
	if(!_ptrc_glUniform1uivEXT) numFailed++;
	_ptrc_glUniform2uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint))IntGetProcAddress("glUniform2uiEXT");
	if(!_ptrc_glUniform2uiEXT) numFailed++;
	_ptrc_glUniform2uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform2uivEXT");
	if(!_ptrc_glUniform2uivEXT) numFailed++;
	_ptrc_glUniform3uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform3uiEXT");
	if(!_ptrc_glUniform3uiEXT) numFailed++;
	_ptrc_glUniform3uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform3uivEXT");
	if(!_ptrc_glUniform3uivEXT) numFailed++;
	_ptrc_glUniform4uiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform4uiEXT");
	if(!_ptrc_glUniform4uiEXT) numFailed++;
	_ptrc_glUniform4uivEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform4uivEXT");
	if(!_ptrc_glUniform4uivEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramEXT)(GLenum, GLboolean, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterfvEXT)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterivEXT)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxEXT)(GLenum, GLboolean, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterfvEXT)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMinmaxParameterivEXT)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glHistogramEXT)(GLenum, GLsizei, GLenum, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMinmaxEXT)(GLenum, GLenum, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResetHistogramEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResetMinmaxEXT)(GLenum) = NULL;

static int Load_EXT_histogram()
{
	int numFailed = 0;
	_ptrc_glGetHistogramEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetHistogramEXT");
	if(!_ptrc_glGetHistogramEXT) numFailed++;
	_ptrc_glGetHistogramParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetHistogramParameterfvEXT");
	if(!_ptrc_glGetHistogramParameterfvEXT) numFailed++;
	_ptrc_glGetHistogramParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetHistogramParameterivEXT");
	if(!_ptrc_glGetHistogramParameterivEXT) numFailed++;
	_ptrc_glGetMinmaxEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetMinmaxEXT");
	if(!_ptrc_glGetMinmaxEXT) numFailed++;
	_ptrc_glGetMinmaxParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMinmaxParameterfvEXT");
	if(!_ptrc_glGetMinmaxParameterfvEXT) numFailed++;
	_ptrc_glGetMinmaxParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetMinmaxParameterivEXT");
	if(!_ptrc_glGetMinmaxParameterivEXT) numFailed++;
	_ptrc_glHistogramEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLboolean))IntGetProcAddress("glHistogramEXT");
	if(!_ptrc_glHistogramEXT) numFailed++;
	_ptrc_glMinmaxEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLboolean))IntGetProcAddress("glMinmaxEXT");
	if(!_ptrc_glMinmaxEXT) numFailed++;
	_ptrc_glResetHistogramEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glResetHistogramEXT");
	if(!_ptrc_glResetHistogramEXT) numFailed++;
	_ptrc_glResetMinmaxEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glResetMinmaxEXT");
	if(!_ptrc_glResetMinmaxEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glIndexFuncEXT)(GLenum, GLclampf) = NULL;

static int Load_EXT_index_func()
{
	int numFailed = 0;
	_ptrc_glIndexFuncEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLclampf))IntGetProcAddress("glIndexFuncEXT");
	if(!_ptrc_glIndexFuncEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glIndexMaterialEXT)(GLenum, GLenum) = NULL;

static int Load_EXT_index_material()
{
	int numFailed = 0;
	_ptrc_glIndexMaterialEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glIndexMaterialEXT");
	if(!_ptrc_glIndexMaterialEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glApplyTextureEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureLightEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureMaterialEXT)(GLenum, GLenum) = NULL;

static int Load_EXT_light_texture()
{
	int numFailed = 0;
	_ptrc_glApplyTextureEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glApplyTextureEXT");
	if(!_ptrc_glApplyTextureEXT) numFailed++;
	_ptrc_glTextureLightEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glTextureLightEXT");
	if(!_ptrc_glTextureLightEXT) numFailed++;
	_ptrc_glTextureMaterialEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glTextureMaterialEXT");
	if(!_ptrc_glTextureMaterialEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysEXT)(GLenum, const GLint *, const GLsizei *, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsEXT)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei) = NULL;

static int Load_EXT_multi_draw_arrays()
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *, const GLsizei *, GLsizei))IntGetProcAddress("glMultiDrawArraysEXT");
	if(!_ptrc_glMultiDrawArraysEXT) numFailed++;
	_ptrc_glMultiDrawElementsEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei))IntGetProcAddress("glMultiDrawElementsEXT");
	if(!_ptrc_glMultiDrawElementsEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskEXT)(GLclampf, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplePatternEXT)(GLenum) = NULL;

static int Load_EXT_multisample()
{
	int numFailed = 0;
	_ptrc_glSampleMaskEXT = (void (CODEGEN_FUNCPTR *)(GLclampf, GLboolean))IntGetProcAddress("glSampleMaskEXT");
	if(!_ptrc_glSampleMaskEXT) numFailed++;
	_ptrc_glSamplePatternEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glSamplePatternEXT");
	if(!_ptrc_glSamplePatternEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorTableEXT)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableEXT)(GLenum, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfvEXT)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterivEXT)(GLenum, GLenum, GLint *) = NULL;

static int Load_EXT_paletted_texture()
{
	int numFailed = 0;
	_ptrc_glColorTableEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glColorTableEXT");
	if(!_ptrc_glColorTableEXT) numFailed++;
	_ptrc_glGetColorTableEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetColorTableEXT");
	if(!_ptrc_glGetColorTableEXT) numFailed++;
	_ptrc_glGetColorTableParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetColorTableParameterfvEXT");
	if(!_ptrc_glGetColorTableParameterfvEXT) numFailed++;
	_ptrc_glGetColorTableParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetColorTableParameterivEXT");
	if(!_ptrc_glGetColorTableParameterivEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTransformParameterfvEXT)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTransformParameterivEXT)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameterfEXT)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameterfvEXT)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameteriEXT)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTransformParameterivEXT)(GLenum, GLenum, const GLint *) = NULL;

static int Load_EXT_pixel_transform()
{
	int numFailed = 0;
	_ptrc_glGetPixelTransformParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetPixelTransformParameterfvEXT");
	if(!_ptrc_glGetPixelTransformParameterfvEXT) numFailed++;
	_ptrc_glGetPixelTransformParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetPixelTransformParameterivEXT");
	if(!_ptrc_glGetPixelTransformParameterivEXT) numFailed++;
	_ptrc_glPixelTransformParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glPixelTransformParameterfEXT");
	if(!_ptrc_glPixelTransformParameterfEXT) numFailed++;
	_ptrc_glPixelTransformParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glPixelTransformParameterfvEXT");
	if(!_ptrc_glPixelTransformParameterfvEXT) numFailed++;
	_ptrc_glPixelTransformParameteriEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glPixelTransformParameteriEXT");
	if(!_ptrc_glPixelTransformParameteriEXT) numFailed++;
	_ptrc_glPixelTransformParameterivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glPixelTransformParameterivEXT");
	if(!_ptrc_glPixelTransformParameterivEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfEXT)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvEXT)(GLenum, const GLfloat *) = NULL;

static int Load_EXT_point_parameters()
{
	int numFailed = 0;
	_ptrc_glPointParameterfEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPointParameterfEXT");
	if(!_ptrc_glPointParameterfEXT) numFailed++;
	_ptrc_glPointParameterfvEXT = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPointParameterfvEXT");
	if(!_ptrc_glPointParameterfvEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffsetEXT)(GLfloat, GLfloat) = NULL;

static int Load_EXT_polygon_offset()
{
	int numFailed = 0;
	_ptrc_glPolygonOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glPolygonOffsetEXT");
	if(!_ptrc_glPolygonOffsetEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProvokingVertexEXT)(GLenum) = NULL;

static int Load_EXT_provoking_vertex()
{
	int numFailed = 0;
	_ptrc_glProvokingVertexEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glProvokingVertexEXT");
	if(!_ptrc_glProvokingVertexEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bEXT)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bvEXT)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dEXT)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dvEXT)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fEXT)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fvEXT)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3iEXT)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ivEXT)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3sEXT)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3svEXT)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubEXT)(GLubyte, GLubyte, GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubvEXT)(const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uiEXT)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uivEXT)(const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usEXT)(GLushort, GLushort, GLushort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usvEXT)(const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointerEXT)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_EXT_secondary_color()
{
	int numFailed = 0;
	_ptrc_glSecondaryColor3bEXT = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glSecondaryColor3bEXT");
	if(!_ptrc_glSecondaryColor3bEXT) numFailed++;
	_ptrc_glSecondaryColor3bvEXT = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glSecondaryColor3bvEXT");
	if(!_ptrc_glSecondaryColor3bvEXT) numFailed++;
	_ptrc_glSecondaryColor3dEXT = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glSecondaryColor3dEXT");
	if(!_ptrc_glSecondaryColor3dEXT) numFailed++;
	_ptrc_glSecondaryColor3dvEXT = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glSecondaryColor3dvEXT");
	if(!_ptrc_glSecondaryColor3dvEXT) numFailed++;
	_ptrc_glSecondaryColor3fEXT = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glSecondaryColor3fEXT");
	if(!_ptrc_glSecondaryColor3fEXT) numFailed++;
	_ptrc_glSecondaryColor3fvEXT = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glSecondaryColor3fvEXT");
	if(!_ptrc_glSecondaryColor3fvEXT) numFailed++;
	_ptrc_glSecondaryColor3iEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glSecondaryColor3iEXT");
	if(!_ptrc_glSecondaryColor3iEXT) numFailed++;
	_ptrc_glSecondaryColor3ivEXT = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glSecondaryColor3ivEXT");
	if(!_ptrc_glSecondaryColor3ivEXT) numFailed++;
	_ptrc_glSecondaryColor3sEXT = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glSecondaryColor3sEXT");
	if(!_ptrc_glSecondaryColor3sEXT) numFailed++;
	_ptrc_glSecondaryColor3svEXT = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glSecondaryColor3svEXT");
	if(!_ptrc_glSecondaryColor3svEXT) numFailed++;
	_ptrc_glSecondaryColor3ubEXT = (void (CODEGEN_FUNCPTR *)(GLubyte, GLubyte, GLubyte))IntGetProcAddress("glSecondaryColor3ubEXT");
	if(!_ptrc_glSecondaryColor3ubEXT) numFailed++;
	_ptrc_glSecondaryColor3ubvEXT = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glSecondaryColor3ubvEXT");
	if(!_ptrc_glSecondaryColor3ubvEXT) numFailed++;
	_ptrc_glSecondaryColor3uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glSecondaryColor3uiEXT");
	if(!_ptrc_glSecondaryColor3uiEXT) numFailed++;
	_ptrc_glSecondaryColor3uivEXT = (void (CODEGEN_FUNCPTR *)(const GLuint *))IntGetProcAddress("glSecondaryColor3uivEXT");
	if(!_ptrc_glSecondaryColor3uivEXT) numFailed++;
	_ptrc_glSecondaryColor3usEXT = (void (CODEGEN_FUNCPTR *)(GLushort, GLushort, GLushort))IntGetProcAddress("glSecondaryColor3usEXT");
	if(!_ptrc_glSecondaryColor3usEXT) numFailed++;
	_ptrc_glSecondaryColor3usvEXT = (void (CODEGEN_FUNCPTR *)(const GLushort *))IntGetProcAddress("glSecondaryColor3usvEXT");
	if(!_ptrc_glSecondaryColor3usvEXT) numFailed++;
	_ptrc_glSecondaryColorPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glSecondaryColorPointerEXT");
	if(!_ptrc_glSecondaryColorPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveProgramEXT)(GLuint) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShaderProgramEXT)(GLenum, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseShaderProgramEXT)(GLenum, GLuint) = NULL;

static int Load_EXT_separate_shader_objects()
{
	int numFailed = 0;
	_ptrc_glActiveProgramEXT = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glActiveProgramEXT");
	if(!_ptrc_glActiveProgramEXT) numFailed++;
	_ptrc_glCreateShaderProgramEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum, const GLchar *))IntGetProcAddress("glCreateShaderProgramEXT");
	if(!_ptrc_glCreateShaderProgramEXT) numFailed++;
	_ptrc_glUseShaderProgramEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glUseShaderProgramEXT");
	if(!_ptrc_glUseShaderProgramEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindImageTextureEXT)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMemoryBarrierEXT)(GLbitfield) = NULL;

static int Load_EXT_shader_image_load_store()
{
	int numFailed = 0;
	_ptrc_glBindImageTextureEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLint))IntGetProcAddress("glBindImageTextureEXT");
	if(!_ptrc_glBindImageTextureEXT) numFailed++;
	_ptrc_glMemoryBarrierEXT = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrierEXT");
	if(!_ptrc_glMemoryBarrierEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glStencilClearTagEXT)(GLsizei, GLuint) = NULL;

static int Load_EXT_stencil_clear_tag()
{
	int numFailed = 0;
	_ptrc_glStencilClearTagEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint))IntGetProcAddress("glStencilClearTagEXT");
	if(!_ptrc_glStencilClearTagEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveStencilFaceEXT)(GLenum) = NULL;

static int Load_EXT_stencil_two_side()
{
	int numFailed = 0;
	_ptrc_glActiveStencilFaceEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glActiveStencilFaceEXT");
	if(!_ptrc_glActiveStencilFaceEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage1DEXT)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage2DEXT)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;

static int Load_EXT_subtexture()
{
	int numFailed = 0;
	_ptrc_glTexSubImage1DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexSubImage1DEXT");
	if(!_ptrc_glTexSubImage1DEXT) numFailed++;
	_ptrc_glTexSubImage2DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexSubImage2DEXT");
	if(!_ptrc_glTexSubImage2DEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DEXT)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3DEXT)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;

static int Load_EXT_texture3D()
{
	int numFailed = 0;
	_ptrc_glTexImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexImage3DEXT");
	if(!_ptrc_glTexImage3DEXT) numFailed++;
	_ptrc_glTexSubImage3DEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexSubImage3DEXT");
	if(!_ptrc_glTexSubImage3DEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexBufferEXT)(GLenum, GLenum, GLuint) = NULL;

static int Load_EXT_texture_buffer_object()
{
	int numFailed = 0;
	_ptrc_glTexBufferEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glTexBufferEXT");
	if(!_ptrc_glTexBufferEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearColorIiEXT)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearColorIuiEXT)(GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIivEXT)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuivEXT)(GLenum, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIivEXT)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuivEXT)(GLenum, GLenum, const GLuint *) = NULL;

static int Load_EXT_texture_integer()
{
	int numFailed = 0;
	_ptrc_glClearColorIiEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glClearColorIiEXT");
	if(!_ptrc_glClearColorIiEXT) numFailed++;
	_ptrc_glClearColorIuiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glClearColorIuiEXT");
	if(!_ptrc_glClearColorIuiEXT) numFailed++;
	_ptrc_glGetTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexParameterIivEXT");
	if(!_ptrc_glGetTexParameterIivEXT) numFailed++;
	_ptrc_glGetTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint *))IntGetProcAddress("glGetTexParameterIuivEXT");
	if(!_ptrc_glGetTexParameterIuivEXT) numFailed++;
	_ptrc_glTexParameterIivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexParameterIivEXT");
	if(!_ptrc_glTexParameterIivEXT) numFailed++;
	_ptrc_glTexParameterIuivEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glTexParameterIuivEXT");
	if(!_ptrc_glTexParameterIuivEXT) numFailed++;
	return numFailed;
}

GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreTexturesResidentEXT)(GLsizei, const GLuint *, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindTextureEXT)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTexturesEXT)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTexturesEXT)(GLsizei, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTexturesEXT)(GLsizei, const GLuint *, const GLclampf *) = NULL;

static int Load_EXT_texture_object()
{
	int numFailed = 0;
	_ptrc_glAreTexturesResidentEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLboolean *))IntGetProcAddress("glAreTexturesResidentEXT");
	if(!_ptrc_glAreTexturesResidentEXT) numFailed++;
	_ptrc_glBindTextureEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTextureEXT");
	if(!_ptrc_glBindTextureEXT) numFailed++;
	_ptrc_glDeleteTexturesEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTexturesEXT");
	if(!_ptrc_glDeleteTexturesEXT) numFailed++;
	_ptrc_glGenTexturesEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTexturesEXT");
	if(!_ptrc_glGenTexturesEXT) numFailed++;
	_ptrc_glIsTextureEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTextureEXT");
	if(!_ptrc_glIsTextureEXT) numFailed++;
	_ptrc_glPrioritizeTexturesEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, const GLclampf *))IntGetProcAddress("glPrioritizeTexturesEXT");
	if(!_ptrc_glPrioritizeTexturesEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTextureNormalEXT)(GLenum) = NULL;

static int Load_EXT_texture_perturb_normal()
{
	int numFailed = 0;
	_ptrc_glTextureNormalEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glTextureNormalEXT");
	if(!_ptrc_glTextureNormalEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjecti64vEXT)(GLuint, GLenum, GLint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectui64vEXT)(GLuint, GLenum, GLuint64 *) = NULL;

static int Load_EXT_timer_query()
{
	int numFailed = 0;
	_ptrc_glGetQueryObjecti64vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetQueryObjecti64vEXT");
	if(!_ptrc_glGetQueryObjecti64vEXT) numFailed++;
	_ptrc_glGetQueryObjectui64vEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64 *))IntGetProcAddress("glGetQueryObjectui64vEXT");
	if(!_ptrc_glGetQueryObjectui64vEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedbackEXT)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBaseEXT)(GLenum, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferOffsetEXT)(GLenum, GLuint, GLuint, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRangeEXT)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedbackEXT)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVaryingEXT)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryingsEXT)(GLuint, GLsizei, const GLchar *const*, GLenum) = NULL;

static int Load_EXT_transform_feedback()
{
	int numFailed = 0;
	_ptrc_glBeginTransformFeedbackEXT = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBeginTransformFeedbackEXT");
	if(!_ptrc_glBeginTransformFeedbackEXT) numFailed++;
	_ptrc_glBindBufferBaseEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBindBufferBaseEXT");
	if(!_ptrc_glBindBufferBaseEXT) numFailed++;
	_ptrc_glBindBufferOffsetEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr))IntGetProcAddress("glBindBufferOffsetEXT");
	if(!_ptrc_glBindBufferOffsetEXT) numFailed++;
	_ptrc_glBindBufferRangeEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glBindBufferRangeEXT");
	if(!_ptrc_glBindBufferRangeEXT) numFailed++;
	_ptrc_glEndTransformFeedbackEXT = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndTransformFeedbackEXT");
	if(!_ptrc_glEndTransformFeedbackEXT) numFailed++;
	_ptrc_glGetTransformFeedbackVaryingEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *))IntGetProcAddress("glGetTransformFeedbackVaryingEXT");
	if(!_ptrc_glGetTransformFeedbackVaryingEXT) numFailed++;
	_ptrc_glTransformFeedbackVaryingsEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, GLenum))IntGetProcAddress("glTransformFeedbackVaryingsEXT");
	if(!_ptrc_glTransformFeedbackVaryingsEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glArrayElementEXT)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysEXT)(GLenum, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointerEXT)(GLsizei, GLsizei, const GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPointervEXT)(GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexPointerEXT)(GLenum, GLsizei, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalPointerEXT)(GLenum, GLsizei, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexPointerEXT)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *) = NULL;

static int Load_EXT_vertex_array()
{
	int numFailed = 0;
	_ptrc_glArrayElementEXT = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glArrayElementEXT");
	if(!_ptrc_glArrayElementEXT) numFailed++;
	_ptrc_glColorPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *))IntGetProcAddress("glColorPointerEXT");
	if(!_ptrc_glColorPointerEXT) numFailed++;
	_ptrc_glDrawArraysEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei))IntGetProcAddress("glDrawArraysEXT");
	if(!_ptrc_glDrawArraysEXT) numFailed++;
	_ptrc_glEdgeFlagPointerEXT = (void (CODEGEN_FUNCPTR *)(GLsizei, GLsizei, const GLboolean *))IntGetProcAddress("glEdgeFlagPointerEXT");
	if(!_ptrc_glEdgeFlagPointerEXT) numFailed++;
	_ptrc_glGetPointervEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLvoid **))IntGetProcAddress("glGetPointervEXT");
	if(!_ptrc_glGetPointervEXT) numFailed++;
	_ptrc_glIndexPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, const GLvoid *))IntGetProcAddress("glIndexPointerEXT");
	if(!_ptrc_glIndexPointerEXT) numFailed++;
	_ptrc_glNormalPointerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, const GLvoid *))IntGetProcAddress("glNormalPointerEXT");
	if(!_ptrc_glNormalPointerEXT) numFailed++;
	_ptrc_glTexCoordPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *))IntGetProcAddress("glTexCoordPointerEXT");
	if(!_ptrc_glTexCoordPointerEXT) numFailed++;
	_ptrc_glVertexPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, GLsizei, const GLvoid *))IntGetProcAddress("glVertexPointerEXT");
	if(!_ptrc_glVertexPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLdvEXT)(GLuint, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dEXT)(GLuint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1dvEXT)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dEXT)(GLuint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2dvEXT)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dEXT)(GLuint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3dvEXT)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dEXT)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4dvEXT)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLPointerEXT)(GLuint, GLint, GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_EXT_vertex_attrib_64bit()
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribLdvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribLdvEXT");
	if(!_ptrc_glGetVertexAttribLdvEXT) numFailed++;
	_ptrc_glVertexAttribL1dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttribL1dEXT");
	if(!_ptrc_glVertexAttribL1dEXT) numFailed++;
	_ptrc_glVertexAttribL1dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL1dvEXT");
	if(!_ptrc_glVertexAttribL1dvEXT) numFailed++;
	_ptrc_glVertexAttribL2dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL2dEXT");
	if(!_ptrc_glVertexAttribL2dEXT) numFailed++;
	_ptrc_glVertexAttribL2dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL2dvEXT");
	if(!_ptrc_glVertexAttribL2dvEXT) numFailed++;
	_ptrc_glVertexAttribL3dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL3dEXT");
	if(!_ptrc_glVertexAttribL3dEXT) numFailed++;
	_ptrc_glVertexAttribL3dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL3dvEXT");
	if(!_ptrc_glVertexAttribL3dvEXT) numFailed++;
	_ptrc_glVertexAttribL4dEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL4dEXT");
	if(!_ptrc_glVertexAttribL4dEXT) numFailed++;
	_ptrc_glVertexAttribL4dvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL4dvEXT");
	if(!_ptrc_glVertexAttribL4dvEXT) numFailed++;
	_ptrc_glVertexAttribLPointerEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribLPointerEXT");
	if(!_ptrc_glVertexAttribLPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginVertexShaderEXT)() = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glBindLightParameterEXT)(GLenum, GLenum) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glBindMaterialParameterEXT)(GLenum, GLenum) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glBindParameterEXT)(GLenum) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glBindTexGenParameterEXT)(GLenum, GLenum, GLenum) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glBindTextureUnitParameterEXT)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindVertexShaderEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteVertexShaderEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVariantClientStateEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVariantClientStateEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndVertexShaderEXT)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glExtractComponentEXT)(GLuint, GLuint, GLuint) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGenSymbolsEXT)(GLenum, GLenum, GLenum, GLuint) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGenVertexShadersEXT)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInvariantBooleanvEXT)(GLuint, GLenum, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInvariantFloatvEXT)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInvariantIntegervEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetLocalConstantBooleanvEXT)(GLuint, GLenum, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetLocalConstantFloatvEXT)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetLocalConstantIntegervEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVariantBooleanvEXT)(GLuint, GLenum, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVariantFloatvEXT)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVariantIntegervEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVariantPointervEXT)(GLuint, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInsertComponentEXT)(GLuint, GLuint, GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsVariantEnabledEXT)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSetInvariantEXT)(GLuint, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSetLocalConstantEXT)(GLuint, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderOp1EXT)(GLenum, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderOp2EXT)(GLenum, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderOp3EXT)(GLenum, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSwizzleEXT)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantPointerEXT)(GLuint, GLenum, GLuint, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantbvEXT)(GLuint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantdvEXT)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantfvEXT)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantivEXT)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantsvEXT)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantubvEXT)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantuivEXT)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVariantusvEXT)(GLuint, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWriteMaskEXT)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum) = NULL;

static int Load_EXT_vertex_shader()
{
	int numFailed = 0;
	_ptrc_glBeginVertexShaderEXT = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glBeginVertexShaderEXT");
	if(!_ptrc_glBeginVertexShaderEXT) numFailed++;
	_ptrc_glBindLightParameterEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBindLightParameterEXT");
	if(!_ptrc_glBindLightParameterEXT) numFailed++;
	_ptrc_glBindMaterialParameterEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBindMaterialParameterEXT");
	if(!_ptrc_glBindMaterialParameterEXT) numFailed++;
	_ptrc_glBindParameterEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBindParameterEXT");
	if(!_ptrc_glBindParameterEXT) numFailed++;
	_ptrc_glBindTexGenParameterEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum))IntGetProcAddress("glBindTexGenParameterEXT");
	if(!_ptrc_glBindTexGenParameterEXT) numFailed++;
	_ptrc_glBindTextureUnitParameterEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBindTextureUnitParameterEXT");
	if(!_ptrc_glBindTextureUnitParameterEXT) numFailed++;
	_ptrc_glBindVertexShaderEXT = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindVertexShaderEXT");
	if(!_ptrc_glBindVertexShaderEXT) numFailed++;
	_ptrc_glDeleteVertexShaderEXT = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDeleteVertexShaderEXT");
	if(!_ptrc_glDeleteVertexShaderEXT) numFailed++;
	_ptrc_glDisableVariantClientStateEXT = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDisableVariantClientStateEXT");
	if(!_ptrc_glDisableVariantClientStateEXT) numFailed++;
	_ptrc_glEnableVariantClientStateEXT = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEnableVariantClientStateEXT");
	if(!_ptrc_glEnableVariantClientStateEXT) numFailed++;
	_ptrc_glEndVertexShaderEXT = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndVertexShaderEXT");
	if(!_ptrc_glEndVertexShaderEXT) numFailed++;
	_ptrc_glExtractComponentEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glExtractComponentEXT");
	if(!_ptrc_glExtractComponentEXT) numFailed++;
	_ptrc_glGenSymbolsEXT = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glGenSymbolsEXT");
	if(!_ptrc_glGenSymbolsEXT) numFailed++;
	_ptrc_glGenVertexShadersEXT = (GLuint (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glGenVertexShadersEXT");
	if(!_ptrc_glGenVertexShadersEXT) numFailed++;
	_ptrc_glGetInvariantBooleanvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean *))IntGetProcAddress("glGetInvariantBooleanvEXT");
	if(!_ptrc_glGetInvariantBooleanvEXT) numFailed++;
	_ptrc_glGetInvariantFloatvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetInvariantFloatvEXT");
	if(!_ptrc_glGetInvariantFloatvEXT) numFailed++;
	_ptrc_glGetInvariantIntegervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetInvariantIntegervEXT");
	if(!_ptrc_glGetInvariantIntegervEXT) numFailed++;
	_ptrc_glGetLocalConstantBooleanvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean *))IntGetProcAddress("glGetLocalConstantBooleanvEXT");
	if(!_ptrc_glGetLocalConstantBooleanvEXT) numFailed++;
	_ptrc_glGetLocalConstantFloatvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetLocalConstantFloatvEXT");
	if(!_ptrc_glGetLocalConstantFloatvEXT) numFailed++;
	_ptrc_glGetLocalConstantIntegervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetLocalConstantIntegervEXT");
	if(!_ptrc_glGetLocalConstantIntegervEXT) numFailed++;
	_ptrc_glGetVariantBooleanvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean *))IntGetProcAddress("glGetVariantBooleanvEXT");
	if(!_ptrc_glGetVariantBooleanvEXT) numFailed++;
	_ptrc_glGetVariantFloatvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVariantFloatvEXT");
	if(!_ptrc_glGetVariantFloatvEXT) numFailed++;
	_ptrc_glGetVariantIntegervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVariantIntegervEXT");
	if(!_ptrc_glGetVariantIntegervEXT) numFailed++;
	_ptrc_glGetVariantPointervEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLvoid **))IntGetProcAddress("glGetVariantPointervEXT");
	if(!_ptrc_glGetVariantPointervEXT) numFailed++;
	_ptrc_glInsertComponentEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glInsertComponentEXT");
	if(!_ptrc_glInsertComponentEXT) numFailed++;
	_ptrc_glIsVariantEnabledEXT = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glIsVariantEnabledEXT");
	if(!_ptrc_glIsVariantEnabledEXT) numFailed++;
	_ptrc_glSetInvariantEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLvoid *))IntGetProcAddress("glSetInvariantEXT");
	if(!_ptrc_glSetInvariantEXT) numFailed++;
	_ptrc_glSetLocalConstantEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLvoid *))IntGetProcAddress("glSetLocalConstantEXT");
	if(!_ptrc_glSetLocalConstantEXT) numFailed++;
	_ptrc_glShaderOp1EXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glShaderOp1EXT");
	if(!_ptrc_glShaderOp1EXT) numFailed++;
	_ptrc_glShaderOp2EXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint))IntGetProcAddress("glShaderOp2EXT");
	if(!_ptrc_glShaderOp2EXT) numFailed++;
	_ptrc_glShaderOp3EXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glShaderOp3EXT");
	if(!_ptrc_glShaderOp3EXT) numFailed++;
	_ptrc_glSwizzleEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glSwizzleEXT");
	if(!_ptrc_glSwizzleEXT) numFailed++;
	_ptrc_glVariantPointerEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, const GLvoid *))IntGetProcAddress("glVariantPointerEXT");
	if(!_ptrc_glVariantPointerEXT) numFailed++;
	_ptrc_glVariantbvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVariantbvEXT");
	if(!_ptrc_glVariantbvEXT) numFailed++;
	_ptrc_glVariantdvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVariantdvEXT");
	if(!_ptrc_glVariantdvEXT) numFailed++;
	_ptrc_glVariantfvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVariantfvEXT");
	if(!_ptrc_glVariantfvEXT) numFailed++;
	_ptrc_glVariantivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVariantivEXT");
	if(!_ptrc_glVariantivEXT) numFailed++;
	_ptrc_glVariantsvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVariantsvEXT");
	if(!_ptrc_glVariantsvEXT) numFailed++;
	_ptrc_glVariantubvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVariantubvEXT");
	if(!_ptrc_glVariantubvEXT) numFailed++;
	_ptrc_glVariantuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVariantuivEXT");
	if(!_ptrc_glVariantuivEXT) numFailed++;
	_ptrc_glVariantusvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVariantusvEXT");
	if(!_ptrc_glVariantusvEXT) numFailed++;
	_ptrc_glWriteMaskEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glWriteMaskEXT");
	if(!_ptrc_glWriteMaskEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glVertexWeightPointerEXT)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexWeightfEXT)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexWeightfvEXT)(const GLfloat *) = NULL;

static int Load_EXT_vertex_weighting()
{
	int numFailed = 0;
	_ptrc_glVertexWeightPointerEXT = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexWeightPointerEXT");
	if(!_ptrc_glVertexWeightPointerEXT) numFailed++;
	_ptrc_glVertexWeightfEXT = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glVertexWeightfEXT");
	if(!_ptrc_glVertexWeightfEXT) numFailed++;
	_ptrc_glVertexWeightfvEXT = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glVertexWeightfvEXT");
	if(!_ptrc_glVertexWeightfvEXT) numFailed++;
	return numFailed;
}

GLsync (CODEGEN_FUNCPTR *_ptrc_glImportSyncEXT)(GLenum, GLintptr, GLbitfield) = NULL;

static int Load_EXT_x11_sync_object()
{
	int numFailed = 0;
	_ptrc_glImportSyncEXT = (GLsync (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLbitfield))IntGetProcAddress("glImportSyncEXT");
	if(!_ptrc_glImportSyncEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFrameTerminatorGREMEDY)() = NULL;

static int Load_GREMEDY_frame_terminator()
{
	int numFailed = 0;
	_ptrc_glFrameTerminatorGREMEDY = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glFrameTerminatorGREMEDY");
	if(!_ptrc_glFrameTerminatorGREMEDY) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glStringMarkerGREMEDY)(GLsizei, const GLvoid *) = NULL;

static int Load_GREMEDY_string_marker()
{
	int numFailed = 0;
	_ptrc_glStringMarkerGREMEDY = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLvoid *))IntGetProcAddress("glStringMarkerGREMEDY");
	if(!_ptrc_glStringMarkerGREMEDY) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetImageTransformParameterfvHP)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetImageTransformParameterivHP)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameterfHP)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameterfvHP)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameteriHP)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glImageTransformParameterivHP)(GLenum, GLenum, const GLint *) = NULL;

static int Load_HP_image_transform()
{
	int numFailed = 0;
	_ptrc_glGetImageTransformParameterfvHP = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetImageTransformParameterfvHP");
	if(!_ptrc_glGetImageTransformParameterfvHP) numFailed++;
	_ptrc_glGetImageTransformParameterivHP = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetImageTransformParameterivHP");
	if(!_ptrc_glGetImageTransformParameterivHP) numFailed++;
	_ptrc_glImageTransformParameterfHP = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glImageTransformParameterfHP");
	if(!_ptrc_glImageTransformParameterfHP) numFailed++;
	_ptrc_glImageTransformParameterfvHP = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glImageTransformParameterfvHP");
	if(!_ptrc_glImageTransformParameterfvHP) numFailed++;
	_ptrc_glImageTransformParameteriHP = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glImageTransformParameteriHP");
	if(!_ptrc_glImageTransformParameteriHP) numFailed++;
	_ptrc_glImageTransformParameterivHP = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glImageTransformParameterivHP");
	if(!_ptrc_glImageTransformParameterivHP) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiModeDrawArraysIBM)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiModeDrawElementsIBM)(const GLenum *, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, GLint) = NULL;

static int Load_IBM_multimode_draw_arrays()
{
	int numFailed = 0;
	_ptrc_glMultiModeDrawArraysIBM = (void (CODEGEN_FUNCPTR *)(const GLenum *, const GLint *, const GLsizei *, GLsizei, GLint))IntGetProcAddress("glMultiModeDrawArraysIBM");
	if(!_ptrc_glMultiModeDrawArraysIBM) numFailed++;
	_ptrc_glMultiModeDrawElementsIBM = (void (CODEGEN_FUNCPTR *)(const GLenum *, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, GLint))IntGetProcAddress("glMultiModeDrawElementsIBM");
	if(!_ptrc_glMultiModeDrawElementsIBM) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushStaticDataIBM)(GLenum) = NULL;

static int Load_IBM_static_data()
{
	int numFailed = 0;
	_ptrc_glFlushStaticDataIBM = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glFlushStaticDataIBM");
	if(!_ptrc_glFlushStaticDataIBM) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointerListIBM)(GLint, const GLboolean **, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointerListIBM)(GLenum, GLint, const GLvoid **, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexPointerListIBM)(GLenum, GLint, const GLvoid **, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalPointerListIBM)(GLenum, GLint, const GLvoid **, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexPointerListIBM)(GLint, GLenum, GLint, const GLvoid **, GLint) = NULL;

static int Load_IBM_vertex_array_lists()
{
	int numFailed = 0;
	_ptrc_glColorPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLint, const GLvoid **, GLint))IntGetProcAddress("glColorPointerListIBM");
	if(!_ptrc_glColorPointerListIBM) numFailed++;
	_ptrc_glEdgeFlagPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLint, const GLboolean **, GLint))IntGetProcAddress("glEdgeFlagPointerListIBM");
	if(!_ptrc_glEdgeFlagPointerListIBM) numFailed++;
	_ptrc_glFogCoordPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLvoid **, GLint))IntGetProcAddress("glFogCoordPointerListIBM");
	if(!_ptrc_glFogCoordPointerListIBM) numFailed++;
	_ptrc_glIndexPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLvoid **, GLint))IntGetProcAddress("glIndexPointerListIBM");
	if(!_ptrc_glIndexPointerListIBM) numFailed++;
	_ptrc_glNormalPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLvoid **, GLint))IntGetProcAddress("glNormalPointerListIBM");
	if(!_ptrc_glNormalPointerListIBM) numFailed++;
	_ptrc_glSecondaryColorPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLint, const GLvoid **, GLint))IntGetProcAddress("glSecondaryColorPointerListIBM");
	if(!_ptrc_glSecondaryColorPointerListIBM) numFailed++;
	_ptrc_glTexCoordPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLint, const GLvoid **, GLint))IntGetProcAddress("glTexCoordPointerListIBM");
	if(!_ptrc_glTexCoordPointerListIBM) numFailed++;
	_ptrc_glVertexPointerListIBM = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLint, const GLvoid **, GLint))IntGetProcAddress("glVertexPointerListIBM");
	if(!_ptrc_glVertexPointerListIBM) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparateINGR)(GLenum, GLenum, GLenum, GLenum) = NULL;

static int Load_INGR_blend_func_separate()
{
	int numFailed = 0;
	_ptrc_glBlendFuncSeparateINGR = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparateINGR");
	if(!_ptrc_glBlendFuncSeparateINGR) numFailed++;
	return numFailed;
}

void * (CODEGEN_FUNCPTR *_ptrc_glMapTexture2DINTEL)(GLuint, GLint, GLbitfield, const GLint *, const GLenum *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSyncTextureINTEL)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUnmapTexture2DINTEL)(GLuint, GLint) = NULL;

static int Load_INTEL_map_texture()
{
	int numFailed = 0;
	_ptrc_glMapTexture2DINTEL = (void * (CODEGEN_FUNCPTR *)(GLuint, GLint, GLbitfield, const GLint *, const GLenum *))IntGetProcAddress("glMapTexture2DINTEL");
	if(!_ptrc_glMapTexture2DINTEL) numFailed++;
	_ptrc_glSyncTextureINTEL = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glSyncTextureINTEL");
	if(!_ptrc_glSyncTextureINTEL) numFailed++;
	_ptrc_glUnmapTexture2DINTEL = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glUnmapTexture2DINTEL");
	if(!_ptrc_glUnmapTexture2DINTEL) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorPointervINTEL)(GLint, GLenum, const GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalPointervINTEL)(GLenum, const GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointervINTEL)(GLint, GLenum, const GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexPointervINTEL)(GLint, GLenum, const GLvoid **) = NULL;

static int Load_INTEL_parallel_arrays()
{
	int numFailed = 0;
	_ptrc_glColorPointervINTEL = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, const GLvoid **))IntGetProcAddress("glColorPointervINTEL");
	if(!_ptrc_glColorPointervINTEL) numFailed++;
	_ptrc_glNormalPointervINTEL = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid **))IntGetProcAddress("glNormalPointervINTEL");
	if(!_ptrc_glNormalPointervINTEL) numFailed++;
	_ptrc_glTexCoordPointervINTEL = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, const GLvoid **))IntGetProcAddress("glTexCoordPointervINTEL");
	if(!_ptrc_glTexCoordPointervINTEL) numFailed++;
	_ptrc_glVertexPointervINTEL = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, const GLvoid **))IntGetProcAddress("glVertexPointervINTEL");
	if(!_ptrc_glVertexPointervINTEL) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glResizeBuffersMESA)() = NULL;

static int Load_MESA_resize_buffers()
{
	int numFailed = 0;
	_ptrc_glResizeBuffersMESA = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glResizeBuffersMESA");
	if(!_ptrc_glResizeBuffersMESA) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dMESA)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dvMESA)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fMESA)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fvMESA)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iMESA)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2ivMESA)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sMESA)(GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2svMESA)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dMESA)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dvMESA)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fMESA)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fvMESA)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iMESA)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3ivMESA)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sMESA)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3svMESA)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4dMESA)(GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4dvMESA)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4fMESA)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4fvMESA)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4iMESA)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4ivMESA)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4sMESA)(GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos4svMESA)(const GLshort *) = NULL;

static int Load_MESA_window_pos()
{
	int numFailed = 0;
	_ptrc_glWindowPos2dMESA = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glWindowPos2dMESA");
	if(!_ptrc_glWindowPos2dMESA) numFailed++;
	_ptrc_glWindowPos2dvMESA = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos2dvMESA");
	if(!_ptrc_glWindowPos2dvMESA) numFailed++;
	_ptrc_glWindowPos2fMESA = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glWindowPos2fMESA");
	if(!_ptrc_glWindowPos2fMESA) numFailed++;
	_ptrc_glWindowPos2fvMESA = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos2fvMESA");
	if(!_ptrc_glWindowPos2fvMESA) numFailed++;
	_ptrc_glWindowPos2iMESA = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glWindowPos2iMESA");
	if(!_ptrc_glWindowPos2iMESA) numFailed++;
	_ptrc_glWindowPos2ivMESA = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos2ivMESA");
	if(!_ptrc_glWindowPos2ivMESA) numFailed++;
	_ptrc_glWindowPos2sMESA = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort))IntGetProcAddress("glWindowPos2sMESA");
	if(!_ptrc_glWindowPos2sMESA) numFailed++;
	_ptrc_glWindowPos2svMESA = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos2svMESA");
	if(!_ptrc_glWindowPos2svMESA) numFailed++;
	_ptrc_glWindowPos3dMESA = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glWindowPos3dMESA");
	if(!_ptrc_glWindowPos3dMESA) numFailed++;
	_ptrc_glWindowPos3dvMESA = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos3dvMESA");
	if(!_ptrc_glWindowPos3dvMESA) numFailed++;
	_ptrc_glWindowPos3fMESA = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glWindowPos3fMESA");
	if(!_ptrc_glWindowPos3fMESA) numFailed++;
	_ptrc_glWindowPos3fvMESA = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos3fvMESA");
	if(!_ptrc_glWindowPos3fvMESA) numFailed++;
	_ptrc_glWindowPos3iMESA = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glWindowPos3iMESA");
	if(!_ptrc_glWindowPos3iMESA) numFailed++;
	_ptrc_glWindowPos3ivMESA = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos3ivMESA");
	if(!_ptrc_glWindowPos3ivMESA) numFailed++;
	_ptrc_glWindowPos3sMESA = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glWindowPos3sMESA");
	if(!_ptrc_glWindowPos3sMESA) numFailed++;
	_ptrc_glWindowPos3svMESA = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos3svMESA");
	if(!_ptrc_glWindowPos3svMESA) numFailed++;
	_ptrc_glWindowPos4dMESA = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glWindowPos4dMESA");
	if(!_ptrc_glWindowPos4dMESA) numFailed++;
	_ptrc_glWindowPos4dvMESA = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos4dvMESA");
	if(!_ptrc_glWindowPos4dvMESA) numFailed++;
	_ptrc_glWindowPos4fMESA = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glWindowPos4fMESA");
	if(!_ptrc_glWindowPos4fMESA) numFailed++;
	_ptrc_glWindowPos4fvMESA = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos4fvMESA");
	if(!_ptrc_glWindowPos4fvMESA) numFailed++;
	_ptrc_glWindowPos4iMESA = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glWindowPos4iMESA");
	if(!_ptrc_glWindowPos4iMESA) numFailed++;
	_ptrc_glWindowPos4ivMESA = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos4ivMESA");
	if(!_ptrc_glWindowPos4ivMESA) numFailed++;
	_ptrc_glWindowPos4sMESA = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glWindowPos4sMESA");
	if(!_ptrc_glWindowPos4sMESA) numFailed++;
	_ptrc_glWindowPos4svMESA = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos4svMESA");
	if(!_ptrc_glWindowPos4svMESA) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNVX)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNVX)() = NULL;

static int Load_NVX_conditional_render()
{
	int numFailed = 0;
	_ptrc_glBeginConditionalRenderNVX = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBeginConditionalRenderNVX");
	if(!_ptrc_glBeginConditionalRenderNVX) numFailed++;
	_ptrc_glEndConditionalRenderNVX = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndConditionalRenderNVX");
	if(!_ptrc_glEndConditionalRenderNVX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArraysIndirectBindlessNV)(GLenum, const GLvoid *, GLsizei, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElementsIndirectBindlessNV)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei, GLint) = NULL;

static int Load_NV_bindless_multi_draw_indirect()
{
	int numFailed = 0;
	_ptrc_glMultiDrawArraysIndirectBindlessNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid *, GLsizei, GLsizei, GLint))IntGetProcAddress("glMultiDrawArraysIndirectBindlessNV");
	if(!_ptrc_glMultiDrawArraysIndirectBindlessNV) numFailed++;
	_ptrc_glMultiDrawElementsIndirectBindlessNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLvoid *, GLsizei, GLsizei, GLint))IntGetProcAddress("glMultiDrawElementsIndirectBindlessNV");
	if(!_ptrc_glMultiDrawElementsIndirectBindlessNV) numFailed++;
	return numFailed;
}

GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetImageHandleNV)(GLuint, GLint, GLboolean, GLint, GLenum) = NULL;
GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureHandleNV)(GLuint) = NULL;
GLuint64 (CODEGEN_FUNCPTR *_ptrc_glGetTextureSamplerHandleNV)(GLuint, GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsImageHandleResidentNV)(GLuint64) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTextureHandleResidentNV)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleNonResidentNV)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeImageHandleResidentNV)(GLuint64, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleNonResidentNV)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeTextureHandleResidentNV)(GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64NV)(GLuint, GLint, GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformHandleui64vNV)(GLuint, GLint, GLsizei, const GLuint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64NV)(GLint, GLuint64) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformHandleui64vNV)(GLint, GLsizei, const GLuint64 *) = NULL;

static int Load_NV_bindless_texture()
{
	int numFailed = 0;
	_ptrc_glGetImageHandleNV = (GLuint64 (CODEGEN_FUNCPTR *)(GLuint, GLint, GLboolean, GLint, GLenum))IntGetProcAddress("glGetImageHandleNV");
	if(!_ptrc_glGetImageHandleNV) numFailed++;
	_ptrc_glGetTextureHandleNV = (GLuint64 (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glGetTextureHandleNV");
	if(!_ptrc_glGetTextureHandleNV) numFailed++;
	_ptrc_glGetTextureSamplerHandleNV = (GLuint64 (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glGetTextureSamplerHandleNV");
	if(!_ptrc_glGetTextureSamplerHandleNV) numFailed++;
	_ptrc_glIsImageHandleResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glIsImageHandleResidentNV");
	if(!_ptrc_glIsImageHandleResidentNV) numFailed++;
	_ptrc_glIsTextureHandleResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glIsTextureHandleResidentNV");
	if(!_ptrc_glIsTextureHandleResidentNV) numFailed++;
	_ptrc_glMakeImageHandleNonResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glMakeImageHandleNonResidentNV");
	if(!_ptrc_glMakeImageHandleNonResidentNV) numFailed++;
	_ptrc_glMakeImageHandleResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint64, GLenum))IntGetProcAddress("glMakeImageHandleResidentNV");
	if(!_ptrc_glMakeImageHandleResidentNV) numFailed++;
	_ptrc_glMakeTextureHandleNonResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glMakeTextureHandleNonResidentNV");
	if(!_ptrc_glMakeTextureHandleNonResidentNV) numFailed++;
	_ptrc_glMakeTextureHandleResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint64))IntGetProcAddress("glMakeTextureHandleResidentNV");
	if(!_ptrc_glMakeTextureHandleResidentNV) numFailed++;
	_ptrc_glProgramUniformHandleui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64))IntGetProcAddress("glProgramUniformHandleui64NV");
	if(!_ptrc_glProgramUniformHandleui64NV) numFailed++;
	_ptrc_glProgramUniformHandleui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glProgramUniformHandleui64vNV");
	if(!_ptrc_glProgramUniformHandleui64vNV) numFailed++;
	_ptrc_glUniformHandleui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64))IntGetProcAddress("glUniformHandleui64NV");
	if(!_ptrc_glUniformHandleui64NV) numFailed++;
	_ptrc_glUniformHandleui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64 *))IntGetProcAddress("glUniformHandleui64vNV");
	if(!_ptrc_glUniformHandleui64vNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBlendBarrierNV)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendParameteriNV)(GLenum, GLint) = NULL;

static int Load_NV_blend_equation_advanced()
{
	int numFailed = 0;
	_ptrc_glBlendBarrierNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glBlendBarrierNV");
	if(!_ptrc_glBlendBarrierNV) numFailed++;
	_ptrc_glBlendParameteriNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glBlendParameteriNV");
	if(!_ptrc_glBlendParameteriNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRenderNV)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRenderNV)() = NULL;

static int Load_NV_conditional_render()
{
	int numFailed = 0;
	_ptrc_glBeginConditionalRenderNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBeginConditionalRenderNV");
	if(!_ptrc_glBeginConditionalRenderNV) numFailed++;
	_ptrc_glEndConditionalRenderNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndConditionalRenderNV");
	if(!_ptrc_glEndConditionalRenderNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyImageSubDataNV)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei) = NULL;

static int Load_NV_copy_image()
{
	int numFailed = 0;
	_ptrc_glCopyImageSubDataNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glCopyImageSubDataNV");
	if(!_ptrc_glCopyImageSubDataNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearDepthdNV)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthBoundsdNV)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangedNV)(GLdouble, GLdouble) = NULL;

static int Load_NV_depth_buffer_float()
{
	int numFailed = 0;
	_ptrc_glClearDepthdNV = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glClearDepthdNV");
	if(!_ptrc_glClearDepthdNV) numFailed++;
	_ptrc_glDepthBoundsdNV = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glDepthBoundsdNV");
	if(!_ptrc_glDepthBoundsdNV) numFailed++;
	_ptrc_glDepthRangedNV = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glDepthRangedNV");
	if(!_ptrc_glDepthRangedNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawTextureNV)(GLuint, GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;

static int Load_NV_draw_texture()
{
	int numFailed = 0;
	_ptrc_glDrawTextureNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glDrawTextureNV");
	if(!_ptrc_glDrawTextureNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glEvalMapsNV)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapAttribParameterfvNV)(GLenum, GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapAttribParameterivNV)(GLenum, GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapControlPointsNV)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapParameterfvNV)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapParameterivNV)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapControlPointsNV)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapParameterfvNV)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapParameterivNV)(GLenum, GLenum, const GLint *) = NULL;

static int Load_NV_evaluators()
{
	int numFailed = 0;
	_ptrc_glEvalMapsNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glEvalMapsNV");
	if(!_ptrc_glEvalMapsNV) numFailed++;
	_ptrc_glGetMapAttribParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetMapAttribParameterfvNV");
	if(!_ptrc_glGetMapAttribParameterfvNV) numFailed++;
	_ptrc_glGetMapAttribParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetMapAttribParameterivNV");
	if(!_ptrc_glGetMapAttribParameterivNV) numFailed++;
	_ptrc_glGetMapControlPointsNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid *))IntGetProcAddress("glGetMapControlPointsNV");
	if(!_ptrc_glGetMapControlPointsNV) numFailed++;
	_ptrc_glGetMapParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMapParameterfvNV");
	if(!_ptrc_glGetMapParameterfvNV) numFailed++;
	_ptrc_glGetMapParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetMapParameterivNV");
	if(!_ptrc_glGetMapParameterivNV) numFailed++;
	_ptrc_glMapControlPointsNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid *))IntGetProcAddress("glMapControlPointsNV");
	if(!_ptrc_glMapControlPointsNV) numFailed++;
	_ptrc_glMapParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMapParameterfvNV");
	if(!_ptrc_glMapParameterfvNV) numFailed++;
	_ptrc_glMapParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glMapParameterivNV");
	if(!_ptrc_glMapParameterivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetMultisamplefvNV)(GLenum, GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskIndexedNV)(GLuint, GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexRenderbufferNV)(GLenum, GLuint) = NULL;

static int Load_NV_explicit_multisample()
{
	int numFailed = 0;
	_ptrc_glGetMultisamplefvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetMultisamplefvNV");
	if(!_ptrc_glGetMultisamplefvNV) numFailed++;
	_ptrc_glSampleMaskIndexedNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield))IntGetProcAddress("glSampleMaskIndexedNV");
	if(!_ptrc_glSampleMaskIndexedNV) numFailed++;
	_ptrc_glTexRenderbufferNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glTexRenderbufferNV");
	if(!_ptrc_glTexRenderbufferNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDeleteFencesNV)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinishFenceNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenFencesNV)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFenceivNV)(GLuint, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsFenceNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSetFenceNV)(GLuint, GLenum) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glTestFenceNV)(GLuint) = NULL;

static int Load_NV_fence()
{
	int numFailed = 0;
	_ptrc_glDeleteFencesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFencesNV");
	if(!_ptrc_glDeleteFencesNV) numFailed++;
	_ptrc_glFinishFenceNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glFinishFenceNV");
	if(!_ptrc_glFinishFenceNV) numFailed++;
	_ptrc_glGenFencesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFencesNV");
	if(!_ptrc_glGenFencesNV) numFailed++;
	_ptrc_glGetFenceivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetFenceivNV");
	if(!_ptrc_glGetFenceivNV) numFailed++;
	_ptrc_glIsFenceNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFenceNV");
	if(!_ptrc_glIsFenceNV) numFailed++;
	_ptrc_glSetFenceNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glSetFenceNV");
	if(!_ptrc_glSetFenceNV) numFailed++;
	_ptrc_glTestFenceNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glTestFenceNV");
	if(!_ptrc_glTestFenceNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterdvNV)(GLuint, GLsizei, const GLubyte *, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramNamedParameterfvNV)(GLuint, GLsizei, const GLubyte *, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dNV)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4dvNV)(GLuint, GLsizei, const GLubyte *, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fNV)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramNamedParameter4fvNV)(GLuint, GLsizei, const GLubyte *, const GLfloat *) = NULL;

static int Load_NV_fragment_program()
{
	int numFailed = 0;
	_ptrc_glGetProgramNamedParameterdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLdouble *))IntGetProcAddress("glGetProgramNamedParameterdvNV");
	if(!_ptrc_glGetProgramNamedParameterdvNV) numFailed++;
	_ptrc_glGetProgramNamedParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLfloat *))IntGetProcAddress("glGetProgramNamedParameterfvNV");
	if(!_ptrc_glGetProgramNamedParameterfvNV) numFailed++;
	_ptrc_glProgramNamedParameter4dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramNamedParameter4dNV");
	if(!_ptrc_glProgramNamedParameter4dNV) numFailed++;
	_ptrc_glProgramNamedParameter4dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, const GLdouble *))IntGetProcAddress("glProgramNamedParameter4dvNV");
	if(!_ptrc_glProgramNamedParameter4dvNV) numFailed++;
	_ptrc_glProgramNamedParameter4fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramNamedParameter4fNV");
	if(!_ptrc_glProgramNamedParameter4fNV) numFailed++;
	_ptrc_glProgramNamedParameter4fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, const GLfloat *))IntGetProcAddress("glProgramNamedParameter4fvNV");
	if(!_ptrc_glProgramNamedParameter4fvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glRenderbufferStorageMultisampleCoverageNV)(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei) = NULL;

static int Load_NV_framebuffer_multisample_coverage()
{
	int numFailed = 0;
	_ptrc_glRenderbufferStorageMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisampleCoverageNV");
	if(!_ptrc_glRenderbufferStorageMultisampleCoverageNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureEXT)(GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureFaceEXT)(GLenum, GLenum, GLuint, GLint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTextureLayerEXT)(GLenum, GLenum, GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramVertexLimitNV)(GLenum, GLint) = NULL;

static int Load_NV_geometry_program4()
{
	int numFailed = 0;
	_ptrc_glFramebufferTextureEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTextureEXT");
	if(!_ptrc_glFramebufferTextureEXT) numFailed++;
	_ptrc_glFramebufferTextureFaceEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLenum))IntGetProcAddress("glFramebufferTextureFaceEXT");
	if(!_ptrc_glFramebufferTextureFaceEXT) numFailed++;
	_ptrc_glFramebufferTextureLayerEXT = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayerEXT");
	if(!_ptrc_glFramebufferTextureLayerEXT) numFailed++;
	_ptrc_glProgramVertexLimitNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glProgramVertexLimitNV");
	if(!_ptrc_glProgramVertexLimitNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIivNV)(GLenum, GLuint, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramEnvParameterIuivNV)(GLenum, GLuint, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIivNV)(GLenum, GLuint, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramLocalParameterIuivNV)(GLenum, GLuint, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4iNV)(GLenum, GLuint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4ivNV)(GLenum, GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uiNV)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParameterI4uivNV)(GLenum, GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4ivNV)(GLenum, GLuint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramEnvParametersI4uivNV)(GLenum, GLuint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4iNV)(GLenum, GLuint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4ivNV)(GLenum, GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uiNV)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParameterI4uivNV)(GLenum, GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4ivNV)(GLenum, GLuint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramLocalParametersI4uivNV)(GLenum, GLuint, GLsizei, const GLuint *) = NULL;

static int Load_NV_gpu_program4()
{
	int numFailed = 0;
	_ptrc_glGetProgramEnvParameterIivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetProgramEnvParameterIivNV");
	if(!_ptrc_glGetProgramEnvParameterIivNV) numFailed++;
	_ptrc_glGetProgramEnvParameterIuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint *))IntGetProcAddress("glGetProgramEnvParameterIuivNV");
	if(!_ptrc_glGetProgramEnvParameterIuivNV) numFailed++;
	_ptrc_glGetProgramLocalParameterIivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetProgramLocalParameterIivNV");
	if(!_ptrc_glGetProgramLocalParameterIivNV) numFailed++;
	_ptrc_glGetProgramLocalParameterIuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint *))IntGetProcAddress("glGetProgramLocalParameterIuivNV");
	if(!_ptrc_glGetProgramLocalParameterIuivNV) numFailed++;
	_ptrc_glProgramEnvParameterI4iNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramEnvParameterI4iNV");
	if(!_ptrc_glProgramEnvParameterI4iNV) numFailed++;
	_ptrc_glProgramEnvParameterI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLint *))IntGetProcAddress("glProgramEnvParameterI4ivNV");
	if(!_ptrc_glProgramEnvParameterI4ivNV) numFailed++;
	_ptrc_glProgramEnvParameterI4uiNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramEnvParameterI4uiNV");
	if(!_ptrc_glProgramEnvParameterI4uiNV) numFailed++;
	_ptrc_glProgramEnvParameterI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLuint *))IntGetProcAddress("glProgramEnvParameterI4uivNV");
	if(!_ptrc_glProgramEnvParameterI4uivNV) numFailed++;
	_ptrc_glProgramEnvParametersI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLint *))IntGetProcAddress("glProgramEnvParametersI4ivNV");
	if(!_ptrc_glProgramEnvParametersI4ivNV) numFailed++;
	_ptrc_glProgramEnvParametersI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glProgramEnvParametersI4uivNV");
	if(!_ptrc_glProgramEnvParametersI4uivNV) numFailed++;
	_ptrc_glProgramLocalParameterI4iNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramLocalParameterI4iNV");
	if(!_ptrc_glProgramLocalParameterI4iNV) numFailed++;
	_ptrc_glProgramLocalParameterI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLint *))IntGetProcAddress("glProgramLocalParameterI4ivNV");
	if(!_ptrc_glProgramLocalParameterI4ivNV) numFailed++;
	_ptrc_glProgramLocalParameterI4uiNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramLocalParameterI4uiNV");
	if(!_ptrc_glProgramLocalParameterI4uiNV) numFailed++;
	_ptrc_glProgramLocalParameterI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLuint *))IntGetProcAddress("glProgramLocalParameterI4uivNV");
	if(!_ptrc_glProgramLocalParameterI4uivNV) numFailed++;
	_ptrc_glProgramLocalParametersI4ivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLint *))IntGetProcAddress("glProgramLocalParametersI4ivNV");
	if(!_ptrc_glProgramLocalParametersI4ivNV) numFailed++;
	_ptrc_glProgramLocalParametersI4uivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glProgramLocalParametersI4uivNV");
	if(!_ptrc_glProgramLocalParametersI4uivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetProgramSubroutineParameteruivNV)(GLenum, GLuint, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramSubroutineParametersuivNV)(GLenum, GLsizei, const GLuint *) = NULL;

static int Load_NV_gpu_program5()
{
	int numFailed = 0;
	_ptrc_glGetProgramSubroutineParameteruivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint *))IntGetProcAddress("glGetProgramSubroutineParameteruivNV");
	if(!_ptrc_glGetProgramSubroutineParameteruivNV) numFailed++;
	_ptrc_glProgramSubroutineParametersuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLuint *))IntGetProcAddress("glProgramSubroutineParametersuivNV");
	if(!_ptrc_glProgramSubroutineParametersuivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetUniformi64vNV)(GLuint, GLint, GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64NV)(GLuint, GLint, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64NV)(GLuint, GLint, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform1ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64NV)(GLuint, GLint, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64NV)(GLuint, GLint, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform2ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64NV)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64NV)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform3ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64NV)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4i64vNV)(GLuint, GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64NV)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniform4ui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64NV)(GLint, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i64vNV)(GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64NV)(GLint, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui64vNV)(GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64NV)(GLint, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i64vNV)(GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64NV)(GLint, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui64vNV)(GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64NV)(GLint, GLint64EXT, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i64vNV)(GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64NV)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui64vNV)(GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64NV)(GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i64vNV)(GLint, GLsizei, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64NV)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui64vNV)(GLint, GLsizei, const GLuint64EXT *) = NULL;

static int Load_NV_gpu_shader5()
{
	int numFailed = 0;
	_ptrc_glGetUniformi64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT *))IntGetProcAddress("glGetUniformi64vNV");
	if(!_ptrc_glGetUniformi64vNV) numFailed++;
	_ptrc_glProgramUniform1i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT))IntGetProcAddress("glProgramUniform1i64NV");
	if(!_ptrc_glProgramUniform1i64NV) numFailed++;
	_ptrc_glProgramUniform1i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform1i64vNV");
	if(!_ptrc_glProgramUniform1i64vNV) numFailed++;
	_ptrc_glProgramUniform1ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT))IntGetProcAddress("glProgramUniform1ui64NV");
	if(!_ptrc_glProgramUniform1ui64NV) numFailed++;
	_ptrc_glProgramUniform1ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform1ui64vNV");
	if(!_ptrc_glProgramUniform1ui64vNV) numFailed++;
	_ptrc_glProgramUniform2i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT, GLint64EXT))IntGetProcAddress("glProgramUniform2i64NV");
	if(!_ptrc_glProgramUniform2i64NV) numFailed++;
	_ptrc_glProgramUniform2i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform2i64vNV");
	if(!_ptrc_glProgramUniform2i64vNV) numFailed++;
	_ptrc_glProgramUniform2ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glProgramUniform2ui64NV");
	if(!_ptrc_glProgramUniform2ui64NV) numFailed++;
	_ptrc_glProgramUniform2ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform2ui64vNV");
	if(!_ptrc_glProgramUniform2ui64vNV) numFailed++;
	_ptrc_glProgramUniform3i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glProgramUniform3i64NV");
	if(!_ptrc_glProgramUniform3i64NV) numFailed++;
	_ptrc_glProgramUniform3i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform3i64vNV");
	if(!_ptrc_glProgramUniform3i64vNV) numFailed++;
	_ptrc_glProgramUniform3ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glProgramUniform3ui64NV");
	if(!_ptrc_glProgramUniform3ui64NV) numFailed++;
	_ptrc_glProgramUniform3ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform3ui64vNV");
	if(!_ptrc_glProgramUniform3ui64vNV) numFailed++;
	_ptrc_glProgramUniform4i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glProgramUniform4i64NV");
	if(!_ptrc_glProgramUniform4i64NV) numFailed++;
	_ptrc_glProgramUniform4i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glProgramUniform4i64vNV");
	if(!_ptrc_glProgramUniform4i64vNV) numFailed++;
	_ptrc_glProgramUniform4ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glProgramUniform4ui64NV");
	if(!_ptrc_glProgramUniform4ui64NV) numFailed++;
	_ptrc_glProgramUniform4ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniform4ui64vNV");
	if(!_ptrc_glProgramUniform4ui64vNV) numFailed++;
	_ptrc_glUniform1i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT))IntGetProcAddress("glUniform1i64NV");
	if(!_ptrc_glUniform1i64NV) numFailed++;
	_ptrc_glUniform1i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform1i64vNV");
	if(!_ptrc_glUniform1i64vNV) numFailed++;
	_ptrc_glUniform1ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT))IntGetProcAddress("glUniform1ui64NV");
	if(!_ptrc_glUniform1ui64NV) numFailed++;
	_ptrc_glUniform1ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform1ui64vNV");
	if(!_ptrc_glUniform1ui64vNV) numFailed++;
	_ptrc_glUniform2i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT, GLint64EXT))IntGetProcAddress("glUniform2i64NV");
	if(!_ptrc_glUniform2i64NV) numFailed++;
	_ptrc_glUniform2i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform2i64vNV");
	if(!_ptrc_glUniform2i64vNV) numFailed++;
	_ptrc_glUniform2ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glUniform2ui64NV");
	if(!_ptrc_glUniform2ui64NV) numFailed++;
	_ptrc_glUniform2ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform2ui64vNV");
	if(!_ptrc_glUniform2ui64vNV) numFailed++;
	_ptrc_glUniform3i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glUniform3i64NV");
	if(!_ptrc_glUniform3i64NV) numFailed++;
	_ptrc_glUniform3i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform3i64vNV");
	if(!_ptrc_glUniform3i64vNV) numFailed++;
	_ptrc_glUniform3ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glUniform3ui64NV");
	if(!_ptrc_glUniform3ui64NV) numFailed++;
	_ptrc_glUniform3ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform3ui64vNV");
	if(!_ptrc_glUniform3ui64vNV) numFailed++;
	_ptrc_glUniform4i64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glUniform4i64NV");
	if(!_ptrc_glUniform4i64NV) numFailed++;
	_ptrc_glUniform4i64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint64EXT *))IntGetProcAddress("glUniform4i64vNV");
	if(!_ptrc_glUniform4i64vNV) numFailed++;
	_ptrc_glUniform4ui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glUniform4ui64NV");
	if(!_ptrc_glUniform4ui64NV) numFailed++;
	_ptrc_glUniform4ui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniform4ui64vNV");
	if(!_ptrc_glUniform4ui64vNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColor3hNV)(GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4hNV)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhNV)(GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordhvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hNV)(GLenum, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1hvNV)(GLenum, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hNV)(GLenum, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2hvNV)(GLenum, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hNV)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3hvNV)(GLenum, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hNV)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4hvNV)(GLenum, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3hNV)(GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hNV)(GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hNV)(GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hNV)(GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hNV)(GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hNV)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2hNV)(GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3hNV)(GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4hNV)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4hvNV)(const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hNV)(GLuint, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1hvNV)(GLuint, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hNV)(GLuint, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2hvNV)(GLuint, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hNV)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3hvNV)(GLuint, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hNV)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4hvNV)(GLuint, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1hvNV)(GLuint, GLsizei, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2hvNV)(GLuint, GLsizei, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3hvNV)(GLuint, GLsizei, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4hvNV)(GLuint, GLsizei, const GLhalfNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthNV)(GLhalfNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexWeighthvNV)(const GLhalfNV *) = NULL;

static int Load_NV_half_float()
{
	int numFailed = 0;
	_ptrc_glColor3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glColor3hNV");
	if(!_ptrc_glColor3hNV) numFailed++;
	_ptrc_glColor3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glColor3hvNV");
	if(!_ptrc_glColor3hvNV) numFailed++;
	_ptrc_glColor4hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glColor4hNV");
	if(!_ptrc_glColor4hNV) numFailed++;
	_ptrc_glColor4hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glColor4hvNV");
	if(!_ptrc_glColor4hvNV) numFailed++;
	_ptrc_glFogCoordhNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV))IntGetProcAddress("glFogCoordhNV");
	if(!_ptrc_glFogCoordhNV) numFailed++;
	_ptrc_glFogCoordhvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glFogCoordhvNV");
	if(!_ptrc_glFogCoordhvNV) numFailed++;
	_ptrc_glMultiTexCoord1hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV))IntGetProcAddress("glMultiTexCoord1hNV");
	if(!_ptrc_glMultiTexCoord1hNV) numFailed++;
	_ptrc_glMultiTexCoord1hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord1hvNV");
	if(!_ptrc_glMultiTexCoord1hvNV) numFailed++;
	_ptrc_glMultiTexCoord2hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV, GLhalfNV))IntGetProcAddress("glMultiTexCoord2hNV");
	if(!_ptrc_glMultiTexCoord2hNV) numFailed++;
	_ptrc_glMultiTexCoord2hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord2hvNV");
	if(!_ptrc_glMultiTexCoord2hvNV) numFailed++;
	_ptrc_glMultiTexCoord3hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glMultiTexCoord3hNV");
	if(!_ptrc_glMultiTexCoord3hNV) numFailed++;
	_ptrc_glMultiTexCoord3hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord3hvNV");
	if(!_ptrc_glMultiTexCoord3hvNV) numFailed++;
	_ptrc_glMultiTexCoord4hNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glMultiTexCoord4hNV");
	if(!_ptrc_glMultiTexCoord4hNV) numFailed++;
	_ptrc_glMultiTexCoord4hvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLhalfNV *))IntGetProcAddress("glMultiTexCoord4hvNV");
	if(!_ptrc_glMultiTexCoord4hvNV) numFailed++;
	_ptrc_glNormal3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glNormal3hNV");
	if(!_ptrc_glNormal3hNV) numFailed++;
	_ptrc_glNormal3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glNormal3hvNV");
	if(!_ptrc_glNormal3hvNV) numFailed++;
	_ptrc_glSecondaryColor3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glSecondaryColor3hNV");
	if(!_ptrc_glSecondaryColor3hNV) numFailed++;
	_ptrc_glSecondaryColor3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glSecondaryColor3hvNV");
	if(!_ptrc_glSecondaryColor3hvNV) numFailed++;
	_ptrc_glTexCoord1hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV))IntGetProcAddress("glTexCoord1hNV");
	if(!_ptrc_glTexCoord1hNV) numFailed++;
	_ptrc_glTexCoord1hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord1hvNV");
	if(!_ptrc_glTexCoord1hvNV) numFailed++;
	_ptrc_glTexCoord2hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV))IntGetProcAddress("glTexCoord2hNV");
	if(!_ptrc_glTexCoord2hNV) numFailed++;
	_ptrc_glTexCoord2hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord2hvNV");
	if(!_ptrc_glTexCoord2hvNV) numFailed++;
	_ptrc_glTexCoord3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glTexCoord3hNV");
	if(!_ptrc_glTexCoord3hNV) numFailed++;
	_ptrc_glTexCoord3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord3hvNV");
	if(!_ptrc_glTexCoord3hvNV) numFailed++;
	_ptrc_glTexCoord4hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glTexCoord4hNV");
	if(!_ptrc_glTexCoord4hNV) numFailed++;
	_ptrc_glTexCoord4hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glTexCoord4hvNV");
	if(!_ptrc_glTexCoord4hvNV) numFailed++;
	_ptrc_glVertex2hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV))IntGetProcAddress("glVertex2hNV");
	if(!_ptrc_glVertex2hNV) numFailed++;
	_ptrc_glVertex2hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertex2hvNV");
	if(!_ptrc_glVertex2hvNV) numFailed++;
	_ptrc_glVertex3hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertex3hNV");
	if(!_ptrc_glVertex3hNV) numFailed++;
	_ptrc_glVertex3hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertex3hvNV");
	if(!_ptrc_glVertex3hvNV) numFailed++;
	_ptrc_glVertex4hNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertex4hNV");
	if(!_ptrc_glVertex4hNV) numFailed++;
	_ptrc_glVertex4hvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertex4hvNV");
	if(!_ptrc_glVertex4hvNV) numFailed++;
	_ptrc_glVertexAttrib1hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV))IntGetProcAddress("glVertexAttrib1hNV");
	if(!_ptrc_glVertexAttrib1hNV) numFailed++;
	_ptrc_glVertexAttrib1hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib1hvNV");
	if(!_ptrc_glVertexAttrib1hvNV) numFailed++;
	_ptrc_glVertexAttrib2hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertexAttrib2hNV");
	if(!_ptrc_glVertexAttrib2hNV) numFailed++;
	_ptrc_glVertexAttrib2hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib2hvNV");
	if(!_ptrc_glVertexAttrib2hvNV) numFailed++;
	_ptrc_glVertexAttrib3hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertexAttrib3hNV");
	if(!_ptrc_glVertexAttrib3hNV) numFailed++;
	_ptrc_glVertexAttrib3hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib3hvNV");
	if(!_ptrc_glVertexAttrib3hvNV) numFailed++;
	_ptrc_glVertexAttrib4hNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLhalfNV, GLhalfNV, GLhalfNV, GLhalfNV))IntGetProcAddress("glVertexAttrib4hNV");
	if(!_ptrc_glVertexAttrib4hNV) numFailed++;
	_ptrc_glVertexAttrib4hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLhalfNV *))IntGetProcAddress("glVertexAttrib4hvNV");
	if(!_ptrc_glVertexAttrib4hvNV) numFailed++;
	_ptrc_glVertexAttribs1hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs1hvNV");
	if(!_ptrc_glVertexAttribs1hvNV) numFailed++;
	_ptrc_glVertexAttribs2hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs2hvNV");
	if(!_ptrc_glVertexAttribs2hvNV) numFailed++;
	_ptrc_glVertexAttribs3hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs3hvNV");
	if(!_ptrc_glVertexAttribs3hvNV) numFailed++;
	_ptrc_glVertexAttribs4hvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLhalfNV *))IntGetProcAddress("glVertexAttribs4hvNV");
	if(!_ptrc_glVertexAttribs4hvNV) numFailed++;
	_ptrc_glVertexWeighthNV = (void (CODEGEN_FUNCPTR *)(GLhalfNV))IntGetProcAddress("glVertexWeighthNV");
	if(!_ptrc_glVertexWeighthNV) numFailed++;
	_ptrc_glVertexWeighthvNV = (void (CODEGEN_FUNCPTR *)(const GLhalfNV *))IntGetProcAddress("glVertexWeighthvNV");
	if(!_ptrc_glVertexWeighthvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginOcclusionQueryNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteOcclusionQueriesNV)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndOcclusionQueryNV)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenOcclusionQueriesNV)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryivNV)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetOcclusionQueryuivNV)(GLuint, GLenum, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsOcclusionQueryNV)(GLuint) = NULL;

static int Load_NV_occlusion_query()
{
	int numFailed = 0;
	_ptrc_glBeginOcclusionQueryNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBeginOcclusionQueryNV");
	if(!_ptrc_glBeginOcclusionQueryNV) numFailed++;
	_ptrc_glDeleteOcclusionQueriesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteOcclusionQueriesNV");
	if(!_ptrc_glDeleteOcclusionQueriesNV) numFailed++;
	_ptrc_glEndOcclusionQueryNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndOcclusionQueryNV");
	if(!_ptrc_glEndOcclusionQueryNV) numFailed++;
	_ptrc_glGenOcclusionQueriesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenOcclusionQueriesNV");
	if(!_ptrc_glGenOcclusionQueriesNV) numFailed++;
	_ptrc_glGetOcclusionQueryivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetOcclusionQueryivNV");
	if(!_ptrc_glGetOcclusionQueryivNV) numFailed++;
	_ptrc_glGetOcclusionQueryuivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetOcclusionQueryuivNV");
	if(!_ptrc_glGetOcclusionQueryuivNV) numFailed++;
	_ptrc_glIsOcclusionQueryNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsOcclusionQueryNV");
	if(!_ptrc_glIsOcclusionQueryNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIivNV)(GLenum, GLuint, GLuint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersIuivNV)(GLenum, GLuint, GLuint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramBufferParametersfvNV)(GLenum, GLuint, GLuint, GLsizei, const GLfloat *) = NULL;

static int Load_NV_parameter_buffer_object()
{
	int numFailed = 0;
	_ptrc_glProgramBufferParametersIivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, const GLint *))IntGetProcAddress("glProgramBufferParametersIivNV");
	if(!_ptrc_glProgramBufferParametersIivNV) numFailed++;
	_ptrc_glProgramBufferParametersIuivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glProgramBufferParametersIuivNV");
	if(!_ptrc_glProgramBufferParametersIuivNV) numFailed++;
	_ptrc_glProgramBufferParametersfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramBufferParametersfvNV");
	if(!_ptrc_glProgramBufferParametersfvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCopyPathNV)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverFillPathNV)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCoverStrokePathNV)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeletePathsNV)(GLuint, GLsizei) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGenPathsNV)(GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenfvNV)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathColorGenivNV)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathCommandsNV)(GLuint, GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathCoordsNV)(GLuint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathDashArrayNV)(GLuint, GLfloat *) = NULL;
GLfloat (CODEGEN_FUNCPTR *_ptrc_glGetPathLengthNV)(GLuint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricRangeNV)(GLbitfield, GLuint, GLsizei, GLsizei, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathMetricsNV)(GLbitfield, GLsizei, GLenum, const GLvoid *, GLuint, GLsizei, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterfvNV)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathParameterivNV)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathSpacingNV)(GLenum, GLsizei, GLenum, const GLvoid *, GLuint, GLfloat, GLfloat, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenfvNV)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPathTexGenivNV)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInterpolatePathsNV)(GLuint, GLuint, GLuint, GLfloat) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPathNV)(GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInFillPathNV)(GLuint, GLuint, GLfloat, GLfloat) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsPointInStrokePathNV)(GLuint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathColorGenNV)(GLenum, GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathCommandsNV)(GLuint, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathCoordsNV)(GLuint, GLsizei, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathCoverDepthFuncNV)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathDashArrayNV)(GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathFogGenNV)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphRangeNV)(GLuint, GLenum, const GLvoid *, GLbitfield, GLuint, GLsizei, GLenum, GLuint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathGlyphsNV)(GLuint, GLenum, const GLvoid *, GLbitfield, GLsizei, GLenum, const GLvoid *, GLenum, GLuint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfNV)(GLuint, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameterfvNV)(GLuint, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameteriNV)(GLuint, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathParameterivNV)(GLuint, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathStencilDepthOffsetNV)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathStencilFuncNV)(GLenum, GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathStringNV)(GLuint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathSubCommandsNV)(GLuint, GLsizei, GLsizei, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathSubCoordsNV)(GLuint, GLsizei, GLsizei, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPathTexGenNV)(GLenum, GLenum, GLint, const GLfloat *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glPointAlongPathNV)(GLuint, GLsizei, GLsizei, GLfloat, GLfloat *, GLfloat *, GLfloat *, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLuint, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFillPathNV)(GLuint, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathInstancedNV)(GLsizei, GLenum, const GLvoid *, GLuint, GLint, GLuint, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilStrokePathNV)(GLuint, GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformPathNV)(GLuint, GLuint, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWeightPathsNV)(GLuint, GLsizei, const GLuint *, const GLfloat *) = NULL;

static int Load_NV_path_rendering()
{
	int numFailed = 0;
	_ptrc_glCopyPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glCopyPathNV");
	if(!_ptrc_glCopyPathNV) numFailed++;
	_ptrc_glCoverFillPathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glCoverFillPathInstancedNV");
	if(!_ptrc_glCoverFillPathInstancedNV) numFailed++;
	_ptrc_glCoverFillPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCoverFillPathNV");
	if(!_ptrc_glCoverFillPathNV) numFailed++;
	_ptrc_glCoverStrokePathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glCoverStrokePathInstancedNV");
	if(!_ptrc_glCoverStrokePathInstancedNV) numFailed++;
	_ptrc_glCoverStrokePathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glCoverStrokePathNV");
	if(!_ptrc_glCoverStrokePathNV) numFailed++;
	_ptrc_glDeletePathsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei))IntGetProcAddress("glDeletePathsNV");
	if(!_ptrc_glDeletePathsNV) numFailed++;
	_ptrc_glGenPathsNV = (GLuint (CODEGEN_FUNCPTR *)(GLsizei))IntGetProcAddress("glGenPathsNV");
	if(!_ptrc_glGenPathsNV) numFailed++;
	_ptrc_glGetPathColorGenfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetPathColorGenfvNV");
	if(!_ptrc_glGetPathColorGenfvNV) numFailed++;
	_ptrc_glGetPathColorGenivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetPathColorGenivNV");
	if(!_ptrc_glGetPathColorGenivNV) numFailed++;
	_ptrc_glGetPathCommandsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte *))IntGetProcAddress("glGetPathCommandsNV");
	if(!_ptrc_glGetPathCommandsNV) numFailed++;
	_ptrc_glGetPathCoordsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat *))IntGetProcAddress("glGetPathCoordsNV");
	if(!_ptrc_glGetPathCoordsNV) numFailed++;
	_ptrc_glGetPathDashArrayNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat *))IntGetProcAddress("glGetPathDashArrayNV");
	if(!_ptrc_glGetPathDashArrayNV) numFailed++;
	_ptrc_glGetPathLengthNV = (GLfloat (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei))IntGetProcAddress("glGetPathLengthNV");
	if(!_ptrc_glGetPathLengthNV) numFailed++;
	_ptrc_glGetPathMetricRangeNV = (void (CODEGEN_FUNCPTR *)(GLbitfield, GLuint, GLsizei, GLsizei, GLfloat *))IntGetProcAddress("glGetPathMetricRangeNV");
	if(!_ptrc_glGetPathMetricRangeNV) numFailed++;
	_ptrc_glGetPathMetricsNV = (void (CODEGEN_FUNCPTR *)(GLbitfield, GLsizei, GLenum, const GLvoid *, GLuint, GLsizei, GLfloat *))IntGetProcAddress("glGetPathMetricsNV");
	if(!_ptrc_glGetPathMetricsNV) numFailed++;
	_ptrc_glGetPathParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetPathParameterfvNV");
	if(!_ptrc_glGetPathParameterfvNV) numFailed++;
	_ptrc_glGetPathParameterivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetPathParameterivNV");
	if(!_ptrc_glGetPathParameterivNV) numFailed++;
	_ptrc_glGetPathSpacingNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLuint, GLfloat, GLfloat, GLenum, GLfloat *))IntGetProcAddress("glGetPathSpacingNV");
	if(!_ptrc_glGetPathSpacingNV) numFailed++;
	_ptrc_glGetPathTexGenfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetPathTexGenfvNV");
	if(!_ptrc_glGetPathTexGenfvNV) numFailed++;
	_ptrc_glGetPathTexGenivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetPathTexGenivNV");
	if(!_ptrc_glGetPathTexGenivNV) numFailed++;
	_ptrc_glInterpolatePathsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLfloat))IntGetProcAddress("glInterpolatePathsNV");
	if(!_ptrc_glInterpolatePathsNV) numFailed++;
	_ptrc_glIsPathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsPathNV");
	if(!_ptrc_glIsPathNV) numFailed++;
	_ptrc_glIsPointInFillPathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLfloat, GLfloat))IntGetProcAddress("glIsPointInFillPathNV");
	if(!_ptrc_glIsPointInFillPathNV) numFailed++;
	_ptrc_glIsPointInStrokePathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glIsPointInStrokePathNV");
	if(!_ptrc_glIsPointInStrokePathNV) numFailed++;
	_ptrc_glPathColorGenNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, const GLfloat *))IntGetProcAddress("glPathColorGenNV");
	if(!_ptrc_glPathColorGenNV) numFailed++;
	_ptrc_glPathCommandsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glPathCommandsNV");
	if(!_ptrc_glPathCommandsNV) numFailed++;
	_ptrc_glPathCoordsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glPathCoordsNV");
	if(!_ptrc_glPathCoordsNV) numFailed++;
	_ptrc_glPathCoverDepthFuncNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glPathCoverDepthFuncNV");
	if(!_ptrc_glPathCoverDepthFuncNV) numFailed++;
	_ptrc_glPathDashArrayNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glPathDashArrayNV");
	if(!_ptrc_glPathDashArrayNV) numFailed++;
	_ptrc_glPathFogGenNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glPathFogGenNV");
	if(!_ptrc_glPathFogGenNV) numFailed++;
	_ptrc_glPathGlyphRangeNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLvoid *, GLbitfield, GLuint, GLsizei, GLenum, GLuint, GLfloat))IntGetProcAddress("glPathGlyphRangeNV");
	if(!_ptrc_glPathGlyphRangeNV) numFailed++;
	_ptrc_glPathGlyphsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLvoid *, GLbitfield, GLsizei, GLenum, const GLvoid *, GLenum, GLuint, GLfloat))IntGetProcAddress("glPathGlyphsNV");
	if(!_ptrc_glPathGlyphsNV) numFailed++;
	_ptrc_glPathParameterfNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glPathParameterfNV");
	if(!_ptrc_glPathParameterfNV) numFailed++;
	_ptrc_glPathParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glPathParameterfvNV");
	if(!_ptrc_glPathParameterfvNV) numFailed++;
	_ptrc_glPathParameteriNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glPathParameteriNV");
	if(!_ptrc_glPathParameteriNV) numFailed++;
	_ptrc_glPathParameterivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glPathParameterivNV");
	if(!_ptrc_glPathParameterivNV) numFailed++;
	_ptrc_glPathStencilDepthOffsetNV = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glPathStencilDepthOffsetNV");
	if(!_ptrc_glPathStencilDepthOffsetNV) numFailed++;
	_ptrc_glPathStencilFuncNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint))IntGetProcAddress("glPathStencilFuncNV");
	if(!_ptrc_glPathStencilFuncNV) numFailed++;
	_ptrc_glPathStringNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glPathStringNV");
	if(!_ptrc_glPathStringNV) numFailed++;
	_ptrc_glPathSubCommandsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLsizei, const GLubyte *, GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glPathSubCommandsNV");
	if(!_ptrc_glPathSubCommandsNV) numFailed++;
	_ptrc_glPathSubCoordsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glPathSubCoordsNV");
	if(!_ptrc_glPathSubCoordsNV) numFailed++;
	_ptrc_glPathTexGenNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, const GLfloat *))IntGetProcAddress("glPathTexGenNV");
	if(!_ptrc_glPathTexGenNV) numFailed++;
	_ptrc_glPointAlongPathNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei, GLfloat, GLfloat *, GLfloat *, GLfloat *, GLfloat *))IntGetProcAddress("glPointAlongPathNV");
	if(!_ptrc_glPointAlongPathNV) numFailed++;
	_ptrc_glStencilFillPathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const GLvoid *, GLuint, GLenum, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glStencilFillPathInstancedNV");
	if(!_ptrc_glStencilFillPathInstancedNV) numFailed++;
	_ptrc_glStencilFillPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint))IntGetProcAddress("glStencilFillPathNV");
	if(!_ptrc_glStencilFillPathNV) numFailed++;
	_ptrc_glStencilStrokePathInstancedNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const GLvoid *, GLuint, GLint, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glStencilStrokePathInstancedNV");
	if(!_ptrc_glStencilStrokePathInstancedNV) numFailed++;
	_ptrc_glStencilStrokePathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glStencilStrokePathNV");
	if(!_ptrc_glStencilStrokePathNV) numFailed++;
	_ptrc_glTransformPathNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glTransformPathNV");
	if(!_ptrc_glTransformPathNV) numFailed++;
	_ptrc_glWeightPathsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, const GLfloat *))IntGetProcAddress("glWeightPathsNV");
	if(!_ptrc_glWeightPathsNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushPixelDataRangeNV)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelDataRangeNV)(GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_NV_pixel_data_range()
{
	int numFailed = 0;
	_ptrc_glFlushPixelDataRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glFlushPixelDataRangeNV");
	if(!_ptrc_glFlushPixelDataRangeNV) numFailed++;
	_ptrc_glPixelDataRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glPixelDataRangeNV");
	if(!_ptrc_glPixelDataRangeNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriNV)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterivNV)(GLenum, const GLint *) = NULL;

static int Load_NV_point_sprite()
{
	int numFailed = 0;
	_ptrc_glPointParameteriNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPointParameteriNV");
	if(!_ptrc_glPointParameteriNV) numFailed++;
	_ptrc_glPointParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glPointParameterivNV");
	if(!_ptrc_glPointParameterivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVideoi64vNV)(GLuint, GLenum, GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoivNV)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoui64vNV)(GLuint, GLenum, GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideouivNV)(GLuint, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPresentFrameDualFillNV)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPresentFrameKeyedNV)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLuint, GLenum, GLuint, GLuint) = NULL;

static int Load_NV_present_video()
{
	int numFailed = 0;
	_ptrc_glGetVideoi64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64EXT *))IntGetProcAddress("glGetVideoi64vNV");
	if(!_ptrc_glGetVideoi64vNV) numFailed++;
	_ptrc_glGetVideoivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVideoivNV");
	if(!_ptrc_glGetVideoivNV) numFailed++;
	_ptrc_glGetVideoui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64EXT *))IntGetProcAddress("glGetVideoui64vNV");
	if(!_ptrc_glGetVideoui64vNV) numFailed++;
	_ptrc_glGetVideouivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetVideouivNV");
	if(!_ptrc_glGetVideouivNV) numFailed++;
	_ptrc_glPresentFrameDualFillNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint, GLenum, GLuint))IntGetProcAddress("glPresentFrameDualFillNV");
	if(!_ptrc_glPresentFrameDualFillNV) numFailed++;
	_ptrc_glPresentFrameKeyedNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint, GLuint, GLenum, GLenum, GLuint, GLuint, GLenum, GLuint, GLuint))IntGetProcAddress("glPresentFrameKeyedNV");
	if(!_ptrc_glPresentFrameKeyedNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndexNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartNV)() = NULL;

static int Load_NV_primitive_restart()
{
	int numFailed = 0;
	_ptrc_glPrimitiveRestartIndexNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glPrimitiveRestartIndexNV");
	if(!_ptrc_glPrimitiveRestartIndexNV) numFailed++;
	_ptrc_glPrimitiveRestartNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPrimitiveRestartNV");
	if(!_ptrc_glPrimitiveRestartNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCombinerInputNV)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerOutputNV)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfNV)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterfvNV)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameteriNV)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCombinerParameterivNV)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinalCombinerInputNV)(GLenum, GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterfvNV)(GLenum, GLenum, GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerInputParameterivNV)(GLenum, GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterfvNV)(GLenum, GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerOutputParameterivNV)(GLenum, GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterfvNV)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFinalCombinerInputParameterivNV)(GLenum, GLenum, GLint *) = NULL;

static int Load_NV_register_combiners()
{
	int numFailed = 0;
	_ptrc_glCombinerInputNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glCombinerInputNV");
	if(!_ptrc_glCombinerInputNV) numFailed++;
	_ptrc_glCombinerOutputNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glCombinerOutputNV");
	if(!_ptrc_glCombinerOutputNV) numFailed++;
	_ptrc_glCombinerParameterfNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glCombinerParameterfNV");
	if(!_ptrc_glCombinerParameterfNV) numFailed++;
	_ptrc_glCombinerParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glCombinerParameterfvNV");
	if(!_ptrc_glCombinerParameterfvNV) numFailed++;
	_ptrc_glCombinerParameteriNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glCombinerParameteriNV");
	if(!_ptrc_glCombinerParameteriNV) numFailed++;
	_ptrc_glCombinerParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glCombinerParameterivNV");
	if(!_ptrc_glCombinerParameterivNV) numFailed++;
	_ptrc_glFinalCombinerInputNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glFinalCombinerInputNV");
	if(!_ptrc_glFinalCombinerInputNV) numFailed++;
	_ptrc_glGetCombinerInputParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetCombinerInputParameterfvNV");
	if(!_ptrc_glGetCombinerInputParameterfvNV) numFailed++;
	_ptrc_glGetCombinerInputParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetCombinerInputParameterivNV");
	if(!_ptrc_glGetCombinerInputParameterivNV) numFailed++;
	_ptrc_glGetCombinerOutputParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetCombinerOutputParameterfvNV");
	if(!_ptrc_glGetCombinerOutputParameterfvNV) numFailed++;
	_ptrc_glGetCombinerOutputParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetCombinerOutputParameterivNV");
	if(!_ptrc_glGetCombinerOutputParameterivNV) numFailed++;
	_ptrc_glGetFinalCombinerInputParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetFinalCombinerInputParameterfvNV");
	if(!_ptrc_glGetFinalCombinerInputParameterfvNV) numFailed++;
	_ptrc_glGetFinalCombinerInputParameterivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFinalCombinerInputParameterivNV");
	if(!_ptrc_glGetFinalCombinerInputParameterivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glCombinerStageParameterfvNV)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCombinerStageParameterfvNV)(GLenum, GLenum, GLfloat *) = NULL;

static int Load_NV_register_combiners2()
{
	int numFailed = 0;
	_ptrc_glCombinerStageParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glCombinerStageParameterfvNV");
	if(!_ptrc_glCombinerStageParameterfvNV) numFailed++;
	_ptrc_glGetCombinerStageParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetCombinerStageParameterfvNV");
	if(!_ptrc_glGetCombinerStageParameterfvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameterui64vNV)(GLenum, GLenum, GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64vNV)(GLenum, GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetNamedBufferParameterui64vNV)(GLuint, GLenum, GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformui64vNV)(GLuint, GLint, GLuint64EXT *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBufferResidentNV)(GLenum) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsNamedBufferResidentNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferNonResidentNV)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeBufferResidentNV)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferNonResidentNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMakeNamedBufferResidentNV)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64NV)(GLuint, GLint, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramUniformui64vNV)(GLuint, GLint, GLsizei, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformui64NV)(GLint, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformui64vNV)(GLint, GLsizei, const GLuint64EXT *) = NULL;

static int Load_NV_shader_buffer_load()
{
	int numFailed = 0;
	_ptrc_glGetBufferParameterui64vNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint64EXT *))IntGetProcAddress("glGetBufferParameterui64vNV");
	if(!_ptrc_glGetBufferParameterui64vNV) numFailed++;
	_ptrc_glGetIntegerui64vNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint64EXT *))IntGetProcAddress("glGetIntegerui64vNV");
	if(!_ptrc_glGetIntegerui64vNV) numFailed++;
	_ptrc_glGetNamedBufferParameterui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64EXT *))IntGetProcAddress("glGetNamedBufferParameterui64vNV");
	if(!_ptrc_glGetNamedBufferParameterui64vNV) numFailed++;
	_ptrc_glGetUniformui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT *))IntGetProcAddress("glGetUniformui64vNV");
	if(!_ptrc_glGetUniformui64vNV) numFailed++;
	_ptrc_glIsBufferResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glIsBufferResidentNV");
	if(!_ptrc_glIsBufferResidentNV) numFailed++;
	_ptrc_glIsNamedBufferResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsNamedBufferResidentNV");
	if(!_ptrc_glIsNamedBufferResidentNV) numFailed++;
	_ptrc_glMakeBufferNonResidentNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMakeBufferNonResidentNV");
	if(!_ptrc_glMakeBufferNonResidentNV) numFailed++;
	_ptrc_glMakeBufferResidentNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glMakeBufferResidentNV");
	if(!_ptrc_glMakeBufferResidentNV) numFailed++;
	_ptrc_glMakeNamedBufferNonResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glMakeNamedBufferNonResidentNV");
	if(!_ptrc_glMakeNamedBufferNonResidentNV) numFailed++;
	_ptrc_glMakeNamedBufferResidentNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glMakeNamedBufferResidentNV");
	if(!_ptrc_glMakeNamedBufferResidentNV) numFailed++;
	_ptrc_glProgramUniformui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint64EXT))IntGetProcAddress("glProgramUniformui64NV");
	if(!_ptrc_glProgramUniformui64NV) numFailed++;
	_ptrc_glProgramUniformui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glProgramUniformui64vNV");
	if(!_ptrc_glProgramUniformui64vNV) numFailed++;
	_ptrc_glUniformui64NV = (void (CODEGEN_FUNCPTR *)(GLint, GLuint64EXT))IntGetProcAddress("glUniformui64NV");
	if(!_ptrc_glUniformui64NV) numFailed++;
	_ptrc_glUniformui64vNV = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint64EXT *))IntGetProcAddress("glUniformui64vNV");
	if(!_ptrc_glUniformui64vNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTextureBarrierNV)() = NULL;

static int Load_NV_texture_barrier()
{
	int numFailed = 0;
	_ptrc_glTextureBarrierNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glTextureBarrierNV");
	if(!_ptrc_glTextureBarrierNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexImage2DMultisampleCoverageNV)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage3DMultisampleCoverageNV)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleCoverageNV)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage2DMultisampleNV)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleCoverageNV)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTextureImage3DMultisampleNV)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean) = NULL;

static int Load_NV_texture_multisample()
{
	int numFailed = 0;
	_ptrc_glTexImage2DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage2DMultisampleCoverageNV");
	if(!_ptrc_glTexImage2DMultisampleCoverageNV) numFailed++;
	_ptrc_glTexImage3DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage3DMultisampleCoverageNV");
	if(!_ptrc_glTexImage3DMultisampleCoverageNV) numFailed++;
	_ptrc_glTextureImage2DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage2DMultisampleCoverageNV");
	if(!_ptrc_glTextureImage2DMultisampleCoverageNV) numFailed++;
	_ptrc_glTextureImage2DMultisampleNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage2DMultisampleNV");
	if(!_ptrc_glTextureImage2DMultisampleNV) numFailed++;
	_ptrc_glTextureImage3DMultisampleCoverageNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage3DMultisampleCoverageNV");
	if(!_ptrc_glTextureImage3DMultisampleCoverageNV) numFailed++;
	_ptrc_glTextureImage3DMultisampleNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTextureImage3DMultisampleNV");
	if(!_ptrc_glTextureImage3DMultisampleNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glActiveVaryingNV)(GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedbackNV)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBaseNV)(GLenum, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferOffsetNV)(GLenum, GLuint, GLuint, GLintptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRangeNV)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedbackNV)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveVaryingNV)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVaryingNV)(GLuint, GLuint, GLint *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetVaryingLocationNV)(GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackAttribsNV)(GLuint, const GLint *, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackStreamAttribsNV)(GLsizei, const GLint *, GLsizei, const GLint *, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryingsNV)(GLuint, GLsizei, const GLint *, GLenum) = NULL;

static int Load_NV_transform_feedback()
{
	int numFailed = 0;
	_ptrc_glActiveVaryingNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glActiveVaryingNV");
	if(!_ptrc_glActiveVaryingNV) numFailed++;
	_ptrc_glBeginTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBeginTransformFeedbackNV");
	if(!_ptrc_glBeginTransformFeedbackNV) numFailed++;
	_ptrc_glBindBufferBaseNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBindBufferBaseNV");
	if(!_ptrc_glBindBufferBaseNV) numFailed++;
	_ptrc_glBindBufferOffsetNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr))IntGetProcAddress("glBindBufferOffsetNV");
	if(!_ptrc_glBindBufferOffsetNV) numFailed++;
	_ptrc_glBindBufferRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glBindBufferRangeNV");
	if(!_ptrc_glBindBufferRangeNV) numFailed++;
	_ptrc_glEndTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndTransformFeedbackNV");
	if(!_ptrc_glEndTransformFeedbackNV) numFailed++;
	_ptrc_glGetActiveVaryingNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *))IntGetProcAddress("glGetActiveVaryingNV");
	if(!_ptrc_glGetActiveVaryingNV) numFailed++;
	_ptrc_glGetTransformFeedbackVaryingNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint *))IntGetProcAddress("glGetTransformFeedbackVaryingNV");
	if(!_ptrc_glGetTransformFeedbackVaryingNV) numFailed++;
	_ptrc_glGetVaryingLocationNV = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetVaryingLocationNV");
	if(!_ptrc_glGetVaryingLocationNV) numFailed++;
	_ptrc_glTransformFeedbackAttribsNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *, GLenum))IntGetProcAddress("glTransformFeedbackAttribsNV");
	if(!_ptrc_glTransformFeedbackAttribsNV) numFailed++;
	_ptrc_glTransformFeedbackStreamAttribsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLint *, GLsizei, const GLint *, GLenum))IntGetProcAddress("glTransformFeedbackStreamAttribsNV");
	if(!_ptrc_glTransformFeedbackStreamAttribsNV) numFailed++;
	_ptrc_glTransformFeedbackVaryingsNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLint *, GLenum))IntGetProcAddress("glTransformFeedbackVaryingsNV");
	if(!_ptrc_glTransformFeedbackVaryingsNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBindTransformFeedbackNV)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTransformFeedbacksNV)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawTransformFeedbackNV)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTransformFeedbacksNV)(GLsizei, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTransformFeedbackNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPauseTransformFeedbackNV)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glResumeTransformFeedbackNV)() = NULL;

static int Load_NV_transform_feedback2()
{
	int numFailed = 0;
	_ptrc_glBindTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTransformFeedbackNV");
	if(!_ptrc_glBindTransformFeedbackNV) numFailed++;
	_ptrc_glDeleteTransformFeedbacksNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTransformFeedbacksNV");
	if(!_ptrc_glDeleteTransformFeedbacksNV) numFailed++;
	_ptrc_glDrawTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDrawTransformFeedbackNV");
	if(!_ptrc_glDrawTransformFeedbackNV) numFailed++;
	_ptrc_glGenTransformFeedbacksNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTransformFeedbacksNV");
	if(!_ptrc_glGenTransformFeedbacksNV) numFailed++;
	_ptrc_glIsTransformFeedbackNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTransformFeedbackNV");
	if(!_ptrc_glIsTransformFeedbackNV) numFailed++;
	_ptrc_glPauseTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPauseTransformFeedbackNV");
	if(!_ptrc_glPauseTransformFeedbackNV) numFailed++;
	_ptrc_glResumeTransformFeedbackNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glResumeTransformFeedbackNV");
	if(!_ptrc_glResumeTransformFeedbackNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glVDPAUFiniNV)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVDPAUGetSurfaceivNV)(GLvdpauSurfaceNV, GLenum, GLsizei, GLsizei *, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVDPAUInitNV)(const GLvoid *, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVDPAUIsSurfaceNV)(GLvdpauSurfaceNV) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVDPAUMapSurfacesNV)(GLsizei, const GLvdpauSurfaceNV *) = NULL;
GLvdpauSurfaceNV (CODEGEN_FUNCPTR *_ptrc_glVDPAURegisterOutputSurfaceNV)(const GLvoid *, GLenum, GLsizei, const GLuint *) = NULL;
GLvdpauSurfaceNV (CODEGEN_FUNCPTR *_ptrc_glVDPAURegisterVideoSurfaceNV)(const GLvoid *, GLenum, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVDPAUSurfaceAccessNV)(GLvdpauSurfaceNV, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVDPAUUnmapSurfacesNV)(GLsizei, const GLvdpauSurfaceNV *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVDPAUUnregisterSurfaceNV)(GLvdpauSurfaceNV) = NULL;

static int Load_NV_vdpau_interop()
{
	int numFailed = 0;
	_ptrc_glVDPAUFiniNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glVDPAUFiniNV");
	if(!_ptrc_glVDPAUFiniNV) numFailed++;
	_ptrc_glVDPAUGetSurfaceivNV = (void (CODEGEN_FUNCPTR *)(GLvdpauSurfaceNV, GLenum, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glVDPAUGetSurfaceivNV");
	if(!_ptrc_glVDPAUGetSurfaceivNV) numFailed++;
	_ptrc_glVDPAUInitNV = (void (CODEGEN_FUNCPTR *)(const GLvoid *, const GLvoid *))IntGetProcAddress("glVDPAUInitNV");
	if(!_ptrc_glVDPAUInitNV) numFailed++;
	_ptrc_glVDPAUIsSurfaceNV = (void (CODEGEN_FUNCPTR *)(GLvdpauSurfaceNV))IntGetProcAddress("glVDPAUIsSurfaceNV");
	if(!_ptrc_glVDPAUIsSurfaceNV) numFailed++;
	_ptrc_glVDPAUMapSurfacesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLvdpauSurfaceNV *))IntGetProcAddress("glVDPAUMapSurfacesNV");
	if(!_ptrc_glVDPAUMapSurfacesNV) numFailed++;
	_ptrc_glVDPAURegisterOutputSurfaceNV = (GLvdpauSurfaceNV (CODEGEN_FUNCPTR *)(const GLvoid *, GLenum, GLsizei, const GLuint *))IntGetProcAddress("glVDPAURegisterOutputSurfaceNV");
	if(!_ptrc_glVDPAURegisterOutputSurfaceNV) numFailed++;
	_ptrc_glVDPAURegisterVideoSurfaceNV = (GLvdpauSurfaceNV (CODEGEN_FUNCPTR *)(const GLvoid *, GLenum, GLsizei, const GLuint *))IntGetProcAddress("glVDPAURegisterVideoSurfaceNV");
	if(!_ptrc_glVDPAURegisterVideoSurfaceNV) numFailed++;
	_ptrc_glVDPAUSurfaceAccessNV = (void (CODEGEN_FUNCPTR *)(GLvdpauSurfaceNV, GLenum))IntGetProcAddress("glVDPAUSurfaceAccessNV");
	if(!_ptrc_glVDPAUSurfaceAccessNV) numFailed++;
	_ptrc_glVDPAUUnmapSurfacesNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLvdpauSurfaceNV *))IntGetProcAddress("glVDPAUUnmapSurfacesNV");
	if(!_ptrc_glVDPAUUnmapSurfacesNV) numFailed++;
	_ptrc_glVDPAUUnregisterSurfaceNV = (void (CODEGEN_FUNCPTR *)(GLvdpauSurfaceNV))IntGetProcAddress("glVDPAUUnregisterSurfaceNV");
	if(!_ptrc_glVDPAUUnregisterSurfaceNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushVertexArrayRangeNV)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexArrayRangeNV)(GLsizei, const GLvoid *) = NULL;

static int Load_NV_vertex_array_range()
{
	int numFailed = 0;
	_ptrc_glFlushVertexArrayRangeNV = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glFlushVertexArrayRangeNV");
	if(!_ptrc_glFlushVertexArrayRangeNV) numFailed++;
	_ptrc_glVertexArrayRangeNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLvoid *))IntGetProcAddress("glVertexArrayRangeNV");
	if(!_ptrc_glVertexArrayRangeNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLi64vNV)(GLuint, GLenum, GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribLui64vNV)(GLuint, GLenum, GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64NV)(GLuint, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1i64vNV)(GLuint, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64NV)(GLuint, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL1ui64vNV)(GLuint, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64NV)(GLuint, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2i64vNV)(GLuint, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64NV)(GLuint, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL2ui64vNV)(GLuint, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64NV)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3i64vNV)(GLuint, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64NV)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL3ui64vNV)(GLuint, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64NV)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4i64vNV)(GLuint, const GLint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64NV)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribL4ui64vNV)(GLuint, const GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribLFormatNV)(GLuint, GLint, GLenum, GLsizei) = NULL;

static int Load_NV_vertex_attrib_integer_64bit()
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribLi64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64EXT *))IntGetProcAddress("glGetVertexAttribLi64vNV");
	if(!_ptrc_glGetVertexAttribLi64vNV) numFailed++;
	_ptrc_glGetVertexAttribLui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64EXT *))IntGetProcAddress("glGetVertexAttribLui64vNV");
	if(!_ptrc_glGetVertexAttribLui64vNV) numFailed++;
	_ptrc_glVertexAttribL1i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT))IntGetProcAddress("glVertexAttribL1i64NV");
	if(!_ptrc_glVertexAttribL1i64NV) numFailed++;
	_ptrc_glVertexAttribL1i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL1i64vNV");
	if(!_ptrc_glVertexAttribL1i64vNV) numFailed++;
	_ptrc_glVertexAttribL1ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT))IntGetProcAddress("glVertexAttribL1ui64NV");
	if(!_ptrc_glVertexAttribL1ui64NV) numFailed++;
	_ptrc_glVertexAttribL1ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL1ui64vNV");
	if(!_ptrc_glVertexAttribL1ui64vNV) numFailed++;
	_ptrc_glVertexAttribL2i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT, GLint64EXT))IntGetProcAddress("glVertexAttribL2i64NV");
	if(!_ptrc_glVertexAttribL2i64NV) numFailed++;
	_ptrc_glVertexAttribL2i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL2i64vNV");
	if(!_ptrc_glVertexAttribL2i64vNV) numFailed++;
	_ptrc_glVertexAttribL2ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glVertexAttribL2ui64NV");
	if(!_ptrc_glVertexAttribL2ui64NV) numFailed++;
	_ptrc_glVertexAttribL2ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL2ui64vNV");
	if(!_ptrc_glVertexAttribL2ui64vNV) numFailed++;
	_ptrc_glVertexAttribL3i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glVertexAttribL3i64NV");
	if(!_ptrc_glVertexAttribL3i64NV) numFailed++;
	_ptrc_glVertexAttribL3i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL3i64vNV");
	if(!_ptrc_glVertexAttribL3i64vNV) numFailed++;
	_ptrc_glVertexAttribL3ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glVertexAttribL3ui64NV");
	if(!_ptrc_glVertexAttribL3ui64NV) numFailed++;
	_ptrc_glVertexAttribL3ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL3ui64vNV");
	if(!_ptrc_glVertexAttribL3ui64vNV) numFailed++;
	_ptrc_glVertexAttribL4i64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint64EXT, GLint64EXT, GLint64EXT, GLint64EXT))IntGetProcAddress("glVertexAttribL4i64NV");
	if(!_ptrc_glVertexAttribL4i64NV) numFailed++;
	_ptrc_glVertexAttribL4i64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint64EXT *))IntGetProcAddress("glVertexAttribL4i64vNV");
	if(!_ptrc_glVertexAttribL4i64vNV) numFailed++;
	_ptrc_glVertexAttribL4ui64NV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint64EXT, GLuint64EXT, GLuint64EXT, GLuint64EXT))IntGetProcAddress("glVertexAttribL4ui64NV");
	if(!_ptrc_glVertexAttribL4ui64NV) numFailed++;
	_ptrc_glVertexAttribL4ui64vNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint64EXT *))IntGetProcAddress("glVertexAttribL4ui64vNV");
	if(!_ptrc_glVertexAttribL4ui64vNV) numFailed++;
	_ptrc_glVertexAttribLFormatNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei))IntGetProcAddress("glVertexAttribLFormatNV");
	if(!_ptrc_glVertexAttribLFormatNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBufferAddressRangeNV)(GLenum, GLuint, GLuint64EXT, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorFormatNV)(GLint, GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagFormatNV)(GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordFormatNV)(GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerui64i_vNV)(GLenum, GLuint, GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexFormatNV)(GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalFormatNV)(GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorFormatNV)(GLint, GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordFormatNV)(GLint, GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribFormatNV)(GLuint, GLint, GLenum, GLboolean, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIFormatNV)(GLuint, GLint, GLenum, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexFormatNV)(GLint, GLenum, GLsizei) = NULL;

static int Load_NV_vertex_buffer_unified_memory()
{
	int numFailed = 0;
	_ptrc_glBufferAddressRangeNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint64EXT, GLsizeiptr))IntGetProcAddress("glBufferAddressRangeNV");
	if(!_ptrc_glBufferAddressRangeNV) numFailed++;
	_ptrc_glColorFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glColorFormatNV");
	if(!_ptrc_glColorFormatNV) numFailed++;
	_ptrc_glEdgeFlagFormatNV = (void (CODEGEN_FUNCPTR *)(GLsizei))IntGetProcAddress("glEdgeFlagFormatNV");
	if(!_ptrc_glEdgeFlagFormatNV) numFailed++;
	_ptrc_glFogCoordFormatNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei))IntGetProcAddress("glFogCoordFormatNV");
	if(!_ptrc_glFogCoordFormatNV) numFailed++;
	_ptrc_glGetIntegerui64i_vNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint64EXT *))IntGetProcAddress("glGetIntegerui64i_vNV");
	if(!_ptrc_glGetIntegerui64i_vNV) numFailed++;
	_ptrc_glIndexFormatNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei))IntGetProcAddress("glIndexFormatNV");
	if(!_ptrc_glIndexFormatNV) numFailed++;
	_ptrc_glNormalFormatNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei))IntGetProcAddress("glNormalFormatNV");
	if(!_ptrc_glNormalFormatNV) numFailed++;
	_ptrc_glSecondaryColorFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glSecondaryColorFormatNV");
	if(!_ptrc_glSecondaryColorFormatNV) numFailed++;
	_ptrc_glTexCoordFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glTexCoordFormatNV");
	if(!_ptrc_glTexCoordFormatNV) numFailed++;
	_ptrc_glVertexAttribFormatNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei))IntGetProcAddress("glVertexAttribFormatNV");
	if(!_ptrc_glVertexAttribFormatNV) numFailed++;
	_ptrc_glVertexAttribIFormatNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei))IntGetProcAddress("glVertexAttribIFormatNV");
	if(!_ptrc_glVertexAttribIFormatNV) numFailed++;
	_ptrc_glVertexFormatNV = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei))IntGetProcAddress("glVertexFormatNV");
	if(!_ptrc_glVertexFormatNV) numFailed++;
	return numFailed;
}

GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreProgramsResidentNV)(GLsizei, const GLuint *, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindProgramNV)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgramsNV)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glExecuteProgramNV)(GLenum, GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenProgramsNV)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterdvNV)(GLenum, GLuint, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramParameterfvNV)(GLenum, GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramStringNV)(GLuint, GLenum, GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramivNV)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTrackMatrixivNV)(GLenum, GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointervNV)(GLuint, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdvNV)(GLuint, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfvNV)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribivNV)(GLuint, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgramNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadProgramNV)(GLenum, GLuint, GLsizei, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dNV)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4dvNV)(GLenum, GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fNV)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameter4fvNV)(GLenum, GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4dvNV)(GLenum, GLuint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glProgramParameters4fvNV)(GLenum, GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRequestResidentProgramsNV)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTrackMatrixNV)(GLenum, GLuint, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dNV)(GLuint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dvNV)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fNV)(GLuint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fvNV)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sNV)(GLuint, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1svNV)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dNV)(GLuint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dvNV)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fNV)(GLuint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fvNV)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sNV)(GLuint, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2svNV)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dNV)(GLuint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dvNV)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fNV)(GLuint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fvNV)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sNV)(GLuint, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3svNV)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dNV)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dvNV)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fNV)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fvNV)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sNV)(GLuint, GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4svNV)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubNV)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubvNV)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointerNV)(GLuint, GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1dvNV)(GLuint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1fvNV)(GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs1svNV)(GLuint, GLsizei, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2dvNV)(GLuint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2fvNV)(GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs2svNV)(GLuint, GLsizei, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3dvNV)(GLuint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3fvNV)(GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs3svNV)(GLuint, GLsizei, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4dvNV)(GLuint, GLsizei, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4fvNV)(GLuint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4svNV)(GLuint, GLsizei, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribs4ubvNV)(GLuint, GLsizei, const GLubyte *) = NULL;

static int Load_NV_vertex_program()
{
	int numFailed = 0;
	_ptrc_glAreProgramsResidentNV = (GLboolean (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLboolean *))IntGetProcAddress("glAreProgramsResidentNV");
	if(!_ptrc_glAreProgramsResidentNV) numFailed++;
	_ptrc_glBindProgramNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindProgramNV");
	if(!_ptrc_glBindProgramNV) numFailed++;
	_ptrc_glDeleteProgramsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramsNV");
	if(!_ptrc_glDeleteProgramsNV) numFailed++;
	_ptrc_glExecuteProgramNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glExecuteProgramNV");
	if(!_ptrc_glExecuteProgramNV) numFailed++;
	_ptrc_glGenProgramsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramsNV");
	if(!_ptrc_glGenProgramsNV) numFailed++;
	_ptrc_glGetProgramParameterdvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetProgramParameterdvNV");
	if(!_ptrc_glGetProgramParameterdvNV) numFailed++;
	_ptrc_glGetProgramParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetProgramParameterfvNV");
	if(!_ptrc_glGetProgramParameterfvNV) numFailed++;
	_ptrc_glGetProgramStringNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLubyte *))IntGetProcAddress("glGetProgramStringNV");
	if(!_ptrc_glGetProgramStringNV) numFailed++;
	_ptrc_glGetProgramivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramivNV");
	if(!_ptrc_glGetProgramivNV) numFailed++;
	_ptrc_glGetTrackMatrixivNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetTrackMatrixivNV");
	if(!_ptrc_glGetTrackMatrixivNV) numFailed++;
	_ptrc_glGetVertexAttribPointervNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLvoid **))IntGetProcAddress("glGetVertexAttribPointervNV");
	if(!_ptrc_glGetVertexAttribPointervNV) numFailed++;
	_ptrc_glGetVertexAttribdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribdvNV");
	if(!_ptrc_glGetVertexAttribdvNV) numFailed++;
	_ptrc_glGetVertexAttribfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribfvNV");
	if(!_ptrc_glGetVertexAttribfvNV) numFailed++;
	_ptrc_glGetVertexAttribivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribivNV");
	if(!_ptrc_glGetVertexAttribivNV) numFailed++;
	_ptrc_glIsProgramNV = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramNV");
	if(!_ptrc_glIsProgramNV) numFailed++;
	_ptrc_glLoadProgramNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLubyte *))IntGetProcAddress("glLoadProgramNV");
	if(!_ptrc_glLoadProgramNV) numFailed++;
	_ptrc_glProgramParameter4dNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramParameter4dNV");
	if(!_ptrc_glProgramParameter4dNV) numFailed++;
	_ptrc_glProgramParameter4dvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLdouble *))IntGetProcAddress("glProgramParameter4dvNV");
	if(!_ptrc_glProgramParameter4dvNV) numFailed++;
	_ptrc_glProgramParameter4fNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramParameter4fNV");
	if(!_ptrc_glProgramParameter4fNV) numFailed++;
	_ptrc_glProgramParameter4fvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, const GLfloat *))IntGetProcAddress("glProgramParameter4fvNV");
	if(!_ptrc_glProgramParameter4fvNV) numFailed++;
	_ptrc_glProgramParameters4dvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramParameters4dvNV");
	if(!_ptrc_glProgramParameters4dvNV) numFailed++;
	_ptrc_glProgramParameters4fvNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramParameters4fvNV");
	if(!_ptrc_glProgramParameters4fvNV) numFailed++;
	_ptrc_glRequestResidentProgramsNV = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glRequestResidentProgramsNV");
	if(!_ptrc_glRequestResidentProgramsNV) numFailed++;
	_ptrc_glTrackMatrixNV = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLenum))IntGetProcAddress("glTrackMatrixNV");
	if(!_ptrc_glTrackMatrixNV) numFailed++;
	_ptrc_glVertexAttrib1dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttrib1dNV");
	if(!_ptrc_glVertexAttrib1dNV) numFailed++;
	_ptrc_glVertexAttrib1dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib1dvNV");
	if(!_ptrc_glVertexAttrib1dvNV) numFailed++;
	_ptrc_glVertexAttrib1fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat))IntGetProcAddress("glVertexAttrib1fNV");
	if(!_ptrc_glVertexAttrib1fNV) numFailed++;
	_ptrc_glVertexAttrib1fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib1fvNV");
	if(!_ptrc_glVertexAttrib1fvNV) numFailed++;
	_ptrc_glVertexAttrib1sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort))IntGetProcAddress("glVertexAttrib1sNV");
	if(!_ptrc_glVertexAttrib1sNV) numFailed++;
	_ptrc_glVertexAttrib1svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib1svNV");
	if(!_ptrc_glVertexAttrib1svNV) numFailed++;
	_ptrc_glVertexAttrib2dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib2dNV");
	if(!_ptrc_glVertexAttrib2dNV) numFailed++;
	_ptrc_glVertexAttrib2dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib2dvNV");
	if(!_ptrc_glVertexAttrib2dvNV) numFailed++;
	_ptrc_glVertexAttrib2fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib2fNV");
	if(!_ptrc_glVertexAttrib2fNV) numFailed++;
	_ptrc_glVertexAttrib2fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib2fvNV");
	if(!_ptrc_glVertexAttrib2fvNV) numFailed++;
	_ptrc_glVertexAttrib2sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort))IntGetProcAddress("glVertexAttrib2sNV");
	if(!_ptrc_glVertexAttrib2sNV) numFailed++;
	_ptrc_glVertexAttrib2svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib2svNV");
	if(!_ptrc_glVertexAttrib2svNV) numFailed++;
	_ptrc_glVertexAttrib3dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib3dNV");
	if(!_ptrc_glVertexAttrib3dNV) numFailed++;
	_ptrc_glVertexAttrib3dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib3dvNV");
	if(!_ptrc_glVertexAttrib3dvNV) numFailed++;
	_ptrc_glVertexAttrib3fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib3fNV");
	if(!_ptrc_glVertexAttrib3fNV) numFailed++;
	_ptrc_glVertexAttrib3fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib3fvNV");
	if(!_ptrc_glVertexAttrib3fvNV) numFailed++;
	_ptrc_glVertexAttrib3sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib3sNV");
	if(!_ptrc_glVertexAttrib3sNV) numFailed++;
	_ptrc_glVertexAttrib3svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib3svNV");
	if(!_ptrc_glVertexAttrib3svNV) numFailed++;
	_ptrc_glVertexAttrib4dNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib4dNV");
	if(!_ptrc_glVertexAttrib4dNV) numFailed++;
	_ptrc_glVertexAttrib4dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib4dvNV");
	if(!_ptrc_glVertexAttrib4dvNV) numFailed++;
	_ptrc_glVertexAttrib4fNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib4fNV");
	if(!_ptrc_glVertexAttrib4fNV) numFailed++;
	_ptrc_glVertexAttrib4fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib4fvNV");
	if(!_ptrc_glVertexAttrib4fvNV) numFailed++;
	_ptrc_glVertexAttrib4sNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib4sNV");
	if(!_ptrc_glVertexAttrib4sNV) numFailed++;
	_ptrc_glVertexAttrib4svNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4svNV");
	if(!_ptrc_glVertexAttrib4svNV) numFailed++;
	_ptrc_glVertexAttrib4ubNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glVertexAttrib4ubNV");
	if(!_ptrc_glVertexAttrib4ubNV) numFailed++;
	_ptrc_glVertexAttrib4ubvNV = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4ubvNV");
	if(!_ptrc_glVertexAttrib4ubvNV) numFailed++;
	_ptrc_glVertexAttribPointerNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribPointerNV");
	if(!_ptrc_glVertexAttribPointerNV) numFailed++;
	_ptrc_glVertexAttribs1dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs1dvNV");
	if(!_ptrc_glVertexAttribs1dvNV) numFailed++;
	_ptrc_glVertexAttribs1fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs1fvNV");
	if(!_ptrc_glVertexAttribs1fvNV) numFailed++;
	_ptrc_glVertexAttribs1svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs1svNV");
	if(!_ptrc_glVertexAttribs1svNV) numFailed++;
	_ptrc_glVertexAttribs2dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs2dvNV");
	if(!_ptrc_glVertexAttribs2dvNV) numFailed++;
	_ptrc_glVertexAttribs2fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs2fvNV");
	if(!_ptrc_glVertexAttribs2fvNV) numFailed++;
	_ptrc_glVertexAttribs2svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs2svNV");
	if(!_ptrc_glVertexAttribs2svNV) numFailed++;
	_ptrc_glVertexAttribs3dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs3dvNV");
	if(!_ptrc_glVertexAttribs3dvNV) numFailed++;
	_ptrc_glVertexAttribs3fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs3fvNV");
	if(!_ptrc_glVertexAttribs3fvNV) numFailed++;
	_ptrc_glVertexAttribs3svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs3svNV");
	if(!_ptrc_glVertexAttribs3svNV) numFailed++;
	_ptrc_glVertexAttribs4dvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glVertexAttribs4dvNV");
	if(!_ptrc_glVertexAttribs4dvNV) numFailed++;
	_ptrc_glVertexAttribs4fvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glVertexAttribs4fvNV");
	if(!_ptrc_glVertexAttribs4fvNV) numFailed++;
	_ptrc_glVertexAttribs4svNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLshort *))IntGetProcAddress("glVertexAttribs4svNV");
	if(!_ptrc_glVertexAttribs4svNV) numFailed++;
	_ptrc_glVertexAttribs4ubvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLubyte *))IntGetProcAddress("glVertexAttribs4ubvNV");
	if(!_ptrc_glVertexAttribs4ubvNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIivEXT)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIuivEXT)(GLuint, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1iEXT)(GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1ivEXT)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uiEXT)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uivEXT)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2iEXT)(GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2ivEXT)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uiEXT)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uivEXT)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3iEXT)(GLuint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3ivEXT)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uiEXT)(GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uivEXT)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4bvEXT)(GLuint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4iEXT)(GLuint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ivEXT)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4svEXT)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ubvEXT)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uiEXT)(GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uivEXT)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4usvEXT)(GLuint, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIPointerEXT)(GLuint, GLint, GLenum, GLsizei, const GLvoid *) = NULL;

static int Load_NV_vertex_program4()
{
	int numFailed = 0;
	_ptrc_glGetVertexAttribIivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribIivEXT");
	if(!_ptrc_glGetVertexAttribIivEXT) numFailed++;
	_ptrc_glGetVertexAttribIuivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetVertexAttribIuivEXT");
	if(!_ptrc_glGetVertexAttribIuivEXT) numFailed++;
	_ptrc_glVertexAttribI1iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glVertexAttribI1iEXT");
	if(!_ptrc_glVertexAttribI1iEXT) numFailed++;
	_ptrc_glVertexAttribI1ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI1ivEXT");
	if(!_ptrc_glVertexAttribI1ivEXT) numFailed++;
	_ptrc_glVertexAttribI1uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribI1uiEXT");
	if(!_ptrc_glVertexAttribI1uiEXT) numFailed++;
	_ptrc_glVertexAttribI1uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI1uivEXT");
	if(!_ptrc_glVertexAttribI1uivEXT) numFailed++;
	_ptrc_glVertexAttribI2iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glVertexAttribI2iEXT");
	if(!_ptrc_glVertexAttribI2iEXT) numFailed++;
	_ptrc_glVertexAttribI2ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI2ivEXT");
	if(!_ptrc_glVertexAttribI2ivEXT) numFailed++;
	_ptrc_glVertexAttribI2uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI2uiEXT");
	if(!_ptrc_glVertexAttribI2uiEXT) numFailed++;
	_ptrc_glVertexAttribI2uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI2uivEXT");
	if(!_ptrc_glVertexAttribI2uivEXT) numFailed++;
	_ptrc_glVertexAttribI3iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glVertexAttribI3iEXT");
	if(!_ptrc_glVertexAttribI3iEXT) numFailed++;
	_ptrc_glVertexAttribI3ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI3ivEXT");
	if(!_ptrc_glVertexAttribI3ivEXT) numFailed++;
	_ptrc_glVertexAttribI3uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI3uiEXT");
	if(!_ptrc_glVertexAttribI3uiEXT) numFailed++;
	_ptrc_glVertexAttribI3uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI3uivEXT");
	if(!_ptrc_glVertexAttribI3uivEXT) numFailed++;
	_ptrc_glVertexAttribI4bvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttribI4bvEXT");
	if(!_ptrc_glVertexAttribI4bvEXT) numFailed++;
	_ptrc_glVertexAttribI4iEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glVertexAttribI4iEXT");
	if(!_ptrc_glVertexAttribI4iEXT) numFailed++;
	_ptrc_glVertexAttribI4ivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI4ivEXT");
	if(!_ptrc_glVertexAttribI4ivEXT) numFailed++;
	_ptrc_glVertexAttribI4svEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttribI4svEXT");
	if(!_ptrc_glVertexAttribI4svEXT) numFailed++;
	_ptrc_glVertexAttribI4ubvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttribI4ubvEXT");
	if(!_ptrc_glVertexAttribI4ubvEXT) numFailed++;
	_ptrc_glVertexAttribI4uiEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI4uiEXT");
	if(!_ptrc_glVertexAttribI4uiEXT) numFailed++;
	_ptrc_glVertexAttribI4uivEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI4uivEXT");
	if(!_ptrc_glVertexAttribI4uivEXT) numFailed++;
	_ptrc_glVertexAttribI4usvEXT = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttribI4usvEXT");
	if(!_ptrc_glVertexAttribI4usvEXT) numFailed++;
	_ptrc_glVertexAttribIPointerEXT = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribIPointerEXT");
	if(!_ptrc_glVertexAttribIPointerEXT) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glBeginVideoCaptureNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamBufferNV)(GLuint, GLuint, GLenum, GLintptrARB) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindVideoCaptureStreamTextureNV)(GLuint, GLuint, GLenum, GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndVideoCaptureNV)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamdvNV)(GLuint, GLuint, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamfvNV)(GLuint, GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureStreamivNV)(GLuint, GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVideoCaptureivNV)(GLuint, GLenum, GLint *) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureNV)(GLuint, GLuint *, GLuint64EXT *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterdvNV)(GLuint, GLuint, GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterfvNV)(GLuint, GLuint, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVideoCaptureStreamParameterivNV)(GLuint, GLuint, GLenum, const GLint *) = NULL;

static int Load_NV_video_capture()
{
	int numFailed = 0;
	_ptrc_glBeginVideoCaptureNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBeginVideoCaptureNV");
	if(!_ptrc_glBeginVideoCaptureNV) numFailed++;
	_ptrc_glBindVideoCaptureStreamBufferNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLintptrARB))IntGetProcAddress("glBindVideoCaptureStreamBufferNV");
	if(!_ptrc_glBindVideoCaptureStreamBufferNV) numFailed++;
	_ptrc_glBindVideoCaptureStreamTextureNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLenum, GLuint))IntGetProcAddress("glBindVideoCaptureStreamTextureNV");
	if(!_ptrc_glBindVideoCaptureStreamTextureNV) numFailed++;
	_ptrc_glEndVideoCaptureNV = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEndVideoCaptureNV");
	if(!_ptrc_glEndVideoCaptureNV) numFailed++;
	_ptrc_glGetVideoCaptureStreamdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVideoCaptureStreamdvNV");
	if(!_ptrc_glGetVideoCaptureStreamdvNV) numFailed++;
	_ptrc_glGetVideoCaptureStreamfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVideoCaptureStreamfvNV");
	if(!_ptrc_glGetVideoCaptureStreamfvNV) numFailed++;
	_ptrc_glGetVideoCaptureStreamivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetVideoCaptureStreamivNV");
	if(!_ptrc_glGetVideoCaptureStreamivNV) numFailed++;
	_ptrc_glGetVideoCaptureivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVideoCaptureivNV");
	if(!_ptrc_glGetVideoCaptureivNV) numFailed++;
	_ptrc_glVideoCaptureNV = (GLenum (CODEGEN_FUNCPTR *)(GLuint, GLuint *, GLuint64EXT *))IntGetProcAddress("glVideoCaptureNV");
	if(!_ptrc_glVideoCaptureNV) numFailed++;
	_ptrc_glVideoCaptureStreamParameterdvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLdouble *))IntGetProcAddress("glVideoCaptureStreamParameterdvNV");
	if(!_ptrc_glVideoCaptureStreamParameterdvNV) numFailed++;
	_ptrc_glVideoCaptureStreamParameterfvNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLfloat *))IntGetProcAddress("glVideoCaptureStreamParameterfvNV");
	if(!_ptrc_glVideoCaptureStreamParameterfvNV) numFailed++;
	_ptrc_glVideoCaptureStreamParameterivNV = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, const GLint *))IntGetProcAddress("glVideoCaptureStreamParameterivNV");
	if(!_ptrc_glVideoCaptureStreamParameterivNV) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1bOES)(GLenum, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1bvOES)(GLenum, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2bOES)(GLenum, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2bvOES)(GLenum, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3bOES)(GLenum, GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3bvOES)(GLenum, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4bOES)(GLenum, GLbyte, GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4bvOES)(GLenum, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1bOES)(GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1bvOES)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2bOES)(GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2bvOES)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3bOES)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3bvOES)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4bOES)(GLbyte, GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4bvOES)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2bOES)(GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2bvOES)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3bOES)(GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3bvOES)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4bOES)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4bvOES)(const GLbyte *) = NULL;

static int Load_OES_byte_coordinates()
{
	int numFailed = 0;
	_ptrc_glMultiTexCoord1bOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLbyte))IntGetProcAddress("glMultiTexCoord1bOES");
	if(!_ptrc_glMultiTexCoord1bOES) numFailed++;
	_ptrc_glMultiTexCoord1bvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLbyte *))IntGetProcAddress("glMultiTexCoord1bvOES");
	if(!_ptrc_glMultiTexCoord1bvOES) numFailed++;
	_ptrc_glMultiTexCoord2bOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLbyte, GLbyte))IntGetProcAddress("glMultiTexCoord2bOES");
	if(!_ptrc_glMultiTexCoord2bOES) numFailed++;
	_ptrc_glMultiTexCoord2bvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLbyte *))IntGetProcAddress("glMultiTexCoord2bvOES");
	if(!_ptrc_glMultiTexCoord2bvOES) numFailed++;
	_ptrc_glMultiTexCoord3bOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLbyte, GLbyte, GLbyte))IntGetProcAddress("glMultiTexCoord3bOES");
	if(!_ptrc_glMultiTexCoord3bOES) numFailed++;
	_ptrc_glMultiTexCoord3bvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLbyte *))IntGetProcAddress("glMultiTexCoord3bvOES");
	if(!_ptrc_glMultiTexCoord3bvOES) numFailed++;
	_ptrc_glMultiTexCoord4bOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLbyte, GLbyte, GLbyte, GLbyte))IntGetProcAddress("glMultiTexCoord4bOES");
	if(!_ptrc_glMultiTexCoord4bOES) numFailed++;
	_ptrc_glMultiTexCoord4bvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLbyte *))IntGetProcAddress("glMultiTexCoord4bvOES");
	if(!_ptrc_glMultiTexCoord4bvOES) numFailed++;
	_ptrc_glTexCoord1bOES = (void (CODEGEN_FUNCPTR *)(GLbyte))IntGetProcAddress("glTexCoord1bOES");
	if(!_ptrc_glTexCoord1bOES) numFailed++;
	_ptrc_glTexCoord1bvOES = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glTexCoord1bvOES");
	if(!_ptrc_glTexCoord1bvOES) numFailed++;
	_ptrc_glTexCoord2bOES = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte))IntGetProcAddress("glTexCoord2bOES");
	if(!_ptrc_glTexCoord2bOES) numFailed++;
	_ptrc_glTexCoord2bvOES = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glTexCoord2bvOES");
	if(!_ptrc_glTexCoord2bvOES) numFailed++;
	_ptrc_glTexCoord3bOES = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glTexCoord3bOES");
	if(!_ptrc_glTexCoord3bOES) numFailed++;
	_ptrc_glTexCoord3bvOES = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glTexCoord3bvOES");
	if(!_ptrc_glTexCoord3bvOES) numFailed++;
	_ptrc_glTexCoord4bOES = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte, GLbyte))IntGetProcAddress("glTexCoord4bOES");
	if(!_ptrc_glTexCoord4bOES) numFailed++;
	_ptrc_glTexCoord4bvOES = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glTexCoord4bvOES");
	if(!_ptrc_glTexCoord4bvOES) numFailed++;
	_ptrc_glVertex2bOES = (void (CODEGEN_FUNCPTR *)(GLbyte))IntGetProcAddress("glVertex2bOES");
	if(!_ptrc_glVertex2bOES) numFailed++;
	_ptrc_glVertex2bvOES = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glVertex2bvOES");
	if(!_ptrc_glVertex2bvOES) numFailed++;
	_ptrc_glVertex3bOES = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte))IntGetProcAddress("glVertex3bOES");
	if(!_ptrc_glVertex3bOES) numFailed++;
	_ptrc_glVertex3bvOES = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glVertex3bvOES");
	if(!_ptrc_glVertex3bvOES) numFailed++;
	_ptrc_glVertex4bOES = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glVertex4bOES");
	if(!_ptrc_glVertex4bOES) numFailed++;
	_ptrc_glVertex4bvOES = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glVertex4bvOES");
	if(!_ptrc_glVertex4bvOES) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glAccumxOES)(GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glAlphaFuncxOES)(GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBitmapxOES)(GLsizei, GLsizei, GLfixed, GLfixed, GLfixed, GLfixed, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendColorxOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearAccumxOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearColorxOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearDepthxOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClipPlanexOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3xOES)(GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4xOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterxOES)(GLenum, GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glConvolutionParameterxvOES)(GLenum, GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangexOES)(GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1xOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2xOES)(GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFeedbackBufferxOES)(GLsizei, GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogxOES)(GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogxvOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFrustumxOES)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetClipPlanexOES)(GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetConvolutionParameterxvOES)(GLenum, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFixedvOES)(GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetHistogramParameterxvOES)(GLenum, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetLightxOES)(GLenum, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapxvOES)(GLenum, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMaterialxOES)(GLenum, GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapxv)(GLenum, GLint, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexEnvxvOES)(GLenum, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexGenxvOES)(GLenum, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameterxvOES)(GLenum, GLint, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterxvOES)(GLenum, GLenum, GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexxOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexxvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightModelxOES)(GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightModelxvOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightxOES)(GLenum, GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightxvOES)(GLenum, GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLineWidthxOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadMatrixxOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixxOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMap1xOES)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMap2xOES)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed, GLfixed, GLint, GLint, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapGrid1xOES)(GLint, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapGrid2xOES)(GLint, GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMaterialxOES)(GLenum, GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMaterialxvOES)(GLenum, GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultMatrixxOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixxOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1xOES)(GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1xvOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2xOES)(GLenum, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2xvOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3xOES)(GLenum, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3xvOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4xOES)(GLenum, GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4xvOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3xOES)(GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glOrthoxOES)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPassThroughxOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelMapx)(GLenum, GLint, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelStorex)(GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTransferxOES)(GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelZoomxOES)(GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterxvOES)(GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointSizexOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffsetxOES)(GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTexturesxOES)(GLsizei, const GLuint *, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2xOES)(GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3xOES)(GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4xOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectxOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectxvOES)(const GLfixed *, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRotatexOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverageOES)(GLfixed, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScalexOES)(GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1xOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2xOES)(GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3xOES)(GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4xOES)(GLfixed, GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexEnvxOES)(GLenum, GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexEnvxvOES)(GLenum, GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGenxOES)(GLenum, GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGenxvOES)(GLenum, GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterxOES)(GLenum, GLenum, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterxvOES)(GLenum, GLenum, const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTranslatexOES)(GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2xOES)(GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3xOES)(GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3xvOES)(const GLfixed *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4xOES)(GLfixed, GLfixed, GLfixed) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4xvOES)(const GLfixed *) = NULL;

static int Load_OES_fixed_point()
{
	int numFailed = 0;
	_ptrc_glAccumxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed))IntGetProcAddress("glAccumxOES");
	if(!_ptrc_glAccumxOES) numFailed++;
	_ptrc_glAlphaFuncxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed))IntGetProcAddress("glAlphaFuncxOES");
	if(!_ptrc_glAlphaFuncxOES) numFailed++;
	_ptrc_glBitmapxOES = (void (CODEGEN_FUNCPTR *)(GLsizei, GLsizei, GLfixed, GLfixed, GLfixed, GLfixed, const GLubyte *))IntGetProcAddress("glBitmapxOES");
	if(!_ptrc_glBitmapxOES) numFailed++;
	_ptrc_glBlendColorxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glBlendColorxOES");
	if(!_ptrc_glBlendColorxOES) numFailed++;
	_ptrc_glClearAccumxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glClearAccumxOES");
	if(!_ptrc_glClearAccumxOES) numFailed++;
	_ptrc_glClearColorxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glClearColorxOES");
	if(!_ptrc_glClearColorxOES) numFailed++;
	_ptrc_glClearDepthxOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glClearDepthxOES");
	if(!_ptrc_glClearDepthxOES) numFailed++;
	_ptrc_glClipPlanexOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glClipPlanexOES");
	if(!_ptrc_glClipPlanexOES) numFailed++;
	_ptrc_glColor3xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed))IntGetProcAddress("glColor3xOES");
	if(!_ptrc_glColor3xOES) numFailed++;
	_ptrc_glColor3xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glColor3xvOES");
	if(!_ptrc_glColor3xvOES) numFailed++;
	_ptrc_glColor4xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glColor4xOES");
	if(!_ptrc_glColor4xOES) numFailed++;
	_ptrc_glColor4xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glColor4xvOES");
	if(!_ptrc_glColor4xvOES) numFailed++;
	_ptrc_glConvolutionParameterxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed))IntGetProcAddress("glConvolutionParameterxOES");
	if(!_ptrc_glConvolutionParameterxOES) numFailed++;
	_ptrc_glConvolutionParameterxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfixed *))IntGetProcAddress("glConvolutionParameterxvOES");
	if(!_ptrc_glConvolutionParameterxvOES) numFailed++;
	_ptrc_glDepthRangexOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed))IntGetProcAddress("glDepthRangexOES");
	if(!_ptrc_glDepthRangexOES) numFailed++;
	_ptrc_glEvalCoord1xOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glEvalCoord1xOES");
	if(!_ptrc_glEvalCoord1xOES) numFailed++;
	_ptrc_glEvalCoord1xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glEvalCoord1xvOES");
	if(!_ptrc_glEvalCoord1xvOES) numFailed++;
	_ptrc_glEvalCoord2xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed))IntGetProcAddress("glEvalCoord2xOES");
	if(!_ptrc_glEvalCoord2xOES) numFailed++;
	_ptrc_glEvalCoord2xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glEvalCoord2xvOES");
	if(!_ptrc_glEvalCoord2xvOES) numFailed++;
	_ptrc_glFeedbackBufferxOES = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const GLfixed *))IntGetProcAddress("glFeedbackBufferxOES");
	if(!_ptrc_glFeedbackBufferxOES) numFailed++;
	_ptrc_glFogxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed))IntGetProcAddress("glFogxOES");
	if(!_ptrc_glFogxOES) numFailed++;
	_ptrc_glFogxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glFogxvOES");
	if(!_ptrc_glFogxvOES) numFailed++;
	_ptrc_glFrustumxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glFrustumxOES");
	if(!_ptrc_glFrustumxOES) numFailed++;
	_ptrc_glGetClipPlanexOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed *))IntGetProcAddress("glGetClipPlanexOES");
	if(!_ptrc_glGetClipPlanexOES) numFailed++;
	_ptrc_glGetConvolutionParameterxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed *))IntGetProcAddress("glGetConvolutionParameterxvOES");
	if(!_ptrc_glGetConvolutionParameterxvOES) numFailed++;
	_ptrc_glGetFixedvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed *))IntGetProcAddress("glGetFixedvOES");
	if(!_ptrc_glGetFixedvOES) numFailed++;
	_ptrc_glGetHistogramParameterxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed *))IntGetProcAddress("glGetHistogramParameterxvOES");
	if(!_ptrc_glGetHistogramParameterxvOES) numFailed++;
	_ptrc_glGetLightxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed *))IntGetProcAddress("glGetLightxOES");
	if(!_ptrc_glGetLightxOES) numFailed++;
	_ptrc_glGetMapxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed *))IntGetProcAddress("glGetMapxvOES");
	if(!_ptrc_glGetMapxvOES) numFailed++;
	_ptrc_glGetMaterialxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed))IntGetProcAddress("glGetMaterialxOES");
	if(!_ptrc_glGetMaterialxOES) numFailed++;
	_ptrc_glGetPixelMapxv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLfixed *))IntGetProcAddress("glGetPixelMapxv");
	if(!_ptrc_glGetPixelMapxv) numFailed++;
	_ptrc_glGetTexEnvxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed *))IntGetProcAddress("glGetTexEnvxvOES");
	if(!_ptrc_glGetTexEnvxvOES) numFailed++;
	_ptrc_glGetTexGenxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed *))IntGetProcAddress("glGetTexGenxvOES");
	if(!_ptrc_glGetTexGenxvOES) numFailed++;
	_ptrc_glGetTexLevelParameterxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLfixed *))IntGetProcAddress("glGetTexLevelParameterxvOES");
	if(!_ptrc_glGetTexLevelParameterxvOES) numFailed++;
	_ptrc_glGetTexParameterxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed *))IntGetProcAddress("glGetTexParameterxvOES");
	if(!_ptrc_glGetTexParameterxvOES) numFailed++;
	_ptrc_glIndexxOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glIndexxOES");
	if(!_ptrc_glIndexxOES) numFailed++;
	_ptrc_glIndexxvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glIndexxvOES");
	if(!_ptrc_glIndexxvOES) numFailed++;
	_ptrc_glLightModelxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed))IntGetProcAddress("glLightModelxOES");
	if(!_ptrc_glLightModelxOES) numFailed++;
	_ptrc_glLightModelxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glLightModelxvOES");
	if(!_ptrc_glLightModelxvOES) numFailed++;
	_ptrc_glLightxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed))IntGetProcAddress("glLightxOES");
	if(!_ptrc_glLightxOES) numFailed++;
	_ptrc_glLightxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfixed *))IntGetProcAddress("glLightxvOES");
	if(!_ptrc_glLightxvOES) numFailed++;
	_ptrc_glLineWidthxOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glLineWidthxOES");
	if(!_ptrc_glLineWidthxOES) numFailed++;
	_ptrc_glLoadMatrixxOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glLoadMatrixxOES");
	if(!_ptrc_glLoadMatrixxOES) numFailed++;
	_ptrc_glLoadTransposeMatrixxOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glLoadTransposeMatrixxOES");
	if(!_ptrc_glLoadTransposeMatrixxOES) numFailed++;
	_ptrc_glMap1xOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed))IntGetProcAddress("glMap1xOES");
	if(!_ptrc_glMap1xOES) numFailed++;
	_ptrc_glMap2xOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed, GLfixed, GLint, GLint, GLfixed, GLfixed, GLint, GLint, GLfixed))IntGetProcAddress("glMap2xOES");
	if(!_ptrc_glMap2xOES) numFailed++;
	_ptrc_glMapGrid1xOES = (void (CODEGEN_FUNCPTR *)(GLint, GLfixed, GLfixed))IntGetProcAddress("glMapGrid1xOES");
	if(!_ptrc_glMapGrid1xOES) numFailed++;
	_ptrc_glMapGrid2xOES = (void (CODEGEN_FUNCPTR *)(GLint, GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glMapGrid2xOES");
	if(!_ptrc_glMapGrid2xOES) numFailed++;
	_ptrc_glMaterialxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed))IntGetProcAddress("glMaterialxOES");
	if(!_ptrc_glMaterialxOES) numFailed++;
	_ptrc_glMaterialxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfixed *))IntGetProcAddress("glMaterialxvOES");
	if(!_ptrc_glMaterialxvOES) numFailed++;
	_ptrc_glMultMatrixxOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glMultMatrixxOES");
	if(!_ptrc_glMultMatrixxOES) numFailed++;
	_ptrc_glMultTransposeMatrixxOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glMultTransposeMatrixxOES");
	if(!_ptrc_glMultTransposeMatrixxOES) numFailed++;
	_ptrc_glMultiTexCoord1xOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed))IntGetProcAddress("glMultiTexCoord1xOES");
	if(!_ptrc_glMultiTexCoord1xOES) numFailed++;
	_ptrc_glMultiTexCoord1xvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glMultiTexCoord1xvOES");
	if(!_ptrc_glMultiTexCoord1xvOES) numFailed++;
	_ptrc_glMultiTexCoord2xOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed, GLfixed))IntGetProcAddress("glMultiTexCoord2xOES");
	if(!_ptrc_glMultiTexCoord2xOES) numFailed++;
	_ptrc_glMultiTexCoord2xvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glMultiTexCoord2xvOES");
	if(!_ptrc_glMultiTexCoord2xvOES) numFailed++;
	_ptrc_glMultiTexCoord3xOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glMultiTexCoord3xOES");
	if(!_ptrc_glMultiTexCoord3xOES) numFailed++;
	_ptrc_glMultiTexCoord3xvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glMultiTexCoord3xvOES");
	if(!_ptrc_glMultiTexCoord3xvOES) numFailed++;
	_ptrc_glMultiTexCoord4xOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glMultiTexCoord4xOES");
	if(!_ptrc_glMultiTexCoord4xOES) numFailed++;
	_ptrc_glMultiTexCoord4xvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glMultiTexCoord4xvOES");
	if(!_ptrc_glMultiTexCoord4xvOES) numFailed++;
	_ptrc_glNormal3xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed))IntGetProcAddress("glNormal3xOES");
	if(!_ptrc_glNormal3xOES) numFailed++;
	_ptrc_glNormal3xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glNormal3xvOES");
	if(!_ptrc_glNormal3xvOES) numFailed++;
	_ptrc_glOrthoxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glOrthoxOES");
	if(!_ptrc_glOrthoxOES) numFailed++;
	_ptrc_glPassThroughxOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glPassThroughxOES");
	if(!_ptrc_glPassThroughxOES) numFailed++;
	_ptrc_glPixelMapx = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLfixed *))IntGetProcAddress("glPixelMapx");
	if(!_ptrc_glPixelMapx) numFailed++;
	_ptrc_glPixelStorex = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed))IntGetProcAddress("glPixelStorex");
	if(!_ptrc_glPixelStorex) numFailed++;
	_ptrc_glPixelTransferxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfixed))IntGetProcAddress("glPixelTransferxOES");
	if(!_ptrc_glPixelTransferxOES) numFailed++;
	_ptrc_glPixelZoomxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed))IntGetProcAddress("glPixelZoomxOES");
	if(!_ptrc_glPixelZoomxOES) numFailed++;
	_ptrc_glPointParameterxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfixed *))IntGetProcAddress("glPointParameterxvOES");
	if(!_ptrc_glPointParameterxvOES) numFailed++;
	_ptrc_glPointSizexOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glPointSizexOES");
	if(!_ptrc_glPointSizexOES) numFailed++;
	_ptrc_glPolygonOffsetxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed))IntGetProcAddress("glPolygonOffsetxOES");
	if(!_ptrc_glPolygonOffsetxOES) numFailed++;
	_ptrc_glPrioritizeTexturesxOES = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, const GLfixed *))IntGetProcAddress("glPrioritizeTexturesxOES");
	if(!_ptrc_glPrioritizeTexturesxOES) numFailed++;
	_ptrc_glRasterPos2xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed))IntGetProcAddress("glRasterPos2xOES");
	if(!_ptrc_glRasterPos2xOES) numFailed++;
	_ptrc_glRasterPos2xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glRasterPos2xvOES");
	if(!_ptrc_glRasterPos2xvOES) numFailed++;
	_ptrc_glRasterPos3xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed))IntGetProcAddress("glRasterPos3xOES");
	if(!_ptrc_glRasterPos3xOES) numFailed++;
	_ptrc_glRasterPos3xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glRasterPos3xvOES");
	if(!_ptrc_glRasterPos3xvOES) numFailed++;
	_ptrc_glRasterPos4xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glRasterPos4xOES");
	if(!_ptrc_glRasterPos4xOES) numFailed++;
	_ptrc_glRasterPos4xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glRasterPos4xvOES");
	if(!_ptrc_glRasterPos4xvOES) numFailed++;
	_ptrc_glRectxOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glRectxOES");
	if(!_ptrc_glRectxOES) numFailed++;
	_ptrc_glRectxvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *, const GLfixed *))IntGetProcAddress("glRectxvOES");
	if(!_ptrc_glRectxvOES) numFailed++;
	_ptrc_glRotatexOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glRotatexOES");
	if(!_ptrc_glRotatexOES) numFailed++;
	_ptrc_glSampleCoverageOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLboolean))IntGetProcAddress("glSampleCoverageOES");
	if(!_ptrc_glSampleCoverageOES) numFailed++;
	_ptrc_glScalexOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed))IntGetProcAddress("glScalexOES");
	if(!_ptrc_glScalexOES) numFailed++;
	_ptrc_glTexCoord1xOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glTexCoord1xOES");
	if(!_ptrc_glTexCoord1xOES) numFailed++;
	_ptrc_glTexCoord1xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glTexCoord1xvOES");
	if(!_ptrc_glTexCoord1xvOES) numFailed++;
	_ptrc_glTexCoord2xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed))IntGetProcAddress("glTexCoord2xOES");
	if(!_ptrc_glTexCoord2xOES) numFailed++;
	_ptrc_glTexCoord2xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glTexCoord2xvOES");
	if(!_ptrc_glTexCoord2xvOES) numFailed++;
	_ptrc_glTexCoord3xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed))IntGetProcAddress("glTexCoord3xOES");
	if(!_ptrc_glTexCoord3xOES) numFailed++;
	_ptrc_glTexCoord3xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glTexCoord3xvOES");
	if(!_ptrc_glTexCoord3xvOES) numFailed++;
	_ptrc_glTexCoord4xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed, GLfixed))IntGetProcAddress("glTexCoord4xOES");
	if(!_ptrc_glTexCoord4xOES) numFailed++;
	_ptrc_glTexCoord4xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glTexCoord4xvOES");
	if(!_ptrc_glTexCoord4xvOES) numFailed++;
	_ptrc_glTexEnvxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed))IntGetProcAddress("glTexEnvxOES");
	if(!_ptrc_glTexEnvxOES) numFailed++;
	_ptrc_glTexEnvxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfixed *))IntGetProcAddress("glTexEnvxvOES");
	if(!_ptrc_glTexEnvxvOES) numFailed++;
	_ptrc_glTexGenxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed))IntGetProcAddress("glTexGenxOES");
	if(!_ptrc_glTexGenxOES) numFailed++;
	_ptrc_glTexGenxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfixed *))IntGetProcAddress("glTexGenxvOES");
	if(!_ptrc_glTexGenxvOES) numFailed++;
	_ptrc_glTexParameterxOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfixed))IntGetProcAddress("glTexParameterxOES");
	if(!_ptrc_glTexParameterxOES) numFailed++;
	_ptrc_glTexParameterxvOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfixed *))IntGetProcAddress("glTexParameterxvOES");
	if(!_ptrc_glTexParameterxvOES) numFailed++;
	_ptrc_glTranslatexOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed))IntGetProcAddress("glTranslatexOES");
	if(!_ptrc_glTranslatexOES) numFailed++;
	_ptrc_glVertex2xOES = (void (CODEGEN_FUNCPTR *)(GLfixed))IntGetProcAddress("glVertex2xOES");
	if(!_ptrc_glVertex2xOES) numFailed++;
	_ptrc_glVertex2xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glVertex2xvOES");
	if(!_ptrc_glVertex2xvOES) numFailed++;
	_ptrc_glVertex3xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed))IntGetProcAddress("glVertex3xOES");
	if(!_ptrc_glVertex3xOES) numFailed++;
	_ptrc_glVertex3xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glVertex3xvOES");
	if(!_ptrc_glVertex3xvOES) numFailed++;
	_ptrc_glVertex4xOES = (void (CODEGEN_FUNCPTR *)(GLfixed, GLfixed, GLfixed))IntGetProcAddress("glVertex4xOES");
	if(!_ptrc_glVertex4xOES) numFailed++;
	_ptrc_glVertex4xvOES = (void (CODEGEN_FUNCPTR *)(const GLfixed *))IntGetProcAddress("glVertex4xvOES");
	if(!_ptrc_glVertex4xvOES) numFailed++;
	return numFailed;
}

GLbitfield (CODEGEN_FUNCPTR *_ptrc_glQueryMatrixxOES)(GLfixed *, GLint *) = NULL;

static int Load_OES_query_matrix()
{
	int numFailed = 0;
	_ptrc_glQueryMatrixxOES = (GLbitfield (CODEGEN_FUNCPTR *)(GLfixed *, GLint *))IntGetProcAddress("glQueryMatrixxOES");
	if(!_ptrc_glQueryMatrixxOES) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glClearDepthfOES)(GLclampf) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClipPlanefOES)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRangefOES)(GLclampf, GLclampf) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFrustumfOES)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetClipPlanefOES)(GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glOrthofOES)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;

static int Load_OES_single_precision()
{
	int numFailed = 0;
	_ptrc_glClearDepthfOES = (void (CODEGEN_FUNCPTR *)(GLclampf))IntGetProcAddress("glClearDepthfOES");
	if(!_ptrc_glClearDepthfOES) numFailed++;
	_ptrc_glClipPlanefOES = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glClipPlanefOES");
	if(!_ptrc_glClipPlanefOES) numFailed++;
	_ptrc_glDepthRangefOES = (void (CODEGEN_FUNCPTR *)(GLclampf, GLclampf))IntGetProcAddress("glDepthRangefOES");
	if(!_ptrc_glDepthRangefOES) numFailed++;
	_ptrc_glFrustumfOES = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glFrustumfOES");
	if(!_ptrc_glFrustumfOES) numFailed++;
	_ptrc_glGetClipPlanefOES = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetClipPlanefOES");
	if(!_ptrc_glGetClipPlanefOES) numFailed++;
	_ptrc_glOrthofOES = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glOrthofOES");
	if(!_ptrc_glOrthofOES) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glHintPGI)(GLenum, GLint) = NULL;

static int Load_PGI_misc_hints()
{
	int numFailed = 0;
	_ptrc_glHintPGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glHintPGI");
	if(!_ptrc_glHintPGI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDetailTexFuncSGIS)(GLenum, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDetailTexFuncSGIS)(GLenum, GLfloat *) = NULL;

static int Load_SGIS_detail_texture()
{
	int numFailed = 0;
	_ptrc_glDetailTexFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLfloat *))IntGetProcAddress("glDetailTexFuncSGIS");
	if(!_ptrc_glDetailTexFuncSGIS) numFailed++;
	_ptrc_glGetDetailTexFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetDetailTexFuncSGIS");
	if(!_ptrc_glGetDetailTexFuncSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFogFuncSGIS)(GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFogFuncSGIS)(GLfloat *) = NULL;

static int Load_SGIS_fog_function()
{
	int numFailed = 0;
	_ptrc_glFogFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLfloat *))IntGetProcAddress("glFogFuncSGIS");
	if(!_ptrc_glFogFuncSGIS) numFailed++;
	_ptrc_glGetFogFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLfloat *))IntGetProcAddress("glGetFogFuncSGIS");
	if(!_ptrc_glGetFogFuncSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSampleMaskSGIS)(GLclampf, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSamplePatternSGIS)(GLenum) = NULL;

static int Load_SGIS_multisample()
{
	int numFailed = 0;
	_ptrc_glSampleMaskSGIS = (void (CODEGEN_FUNCPTR *)(GLclampf, GLboolean))IntGetProcAddress("glSampleMaskSGIS");
	if(!_ptrc_glSampleMaskSGIS) numFailed++;
	_ptrc_glSamplePatternSGIS = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glSamplePatternSGIS");
	if(!_ptrc_glSamplePatternSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTexGenParameterfvSGIS)(GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPixelTexGenParameterivSGIS)(GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameterfSGIS)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameterfvSGIS)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameteriSGIS)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenParameterivSGIS)(GLenum, const GLint *) = NULL;

static int Load_SGIS_pixel_texture()
{
	int numFailed = 0;
	_ptrc_glGetPixelTexGenParameterfvSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetPixelTexGenParameterfvSGIS");
	if(!_ptrc_glGetPixelTexGenParameterfvSGIS) numFailed++;
	_ptrc_glGetPixelTexGenParameterivSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLint *))IntGetProcAddress("glGetPixelTexGenParameterivSGIS");
	if(!_ptrc_glGetPixelTexGenParameterivSGIS) numFailed++;
	_ptrc_glPixelTexGenParameterfSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPixelTexGenParameterfSGIS");
	if(!_ptrc_glPixelTexGenParameterfSGIS) numFailed++;
	_ptrc_glPixelTexGenParameterfvSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPixelTexGenParameterfvSGIS");
	if(!_ptrc_glPixelTexGenParameterfvSGIS) numFailed++;
	_ptrc_glPixelTexGenParameteriSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPixelTexGenParameteriSGIS");
	if(!_ptrc_glPixelTexGenParameteriSGIS) numFailed++;
	_ptrc_glPixelTexGenParameterivSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glPixelTexGenParameterivSGIS");
	if(!_ptrc_glPixelTexGenParameterivSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfSGIS)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfvSGIS)(GLenum, const GLfloat *) = NULL;

static int Load_SGIS_point_parameters()
{
	int numFailed = 0;
	_ptrc_glPointParameterfSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPointParameterfSGIS");
	if(!_ptrc_glPointParameterfSGIS) numFailed++;
	_ptrc_glPointParameterfvSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPointParameterfvSGIS");
	if(!_ptrc_glPointParameterfvSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetSharpenTexFuncSGIS)(GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSharpenTexFuncSGIS)(GLenum, GLsizei, const GLfloat *) = NULL;

static int Load_SGIS_sharpen_texture()
{
	int numFailed = 0;
	_ptrc_glGetSharpenTexFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetSharpenTexFuncSGIS");
	if(!_ptrc_glGetSharpenTexFuncSGIS) numFailed++;
	_ptrc_glSharpenTexFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLfloat *))IntGetProcAddress("glSharpenTexFuncSGIS");
	if(!_ptrc_glSharpenTexFuncSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTexImage4DSGIS)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage4DSGIS)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;

static int Load_SGIS_texture4D()
{
	int numFailed = 0;
	_ptrc_glTexImage4DSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexImage4DSGIS");
	if(!_ptrc_glTexImage4DSGIS) numFailed++;
	_ptrc_glTexSubImage4DSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexSubImage4DSGIS");
	if(!_ptrc_glTexSubImage4DSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTextureColorMaskSGIS)(GLboolean, GLboolean, GLboolean, GLboolean) = NULL;

static int Load_SGIS_texture_color_mask()
{
	int numFailed = 0;
	_ptrc_glTextureColorMaskSGIS = (void (CODEGEN_FUNCPTR *)(GLboolean, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glTextureColorMaskSGIS");
	if(!_ptrc_glTextureColorMaskSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetTexFilterFuncSGIS)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexFilterFuncSGIS)(GLenum, GLenum, GLsizei, const GLfloat *) = NULL;

static int Load_SGIS_texture_filter4()
{
	int numFailed = 0;
	_ptrc_glGetTexFilterFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetTexFilterFuncSGIS");
	if(!_ptrc_glGetTexFilterFuncSGIS) numFailed++;
	_ptrc_glTexFilterFuncSGIS = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, const GLfloat *))IntGetProcAddress("glTexFilterFuncSGIS");
	if(!_ptrc_glTexFilterFuncSGIS) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glAsyncMarkerSGIX)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteAsyncMarkersSGIX)(GLuint, GLsizei) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glFinishAsyncSGIX)(GLuint *) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGenAsyncMarkersSGIX)(GLsizei) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsAsyncMarkerSGIX)(GLuint) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glPollAsyncSGIX)(GLuint *) = NULL;

static int Load_SGIX_async()
{
	int numFailed = 0;
	_ptrc_glAsyncMarkerSGIX = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glAsyncMarkerSGIX");
	if(!_ptrc_glAsyncMarkerSGIX) numFailed++;
	_ptrc_glDeleteAsyncMarkersSGIX = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei))IntGetProcAddress("glDeleteAsyncMarkersSGIX");
	if(!_ptrc_glDeleteAsyncMarkersSGIX) numFailed++;
	_ptrc_glFinishAsyncSGIX = (GLint (CODEGEN_FUNCPTR *)(GLuint *))IntGetProcAddress("glFinishAsyncSGIX");
	if(!_ptrc_glFinishAsyncSGIX) numFailed++;
	_ptrc_glGenAsyncMarkersSGIX = (GLuint (CODEGEN_FUNCPTR *)(GLsizei))IntGetProcAddress("glGenAsyncMarkersSGIX");
	if(!_ptrc_glGenAsyncMarkersSGIX) numFailed++;
	_ptrc_glIsAsyncMarkerSGIX = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsAsyncMarkerSGIX");
	if(!_ptrc_glIsAsyncMarkerSGIX) numFailed++;
	_ptrc_glPollAsyncSGIX = (GLint (CODEGEN_FUNCPTR *)(GLuint *))IntGetProcAddress("glPollAsyncSGIX");
	if(!_ptrc_glPollAsyncSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFlushRasterSGIX)() = NULL;

static int Load_SGIX_flush_raster()
{
	int numFailed = 0;
	_ptrc_glFlushRasterSGIX = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glFlushRasterSGIX");
	if(!_ptrc_glFlushRasterSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFragmentColorMaterialSGIX)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModelfSGIX)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModelfvSGIX)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModeliSGIX)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightModelivSGIX)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightfSGIX)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightfvSGIX)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightiSGIX)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentLightivSGIX)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialfSGIX)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialfvSGIX)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialiSGIX)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFragmentMaterialivSGIX)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentLightfvSGIX)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentLightivSGIX)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentMaterialfvSGIX)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFragmentMaterialivSGIX)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightEnviSGIX)(GLenum, GLint) = NULL;

static int Load_SGIX_fragment_lighting()
{
	int numFailed = 0;
	_ptrc_glFragmentColorMaterialSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glFragmentColorMaterialSGIX");
	if(!_ptrc_glFragmentColorMaterialSGIX) numFailed++;
	_ptrc_glFragmentLightModelfSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glFragmentLightModelfSGIX");
	if(!_ptrc_glFragmentLightModelfSGIX) numFailed++;
	_ptrc_glFragmentLightModelfvSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glFragmentLightModelfvSGIX");
	if(!_ptrc_glFragmentLightModelfvSGIX) numFailed++;
	_ptrc_glFragmentLightModeliSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glFragmentLightModeliSGIX");
	if(!_ptrc_glFragmentLightModeliSGIX) numFailed++;
	_ptrc_glFragmentLightModelivSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glFragmentLightModelivSGIX");
	if(!_ptrc_glFragmentLightModelivSGIX) numFailed++;
	_ptrc_glFragmentLightfSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glFragmentLightfSGIX");
	if(!_ptrc_glFragmentLightfSGIX) numFailed++;
	_ptrc_glFragmentLightfvSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glFragmentLightfvSGIX");
	if(!_ptrc_glFragmentLightfvSGIX) numFailed++;
	_ptrc_glFragmentLightiSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glFragmentLightiSGIX");
	if(!_ptrc_glFragmentLightiSGIX) numFailed++;
	_ptrc_glFragmentLightivSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glFragmentLightivSGIX");
	if(!_ptrc_glFragmentLightivSGIX) numFailed++;
	_ptrc_glFragmentMaterialfSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glFragmentMaterialfSGIX");
	if(!_ptrc_glFragmentMaterialfSGIX) numFailed++;
	_ptrc_glFragmentMaterialfvSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glFragmentMaterialfvSGIX");
	if(!_ptrc_glFragmentMaterialfvSGIX) numFailed++;
	_ptrc_glFragmentMaterialiSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glFragmentMaterialiSGIX");
	if(!_ptrc_glFragmentMaterialiSGIX) numFailed++;
	_ptrc_glFragmentMaterialivSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glFragmentMaterialivSGIX");
	if(!_ptrc_glFragmentMaterialivSGIX) numFailed++;
	_ptrc_glGetFragmentLightfvSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetFragmentLightfvSGIX");
	if(!_ptrc_glGetFragmentLightfvSGIX) numFailed++;
	_ptrc_glGetFragmentLightivSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFragmentLightivSGIX");
	if(!_ptrc_glGetFragmentLightivSGIX) numFailed++;
	_ptrc_glGetFragmentMaterialfvSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetFragmentMaterialfvSGIX");
	if(!_ptrc_glGetFragmentMaterialfvSGIX) numFailed++;
	_ptrc_glGetFragmentMaterialivSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFragmentMaterialivSGIX");
	if(!_ptrc_glGetFragmentMaterialivSGIX) numFailed++;
	_ptrc_glLightEnviSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glLightEnviSGIX");
	if(!_ptrc_glLightEnviSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFrameZoomSGIX)(GLint) = NULL;

static int Load_SGIX_framezoom()
{
	int numFailed = 0;
	_ptrc_glFrameZoomSGIX = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glFrameZoomSGIX");
	if(!_ptrc_glFrameZoomSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glIglooInterfaceSGIX)(GLenum, const GLvoid *) = NULL;

static int Load_SGIX_igloo_interface()
{
	int numFailed = 0;
	_ptrc_glIglooInterfaceSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid *))IntGetProcAddress("glIglooInterfaceSGIX");
	if(!_ptrc_glIglooInterfaceSGIX) numFailed++;
	return numFailed;
}

GLint (CODEGEN_FUNCPTR *_ptrc_glGetInstrumentsSGIX)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInstrumentsBufferSGIX)(GLsizei, GLint *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glPollInstrumentsSGIX)(GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadInstrumentsSGIX)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStartInstrumentsSGIX)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStopInstrumentsSGIX)(GLint) = NULL;

static int Load_SGIX_instruments()
{
	int numFailed = 0;
	_ptrc_glGetInstrumentsSGIX = (GLint (CODEGEN_FUNCPTR *)())IntGetProcAddress("glGetInstrumentsSGIX");
	if(!_ptrc_glGetInstrumentsSGIX) numFailed++;
	_ptrc_glInstrumentsBufferSGIX = (void (CODEGEN_FUNCPTR *)(GLsizei, GLint *))IntGetProcAddress("glInstrumentsBufferSGIX");
	if(!_ptrc_glInstrumentsBufferSGIX) numFailed++;
	_ptrc_glPollInstrumentsSGIX = (GLint (CODEGEN_FUNCPTR *)(GLint *))IntGetProcAddress("glPollInstrumentsSGIX");
	if(!_ptrc_glPollInstrumentsSGIX) numFailed++;
	_ptrc_glReadInstrumentsSGIX = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glReadInstrumentsSGIX");
	if(!_ptrc_glReadInstrumentsSGIX) numFailed++;
	_ptrc_glStartInstrumentsSGIX = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glStartInstrumentsSGIX");
	if(!_ptrc_glStartInstrumentsSGIX) numFailed++;
	_ptrc_glStopInstrumentsSGIX = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glStopInstrumentsSGIX");
	if(!_ptrc_glStopInstrumentsSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGetListParameterfvSGIX)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetListParameterivSGIX)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glListParameterfSGIX)(GLuint, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glListParameterfvSGIX)(GLuint, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glListParameteriSGIX)(GLuint, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glListParameterivSGIX)(GLuint, GLenum, const GLint *) = NULL;

static int Load_SGIX_list_priority()
{
	int numFailed = 0;
	_ptrc_glGetListParameterfvSGIX = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetListParameterfvSGIX");
	if(!_ptrc_glGetListParameterfvSGIX) numFailed++;
	_ptrc_glGetListParameterivSGIX = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetListParameterivSGIX");
	if(!_ptrc_glGetListParameterivSGIX) numFailed++;
	_ptrc_glListParameterfSGIX = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glListParameterfSGIX");
	if(!_ptrc_glListParameterfSGIX) numFailed++;
	_ptrc_glListParameterfvSGIX = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glListParameterfvSGIX");
	if(!_ptrc_glListParameterfvSGIX) numFailed++;
	_ptrc_glListParameteriSGIX = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glListParameteriSGIX");
	if(!_ptrc_glListParameteriSGIX) numFailed++;
	_ptrc_glListParameterivSGIX = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glListParameterivSGIX");
	if(!_ptrc_glListParameterivSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glPixelTexGenSGIX)(GLenum) = NULL;

static int Load_SGIX_pixel_texture()
{
	int numFailed = 0;
	_ptrc_glPixelTexGenSGIX = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glPixelTexGenSGIX");
	if(!_ptrc_glPixelTexGenSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDeformSGIX)(GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeformationMap3dSGIX)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeformationMap3fSGIX)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadIdentityDeformationMapSGIX)(GLbitfield) = NULL;

static int Load_SGIX_polynomial_ffd()
{
	int numFailed = 0;
	_ptrc_glDeformSGIX = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glDeformSGIX");
	if(!_ptrc_glDeformSGIX) numFailed++;
	_ptrc_glDeformationMap3dSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *))IntGetProcAddress("glDeformationMap3dSGIX");
	if(!_ptrc_glDeformationMap3dSGIX) numFailed++;
	_ptrc_glDeformationMap3fSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *))IntGetProcAddress("glDeformationMap3fSGIX");
	if(!_ptrc_glDeformationMap3fSGIX) numFailed++;
	_ptrc_glLoadIdentityDeformationMapSGIX = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glLoadIdentityDeformationMapSGIX");
	if(!_ptrc_glLoadIdentityDeformationMapSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glReferencePlaneSGIX)(const GLdouble *) = NULL;

static int Load_SGIX_reference_plane()
{
	int numFailed = 0;
	_ptrc_glReferencePlaneSGIX = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glReferencePlaneSGIX");
	if(!_ptrc_glReferencePlaneSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameterfSGIX)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameterfvSGIX)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameteriSGIX)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSpriteParameterivSGIX)(GLenum, const GLint *) = NULL;

static int Load_SGIX_sprite()
{
	int numFailed = 0;
	_ptrc_glSpriteParameterfSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glSpriteParameterfSGIX");
	if(!_ptrc_glSpriteParameterfSGIX) numFailed++;
	_ptrc_glSpriteParameterfvSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glSpriteParameterfvSGIX");
	if(!_ptrc_glSpriteParameterfvSGIX) numFailed++;
	_ptrc_glSpriteParameteriSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glSpriteParameteriSGIX");
	if(!_ptrc_glSpriteParameteriSGIX) numFailed++;
	_ptrc_glSpriteParameterivSGIX = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glSpriteParameterivSGIX");
	if(!_ptrc_glSpriteParameterivSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glTagSampleBufferSGIX)() = NULL;

static int Load_SGIX_tag_sample_buffer()
{
	int numFailed = 0;
	_ptrc_glTagSampleBufferSGIX = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glTagSampleBufferSGIX");
	if(!_ptrc_glTagSampleBufferSGIX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterfvSGI)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTableParameterivSGI)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorTableSGI)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyColorTableSGI)(GLenum, GLenum, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterfvSGI)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableParameterivSGI)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetColorTableSGI)(GLenum, GLenum, GLenum, GLvoid *) = NULL;

static int Load_SGI_color_table()
{
	int numFailed = 0;
	_ptrc_glColorTableParameterfvSGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glColorTableParameterfvSGI");
	if(!_ptrc_glColorTableParameterfvSGI) numFailed++;
	_ptrc_glColorTableParameterivSGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glColorTableParameterivSGI");
	if(!_ptrc_glColorTableParameterivSGI) numFailed++;
	_ptrc_glColorTableSGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glColorTableSGI");
	if(!_ptrc_glColorTableSGI) numFailed++;
	_ptrc_glCopyColorTableSGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLint, GLsizei))IntGetProcAddress("glCopyColorTableSGI");
	if(!_ptrc_glCopyColorTableSGI) numFailed++;
	_ptrc_glGetColorTableParameterfvSGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetColorTableParameterfvSGI");
	if(!_ptrc_glGetColorTableParameterfvSGI) numFailed++;
	_ptrc_glGetColorTableParameterivSGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetColorTableParameterivSGI");
	if(!_ptrc_glGetColorTableParameterivSGI) numFailed++;
	_ptrc_glGetColorTableSGI = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetColorTableSGI");
	if(!_ptrc_glGetColorTableSGI) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glFinishTextureSUNX)() = NULL;

static int Load_SUNX_constant_data()
{
	int numFailed = 0;
	_ptrc_glFinishTextureSUNX = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glFinishTextureSUNX");
	if(!_ptrc_glFinishTextureSUNX) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorbSUN)(GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactordSUN)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorfSUN)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactoriSUN)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorsSUN)(GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorubSUN)(GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactoruiSUN)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGlobalAlphaFactorusSUN)(GLushort) = NULL;

static int Load_SUN_global_alpha()
{
	int numFailed = 0;
	_ptrc_glGlobalAlphaFactorbSUN = (void (CODEGEN_FUNCPTR *)(GLbyte))IntGetProcAddress("glGlobalAlphaFactorbSUN");
	if(!_ptrc_glGlobalAlphaFactorbSUN) numFailed++;
	_ptrc_glGlobalAlphaFactordSUN = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glGlobalAlphaFactordSUN");
	if(!_ptrc_glGlobalAlphaFactordSUN) numFailed++;
	_ptrc_glGlobalAlphaFactorfSUN = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glGlobalAlphaFactorfSUN");
	if(!_ptrc_glGlobalAlphaFactorfSUN) numFailed++;
	_ptrc_glGlobalAlphaFactoriSUN = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glGlobalAlphaFactoriSUN");
	if(!_ptrc_glGlobalAlphaFactoriSUN) numFailed++;
	_ptrc_glGlobalAlphaFactorsSUN = (void (CODEGEN_FUNCPTR *)(GLshort))IntGetProcAddress("glGlobalAlphaFactorsSUN");
	if(!_ptrc_glGlobalAlphaFactorsSUN) numFailed++;
	_ptrc_glGlobalAlphaFactorubSUN = (void (CODEGEN_FUNCPTR *)(GLubyte))IntGetProcAddress("glGlobalAlphaFactorubSUN");
	if(!_ptrc_glGlobalAlphaFactorubSUN) numFailed++;
	_ptrc_glGlobalAlphaFactoruiSUN = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glGlobalAlphaFactoruiSUN");
	if(!_ptrc_glGlobalAlphaFactoruiSUN) numFailed++;
	_ptrc_glGlobalAlphaFactorusSUN = (void (CODEGEN_FUNCPTR *)(GLushort))IntGetProcAddress("glGlobalAlphaFactorusSUN");
	if(!_ptrc_glGlobalAlphaFactorusSUN) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glDrawMeshArraysSUN)(GLenum, GLint, GLsizei, GLsizei) = NULL;

static int Load_SUN_mesh_array()
{
	int numFailed = 0;
	_ptrc_glDrawMeshArraysSUN = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei))IntGetProcAddress("glDrawMeshArraysSUN");
	if(!_ptrc_glDrawMeshArraysSUN) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodePointerSUN)(GLenum, GLsizei, const GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeubSUN)(GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeubvSUN)(const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiSUN)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuivSUN)(const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeusSUN)(GLushort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeusvSUN)(const GLushort *) = NULL;

static int Load_SUN_triangle_list()
{
	int numFailed = 0;
	_ptrc_glReplacementCodePointerSUN = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid **))IntGetProcAddress("glReplacementCodePointerSUN");
	if(!_ptrc_glReplacementCodePointerSUN) numFailed++;
	_ptrc_glReplacementCodeubSUN = (void (CODEGEN_FUNCPTR *)(GLubyte))IntGetProcAddress("glReplacementCodeubSUN");
	if(!_ptrc_glReplacementCodeubSUN) numFailed++;
	_ptrc_glReplacementCodeubvSUN = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glReplacementCodeubvSUN");
	if(!_ptrc_glReplacementCodeubvSUN) numFailed++;
	_ptrc_glReplacementCodeuiSUN = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glReplacementCodeuiSUN");
	if(!_ptrc_glReplacementCodeuiSUN) numFailed++;
	_ptrc_glReplacementCodeuivSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *))IntGetProcAddress("glReplacementCodeuivSUN");
	if(!_ptrc_glReplacementCodeuivSUN) numFailed++;
	_ptrc_glReplacementCodeusSUN = (void (CODEGEN_FUNCPTR *)(GLushort))IntGetProcAddress("glReplacementCodeusSUN");
	if(!_ptrc_glReplacementCodeusSUN) numFailed++;
	_ptrc_glReplacementCodeusvSUN = (void (CODEGEN_FUNCPTR *)(const GLushort *))IntGetProcAddress("glReplacementCodeusvSUN");
	if(!_ptrc_glReplacementCodeusvSUN) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glColor3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3fVertex3fvSUN)(const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4fNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4fNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex2fSUN)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex2fvSUN)(const GLubyte *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex3fSUN)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4ubVertex3fvSUN)(const GLubyte *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4ubVertex3fSUN)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiColor4ubVertex3fvSUN)(const GLuint *, const GLubyte *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiTexCoord2fVertex3fvSUN)(const GLuint *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiVertex3fSUN)(GLuint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReplacementCodeuiVertex3fvSUN)(const GLuint *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4fNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4fNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4ubVertex3fSUN)(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fColor4ubVertex3fvSUN)(const GLfloat *, const GLubyte *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fNormal3fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fNormal3fVertex3fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fVertex3fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fVertex3fvSUN)(const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fColor4fNormal3fVertex4fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fColor4fNormal3fVertex4fvSUN)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fVertex4fSUN)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fVertex4fvSUN)(const GLfloat *, const GLfloat *) = NULL;

static int Load_SUN_vertex()
{
	int numFailed = 0;
	_ptrc_glColor3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glColor3fVertex3fSUN");
	if(!_ptrc_glColor3fVertex3fSUN) numFailed++;
	_ptrc_glColor3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *))IntGetProcAddress("glColor3fVertex3fvSUN");
	if(!_ptrc_glColor3fVertex3fvSUN) numFailed++;
	_ptrc_glColor4fNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glColor4fNormal3fVertex3fSUN");
	if(!_ptrc_glColor4fNormal3fVertex3fSUN) numFailed++;
	_ptrc_glColor4fNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glColor4fNormal3fVertex3fvSUN");
	if(!_ptrc_glColor4fNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glColor4ubVertex2fSUN = (void (CODEGEN_FUNCPTR *)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat))IntGetProcAddress("glColor4ubVertex2fSUN");
	if(!_ptrc_glColor4ubVertex2fSUN) numFailed++;
	_ptrc_glColor4ubVertex2fvSUN = (void (CODEGEN_FUNCPTR *)(const GLubyte *, const GLfloat *))IntGetProcAddress("glColor4ubVertex2fvSUN");
	if(!_ptrc_glColor4ubVertex2fvSUN) numFailed++;
	_ptrc_glColor4ubVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glColor4ubVertex3fSUN");
	if(!_ptrc_glColor4ubVertex3fSUN) numFailed++;
	_ptrc_glColor4ubVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLubyte *, const GLfloat *))IntGetProcAddress("glColor4ubVertex3fvSUN");
	if(!_ptrc_glColor4ubVertex3fvSUN) numFailed++;
	_ptrc_glNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glNormal3fVertex3fSUN");
	if(!_ptrc_glNormal3fVertex3fSUN) numFailed++;
	_ptrc_glNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *))IntGetProcAddress("glNormal3fVertex3fvSUN");
	if(!_ptrc_glNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiColor3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiColor3fVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiColor3fVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiColor3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLfloat *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiColor3fVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiColor3fVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiColor4fNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiColor4ubVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiColor4ubVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiColor4ubVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiColor4ubVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLubyte *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiColor4ubVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiColor4ubVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiNormal3fVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiNormal3fVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLfloat *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiNormal3fVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiTexCoord2fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiTexCoord2fVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiTexCoord2fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLfloat *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiTexCoord2fVertex3fvSUN) numFailed++;
	_ptrc_glReplacementCodeuiVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glReplacementCodeuiVertex3fSUN");
	if(!_ptrc_glReplacementCodeuiVertex3fSUN) numFailed++;
	_ptrc_glReplacementCodeuiVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLuint *, const GLfloat *))IntGetProcAddress("glReplacementCodeuiVertex3fvSUN");
	if(!_ptrc_glReplacementCodeuiVertex3fvSUN) numFailed++;
	_ptrc_glTexCoord2fColor3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord2fColor3fVertex3fSUN");
	if(!_ptrc_glTexCoord2fColor3fVertex3fSUN) numFailed++;
	_ptrc_glTexCoord2fColor3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glTexCoord2fColor3fVertex3fvSUN");
	if(!_ptrc_glTexCoord2fColor3fVertex3fvSUN) numFailed++;
	_ptrc_glTexCoord2fColor4fNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fSUN");
	if(!_ptrc_glTexCoord2fColor4fNormal3fVertex3fSUN) numFailed++;
	_ptrc_glTexCoord2fColor4fNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fvSUN");
	if(!_ptrc_glTexCoord2fColor4fNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glTexCoord2fColor4ubVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord2fColor4ubVertex3fSUN");
	if(!_ptrc_glTexCoord2fColor4ubVertex3fSUN) numFailed++;
	_ptrc_glTexCoord2fColor4ubVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLubyte *, const GLfloat *))IntGetProcAddress("glTexCoord2fColor4ubVertex3fvSUN");
	if(!_ptrc_glTexCoord2fColor4ubVertex3fvSUN) numFailed++;
	_ptrc_glTexCoord2fNormal3fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord2fNormal3fVertex3fSUN");
	if(!_ptrc_glTexCoord2fNormal3fVertex3fSUN) numFailed++;
	_ptrc_glTexCoord2fNormal3fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glTexCoord2fNormal3fVertex3fvSUN");
	if(!_ptrc_glTexCoord2fNormal3fVertex3fvSUN) numFailed++;
	_ptrc_glTexCoord2fVertex3fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord2fVertex3fSUN");
	if(!_ptrc_glTexCoord2fVertex3fSUN) numFailed++;
	_ptrc_glTexCoord2fVertex3fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *))IntGetProcAddress("glTexCoord2fVertex3fvSUN");
	if(!_ptrc_glTexCoord2fVertex3fvSUN) numFailed++;
	_ptrc_glTexCoord4fColor4fNormal3fVertex4fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fSUN");
	if(!_ptrc_glTexCoord4fColor4fNormal3fVertex4fSUN) numFailed++;
	_ptrc_glTexCoord4fColor4fNormal3fVertex4fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *))IntGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fvSUN");
	if(!_ptrc_glTexCoord4fColor4fNormal3fVertex4fvSUN) numFailed++;
	_ptrc_glTexCoord4fVertex4fSUN = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord4fVertex4fSUN");
	if(!_ptrc_glTexCoord4fVertex4fSUN) numFailed++;
	_ptrc_glTexCoord4fVertex4fvSUN = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *))IntGetProcAddress("glTexCoord4fVertex4fvSUN");
	if(!_ptrc_glTexCoord4fVertex4fvSUN) numFailed++;
	return numFailed;
}

void (CODEGEN_FUNCPTR *_ptrc_glAccum)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glAlphaFunc)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBegin)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBitmap)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFunc)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCallList)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCallLists)(GLsizei, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClear)(GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearAccum)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearColor)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearDepth)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearIndex)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearStencil)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClipPlane)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3b)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3bv)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3d)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3f)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3s)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3ub)(GLubyte, GLubyte, GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3ubv)(const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3ui)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3uiv)(const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3us)(GLushort, GLushort, GLushort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor3usv)(const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4b)(GLbyte, GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4bv)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4d)(GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4f)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4i)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4s)(GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4ub)(GLubyte, GLubyte, GLubyte, GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4ubv)(const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4ui)(GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4uiv)(const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4us)(GLushort, GLushort, GLushort, GLushort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColor4usv)(const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorMask)(GLboolean, GLboolean, GLboolean, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorMaterial)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyPixels)(GLint, GLint, GLsizei, GLsizei, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCullFace)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteLists)(GLuint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthFunc)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthMask)(GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDepthRange)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisable)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffer)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawPixels)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlag)(GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagv)(const GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnable)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnd)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndList)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1d)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1f)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord1fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2d)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2f)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalCoord2fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalMesh1)(GLenum, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalMesh2)(GLenum, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalPoint1)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEvalPoint2)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFeedbackBuffer)(GLsizei, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFinish)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFlush)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogf)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogfv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogi)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogiv)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFrontFace)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFrustum)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glGenLists)(GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBooleanv)(GLenum, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetClipPlane)(GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetDoublev)(GLenum, GLdouble *) = NULL;
GLenum (CODEGEN_FUNCPTR *_ptrc_glGetError)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetFloatv)(GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegerv)(GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetLightfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetLightiv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapdv)(GLenum, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMapiv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMaterialfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetMaterialiv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapfv)(GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapuiv)(GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPixelMapusv)(GLenum, GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetPolygonStipple)(GLubyte *) = NULL;
const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetString)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexEnvfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexEnviv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexGendv)(GLenum, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexGenfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexGeniv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexImage)(GLenum, GLint, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameterfv)(GLenum, GLint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexLevelParameteriv)(GLenum, GLint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterfv)(GLenum, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameteriv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glHint)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexMask)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexd)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexdv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexf)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexfv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexi)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexiv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexs)(GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexsv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInitNames)() = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabled)(GLenum) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsList)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightModelf)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightModelfv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightModeli)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightModeliv)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightf)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightfv)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLighti)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLightiv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLineStipple)(GLint, GLushort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLineWidth)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glListBase)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadIdentity)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadMatrixd)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadMatrixf)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadName)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLogicOp)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMap1d)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMap1f)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMap2d)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMap2f)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapGrid1d)(GLint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapGrid1f)(GLint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapGrid2d)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMapGrid2f)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMaterialf)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMaterialfv)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMateriali)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMaterialiv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMatrixMode)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultMatrixd)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultMatrixf)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNewList)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3b)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3bv)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3d)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3f)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3s)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormal3sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glOrtho)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPassThrough)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelMapfv)(GLenum, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelMapuiv)(GLenum, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelMapusv)(GLenum, GLsizei, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelStoref)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelStorei)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTransferf)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelTransferi)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPixelZoom)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointSize)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPolygonMode)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPolygonStipple)(const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPopAttrib)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPopMatrix)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPopName)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushAttrib)(GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushMatrix)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushName)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2d)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2f)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2i)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2s)(GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos2sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3d)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3f)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3s)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos3sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4d)(GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4f)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4i)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4s)(GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRasterPos4sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadBuffer)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectd)(GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectdv)(const GLdouble *, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectf)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectfv)(const GLfloat *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRecti)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectiv)(const GLint *, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRects)(GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRectsv)(const GLshort *, const GLshort *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glRenderMode)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRotated)(GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glRotatef)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScaled)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScalef)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glScissor)(GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSelectBuffer)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShadeModel)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFunc)(GLenum, GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilMask)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilOp)(GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1d)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1f)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1i)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1s)(GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord1sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2d)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2f)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2i)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2s)(GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord2sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3d)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3f)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3s)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord3sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4d)(GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4f)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4i)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4s)(GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoord4sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexEnvf)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexEnvfv)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexEnvi)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexEnviv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGend)(GLenum, GLenum, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGendv)(GLenum, GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGenf)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGenfv)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGeni)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexGeniv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage1D)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterf)(GLenum, GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterfv)(GLenum, GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameteri)(GLenum, GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameteriv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTranslated)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTranslatef)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2d)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2f)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2i)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2s)(GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex2sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3d)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3f)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3s)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex3sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4d)(GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4f)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4i)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4s)(GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertex4sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glViewport)(GLint, GLint, GLsizei, GLsizei) = NULL;

GLboolean (CODEGEN_FUNCPTR *_ptrc_glAreTexturesResident)(GLsizei, const GLuint *, GLboolean *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glArrayElement)(GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindTexture)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorPointer)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage1D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexImage2D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage1D)(GLenum, GLint, GLint, GLint, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteTextures)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableClientState)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawArrays)(GLenum, GLint, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElements)(GLenum, GLsizei, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEdgeFlagPointer)(GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableClientState)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenTextures)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexPointer)(GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexub)(GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glIndexubv)(const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glInterleavedArrays)(GLenum, GLsizei, const GLvoid *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsTexture)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glNormalPointer)(GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPolygonOffset)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPopClientAttrib)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrioritizeTextures)(GLsizei, const GLuint *, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPushClientAttrib)(GLbitfield) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexCoordPointer)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexPointer)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBlendColor)(GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquation)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCopyTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawRangeElements)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexImage3D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glActiveTexture)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClientActiveTexture)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage1D)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage2D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexImage3D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompressedTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetCompressedTexImage)(GLenum, GLint, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixd)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLoadTransposeMatrixf)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixd)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultTransposeMatrixf)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1d)(GLenum, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1dv)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1f)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1fv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1i)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1iv)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1s)(GLenum, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord1sv)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2d)(GLenum, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2dv)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2f)(GLenum, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2fv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2i)(GLenum, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2iv)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2s)(GLenum, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord2sv)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3d)(GLenum, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3dv)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3f)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3fv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3i)(GLenum, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3iv)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3s)(GLenum, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord3sv)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4d)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4dv)(GLenum, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4f)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4fv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4i)(GLenum, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4iv)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4s)(GLenum, GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiTexCoord4sv)(GLenum, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSampleCoverage)(GLfloat, GLboolean) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordPointer)(GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordd)(GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoorddv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordf)(GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glFogCoordfv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawArrays)(GLenum, const GLint *, const GLsizei *, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMultiDrawElements)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterf)(GLenum, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameterfv)(GLenum, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameteri)(GLenum, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPointParameteriv)(GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3b)(GLbyte, GLbyte, GLbyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3bv)(const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3d)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3f)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3s)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ub)(GLubyte, GLubyte, GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ubv)(const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3ui)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3uiv)(const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3us)(GLushort, GLushort, GLushort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColor3usv)(const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glSecondaryColorPointer)(GLint, GLenum, GLsizei, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2d)(GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2f)(GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2i)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2s)(GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos2sv)(const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3d)(GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3dv)(const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3f)(GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3fv)(const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3iv)(const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3s)(GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glWindowPos3sv)(const GLshort *) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBeginQuery)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBuffer)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferData)(GLenum, GLsizeiptr, const GLvoid *, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBufferSubData)(GLenum, GLintptr, GLsizeiptr, const GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteBuffers)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteQueries)(GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndQuery)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenBuffers)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGenQueries)(GLsizei, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteriv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferPointerv)(GLenum, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferSubData)(GLenum, GLintptr, GLsizeiptr, GLvoid *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectiv)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryObjectuiv)(GLuint, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetQueryiv)(GLenum, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsBuffer)(GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsQuery)(GLuint) = NULL;
void * (CODEGEN_FUNCPTR *_ptrc_glMapBuffer)(GLenum, GLenum) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glUnmapBuffer)(GLenum) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glAttachShader)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindAttribLocation)(GLuint, GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparate)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glCompileShader)(GLuint) = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateProgram)() = NULL;
GLuint (CODEGEN_FUNCPTR *_ptrc_glCreateShader)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteProgram)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDeleteShader)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDetachShader)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisableVertexAttribArray)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawBuffers)(GLsizei, const GLenum *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnableVertexAttribArray)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveAttrib)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetActiveUniform)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetAttachedShaders)(GLuint, GLsizei, GLsizei *, GLuint *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetAttribLocation)(GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetProgramiv)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderSource)(GLuint, GLsizei, GLsizei *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetShaderiv)(GLuint, GLenum, GLint *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetUniformLocation)(GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformfv)(GLuint, GLint, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformiv)(GLuint, GLint, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribPointerv)(GLuint, GLenum, GLvoid **) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribdv)(GLuint, GLenum, GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribfv)(GLuint, GLenum, GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribiv)(GLuint, GLenum, GLint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsProgram)(GLuint) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsShader)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glLinkProgram)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glShaderSource)(GLuint, GLsizei, const GLchar *const*, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilFuncSeparate)(GLenum, GLenum, GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilMaskSeparate)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glStencilOpSeparate)(GLenum, GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1f)(GLint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1fv)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1i)(GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1iv)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2f)(GLint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2fv)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2i)(GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2iv)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3f)(GLint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3fv)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3i)(GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3iv)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4fv)(GLint, GLsizei, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4i)(GLint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4iv)(GLint, GLsizei, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUseProgram)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glValidateProgram)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1d)(GLuint, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1f)(GLuint, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1fv)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1s)(GLuint, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib1sv)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2d)(GLuint, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2f)(GLuint, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2fv)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2s)(GLuint, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib2sv)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3d)(GLuint, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3f)(GLuint, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3fv)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3s)(GLuint, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib3sv)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nbv)(GLuint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Niv)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nsv)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nub)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nubv)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nuiv)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4Nusv)(GLuint, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4bv)(GLuint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4dv)(GLuint, const GLdouble *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4f)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4fv)(GLuint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4iv)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4s)(GLuint, GLshort, GLshort, GLshort, GLshort) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4sv)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4ubv)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4uiv)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttrib4usv)(GLuint, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x3fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix2x4fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x2fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix3x4fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x2fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniformMatrix4x3fv)(GLint, GLsizei, GLboolean, const GLfloat *) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBeginConditionalRender)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBeginTransformFeedback)(GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferBase)(GLenum, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindBufferRange)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBindFragDataLocation)(GLuint, GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClampColor)(GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfi)(GLenum, GLint, GLfloat, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferfv)(GLenum, GLint, const GLfloat *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferiv)(GLenum, GLint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glClearBufferuiv)(GLenum, GLint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glColorMaski)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDisablei)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEnablei)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndConditionalRender)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glEndTransformFeedback)() = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBooleani_v)(GLenum, GLuint, GLboolean *) = NULL;
GLint (CODEGEN_FUNCPTR *_ptrc_glGetFragDataLocation)(GLuint, const GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetIntegeri_v)(GLenum, GLuint, GLint *) = NULL;
const GLubyte * (CODEGEN_FUNCPTR *_ptrc_glGetStringi)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIiv)(GLenum, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTexParameterIuiv)(GLenum, GLenum, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetTransformFeedbackVarying)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetUniformuiv)(GLuint, GLint, GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIiv)(GLuint, GLenum, GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetVertexAttribIuiv)(GLuint, GLenum, GLuint *) = NULL;
GLboolean (CODEGEN_FUNCPTR *_ptrc_glIsEnabledi)(GLenum, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIiv)(GLenum, GLenum, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexParameterIuiv)(GLenum, GLenum, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTransformFeedbackVaryings)(GLuint, GLsizei, const GLchar *const*, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1ui)(GLint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform1uiv)(GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2ui)(GLint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform2uiv)(GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3ui)(GLint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform3uiv)(GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4ui)(GLint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glUniform4uiv)(GLint, GLsizei, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1i)(GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1iv)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1ui)(GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI1uiv)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2i)(GLuint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2iv)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2ui)(GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI2uiv)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3i)(GLuint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3iv)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3ui)(GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI3uiv)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4bv)(GLuint, const GLbyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4i)(GLuint, GLint, GLint, GLint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4iv)(GLuint, const GLint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4sv)(GLuint, const GLshort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ubv)(GLuint, const GLubyte *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4ui)(GLuint, GLuint, GLuint, GLuint, GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4uiv)(GLuint, const GLuint *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribI4usv)(GLuint, const GLushort *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribIPointer)(GLuint, GLint, GLenum, GLsizei, const GLvoid *) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glDrawArraysInstanced)(GLenum, GLint, GLsizei, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glDrawElementsInstanced)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glPrimitiveRestartIndex)(GLuint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glTexBuffer)(GLenum, GLenum, GLuint) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glFramebufferTexture)(GLenum, GLenum, GLuint, GLint) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetBufferParameteri64v)(GLenum, GLenum, GLint64 *) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glGetInteger64i_v)(GLenum, GLuint, GLint64 *) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glVertexAttribDivisor)(GLuint, GLuint) = NULL;

void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationSeparatei)(GLuint, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendEquationi)(GLuint, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFuncSeparatei)(GLuint, GLenum, GLenum, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glBlendFunci)(GLuint, GLenum, GLenum) = NULL;
void (CODEGEN_FUNCPTR *_ptrc_glMinSampleShading)(GLfloat) = NULL;





static int Load_Version_4_4()
{
	int numFailed = 0;
	_ptrc_glAccum = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glAccum");
	if(!_ptrc_glAccum) numFailed++;
	_ptrc_glAlphaFunc = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glAlphaFunc");
	if(!_ptrc_glAlphaFunc) numFailed++;
	_ptrc_glBegin = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBegin");
	if(!_ptrc_glBegin) numFailed++;
	_ptrc_glBitmap = (void (CODEGEN_FUNCPTR *)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *))IntGetProcAddress("glBitmap");
	if(!_ptrc_glBitmap) numFailed++;
	_ptrc_glBlendFunc = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBlendFunc");
	if(!_ptrc_glBlendFunc) numFailed++;
	_ptrc_glCallList = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glCallList");
	if(!_ptrc_glCallList) numFailed++;
	_ptrc_glCallLists = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glCallLists");
	if(!_ptrc_glCallLists) numFailed++;
	_ptrc_glClear = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glClear");
	if(!_ptrc_glClear) numFailed++;
	_ptrc_glClearAccum = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glClearAccum");
	if(!_ptrc_glClearAccum) numFailed++;
	_ptrc_glClearColor = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glClearColor");
	if(!_ptrc_glClearColor) numFailed++;
	_ptrc_glClearDepth = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glClearDepth");
	if(!_ptrc_glClearDepth) numFailed++;
	_ptrc_glClearIndex = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glClearIndex");
	if(!_ptrc_glClearIndex) numFailed++;
	_ptrc_glClearStencil = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glClearStencil");
	if(!_ptrc_glClearStencil) numFailed++;
	_ptrc_glClipPlane = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glClipPlane");
	if(!_ptrc_glClipPlane) numFailed++;
	_ptrc_glColor3b = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glColor3b");
	if(!_ptrc_glColor3b) numFailed++;
	_ptrc_glColor3bv = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glColor3bv");
	if(!_ptrc_glColor3bv) numFailed++;
	_ptrc_glColor3d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glColor3d");
	if(!_ptrc_glColor3d) numFailed++;
	_ptrc_glColor3dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glColor3dv");
	if(!_ptrc_glColor3dv) numFailed++;
	_ptrc_glColor3f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glColor3f");
	if(!_ptrc_glColor3f) numFailed++;
	_ptrc_glColor3fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glColor3fv");
	if(!_ptrc_glColor3fv) numFailed++;
	_ptrc_glColor3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glColor3i");
	if(!_ptrc_glColor3i) numFailed++;
	_ptrc_glColor3iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glColor3iv");
	if(!_ptrc_glColor3iv) numFailed++;
	_ptrc_glColor3s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glColor3s");
	if(!_ptrc_glColor3s) numFailed++;
	_ptrc_glColor3sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glColor3sv");
	if(!_ptrc_glColor3sv) numFailed++;
	_ptrc_glColor3ub = (void (CODEGEN_FUNCPTR *)(GLubyte, GLubyte, GLubyte))IntGetProcAddress("glColor3ub");
	if(!_ptrc_glColor3ub) numFailed++;
	_ptrc_glColor3ubv = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glColor3ubv");
	if(!_ptrc_glColor3ubv) numFailed++;
	_ptrc_glColor3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glColor3ui");
	if(!_ptrc_glColor3ui) numFailed++;
	_ptrc_glColor3uiv = (void (CODEGEN_FUNCPTR *)(const GLuint *))IntGetProcAddress("glColor3uiv");
	if(!_ptrc_glColor3uiv) numFailed++;
	_ptrc_glColor3us = (void (CODEGEN_FUNCPTR *)(GLushort, GLushort, GLushort))IntGetProcAddress("glColor3us");
	if(!_ptrc_glColor3us) numFailed++;
	_ptrc_glColor3usv = (void (CODEGEN_FUNCPTR *)(const GLushort *))IntGetProcAddress("glColor3usv");
	if(!_ptrc_glColor3usv) numFailed++;
	_ptrc_glColor4b = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte, GLbyte))IntGetProcAddress("glColor4b");
	if(!_ptrc_glColor4b) numFailed++;
	_ptrc_glColor4bv = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glColor4bv");
	if(!_ptrc_glColor4bv) numFailed++;
	_ptrc_glColor4d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glColor4d");
	if(!_ptrc_glColor4d) numFailed++;
	_ptrc_glColor4dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glColor4dv");
	if(!_ptrc_glColor4dv) numFailed++;
	_ptrc_glColor4f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glColor4f");
	if(!_ptrc_glColor4f) numFailed++;
	_ptrc_glColor4fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glColor4fv");
	if(!_ptrc_glColor4fv) numFailed++;
	_ptrc_glColor4i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glColor4i");
	if(!_ptrc_glColor4i) numFailed++;
	_ptrc_glColor4iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glColor4iv");
	if(!_ptrc_glColor4iv) numFailed++;
	_ptrc_glColor4s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glColor4s");
	if(!_ptrc_glColor4s) numFailed++;
	_ptrc_glColor4sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glColor4sv");
	if(!_ptrc_glColor4sv) numFailed++;
	_ptrc_glColor4ub = (void (CODEGEN_FUNCPTR *)(GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glColor4ub");
	if(!_ptrc_glColor4ub) numFailed++;
	_ptrc_glColor4ubv = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glColor4ubv");
	if(!_ptrc_glColor4ubv) numFailed++;
	_ptrc_glColor4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glColor4ui");
	if(!_ptrc_glColor4ui) numFailed++;
	_ptrc_glColor4uiv = (void (CODEGEN_FUNCPTR *)(const GLuint *))IntGetProcAddress("glColor4uiv");
	if(!_ptrc_glColor4uiv) numFailed++;
	_ptrc_glColor4us = (void (CODEGEN_FUNCPTR *)(GLushort, GLushort, GLushort, GLushort))IntGetProcAddress("glColor4us");
	if(!_ptrc_glColor4us) numFailed++;
	_ptrc_glColor4usv = (void (CODEGEN_FUNCPTR *)(const GLushort *))IntGetProcAddress("glColor4usv");
	if(!_ptrc_glColor4usv) numFailed++;
	_ptrc_glColorMask = (void (CODEGEN_FUNCPTR *)(GLboolean, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glColorMask");
	if(!_ptrc_glColorMask) numFailed++;
	_ptrc_glColorMaterial = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glColorMaterial");
	if(!_ptrc_glColorMaterial) numFailed++;
	_ptrc_glCopyPixels = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei, GLenum))IntGetProcAddress("glCopyPixels");
	if(!_ptrc_glCopyPixels) numFailed++;
	_ptrc_glCullFace = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCullFace");
	if(!_ptrc_glCullFace) numFailed++;
	_ptrc_glDeleteLists = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei))IntGetProcAddress("glDeleteLists");
	if(!_ptrc_glDeleteLists) numFailed++;
	_ptrc_glDepthFunc = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glDepthFunc");
	if(!_ptrc_glDepthFunc) numFailed++;
	_ptrc_glDepthMask = (void (CODEGEN_FUNCPTR *)(GLboolean))IntGetProcAddress("glDepthMask");
	if(!_ptrc_glDepthMask) numFailed++;
	_ptrc_glDepthRange = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glDepthRange");
	if(!_ptrc_glDepthRange) numFailed++;
	_ptrc_glDisable = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glDisable");
	if(!_ptrc_glDisable) numFailed++;
	_ptrc_glDrawBuffer = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glDrawBuffer");
	if(!_ptrc_glDrawBuffer) numFailed++;
	_ptrc_glDrawPixels = (void (CODEGEN_FUNCPTR *)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glDrawPixels");
	if(!_ptrc_glDrawPixels) numFailed++;
	_ptrc_glEdgeFlag = (void (CODEGEN_FUNCPTR *)(GLboolean))IntGetProcAddress("glEdgeFlag");
	if(!_ptrc_glEdgeFlag) numFailed++;
	_ptrc_glEdgeFlagv = (void (CODEGEN_FUNCPTR *)(const GLboolean *))IntGetProcAddress("glEdgeFlagv");
	if(!_ptrc_glEdgeFlagv) numFailed++;
	_ptrc_glEnable = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glEnable");
	if(!_ptrc_glEnable) numFailed++;
	_ptrc_glEnd = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEnd");
	if(!_ptrc_glEnd) numFailed++;
	_ptrc_glEndList = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndList");
	if(!_ptrc_glEndList) numFailed++;
	_ptrc_glEvalCoord1d = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glEvalCoord1d");
	if(!_ptrc_glEvalCoord1d) numFailed++;
	_ptrc_glEvalCoord1dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glEvalCoord1dv");
	if(!_ptrc_glEvalCoord1dv) numFailed++;
	_ptrc_glEvalCoord1f = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glEvalCoord1f");
	if(!_ptrc_glEvalCoord1f) numFailed++;
	_ptrc_glEvalCoord1fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glEvalCoord1fv");
	if(!_ptrc_glEvalCoord1fv) numFailed++;
	_ptrc_glEvalCoord2d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glEvalCoord2d");
	if(!_ptrc_glEvalCoord2d) numFailed++;
	_ptrc_glEvalCoord2dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glEvalCoord2dv");
	if(!_ptrc_glEvalCoord2dv) numFailed++;
	_ptrc_glEvalCoord2f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glEvalCoord2f");
	if(!_ptrc_glEvalCoord2f) numFailed++;
	_ptrc_glEvalCoord2fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glEvalCoord2fv");
	if(!_ptrc_glEvalCoord2fv) numFailed++;
	_ptrc_glEvalMesh1 = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint))IntGetProcAddress("glEvalMesh1");
	if(!_ptrc_glEvalMesh1) numFailed++;
	_ptrc_glEvalMesh2 = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint))IntGetProcAddress("glEvalMesh2");
	if(!_ptrc_glEvalMesh2) numFailed++;
	_ptrc_glEvalPoint1 = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glEvalPoint1");
	if(!_ptrc_glEvalPoint1) numFailed++;
	_ptrc_glEvalPoint2 = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glEvalPoint2");
	if(!_ptrc_glEvalPoint2) numFailed++;
	_ptrc_glFeedbackBuffer = (void (CODEGEN_FUNCPTR *)(GLsizei, GLenum, GLfloat *))IntGetProcAddress("glFeedbackBuffer");
	if(!_ptrc_glFeedbackBuffer) numFailed++;
	_ptrc_glFinish = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glFinish");
	if(!_ptrc_glFinish) numFailed++;
	_ptrc_glFlush = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glFlush");
	if(!_ptrc_glFlush) numFailed++;
	_ptrc_glFogf = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glFogf");
	if(!_ptrc_glFogf) numFailed++;
	_ptrc_glFogfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glFogfv");
	if(!_ptrc_glFogfv) numFailed++;
	_ptrc_glFogi = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glFogi");
	if(!_ptrc_glFogi) numFailed++;
	_ptrc_glFogiv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glFogiv");
	if(!_ptrc_glFogiv) numFailed++;
	_ptrc_glFrontFace = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glFrontFace");
	if(!_ptrc_glFrontFace) numFailed++;
	_ptrc_glFrustum = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glFrustum");
	if(!_ptrc_glFrustum) numFailed++;
	_ptrc_glGenLists = (GLuint (CODEGEN_FUNCPTR *)(GLsizei))IntGetProcAddress("glGenLists");
	if(!_ptrc_glGenLists) numFailed++;
	_ptrc_glGetBooleanv = (void (CODEGEN_FUNCPTR *)(GLenum, GLboolean *))IntGetProcAddress("glGetBooleanv");
	if(!_ptrc_glGetBooleanv) numFailed++;
	_ptrc_glGetClipPlane = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble *))IntGetProcAddress("glGetClipPlane");
	if(!_ptrc_glGetClipPlane) numFailed++;
	_ptrc_glGetDoublev = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble *))IntGetProcAddress("glGetDoublev");
	if(!_ptrc_glGetDoublev) numFailed++;
	_ptrc_glGetError = (GLenum (CODEGEN_FUNCPTR *)())IntGetProcAddress("glGetError");
	if(!_ptrc_glGetError) numFailed++;
	_ptrc_glGetFloatv = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetFloatv");
	if(!_ptrc_glGetFloatv) numFailed++;
	_ptrc_glGetIntegerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint *))IntGetProcAddress("glGetIntegerv");
	if(!_ptrc_glGetIntegerv) numFailed++;
	_ptrc_glGetLightfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetLightfv");
	if(!_ptrc_glGetLightfv) numFailed++;
	_ptrc_glGetLightiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetLightiv");
	if(!_ptrc_glGetLightiv) numFailed++;
	_ptrc_glGetMapdv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLdouble *))IntGetProcAddress("glGetMapdv");
	if(!_ptrc_glGetMapdv) numFailed++;
	_ptrc_glGetMapfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMapfv");
	if(!_ptrc_glGetMapfv) numFailed++;
	_ptrc_glGetMapiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetMapiv");
	if(!_ptrc_glGetMapiv) numFailed++;
	_ptrc_glGetMaterialfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetMaterialfv");
	if(!_ptrc_glGetMaterialfv) numFailed++;
	_ptrc_glGetMaterialiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetMaterialiv");
	if(!_ptrc_glGetMaterialiv) numFailed++;
	_ptrc_glGetPixelMapfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat *))IntGetProcAddress("glGetPixelMapfv");
	if(!_ptrc_glGetPixelMapfv) numFailed++;
	_ptrc_glGetPixelMapuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint *))IntGetProcAddress("glGetPixelMapuiv");
	if(!_ptrc_glGetPixelMapuiv) numFailed++;
	_ptrc_glGetPixelMapusv = (void (CODEGEN_FUNCPTR *)(GLenum, GLushort *))IntGetProcAddress("glGetPixelMapusv");
	if(!_ptrc_glGetPixelMapusv) numFailed++;
	_ptrc_glGetPolygonStipple = (void (CODEGEN_FUNCPTR *)(GLubyte *))IntGetProcAddress("glGetPolygonStipple");
	if(!_ptrc_glGetPolygonStipple) numFailed++;
	_ptrc_glGetString = (const GLubyte * (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGetString");
	if(!_ptrc_glGetString) numFailed++;
	_ptrc_glGetTexEnvfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetTexEnvfv");
	if(!_ptrc_glGetTexEnvfv) numFailed++;
	_ptrc_glGetTexEnviv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexEnviv");
	if(!_ptrc_glGetTexEnviv) numFailed++;
	_ptrc_glGetTexGendv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLdouble *))IntGetProcAddress("glGetTexGendv");
	if(!_ptrc_glGetTexGendv) numFailed++;
	_ptrc_glGetTexGenfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetTexGenfv");
	if(!_ptrc_glGetTexGenfv) numFailed++;
	_ptrc_glGetTexGeniv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexGeniv");
	if(!_ptrc_glGetTexGeniv) numFailed++;
	_ptrc_glGetTexImage = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLenum, GLvoid *))IntGetProcAddress("glGetTexImage");
	if(!_ptrc_glGetTexImage) numFailed++;
	_ptrc_glGetTexLevelParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLfloat *))IntGetProcAddress("glGetTexLevelParameterfv");
	if(!_ptrc_glGetTexLevelParameterfv) numFailed++;
	_ptrc_glGetTexLevelParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint *))IntGetProcAddress("glGetTexLevelParameteriv");
	if(!_ptrc_glGetTexLevelParameteriv) numFailed++;
	_ptrc_glGetTexParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat *))IntGetProcAddress("glGetTexParameterfv");
	if(!_ptrc_glGetTexParameterfv) numFailed++;
	_ptrc_glGetTexParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexParameteriv");
	if(!_ptrc_glGetTexParameteriv) numFailed++;
	_ptrc_glHint = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glHint");
	if(!_ptrc_glHint) numFailed++;
	_ptrc_glIndexMask = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIndexMask");
	if(!_ptrc_glIndexMask) numFailed++;
	_ptrc_glIndexd = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glIndexd");
	if(!_ptrc_glIndexd) numFailed++;
	_ptrc_glIndexdv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glIndexdv");
	if(!_ptrc_glIndexdv) numFailed++;
	_ptrc_glIndexf = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glIndexf");
	if(!_ptrc_glIndexf) numFailed++;
	_ptrc_glIndexfv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glIndexfv");
	if(!_ptrc_glIndexfv) numFailed++;
	_ptrc_glIndexi = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glIndexi");
	if(!_ptrc_glIndexi) numFailed++;
	_ptrc_glIndexiv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glIndexiv");
	if(!_ptrc_glIndexiv) numFailed++;
	_ptrc_glIndexs = (void (CODEGEN_FUNCPTR *)(GLshort))IntGetProcAddress("glIndexs");
	if(!_ptrc_glIndexs) numFailed++;
	_ptrc_glIndexsv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glIndexsv");
	if(!_ptrc_glIndexsv) numFailed++;
	_ptrc_glInitNames = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glInitNames");
	if(!_ptrc_glInitNames) numFailed++;
	_ptrc_glIsEnabled = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glIsEnabled");
	if(!_ptrc_glIsEnabled) numFailed++;
	_ptrc_glIsList = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsList");
	if(!_ptrc_glIsList) numFailed++;
	_ptrc_glLightModelf = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glLightModelf");
	if(!_ptrc_glLightModelf) numFailed++;
	_ptrc_glLightModelfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glLightModelfv");
	if(!_ptrc_glLightModelfv) numFailed++;
	_ptrc_glLightModeli = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glLightModeli");
	if(!_ptrc_glLightModeli) numFailed++;
	_ptrc_glLightModeliv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glLightModeliv");
	if(!_ptrc_glLightModeliv) numFailed++;
	_ptrc_glLightf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glLightf");
	if(!_ptrc_glLightf) numFailed++;
	_ptrc_glLightfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glLightfv");
	if(!_ptrc_glLightfv) numFailed++;
	_ptrc_glLighti = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glLighti");
	if(!_ptrc_glLighti) numFailed++;
	_ptrc_glLightiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glLightiv");
	if(!_ptrc_glLightiv) numFailed++;
	_ptrc_glLineStipple = (void (CODEGEN_FUNCPTR *)(GLint, GLushort))IntGetProcAddress("glLineStipple");
	if(!_ptrc_glLineStipple) numFailed++;
	_ptrc_glLineWidth = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glLineWidth");
	if(!_ptrc_glLineWidth) numFailed++;
	_ptrc_glListBase = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glListBase");
	if(!_ptrc_glListBase) numFailed++;
	_ptrc_glLoadIdentity = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glLoadIdentity");
	if(!_ptrc_glLoadIdentity) numFailed++;
	_ptrc_glLoadMatrixd = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glLoadMatrixd");
	if(!_ptrc_glLoadMatrixd) numFailed++;
	_ptrc_glLoadMatrixf = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glLoadMatrixf");
	if(!_ptrc_glLoadMatrixf) numFailed++;
	_ptrc_glLoadName = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glLoadName");
	if(!_ptrc_glLoadName) numFailed++;
	_ptrc_glLogicOp = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glLogicOp");
	if(!_ptrc_glLogicOp) numFailed++;
	_ptrc_glMap1d = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *))IntGetProcAddress("glMap1d");
	if(!_ptrc_glMap1d) numFailed++;
	_ptrc_glMap1f = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *))IntGetProcAddress("glMap1f");
	if(!_ptrc_glMap1f) numFailed++;
	_ptrc_glMap2d = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *))IntGetProcAddress("glMap2d");
	if(!_ptrc_glMap2d) numFailed++;
	_ptrc_glMap2f = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *))IntGetProcAddress("glMap2f");
	if(!_ptrc_glMap2f) numFailed++;
	_ptrc_glMapGrid1d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble))IntGetProcAddress("glMapGrid1d");
	if(!_ptrc_glMapGrid1d) numFailed++;
	_ptrc_glMapGrid1f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat))IntGetProcAddress("glMapGrid1f");
	if(!_ptrc_glMapGrid1f) numFailed++;
	_ptrc_glMapGrid2d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble))IntGetProcAddress("glMapGrid2d");
	if(!_ptrc_glMapGrid2d) numFailed++;
	_ptrc_glMapGrid2f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat))IntGetProcAddress("glMapGrid2f");
	if(!_ptrc_glMapGrid2f) numFailed++;
	_ptrc_glMaterialf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glMaterialf");
	if(!_ptrc_glMaterialf) numFailed++;
	_ptrc_glMaterialfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glMaterialfv");
	if(!_ptrc_glMaterialfv) numFailed++;
	_ptrc_glMateriali = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glMateriali");
	if(!_ptrc_glMateriali) numFailed++;
	_ptrc_glMaterialiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glMaterialiv");
	if(!_ptrc_glMaterialiv) numFailed++;
	_ptrc_glMatrixMode = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glMatrixMode");
	if(!_ptrc_glMatrixMode) numFailed++;
	_ptrc_glMultMatrixd = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glMultMatrixd");
	if(!_ptrc_glMultMatrixd) numFailed++;
	_ptrc_glMultMatrixf = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glMultMatrixf");
	if(!_ptrc_glMultMatrixf) numFailed++;
	_ptrc_glNewList = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glNewList");
	if(!_ptrc_glNewList) numFailed++;
	_ptrc_glNormal3b = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glNormal3b");
	if(!_ptrc_glNormal3b) numFailed++;
	_ptrc_glNormal3bv = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glNormal3bv");
	if(!_ptrc_glNormal3bv) numFailed++;
	_ptrc_glNormal3d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glNormal3d");
	if(!_ptrc_glNormal3d) numFailed++;
	_ptrc_glNormal3dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glNormal3dv");
	if(!_ptrc_glNormal3dv) numFailed++;
	_ptrc_glNormal3f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glNormal3f");
	if(!_ptrc_glNormal3f) numFailed++;
	_ptrc_glNormal3fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glNormal3fv");
	if(!_ptrc_glNormal3fv) numFailed++;
	_ptrc_glNormal3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glNormal3i");
	if(!_ptrc_glNormal3i) numFailed++;
	_ptrc_glNormal3iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glNormal3iv");
	if(!_ptrc_glNormal3iv) numFailed++;
	_ptrc_glNormal3s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glNormal3s");
	if(!_ptrc_glNormal3s) numFailed++;
	_ptrc_glNormal3sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glNormal3sv");
	if(!_ptrc_glNormal3sv) numFailed++;
	_ptrc_glOrtho = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glOrtho");
	if(!_ptrc_glOrtho) numFailed++;
	_ptrc_glPassThrough = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glPassThrough");
	if(!_ptrc_glPassThrough) numFailed++;
	_ptrc_glPixelMapfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLfloat *))IntGetProcAddress("glPixelMapfv");
	if(!_ptrc_glPixelMapfv) numFailed++;
	_ptrc_glPixelMapuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLuint *))IntGetProcAddress("glPixelMapuiv");
	if(!_ptrc_glPixelMapuiv) numFailed++;
	_ptrc_glPixelMapusv = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLushort *))IntGetProcAddress("glPixelMapusv");
	if(!_ptrc_glPixelMapusv) numFailed++;
	_ptrc_glPixelStoref = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPixelStoref");
	if(!_ptrc_glPixelStoref) numFailed++;
	_ptrc_glPixelStorei = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPixelStorei");
	if(!_ptrc_glPixelStorei) numFailed++;
	_ptrc_glPixelTransferf = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPixelTransferf");
	if(!_ptrc_glPixelTransferf) numFailed++;
	_ptrc_glPixelTransferi = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPixelTransferi");
	if(!_ptrc_glPixelTransferi) numFailed++;
	_ptrc_glPixelZoom = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glPixelZoom");
	if(!_ptrc_glPixelZoom) numFailed++;
	_ptrc_glPointSize = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glPointSize");
	if(!_ptrc_glPointSize) numFailed++;
	_ptrc_glPolygonMode = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glPolygonMode");
	if(!_ptrc_glPolygonMode) numFailed++;
	_ptrc_glPolygonStipple = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glPolygonStipple");
	if(!_ptrc_glPolygonStipple) numFailed++;
	_ptrc_glPopAttrib = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPopAttrib");
	if(!_ptrc_glPopAttrib) numFailed++;
	_ptrc_glPopMatrix = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPopMatrix");
	if(!_ptrc_glPopMatrix) numFailed++;
	_ptrc_glPopName = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPopName");
	if(!_ptrc_glPopName) numFailed++;
	_ptrc_glPushAttrib = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glPushAttrib");
	if(!_ptrc_glPushAttrib) numFailed++;
	_ptrc_glPushMatrix = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPushMatrix");
	if(!_ptrc_glPushMatrix) numFailed++;
	_ptrc_glPushName = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glPushName");
	if(!_ptrc_glPushName) numFailed++;
	_ptrc_glRasterPos2d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glRasterPos2d");
	if(!_ptrc_glRasterPos2d) numFailed++;
	_ptrc_glRasterPos2dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glRasterPos2dv");
	if(!_ptrc_glRasterPos2dv) numFailed++;
	_ptrc_glRasterPos2f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glRasterPos2f");
	if(!_ptrc_glRasterPos2f) numFailed++;
	_ptrc_glRasterPos2fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glRasterPos2fv");
	if(!_ptrc_glRasterPos2fv) numFailed++;
	_ptrc_glRasterPos2i = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glRasterPos2i");
	if(!_ptrc_glRasterPos2i) numFailed++;
	_ptrc_glRasterPos2iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glRasterPos2iv");
	if(!_ptrc_glRasterPos2iv) numFailed++;
	_ptrc_glRasterPos2s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort))IntGetProcAddress("glRasterPos2s");
	if(!_ptrc_glRasterPos2s) numFailed++;
	_ptrc_glRasterPos2sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glRasterPos2sv");
	if(!_ptrc_glRasterPos2sv) numFailed++;
	_ptrc_glRasterPos3d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glRasterPos3d");
	if(!_ptrc_glRasterPos3d) numFailed++;
	_ptrc_glRasterPos3dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glRasterPos3dv");
	if(!_ptrc_glRasterPos3dv) numFailed++;
	_ptrc_glRasterPos3f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glRasterPos3f");
	if(!_ptrc_glRasterPos3f) numFailed++;
	_ptrc_glRasterPos3fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glRasterPos3fv");
	if(!_ptrc_glRasterPos3fv) numFailed++;
	_ptrc_glRasterPos3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glRasterPos3i");
	if(!_ptrc_glRasterPos3i) numFailed++;
	_ptrc_glRasterPos3iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glRasterPos3iv");
	if(!_ptrc_glRasterPos3iv) numFailed++;
	_ptrc_glRasterPos3s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glRasterPos3s");
	if(!_ptrc_glRasterPos3s) numFailed++;
	_ptrc_glRasterPos3sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glRasterPos3sv");
	if(!_ptrc_glRasterPos3sv) numFailed++;
	_ptrc_glRasterPos4d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glRasterPos4d");
	if(!_ptrc_glRasterPos4d) numFailed++;
	_ptrc_glRasterPos4dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glRasterPos4dv");
	if(!_ptrc_glRasterPos4dv) numFailed++;
	_ptrc_glRasterPos4f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glRasterPos4f");
	if(!_ptrc_glRasterPos4f) numFailed++;
	_ptrc_glRasterPos4fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glRasterPos4fv");
	if(!_ptrc_glRasterPos4fv) numFailed++;
	_ptrc_glRasterPos4i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glRasterPos4i");
	if(!_ptrc_glRasterPos4i) numFailed++;
	_ptrc_glRasterPos4iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glRasterPos4iv");
	if(!_ptrc_glRasterPos4iv) numFailed++;
	_ptrc_glRasterPos4s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glRasterPos4s");
	if(!_ptrc_glRasterPos4s) numFailed++;
	_ptrc_glRasterPos4sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glRasterPos4sv");
	if(!_ptrc_glRasterPos4sv) numFailed++;
	_ptrc_glReadBuffer = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glReadBuffer");
	if(!_ptrc_glReadBuffer) numFailed++;
	_ptrc_glReadPixels = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *))IntGetProcAddress("glReadPixels");
	if(!_ptrc_glReadPixels) numFailed++;
	_ptrc_glRectd = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glRectd");
	if(!_ptrc_glRectd) numFailed++;
	_ptrc_glRectdv = (void (CODEGEN_FUNCPTR *)(const GLdouble *, const GLdouble *))IntGetProcAddress("glRectdv");
	if(!_ptrc_glRectdv) numFailed++;
	_ptrc_glRectf = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glRectf");
	if(!_ptrc_glRectf) numFailed++;
	_ptrc_glRectfv = (void (CODEGEN_FUNCPTR *)(const GLfloat *, const GLfloat *))IntGetProcAddress("glRectfv");
	if(!_ptrc_glRectfv) numFailed++;
	_ptrc_glRecti = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glRecti");
	if(!_ptrc_glRecti) numFailed++;
	_ptrc_glRectiv = (void (CODEGEN_FUNCPTR *)(const GLint *, const GLint *))IntGetProcAddress("glRectiv");
	if(!_ptrc_glRectiv) numFailed++;
	_ptrc_glRects = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glRects");
	if(!_ptrc_glRects) numFailed++;
	_ptrc_glRectsv = (void (CODEGEN_FUNCPTR *)(const GLshort *, const GLshort *))IntGetProcAddress("glRectsv");
	if(!_ptrc_glRectsv) numFailed++;
	_ptrc_glRenderMode = (GLint (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glRenderMode");
	if(!_ptrc_glRenderMode) numFailed++;
	_ptrc_glRotated = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glRotated");
	if(!_ptrc_glRotated) numFailed++;
	_ptrc_glRotatef = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glRotatef");
	if(!_ptrc_glRotatef) numFailed++;
	_ptrc_glScaled = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glScaled");
	if(!_ptrc_glScaled) numFailed++;
	_ptrc_glScalef = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glScalef");
	if(!_ptrc_glScalef) numFailed++;
	_ptrc_glScissor = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glScissor");
	if(!_ptrc_glScissor) numFailed++;
	_ptrc_glSelectBuffer = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glSelectBuffer");
	if(!_ptrc_glSelectBuffer) numFailed++;
	_ptrc_glShadeModel = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glShadeModel");
	if(!_ptrc_glShadeModel) numFailed++;
	_ptrc_glStencilFunc = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint))IntGetProcAddress("glStencilFunc");
	if(!_ptrc_glStencilFunc) numFailed++;
	_ptrc_glStencilMask = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glStencilMask");
	if(!_ptrc_glStencilMask) numFailed++;
	_ptrc_glStencilOp = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum))IntGetProcAddress("glStencilOp");
	if(!_ptrc_glStencilOp) numFailed++;
	_ptrc_glTexCoord1d = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glTexCoord1d");
	if(!_ptrc_glTexCoord1d) numFailed++;
	_ptrc_glTexCoord1dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glTexCoord1dv");
	if(!_ptrc_glTexCoord1dv) numFailed++;
	_ptrc_glTexCoord1f = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glTexCoord1f");
	if(!_ptrc_glTexCoord1f) numFailed++;
	_ptrc_glTexCoord1fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glTexCoord1fv");
	if(!_ptrc_glTexCoord1fv) numFailed++;
	_ptrc_glTexCoord1i = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glTexCoord1i");
	if(!_ptrc_glTexCoord1i) numFailed++;
	_ptrc_glTexCoord1iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glTexCoord1iv");
	if(!_ptrc_glTexCoord1iv) numFailed++;
	_ptrc_glTexCoord1s = (void (CODEGEN_FUNCPTR *)(GLshort))IntGetProcAddress("glTexCoord1s");
	if(!_ptrc_glTexCoord1s) numFailed++;
	_ptrc_glTexCoord1sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glTexCoord1sv");
	if(!_ptrc_glTexCoord1sv) numFailed++;
	_ptrc_glTexCoord2d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glTexCoord2d");
	if(!_ptrc_glTexCoord2d) numFailed++;
	_ptrc_glTexCoord2dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glTexCoord2dv");
	if(!_ptrc_glTexCoord2dv) numFailed++;
	_ptrc_glTexCoord2f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glTexCoord2f");
	if(!_ptrc_glTexCoord2f) numFailed++;
	_ptrc_glTexCoord2fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glTexCoord2fv");
	if(!_ptrc_glTexCoord2fv) numFailed++;
	_ptrc_glTexCoord2i = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glTexCoord2i");
	if(!_ptrc_glTexCoord2i) numFailed++;
	_ptrc_glTexCoord2iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glTexCoord2iv");
	if(!_ptrc_glTexCoord2iv) numFailed++;
	_ptrc_glTexCoord2s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort))IntGetProcAddress("glTexCoord2s");
	if(!_ptrc_glTexCoord2s) numFailed++;
	_ptrc_glTexCoord2sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glTexCoord2sv");
	if(!_ptrc_glTexCoord2sv) numFailed++;
	_ptrc_glTexCoord3d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glTexCoord3d");
	if(!_ptrc_glTexCoord3d) numFailed++;
	_ptrc_glTexCoord3dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glTexCoord3dv");
	if(!_ptrc_glTexCoord3dv) numFailed++;
	_ptrc_glTexCoord3f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord3f");
	if(!_ptrc_glTexCoord3f) numFailed++;
	_ptrc_glTexCoord3fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glTexCoord3fv");
	if(!_ptrc_glTexCoord3fv) numFailed++;
	_ptrc_glTexCoord3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glTexCoord3i");
	if(!_ptrc_glTexCoord3i) numFailed++;
	_ptrc_glTexCoord3iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glTexCoord3iv");
	if(!_ptrc_glTexCoord3iv) numFailed++;
	_ptrc_glTexCoord3s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glTexCoord3s");
	if(!_ptrc_glTexCoord3s) numFailed++;
	_ptrc_glTexCoord3sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glTexCoord3sv");
	if(!_ptrc_glTexCoord3sv) numFailed++;
	_ptrc_glTexCoord4d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glTexCoord4d");
	if(!_ptrc_glTexCoord4d) numFailed++;
	_ptrc_glTexCoord4dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glTexCoord4dv");
	if(!_ptrc_glTexCoord4dv) numFailed++;
	_ptrc_glTexCoord4f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTexCoord4f");
	if(!_ptrc_glTexCoord4f) numFailed++;
	_ptrc_glTexCoord4fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glTexCoord4fv");
	if(!_ptrc_glTexCoord4fv) numFailed++;
	_ptrc_glTexCoord4i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glTexCoord4i");
	if(!_ptrc_glTexCoord4i) numFailed++;
	_ptrc_glTexCoord4iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glTexCoord4iv");
	if(!_ptrc_glTexCoord4iv) numFailed++;
	_ptrc_glTexCoord4s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glTexCoord4s");
	if(!_ptrc_glTexCoord4s) numFailed++;
	_ptrc_glTexCoord4sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glTexCoord4sv");
	if(!_ptrc_glTexCoord4sv) numFailed++;
	_ptrc_glTexEnvf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glTexEnvf");
	if(!_ptrc_glTexEnvf) numFailed++;
	_ptrc_glTexEnvfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glTexEnvfv");
	if(!_ptrc_glTexEnvfv) numFailed++;
	_ptrc_glTexEnvi = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glTexEnvi");
	if(!_ptrc_glTexEnvi) numFailed++;
	_ptrc_glTexEnviv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexEnviv");
	if(!_ptrc_glTexEnviv) numFailed++;
	_ptrc_glTexGend = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLdouble))IntGetProcAddress("glTexGend");
	if(!_ptrc_glTexGend) numFailed++;
	_ptrc_glTexGendv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLdouble *))IntGetProcAddress("glTexGendv");
	if(!_ptrc_glTexGendv) numFailed++;
	_ptrc_glTexGenf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glTexGenf");
	if(!_ptrc_glTexGenf) numFailed++;
	_ptrc_glTexGenfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glTexGenfv");
	if(!_ptrc_glTexGenfv) numFailed++;
	_ptrc_glTexGeni = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glTexGeni");
	if(!_ptrc_glTexGeni) numFailed++;
	_ptrc_glTexGeniv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexGeniv");
	if(!_ptrc_glTexGeniv) numFailed++;
	_ptrc_glTexImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexImage1D");
	if(!_ptrc_glTexImage1D) numFailed++;
	_ptrc_glTexImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexImage2D");
	if(!_ptrc_glTexImage2D) numFailed++;
	_ptrc_glTexParameterf = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLfloat))IntGetProcAddress("glTexParameterf");
	if(!_ptrc_glTexParameterf) numFailed++;
	_ptrc_glTexParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLfloat *))IntGetProcAddress("glTexParameterfv");
	if(!_ptrc_glTexParameterfv) numFailed++;
	_ptrc_glTexParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glTexParameteri");
	if(!_ptrc_glTexParameteri) numFailed++;
	_ptrc_glTexParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexParameteriv");
	if(!_ptrc_glTexParameteriv) numFailed++;
	_ptrc_glTranslated = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glTranslated");
	if(!_ptrc_glTranslated) numFailed++;
	_ptrc_glTranslatef = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glTranslatef");
	if(!_ptrc_glTranslatef) numFailed++;
	_ptrc_glVertex2d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glVertex2d");
	if(!_ptrc_glVertex2d) numFailed++;
	_ptrc_glVertex2dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glVertex2dv");
	if(!_ptrc_glVertex2dv) numFailed++;
	_ptrc_glVertex2f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glVertex2f");
	if(!_ptrc_glVertex2f) numFailed++;
	_ptrc_glVertex2fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glVertex2fv");
	if(!_ptrc_glVertex2fv) numFailed++;
	_ptrc_glVertex2i = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glVertex2i");
	if(!_ptrc_glVertex2i) numFailed++;
	_ptrc_glVertex2iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glVertex2iv");
	if(!_ptrc_glVertex2iv) numFailed++;
	_ptrc_glVertex2s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort))IntGetProcAddress("glVertex2s");
	if(!_ptrc_glVertex2s) numFailed++;
	_ptrc_glVertex2sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glVertex2sv");
	if(!_ptrc_glVertex2sv) numFailed++;
	_ptrc_glVertex3d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertex3d");
	if(!_ptrc_glVertex3d) numFailed++;
	_ptrc_glVertex3dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glVertex3dv");
	if(!_ptrc_glVertex3dv) numFailed++;
	_ptrc_glVertex3f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertex3f");
	if(!_ptrc_glVertex3f) numFailed++;
	_ptrc_glVertex3fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glVertex3fv");
	if(!_ptrc_glVertex3fv) numFailed++;
	_ptrc_glVertex3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glVertex3i");
	if(!_ptrc_glVertex3i) numFailed++;
	_ptrc_glVertex3iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glVertex3iv");
	if(!_ptrc_glVertex3iv) numFailed++;
	_ptrc_glVertex3s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glVertex3s");
	if(!_ptrc_glVertex3s) numFailed++;
	_ptrc_glVertex3sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glVertex3sv");
	if(!_ptrc_glVertex3sv) numFailed++;
	_ptrc_glVertex4d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertex4d");
	if(!_ptrc_glVertex4d) numFailed++;
	_ptrc_glVertex4dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glVertex4dv");
	if(!_ptrc_glVertex4dv) numFailed++;
	_ptrc_glVertex4f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertex4f");
	if(!_ptrc_glVertex4f) numFailed++;
	_ptrc_glVertex4fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glVertex4fv");
	if(!_ptrc_glVertex4fv) numFailed++;
	_ptrc_glVertex4i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glVertex4i");
	if(!_ptrc_glVertex4i) numFailed++;
	_ptrc_glVertex4iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glVertex4iv");
	if(!_ptrc_glVertex4iv) numFailed++;
	_ptrc_glVertex4s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertex4s");
	if(!_ptrc_glVertex4s) numFailed++;
	_ptrc_glVertex4sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glVertex4sv");
	if(!_ptrc_glVertex4sv) numFailed++;
	_ptrc_glViewport = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glViewport");
	if(!_ptrc_glViewport) numFailed++;
	_ptrc_glAreTexturesResident = (GLboolean (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLboolean *))IntGetProcAddress("glAreTexturesResident");
	if(!_ptrc_glAreTexturesResident) numFailed++;
	_ptrc_glArrayElement = (void (CODEGEN_FUNCPTR *)(GLint))IntGetProcAddress("glArrayElement");
	if(!_ptrc_glArrayElement) numFailed++;
	_ptrc_glBindTexture = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTexture");
	if(!_ptrc_glBindTexture) numFailed++;
	_ptrc_glColorPointer = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glColorPointer");
	if(!_ptrc_glColorPointer) numFailed++;
	_ptrc_glCopyTexImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint))IntGetProcAddress("glCopyTexImage1D");
	if(!_ptrc_glCopyTexImage1D) numFailed++;
	_ptrc_glCopyTexImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint))IntGetProcAddress("glCopyTexImage2D");
	if(!_ptrc_glCopyTexImage2D) numFailed++;
	_ptrc_glCopyTexSubImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei))IntGetProcAddress("glCopyTexSubImage1D");
	if(!_ptrc_glCopyTexSubImage1D) numFailed++;
	_ptrc_glCopyTexSubImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTexSubImage2D");
	if(!_ptrc_glCopyTexSubImage2D) numFailed++;
	_ptrc_glDeleteTextures = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTextures");
	if(!_ptrc_glDeleteTextures) numFailed++;
	_ptrc_glDisableClientState = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glDisableClientState");
	if(!_ptrc_glDisableClientState) numFailed++;
	_ptrc_glDrawArrays = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei))IntGetProcAddress("glDrawArrays");
	if(!_ptrc_glDrawArrays) numFailed++;
	_ptrc_glDrawElements = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glDrawElements");
	if(!_ptrc_glDrawElements) numFailed++;
	_ptrc_glEdgeFlagPointer = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLvoid *))IntGetProcAddress("glEdgeFlagPointer");
	if(!_ptrc_glEdgeFlagPointer) numFailed++;
	_ptrc_glEnableClientState = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glEnableClientState");
	if(!_ptrc_glEnableClientState) numFailed++;
	_ptrc_glGenTextures = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTextures");
	if(!_ptrc_glGenTextures) numFailed++;
	_ptrc_glGetPointerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLvoid **))IntGetProcAddress("glGetPointerv");
	if(!_ptrc_glGetPointerv) numFailed++;
	_ptrc_glIndexPointer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glIndexPointer");
	if(!_ptrc_glIndexPointer) numFailed++;
	_ptrc_glIndexub = (void (CODEGEN_FUNCPTR *)(GLubyte))IntGetProcAddress("glIndexub");
	if(!_ptrc_glIndexub) numFailed++;
	_ptrc_glIndexubv = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glIndexubv");
	if(!_ptrc_glIndexubv) numFailed++;
	_ptrc_glInterleavedArrays = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glInterleavedArrays");
	if(!_ptrc_glInterleavedArrays) numFailed++;
	_ptrc_glIsTexture = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTexture");
	if(!_ptrc_glIsTexture) numFailed++;
	_ptrc_glNormalPointer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glNormalPointer");
	if(!_ptrc_glNormalPointer) numFailed++;
	_ptrc_glPolygonOffset = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glPolygonOffset");
	if(!_ptrc_glPolygonOffset) numFailed++;
	_ptrc_glPopClientAttrib = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPopClientAttrib");
	if(!_ptrc_glPopClientAttrib) numFailed++;
	_ptrc_glPrioritizeTextures = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, const GLfloat *))IntGetProcAddress("glPrioritizeTextures");
	if(!_ptrc_glPrioritizeTextures) numFailed++;
	_ptrc_glPushClientAttrib = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glPushClientAttrib");
	if(!_ptrc_glPushClientAttrib) numFailed++;
	_ptrc_glTexCoordPointer = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glTexCoordPointer");
	if(!_ptrc_glTexCoordPointer) numFailed++;
	_ptrc_glTexSubImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexSubImage1D");
	if(!_ptrc_glTexSubImage1D) numFailed++;
	_ptrc_glTexSubImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexSubImage2D");
	if(!_ptrc_glTexSubImage2D) numFailed++;
	_ptrc_glVertexPointer = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexPointer");
	if(!_ptrc_glVertexPointer) numFailed++;
	_ptrc_glBlendColor = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glBlendColor");
	if(!_ptrc_glBlendColor) numFailed++;
	_ptrc_glBlendEquation = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBlendEquation");
	if(!_ptrc_glBlendEquation) numFailed++;
	_ptrc_glCopyTexSubImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glCopyTexSubImage3D");
	if(!_ptrc_glCopyTexSubImage3D) numFailed++;
	_ptrc_glDrawRangeElements = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *))IntGetProcAddress("glDrawRangeElements");
	if(!_ptrc_glDrawRangeElements) numFailed++;
	_ptrc_glTexImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexImage3D");
	if(!_ptrc_glTexImage3D) numFailed++;
	_ptrc_glTexSubImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *))IntGetProcAddress("glTexSubImage3D");
	if(!_ptrc_glTexSubImage3D) numFailed++;
	_ptrc_glActiveTexture = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glActiveTexture");
	if(!_ptrc_glActiveTexture) numFailed++;
	_ptrc_glClientActiveTexture = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glClientActiveTexture");
	if(!_ptrc_glClientActiveTexture) numFailed++;
	_ptrc_glCompressedTexImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexImage1D");
	if(!_ptrc_glCompressedTexImage1D) numFailed++;
	_ptrc_glCompressedTexImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexImage2D");
	if(!_ptrc_glCompressedTexImage2D) numFailed++;
	_ptrc_glCompressedTexImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexImage3D");
	if(!_ptrc_glCompressedTexImage3D) numFailed++;
	_ptrc_glCompressedTexSubImage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexSubImage1D");
	if(!_ptrc_glCompressedTexSubImage1D) numFailed++;
	_ptrc_glCompressedTexSubImage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexSubImage2D");
	if(!_ptrc_glCompressedTexSubImage2D) numFailed++;
	_ptrc_glCompressedTexSubImage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glCompressedTexSubImage3D");
	if(!_ptrc_glCompressedTexSubImage3D) numFailed++;
	_ptrc_glGetCompressedTexImage = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLvoid *))IntGetProcAddress("glGetCompressedTexImage");
	if(!_ptrc_glGetCompressedTexImage) numFailed++;
	_ptrc_glLoadTransposeMatrixd = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glLoadTransposeMatrixd");
	if(!_ptrc_glLoadTransposeMatrixd) numFailed++;
	_ptrc_glLoadTransposeMatrixf = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glLoadTransposeMatrixf");
	if(!_ptrc_glLoadTransposeMatrixf) numFailed++;
	_ptrc_glMultTransposeMatrixd = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glMultTransposeMatrixd");
	if(!_ptrc_glMultTransposeMatrixd) numFailed++;
	_ptrc_glMultTransposeMatrixf = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glMultTransposeMatrixf");
	if(!_ptrc_glMultTransposeMatrixf) numFailed++;
	_ptrc_glMultiTexCoord1d = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble))IntGetProcAddress("glMultiTexCoord1d");
	if(!_ptrc_glMultiTexCoord1d) numFailed++;
	_ptrc_glMultiTexCoord1dv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord1dv");
	if(!_ptrc_glMultiTexCoord1dv) numFailed++;
	_ptrc_glMultiTexCoord1f = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glMultiTexCoord1f");
	if(!_ptrc_glMultiTexCoord1f) numFailed++;
	_ptrc_glMultiTexCoord1fv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord1fv");
	if(!_ptrc_glMultiTexCoord1fv) numFailed++;
	_ptrc_glMultiTexCoord1i = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glMultiTexCoord1i");
	if(!_ptrc_glMultiTexCoord1i) numFailed++;
	_ptrc_glMultiTexCoord1iv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord1iv");
	if(!_ptrc_glMultiTexCoord1iv) numFailed++;
	_ptrc_glMultiTexCoord1s = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort))IntGetProcAddress("glMultiTexCoord1s");
	if(!_ptrc_glMultiTexCoord1s) numFailed++;
	_ptrc_glMultiTexCoord1sv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord1sv");
	if(!_ptrc_glMultiTexCoord1sv) numFailed++;
	_ptrc_glMultiTexCoord2d = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord2d");
	if(!_ptrc_glMultiTexCoord2d) numFailed++;
	_ptrc_glMultiTexCoord2dv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord2dv");
	if(!_ptrc_glMultiTexCoord2dv) numFailed++;
	_ptrc_glMultiTexCoord2f = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord2f");
	if(!_ptrc_glMultiTexCoord2f) numFailed++;
	_ptrc_glMultiTexCoord2fv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord2fv");
	if(!_ptrc_glMultiTexCoord2fv) numFailed++;
	_ptrc_glMultiTexCoord2i = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint))IntGetProcAddress("glMultiTexCoord2i");
	if(!_ptrc_glMultiTexCoord2i) numFailed++;
	_ptrc_glMultiTexCoord2iv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord2iv");
	if(!_ptrc_glMultiTexCoord2iv) numFailed++;
	_ptrc_glMultiTexCoord2s = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord2s");
	if(!_ptrc_glMultiTexCoord2s) numFailed++;
	_ptrc_glMultiTexCoord2sv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord2sv");
	if(!_ptrc_glMultiTexCoord2sv) numFailed++;
	_ptrc_glMultiTexCoord3d = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord3d");
	if(!_ptrc_glMultiTexCoord3d) numFailed++;
	_ptrc_glMultiTexCoord3dv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord3dv");
	if(!_ptrc_glMultiTexCoord3dv) numFailed++;
	_ptrc_glMultiTexCoord3f = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord3f");
	if(!_ptrc_glMultiTexCoord3f) numFailed++;
	_ptrc_glMultiTexCoord3fv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord3fv");
	if(!_ptrc_glMultiTexCoord3fv) numFailed++;
	_ptrc_glMultiTexCoord3i = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint))IntGetProcAddress("glMultiTexCoord3i");
	if(!_ptrc_glMultiTexCoord3i) numFailed++;
	_ptrc_glMultiTexCoord3iv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord3iv");
	if(!_ptrc_glMultiTexCoord3iv) numFailed++;
	_ptrc_glMultiTexCoord3s = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord3s");
	if(!_ptrc_glMultiTexCoord3s) numFailed++;
	_ptrc_glMultiTexCoord3sv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord3sv");
	if(!_ptrc_glMultiTexCoord3sv) numFailed++;
	_ptrc_glMultiTexCoord4d = (void (CODEGEN_FUNCPTR *)(GLenum, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glMultiTexCoord4d");
	if(!_ptrc_glMultiTexCoord4d) numFailed++;
	_ptrc_glMultiTexCoord4dv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLdouble *))IntGetProcAddress("glMultiTexCoord4dv");
	if(!_ptrc_glMultiTexCoord4dv) numFailed++;
	_ptrc_glMultiTexCoord4f = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glMultiTexCoord4f");
	if(!_ptrc_glMultiTexCoord4f) numFailed++;
	_ptrc_glMultiTexCoord4fv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glMultiTexCoord4fv");
	if(!_ptrc_glMultiTexCoord4fv) numFailed++;
	_ptrc_glMultiTexCoord4i = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLint, GLint, GLint))IntGetProcAddress("glMultiTexCoord4i");
	if(!_ptrc_glMultiTexCoord4i) numFailed++;
	_ptrc_glMultiTexCoord4iv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glMultiTexCoord4iv");
	if(!_ptrc_glMultiTexCoord4iv) numFailed++;
	_ptrc_glMultiTexCoord4s = (void (CODEGEN_FUNCPTR *)(GLenum, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glMultiTexCoord4s");
	if(!_ptrc_glMultiTexCoord4s) numFailed++;
	_ptrc_glMultiTexCoord4sv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLshort *))IntGetProcAddress("glMultiTexCoord4sv");
	if(!_ptrc_glMultiTexCoord4sv) numFailed++;
	_ptrc_glSampleCoverage = (void (CODEGEN_FUNCPTR *)(GLfloat, GLboolean))IntGetProcAddress("glSampleCoverage");
	if(!_ptrc_glSampleCoverage) numFailed++;
	_ptrc_glBlendFuncSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparate");
	if(!_ptrc_glBlendFuncSeparate) numFailed++;
	_ptrc_glFogCoordPointer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glFogCoordPointer");
	if(!_ptrc_glFogCoordPointer) numFailed++;
	_ptrc_glFogCoordd = (void (CODEGEN_FUNCPTR *)(GLdouble))IntGetProcAddress("glFogCoordd");
	if(!_ptrc_glFogCoordd) numFailed++;
	_ptrc_glFogCoorddv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glFogCoorddv");
	if(!_ptrc_glFogCoorddv) numFailed++;
	_ptrc_glFogCoordf = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glFogCoordf");
	if(!_ptrc_glFogCoordf) numFailed++;
	_ptrc_glFogCoordfv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glFogCoordfv");
	if(!_ptrc_glFogCoordfv) numFailed++;
	_ptrc_glMultiDrawArrays = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *, const GLsizei *, GLsizei))IntGetProcAddress("glMultiDrawArrays");
	if(!_ptrc_glMultiDrawArrays) numFailed++;
	_ptrc_glMultiDrawElements = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei))IntGetProcAddress("glMultiDrawElements");
	if(!_ptrc_glMultiDrawElements) numFailed++;
	_ptrc_glPointParameterf = (void (CODEGEN_FUNCPTR *)(GLenum, GLfloat))IntGetProcAddress("glPointParameterf");
	if(!_ptrc_glPointParameterf) numFailed++;
	_ptrc_glPointParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPointParameterfv");
	if(!_ptrc_glPointParameterfv) numFailed++;
	_ptrc_glPointParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPointParameteri");
	if(!_ptrc_glPointParameteri) numFailed++;
	_ptrc_glPointParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLint *))IntGetProcAddress("glPointParameteriv");
	if(!_ptrc_glPointParameteriv) numFailed++;
	_ptrc_glSecondaryColor3b = (void (CODEGEN_FUNCPTR *)(GLbyte, GLbyte, GLbyte))IntGetProcAddress("glSecondaryColor3b");
	if(!_ptrc_glSecondaryColor3b) numFailed++;
	_ptrc_glSecondaryColor3bv = (void (CODEGEN_FUNCPTR *)(const GLbyte *))IntGetProcAddress("glSecondaryColor3bv");
	if(!_ptrc_glSecondaryColor3bv) numFailed++;
	_ptrc_glSecondaryColor3d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glSecondaryColor3d");
	if(!_ptrc_glSecondaryColor3d) numFailed++;
	_ptrc_glSecondaryColor3dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glSecondaryColor3dv");
	if(!_ptrc_glSecondaryColor3dv) numFailed++;
	_ptrc_glSecondaryColor3f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glSecondaryColor3f");
	if(!_ptrc_glSecondaryColor3f) numFailed++;
	_ptrc_glSecondaryColor3fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glSecondaryColor3fv");
	if(!_ptrc_glSecondaryColor3fv) numFailed++;
	_ptrc_glSecondaryColor3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glSecondaryColor3i");
	if(!_ptrc_glSecondaryColor3i) numFailed++;
	_ptrc_glSecondaryColor3iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glSecondaryColor3iv");
	if(!_ptrc_glSecondaryColor3iv) numFailed++;
	_ptrc_glSecondaryColor3s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glSecondaryColor3s");
	if(!_ptrc_glSecondaryColor3s) numFailed++;
	_ptrc_glSecondaryColor3sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glSecondaryColor3sv");
	if(!_ptrc_glSecondaryColor3sv) numFailed++;
	_ptrc_glSecondaryColor3ub = (void (CODEGEN_FUNCPTR *)(GLubyte, GLubyte, GLubyte))IntGetProcAddress("glSecondaryColor3ub");
	if(!_ptrc_glSecondaryColor3ub) numFailed++;
	_ptrc_glSecondaryColor3ubv = (void (CODEGEN_FUNCPTR *)(const GLubyte *))IntGetProcAddress("glSecondaryColor3ubv");
	if(!_ptrc_glSecondaryColor3ubv) numFailed++;
	_ptrc_glSecondaryColor3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glSecondaryColor3ui");
	if(!_ptrc_glSecondaryColor3ui) numFailed++;
	_ptrc_glSecondaryColor3uiv = (void (CODEGEN_FUNCPTR *)(const GLuint *))IntGetProcAddress("glSecondaryColor3uiv");
	if(!_ptrc_glSecondaryColor3uiv) numFailed++;
	_ptrc_glSecondaryColor3us = (void (CODEGEN_FUNCPTR *)(GLushort, GLushort, GLushort))IntGetProcAddress("glSecondaryColor3us");
	if(!_ptrc_glSecondaryColor3us) numFailed++;
	_ptrc_glSecondaryColor3usv = (void (CODEGEN_FUNCPTR *)(const GLushort *))IntGetProcAddress("glSecondaryColor3usv");
	if(!_ptrc_glSecondaryColor3usv) numFailed++;
	_ptrc_glSecondaryColorPointer = (void (CODEGEN_FUNCPTR *)(GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glSecondaryColorPointer");
	if(!_ptrc_glSecondaryColorPointer) numFailed++;
	_ptrc_glWindowPos2d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble))IntGetProcAddress("glWindowPos2d");
	if(!_ptrc_glWindowPos2d) numFailed++;
	_ptrc_glWindowPos2dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos2dv");
	if(!_ptrc_glWindowPos2dv) numFailed++;
	_ptrc_glWindowPos2f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glWindowPos2f");
	if(!_ptrc_glWindowPos2f) numFailed++;
	_ptrc_glWindowPos2fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos2fv");
	if(!_ptrc_glWindowPos2fv) numFailed++;
	_ptrc_glWindowPos2i = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glWindowPos2i");
	if(!_ptrc_glWindowPos2i) numFailed++;
	_ptrc_glWindowPos2iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos2iv");
	if(!_ptrc_glWindowPos2iv) numFailed++;
	_ptrc_glWindowPos2s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort))IntGetProcAddress("glWindowPos2s");
	if(!_ptrc_glWindowPos2s) numFailed++;
	_ptrc_glWindowPos2sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos2sv");
	if(!_ptrc_glWindowPos2sv) numFailed++;
	_ptrc_glWindowPos3d = (void (CODEGEN_FUNCPTR *)(GLdouble, GLdouble, GLdouble))IntGetProcAddress("glWindowPos3d");
	if(!_ptrc_glWindowPos3d) numFailed++;
	_ptrc_glWindowPos3dv = (void (CODEGEN_FUNCPTR *)(const GLdouble *))IntGetProcAddress("glWindowPos3dv");
	if(!_ptrc_glWindowPos3dv) numFailed++;
	_ptrc_glWindowPos3f = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat, GLfloat))IntGetProcAddress("glWindowPos3f");
	if(!_ptrc_glWindowPos3f) numFailed++;
	_ptrc_glWindowPos3fv = (void (CODEGEN_FUNCPTR *)(const GLfloat *))IntGetProcAddress("glWindowPos3fv");
	if(!_ptrc_glWindowPos3fv) numFailed++;
	_ptrc_glWindowPos3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glWindowPos3i");
	if(!_ptrc_glWindowPos3i) numFailed++;
	_ptrc_glWindowPos3iv = (void (CODEGEN_FUNCPTR *)(const GLint *))IntGetProcAddress("glWindowPos3iv");
	if(!_ptrc_glWindowPos3iv) numFailed++;
	_ptrc_glWindowPos3s = (void (CODEGEN_FUNCPTR *)(GLshort, GLshort, GLshort))IntGetProcAddress("glWindowPos3s");
	if(!_ptrc_glWindowPos3s) numFailed++;
	_ptrc_glWindowPos3sv = (void (CODEGEN_FUNCPTR *)(const GLshort *))IntGetProcAddress("glWindowPos3sv");
	if(!_ptrc_glWindowPos3sv) numFailed++;
	_ptrc_glBeginQuery = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBeginQuery");
	if(!_ptrc_glBeginQuery) numFailed++;
	_ptrc_glBindBuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindBuffer");
	if(!_ptrc_glBindBuffer) numFailed++;
	_ptrc_glBufferData = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptr, const GLvoid *, GLenum))IntGetProcAddress("glBufferData");
	if(!_ptrc_glBufferData) numFailed++;
	_ptrc_glBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, const GLvoid *))IntGetProcAddress("glBufferSubData");
	if(!_ptrc_glBufferSubData) numFailed++;
	_ptrc_glDeleteBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteBuffers");
	if(!_ptrc_glDeleteBuffers) numFailed++;
	_ptrc_glDeleteQueries = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteQueries");
	if(!_ptrc_glDeleteQueries) numFailed++;
	_ptrc_glEndQuery = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glEndQuery");
	if(!_ptrc_glEndQuery) numFailed++;
	_ptrc_glGenBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenBuffers");
	if(!_ptrc_glGenBuffers) numFailed++;
	_ptrc_glGenQueries = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenQueries");
	if(!_ptrc_glGenQueries) numFailed++;
	_ptrc_glGetBufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetBufferParameteriv");
	if(!_ptrc_glGetBufferParameteriv) numFailed++;
	_ptrc_glGetBufferPointerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLvoid **))IntGetProcAddress("glGetBufferPointerv");
	if(!_ptrc_glGetBufferPointerv) numFailed++;
	_ptrc_glGetBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, GLvoid *))IntGetProcAddress("glGetBufferSubData");
	if(!_ptrc_glGetBufferSubData) numFailed++;
	_ptrc_glGetQueryObjectiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryObjectiv");
	if(!_ptrc_glGetQueryObjectiv) numFailed++;
	_ptrc_glGetQueryObjectuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetQueryObjectuiv");
	if(!_ptrc_glGetQueryObjectuiv) numFailed++;
	_ptrc_glGetQueryiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetQueryiv");
	if(!_ptrc_glGetQueryiv) numFailed++;
	_ptrc_glIsBuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsBuffer");
	if(!_ptrc_glIsBuffer) numFailed++;
	_ptrc_glIsQuery = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsQuery");
	if(!_ptrc_glIsQuery) numFailed++;
	_ptrc_glMapBuffer = (void * (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glMapBuffer");
	if(!_ptrc_glMapBuffer) numFailed++;
	_ptrc_glUnmapBuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glUnmapBuffer");
	if(!_ptrc_glUnmapBuffer) numFailed++;
	_ptrc_glAttachShader = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glAttachShader");
	if(!_ptrc_glAttachShader) numFailed++;
	_ptrc_glBindAttribLocation = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindAttribLocation");
	if(!_ptrc_glBindAttribLocation) numFailed++;
	_ptrc_glBlendEquationSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparate");
	if(!_ptrc_glBlendEquationSeparate) numFailed++;
	_ptrc_glCompileShader = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glCompileShader");
	if(!_ptrc_glCompileShader) numFailed++;
	_ptrc_glCreateProgram = (GLuint (CODEGEN_FUNCPTR *)())IntGetProcAddress("glCreateProgram");
	if(!_ptrc_glCreateProgram) numFailed++;
	_ptrc_glCreateShader = (GLuint (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCreateShader");
	if(!_ptrc_glCreateShader) numFailed++;
	_ptrc_glDeleteProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDeleteProgram");
	if(!_ptrc_glDeleteProgram) numFailed++;
	_ptrc_glDeleteShader = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDeleteShader");
	if(!_ptrc_glDeleteShader) numFailed++;
	_ptrc_glDetachShader = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glDetachShader");
	if(!_ptrc_glDetachShader) numFailed++;
	_ptrc_glDisableVertexAttribArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glDisableVertexAttribArray");
	if(!_ptrc_glDisableVertexAttribArray) numFailed++;
	_ptrc_glDrawBuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLenum *))IntGetProcAddress("glDrawBuffers");
	if(!_ptrc_glDrawBuffers) numFailed++;
	_ptrc_glEnableVertexAttribArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glEnableVertexAttribArray");
	if(!_ptrc_glEnableVertexAttribArray) numFailed++;
	_ptrc_glGetActiveAttrib = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *))IntGetProcAddress("glGetActiveAttrib");
	if(!_ptrc_glGetActiveAttrib) numFailed++;
	_ptrc_glGetActiveUniform = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *))IntGetProcAddress("glGetActiveUniform");
	if(!_ptrc_glGetActiveUniform) numFailed++;
	_ptrc_glGetAttachedShaders = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLuint *))IntGetProcAddress("glGetAttachedShaders");
	if(!_ptrc_glGetAttachedShaders) numFailed++;
	_ptrc_glGetAttribLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetAttribLocation");
	if(!_ptrc_glGetAttribLocation) numFailed++;
	_ptrc_glGetProgramInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramInfoLog");
	if(!_ptrc_glGetProgramInfoLog) numFailed++;
	_ptrc_glGetProgramiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramiv");
	if(!_ptrc_glGetProgramiv) numFailed++;
	_ptrc_glGetShaderInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetShaderInfoLog");
	if(!_ptrc_glGetShaderInfoLog) numFailed++;
	_ptrc_glGetShaderSource = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetShaderSource");
	if(!_ptrc_glGetShaderSource) numFailed++;
	_ptrc_glGetShaderiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetShaderiv");
	if(!_ptrc_glGetShaderiv) numFailed++;
	_ptrc_glGetUniformLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetUniformLocation");
	if(!_ptrc_glGetUniformLocation) numFailed++;
	_ptrc_glGetUniformfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat *))IntGetProcAddress("glGetUniformfv");
	if(!_ptrc_glGetUniformfv) numFailed++;
	_ptrc_glGetUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint *))IntGetProcAddress("glGetUniformiv");
	if(!_ptrc_glGetUniformiv) numFailed++;
	_ptrc_glGetVertexAttribPointerv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLvoid **))IntGetProcAddress("glGetVertexAttribPointerv");
	if(!_ptrc_glGetVertexAttribPointerv) numFailed++;
	_ptrc_glGetVertexAttribdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribdv");
	if(!_ptrc_glGetVertexAttribdv) numFailed++;
	_ptrc_glGetVertexAttribfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetVertexAttribfv");
	if(!_ptrc_glGetVertexAttribfv) numFailed++;
	_ptrc_glGetVertexAttribiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribiv");
	if(!_ptrc_glGetVertexAttribiv) numFailed++;
	_ptrc_glIsProgram = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgram");
	if(!_ptrc_glIsProgram) numFailed++;
	_ptrc_glIsShader = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsShader");
	if(!_ptrc_glIsShader) numFailed++;
	_ptrc_glLinkProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glLinkProgram");
	if(!_ptrc_glLinkProgram) numFailed++;
	_ptrc_glShaderSource = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, const GLint *))IntGetProcAddress("glShaderSource");
	if(!_ptrc_glShaderSource) numFailed++;
	_ptrc_glStencilFuncSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint, GLuint))IntGetProcAddress("glStencilFuncSeparate");
	if(!_ptrc_glStencilFuncSeparate) numFailed++;
	_ptrc_glStencilMaskSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glStencilMaskSeparate");
	if(!_ptrc_glStencilMaskSeparate) numFailed++;
	_ptrc_glStencilOpSeparate = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glStencilOpSeparate");
	if(!_ptrc_glStencilOpSeparate) numFailed++;
	_ptrc_glUniform1f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat))IntGetProcAddress("glUniform1f");
	if(!_ptrc_glUniform1f) numFailed++;
	_ptrc_glUniform1fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform1fv");
	if(!_ptrc_glUniform1fv) numFailed++;
	_ptrc_glUniform1i = (void (CODEGEN_FUNCPTR *)(GLint, GLint))IntGetProcAddress("glUniform1i");
	if(!_ptrc_glUniform1i) numFailed++;
	_ptrc_glUniform1iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform1iv");
	if(!_ptrc_glUniform1iv) numFailed++;
	_ptrc_glUniform2f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat))IntGetProcAddress("glUniform2f");
	if(!_ptrc_glUniform2f) numFailed++;
	_ptrc_glUniform2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform2fv");
	if(!_ptrc_glUniform2fv) numFailed++;
	_ptrc_glUniform2i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint))IntGetProcAddress("glUniform2i");
	if(!_ptrc_glUniform2i) numFailed++;
	_ptrc_glUniform2iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform2iv");
	if(!_ptrc_glUniform2iv) numFailed++;
	_ptrc_glUniform3f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform3f");
	if(!_ptrc_glUniform3f) numFailed++;
	_ptrc_glUniform3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform3fv");
	if(!_ptrc_glUniform3fv) numFailed++;
	_ptrc_glUniform3i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform3i");
	if(!_ptrc_glUniform3i) numFailed++;
	_ptrc_glUniform3iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform3iv");
	if(!_ptrc_glUniform3iv) numFailed++;
	_ptrc_glUniform4f = (void (CODEGEN_FUNCPTR *)(GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glUniform4f");
	if(!_ptrc_glUniform4f) numFailed++;
	_ptrc_glUniform4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLfloat *))IntGetProcAddress("glUniform4fv");
	if(!_ptrc_glUniform4fv) numFailed++;
	_ptrc_glUniform4i = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glUniform4i");
	if(!_ptrc_glUniform4i) numFailed++;
	_ptrc_glUniform4iv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLint *))IntGetProcAddress("glUniform4iv");
	if(!_ptrc_glUniform4iv) numFailed++;
	_ptrc_glUniformMatrix2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2fv");
	if(!_ptrc_glUniformMatrix2fv) numFailed++;
	_ptrc_glUniformMatrix3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3fv");
	if(!_ptrc_glUniformMatrix3fv) numFailed++;
	_ptrc_glUniformMatrix4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4fv");
	if(!_ptrc_glUniformMatrix4fv) numFailed++;
	_ptrc_glUseProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glUseProgram");
	if(!_ptrc_glUseProgram) numFailed++;
	_ptrc_glValidateProgram = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glValidateProgram");
	if(!_ptrc_glValidateProgram) numFailed++;
	_ptrc_glVertexAttrib1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttrib1d");
	if(!_ptrc_glVertexAttrib1d) numFailed++;
	_ptrc_glVertexAttrib1dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib1dv");
	if(!_ptrc_glVertexAttrib1dv) numFailed++;
	_ptrc_glVertexAttrib1f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat))IntGetProcAddress("glVertexAttrib1f");
	if(!_ptrc_glVertexAttrib1f) numFailed++;
	_ptrc_glVertexAttrib1fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib1fv");
	if(!_ptrc_glVertexAttrib1fv) numFailed++;
	_ptrc_glVertexAttrib1s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort))IntGetProcAddress("glVertexAttrib1s");
	if(!_ptrc_glVertexAttrib1s) numFailed++;
	_ptrc_glVertexAttrib1sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib1sv");
	if(!_ptrc_glVertexAttrib1sv) numFailed++;
	_ptrc_glVertexAttrib2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib2d");
	if(!_ptrc_glVertexAttrib2d) numFailed++;
	_ptrc_glVertexAttrib2dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib2dv");
	if(!_ptrc_glVertexAttrib2dv) numFailed++;
	_ptrc_glVertexAttrib2f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib2f");
	if(!_ptrc_glVertexAttrib2f) numFailed++;
	_ptrc_glVertexAttrib2fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib2fv");
	if(!_ptrc_glVertexAttrib2fv) numFailed++;
	_ptrc_glVertexAttrib2s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort))IntGetProcAddress("glVertexAttrib2s");
	if(!_ptrc_glVertexAttrib2s) numFailed++;
	_ptrc_glVertexAttrib2sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib2sv");
	if(!_ptrc_glVertexAttrib2sv) numFailed++;
	_ptrc_glVertexAttrib3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib3d");
	if(!_ptrc_glVertexAttrib3d) numFailed++;
	_ptrc_glVertexAttrib3dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib3dv");
	if(!_ptrc_glVertexAttrib3dv) numFailed++;
	_ptrc_glVertexAttrib3f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib3f");
	if(!_ptrc_glVertexAttrib3f) numFailed++;
	_ptrc_glVertexAttrib3fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib3fv");
	if(!_ptrc_glVertexAttrib3fv) numFailed++;
	_ptrc_glVertexAttrib3s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib3s");
	if(!_ptrc_glVertexAttrib3s) numFailed++;
	_ptrc_glVertexAttrib3sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib3sv");
	if(!_ptrc_glVertexAttrib3sv) numFailed++;
	_ptrc_glVertexAttrib4Nbv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4Nbv");
	if(!_ptrc_glVertexAttrib4Nbv) numFailed++;
	_ptrc_glVertexAttrib4Niv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4Niv");
	if(!_ptrc_glVertexAttrib4Niv) numFailed++;
	_ptrc_glVertexAttrib4Nsv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4Nsv");
	if(!_ptrc_glVertexAttrib4Nsv) numFailed++;
	_ptrc_glVertexAttrib4Nub = (void (CODEGEN_FUNCPTR *)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte))IntGetProcAddress("glVertexAttrib4Nub");
	if(!_ptrc_glVertexAttrib4Nub) numFailed++;
	_ptrc_glVertexAttrib4Nubv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4Nubv");
	if(!_ptrc_glVertexAttrib4Nubv) numFailed++;
	_ptrc_glVertexAttrib4Nuiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4Nuiv");
	if(!_ptrc_glVertexAttrib4Nuiv) numFailed++;
	_ptrc_glVertexAttrib4Nusv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4Nusv");
	if(!_ptrc_glVertexAttrib4Nusv) numFailed++;
	_ptrc_glVertexAttrib4bv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttrib4bv");
	if(!_ptrc_glVertexAttrib4bv) numFailed++;
	_ptrc_glVertexAttrib4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttrib4d");
	if(!_ptrc_glVertexAttrib4d) numFailed++;
	_ptrc_glVertexAttrib4dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttrib4dv");
	if(!_ptrc_glVertexAttrib4dv) numFailed++;
	_ptrc_glVertexAttrib4f = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glVertexAttrib4f");
	if(!_ptrc_glVertexAttrib4f) numFailed++;
	_ptrc_glVertexAttrib4fv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glVertexAttrib4fv");
	if(!_ptrc_glVertexAttrib4fv) numFailed++;
	_ptrc_glVertexAttrib4iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttrib4iv");
	if(!_ptrc_glVertexAttrib4iv) numFailed++;
	_ptrc_glVertexAttrib4s = (void (CODEGEN_FUNCPTR *)(GLuint, GLshort, GLshort, GLshort, GLshort))IntGetProcAddress("glVertexAttrib4s");
	if(!_ptrc_glVertexAttrib4s) numFailed++;
	_ptrc_glVertexAttrib4sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttrib4sv");
	if(!_ptrc_glVertexAttrib4sv) numFailed++;
	_ptrc_glVertexAttrib4ubv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttrib4ubv");
	if(!_ptrc_glVertexAttrib4ubv) numFailed++;
	_ptrc_glVertexAttrib4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttrib4uiv");
	if(!_ptrc_glVertexAttrib4uiv) numFailed++;
	_ptrc_glVertexAttrib4usv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttrib4usv");
	if(!_ptrc_glVertexAttrib4usv) numFailed++;
	_ptrc_glVertexAttribPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribPointer");
	if(!_ptrc_glVertexAttribPointer) numFailed++;
	_ptrc_glUniformMatrix2x3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2x3fv");
	if(!_ptrc_glUniformMatrix2x3fv) numFailed++;
	_ptrc_glUniformMatrix2x4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix2x4fv");
	if(!_ptrc_glUniformMatrix2x4fv) numFailed++;
	_ptrc_glUniformMatrix3x2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3x2fv");
	if(!_ptrc_glUniformMatrix3x2fv) numFailed++;
	_ptrc_glUniformMatrix3x4fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix3x4fv");
	if(!_ptrc_glUniformMatrix3x4fv) numFailed++;
	_ptrc_glUniformMatrix4x2fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4x2fv");
	if(!_ptrc_glUniformMatrix4x2fv) numFailed++;
	_ptrc_glUniformMatrix4x3fv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glUniformMatrix4x3fv");
	if(!_ptrc_glUniformMatrix4x3fv) numFailed++;
	_ptrc_glBeginConditionalRender = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBeginConditionalRender");
	if(!_ptrc_glBeginConditionalRender) numFailed++;
	_ptrc_glBeginTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glBeginTransformFeedback");
	if(!_ptrc_glBeginTransformFeedback) numFailed++;
	_ptrc_glBindBufferBase = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBindBufferBase");
	if(!_ptrc_glBindBufferBase) numFailed++;
	_ptrc_glBindBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glBindBufferRange");
	if(!_ptrc_glBindBufferRange) numFailed++;
	_ptrc_glBindFragDataLocation = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocation");
	if(!_ptrc_glBindFragDataLocation) numFailed++;
	_ptrc_glBindFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindFramebuffer");
	if(!_ptrc_glBindFramebuffer) numFailed++;
	_ptrc_glBindRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindRenderbuffer");
	if(!_ptrc_glBindRenderbuffer) numFailed++;
	_ptrc_glBindVertexArray = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindVertexArray");
	if(!_ptrc_glBindVertexArray) numFailed++;
	_ptrc_glBlitFramebuffer = (void (CODEGEN_FUNCPTR *)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum))IntGetProcAddress("glBlitFramebuffer");
	if(!_ptrc_glBlitFramebuffer) numFailed++;
	_ptrc_glCheckFramebufferStatus = (GLenum (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glCheckFramebufferStatus");
	if(!_ptrc_glCheckFramebufferStatus) numFailed++;
	_ptrc_glClampColor = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum))IntGetProcAddress("glClampColor");
	if(!_ptrc_glClampColor) numFailed++;
	_ptrc_glClearBufferfi = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLfloat, GLint))IntGetProcAddress("glClearBufferfi");
	if(!_ptrc_glClearBufferfi) numFailed++;
	_ptrc_glClearBufferfv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLfloat *))IntGetProcAddress("glClearBufferfv");
	if(!_ptrc_glClearBufferfv) numFailed++;
	_ptrc_glClearBufferiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLint *))IntGetProcAddress("glClearBufferiv");
	if(!_ptrc_glClearBufferiv) numFailed++;
	_ptrc_glClearBufferuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, const GLuint *))IntGetProcAddress("glClearBufferuiv");
	if(!_ptrc_glClearBufferuiv) numFailed++;
	_ptrc_glColorMaski = (void (CODEGEN_FUNCPTR *)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean))IntGetProcAddress("glColorMaski");
	if(!_ptrc_glColorMaski) numFailed++;
	_ptrc_glDeleteFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteFramebuffers");
	if(!_ptrc_glDeleteFramebuffers) numFailed++;
	_ptrc_glDeleteRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteRenderbuffers");
	if(!_ptrc_glDeleteRenderbuffers) numFailed++;
	_ptrc_glDeleteVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteVertexArrays");
	if(!_ptrc_glDeleteVertexArrays) numFailed++;
	_ptrc_glDisablei = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDisablei");
	if(!_ptrc_glDisablei) numFailed++;
	_ptrc_glEnablei = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEnablei");
	if(!_ptrc_glEnablei) numFailed++;
	_ptrc_glEndConditionalRender = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndConditionalRender");
	if(!_ptrc_glEndConditionalRender) numFailed++;
	_ptrc_glEndTransformFeedback = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glEndTransformFeedback");
	if(!_ptrc_glEndTransformFeedback) numFailed++;
	_ptrc_glFlushMappedBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr))IntGetProcAddress("glFlushMappedBufferRange");
	if(!_ptrc_glFlushMappedBufferRange) numFailed++;
	_ptrc_glFramebufferRenderbuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint))IntGetProcAddress("glFramebufferRenderbuffer");
	if(!_ptrc_glFramebufferRenderbuffer) numFailed++;
	_ptrc_glFramebufferTexture1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture1D");
	if(!_ptrc_glFramebufferTexture1D) numFailed++;
	_ptrc_glFramebufferTexture2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture2D");
	if(!_ptrc_glFramebufferTexture2D) numFailed++;
	_ptrc_glFramebufferTexture3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTexture3D");
	if(!_ptrc_glFramebufferTexture3D) numFailed++;
	_ptrc_glFramebufferTextureLayer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint, GLint))IntGetProcAddress("glFramebufferTextureLayer");
	if(!_ptrc_glFramebufferTextureLayer) numFailed++;
	_ptrc_glGenFramebuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenFramebuffers");
	if(!_ptrc_glGenFramebuffers) numFailed++;
	_ptrc_glGenRenderbuffers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenRenderbuffers");
	if(!_ptrc_glGenRenderbuffers) numFailed++;
	_ptrc_glGenVertexArrays = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenVertexArrays");
	if(!_ptrc_glGenVertexArrays) numFailed++;
	_ptrc_glGenerateMipmap = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glGenerateMipmap");
	if(!_ptrc_glGenerateMipmap) numFailed++;
	_ptrc_glGetBooleani_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLboolean *))IntGetProcAddress("glGetBooleani_v");
	if(!_ptrc_glGetBooleani_v) numFailed++;
	_ptrc_glGetFragDataLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataLocation");
	if(!_ptrc_glGetFragDataLocation) numFailed++;
	_ptrc_glGetFramebufferAttachmentParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!_ptrc_glGetFramebufferAttachmentParameteriv) numFailed++;
	_ptrc_glGetIntegeri_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint *))IntGetProcAddress("glGetIntegeri_v");
	if(!_ptrc_glGetIntegeri_v) numFailed++;
	_ptrc_glGetRenderbufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetRenderbufferParameteriv");
	if(!_ptrc_glGetRenderbufferParameteriv) numFailed++;
	_ptrc_glGetStringi = (const GLubyte * (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glGetStringi");
	if(!_ptrc_glGetStringi) numFailed++;
	_ptrc_glGetTexParameterIiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetTexParameterIiv");
	if(!_ptrc_glGetTexParameterIiv) numFailed++;
	_ptrc_glGetTexParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint *))IntGetProcAddress("glGetTexParameterIuiv");
	if(!_ptrc_glGetTexParameterIuiv) numFailed++;
	_ptrc_glGetTransformFeedbackVarying = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *))IntGetProcAddress("glGetTransformFeedbackVarying");
	if(!_ptrc_glGetTransformFeedbackVarying) numFailed++;
	_ptrc_glGetUniformuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint *))IntGetProcAddress("glGetUniformuiv");
	if(!_ptrc_glGetUniformuiv) numFailed++;
	_ptrc_glGetVertexAttribIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetVertexAttribIiv");
	if(!_ptrc_glGetVertexAttribIiv) numFailed++;
	_ptrc_glGetVertexAttribIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetVertexAttribIuiv");
	if(!_ptrc_glGetVertexAttribIuiv) numFailed++;
	_ptrc_glIsEnabledi = (GLboolean (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glIsEnabledi");
	if(!_ptrc_glIsEnabledi) numFailed++;
	_ptrc_glIsFramebuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsFramebuffer");
	if(!_ptrc_glIsFramebuffer) numFailed++;
	_ptrc_glIsRenderbuffer = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsRenderbuffer");
	if(!_ptrc_glIsRenderbuffer) numFailed++;
	_ptrc_glIsVertexArray = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsVertexArray");
	if(!_ptrc_glIsVertexArray) numFailed++;
	_ptrc_glMapBufferRange = (void * (CODEGEN_FUNCPTR *)(GLenum, GLintptr, GLsizeiptr, GLbitfield))IntGetProcAddress("glMapBufferRange");
	if(!_ptrc_glMapBufferRange) numFailed++;
	_ptrc_glRenderbufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorage");
	if(!_ptrc_glRenderbufferStorage) numFailed++;
	_ptrc_glRenderbufferStorageMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glRenderbufferStorageMultisample");
	if(!_ptrc_glRenderbufferStorageMultisample) numFailed++;
	_ptrc_glTexParameterIiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLint *))IntGetProcAddress("glTexParameterIiv");
	if(!_ptrc_glTexParameterIiv) numFailed++;
	_ptrc_glTexParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLuint *))IntGetProcAddress("glTexParameterIuiv");
	if(!_ptrc_glTexParameterIuiv) numFailed++;
	_ptrc_glTransformFeedbackVaryings = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, GLenum))IntGetProcAddress("glTransformFeedbackVaryings");
	if(!_ptrc_glTransformFeedbackVaryings) numFailed++;
	_ptrc_glUniform1ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint))IntGetProcAddress("glUniform1ui");
	if(!_ptrc_glUniform1ui) numFailed++;
	_ptrc_glUniform1uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform1uiv");
	if(!_ptrc_glUniform1uiv) numFailed++;
	_ptrc_glUniform2ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint))IntGetProcAddress("glUniform2ui");
	if(!_ptrc_glUniform2ui) numFailed++;
	_ptrc_glUniform2uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform2uiv");
	if(!_ptrc_glUniform2uiv) numFailed++;
	_ptrc_glUniform3ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform3ui");
	if(!_ptrc_glUniform3ui) numFailed++;
	_ptrc_glUniform3uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform3uiv");
	if(!_ptrc_glUniform3uiv) numFailed++;
	_ptrc_glUniform4ui = (void (CODEGEN_FUNCPTR *)(GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glUniform4ui");
	if(!_ptrc_glUniform4ui) numFailed++;
	_ptrc_glUniform4uiv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLuint *))IntGetProcAddress("glUniform4uiv");
	if(!_ptrc_glUniform4uiv) numFailed++;
	_ptrc_glVertexAttribI1i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glVertexAttribI1i");
	if(!_ptrc_glVertexAttribI1i) numFailed++;
	_ptrc_glVertexAttribI1iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI1iv");
	if(!_ptrc_glVertexAttribI1iv) numFailed++;
	_ptrc_glVertexAttribI1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribI1ui");
	if(!_ptrc_glVertexAttribI1ui) numFailed++;
	_ptrc_glVertexAttribI1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI1uiv");
	if(!_ptrc_glVertexAttribI1uiv) numFailed++;
	_ptrc_glVertexAttribI2i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glVertexAttribI2i");
	if(!_ptrc_glVertexAttribI2i) numFailed++;
	_ptrc_glVertexAttribI2iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI2iv");
	if(!_ptrc_glVertexAttribI2iv) numFailed++;
	_ptrc_glVertexAttribI2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI2ui");
	if(!_ptrc_glVertexAttribI2ui) numFailed++;
	_ptrc_glVertexAttribI2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI2uiv");
	if(!_ptrc_glVertexAttribI2uiv) numFailed++;
	_ptrc_glVertexAttribI3i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glVertexAttribI3i");
	if(!_ptrc_glVertexAttribI3i) numFailed++;
	_ptrc_glVertexAttribI3iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI3iv");
	if(!_ptrc_glVertexAttribI3iv) numFailed++;
	_ptrc_glVertexAttribI3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI3ui");
	if(!_ptrc_glVertexAttribI3ui) numFailed++;
	_ptrc_glVertexAttribI3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI3uiv");
	if(!_ptrc_glVertexAttribI3uiv) numFailed++;
	_ptrc_glVertexAttribI4bv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLbyte *))IntGetProcAddress("glVertexAttribI4bv");
	if(!_ptrc_glVertexAttribI4bv) numFailed++;
	_ptrc_glVertexAttribI4i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glVertexAttribI4i");
	if(!_ptrc_glVertexAttribI4i) numFailed++;
	_ptrc_glVertexAttribI4iv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glVertexAttribI4iv");
	if(!_ptrc_glVertexAttribI4iv) numFailed++;
	_ptrc_glVertexAttribI4sv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLshort *))IntGetProcAddress("glVertexAttribI4sv");
	if(!_ptrc_glVertexAttribI4sv) numFailed++;
	_ptrc_glVertexAttribI4ubv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLubyte *))IntGetProcAddress("glVertexAttribI4ubv");
	if(!_ptrc_glVertexAttribI4ubv) numFailed++;
	_ptrc_glVertexAttribI4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glVertexAttribI4ui");
	if(!_ptrc_glVertexAttribI4ui) numFailed++;
	_ptrc_glVertexAttribI4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLuint *))IntGetProcAddress("glVertexAttribI4uiv");
	if(!_ptrc_glVertexAttribI4uiv) numFailed++;
	_ptrc_glVertexAttribI4usv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLushort *))IntGetProcAddress("glVertexAttribI4usv");
	if(!_ptrc_glVertexAttribI4usv) numFailed++;
	_ptrc_glVertexAttribIPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribIPointer");
	if(!_ptrc_glVertexAttribIPointer) numFailed++;
	_ptrc_glCopyBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr))IntGetProcAddress("glCopyBufferSubData");
	if(!_ptrc_glCopyBufferSubData) numFailed++;
	_ptrc_glDrawArraysInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei))IntGetProcAddress("glDrawArraysInstanced");
	if(!_ptrc_glDrawArraysInstanced) numFailed++;
	_ptrc_glDrawElementsInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei))IntGetProcAddress("glDrawElementsInstanced");
	if(!_ptrc_glDrawElementsInstanced) numFailed++;
	_ptrc_glGetActiveUniformBlockName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformBlockName");
	if(!_ptrc_glGetActiveUniformBlockName) numFailed++;
	_ptrc_glGetActiveUniformBlockiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformBlockiv");
	if(!_ptrc_glGetActiveUniformBlockiv) numFailed++;
	_ptrc_glGetActiveUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveUniformName");
	if(!_ptrc_glGetActiveUniformName) numFailed++;
	_ptrc_glGetActiveUniformsiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, GLenum, GLint *))IntGetProcAddress("glGetActiveUniformsiv");
	if(!_ptrc_glGetActiveUniformsiv) numFailed++;
	_ptrc_glGetUniformBlockIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetUniformBlockIndex");
	if(!_ptrc_glGetUniformBlockIndex) numFailed++;
	_ptrc_glGetUniformIndices = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLchar *const*, GLuint *))IntGetProcAddress("glGetUniformIndices");
	if(!_ptrc_glGetUniformIndices) numFailed++;
	_ptrc_glPrimitiveRestartIndex = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glPrimitiveRestartIndex");
	if(!_ptrc_glPrimitiveRestartIndex) numFailed++;
	_ptrc_glTexBuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint))IntGetProcAddress("glTexBuffer");
	if(!_ptrc_glTexBuffer) numFailed++;
	_ptrc_glUniformBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glUniformBlockBinding");
	if(!_ptrc_glUniformBlockBinding) numFailed++;
	_ptrc_glClientWaitSync = (GLenum (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glClientWaitSync");
	if(!_ptrc_glClientWaitSync) numFailed++;
	_ptrc_glDeleteSync = (void (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glDeleteSync");
	if(!_ptrc_glDeleteSync) numFailed++;
	_ptrc_glDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLint))IntGetProcAddress("glDrawElementsBaseVertex");
	if(!_ptrc_glDrawElementsBaseVertex) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const GLvoid *, GLsizei, GLint))IntGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!_ptrc_glDrawElementsInstancedBaseVertex) numFailed++;
	_ptrc_glDrawRangeElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *, GLint))IntGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!_ptrc_glDrawRangeElementsBaseVertex) numFailed++;
	_ptrc_glFenceSync = (GLsync (CODEGEN_FUNCPTR *)(GLenum, GLbitfield))IntGetProcAddress("glFenceSync");
	if(!_ptrc_glFenceSync) numFailed++;
	_ptrc_glFramebufferTexture = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLint))IntGetProcAddress("glFramebufferTexture");
	if(!_ptrc_glFramebufferTexture) numFailed++;
	_ptrc_glGetBufferParameteri64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint64 *))IntGetProcAddress("glGetBufferParameteri64v");
	if(!_ptrc_glGetBufferParameteri64v) numFailed++;
	_ptrc_glGetInteger64i_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLint64 *))IntGetProcAddress("glGetInteger64i_v");
	if(!_ptrc_glGetInteger64i_v) numFailed++;
	_ptrc_glGetInteger64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLint64 *))IntGetProcAddress("glGetInteger64v");
	if(!_ptrc_glGetInteger64v) numFailed++;
	_ptrc_glGetMultisamplefv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetMultisamplefv");
	if(!_ptrc_glGetMultisamplefv) numFailed++;
	_ptrc_glGetSynciv = (void (CODEGEN_FUNCPTR *)(GLsync, GLenum, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetSynciv");
	if(!_ptrc_glGetSynciv) numFailed++;
	_ptrc_glIsSync = (GLboolean (CODEGEN_FUNCPTR *)(GLsync))IntGetProcAddress("glIsSync");
	if(!_ptrc_glIsSync) numFailed++;
	_ptrc_glMultiDrawElementsBaseVertex = (void (CODEGEN_FUNCPTR *)(GLenum, const GLsizei *, GLenum, const GLvoid *const*, GLsizei, const GLint *))IntGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!_ptrc_glMultiDrawElementsBaseVertex) numFailed++;
	_ptrc_glProvokingVertex = (void (CODEGEN_FUNCPTR *)(GLenum))IntGetProcAddress("glProvokingVertex");
	if(!_ptrc_glProvokingVertex) numFailed++;
	_ptrc_glSampleMaski = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield))IntGetProcAddress("glSampleMaski");
	if(!_ptrc_glSampleMaski) numFailed++;
	_ptrc_glTexImage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage2DMultisample");
	if(!_ptrc_glTexImage2DMultisample) numFailed++;
	_ptrc_glTexImage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLint, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexImage3DMultisample");
	if(!_ptrc_glTexImage3DMultisample) numFailed++;
	_ptrc_glWaitSync = (void (CODEGEN_FUNCPTR *)(GLsync, GLbitfield, GLuint64))IntGetProcAddress("glWaitSync");
	if(!_ptrc_glWaitSync) numFailed++;
	_ptrc_glBindFragDataLocationIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint, const GLchar *))IntGetProcAddress("glBindFragDataLocationIndexed");
	if(!_ptrc_glBindFragDataLocationIndexed) numFailed++;
	_ptrc_glBindSampler = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glBindSampler");
	if(!_ptrc_glBindSampler) numFailed++;
	_ptrc_glDeleteSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteSamplers");
	if(!_ptrc_glDeleteSamplers) numFailed++;
	_ptrc_glGenSamplers = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenSamplers");
	if(!_ptrc_glGenSamplers) numFailed++;
	_ptrc_glGetFragDataIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, const GLchar *))IntGetProcAddress("glGetFragDataIndex");
	if(!_ptrc_glGetFragDataIndex) numFailed++;
	_ptrc_glGetQueryObjecti64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint64 *))IntGetProcAddress("glGetQueryObjecti64v");
	if(!_ptrc_glGetQueryObjecti64v) numFailed++;
	_ptrc_glGetQueryObjectui64v = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint64 *))IntGetProcAddress("glGetQueryObjectui64v");
	if(!_ptrc_glGetQueryObjectui64v) numFailed++;
	_ptrc_glGetSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameterIiv");
	if(!_ptrc_glGetSamplerParameterIiv) numFailed++;
	_ptrc_glGetSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint *))IntGetProcAddress("glGetSamplerParameterIuiv");
	if(!_ptrc_glGetSamplerParameterIuiv) numFailed++;
	_ptrc_glGetSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat *))IntGetProcAddress("glGetSamplerParameterfv");
	if(!_ptrc_glGetSamplerParameterfv) numFailed++;
	_ptrc_glGetSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetSamplerParameteriv");
	if(!_ptrc_glGetSamplerParameteriv) numFailed++;
	_ptrc_glIsSampler = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsSampler");
	if(!_ptrc_glIsSampler) numFailed++;
	_ptrc_glQueryCounter = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glQueryCounter");
	if(!_ptrc_glQueryCounter) numFailed++;
	_ptrc_glSamplerParameterIiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameterIiv");
	if(!_ptrc_glSamplerParameterIiv) numFailed++;
	_ptrc_glSamplerParameterIuiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLuint *))IntGetProcAddress("glSamplerParameterIuiv");
	if(!_ptrc_glSamplerParameterIuiv) numFailed++;
	_ptrc_glSamplerParameterf = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLfloat))IntGetProcAddress("glSamplerParameterf");
	if(!_ptrc_glSamplerParameterf) numFailed++;
	_ptrc_glSamplerParameterfv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLfloat *))IntGetProcAddress("glSamplerParameterfv");
	if(!_ptrc_glSamplerParameterfv) numFailed++;
	_ptrc_glSamplerParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glSamplerParameteri");
	if(!_ptrc_glSamplerParameteri) numFailed++;
	_ptrc_glSamplerParameteriv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLint *))IntGetProcAddress("glSamplerParameteriv");
	if(!_ptrc_glSamplerParameteriv) numFailed++;
	_ptrc_glVertexAttribDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribDivisor");
	if(!_ptrc_glVertexAttribDivisor) numFailed++;
	_ptrc_glVertexAttribP1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP1ui");
	if(!_ptrc_glVertexAttribP1ui) numFailed++;
	_ptrc_glVertexAttribP1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP1uiv");
	if(!_ptrc_glVertexAttribP1uiv) numFailed++;
	_ptrc_glVertexAttribP2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP2ui");
	if(!_ptrc_glVertexAttribP2ui) numFailed++;
	_ptrc_glVertexAttribP2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP2uiv");
	if(!_ptrc_glVertexAttribP2uiv) numFailed++;
	_ptrc_glVertexAttribP3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP3ui");
	if(!_ptrc_glVertexAttribP3ui) numFailed++;
	_ptrc_glVertexAttribP3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP3uiv");
	if(!_ptrc_glVertexAttribP3uiv) numFailed++;
	_ptrc_glVertexAttribP4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribP4ui");
	if(!_ptrc_glVertexAttribP4ui) numFailed++;
	_ptrc_glVertexAttribP4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLboolean, const GLuint *))IntGetProcAddress("glVertexAttribP4uiv");
	if(!_ptrc_glVertexAttribP4uiv) numFailed++;
	_ptrc_glBeginQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glBeginQueryIndexed");
	if(!_ptrc_glBeginQueryIndexed) numFailed++;
	_ptrc_glBindTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glBindTransformFeedback");
	if(!_ptrc_glBindTransformFeedback) numFailed++;
	_ptrc_glBlendEquationSeparatei = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendEquationSeparatei");
	if(!_ptrc_glBlendEquationSeparatei) numFailed++;
	_ptrc_glBlendEquationi = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum))IntGetProcAddress("glBlendEquationi");
	if(!_ptrc_glBlendEquationi) numFailed++;
	_ptrc_glBlendFuncSeparatei = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLenum, GLenum))IntGetProcAddress("glBlendFuncSeparatei");
	if(!_ptrc_glBlendFuncSeparatei) numFailed++;
	_ptrc_glBlendFunci = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum))IntGetProcAddress("glBlendFunci");
	if(!_ptrc_glBlendFunci) numFailed++;
	_ptrc_glDeleteTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteTransformFeedbacks");
	if(!_ptrc_glDeleteTransformFeedbacks) numFailed++;
	_ptrc_glDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const GLvoid *))IntGetProcAddress("glDrawArraysIndirect");
	if(!_ptrc_glDrawArraysIndirect) numFailed++;
	_ptrc_glDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const GLvoid *))IntGetProcAddress("glDrawElementsIndirect");
	if(!_ptrc_glDrawElementsIndirect) numFailed++;
	_ptrc_glDrawTransformFeedback = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glDrawTransformFeedback");
	if(!_ptrc_glDrawTransformFeedback) numFailed++;
	_ptrc_glDrawTransformFeedbackStream = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint))IntGetProcAddress("glDrawTransformFeedbackStream");
	if(!_ptrc_glDrawTransformFeedbackStream) numFailed++;
	_ptrc_glEndQueryIndexed = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glEndQueryIndexed");
	if(!_ptrc_glEndQueryIndexed) numFailed++;
	_ptrc_glGenTransformFeedbacks = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenTransformFeedbacks");
	if(!_ptrc_glGenTransformFeedbacks) numFailed++;
	_ptrc_glGetActiveSubroutineName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineName");
	if(!_ptrc_glGetActiveSubroutineName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetActiveSubroutineUniformName");
	if(!_ptrc_glGetActiveSubroutineUniformName) numFailed++;
	_ptrc_glGetActiveSubroutineUniformiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveSubroutineUniformiv");
	if(!_ptrc_glGetActiveSubroutineUniformiv) numFailed++;
	_ptrc_glGetProgramStageiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramStageiv");
	if(!_ptrc_glGetProgramStageiv) numFailed++;
	_ptrc_glGetQueryIndexediv = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLenum, GLint *))IntGetProcAddress("glGetQueryIndexediv");
	if(!_ptrc_glGetQueryIndexediv) numFailed++;
	_ptrc_glGetSubroutineIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineIndex");
	if(!_ptrc_glGetSubroutineIndex) numFailed++;
	_ptrc_glGetSubroutineUniformLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetSubroutineUniformLocation");
	if(!_ptrc_glGetSubroutineUniformLocation) numFailed++;
	_ptrc_glGetUniformSubroutineuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLuint *))IntGetProcAddress("glGetUniformSubroutineuiv");
	if(!_ptrc_glGetUniformSubroutineuiv) numFailed++;
	_ptrc_glGetUniformdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble *))IntGetProcAddress("glGetUniformdv");
	if(!_ptrc_glGetUniformdv) numFailed++;
	_ptrc_glIsTransformFeedback = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsTransformFeedback");
	if(!_ptrc_glIsTransformFeedback) numFailed++;
	_ptrc_glMinSampleShading = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glMinSampleShading");
	if(!_ptrc_glMinSampleShading) numFailed++;
	_ptrc_glPatchParameterfv = (void (CODEGEN_FUNCPTR *)(GLenum, const GLfloat *))IntGetProcAddress("glPatchParameterfv");
	if(!_ptrc_glPatchParameterfv) numFailed++;
	_ptrc_glPatchParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLint))IntGetProcAddress("glPatchParameteri");
	if(!_ptrc_glPatchParameteri) numFailed++;
	_ptrc_glPauseTransformFeedback = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPauseTransformFeedback");
	if(!_ptrc_glPauseTransformFeedback) numFailed++;
	_ptrc_glResumeTransformFeedback = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glResumeTransformFeedback");
	if(!_ptrc_glResumeTransformFeedback) numFailed++;
	_ptrc_glUniform1d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble))IntGetProcAddress("glUniform1d");
	if(!_ptrc_glUniform1d) numFailed++;
	_ptrc_glUniform1dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform1dv");
	if(!_ptrc_glUniform1dv) numFailed++;
	_ptrc_glUniform2d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble))IntGetProcAddress("glUniform2d");
	if(!_ptrc_glUniform2d) numFailed++;
	_ptrc_glUniform2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform2dv");
	if(!_ptrc_glUniform2dv) numFailed++;
	_ptrc_glUniform3d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform3d");
	if(!_ptrc_glUniform3d) numFailed++;
	_ptrc_glUniform3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform3dv");
	if(!_ptrc_glUniform3dv) numFailed++;
	_ptrc_glUniform4d = (void (CODEGEN_FUNCPTR *)(GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glUniform4d");
	if(!_ptrc_glUniform4d) numFailed++;
	_ptrc_glUniform4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, const GLdouble *))IntGetProcAddress("glUniform4dv");
	if(!_ptrc_glUniform4dv) numFailed++;
	_ptrc_glUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2dv");
	if(!_ptrc_glUniformMatrix2dv) numFailed++;
	_ptrc_glUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x3dv");
	if(!_ptrc_glUniformMatrix2x3dv) numFailed++;
	_ptrc_glUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix2x4dv");
	if(!_ptrc_glUniformMatrix2x4dv) numFailed++;
	_ptrc_glUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3dv");
	if(!_ptrc_glUniformMatrix3dv) numFailed++;
	_ptrc_glUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x2dv");
	if(!_ptrc_glUniformMatrix3x2dv) numFailed++;
	_ptrc_glUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix3x4dv");
	if(!_ptrc_glUniformMatrix3x4dv) numFailed++;
	_ptrc_glUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4dv");
	if(!_ptrc_glUniformMatrix4dv) numFailed++;
	_ptrc_glUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x2dv");
	if(!_ptrc_glUniformMatrix4x2dv) numFailed++;
	_ptrc_glUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glUniformMatrix4x3dv");
	if(!_ptrc_glUniformMatrix4x3dv) numFailed++;
	_ptrc_glUniformSubroutinesuiv = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLuint *))IntGetProcAddress("glUniformSubroutinesuiv");
	if(!_ptrc_glUniformSubroutinesuiv) numFailed++;
	_ptrc_glActiveShaderProgram = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glActiveShaderProgram");
	if(!_ptrc_glActiveShaderProgram) numFailed++;
	_ptrc_glBindProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glBindProgramPipeline");
	if(!_ptrc_glBindProgramPipeline) numFailed++;
	_ptrc_glClearDepthf = (void (CODEGEN_FUNCPTR *)(GLfloat))IntGetProcAddress("glClearDepthf");
	if(!_ptrc_glClearDepthf) numFailed++;
	_ptrc_glCreateShaderProgramv = (GLuint (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLchar *const*))IntGetProcAddress("glCreateShaderProgramv");
	if(!_ptrc_glCreateShaderProgramv) numFailed++;
	_ptrc_glDeleteProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *))IntGetProcAddress("glDeleteProgramPipelines");
	if(!_ptrc_glDeleteProgramPipelines) numFailed++;
	_ptrc_glDepthRangeArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLdouble *))IntGetProcAddress("glDepthRangeArrayv");
	if(!_ptrc_glDepthRangeArrayv) numFailed++;
	_ptrc_glDepthRangeIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glDepthRangeIndexed");
	if(!_ptrc_glDepthRangeIndexed) numFailed++;
	_ptrc_glDepthRangef = (void (CODEGEN_FUNCPTR *)(GLfloat, GLfloat))IntGetProcAddress("glDepthRangef");
	if(!_ptrc_glDepthRangef) numFailed++;
	_ptrc_glGenProgramPipelines = (void (CODEGEN_FUNCPTR *)(GLsizei, GLuint *))IntGetProcAddress("glGenProgramPipelines");
	if(!_ptrc_glGenProgramPipelines) numFailed++;
	_ptrc_glGetDoublei_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLdouble *))IntGetProcAddress("glGetDoublei_v");
	if(!_ptrc_glGetDoublei_v) numFailed++;
	_ptrc_glGetFloati_v = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLfloat *))IntGetProcAddress("glGetFloati_v");
	if(!_ptrc_glGetFloati_v) numFailed++;
	_ptrc_glGetProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLenum *, GLvoid *))IntGetProcAddress("glGetProgramBinary");
	if(!_ptrc_glGetProgramBinary) numFailed++;
	_ptrc_glGetProgramPipelineInfoLog = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramPipelineInfoLog");
	if(!_ptrc_glGetProgramPipelineInfoLog) numFailed++;
	_ptrc_glGetProgramPipelineiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint *))IntGetProcAddress("glGetProgramPipelineiv");
	if(!_ptrc_glGetProgramPipelineiv) numFailed++;
	_ptrc_glGetShaderPrecisionFormat = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *, GLint *))IntGetProcAddress("glGetShaderPrecisionFormat");
	if(!_ptrc_glGetShaderPrecisionFormat) numFailed++;
	_ptrc_glGetVertexAttribLdv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLdouble *))IntGetProcAddress("glGetVertexAttribLdv");
	if(!_ptrc_glGetVertexAttribLdv) numFailed++;
	_ptrc_glIsProgramPipeline = (GLboolean (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glIsProgramPipeline");
	if(!_ptrc_glIsProgramPipeline) numFailed++;
	_ptrc_glProgramBinary = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLvoid *, GLsizei))IntGetProcAddress("glProgramBinary");
	if(!_ptrc_glProgramBinary) numFailed++;
	_ptrc_glProgramParameteri = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint))IntGetProcAddress("glProgramParameteri");
	if(!_ptrc_glProgramParameteri) numFailed++;
	_ptrc_glProgramUniform1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble))IntGetProcAddress("glProgramUniform1d");
	if(!_ptrc_glProgramUniform1d) numFailed++;
	_ptrc_glProgramUniform1dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform1dv");
	if(!_ptrc_glProgramUniform1dv) numFailed++;
	_ptrc_glProgramUniform1f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat))IntGetProcAddress("glProgramUniform1f");
	if(!_ptrc_glProgramUniform1f) numFailed++;
	_ptrc_glProgramUniform1fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform1fv");
	if(!_ptrc_glProgramUniform1fv) numFailed++;
	_ptrc_glProgramUniform1i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint))IntGetProcAddress("glProgramUniform1i");
	if(!_ptrc_glProgramUniform1i) numFailed++;
	_ptrc_glProgramUniform1iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform1iv");
	if(!_ptrc_glProgramUniform1iv) numFailed++;
	_ptrc_glProgramUniform1ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint))IntGetProcAddress("glProgramUniform1ui");
	if(!_ptrc_glProgramUniform1ui) numFailed++;
	_ptrc_glProgramUniform1uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform1uiv");
	if(!_ptrc_glProgramUniform1uiv) numFailed++;
	_ptrc_glProgramUniform2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform2d");
	if(!_ptrc_glProgramUniform2d) numFailed++;
	_ptrc_glProgramUniform2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform2dv");
	if(!_ptrc_glProgramUniform2dv) numFailed++;
	_ptrc_glProgramUniform2f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform2f");
	if(!_ptrc_glProgramUniform2f) numFailed++;
	_ptrc_glProgramUniform2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform2fv");
	if(!_ptrc_glProgramUniform2fv) numFailed++;
	_ptrc_glProgramUniform2i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform2i");
	if(!_ptrc_glProgramUniform2i) numFailed++;
	_ptrc_glProgramUniform2iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform2iv");
	if(!_ptrc_glProgramUniform2iv) numFailed++;
	_ptrc_glProgramUniform2ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint))IntGetProcAddress("glProgramUniform2ui");
	if(!_ptrc_glProgramUniform2ui) numFailed++;
	_ptrc_glProgramUniform2uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform2uiv");
	if(!_ptrc_glProgramUniform2uiv) numFailed++;
	_ptrc_glProgramUniform3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform3d");
	if(!_ptrc_glProgramUniform3d) numFailed++;
	_ptrc_glProgramUniform3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform3dv");
	if(!_ptrc_glProgramUniform3dv) numFailed++;
	_ptrc_glProgramUniform3f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform3f");
	if(!_ptrc_glProgramUniform3f) numFailed++;
	_ptrc_glProgramUniform3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform3fv");
	if(!_ptrc_glProgramUniform3fv) numFailed++;
	_ptrc_glProgramUniform3i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform3i");
	if(!_ptrc_glProgramUniform3i) numFailed++;
	_ptrc_glProgramUniform3iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform3iv");
	if(!_ptrc_glProgramUniform3iv) numFailed++;
	_ptrc_glProgramUniform3ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform3ui");
	if(!_ptrc_glProgramUniform3ui) numFailed++;
	_ptrc_glProgramUniform3uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform3uiv");
	if(!_ptrc_glProgramUniform3uiv) numFailed++;
	_ptrc_glProgramUniform4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glProgramUniform4d");
	if(!_ptrc_glProgramUniform4d) numFailed++;
	_ptrc_glProgramUniform4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLdouble *))IntGetProcAddress("glProgramUniform4dv");
	if(!_ptrc_glProgramUniform4dv) numFailed++;
	_ptrc_glProgramUniform4f = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glProgramUniform4f");
	if(!_ptrc_glProgramUniform4f) numFailed++;
	_ptrc_glProgramUniform4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLfloat *))IntGetProcAddress("glProgramUniform4fv");
	if(!_ptrc_glProgramUniform4fv) numFailed++;
	_ptrc_glProgramUniform4i = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLint))IntGetProcAddress("glProgramUniform4i");
	if(!_ptrc_glProgramUniform4i) numFailed++;
	_ptrc_glProgramUniform4iv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLint *))IntGetProcAddress("glProgramUniform4iv");
	if(!_ptrc_glProgramUniform4iv) numFailed++;
	_ptrc_glProgramUniform4ui = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glProgramUniform4ui");
	if(!_ptrc_glProgramUniform4ui) numFailed++;
	_ptrc_glProgramUniform4uiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, const GLuint *))IntGetProcAddress("glProgramUniform4uiv");
	if(!_ptrc_glProgramUniform4uiv) numFailed++;
	_ptrc_glProgramUniformMatrix2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2dv");
	if(!_ptrc_glProgramUniformMatrix2dv) numFailed++;
	_ptrc_glProgramUniformMatrix2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2fv");
	if(!_ptrc_glProgramUniformMatrix2fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x3dv");
	if(!_ptrc_glProgramUniformMatrix2x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x3fv");
	if(!_ptrc_glProgramUniformMatrix2x3fv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix2x4dv");
	if(!_ptrc_glProgramUniformMatrix2x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix2x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix2x4fv");
	if(!_ptrc_glProgramUniformMatrix2x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3dv");
	if(!_ptrc_glProgramUniformMatrix3dv) numFailed++;
	_ptrc_glProgramUniformMatrix3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3fv");
	if(!_ptrc_glProgramUniformMatrix3fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x2dv");
	if(!_ptrc_glProgramUniformMatrix3x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x2fv");
	if(!_ptrc_glProgramUniformMatrix3x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix3x4dv");
	if(!_ptrc_glProgramUniformMatrix3x4dv) numFailed++;
	_ptrc_glProgramUniformMatrix3x4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix3x4fv");
	if(!_ptrc_glProgramUniformMatrix3x4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4dv");
	if(!_ptrc_glProgramUniformMatrix4dv) numFailed++;
	_ptrc_glProgramUniformMatrix4fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4fv");
	if(!_ptrc_glProgramUniformMatrix4fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x2dv");
	if(!_ptrc_glProgramUniformMatrix4x2dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x2fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x2fv");
	if(!_ptrc_glProgramUniformMatrix4x2fv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3dv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLdouble *))IntGetProcAddress("glProgramUniformMatrix4x3dv");
	if(!_ptrc_glProgramUniformMatrix4x3dv) numFailed++;
	_ptrc_glProgramUniformMatrix4x3fv = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLsizei, GLboolean, const GLfloat *))IntGetProcAddress("glProgramUniformMatrix4x3fv");
	if(!_ptrc_glProgramUniformMatrix4x3fv) numFailed++;
	_ptrc_glReleaseShaderCompiler = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glReleaseShaderCompiler");
	if(!_ptrc_glReleaseShaderCompiler) numFailed++;
	_ptrc_glScissorArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLint *))IntGetProcAddress("glScissorArrayv");
	if(!_ptrc_glScissorArrayv) numFailed++;
	_ptrc_glScissorIndexed = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glScissorIndexed");
	if(!_ptrc_glScissorIndexed) numFailed++;
	_ptrc_glScissorIndexedv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLint *))IntGetProcAddress("glScissorIndexedv");
	if(!_ptrc_glScissorIndexedv) numFailed++;
	_ptrc_glShaderBinary = (void (CODEGEN_FUNCPTR *)(GLsizei, const GLuint *, GLenum, const GLvoid *, GLsizei))IntGetProcAddress("glShaderBinary");
	if(!_ptrc_glShaderBinary) numFailed++;
	_ptrc_glUseProgramStages = (void (CODEGEN_FUNCPTR *)(GLuint, GLbitfield, GLuint))IntGetProcAddress("glUseProgramStages");
	if(!_ptrc_glUseProgramStages) numFailed++;
	_ptrc_glValidateProgramPipeline = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glValidateProgramPipeline");
	if(!_ptrc_glValidateProgramPipeline) numFailed++;
	_ptrc_glVertexAttribL1d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble))IntGetProcAddress("glVertexAttribL1d");
	if(!_ptrc_glVertexAttribL1d) numFailed++;
	_ptrc_glVertexAttribL1dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL1dv");
	if(!_ptrc_glVertexAttribL1dv) numFailed++;
	_ptrc_glVertexAttribL2d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL2d");
	if(!_ptrc_glVertexAttribL2d) numFailed++;
	_ptrc_glVertexAttribL2dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL2dv");
	if(!_ptrc_glVertexAttribL2dv) numFailed++;
	_ptrc_glVertexAttribL3d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL3d");
	if(!_ptrc_glVertexAttribL3d) numFailed++;
	_ptrc_glVertexAttribL3dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL3dv");
	if(!_ptrc_glVertexAttribL3dv) numFailed++;
	_ptrc_glVertexAttribL4d = (void (CODEGEN_FUNCPTR *)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble))IntGetProcAddress("glVertexAttribL4d");
	if(!_ptrc_glVertexAttribL4d) numFailed++;
	_ptrc_glVertexAttribL4dv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLdouble *))IntGetProcAddress("glVertexAttribL4dv");
	if(!_ptrc_glVertexAttribL4dv) numFailed++;
	_ptrc_glVertexAttribLPointer = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLsizei, const GLvoid *))IntGetProcAddress("glVertexAttribLPointer");
	if(!_ptrc_glVertexAttribLPointer) numFailed++;
	_ptrc_glViewportArrayv = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLfloat *))IntGetProcAddress("glViewportArrayv");
	if(!_ptrc_glViewportArrayv) numFailed++;
	_ptrc_glViewportIndexedf = (void (CODEGEN_FUNCPTR *)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat))IntGetProcAddress("glViewportIndexedf");
	if(!_ptrc_glViewportIndexedf) numFailed++;
	_ptrc_glViewportIndexedfv = (void (CODEGEN_FUNCPTR *)(GLuint, const GLfloat *))IntGetProcAddress("glViewportIndexedfv");
	if(!_ptrc_glViewportIndexedfv) numFailed++;
	_ptrc_glBindImageTexture = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum))IntGetProcAddress("glBindImageTexture");
	if(!_ptrc_glBindImageTexture) numFailed++;
	_ptrc_glDrawArraysInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLint, GLsizei, GLsizei, GLuint))IntGetProcAddress("glDrawArraysInstancedBaseInstance");
	if(!_ptrc_glDrawArraysInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseInstance) numFailed++;
	_ptrc_glDrawElementsInstancedBaseVertexBaseInstance = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint))IntGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	if(!_ptrc_glDrawElementsInstancedBaseVertexBaseInstance) numFailed++;
	_ptrc_glDrawTransformFeedbackInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackInstanced");
	if(!_ptrc_glDrawTransformFeedbackInstanced) numFailed++;
	_ptrc_glDrawTransformFeedbackStreamInstanced = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLuint, GLsizei))IntGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	if(!_ptrc_glDrawTransformFeedbackStreamInstanced) numFailed++;
	_ptrc_glGetActiveAtomicCounterBufferiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLenum, GLint *))IntGetProcAddress("glGetActiveAtomicCounterBufferiv");
	if(!_ptrc_glGetActiveAtomicCounterBufferiv) numFailed++;
	_ptrc_glGetInternalformati64v = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, GLint64 *))IntGetProcAddress("glGetInternalformati64v");
	if(!_ptrc_glGetInternalformati64v) numFailed++;
	_ptrc_glMemoryBarrier = (void (CODEGEN_FUNCPTR *)(GLbitfield))IntGetProcAddress("glMemoryBarrier");
	if(!_ptrc_glMemoryBarrier) numFailed++;
	_ptrc_glTexStorage1D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei))IntGetProcAddress("glTexStorage1D");
	if(!_ptrc_glTexStorage1D) numFailed++;
	_ptrc_glTexStorage2D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei))IntGetProcAddress("glTexStorage2D");
	if(!_ptrc_glTexStorage2D) numFailed++;
	_ptrc_glTexStorage3D = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glTexStorage3D");
	if(!_ptrc_glTexStorage3D) numFailed++;
	_ptrc_glBindVertexBuffer = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLintptr, GLsizei))IntGetProcAddress("glBindVertexBuffer");
	if(!_ptrc_glBindVertexBuffer) numFailed++;
	_ptrc_glClearBufferData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferData");
	if(!_ptrc_glClearBufferData) numFailed++;
	_ptrc_glClearBufferSubData = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *))IntGetProcAddress("glClearBufferSubData");
	if(!_ptrc_glClearBufferSubData) numFailed++;
	_ptrc_glCopyImageSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glCopyImageSubData");
	if(!_ptrc_glCopyImageSubData) numFailed++;
	_ptrc_glDebugMessageCallback = (void (CODEGEN_FUNCPTR *)(GLDEBUGPROC, const void *))IntGetProcAddress("glDebugMessageCallback");
	if(!_ptrc_glDebugMessageCallback) numFailed++;
	_ptrc_glDebugMessageControl = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean))IntGetProcAddress("glDebugMessageControl");
	if(!_ptrc_glDebugMessageControl) numFailed++;
	_ptrc_glDebugMessageInsert = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *))IntGetProcAddress("glDebugMessageInsert");
	if(!_ptrc_glDebugMessageInsert) numFailed++;
	_ptrc_glDispatchCompute = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glDispatchCompute");
	if(!_ptrc_glDispatchCompute) numFailed++;
	_ptrc_glDispatchComputeIndirect = (void (CODEGEN_FUNCPTR *)(GLintptr))IntGetProcAddress("glDispatchComputeIndirect");
	if(!_ptrc_glDispatchComputeIndirect) numFailed++;
	_ptrc_glFramebufferParameteri = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint))IntGetProcAddress("glFramebufferParameteri");
	if(!_ptrc_glFramebufferParameteri) numFailed++;
	_ptrc_glGetDebugMessageLog = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *))IntGetProcAddress("glGetDebugMessageLog");
	if(!_ptrc_glGetDebugMessageLog) numFailed++;
	_ptrc_glGetFramebufferParameteriv = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLint *))IntGetProcAddress("glGetFramebufferParameteriv");
	if(!_ptrc_glGetFramebufferParameteriv) numFailed++;
	_ptrc_glGetObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectLabel");
	if(!_ptrc_glGetObjectLabel) numFailed++;
	_ptrc_glGetObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetObjectPtrLabel");
	if(!_ptrc_glGetObjectPtrLabel) numFailed++;
	_ptrc_glGetProgramInterfaceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLenum, GLint *))IntGetProcAddress("glGetProgramInterfaceiv");
	if(!_ptrc_glGetProgramInterfaceiv) numFailed++;
	_ptrc_glGetProgramResourceIndex = (GLuint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceIndex");
	if(!_ptrc_glGetProgramResourceIndex) numFailed++;
	_ptrc_glGetProgramResourceLocation = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocation");
	if(!_ptrc_glGetProgramResourceLocation) numFailed++;
	_ptrc_glGetProgramResourceLocationIndex = (GLint (CODEGEN_FUNCPTR *)(GLuint, GLenum, const GLchar *))IntGetProcAddress("glGetProgramResourceLocationIndex");
	if(!_ptrc_glGetProgramResourceLocationIndex) numFailed++;
	_ptrc_glGetProgramResourceName = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *))IntGetProcAddress("glGetProgramResourceName");
	if(!_ptrc_glGetProgramResourceName) numFailed++;
	_ptrc_glGetProgramResourceiv = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *))IntGetProcAddress("glGetProgramResourceiv");
	if(!_ptrc_glGetProgramResourceiv) numFailed++;
	_ptrc_glInvalidateBufferData = (void (CODEGEN_FUNCPTR *)(GLuint))IntGetProcAddress("glInvalidateBufferData");
	if(!_ptrc_glInvalidateBufferData) numFailed++;
	_ptrc_glInvalidateBufferSubData = (void (CODEGEN_FUNCPTR *)(GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glInvalidateBufferSubData");
	if(!_ptrc_glInvalidateBufferSubData) numFailed++;
	_ptrc_glInvalidateFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *))IntGetProcAddress("glInvalidateFramebuffer");
	if(!_ptrc_glInvalidateFramebuffer) numFailed++;
	_ptrc_glInvalidateSubFramebuffer = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei))IntGetProcAddress("glInvalidateSubFramebuffer");
	if(!_ptrc_glInvalidateSubFramebuffer) numFailed++;
	_ptrc_glInvalidateTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint))IntGetProcAddress("glInvalidateTexImage");
	if(!_ptrc_glInvalidateTexImage) numFailed++;
	_ptrc_glInvalidateTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei))IntGetProcAddress("glInvalidateTexSubImage");
	if(!_ptrc_glInvalidateTexSubImage) numFailed++;
	_ptrc_glMultiDrawArraysIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawArraysIndirect");
	if(!_ptrc_glMultiDrawArraysIndirect) numFailed++;
	_ptrc_glMultiDrawElementsIndirect = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, const void *, GLsizei, GLsizei))IntGetProcAddress("glMultiDrawElementsIndirect");
	if(!_ptrc_glMultiDrawElementsIndirect) numFailed++;
	_ptrc_glObjectLabel = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glObjectLabel");
	if(!_ptrc_glObjectLabel) numFailed++;
	_ptrc_glObjectPtrLabel = (void (CODEGEN_FUNCPTR *)(const void *, GLsizei, const GLchar *))IntGetProcAddress("glObjectPtrLabel");
	if(!_ptrc_glObjectPtrLabel) numFailed++;
	_ptrc_glPopDebugGroup = (void (CODEGEN_FUNCPTR *)())IntGetProcAddress("glPopDebugGroup");
	if(!_ptrc_glPopDebugGroup) numFailed++;
	_ptrc_glPushDebugGroup = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLchar *))IntGetProcAddress("glPushDebugGroup");
	if(!_ptrc_glPushDebugGroup) numFailed++;
	_ptrc_glShaderStorageBlockBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint, GLuint))IntGetProcAddress("glShaderStorageBlockBinding");
	if(!_ptrc_glShaderStorageBlockBinding) numFailed++;
	_ptrc_glTexBufferRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLenum, GLuint, GLintptr, GLsizeiptr))IntGetProcAddress("glTexBufferRange");
	if(!_ptrc_glTexBufferRange) numFailed++;
	_ptrc_glTexStorage2DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage2DMultisample");
	if(!_ptrc_glTexStorage2DMultisample) numFailed++;
	_ptrc_glTexStorage3DMultisample = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean))IntGetProcAddress("glTexStorage3DMultisample");
	if(!_ptrc_glTexStorage3DMultisample) numFailed++;
	_ptrc_glTextureView = (void (CODEGEN_FUNCPTR *)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint))IntGetProcAddress("glTextureView");
	if(!_ptrc_glTextureView) numFailed++;
	_ptrc_glVertexAttribBinding = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexAttribBinding");
	if(!_ptrc_glVertexAttribBinding) numFailed++;
	_ptrc_glVertexAttribFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLboolean, GLuint))IntGetProcAddress("glVertexAttribFormat");
	if(!_ptrc_glVertexAttribFormat) numFailed++;
	_ptrc_glVertexAttribIFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribIFormat");
	if(!_ptrc_glVertexAttribIFormat) numFailed++;
	_ptrc_glVertexAttribLFormat = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLuint))IntGetProcAddress("glVertexAttribLFormat");
	if(!_ptrc_glVertexAttribLFormat) numFailed++;
	_ptrc_glVertexBindingDivisor = (void (CODEGEN_FUNCPTR *)(GLuint, GLuint))IntGetProcAddress("glVertexBindingDivisor");
	if(!_ptrc_glVertexBindingDivisor) numFailed++;
	_ptrc_glBindBuffersBase = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindBuffersBase");
	if(!_ptrc_glBindBuffersBase) numFailed++;
	_ptrc_glBindBuffersRange = (void (CODEGEN_FUNCPTR *)(GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *))IntGetProcAddress("glBindBuffersRange");
	if(!_ptrc_glBindBuffersRange) numFailed++;
	_ptrc_glBindImageTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindImageTextures");
	if(!_ptrc_glBindImageTextures) numFailed++;
	_ptrc_glBindSamplers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindSamplers");
	if(!_ptrc_glBindSamplers) numFailed++;
	_ptrc_glBindTextures = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *))IntGetProcAddress("glBindTextures");
	if(!_ptrc_glBindTextures) numFailed++;
	_ptrc_glBindVertexBuffers = (void (CODEGEN_FUNCPTR *)(GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *))IntGetProcAddress("glBindVertexBuffers");
	if(!_ptrc_glBindVertexBuffers) numFailed++;
	_ptrc_glBufferStorage = (void (CODEGEN_FUNCPTR *)(GLenum, GLsizeiptr, const void *, GLbitfield))IntGetProcAddress("glBufferStorage");
	if(!_ptrc_glBufferStorage) numFailed++;
	_ptrc_glClearTexImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexImage");
	if(!_ptrc_glClearTexImage) numFailed++;
	_ptrc_glClearTexSubImage = (void (CODEGEN_FUNCPTR *)(GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *))IntGetProcAddress("glClearTexSubImage");
	if(!_ptrc_glClearTexSubImage) numFailed++;
	return numFailed;
}

typedef int (*PFN_LOADFUNCPOINTERS)();
typedef struct ogl_StrToExtMap_s
{
	char *extensionName;
	int *extensionVariable;
	PFN_LOADFUNCPOINTERS LoadExtension;
} ogl_StrToExtMap;

static ogl_StrToExtMap ExtensionMap[469] = {
	{"GL_ARB_imaging", &ogl_ext_ARB_imaging, Load_ARB_imaging},
	{"GL_ARB_vertex_array_object", &ogl_ext_ARB_vertex_array_object, Load_ARB_vertex_array_object},
	{"GL_ARB_texture_rg", &ogl_ext_ARB_texture_rg, NULL},
	{"GL_ARB_texture_compression_rgtc", &ogl_ext_ARB_texture_compression_rgtc, NULL},
	{"GL_ARB_map_buffer_range", &ogl_ext_ARB_map_buffer_range, Load_ARB_map_buffer_range},
	{"GL_ARB_half_float_vertex", &ogl_ext_ARB_half_float_vertex, NULL},
	{"GL_ARB_framebuffer_sRGB", &ogl_ext_ARB_framebuffer_sRGB, NULL},
	{"GL_ARB_framebuffer_object", &ogl_ext_ARB_framebuffer_object, Load_ARB_framebuffer_object},
	{"GL_ARB_depth_buffer_float", &ogl_ext_ARB_depth_buffer_float, NULL},
	{"GL_ARB_uniform_buffer_object", &ogl_ext_ARB_uniform_buffer_object, Load_ARB_uniform_buffer_object},
	{"GL_ARB_copy_buffer", &ogl_ext_ARB_copy_buffer, Load_ARB_copy_buffer},
	{"GL_ARB_depth_clamp", &ogl_ext_ARB_depth_clamp, NULL},
	{"GL_ARB_draw_elements_base_vertex", &ogl_ext_ARB_draw_elements_base_vertex, Load_ARB_draw_elements_base_vertex},
	{"GL_ARB_fragment_coord_conventions", &ogl_ext_ARB_fragment_coord_conventions, NULL},
	{"GL_ARB_provoking_vertex", &ogl_ext_ARB_provoking_vertex, Load_ARB_provoking_vertex},
	{"GL_ARB_seamless_cube_map", &ogl_ext_ARB_seamless_cube_map, NULL},
	{"GL_ARB_sync", &ogl_ext_ARB_sync, Load_ARB_sync},
	{"GL_ARB_texture_multisample", &ogl_ext_ARB_texture_multisample, Load_ARB_texture_multisample},
	{"GL_ARB_vertex_array_bgra", &ogl_ext_ARB_vertex_array_bgra, NULL},
	{"GL_ARB_texture_rgb10_a2ui", &ogl_ext_ARB_texture_rgb10_a2ui, NULL},
	{"GL_ARB_texture_swizzle", &ogl_ext_ARB_texture_swizzle, NULL},
	{"GL_ARB_timer_query", &ogl_ext_ARB_timer_query, Load_ARB_timer_query},
	{"GL_ARB_vertex_type_2_10_10_10_rev", &ogl_ext_ARB_vertex_type_2_10_10_10_rev, Load_ARB_vertex_type_2_10_10_10_rev},
	{"GL_ARB_blend_func_extended", &ogl_ext_ARB_blend_func_extended, Load_ARB_blend_func_extended},
	{"GL_ARB_occlusion_query2", &ogl_ext_ARB_occlusion_query2, NULL},
	{"GL_ARB_sampler_objects", &ogl_ext_ARB_sampler_objects, Load_ARB_sampler_objects},
	{"GL_ARB_draw_indirect", &ogl_ext_ARB_draw_indirect, Load_ARB_draw_indirect},
	{"GL_ARB_gpu_shader5", &ogl_ext_ARB_gpu_shader5, NULL},
	{"GL_ARB_gpu_shader_fp64", &ogl_ext_ARB_gpu_shader_fp64, Load_ARB_gpu_shader_fp64},
	{"GL_ARB_shader_subroutine", &ogl_ext_ARB_shader_subroutine, Load_ARB_shader_subroutine},
	{"GL_ARB_tessellation_shader", &ogl_ext_ARB_tessellation_shader, Load_ARB_tessellation_shader},
	{"GL_ARB_transform_feedback2", &ogl_ext_ARB_transform_feedback2, Load_ARB_transform_feedback2},
	{"GL_ARB_transform_feedback3", &ogl_ext_ARB_transform_feedback3, Load_ARB_transform_feedback3},
	{"GL_ARB_ES2_compatibility", &ogl_ext_ARB_ES2_compatibility, Load_ARB_ES2_compatibility},
	{"GL_ARB_get_program_binary", &ogl_ext_ARB_get_program_binary, Load_ARB_get_program_binary},
	{"GL_ARB_separate_shader_objects", &ogl_ext_ARB_separate_shader_objects, Load_ARB_separate_shader_objects},
	{"GL_ARB_vertex_attrib_64bit", &ogl_ext_ARB_vertex_attrib_64bit, Load_ARB_vertex_attrib_64bit},
	{"GL_ARB_viewport_array", &ogl_ext_ARB_viewport_array, Load_ARB_viewport_array},
	{"GL_ARB_base_instance", &ogl_ext_ARB_base_instance, Load_ARB_base_instance},
	{"GL_ARB_shading_language_420pack", &ogl_ext_ARB_shading_language_420pack, NULL},
	{"GL_ARB_transform_feedback_instanced", &ogl_ext_ARB_transform_feedback_instanced, Load_ARB_transform_feedback_instanced},
	{"GL_ARB_compressed_texture_pixel_storage", &ogl_ext_ARB_compressed_texture_pixel_storage, NULL},
	{"GL_ARB_conservative_depth", &ogl_ext_ARB_conservative_depth, NULL},
	{"GL_ARB_internalformat_query", &ogl_ext_ARB_internalformat_query, Load_ARB_internalformat_query},
	{"GL_ARB_map_buffer_alignment", &ogl_ext_ARB_map_buffer_alignment, NULL},
	{"GL_ARB_shader_atomic_counters", &ogl_ext_ARB_shader_atomic_counters, Load_ARB_shader_atomic_counters},
	{"GL_ARB_shader_image_load_store", &ogl_ext_ARB_shader_image_load_store, Load_ARB_shader_image_load_store},
	{"GL_ARB_shading_language_packing", &ogl_ext_ARB_shading_language_packing, NULL},
	{"GL_ARB_texture_storage", &ogl_ext_ARB_texture_storage, Load_ARB_texture_storage},
	{"GL_KHR_debug", &ogl_ext_KHR_debug, Load_KHR_debug},
	{"GL_ARB_arrays_of_arrays", &ogl_ext_ARB_arrays_of_arrays, NULL},
	{"GL_ARB_clear_buffer_object", &ogl_ext_ARB_clear_buffer_object, Load_ARB_clear_buffer_object},
	{"GL_ARB_compute_shader", &ogl_ext_ARB_compute_shader, Load_ARB_compute_shader},
	{"GL_ARB_copy_image", &ogl_ext_ARB_copy_image, Load_ARB_copy_image},
	{"GL_ARB_ES3_compatibility", &ogl_ext_ARB_ES3_compatibility, NULL},
	{"GL_ARB_explicit_uniform_location", &ogl_ext_ARB_explicit_uniform_location, NULL},
	{"GL_ARB_fragment_layer_viewport", &ogl_ext_ARB_fragment_layer_viewport, NULL},
	{"GL_ARB_framebuffer_no_attachments", &ogl_ext_ARB_framebuffer_no_attachments, Load_ARB_framebuffer_no_attachments},
	{"GL_ARB_internalformat_query2", &ogl_ext_ARB_internalformat_query2, Load_ARB_internalformat_query2},
	{"GL_ARB_invalidate_subdata", &ogl_ext_ARB_invalidate_subdata, Load_ARB_invalidate_subdata},
	{"GL_ARB_multi_draw_indirect", &ogl_ext_ARB_multi_draw_indirect, Load_ARB_multi_draw_indirect},
	{"GL_ARB_program_interface_query", &ogl_ext_ARB_program_interface_query, Load_ARB_program_interface_query},
	{"GL_ARB_shader_image_size", &ogl_ext_ARB_shader_image_size, NULL},
	{"GL_ARB_shader_storage_buffer_object", &ogl_ext_ARB_shader_storage_buffer_object, Load_ARB_shader_storage_buffer_object},
	{"GL_ARB_stencil_texturing", &ogl_ext_ARB_stencil_texturing, NULL},
	{"GL_ARB_texture_buffer_range", &ogl_ext_ARB_texture_buffer_range, Load_ARB_texture_buffer_range},
	{"GL_ARB_texture_query_levels", &ogl_ext_ARB_texture_query_levels, NULL},
	{"GL_ARB_texture_storage_multisample", &ogl_ext_ARB_texture_storage_multisample, Load_ARB_texture_storage_multisample},
	{"GL_ARB_texture_view", &ogl_ext_ARB_texture_view, Load_ARB_texture_view},
	{"GL_ARB_vertex_attrib_binding", &ogl_ext_ARB_vertex_attrib_binding, Load_ARB_vertex_attrib_binding},
	{"GL_ARB_buffer_storage", &ogl_ext_ARB_buffer_storage, Load_ARB_buffer_storage},
	{"GL_ARB_clear_texture", &ogl_ext_ARB_clear_texture, Load_ARB_clear_texture},
	{"GL_ARB_enhanced_layouts", &ogl_ext_ARB_enhanced_layouts, NULL},
	{"GL_ARB_multi_bind", &ogl_ext_ARB_multi_bind, Load_ARB_multi_bind},
	{"GL_ARB_query_buffer_object", &ogl_ext_ARB_query_buffer_object, NULL},
	{"GL_ARB_texture_mirror_clamp_to_edge", &ogl_ext_ARB_texture_mirror_clamp_to_edge, NULL},
	{"GL_ARB_texture_stencil8", &ogl_ext_ARB_texture_stencil8, NULL},
	{"GL_ARB_vertex_type_10f_11f_11f_rev", &ogl_ext_ARB_vertex_type_10f_11f_11f_rev, NULL},
	{"GL_3DFX_multisample", &ogl_ext_3DFX_multisample, NULL},
	{"GL_3DFX_tbuffer", &ogl_ext_3DFX_tbuffer, Load_3DFX_tbuffer},
	{"GL_3DFX_texture_compression_FXT1", &ogl_ext_3DFX_texture_compression_FXT1, NULL},
	{"GL_AMD_blend_minmax_factor", &ogl_ext_AMD_blend_minmax_factor, NULL},
	{"GL_AMD_conservative_depth", &ogl_ext_AMD_conservative_depth, NULL},
	{"GL_AMD_debug_output", &ogl_ext_AMD_debug_output, Load_AMD_debug_output},
	{"GL_AMD_depth_clamp_separate", &ogl_ext_AMD_depth_clamp_separate, NULL},
	{"GL_AMD_draw_buffers_blend", &ogl_ext_AMD_draw_buffers_blend, Load_AMD_draw_buffers_blend},
	{"GL_AMD_interleaved_elements", &ogl_ext_AMD_interleaved_elements, Load_AMD_interleaved_elements},
	{"GL_AMD_multi_draw_indirect", &ogl_ext_AMD_multi_draw_indirect, Load_AMD_multi_draw_indirect},
	{"GL_AMD_name_gen_delete", &ogl_ext_AMD_name_gen_delete, Load_AMD_name_gen_delete},
	{"GL_AMD_performance_monitor", &ogl_ext_AMD_performance_monitor, Load_AMD_performance_monitor},
	{"GL_AMD_pinned_memory", &ogl_ext_AMD_pinned_memory, NULL},
	{"GL_AMD_query_buffer_object", &ogl_ext_AMD_query_buffer_object, NULL},
	{"GL_AMD_sample_positions", &ogl_ext_AMD_sample_positions, Load_AMD_sample_positions},
	{"GL_AMD_seamless_cubemap_per_texture", &ogl_ext_AMD_seamless_cubemap_per_texture, NULL},
	{"GL_AMD_shader_stencil_export", &ogl_ext_AMD_shader_stencil_export, NULL},
	{"GL_AMD_shader_trinary_minmax", &ogl_ext_AMD_shader_trinary_minmax, NULL},
	{"GL_AMD_sparse_texture", &ogl_ext_AMD_sparse_texture, Load_AMD_sparse_texture},
	{"GL_AMD_stencil_operation_extended", &ogl_ext_AMD_stencil_operation_extended, Load_AMD_stencil_operation_extended},
	{"GL_AMD_texture_texture4", &ogl_ext_AMD_texture_texture4, NULL},
	{"GL_AMD_transform_feedback3_lines_triangles", &ogl_ext_AMD_transform_feedback3_lines_triangles, NULL},
	{"GL_AMD_vertex_shader_layer", &ogl_ext_AMD_vertex_shader_layer, NULL},
	{"GL_AMD_vertex_shader_tessellator", &ogl_ext_AMD_vertex_shader_tessellator, Load_AMD_vertex_shader_tessellator},
	{"GL_AMD_vertex_shader_viewport_index", &ogl_ext_AMD_vertex_shader_viewport_index, NULL},
	{"GL_APPLE_aux_depth_stencil", &ogl_ext_APPLE_aux_depth_stencil, NULL},
	{"GL_APPLE_client_storage", &ogl_ext_APPLE_client_storage, NULL},
	{"GL_APPLE_element_array", &ogl_ext_APPLE_element_array, Load_APPLE_element_array},
	{"GL_APPLE_fence", &ogl_ext_APPLE_fence, Load_APPLE_fence},
	{"GL_APPLE_float_pixels", &ogl_ext_APPLE_float_pixels, NULL},
	{"GL_APPLE_flush_buffer_range", &ogl_ext_APPLE_flush_buffer_range, Load_APPLE_flush_buffer_range},
	{"GL_APPLE_object_purgeable", &ogl_ext_APPLE_object_purgeable, Load_APPLE_object_purgeable},
	{"GL_APPLE_rgb_422", &ogl_ext_APPLE_rgb_422, NULL},
	{"GL_APPLE_row_bytes", &ogl_ext_APPLE_row_bytes, NULL},
	{"GL_APPLE_specular_vector", &ogl_ext_APPLE_specular_vector, NULL},
	{"GL_APPLE_texture_range", &ogl_ext_APPLE_texture_range, Load_APPLE_texture_range},
	{"GL_APPLE_transform_hint", &ogl_ext_APPLE_transform_hint, NULL},
	{"GL_APPLE_vertex_array_object", &ogl_ext_APPLE_vertex_array_object, Load_APPLE_vertex_array_object},
	{"GL_APPLE_vertex_array_range", &ogl_ext_APPLE_vertex_array_range, Load_APPLE_vertex_array_range},
	{"GL_APPLE_vertex_program_evaluators", &ogl_ext_APPLE_vertex_program_evaluators, Load_APPLE_vertex_program_evaluators},
	{"GL_APPLE_ycbcr_422", &ogl_ext_APPLE_ycbcr_422, NULL},
	{"GL_ARB_bindless_texture", &ogl_ext_ARB_bindless_texture, Load_ARB_bindless_texture},
	{"GL_ARB_cl_event", &ogl_ext_ARB_cl_event, Load_ARB_cl_event},
	{"GL_ARB_color_buffer_float", &ogl_ext_ARB_color_buffer_float, Load_ARB_color_buffer_float},
	{"GL_ARB_compatibility", &ogl_ext_ARB_compatibility, NULL},
	{"GL_ARB_compute_variable_group_size", &ogl_ext_ARB_compute_variable_group_size, Load_ARB_compute_variable_group_size},
	{"GL_ARB_debug_output", &ogl_ext_ARB_debug_output, Load_ARB_debug_output},
	{"GL_ARB_depth_texture", &ogl_ext_ARB_depth_texture, NULL},
	{"GL_ARB_draw_buffers", &ogl_ext_ARB_draw_buffers, Load_ARB_draw_buffers},
	{"GL_ARB_draw_buffers_blend", &ogl_ext_ARB_draw_buffers_blend, Load_ARB_draw_buffers_blend},
	{"GL_ARB_draw_instanced", &ogl_ext_ARB_draw_instanced, Load_ARB_draw_instanced},
	{"GL_ARB_explicit_attrib_location", &ogl_ext_ARB_explicit_attrib_location, NULL},
	{"GL_ARB_fragment_program", &ogl_ext_ARB_fragment_program, Load_ARB_fragment_program},
	{"GL_ARB_fragment_program_shadow", &ogl_ext_ARB_fragment_program_shadow, NULL},
	{"GL_ARB_fragment_shader", &ogl_ext_ARB_fragment_shader, NULL},
	{"GL_ARB_geometry_shader4", &ogl_ext_ARB_geometry_shader4, Load_ARB_geometry_shader4},
	{"GL_ARB_half_float_pixel", &ogl_ext_ARB_half_float_pixel, NULL},
	{"GL_ARB_indirect_parameters", &ogl_ext_ARB_indirect_parameters, Load_ARB_indirect_parameters},
	{"GL_ARB_instanced_arrays", &ogl_ext_ARB_instanced_arrays, Load_ARB_instanced_arrays},
	{"GL_ARB_matrix_palette", &ogl_ext_ARB_matrix_palette, Load_ARB_matrix_palette},
	{"GL_ARB_multisample", &ogl_ext_ARB_multisample, Load_ARB_multisample},
	{"GL_ARB_multitexture", &ogl_ext_ARB_multitexture, Load_ARB_multitexture},
	{"GL_ARB_occlusion_query", &ogl_ext_ARB_occlusion_query, Load_ARB_occlusion_query},
	{"GL_ARB_pixel_buffer_object", &ogl_ext_ARB_pixel_buffer_object, NULL},
	{"GL_ARB_point_parameters", &ogl_ext_ARB_point_parameters, Load_ARB_point_parameters},
	{"GL_ARB_point_sprite", &ogl_ext_ARB_point_sprite, NULL},
	{"GL_ARB_robust_buffer_access_behavior", &ogl_ext_ARB_robust_buffer_access_behavior, NULL},
	{"GL_ARB_robustness", &ogl_ext_ARB_robustness, Load_ARB_robustness},
	{"GL_ARB_robustness_isolation", &ogl_ext_ARB_robustness_isolation, NULL},
	{"GL_ARB_sample_shading", &ogl_ext_ARB_sample_shading, Load_ARB_sample_shading},
	{"GL_ARB_seamless_cubemap_per_texture", &ogl_ext_ARB_seamless_cubemap_per_texture, NULL},
	{"GL_ARB_shader_bit_encoding", &ogl_ext_ARB_shader_bit_encoding, NULL},
	{"GL_ARB_shader_draw_parameters", &ogl_ext_ARB_shader_draw_parameters, NULL},
	{"GL_ARB_shader_group_vote", &ogl_ext_ARB_shader_group_vote, NULL},
	{"GL_ARB_shader_objects", &ogl_ext_ARB_shader_objects, Load_ARB_shader_objects},
	{"GL_ARB_shader_precision", &ogl_ext_ARB_shader_precision, NULL},
	{"GL_ARB_shader_stencil_export", &ogl_ext_ARB_shader_stencil_export, NULL},
	{"GL_ARB_shader_texture_lod", &ogl_ext_ARB_shader_texture_lod, NULL},
	{"GL_ARB_shading_language_100", &ogl_ext_ARB_shading_language_100, NULL},
	{"GL_ARB_shading_language_include", &ogl_ext_ARB_shading_language_include, Load_ARB_shading_language_include},
	{"GL_ARB_shadow", &ogl_ext_ARB_shadow, NULL},
	{"GL_ARB_shadow_ambient", &ogl_ext_ARB_shadow_ambient, NULL},
	{"GL_ARB_sparse_texture", &ogl_ext_ARB_sparse_texture, Load_ARB_sparse_texture},
	{"GL_ARB_texture_border_clamp", &ogl_ext_ARB_texture_border_clamp, NULL},
	{"GL_ARB_texture_buffer_object", &ogl_ext_ARB_texture_buffer_object, Load_ARB_texture_buffer_object},
	{"GL_ARB_texture_buffer_object_rgb32", &ogl_ext_ARB_texture_buffer_object_rgb32, NULL},
	{"GL_ARB_texture_compression", &ogl_ext_ARB_texture_compression, Load_ARB_texture_compression},
	{"GL_ARB_texture_compression_bptc", &ogl_ext_ARB_texture_compression_bptc, NULL},
	{"GL_ARB_texture_cube_map", &ogl_ext_ARB_texture_cube_map, NULL},
	{"GL_ARB_texture_cube_map_array", &ogl_ext_ARB_texture_cube_map_array, NULL},
	{"GL_ARB_texture_env_add", &ogl_ext_ARB_texture_env_add, NULL},
	{"GL_ARB_texture_env_combine", &ogl_ext_ARB_texture_env_combine, NULL},
	{"GL_ARB_texture_env_crossbar", &ogl_ext_ARB_texture_env_crossbar, NULL},
	{"GL_ARB_texture_env_dot3", &ogl_ext_ARB_texture_env_dot3, NULL},
	{"GL_ARB_texture_float", &ogl_ext_ARB_texture_float, NULL},
	{"GL_ARB_texture_gather", &ogl_ext_ARB_texture_gather, NULL},
	{"GL_ARB_texture_mirrored_repeat", &ogl_ext_ARB_texture_mirrored_repeat, NULL},
	{"GL_ARB_texture_non_power_of_two", &ogl_ext_ARB_texture_non_power_of_two, NULL},
	{"GL_ARB_texture_query_lod", &ogl_ext_ARB_texture_query_lod, NULL},
	{"GL_ARB_texture_rectangle", &ogl_ext_ARB_texture_rectangle, NULL},
	{"GL_ARB_transpose_matrix", &ogl_ext_ARB_transpose_matrix, Load_ARB_transpose_matrix},
	{"GL_ARB_vertex_blend", &ogl_ext_ARB_vertex_blend, Load_ARB_vertex_blend},
	{"GL_ARB_vertex_buffer_object", &ogl_ext_ARB_vertex_buffer_object, Load_ARB_vertex_buffer_object},
	{"GL_ARB_vertex_program", &ogl_ext_ARB_vertex_program, Load_ARB_vertex_program},
	{"GL_ARB_vertex_shader", &ogl_ext_ARB_vertex_shader, Load_ARB_vertex_shader},
	{"GL_ARB_window_pos", &ogl_ext_ARB_window_pos, Load_ARB_window_pos},
	{"GL_ATI_draw_buffers", &ogl_ext_ATI_draw_buffers, Load_ATI_draw_buffers},
	{"GL_ATI_element_array", &ogl_ext_ATI_element_array, Load_ATI_element_array},
	{"GL_ATI_envmap_bumpmap", &ogl_ext_ATI_envmap_bumpmap, Load_ATI_envmap_bumpmap},
	{"GL_ATI_fragment_shader", &ogl_ext_ATI_fragment_shader, Load_ATI_fragment_shader},
	{"GL_ATI_map_object_buffer", &ogl_ext_ATI_map_object_buffer, Load_ATI_map_object_buffer},
	{"GL_ATI_meminfo", &ogl_ext_ATI_meminfo, NULL},
	{"GL_ATI_pixel_format_float", &ogl_ext_ATI_pixel_format_float, NULL},
	{"GL_ATI_pn_triangles", &ogl_ext_ATI_pn_triangles, Load_ATI_pn_triangles},
	{"GL_ATI_separate_stencil", &ogl_ext_ATI_separate_stencil, Load_ATI_separate_stencil},
	{"GL_ATI_text_fragment_shader", &ogl_ext_ATI_text_fragment_shader, NULL},
	{"GL_ATI_texture_env_combine3", &ogl_ext_ATI_texture_env_combine3, NULL},
	{"GL_ATI_texture_float", &ogl_ext_ATI_texture_float, NULL},
	{"GL_ATI_texture_mirror_once", &ogl_ext_ATI_texture_mirror_once, NULL},
	{"GL_ATI_vertex_array_object", &ogl_ext_ATI_vertex_array_object, Load_ATI_vertex_array_object},
	{"GL_ATI_vertex_attrib_array_object", &ogl_ext_ATI_vertex_attrib_array_object, Load_ATI_vertex_attrib_array_object},
	{"GL_ATI_vertex_streams", &ogl_ext_ATI_vertex_streams, Load_ATI_vertex_streams},
	{"GL_EXT_422_pixels", &ogl_ext_EXT_422_pixels, NULL},
	{"GL_EXT_abgr", &ogl_ext_EXT_abgr, NULL},
	{"GL_EXT_bgra", &ogl_ext_EXT_bgra, NULL},
	{"GL_EXT_bindable_uniform", &ogl_ext_EXT_bindable_uniform, Load_EXT_bindable_uniform},
	{"GL_EXT_blend_color", &ogl_ext_EXT_blend_color, Load_EXT_blend_color},
	{"GL_EXT_blend_equation_separate", &ogl_ext_EXT_blend_equation_separate, Load_EXT_blend_equation_separate},
	{"GL_EXT_blend_func_separate", &ogl_ext_EXT_blend_func_separate, Load_EXT_blend_func_separate},
	{"GL_EXT_blend_logic_op", &ogl_ext_EXT_blend_logic_op, NULL},
	{"GL_EXT_blend_minmax", &ogl_ext_EXT_blend_minmax, Load_EXT_blend_minmax},
	{"GL_EXT_blend_subtract", &ogl_ext_EXT_blend_subtract, NULL},
	{"GL_EXT_clip_volume_hint", &ogl_ext_EXT_clip_volume_hint, NULL},
	{"GL_EXT_cmyka", &ogl_ext_EXT_cmyka, NULL},
	{"GL_EXT_color_subtable", &ogl_ext_EXT_color_subtable, Load_EXT_color_subtable},
	{"GL_EXT_compiled_vertex_array", &ogl_ext_EXT_compiled_vertex_array, Load_EXT_compiled_vertex_array},
	{"GL_EXT_convolution", &ogl_ext_EXT_convolution, Load_EXT_convolution},
	{"GL_EXT_coordinate_frame", &ogl_ext_EXT_coordinate_frame, Load_EXT_coordinate_frame},
	{"GL_EXT_copy_texture", &ogl_ext_EXT_copy_texture, Load_EXT_copy_texture},
	{"GL_EXT_cull_vertex", &ogl_ext_EXT_cull_vertex, Load_EXT_cull_vertex},
	{"GL_EXT_depth_bounds_test", &ogl_ext_EXT_depth_bounds_test, Load_EXT_depth_bounds_test},
	{"GL_EXT_direct_state_access", &ogl_ext_EXT_direct_state_access, Load_EXT_direct_state_access},
	{"GL_EXT_draw_buffers2", &ogl_ext_EXT_draw_buffers2, Load_EXT_draw_buffers2},
	{"GL_EXT_draw_instanced", &ogl_ext_EXT_draw_instanced, Load_EXT_draw_instanced},
	{"GL_EXT_draw_range_elements", &ogl_ext_EXT_draw_range_elements, Load_EXT_draw_range_elements},
	{"GL_EXT_fog_coord", &ogl_ext_EXT_fog_coord, Load_EXT_fog_coord},
	{"GL_EXT_framebuffer_blit", &ogl_ext_EXT_framebuffer_blit, Load_EXT_framebuffer_blit},
	{"GL_EXT_framebuffer_multisample", &ogl_ext_EXT_framebuffer_multisample, Load_EXT_framebuffer_multisample},
	{"GL_EXT_framebuffer_multisample_blit_scaled", &ogl_ext_EXT_framebuffer_multisample_blit_scaled, NULL},
	{"GL_EXT_framebuffer_object", &ogl_ext_EXT_framebuffer_object, Load_EXT_framebuffer_object},
	{"GL_EXT_framebuffer_sRGB", &ogl_ext_EXT_framebuffer_sRGB, NULL},
	{"GL_EXT_geometry_shader4", &ogl_ext_EXT_geometry_shader4, Load_EXT_geometry_shader4},
	{"GL_EXT_gpu_program_parameters", &ogl_ext_EXT_gpu_program_parameters, Load_EXT_gpu_program_parameters},
	{"GL_EXT_gpu_shader4", &ogl_ext_EXT_gpu_shader4, Load_EXT_gpu_shader4},
	{"GL_EXT_histogram", &ogl_ext_EXT_histogram, Load_EXT_histogram},
	{"GL_EXT_index_array_formats", &ogl_ext_EXT_index_array_formats, NULL},
	{"GL_EXT_index_func", &ogl_ext_EXT_index_func, Load_EXT_index_func},
	{"GL_EXT_index_material", &ogl_ext_EXT_index_material, Load_EXT_index_material},
	{"GL_EXT_index_texture", &ogl_ext_EXT_index_texture, NULL},
	{"GL_EXT_light_texture", &ogl_ext_EXT_light_texture, Load_EXT_light_texture},
	{"GL_EXT_misc_attribute", &ogl_ext_EXT_misc_attribute, NULL},
	{"GL_EXT_multi_draw_arrays", &ogl_ext_EXT_multi_draw_arrays, Load_EXT_multi_draw_arrays},
	{"GL_EXT_multisample", &ogl_ext_EXT_multisample, Load_EXT_multisample},
	{"GL_EXT_packed_depth_stencil", &ogl_ext_EXT_packed_depth_stencil, NULL},
	{"GL_EXT_packed_float", &ogl_ext_EXT_packed_float, NULL},
	{"GL_EXT_packed_pixels", &ogl_ext_EXT_packed_pixels, NULL},
	{"GL_EXT_paletted_texture", &ogl_ext_EXT_paletted_texture, Load_EXT_paletted_texture},
	{"GL_EXT_pixel_buffer_object", &ogl_ext_EXT_pixel_buffer_object, NULL},
	{"GL_EXT_pixel_transform", &ogl_ext_EXT_pixel_transform, Load_EXT_pixel_transform},
	{"GL_EXT_pixel_transform_color_table", &ogl_ext_EXT_pixel_transform_color_table, NULL},
	{"GL_EXT_point_parameters", &ogl_ext_EXT_point_parameters, Load_EXT_point_parameters},
	{"GL_EXT_polygon_offset", &ogl_ext_EXT_polygon_offset, Load_EXT_polygon_offset},
	{"GL_EXT_provoking_vertex", &ogl_ext_EXT_provoking_vertex, Load_EXT_provoking_vertex},
	{"GL_EXT_rescale_normal", &ogl_ext_EXT_rescale_normal, NULL},
	{"GL_EXT_secondary_color", &ogl_ext_EXT_secondary_color, Load_EXT_secondary_color},
	{"GL_EXT_separate_shader_objects", &ogl_ext_EXT_separate_shader_objects, Load_EXT_separate_shader_objects},
	{"GL_EXT_separate_specular_color", &ogl_ext_EXT_separate_specular_color, NULL},
	{"GL_EXT_shader_image_load_store", &ogl_ext_EXT_shader_image_load_store, Load_EXT_shader_image_load_store},
	{"GL_EXT_shadow_funcs", &ogl_ext_EXT_shadow_funcs, NULL},
	{"GL_EXT_shared_texture_palette", &ogl_ext_EXT_shared_texture_palette, NULL},
	{"GL_EXT_stencil_clear_tag", &ogl_ext_EXT_stencil_clear_tag, Load_EXT_stencil_clear_tag},
	{"GL_EXT_stencil_two_side", &ogl_ext_EXT_stencil_two_side, Load_EXT_stencil_two_side},
	{"GL_EXT_stencil_wrap", &ogl_ext_EXT_stencil_wrap, NULL},
	{"GL_EXT_subtexture", &ogl_ext_EXT_subtexture, Load_EXT_subtexture},
	{"GL_EXT_texture", &ogl_ext_EXT_texture, NULL},
	{"GL_EXT_texture3D", &ogl_ext_EXT_texture3D, Load_EXT_texture3D},
	{"GL_EXT_texture_array", &ogl_ext_EXT_texture_array, NULL},
	{"GL_EXT_texture_buffer_object", &ogl_ext_EXT_texture_buffer_object, Load_EXT_texture_buffer_object},
	{"GL_EXT_texture_compression_latc", &ogl_ext_EXT_texture_compression_latc, NULL},
	{"GL_EXT_texture_compression_rgtc", &ogl_ext_EXT_texture_compression_rgtc, NULL},
	{"GL_EXT_texture_compression_s3tc", &ogl_ext_EXT_texture_compression_s3tc, NULL},
	{"GL_EXT_texture_cube_map", &ogl_ext_EXT_texture_cube_map, NULL},
	{"GL_EXT_texture_env_add", &ogl_ext_EXT_texture_env_add, NULL},
	{"GL_EXT_texture_env_combine", &ogl_ext_EXT_texture_env_combine, NULL},
	{"GL_EXT_texture_env_dot3", &ogl_ext_EXT_texture_env_dot3, NULL},
	{"GL_EXT_texture_filter_anisotropic", &ogl_ext_EXT_texture_filter_anisotropic, NULL},
	{"GL_EXT_texture_integer", &ogl_ext_EXT_texture_integer, Load_EXT_texture_integer},
	{"GL_EXT_texture_lod_bias", &ogl_ext_EXT_texture_lod_bias, NULL},
	{"GL_EXT_texture_mirror_clamp", &ogl_ext_EXT_texture_mirror_clamp, NULL},
	{"GL_EXT_texture_object", &ogl_ext_EXT_texture_object, Load_EXT_texture_object},
	{"GL_EXT_texture_perturb_normal", &ogl_ext_EXT_texture_perturb_normal, Load_EXT_texture_perturb_normal},
	{"GL_EXT_texture_sRGB", &ogl_ext_EXT_texture_sRGB, NULL},
	{"GL_EXT_texture_sRGB_decode", &ogl_ext_EXT_texture_sRGB_decode, NULL},
	{"GL_EXT_texture_shared_exponent", &ogl_ext_EXT_texture_shared_exponent, NULL},
	{"GL_EXT_texture_snorm", &ogl_ext_EXT_texture_snorm, NULL},
	{"GL_EXT_texture_swizzle", &ogl_ext_EXT_texture_swizzle, NULL},
	{"GL_EXT_timer_query", &ogl_ext_EXT_timer_query, Load_EXT_timer_query},
	{"GL_EXT_transform_feedback", &ogl_ext_EXT_transform_feedback, Load_EXT_transform_feedback},
	{"GL_EXT_vertex_array", &ogl_ext_EXT_vertex_array, Load_EXT_vertex_array},
	{"GL_EXT_vertex_array_bgra", &ogl_ext_EXT_vertex_array_bgra, NULL},
	{"GL_EXT_vertex_attrib_64bit", &ogl_ext_EXT_vertex_attrib_64bit, Load_EXT_vertex_attrib_64bit},
	{"GL_EXT_vertex_shader", &ogl_ext_EXT_vertex_shader, Load_EXT_vertex_shader},
	{"GL_EXT_vertex_weighting", &ogl_ext_EXT_vertex_weighting, Load_EXT_vertex_weighting},
	{"GL_EXT_x11_sync_object", &ogl_ext_EXT_x11_sync_object, Load_EXT_x11_sync_object},
	{"GL_GREMEDY_frame_terminator", &ogl_ext_GREMEDY_frame_terminator, Load_GREMEDY_frame_terminator},
	{"GL_GREMEDY_string_marker", &ogl_ext_GREMEDY_string_marker, Load_GREMEDY_string_marker},
	{"GL_HP_convolution_border_modes", &ogl_ext_HP_convolution_border_modes, NULL},
	{"GL_HP_image_transform", &ogl_ext_HP_image_transform, Load_HP_image_transform},
	{"GL_HP_occlusion_test", &ogl_ext_HP_occlusion_test, NULL},
	{"GL_HP_texture_lighting", &ogl_ext_HP_texture_lighting, NULL},
	{"GL_IBM_cull_vertex", &ogl_ext_IBM_cull_vertex, NULL},
	{"GL_IBM_multimode_draw_arrays", &ogl_ext_IBM_multimode_draw_arrays, Load_IBM_multimode_draw_arrays},
	{"GL_IBM_rasterpos_clip", &ogl_ext_IBM_rasterpos_clip, NULL},
	{"GL_IBM_static_data", &ogl_ext_IBM_static_data, Load_IBM_static_data},
	{"GL_IBM_texture_mirrored_repeat", &ogl_ext_IBM_texture_mirrored_repeat, NULL},
	{"GL_IBM_vertex_array_lists", &ogl_ext_IBM_vertex_array_lists, Load_IBM_vertex_array_lists},
	{"GL_INGR_blend_func_separate", &ogl_ext_INGR_blend_func_separate, Load_INGR_blend_func_separate},
	{"GL_INGR_color_clamp", &ogl_ext_INGR_color_clamp, NULL},
	{"GL_INGR_interlace_read", &ogl_ext_INGR_interlace_read, NULL},
	{"GL_INTEL_map_texture", &ogl_ext_INTEL_map_texture, Load_INTEL_map_texture},
	{"GL_INTEL_parallel_arrays", &ogl_ext_INTEL_parallel_arrays, Load_INTEL_parallel_arrays},
	{"GL_KHR_texture_compression_astc_ldr", &ogl_ext_KHR_texture_compression_astc_ldr, NULL},
	{"GL_MESAX_texture_stack", &ogl_ext_MESAX_texture_stack, NULL},
	{"GL_MESA_pack_invert", &ogl_ext_MESA_pack_invert, NULL},
	{"GL_MESA_resize_buffers", &ogl_ext_MESA_resize_buffers, Load_MESA_resize_buffers},
	{"GL_MESA_window_pos", &ogl_ext_MESA_window_pos, Load_MESA_window_pos},
	{"GL_MESA_ycbcr_texture", &ogl_ext_MESA_ycbcr_texture, NULL},
	{"GL_NVX_conditional_render", &ogl_ext_NVX_conditional_render, Load_NVX_conditional_render},
	{"GL_NV_bindless_multi_draw_indirect", &ogl_ext_NV_bindless_multi_draw_indirect, Load_NV_bindless_multi_draw_indirect},
	{"GL_NV_bindless_texture", &ogl_ext_NV_bindless_texture, Load_NV_bindless_texture},
	{"GL_NV_blend_equation_advanced", &ogl_ext_NV_blend_equation_advanced, Load_NV_blend_equation_advanced},
	{"GL_NV_blend_equation_advanced_coherent", &ogl_ext_NV_blend_equation_advanced_coherent, NULL},
	{"GL_NV_blend_square", &ogl_ext_NV_blend_square, NULL},
	{"GL_NV_compute_program5", &ogl_ext_NV_compute_program5, NULL},
	{"GL_NV_conditional_render", &ogl_ext_NV_conditional_render, Load_NV_conditional_render},
	{"GL_NV_copy_depth_to_color", &ogl_ext_NV_copy_depth_to_color, NULL},
	{"GL_NV_copy_image", &ogl_ext_NV_copy_image, Load_NV_copy_image},
	{"GL_NV_deep_texture3D", &ogl_ext_NV_deep_texture3D, NULL},
	{"GL_NV_depth_buffer_float", &ogl_ext_NV_depth_buffer_float, Load_NV_depth_buffer_float},
	{"GL_NV_depth_clamp", &ogl_ext_NV_depth_clamp, NULL},
	{"GL_NV_draw_texture", &ogl_ext_NV_draw_texture, Load_NV_draw_texture},
	{"GL_NV_evaluators", &ogl_ext_NV_evaluators, Load_NV_evaluators},
	{"GL_NV_explicit_multisample", &ogl_ext_NV_explicit_multisample, Load_NV_explicit_multisample},
	{"GL_NV_fence", &ogl_ext_NV_fence, Load_NV_fence},
	{"GL_NV_float_buffer", &ogl_ext_NV_float_buffer, NULL},
	{"GL_NV_fog_distance", &ogl_ext_NV_fog_distance, NULL},
	{"GL_NV_fragment_program", &ogl_ext_NV_fragment_program, Load_NV_fragment_program},
	{"GL_NV_fragment_program2", &ogl_ext_NV_fragment_program2, NULL},
	{"GL_NV_fragment_program4", &ogl_ext_NV_fragment_program4, NULL},
	{"GL_NV_fragment_program_option", &ogl_ext_NV_fragment_program_option, NULL},
	{"GL_NV_framebuffer_multisample_coverage", &ogl_ext_NV_framebuffer_multisample_coverage, Load_NV_framebuffer_multisample_coverage},
	{"GL_NV_geometry_program4", &ogl_ext_NV_geometry_program4, Load_NV_geometry_program4},
	{"GL_NV_geometry_shader4", &ogl_ext_NV_geometry_shader4, NULL},
	{"GL_NV_gpu_program4", &ogl_ext_NV_gpu_program4, Load_NV_gpu_program4},
	{"GL_NV_gpu_program5", &ogl_ext_NV_gpu_program5, Load_NV_gpu_program5},
	{"GL_NV_gpu_program5_mem_extended", &ogl_ext_NV_gpu_program5_mem_extended, NULL},
	{"GL_NV_gpu_shader5", &ogl_ext_NV_gpu_shader5, Load_NV_gpu_shader5},
	{"GL_NV_half_float", &ogl_ext_NV_half_float, Load_NV_half_float},
	{"GL_NV_light_max_exponent", &ogl_ext_NV_light_max_exponent, NULL},
	{"GL_NV_multisample_coverage", &ogl_ext_NV_multisample_coverage, NULL},
	{"GL_NV_multisample_filter_hint", &ogl_ext_NV_multisample_filter_hint, NULL},
	{"GL_NV_occlusion_query", &ogl_ext_NV_occlusion_query, Load_NV_occlusion_query},
	{"GL_NV_packed_depth_stencil", &ogl_ext_NV_packed_depth_stencil, NULL},
	{"GL_NV_parameter_buffer_object", &ogl_ext_NV_parameter_buffer_object, Load_NV_parameter_buffer_object},
	{"GL_NV_parameter_buffer_object2", &ogl_ext_NV_parameter_buffer_object2, NULL},
	{"GL_NV_path_rendering", &ogl_ext_NV_path_rendering, Load_NV_path_rendering},
	{"GL_NV_pixel_data_range", &ogl_ext_NV_pixel_data_range, Load_NV_pixel_data_range},
	{"GL_NV_point_sprite", &ogl_ext_NV_point_sprite, Load_NV_point_sprite},
	{"GL_NV_present_video", &ogl_ext_NV_present_video, Load_NV_present_video},
	{"GL_NV_primitive_restart", &ogl_ext_NV_primitive_restart, Load_NV_primitive_restart},
	{"GL_NV_register_combiners", &ogl_ext_NV_register_combiners, Load_NV_register_combiners},
	{"GL_NV_register_combiners2", &ogl_ext_NV_register_combiners2, Load_NV_register_combiners2},
	{"GL_NV_shader_atomic_counters", &ogl_ext_NV_shader_atomic_counters, NULL},
	{"GL_NV_shader_atomic_float", &ogl_ext_NV_shader_atomic_float, NULL},
	{"GL_NV_shader_buffer_load", &ogl_ext_NV_shader_buffer_load, Load_NV_shader_buffer_load},
	{"GL_NV_shader_buffer_store", &ogl_ext_NV_shader_buffer_store, NULL},
	{"GL_NV_shader_storage_buffer_object", &ogl_ext_NV_shader_storage_buffer_object, NULL},
	{"GL_NV_tessellation_program5", &ogl_ext_NV_tessellation_program5, NULL},
	{"GL_NV_texgen_emboss", &ogl_ext_NV_texgen_emboss, NULL},
	{"GL_NV_texgen_reflection", &ogl_ext_NV_texgen_reflection, NULL},
	{"GL_NV_texture_barrier", &ogl_ext_NV_texture_barrier, Load_NV_texture_barrier},
	{"GL_NV_texture_compression_vtc", &ogl_ext_NV_texture_compression_vtc, NULL},
	{"GL_NV_texture_env_combine4", &ogl_ext_NV_texture_env_combine4, NULL},
	{"GL_NV_texture_expand_normal", &ogl_ext_NV_texture_expand_normal, NULL},
	{"GL_NV_texture_multisample", &ogl_ext_NV_texture_multisample, Load_NV_texture_multisample},
	{"GL_NV_texture_rectangle", &ogl_ext_NV_texture_rectangle, NULL},
	{"GL_NV_texture_shader", &ogl_ext_NV_texture_shader, NULL},
	{"GL_NV_texture_shader2", &ogl_ext_NV_texture_shader2, NULL},
	{"GL_NV_texture_shader3", &ogl_ext_NV_texture_shader3, NULL},
	{"GL_NV_transform_feedback", &ogl_ext_NV_transform_feedback, Load_NV_transform_feedback},
	{"GL_NV_transform_feedback2", &ogl_ext_NV_transform_feedback2, Load_NV_transform_feedback2},
	{"GL_NV_vdpau_interop", &ogl_ext_NV_vdpau_interop, Load_NV_vdpau_interop},
	{"GL_NV_vertex_array_range", &ogl_ext_NV_vertex_array_range, Load_NV_vertex_array_range},
	{"GL_NV_vertex_array_range2", &ogl_ext_NV_vertex_array_range2, NULL},
	{"GL_NV_vertex_attrib_integer_64bit", &ogl_ext_NV_vertex_attrib_integer_64bit, Load_NV_vertex_attrib_integer_64bit},
	{"GL_NV_vertex_buffer_unified_memory", &ogl_ext_NV_vertex_buffer_unified_memory, Load_NV_vertex_buffer_unified_memory},
	{"GL_NV_vertex_program", &ogl_ext_NV_vertex_program, Load_NV_vertex_program},
	{"GL_NV_vertex_program1_1", &ogl_ext_NV_vertex_program1_1, NULL},
	{"GL_NV_vertex_program2", &ogl_ext_NV_vertex_program2, NULL},
	{"GL_NV_vertex_program2_option", &ogl_ext_NV_vertex_program2_option, NULL},
	{"GL_NV_vertex_program3", &ogl_ext_NV_vertex_program3, NULL},
	{"GL_NV_vertex_program4", &ogl_ext_NV_vertex_program4, Load_NV_vertex_program4},
	{"GL_NV_video_capture", &ogl_ext_NV_video_capture, Load_NV_video_capture},
	{"GL_OES_byte_coordinates", &ogl_ext_OES_byte_coordinates, Load_OES_byte_coordinates},
	{"GL_OES_compressed_paletted_texture", &ogl_ext_OES_compressed_paletted_texture, NULL},
	{"GL_OES_fixed_point", &ogl_ext_OES_fixed_point, Load_OES_fixed_point},
	{"GL_OES_query_matrix", &ogl_ext_OES_query_matrix, Load_OES_query_matrix},
	{"GL_OES_read_format", &ogl_ext_OES_read_format, NULL},
	{"GL_OES_single_precision", &ogl_ext_OES_single_precision, Load_OES_single_precision},
	{"GL_OML_interlace", &ogl_ext_OML_interlace, NULL},
	{"GL_OML_resample", &ogl_ext_OML_resample, NULL},
	{"GL_OML_subsample", &ogl_ext_OML_subsample, NULL},
	{"GL_PGI_misc_hints", &ogl_ext_PGI_misc_hints, Load_PGI_misc_hints},
	{"GL_PGI_vertex_hints", &ogl_ext_PGI_vertex_hints, NULL},
	{"GL_REND_screen_coordinates", &ogl_ext_REND_screen_coordinates, NULL},
	{"GL_S3_s3tc", &ogl_ext_S3_s3tc, NULL},
	{"GL_SGIS_detail_texture", &ogl_ext_SGIS_detail_texture, Load_SGIS_detail_texture},
	{"GL_SGIS_fog_function", &ogl_ext_SGIS_fog_function, Load_SGIS_fog_function},
	{"GL_SGIS_generate_mipmap", &ogl_ext_SGIS_generate_mipmap, NULL},
	{"GL_SGIS_multisample", &ogl_ext_SGIS_multisample, Load_SGIS_multisample},
	{"GL_SGIS_pixel_texture", &ogl_ext_SGIS_pixel_texture, Load_SGIS_pixel_texture},
	{"GL_SGIS_point_line_texgen", &ogl_ext_SGIS_point_line_texgen, NULL},
	{"GL_SGIS_point_parameters", &ogl_ext_SGIS_point_parameters, Load_SGIS_point_parameters},
	{"GL_SGIS_sharpen_texture", &ogl_ext_SGIS_sharpen_texture, Load_SGIS_sharpen_texture},
	{"GL_SGIS_texture4D", &ogl_ext_SGIS_texture4D, Load_SGIS_texture4D},
	{"GL_SGIS_texture_border_clamp", &ogl_ext_SGIS_texture_border_clamp, NULL},
	{"GL_SGIS_texture_color_mask", &ogl_ext_SGIS_texture_color_mask, Load_SGIS_texture_color_mask},
	{"GL_SGIS_texture_edge_clamp", &ogl_ext_SGIS_texture_edge_clamp, NULL},
	{"GL_SGIS_texture_filter4", &ogl_ext_SGIS_texture_filter4, Load_SGIS_texture_filter4},
	{"GL_SGIS_texture_lod", &ogl_ext_SGIS_texture_lod, NULL},
	{"GL_SGIS_texture_select", &ogl_ext_SGIS_texture_select, NULL},
	{"GL_SGIX_async", &ogl_ext_SGIX_async, Load_SGIX_async},
	{"GL_SGIX_async_histogram", &ogl_ext_SGIX_async_histogram, NULL},
	{"GL_SGIX_async_pixel", &ogl_ext_SGIX_async_pixel, NULL},
	{"GL_SGIX_blend_alpha_minmax", &ogl_ext_SGIX_blend_alpha_minmax, NULL},
	{"GL_SGIX_calligraphic_fragment", &ogl_ext_SGIX_calligraphic_fragment, NULL},
	{"GL_SGIX_clipmap", &ogl_ext_SGIX_clipmap, NULL},
	{"GL_SGIX_convolution_accuracy", &ogl_ext_SGIX_convolution_accuracy, NULL},
	{"GL_SGIX_depth_pass_instrument", &ogl_ext_SGIX_depth_pass_instrument, NULL},
	{"GL_SGIX_depth_texture", &ogl_ext_SGIX_depth_texture, NULL},
	{"GL_SGIX_flush_raster", &ogl_ext_SGIX_flush_raster, Load_SGIX_flush_raster},
	{"GL_SGIX_fog_offset", &ogl_ext_SGIX_fog_offset, NULL},
	{"GL_SGIX_fragment_lighting", &ogl_ext_SGIX_fragment_lighting, Load_SGIX_fragment_lighting},
	{"GL_SGIX_framezoom", &ogl_ext_SGIX_framezoom, Load_SGIX_framezoom},
	{"GL_SGIX_igloo_interface", &ogl_ext_SGIX_igloo_interface, Load_SGIX_igloo_interface},
	{"GL_SGIX_instruments", &ogl_ext_SGIX_instruments, Load_SGIX_instruments},
	{"GL_SGIX_interlace", &ogl_ext_SGIX_interlace, NULL},
	{"GL_SGIX_ir_instrument1", &ogl_ext_SGIX_ir_instrument1, NULL},
	{"GL_SGIX_list_priority", &ogl_ext_SGIX_list_priority, Load_SGIX_list_priority},
	{"GL_SGIX_pixel_texture", &ogl_ext_SGIX_pixel_texture, Load_SGIX_pixel_texture},
	{"GL_SGIX_pixel_tiles", &ogl_ext_SGIX_pixel_tiles, NULL},
	{"GL_SGIX_polynomial_ffd", &ogl_ext_SGIX_polynomial_ffd, Load_SGIX_polynomial_ffd},
	{"GL_SGIX_reference_plane", &ogl_ext_SGIX_reference_plane, Load_SGIX_reference_plane},
	{"GL_SGIX_resample", &ogl_ext_SGIX_resample, NULL},
	{"GL_SGIX_scalebias_hint", &ogl_ext_SGIX_scalebias_hint, NULL},
	{"GL_SGIX_shadow", &ogl_ext_SGIX_shadow, NULL},
	{"GL_SGIX_shadow_ambient", &ogl_ext_SGIX_shadow_ambient, NULL},
	{"GL_SGIX_sprite", &ogl_ext_SGIX_sprite, Load_SGIX_sprite},
	{"GL_SGIX_subsample", &ogl_ext_SGIX_subsample, NULL},
	{"GL_SGIX_tag_sample_buffer", &ogl_ext_SGIX_tag_sample_buffer, Load_SGIX_tag_sample_buffer},
	{"GL_SGIX_texture_add_env", &ogl_ext_SGIX_texture_add_env, NULL},
	{"GL_SGIX_texture_coordinate_clamp", &ogl_ext_SGIX_texture_coordinate_clamp, NULL},
	{"GL_SGIX_texture_lod_bias", &ogl_ext_SGIX_texture_lod_bias, NULL},
	{"GL_SGIX_texture_multi_buffer", &ogl_ext_SGIX_texture_multi_buffer, NULL},
	{"GL_SGIX_texture_scale_bias", &ogl_ext_SGIX_texture_scale_bias, NULL},
	{"GL_SGIX_vertex_preclip", &ogl_ext_SGIX_vertex_preclip, NULL},
	{"GL_SGIX_ycrcb", &ogl_ext_SGIX_ycrcb, NULL},
	{"GL_SGIX_ycrcb_subsample", &ogl_ext_SGIX_ycrcb_subsample, NULL},
	{"GL_SGIX_ycrcba", &ogl_ext_SGIX_ycrcba, NULL},
	{"GL_SGI_color_matrix", &ogl_ext_SGI_color_matrix, NULL},
	{"GL_SGI_color_table", &ogl_ext_SGI_color_table, Load_SGI_color_table},
	{"GL_SGI_texture_color_table", &ogl_ext_SGI_texture_color_table, NULL},
	{"GL_SUNX_constant_data", &ogl_ext_SUNX_constant_data, Load_SUNX_constant_data},
	{"GL_SUN_convolution_border_modes", &ogl_ext_SUN_convolution_border_modes, NULL},
	{"GL_SUN_global_alpha", &ogl_ext_SUN_global_alpha, Load_SUN_global_alpha},
	{"GL_SUN_mesh_array", &ogl_ext_SUN_mesh_array, Load_SUN_mesh_array},
	{"GL_SUN_slice_accum", &ogl_ext_SUN_slice_accum, NULL},
	{"GL_SUN_triangle_list", &ogl_ext_SUN_triangle_list, Load_SUN_triangle_list},
	{"GL_SUN_vertex", &ogl_ext_SUN_vertex, Load_SUN_vertex},
	{"GL_WIN_phong_shading", &ogl_ext_WIN_phong_shading, NULL},
	{"GL_WIN_specular_fog", &ogl_ext_WIN_specular_fog, NULL},
};

static int g_extensionMapSize = 469;

static ogl_StrToExtMap *FindExtEntry(const char *extensionName)
{
	int loop;
	ogl_StrToExtMap *currLoc = ExtensionMap;
	for(loop = 0; loop < g_extensionMapSize; ++loop, ++currLoc)
	{
		if(strcmp(extensionName, currLoc->extensionName) == 0)
			return currLoc;
	}
	
	return NULL;
}

static void ClearExtensionVars()
{
	ogl_ext_ARB_imaging = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_array_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_rg = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_compression_rgtc = ogl_LOAD_FAILED;
	ogl_ext_ARB_map_buffer_range = ogl_LOAD_FAILED;
	ogl_ext_ARB_half_float_vertex = ogl_LOAD_FAILED;
	ogl_ext_ARB_framebuffer_sRGB = ogl_LOAD_FAILED;
	ogl_ext_ARB_framebuffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_depth_buffer_float = ogl_LOAD_FAILED;
	ogl_ext_ARB_uniform_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_copy_buffer = ogl_LOAD_FAILED;
	ogl_ext_ARB_depth_clamp = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_elements_base_vertex = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_coord_conventions = ogl_LOAD_FAILED;
	ogl_ext_ARB_provoking_vertex = ogl_LOAD_FAILED;
	ogl_ext_ARB_seamless_cube_map = ogl_LOAD_FAILED;
	ogl_ext_ARB_sync = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_multisample = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_array_bgra = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_rgb10_a2ui = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_swizzle = ogl_LOAD_FAILED;
	ogl_ext_ARB_timer_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_type_2_10_10_10_rev = ogl_LOAD_FAILED;
	ogl_ext_ARB_blend_func_extended = ogl_LOAD_FAILED;
	ogl_ext_ARB_occlusion_query2 = ogl_LOAD_FAILED;
	ogl_ext_ARB_sampler_objects = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_ARB_gpu_shader5 = ogl_LOAD_FAILED;
	ogl_ext_ARB_gpu_shader_fp64 = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_subroutine = ogl_LOAD_FAILED;
	ogl_ext_ARB_tessellation_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_transform_feedback2 = ogl_LOAD_FAILED;
	ogl_ext_ARB_transform_feedback3 = ogl_LOAD_FAILED;
	ogl_ext_ARB_ES2_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_get_program_binary = ogl_LOAD_FAILED;
	ogl_ext_ARB_separate_shader_objects = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_attrib_64bit = ogl_LOAD_FAILED;
	ogl_ext_ARB_viewport_array = ogl_LOAD_FAILED;
	ogl_ext_ARB_base_instance = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_420pack = ogl_LOAD_FAILED;
	ogl_ext_ARB_transform_feedback_instanced = ogl_LOAD_FAILED;
	ogl_ext_ARB_compressed_texture_pixel_storage = ogl_LOAD_FAILED;
	ogl_ext_ARB_conservative_depth = ogl_LOAD_FAILED;
	ogl_ext_ARB_internalformat_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_map_buffer_alignment = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_atomic_counters = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_image_load_store = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_packing = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_storage = ogl_LOAD_FAILED;
	ogl_ext_KHR_debug = ogl_LOAD_FAILED;
	ogl_ext_ARB_arrays_of_arrays = ogl_LOAD_FAILED;
	ogl_ext_ARB_clear_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_compute_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_copy_image = ogl_LOAD_FAILED;
	ogl_ext_ARB_ES3_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_explicit_uniform_location = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_layer_viewport = ogl_LOAD_FAILED;
	ogl_ext_ARB_framebuffer_no_attachments = ogl_LOAD_FAILED;
	ogl_ext_ARB_internalformat_query2 = ogl_LOAD_FAILED;
	ogl_ext_ARB_invalidate_subdata = ogl_LOAD_FAILED;
	ogl_ext_ARB_multi_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_ARB_program_interface_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_image_size = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_storage_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_stencil_texturing = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_buffer_range = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_query_levels = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_storage_multisample = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_view = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_attrib_binding = ogl_LOAD_FAILED;
	ogl_ext_ARB_buffer_storage = ogl_LOAD_FAILED;
	ogl_ext_ARB_clear_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_enhanced_layouts = ogl_LOAD_FAILED;
	ogl_ext_ARB_multi_bind = ogl_LOAD_FAILED;
	ogl_ext_ARB_query_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_mirror_clamp_to_edge = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_stencil8 = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_type_10f_11f_11f_rev = ogl_LOAD_FAILED;
	ogl_ext_3DFX_multisample = ogl_LOAD_FAILED;
	ogl_ext_3DFX_tbuffer = ogl_LOAD_FAILED;
	ogl_ext_3DFX_texture_compression_FXT1 = ogl_LOAD_FAILED;
	ogl_ext_AMD_blend_minmax_factor = ogl_LOAD_FAILED;
	ogl_ext_AMD_conservative_depth = ogl_LOAD_FAILED;
	ogl_ext_AMD_debug_output = ogl_LOAD_FAILED;
	ogl_ext_AMD_depth_clamp_separate = ogl_LOAD_FAILED;
	ogl_ext_AMD_draw_buffers_blend = ogl_LOAD_FAILED;
	ogl_ext_AMD_interleaved_elements = ogl_LOAD_FAILED;
	ogl_ext_AMD_multi_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_AMD_name_gen_delete = ogl_LOAD_FAILED;
	ogl_ext_AMD_performance_monitor = ogl_LOAD_FAILED;
	ogl_ext_AMD_pinned_memory = ogl_LOAD_FAILED;
	ogl_ext_AMD_query_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_AMD_sample_positions = ogl_LOAD_FAILED;
	ogl_ext_AMD_seamless_cubemap_per_texture = ogl_LOAD_FAILED;
	ogl_ext_AMD_shader_stencil_export = ogl_LOAD_FAILED;
	ogl_ext_AMD_shader_trinary_minmax = ogl_LOAD_FAILED;
	ogl_ext_AMD_sparse_texture = ogl_LOAD_FAILED;
	ogl_ext_AMD_stencil_operation_extended = ogl_LOAD_FAILED;
	ogl_ext_AMD_texture_texture4 = ogl_LOAD_FAILED;
	ogl_ext_AMD_transform_feedback3_lines_triangles = ogl_LOAD_FAILED;
	ogl_ext_AMD_vertex_shader_layer = ogl_LOAD_FAILED;
	ogl_ext_AMD_vertex_shader_tessellator = ogl_LOAD_FAILED;
	ogl_ext_AMD_vertex_shader_viewport_index = ogl_LOAD_FAILED;
	ogl_ext_APPLE_aux_depth_stencil = ogl_LOAD_FAILED;
	ogl_ext_APPLE_client_storage = ogl_LOAD_FAILED;
	ogl_ext_APPLE_element_array = ogl_LOAD_FAILED;
	ogl_ext_APPLE_fence = ogl_LOAD_FAILED;
	ogl_ext_APPLE_float_pixels = ogl_LOAD_FAILED;
	ogl_ext_APPLE_flush_buffer_range = ogl_LOAD_FAILED;
	ogl_ext_APPLE_object_purgeable = ogl_LOAD_FAILED;
	ogl_ext_APPLE_rgb_422 = ogl_LOAD_FAILED;
	ogl_ext_APPLE_row_bytes = ogl_LOAD_FAILED;
	ogl_ext_APPLE_specular_vector = ogl_LOAD_FAILED;
	ogl_ext_APPLE_texture_range = ogl_LOAD_FAILED;
	ogl_ext_APPLE_transform_hint = ogl_LOAD_FAILED;
	ogl_ext_APPLE_vertex_array_object = ogl_LOAD_FAILED;
	ogl_ext_APPLE_vertex_array_range = ogl_LOAD_FAILED;
	ogl_ext_APPLE_vertex_program_evaluators = ogl_LOAD_FAILED;
	ogl_ext_APPLE_ycbcr_422 = ogl_LOAD_FAILED;
	ogl_ext_ARB_bindless_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_cl_event = ogl_LOAD_FAILED;
	ogl_ext_ARB_color_buffer_float = ogl_LOAD_FAILED;
	ogl_ext_ARB_compatibility = ogl_LOAD_FAILED;
	ogl_ext_ARB_compute_variable_group_size = ogl_LOAD_FAILED;
	ogl_ext_ARB_debug_output = ogl_LOAD_FAILED;
	ogl_ext_ARB_depth_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_buffers = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_buffers_blend = ogl_LOAD_FAILED;
	ogl_ext_ARB_draw_instanced = ogl_LOAD_FAILED;
	ogl_ext_ARB_explicit_attrib_location = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_program = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_program_shadow = ogl_LOAD_FAILED;
	ogl_ext_ARB_fragment_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_geometry_shader4 = ogl_LOAD_FAILED;
	ogl_ext_ARB_half_float_pixel = ogl_LOAD_FAILED;
	ogl_ext_ARB_indirect_parameters = ogl_LOAD_FAILED;
	ogl_ext_ARB_instanced_arrays = ogl_LOAD_FAILED;
	ogl_ext_ARB_matrix_palette = ogl_LOAD_FAILED;
	ogl_ext_ARB_multisample = ogl_LOAD_FAILED;
	ogl_ext_ARB_multitexture = ogl_LOAD_FAILED;
	ogl_ext_ARB_occlusion_query = ogl_LOAD_FAILED;
	ogl_ext_ARB_pixel_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_point_parameters = ogl_LOAD_FAILED;
	ogl_ext_ARB_point_sprite = ogl_LOAD_FAILED;
	ogl_ext_ARB_robust_buffer_access_behavior = ogl_LOAD_FAILED;
	ogl_ext_ARB_robustness = ogl_LOAD_FAILED;
	ogl_ext_ARB_robustness_isolation = ogl_LOAD_FAILED;
	ogl_ext_ARB_sample_shading = ogl_LOAD_FAILED;
	ogl_ext_ARB_seamless_cubemap_per_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_bit_encoding = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_draw_parameters = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_group_vote = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_objects = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_precision = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_stencil_export = ogl_LOAD_FAILED;
	ogl_ext_ARB_shader_texture_lod = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_100 = ogl_LOAD_FAILED;
	ogl_ext_ARB_shading_language_include = ogl_LOAD_FAILED;
	ogl_ext_ARB_shadow = ogl_LOAD_FAILED;
	ogl_ext_ARB_shadow_ambient = ogl_LOAD_FAILED;
	ogl_ext_ARB_sparse_texture = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_border_clamp = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_buffer_object_rgb32 = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_compression = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_compression_bptc = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_cube_map = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_cube_map_array = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_add = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_combine = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_crossbar = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_env_dot3 = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_float = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_gather = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_mirrored_repeat = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_non_power_of_two = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_query_lod = ogl_LOAD_FAILED;
	ogl_ext_ARB_texture_rectangle = ogl_LOAD_FAILED;
	ogl_ext_ARB_transpose_matrix = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_blend = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_program = ogl_LOAD_FAILED;
	ogl_ext_ARB_vertex_shader = ogl_LOAD_FAILED;
	ogl_ext_ARB_window_pos = ogl_LOAD_FAILED;
	ogl_ext_ATI_draw_buffers = ogl_LOAD_FAILED;
	ogl_ext_ATI_element_array = ogl_LOAD_FAILED;
	ogl_ext_ATI_envmap_bumpmap = ogl_LOAD_FAILED;
	ogl_ext_ATI_fragment_shader = ogl_LOAD_FAILED;
	ogl_ext_ATI_map_object_buffer = ogl_LOAD_FAILED;
	ogl_ext_ATI_meminfo = ogl_LOAD_FAILED;
	ogl_ext_ATI_pixel_format_float = ogl_LOAD_FAILED;
	ogl_ext_ATI_pn_triangles = ogl_LOAD_FAILED;
	ogl_ext_ATI_separate_stencil = ogl_LOAD_FAILED;
	ogl_ext_ATI_text_fragment_shader = ogl_LOAD_FAILED;
	ogl_ext_ATI_texture_env_combine3 = ogl_LOAD_FAILED;
	ogl_ext_ATI_texture_float = ogl_LOAD_FAILED;
	ogl_ext_ATI_texture_mirror_once = ogl_LOAD_FAILED;
	ogl_ext_ATI_vertex_array_object = ogl_LOAD_FAILED;
	ogl_ext_ATI_vertex_attrib_array_object = ogl_LOAD_FAILED;
	ogl_ext_ATI_vertex_streams = ogl_LOAD_FAILED;
	ogl_ext_EXT_422_pixels = ogl_LOAD_FAILED;
	ogl_ext_EXT_abgr = ogl_LOAD_FAILED;
	ogl_ext_EXT_bgra = ogl_LOAD_FAILED;
	ogl_ext_EXT_bindable_uniform = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_color = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_equation_separate = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_func_separate = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_logic_op = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_minmax = ogl_LOAD_FAILED;
	ogl_ext_EXT_blend_subtract = ogl_LOAD_FAILED;
	ogl_ext_EXT_clip_volume_hint = ogl_LOAD_FAILED;
	ogl_ext_EXT_cmyka = ogl_LOAD_FAILED;
	ogl_ext_EXT_color_subtable = ogl_LOAD_FAILED;
	ogl_ext_EXT_compiled_vertex_array = ogl_LOAD_FAILED;
	ogl_ext_EXT_convolution = ogl_LOAD_FAILED;
	ogl_ext_EXT_coordinate_frame = ogl_LOAD_FAILED;
	ogl_ext_EXT_copy_texture = ogl_LOAD_FAILED;
	ogl_ext_EXT_cull_vertex = ogl_LOAD_FAILED;
	ogl_ext_EXT_depth_bounds_test = ogl_LOAD_FAILED;
	ogl_ext_EXT_direct_state_access = ogl_LOAD_FAILED;
	ogl_ext_EXT_draw_buffers2 = ogl_LOAD_FAILED;
	ogl_ext_EXT_draw_instanced = ogl_LOAD_FAILED;
	ogl_ext_EXT_draw_range_elements = ogl_LOAD_FAILED;
	ogl_ext_EXT_fog_coord = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_blit = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_multisample = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_multisample_blit_scaled = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_framebuffer_sRGB = ogl_LOAD_FAILED;
	ogl_ext_EXT_geometry_shader4 = ogl_LOAD_FAILED;
	ogl_ext_EXT_gpu_program_parameters = ogl_LOAD_FAILED;
	ogl_ext_EXT_gpu_shader4 = ogl_LOAD_FAILED;
	ogl_ext_EXT_histogram = ogl_LOAD_FAILED;
	ogl_ext_EXT_index_array_formats = ogl_LOAD_FAILED;
	ogl_ext_EXT_index_func = ogl_LOAD_FAILED;
	ogl_ext_EXT_index_material = ogl_LOAD_FAILED;
	ogl_ext_EXT_index_texture = ogl_LOAD_FAILED;
	ogl_ext_EXT_light_texture = ogl_LOAD_FAILED;
	ogl_ext_EXT_misc_attribute = ogl_LOAD_FAILED;
	ogl_ext_EXT_multi_draw_arrays = ogl_LOAD_FAILED;
	ogl_ext_EXT_multisample = ogl_LOAD_FAILED;
	ogl_ext_EXT_packed_depth_stencil = ogl_LOAD_FAILED;
	ogl_ext_EXT_packed_float = ogl_LOAD_FAILED;
	ogl_ext_EXT_packed_pixels = ogl_LOAD_FAILED;
	ogl_ext_EXT_paletted_texture = ogl_LOAD_FAILED;
	ogl_ext_EXT_pixel_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_pixel_transform = ogl_LOAD_FAILED;
	ogl_ext_EXT_pixel_transform_color_table = ogl_LOAD_FAILED;
	ogl_ext_EXT_point_parameters = ogl_LOAD_FAILED;
	ogl_ext_EXT_polygon_offset = ogl_LOAD_FAILED;
	ogl_ext_EXT_provoking_vertex = ogl_LOAD_FAILED;
	ogl_ext_EXT_rescale_normal = ogl_LOAD_FAILED;
	ogl_ext_EXT_secondary_color = ogl_LOAD_FAILED;
	ogl_ext_EXT_separate_shader_objects = ogl_LOAD_FAILED;
	ogl_ext_EXT_separate_specular_color = ogl_LOAD_FAILED;
	ogl_ext_EXT_shader_image_load_store = ogl_LOAD_FAILED;
	ogl_ext_EXT_shadow_funcs = ogl_LOAD_FAILED;
	ogl_ext_EXT_shared_texture_palette = ogl_LOAD_FAILED;
	ogl_ext_EXT_stencil_clear_tag = ogl_LOAD_FAILED;
	ogl_ext_EXT_stencil_two_side = ogl_LOAD_FAILED;
	ogl_ext_EXT_stencil_wrap = ogl_LOAD_FAILED;
	ogl_ext_EXT_subtexture = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture3D = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_array = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_compression_latc = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_compression_rgtc = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_compression_s3tc = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_cube_map = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_env_add = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_env_combine = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_env_dot3 = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_filter_anisotropic = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_integer = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_lod_bias = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_mirror_clamp = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_object = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_perturb_normal = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_sRGB = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_sRGB_decode = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_shared_exponent = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_snorm = ogl_LOAD_FAILED;
	ogl_ext_EXT_texture_swizzle = ogl_LOAD_FAILED;
	ogl_ext_EXT_timer_query = ogl_LOAD_FAILED;
	ogl_ext_EXT_transform_feedback = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_array = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_array_bgra = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_attrib_64bit = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_shader = ogl_LOAD_FAILED;
	ogl_ext_EXT_vertex_weighting = ogl_LOAD_FAILED;
	ogl_ext_EXT_x11_sync_object = ogl_LOAD_FAILED;
	ogl_ext_GREMEDY_frame_terminator = ogl_LOAD_FAILED;
	ogl_ext_GREMEDY_string_marker = ogl_LOAD_FAILED;
	ogl_ext_HP_convolution_border_modes = ogl_LOAD_FAILED;
	ogl_ext_HP_image_transform = ogl_LOAD_FAILED;
	ogl_ext_HP_occlusion_test = ogl_LOAD_FAILED;
	ogl_ext_HP_texture_lighting = ogl_LOAD_FAILED;
	ogl_ext_IBM_cull_vertex = ogl_LOAD_FAILED;
	ogl_ext_IBM_multimode_draw_arrays = ogl_LOAD_FAILED;
	ogl_ext_IBM_rasterpos_clip = ogl_LOAD_FAILED;
	ogl_ext_IBM_static_data = ogl_LOAD_FAILED;
	ogl_ext_IBM_texture_mirrored_repeat = ogl_LOAD_FAILED;
	ogl_ext_IBM_vertex_array_lists = ogl_LOAD_FAILED;
	ogl_ext_INGR_blend_func_separate = ogl_LOAD_FAILED;
	ogl_ext_INGR_color_clamp = ogl_LOAD_FAILED;
	ogl_ext_INGR_interlace_read = ogl_LOAD_FAILED;
	ogl_ext_INTEL_map_texture = ogl_LOAD_FAILED;
	ogl_ext_INTEL_parallel_arrays = ogl_LOAD_FAILED;
	ogl_ext_KHR_texture_compression_astc_ldr = ogl_LOAD_FAILED;
	ogl_ext_MESAX_texture_stack = ogl_LOAD_FAILED;
	ogl_ext_MESA_pack_invert = ogl_LOAD_FAILED;
	ogl_ext_MESA_resize_buffers = ogl_LOAD_FAILED;
	ogl_ext_MESA_window_pos = ogl_LOAD_FAILED;
	ogl_ext_MESA_ycbcr_texture = ogl_LOAD_FAILED;
	ogl_ext_NVX_conditional_render = ogl_LOAD_FAILED;
	ogl_ext_NV_bindless_multi_draw_indirect = ogl_LOAD_FAILED;
	ogl_ext_NV_bindless_texture = ogl_LOAD_FAILED;
	ogl_ext_NV_blend_equation_advanced = ogl_LOAD_FAILED;
	ogl_ext_NV_blend_equation_advanced_coherent = ogl_LOAD_FAILED;
	ogl_ext_NV_blend_square = ogl_LOAD_FAILED;
	ogl_ext_NV_compute_program5 = ogl_LOAD_FAILED;
	ogl_ext_NV_conditional_render = ogl_LOAD_FAILED;
	ogl_ext_NV_copy_depth_to_color = ogl_LOAD_FAILED;
	ogl_ext_NV_copy_image = ogl_LOAD_FAILED;
	ogl_ext_NV_deep_texture3D = ogl_LOAD_FAILED;
	ogl_ext_NV_depth_buffer_float = ogl_LOAD_FAILED;
	ogl_ext_NV_depth_clamp = ogl_LOAD_FAILED;
	ogl_ext_NV_draw_texture = ogl_LOAD_FAILED;
	ogl_ext_NV_evaluators = ogl_LOAD_FAILED;
	ogl_ext_NV_explicit_multisample = ogl_LOAD_FAILED;
	ogl_ext_NV_fence = ogl_LOAD_FAILED;
	ogl_ext_NV_float_buffer = ogl_LOAD_FAILED;
	ogl_ext_NV_fog_distance = ogl_LOAD_FAILED;
	ogl_ext_NV_fragment_program = ogl_LOAD_FAILED;
	ogl_ext_NV_fragment_program2 = ogl_LOAD_FAILED;
	ogl_ext_NV_fragment_program4 = ogl_LOAD_FAILED;
	ogl_ext_NV_fragment_program_option = ogl_LOAD_FAILED;
	ogl_ext_NV_framebuffer_multisample_coverage = ogl_LOAD_FAILED;
	ogl_ext_NV_geometry_program4 = ogl_LOAD_FAILED;
	ogl_ext_NV_geometry_shader4 = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_program4 = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_program5 = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_program5_mem_extended = ogl_LOAD_FAILED;
	ogl_ext_NV_gpu_shader5 = ogl_LOAD_FAILED;
	ogl_ext_NV_half_float = ogl_LOAD_FAILED;
	ogl_ext_NV_light_max_exponent = ogl_LOAD_FAILED;
	ogl_ext_NV_multisample_coverage = ogl_LOAD_FAILED;
	ogl_ext_NV_multisample_filter_hint = ogl_LOAD_FAILED;
	ogl_ext_NV_occlusion_query = ogl_LOAD_FAILED;
	ogl_ext_NV_packed_depth_stencil = ogl_LOAD_FAILED;
	ogl_ext_NV_parameter_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_NV_parameter_buffer_object2 = ogl_LOAD_FAILED;
	ogl_ext_NV_path_rendering = ogl_LOAD_FAILED;
	ogl_ext_NV_pixel_data_range = ogl_LOAD_FAILED;
	ogl_ext_NV_point_sprite = ogl_LOAD_FAILED;
	ogl_ext_NV_present_video = ogl_LOAD_FAILED;
	ogl_ext_NV_primitive_restart = ogl_LOAD_FAILED;
	ogl_ext_NV_register_combiners = ogl_LOAD_FAILED;
	ogl_ext_NV_register_combiners2 = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_atomic_counters = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_atomic_float = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_buffer_load = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_buffer_store = ogl_LOAD_FAILED;
	ogl_ext_NV_shader_storage_buffer_object = ogl_LOAD_FAILED;
	ogl_ext_NV_tessellation_program5 = ogl_LOAD_FAILED;
	ogl_ext_NV_texgen_emboss = ogl_LOAD_FAILED;
	ogl_ext_NV_texgen_reflection = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_barrier = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_compression_vtc = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_env_combine4 = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_expand_normal = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_multisample = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_rectangle = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_shader = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_shader2 = ogl_LOAD_FAILED;
	ogl_ext_NV_texture_shader3 = ogl_LOAD_FAILED;
	ogl_ext_NV_transform_feedback = ogl_LOAD_FAILED;
	ogl_ext_NV_transform_feedback2 = ogl_LOAD_FAILED;
	ogl_ext_NV_vdpau_interop = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_array_range = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_array_range2 = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_attrib_integer_64bit = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_buffer_unified_memory = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program1_1 = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program2 = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program2_option = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program3 = ogl_LOAD_FAILED;
	ogl_ext_NV_vertex_program4 = ogl_LOAD_FAILED;
	ogl_ext_NV_video_capture = ogl_LOAD_FAILED;
	ogl_ext_OES_byte_coordinates = ogl_LOAD_FAILED;
	ogl_ext_OES_compressed_paletted_texture = ogl_LOAD_FAILED;
	ogl_ext_OES_fixed_point = ogl_LOAD_FAILED;
	ogl_ext_OES_query_matrix = ogl_LOAD_FAILED;
	ogl_ext_OES_read_format = ogl_LOAD_FAILED;
	ogl_ext_OES_single_precision = ogl_LOAD_FAILED;
	ogl_ext_OML_interlace = ogl_LOAD_FAILED;
	ogl_ext_OML_resample = ogl_LOAD_FAILED;
	ogl_ext_OML_subsample = ogl_LOAD_FAILED;
	ogl_ext_PGI_misc_hints = ogl_LOAD_FAILED;
	ogl_ext_PGI_vertex_hints = ogl_LOAD_FAILED;
	ogl_ext_REND_screen_coordinates = ogl_LOAD_FAILED;
	ogl_ext_S3_s3tc = ogl_LOAD_FAILED;
	ogl_ext_SGIS_detail_texture = ogl_LOAD_FAILED;
	ogl_ext_SGIS_fog_function = ogl_LOAD_FAILED;
	ogl_ext_SGIS_generate_mipmap = ogl_LOAD_FAILED;
	ogl_ext_SGIS_multisample = ogl_LOAD_FAILED;
	ogl_ext_SGIS_pixel_texture = ogl_LOAD_FAILED;
	ogl_ext_SGIS_point_line_texgen = ogl_LOAD_FAILED;
	ogl_ext_SGIS_point_parameters = ogl_LOAD_FAILED;
	ogl_ext_SGIS_sharpen_texture = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture4D = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture_border_clamp = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture_color_mask = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture_edge_clamp = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture_filter4 = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture_lod = ogl_LOAD_FAILED;
	ogl_ext_SGIS_texture_select = ogl_LOAD_FAILED;
	ogl_ext_SGIX_async = ogl_LOAD_FAILED;
	ogl_ext_SGIX_async_histogram = ogl_LOAD_FAILED;
	ogl_ext_SGIX_async_pixel = ogl_LOAD_FAILED;
	ogl_ext_SGIX_blend_alpha_minmax = ogl_LOAD_FAILED;
	ogl_ext_SGIX_calligraphic_fragment = ogl_LOAD_FAILED;
	ogl_ext_SGIX_clipmap = ogl_LOAD_FAILED;
	ogl_ext_SGIX_convolution_accuracy = ogl_LOAD_FAILED;
	ogl_ext_SGIX_depth_pass_instrument = ogl_LOAD_FAILED;
	ogl_ext_SGIX_depth_texture = ogl_LOAD_FAILED;
	ogl_ext_SGIX_flush_raster = ogl_LOAD_FAILED;
	ogl_ext_SGIX_fog_offset = ogl_LOAD_FAILED;
	ogl_ext_SGIX_fragment_lighting = ogl_LOAD_FAILED;
	ogl_ext_SGIX_framezoom = ogl_LOAD_FAILED;
	ogl_ext_SGIX_igloo_interface = ogl_LOAD_FAILED;
	ogl_ext_SGIX_instruments = ogl_LOAD_FAILED;
	ogl_ext_SGIX_interlace = ogl_LOAD_FAILED;
	ogl_ext_SGIX_ir_instrument1 = ogl_LOAD_FAILED;
	ogl_ext_SGIX_list_priority = ogl_LOAD_FAILED;
	ogl_ext_SGIX_pixel_texture = ogl_LOAD_FAILED;
	ogl_ext_SGIX_pixel_tiles = ogl_LOAD_FAILED;
	ogl_ext_SGIX_polynomial_ffd = ogl_LOAD_FAILED;
	ogl_ext_SGIX_reference_plane = ogl_LOAD_FAILED;
	ogl_ext_SGIX_resample = ogl_LOAD_FAILED;
	ogl_ext_SGIX_scalebias_hint = ogl_LOAD_FAILED;
	ogl_ext_SGIX_shadow = ogl_LOAD_FAILED;
	ogl_ext_SGIX_shadow_ambient = ogl_LOAD_FAILED;
	ogl_ext_SGIX_sprite = ogl_LOAD_FAILED;
	ogl_ext_SGIX_subsample = ogl_LOAD_FAILED;
	ogl_ext_SGIX_tag_sample_buffer = ogl_LOAD_FAILED;
	ogl_ext_SGIX_texture_add_env = ogl_LOAD_FAILED;
	ogl_ext_SGIX_texture_coordinate_clamp = ogl_LOAD_FAILED;
	ogl_ext_SGIX_texture_lod_bias = ogl_LOAD_FAILED;
	ogl_ext_SGIX_texture_multi_buffer = ogl_LOAD_FAILED;
	ogl_ext_SGIX_texture_scale_bias = ogl_LOAD_FAILED;
	ogl_ext_SGIX_vertex_preclip = ogl_LOAD_FAILED;
	ogl_ext_SGIX_ycrcb = ogl_LOAD_FAILED;
	ogl_ext_SGIX_ycrcb_subsample = ogl_LOAD_FAILED;
	ogl_ext_SGIX_ycrcba = ogl_LOAD_FAILED;
	ogl_ext_SGI_color_matrix = ogl_LOAD_FAILED;
	ogl_ext_SGI_color_table = ogl_LOAD_FAILED;
	ogl_ext_SGI_texture_color_table = ogl_LOAD_FAILED;
	ogl_ext_SUNX_constant_data = ogl_LOAD_FAILED;
	ogl_ext_SUN_convolution_border_modes = ogl_LOAD_FAILED;
	ogl_ext_SUN_global_alpha = ogl_LOAD_FAILED;
	ogl_ext_SUN_mesh_array = ogl_LOAD_FAILED;
	ogl_ext_SUN_slice_accum = ogl_LOAD_FAILED;
	ogl_ext_SUN_triangle_list = ogl_LOAD_FAILED;
	ogl_ext_SUN_vertex = ogl_LOAD_FAILED;
	ogl_ext_WIN_phong_shading = ogl_LOAD_FAILED;
	ogl_ext_WIN_specular_fog = ogl_LOAD_FAILED;
}


static void LoadExtByName(const char *extensionName)
{
	ogl_StrToExtMap *entry = NULL;
	entry = FindExtEntry(extensionName);
	if(entry)
	{
		if(entry->LoadExtension)
		{
			int numFailed = entry->LoadExtension();
			if(numFailed == 0)
			{
				*(entry->extensionVariable) = ogl_LOAD_SUCCEEDED;
			}
			else
			{
				*(entry->extensionVariable) = ogl_LOAD_SUCCEEDED + numFailed;
			}
		}
		else
		{
			*(entry->extensionVariable) = ogl_LOAD_SUCCEEDED;
		}
	}
}


static void ProcExtsFromExtList()
{
	GLint iLoop;
	GLint iNumExtensions = 0;
	_ptrc_glGetIntegerv(GL_NUM_EXTENSIONS, &iNumExtensions);

	for(iLoop = 0; iLoop < iNumExtensions; iLoop++)
	{
		const char *strExtensionName = (const char *)_ptrc_glGetStringi(GL_EXTENSIONS, iLoop);
		LoadExtByName(strExtensionName);
	}
}

int ogl_LoadFunctions()
{
	int numFailed = 0;
	ClearExtensionVars();
	
	_ptrc_glGetIntegerv = (void (CODEGEN_FUNCPTR *)(GLenum, GLint *))IntGetProcAddress("glGetIntegerv");
	if(!_ptrc_glGetIntegerv) return ogl_LOAD_FAILED;
	_ptrc_glGetStringi = (const GLubyte * (CODEGEN_FUNCPTR *)(GLenum, GLuint))IntGetProcAddress("glGetStringi");
	if(!_ptrc_glGetStringi) return ogl_LOAD_FAILED;
	
	ProcExtsFromExtList();
	numFailed = Load_Version_4_4();
	
	if(numFailed == 0)
		return ogl_LOAD_SUCCEEDED;
	else
		return ogl_LOAD_SUCCEEDED + numFailed;
}

static int g_major_version = 0;
static int g_minor_version = 0;

static void GetGLVersion()
{
	glGetIntegerv(GL_MAJOR_VERSION, &g_major_version);
	glGetIntegerv(GL_MINOR_VERSION, &g_minor_version);
}

int ogl_GetMajorVersion()
{
	if(g_major_version == 0)
		GetGLVersion();
	return g_major_version;
}

int ogl_GetMinorVersion()
{
	if(g_major_version == 0) //Yes, check the major version to get the minor one.
		GetGLVersion();
	return g_minor_version;
}

int ogl_IsVersionGEQ(int majorVersion, int minorVersion)
{
	if(g_major_version == 0)
		GetGLVersion();
		
	if(majorVersion > g_major_version) return 1;
	if(majorVersion < g_major_version) return 0;
	if(minorVersion >= g_minor_version) return 1;
	return 0;
}

