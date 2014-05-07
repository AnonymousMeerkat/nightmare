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

int init_argc;
char** init_argv;

// Window

short win_x;
short win_y;
short win_width;
short win_height;
char* win_title;

// Logging

short log_indent;

// Resource

char* rsc_path;

// OpenGL

GLKMatrix4 gl_projection;
GLKMatrix4 gl_view;
GLKMatrix4 gl_model;

// Shader
TS(Shader);

Shader* shader_image;

// Game

bool running;
uint delta;
uint lasttime;
uint currtime;
uint lastsecond;
uint fps;

END_HEAD

#endif
