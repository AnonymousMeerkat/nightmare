#ifndef _NME_SQUARE_H
#define _NME_SQUARE_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NPos.h"
#include "wrap/gl.h"
#include "NTypes.h"

NTS(NShader);

extern GLuint NSquare_id;

void NSquare_init();
void NSquare_destroy();

void NSquare_draw_shape();
void NSquare_draw(NShader* shader, NPos2i pos, NPos2i size, bool flip);

END_HEAD

#endif
