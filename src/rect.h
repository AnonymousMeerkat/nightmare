#ifndef _SP_RECT_H
#define _SP_RECT_H

#include "compat.h"

START_HEAD

#include "pos.h"
#include "misc.h"

STRUCT(Rectf, {
    Pos2f pos;
    Pos2f size;
});

static const Rectf Rectfblank;

static inline Rectf rectf(Pos2f pos, Pos2f size) {
    Rectf ret = {pos, size};
    return ret;
}

STRUCT(Recti, {
    Pos2i pos;
    Pos2i size;
});

static const Recti Rectiblank;

static inline Recti recti(Pos2i pos, Pos2i size) {
    Recti ret = {pos, size};
    return ret;
}

END_HEAD

#endif
