#ifndef _SP_GLOBALS_H
#define _SP_GLOBALS_H

#include "compat.h"

#include "types.h"
#include "misc.h"

START_HEAD

// Functions

void globals_init();
void globals_destroy();

// Init

extern int init_argc;
extern char** init_argv;

// Window

extern short win_x;
extern short win_y;
extern short win_width;
extern short win_height;
extern char* win_title;

// Logging

extern short log_indent;

// Resource

extern char* rsc_path;

// OpenGL

extern GLKMatrix4 gl_projection;
extern GLKMatrix4 gl_view;
extern GLKMatrix4 gl_model;

// Shader
TS(Shader);

extern Shader* shader_image;

// Input

extern bool key_states[256];

// Game

extern bool running;
extern uint delta;
extern uint lasttime;
extern uint currtime;
extern uint lastsecond;
extern uint fps;

END_HEAD

#endif
