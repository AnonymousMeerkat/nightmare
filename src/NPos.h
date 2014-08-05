/*
    Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Nightmare Project nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _NME_POS_H
#define _NME_POS_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NTypes.h"

#define NPosf float
#define NPosi int
#define NPosz char

/*NSTRUCT(NPos2f, {
    NPosf x;
    NPosf y;
});*/

typedef GLKVector2 NPos2f;

static const NPos2f N_Pos2f0;
#define Npos2f0() {0.,0.}

static inline NPos2f Npos2f(NPosf x, NPosf y) {
    NPos2f ret = {x, y};
    return ret;
}

typedef GLKVector3 NPos3f;

static const NPos3f N_Pos3f0;
#define Npos3f0() {0.,0.,0.}

static inline NPos3f Npos3f(NPosf x, NPosf y, NPosf z) {
    NPos3f ret = {x, y, z};
    return ret;
}


NSTRUCT(NPos2i, {
    NPosi x;
    NPosi y;
});

static const NPos2i N_Pos2i0;
#define Npos2i0() {0,0}

static inline NPos2i Npos2i(NPosi x, NPosi y) {
    NPos2i ret = {x, y};
    return ret;
}

NSTRUCT(NPos3i, {
    NPosi x;
    NPosi y;
    NPosi z;
});

static const NPos3i N_Pos3i0;
#define Npos3i0() {0,0,0}

static inline NPos3i Npos3i(NPosi x, NPosi y, NPosi z) {
    NPos3i ret = {x, y, z};
    return ret;
}

#define header(orig_t, new_t) static inline NPos##new_t Npos##orig_t##_##new_t(NPos##orig_t pos)

#define _2(orig_t, new_t)\
header(orig_t, new_t) {\
    NPos##new_t ret = {pos.x, pos.y};\
    return ret;\
}

#define _2_3(orig_t, new_t)\
header(orig_t, new_t) {\
    NPos##new_t ret = {pos.x, pos.y, 0};\
    return ret;\
}

#define _3_3(orig_t, new_t)\
header(orig_t, new_t) {\
    NPos##new_t ret = {pos.x, pos.y, pos.z};\
    return ret;\
}

_2(2f, 2i);
_2(3i, 2i);
_2(3f, 2i);

_2(2i, 2f);
_2(3i, 2f);
_2(3f, 2f);

#undef _2

_2_3(2i, 3i);
_2_3(2f, 3i);
_3_3(3f, 3i);

_2_3(2i, 3f);
_2_3(2f, 3f);
_3_3(3i, 3f);

#undef _2_3
#undef _3_3

#undef header

END_HEAD

#endif
