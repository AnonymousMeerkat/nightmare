#ifndef _NME_GLOBALS_H
#define _NME_GLOBALS_H

#include "NCompat.h"

START_HEAD

#include "NTypes.h"
#include "NUtil.h"
#include "NPos.h"

// Exports
NTS(NShader);
NTS(NImage);
NTS(NSpritesheet);
NTS(NLevel);
NTS(NEntity);
NTS(NShader_info);
NTS(NSpritesheet_data);
NTS(NSpritesheet_info);
NTS(NLevel_info);
NTS(NDLL_info);

#define N_SHADER_IMAGE 0


#ifndef NMEX
// Functions

void NGlobals_init();
void NGlobals_destroy();

// Init

extern int N_argc;
extern char** N_argv;

// Window

extern NPos2i N_win_pos;
extern NPos2i N_win_size;
extern char* N_win_title;

// Logging

extern short N_indent;

// Resource

extern char* N_rsc_path;

// OpenGL

extern GLKMatrix4 N_gl_projection;
extern GLKMatrix4 N_gl_view;
extern GLKMatrix4 N_gl_model;

// Resource Pool

extern NShader** N_shaders;
extern NImage** N_images;
extern NSpritesheet** N_spritesheets;
extern NLevel** N_levels;
extern NEntity* N_player;

// Input

extern bool N_key_states[65536];

// Game.{dll|so}

typedef void* NDLL;

extern NDLL* N_dll;

extern void (*Ndll_init)(int argc, char** argv);
extern void (*Ndll_destroy)();

extern void (*Ndll_loop)(NDLL_info info);


extern NShader_info* N_dll_shader_infos;
extern char** N_dll_image_infos;
extern NSpritesheet_info* N_dll_spritesheet_infos;
extern NLevel_info* N_dll_level_infos;

// Game

extern bool N_running;
extern uint N_delta;
extern uint N_lasttime;
extern uint N_currtime;
extern uint N_lastsecond;
extern uint N_fps;

extern NShader* N_shader;

#else

void NGlobals_set_size(NPos2i size);
NPos2i NGlobals_get_size();

void NGlobals_set_title(char* title);
char* NGlobals_get_title();

void NGlobals_indent_inc();
void NGlobals_indent_dec();

NShader** NGlobals_get_shaders();

#endif

END_HEAD

#endif
