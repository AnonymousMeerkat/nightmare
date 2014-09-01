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

#include "common.h"

void NGL_common_add_changed(NGL_common* common, NGL_enum property) {
    NLIST_PUSH(common->changed, property);
}


void NGL_common_set(NGL_common* common, NGL_enum property, void* value, bool userset) {
    bool set = false;
    size_t counted = 0;
    switch (property) {
#define NGL_NPOINTER_PARAM(c, a, t, p)\
        case N_GL_##p:\
            if (userset && a == N_GL_PARAM_ACCESS_READONLY) {\
                return;\
            }\
            common->p = *((t*)value);\
            set = true;\
            break;
#define NGL_POINTER_PARAM(c, a, t, p)\
        case N_GL_##p:\
            if (userset && a == N_GL_PARAM_ACCESS_READONLY) {\
                return;\
            }\
            /* XXX: Do we NEED to allocate our own memory?? */\
            NRLIST_COUNT((t*)value, counted);\
            common->p = (t) realloc(common->p, counted * sizeof(t));\
            memcpy(common->p, value, counted * sizeof(t));\
            set = true;\
            break;
        #include "params.h"
#undef NGL_POINTER_PARAM
#undef NGL_NPOINTER_PARAM

        default:
            return;
    }

    if (set && userset) {
        NGL_common_add_changed(common, property);
    }
}

void* NGL_common_get(NGL_common* common, NGL_enum property) {
    switch (property) {
#define NGL_NPOINTER_PARAM(c, a, t, p)\
        case N_GL_##p:\
            if (a == N_GL_PARAM_ACCESS_WRITEONLY) {\
                return NULL;\
            }\
            return &(common->p);
#define NGL_POINTER_PARAM(c, a, t, p)\
        case N_GL_##p:\
            if (a == N_GL_PARAM_ACCESS_WRITEONLY) {\
                return NULL;\
            }\
            return common->p;
        #include "params.h"
#undef NGL_POINTER_PARAM
#undef NGL_NPOINTER_PARAM

        default:
            return NULL;
    }
}
