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
#include <NLog.h>
#include <NRsc.h>
#include <NIFF.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <FreeImage.h>

#define ISNIFF(x) NSTREQ(NRsc_get_ext(x), "niff")

int niffconv(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    bool argv1niff = ISNIFF(argv[1]);
    bool argv2niff = ISNIFF(argv[2]);

    uchar* data;
    NPos3i size;
    int channels;

    FreeImage_Initialise(TRUE);

    if (argv1niff) {
        char* read = NRsc_read_file_rp(argv[1]);
        if (!read) {
            return 2;
        }

        NIFF_t* niff = (NIFF_t*)read;
        size.x = niff->x_size;
        size.y = niff->y_size;
        size.z = niff->z_size;
        channels = niff->channels;
        data = NIFF_to_raw(niff);

        free(read);
    } else {
        FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(argv[1], 0);
        if (fif == FIF_UNKNOWN) {
            fif = FreeImage_GetFIFFromFilename(argv[1]);
        }

        if ((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)) {
            FIBITMAP* bitmap_raw = FreeImage_Load(fif, argv[1], 0);

            if (!bitmap_raw) {
                Nerror("Error reading image %s", argv[1]);
                return 2;
            }

            FIBITMAP* bitmap = FreeImage_ConvertTo32Bits(bitmap_raw);
            FreeImage_Unload(bitmap_raw);

            if (!bitmap) {
                Nerror("Error converting image %s", argv[1]);
                return 2;
            }

            size.x = FreeImage_GetWidth(bitmap);
            size.y = FreeImage_GetHeight(bitmap);
            size.z = 1;

            channels = 4;

            uchar* data_raw = FreeImage_GetBits(bitmap);
            data = malloc(size.x * size.y * 4);

            uint pitch_raw = FreeImage_GetPitch(bitmap);
            uint pitch = size.x * 4;

            uchar* line_raw = data_raw + pitch_raw * (size.y - 1);
            uchar* line = data;
            for (ssize_t y = 0; y < size.y; y++) {
                uchar* pixel_raw = line_raw;
                uchar* pixel = line;
                for (ssize_t x = 0; x < size.x; x++) {
                    pixel[0] = pixel_raw[FI_RGBA_RED];
                    pixel[1] = pixel_raw[FI_RGBA_GREEN];
                    pixel[2] = pixel_raw[FI_RGBA_BLUE];
                    pixel[3] = pixel_raw[FI_RGBA_ALPHA];
                    pixel_raw += 4;
                    pixel += 4;
                }
                line_raw -= pitch_raw;
                line += pitch;
            }

            FreeImage_Unload(bitmap);
        } else {
            Nerror("Error checking image %s", argv[1]);
            return 2;
        }
    }

    if (argv2niff) {
        NIFF_t* niff = NIFF_from_raw(data, channels, size.x, size.y, size.z);

        FILE* fp = fopen(argv[2], "wb");
        if (!fp) {
            Nerror("Error opening %s for writing", argv[2]);
            return 3;
        }

        fwrite(niff, 1, NIFF_SIZE(*niff), fp);
        fclose(fp);
    } else {
        FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(argv[2]);
        if (fif == FIF_UNKNOWN) {
            Nerror("File %s not supported for writing", argv[2]);
            return 3;
        }

        FIBITMAP* bitmap = FreeImage_Allocate(size.x, size.y, 32, 0, 0, 0);
        if (!bitmap) {
            Nerror("Error allocating bitmap");
            return 3;
        }

        uint pitch = FreeImage_GetPitch(bitmap);
        BYTE* bits = (BYTE*) FreeImage_GetBits(bitmap);

        for (ssize_t y = 0; y < size.y; y++) {
            BYTE* pixel = bits;
            for (ssize_t x = 0; x < size.x; x++) {
                size_t pos = (size.x * (size.y - y) + x) * channels;
                switch (channels) {
                    case 1:
                        pixel[FI_RGBA_RED] = 1;
                        pixel[FI_RGBA_GREEN] = 1;
                        pixel[FI_RGBA_BLUE] = 1;
                        pixel[FI_RGBA_ALPHA] = data[pos];
                        break;
                    case 2:
                        pixel[FI_RGBA_RED] = data[pos];
                        pixel[FI_RGBA_GREEN] = data[pos + 1];
                        pixel[FI_RGBA_BLUE] = 0;
                        pixel[FI_RGBA_ALPHA] = 1;
                        break;
                    case 3:
                        pixel[FI_RGBA_RED] = data[pos];
                        pixel[FI_RGBA_GREEN] = data[pos + 1];
                        pixel[FI_RGBA_BLUE] = data[pos + 2];
                        pixel[FI_RGBA_ALPHA] = 1;
                        break;
                    case 4:
                        pixel[FI_RGBA_RED] = data[pos];
                        pixel[FI_RGBA_GREEN] = data[pos + 1];
                        pixel[FI_RGBA_BLUE] = data[pos + 2];
                        pixel[FI_RGBA_ALPHA] = data[pos + 3];
                        break;
                }
                pixel += 4;
            }
            bits += pitch;
        }

        if (!FreeImage_Save(fif, bitmap, argv[2], 0)) {
            Nerror("Error saving image %s", argv[2]);
            return 3;
        }
    }

    free(data);

    FreeImage_DeInitialise();

    return 0;
}

NKTool niffconv_tool = {
    .command = "niffconv",
    .description = "Converts to/from various image formats and NIFF",
    .tool = niffconv
};
