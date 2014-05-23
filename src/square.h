#ifndef _SP_SQUARE_H
#define _SP_SQUARE_H

#include "compat.h"

START_HEAD

#include "misc.h"
#include "pos.h"
#include "wrap/gl.h"

TS(Shader);

extern GLuint square_id;

void square_init();
void square_destroy();

void square_draw_shape();
void square_draw(Shader* shader, Pos2i pos, Pos2i size);

END_HEAD

#endif
