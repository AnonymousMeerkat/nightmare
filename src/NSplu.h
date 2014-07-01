#ifndef _NME_SPLU_H
#define _NME_SPLU_H

#include "NCompat.h"

START_HEAD

#include "NTypes.h"
#include "NRect.h"
#include "wrap/gl.h"

NRectf Nsplu_calc_viewport();

GLKMatrix4 Nsplu_calc_pos(GLKVector2 pos);
GLKMatrix4 Nsplu_calc_rect(GLKVector2 pos, GLKVector2 size);
GLKMatrix4 Nsplu_calc_mvp();

END_HEAD

#endif
