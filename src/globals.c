#include "globals.h"

#include <stdlib.h>


int init_argc;
char** init_argv;

short win_x;
short win_y;
short win_width;
short win_height;
char* win_title;

short log_indent;

char* rsc_path;

GLKMatrix4 gl_projection;
GLKMatrix4 gl_view;
GLKMatrix4 gl_model;

Shader* shader_image;

bool key_states[256];

bool running;
uint delta;
uint lasttime;
uint currtime;
uint lastsecond;
uint fps;


void globals_init() {
    win_x = 0;
    win_y = 0;
    win_width = 800;
    win_height = 600;
    win_title = "Silent Ponyville";

    log_indent = 0;

    rsc_path = "";

    shader_image = NULL;

    running = true;
    delta = 0;
    lasttime = 0;
    currtime = 0;
    lastsecond = 0;
    fps = 0;
}

void globals_destroy() {
    return; // Useless
}
