/*
    Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
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

#ifndef _NME_NIFF_H
#define _NME_NIFF_H

#include <NUtil.h>
#include <NTypes.h>

#define NIFF_MAGIC 0x1EA19190

NSTRUCT(NIFF_t, {
    uint32_t magic;
    uint32_t x_size;
    uint32_t y_size;
    uint32_t z_size;
    uint8_t channels;
    uint8_t bpp;
    uint32_t palette_size;

    uchar contents[];
});

#define NIFF_DATA_SIZE(x) ((x).x_size * (x).y_size * (x).z_size)
#define NIFF_DATA_BSIZE(x) ((x).x_size * (x).y_size * (x).z_size * (x).bpp)
#define NIFF_DATA_CSIZE(x) ((x).x_size * (x).y_size * (x).z_size * (x).channels)
#define NIFF_PALETTE_BSIZE(x) ((x).palette_size * 4)
#define NIFF_HEAD_SIZE(x) (sizeof(NIFF_t) + NIFF_PALETTE_BSIZE(x))
#define NIFF_SIZE(x) (sizeof(NIFF_t) + NIFF_DATA_BSIZE(x) + NIFF_PALETTE_BSIZE(x))

NIFF_t* NIFF_from_raw(uchar* raw, uint8_t channels, uint32_t x_size, uint32_t y_size, uint32_t z_size);
uchar* NIFF_to_raw(NIFF_t* niff);

#endif
