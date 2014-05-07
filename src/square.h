#ifndef _SP_SQUARE_H
#define _SP_SQUARE_H

#include "compat.h"

START_HEAD

#include "wrap/gl.h"

extern GLuint square_id;

void square_init();
void square_destroy();

void square_draw();

END_HEAD

#endif
