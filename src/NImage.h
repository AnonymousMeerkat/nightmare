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

#ifndef _NME_IMAGE_H
#define _NME_IMAGE_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NPos.h"
#include "NTypes.h"

NENUM(NImage_type, {
    NImage_IMAGE = 0,
    NImage_FBO = 1
});

NSTRUCT(NImage, {
    NImage_type type;
    uint id;
    NPos2i size;
    void* data;
});

NImage* NImage_new(NImage_type type);
void NImage_destroy(NImage* image);

unsigned char* NImage_load_raw(char* path, NPos2i* size);
bool NImage_load(NImage* image, char* path);

void NImage_record(NImage* image); // FBO
void NImage_stoprecord();

void NImage_bind(NImage* image);
void NImage_unbind();

void NImage_draw(NImage* image, NPos2i pos, bool flip, float alpha);

END_HEAD

#endif
