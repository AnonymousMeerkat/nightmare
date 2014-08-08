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

#ifndef _NME_UTIL_H
#define _NME_UTIL_H

#include "NCompat.h"

START_HEAD

#define NUNUSED(x) (void)(x)
#define NTS(x) typedef struct _##x x
#define NTE(x) typedef enum _##x x
#define NSTRUCT(name, ...) struct _##name __VA_ARGS__;NTS(name)
#define NENUM(name, ...) enum _##name __VA_ARGS__;NTE(name)

#define NSTREQ(x, y) (!strcmp(x, y))

#define NABS(x) ((x) > 0 ? (x) : -(x))
#define NMAX(x, y) ((x) > (y) ? (x) : (y))
#define NMIN(x, y) ((x) < (y) ? (x) : (y))

#define NCLAMP(x, min, max) (NMIN(NMAX(x, min), max))

#define NINRANGE(x, min, max) ((x) >= (min) && (x) <= (max))
#define NINRANGEX(x, min, max) ((x) > (min) && (x) < (max))
#define NOUTRANGE(x, min, max) ((x) <= (min) && (x) >= (max))
#define NOUTRANGEX(x, min, max) ((x) < (min) && (x) > (max))

#define NSPACESHIP(x, y) ((x) > (y) ? 1 : ((x) < (y) ? -1 : 0))

#define NSTRINGIFY(x) #x

END_HEAD

#endif
