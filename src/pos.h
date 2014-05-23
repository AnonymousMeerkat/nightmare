#ifndef _SP_POS_H
#define _SP_POS_H

#include "compat.h"

#include "misc.h"

START_HEAD

#define Posf float
#define Posi int

STRUCT(Pos2f, {
    Posf x;
    Posf y;
});

static const Pos2f Pos2fblank;

static inline Pos2f pos2f(Posf x, Posf y) {
    Pos2f ret = {x, y};
    return ret;
}

STRUCT(Pos2i, {
    Posi x;
    Posi y;
});

static const Pos2i Pos2iblank;

static inline Pos2i pos2i(Posi x, Posi y) {
    Pos2i ret = {x, y};
    return ret;
}

END_HEAD

#endif
