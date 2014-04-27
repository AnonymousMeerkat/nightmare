#ifndef _SP_GLOBALS_H
#define _SP_GLOBALS_H

#include "compat.h"

START_HEAD

/***** TYPES *****/

enum renderer {
    OPENGL1 = 0,
    OPENGL2 = 1,

    DX9 = 10,
    DX10 = 11,
    DX11 = 12,
    DX12 = 13,

    MANTLE = 20
};

/***** FUNCTIONS *****/

void globals_init();
void globals_destroy();

/***** WINDOW *****/

short win_x;
short win_y;
short win_width;
short win_height;

/***** LOGGING *****/

short info_indent;
short debug_indent;
short error_indent;

/***** RENDERING *****/

short fps;
enum renderer renderer;

/***** GAME *****/

END_HEAD

#endif
