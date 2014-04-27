#ifndef _SP_POS_H
#define _SP_POS_H

#include "compat.h"

START_HEAD

#define pos_float double
#define pos_int int

typedef struct {
    pos_float x, y;
} Pos2f;

typedef struct {
    pos_int x, y;
} Pos2i;

END_HEAD

#endif
