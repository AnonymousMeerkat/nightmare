#ifndef _SP_POS_H
#define _SP_POS_H

#include "compat.h"

#include "misc.h"

START_HEAD

#define pos_float float
#define pos_int int

STRUCT(Pos2f, {
    pos_float x;
    pos_float y;
});

static const Pos2f Pos2fblank;

STRUCT(Pos2i, {
    pos_int x;
    pos_int y;
});

static const Pos2i Pos2iblank;

END_HEAD

#endif
