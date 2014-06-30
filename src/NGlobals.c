#include "NGlobals.h"

#include "NDynamic_t.h"


int N_argc;
char** N_argv;

NPos2i N_win_pos;
NPos2i N_win_size;
//char* N_win_title;

short N_indent;

char* N_rsc_path;

GLKMatrix4 N_gl_projection;
GLKMatrix4 N_gl_view;
GLKMatrix4 N_gl_model;

NShader** N_shaders;
NImage** N_images;
NSpritesheet** N_spritesheets;
NLevel** N_levels;
NEntity* N_player;

bool N_key_states[65536];

NDLL* N_dll;
void (*Ndll_init)(int argc, char** argv);
void (*Ndll_destroy)();
void (*Ndll_loop)(NDLL_info info);
NShader_info* N_dll_shader_infos;
char** N_dll_image_infos;
NSpritesheet_info* N_dll_spritesheet_infos;
NLevel_info* N_dll_level_infos;

bool N_running;
uint N_delta;
uint N_lasttime;
uint N_currtime;
uint N_lastsecond;
uint N_fps;

NShader* N_shader;


void NGlobals_init() {
    N_win_pos = NPos2i0;
    N_win_size = Npos2i(800, 600);
    //N_win_title = "Nightmare Engine";

    N_indent = 0;

    N_rsc_path = "";

    NLIST_NEW(NShader*, N__shaders);
    N_shaders = N__shaders.data;
    NLIST_NEW(NImage*, N__images);
    N_images = N__images.data;
    NLIST_NEW(NSpritesheet*, N__spritesheets);
    N_spritesheets = N__spritesheets.data;
    NLIST_NEW(NLevel*, N__levels);
    N_levels = N__levels.data;

    N_dll = NULL;
    Ndll_init = NULL;
    Ndll_destroy = NULL;
    Ndll_loop = NULL;
    N_dll_shader_infos = NULL;
    N_dll_spritesheet_infos = NULL;
    N_dll_image_infos = NULL;

    N_running = true;
    N_delta = 0;
    N_lasttime = 0;
    N_currtime = 0;
    N_lastsecond = 0;
    N_fps = 0;

    N_shader = NULL;
}

void NGlobals_destroy() {
    return; // Useless
}
