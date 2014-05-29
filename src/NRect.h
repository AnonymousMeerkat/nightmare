#ifndef _NME_RECT_H
#define _NME_RECT_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NPos.h"

NSTRUCT(NRectf, {
    NPos2f pos;
    NPos2f size;
});

static const NRectf NRectf0;

static inline NRectf Nrectf(NPos2f pos, NPos2f size) {
    NRectf ret = {pos, size};
    return ret;
}

NSTRUCT(NRecti, {
    NPos2i pos;
    NPos2i size;
});

static const NRecti NRecti0;

static inline NRecti Nrecti(NPos2i pos, NPos2i size) {
    NRecti ret = {pos, size};
    return ret;
}

END_HEAD

#endif
