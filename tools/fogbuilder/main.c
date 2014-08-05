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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


#define WIDTH 256
#define HEIGHT 256
#define BREADTH 64

#define FEATURE_SIZE 8

#define ELEMNUM (WIDTH * HEIGHT * BREADTH)


typedef unsigned char uchar;
typedef double val_t;


typedef struct {
    ushort magic;
    short width;
    short height;
    short breadth;
    uchar contents[0];
} fog3_head;

val_t* values;

fog3_head* ourfog;

val_t frand() {
    return (((val_t)rand()) / (((val_t)RAND_MAX) / 2)) - 1;
}


#define E(x, y, z, c) (((x) & ((WIDTH / (c)) - 1)) + ((y) & ((HEIGHT / (c)) - 1)) * WIDTH + ((z) & ((BREADTH / (c)) - 1)) * WIDTH * HEIGHT)
#define E2(x, y, z) (x) * 4 + (y) * WIDTH * 4 + (z) * WIDTH * HEIGHT * 4
#define VAL(x, y, z, c) (values[E(x, y, z, c)])
#define PIX(x, y, z) (ourfog->contents[E(x, y, z, 1)])

void set_pixel(short x, short y, short z, uchar pix) {
    ourfog->contents[E(x, y, z, 1)] = pix;
}


val_t smooth(short x, short y, short z, short c) {
#if 0
    return VAL(x, y, z, c);
#else
    val_t corners = (VAL(x - 1, y - 1, z - 1, c) + VAL(x + 1, y - 1, z - 1, c) +
                     VAL(x - 1, y + 1, z - 1, c) + VAL(x + 1, y + 1, z - 1, c) +
                     VAL(x - 1, y - 1, z + 1, c) + VAL(x + 1, y - 1, z + 1, c) +
                     VAL(x - 1, y + 1, z + 1, c) + VAL(x + 1, y + 1, z + 1, c)) / 32.;

    val_t sides = (VAL(x - 1, y, z, c) + VAL(x + 1, y, z, c) +
                   VAL(x, y - 1, z, c) + VAL(x, y + 1, z, c) +
                   VAL(x, y, z - 1, c) + VAL(x, y, z + 1, c)) / 12.;

    val_t center = VAL(x, y, z, c) / 4.; // or 3

    return corners + sides + center;
#endif
}


val_t linear_interpolate(val_t n, val_t n1, val_t t) {
    return n * (1. - t) + n1 * t;
}

val_t cos_interpolate(val_t n, val_t n1, val_t t) {
    val_t t_pi = t * 3.1415927;
    val_t f = (1. - cos(t_pi)) * .5;

    return n * (1. - f) + n1 * t;
}

#if 0
#define interpolate(n, n1, t) linear_interpolate(n, n1, t)
#else
#define interpolate(n, n1, t) cos_interpolate(n, n1, t)
#endif

#define bi_interpolate(n00, n10, n01, n11, tx, ty) \
    interpolate(interpolate(n00, n10, tx), interpolate(n01, n11, tx), ty)

#define tri_interpolate(n000, n100, n010, n110, n001, n101, n011, n111, tx, ty, tz) \
    interpolate(bi_interpolate(n000, n100, n010, n110, tx, ty),\
                bi_interpolate(n001, n101, n011, n111, tx, ty), tz)

uchar pixelify(val_t value) {
    val_t calc = ((value + 1.) * 128.);
    if (calc >= 256) {
        calc = 255;
    } else if (calc < 0) {
        calc = 0;
    }
    return (uchar)calc;
}


val_t noise(short x, short y, short z) {
    val_t pixel = 0.;
    val_t scale = 1.;
    short c = FEATURE_SIZE;

    while (c > 1) {
        val_t x_fract = ((val_t)x) / ((val_t)c);
        short x_int = (short)x_fract;
        val_t x_diff = x_fract - x_int;

        val_t y_fract = ((val_t)y) / ((val_t)c);
        short y_int = (short)y_fract;
        val_t y_diff = y_fract - y_int;

        val_t z_fract = ((val_t)z) / ((val_t)c);
        short z_int = (short)z_fract;
        val_t z_diff = z_fract - z_int;


        pixel += tri_interpolate(
            smooth(x_int, y_int, z_int, c), smooth(x_int + 1, y_int, z_int, c),
            smooth(x_int, y_int + 1, z_int, c), smooth(x_int + 1, y_int + 1, z_int, c),
            smooth(x_int, y_int, z_int + 1, c), smooth(x_int + 1, y_int, z_int + 1, c),
            smooth(x_int, y_int + 1, z_int + 1, c), smooth(x_int + 1, y_int + 1, z_int + 1, c),
        x_diff, y_diff, z_diff) * scale;

        c >>= 1;
        scale /= 2.;
    }

    return pixel;
}

int main(int argc, char** argv) {
    char* filename = "fog.fog3";

    if (argc > 1) {
        filename = argv[1];
    }

    srand(time(NULL));

    values = malloc(sizeof(val_t) * ELEMNUM);

    size_t filesize = sizeof(fog3_head) + sizeof(char) * ELEMNUM; //* 4;

    ourfog = malloc(filesize);
    ourfog->magic = 0x1E3D;
    ourfog->width = WIDTH;
    ourfog->height = HEIGHT;
    ourfog->breadth = BREADTH;

    memset(ourfog->contents, 0, sizeof(char) * ELEMNUM); //* 4);

    printf("Generating random\n");

    for (short x = 0; x < WIDTH; x++) {
        for (short y = 0; y < HEIGHT; y++) {
            for (short z = 0; z < BREADTH; z++) {
                VAL(x, y, z, 1) = frand();
            }
        }
    }

    printf("Generating fog\n");

    for (short x = 0; x < WIDTH; x++) {
        for (short y = 0; y < HEIGHT; y++) {
            for (short z = 0; z < BREADTH; z++) {
                char calc = pixelify(noise(x, y, z));
                set_pixel(x, y, z, calc);
            }
        }
        if (x % 16 == 0) {
            printf("Generated chunk %i/%i\n", x / 16, WIDTH / 16);
        }
    }

#if 0
    for (int z = 0; z < BREADTH; z++) {
        char newfilename[10];
        sprintf(newfilename, "%s%u", filename, z);
        FILE* fp = fopen(newfilename, "wb");
        fwrite(ourfog->contents + z * HEIGHT * WIDTH, HEIGHT * WIDTH, 1, fp);
        fclose(fp);
    }
#else
    FILE* fp = fopen(filename, "wb");
    fwrite(ourfog, filesize, 1, fp);
    fclose(fp);
#endif

    free(values);
    free(ourfog);
}
