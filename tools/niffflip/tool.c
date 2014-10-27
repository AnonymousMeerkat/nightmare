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

#include "../NKTool.h"

#include <NTypes.h>
#include <NIFF.h>
#include <NRsc.h>
#include <NLog.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int niffflip(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    char* read = NRsc_read_file_rp(argv[1]);
    if (!read) {
        return 2;
    }

    NIFF_t* niff = (NIFF_t*)read;
    size_t niffsize = NIFF_SIZE(*niff);
    NIFF_t* niff2 = malloc(niffsize);
    size_t headsize = NIFF_HEAD_SIZE(*niff);
    memcpy(niff2, niff, headsize);

    size_t linesize = (niff->x_size) * niff->bpp;

    uchar* line_o = (uchar*)niff + niffsize - linesize;
    uchar* line_n = (uchar*)niff2 + headsize;
    for (size_t y = 0; y < niff->y_size; y++) {
        uchar* pixel_o = line_o;
        uchar* pixel_n = line_n;
        for (size_t x = 0; x < niff->x_size; x++) {
            memcpy(pixel_n, pixel_o, niff->bpp);
            pixel_o += niff->bpp;
            pixel_n += niff->bpp;
        }
        line_o -= linesize;
        line_n += linesize;
    }

    free(read);

    FILE* fp = fopen(argv[1], "wb");
    if (!fp) {
        Nerror("Error opening %s for writing", argv[1]);
        return 3;
    }

    fwrite(niff2, 1, niffsize, fp);
    fclose(fp);

    free(niff2);

    return 0;
}

NKTool niffflip_tool = {
    .command = "niffflip",
    .tool = niffflip
};
