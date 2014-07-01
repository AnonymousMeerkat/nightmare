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
