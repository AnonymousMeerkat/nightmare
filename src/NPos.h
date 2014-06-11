#ifndef _NME_POS_H
#define _NME_POS_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NTypes.h"

#define NPosf float
#define NPosi int

/*NSTRUCT(NPos2f, {
    NPosf x;
    NPosf y;
});*/

typedef GLKVector2 NPos2f;

static const NPos2f NPos2f0;

static inline NPos2f Npos2f(NPosf x, NPosf y) {
    NPos2f ret = {x, y};
    return ret;
}

NSTRUCT(NPos2i, {
    NPosi x;
    NPosi y;
});

static const NPos2i NPos2i0;

static inline NPos2i Npos2i(NPosi x, NPosi y) {
    NPos2i ret = {x, y};
    return ret;
}

static inline GLKVector2 GLKpos2i(NPos2i pos) {
    GLKVector2 vec2;
    vec2.x = pos.x;
    vec2.y = pos.y;
    return vec2;
}

END_HEAD

#endif
