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


#define WIDTH 256
#define HEIGHT 256
#define BREADTH 128

#define FEATURE_SIZE 16

#define ELEMNUM (WIDTH * HEIGHT * BREADTH)


typedef unsigned short ushort;
typedef unsigned int uint;
typedef double val_t;

typedef struct {
    ushort magic;
    ushort width;
    ushort height;
    ushort breadth;
    char contents[0];
} fog3_head;

val_t* contents;

fog3_head* ourfog;


val_t frand() {
    return (((val_t)rand()) / (((val_t)RAND_MAX) / 2)) - 1;
}


#define ELEMENT(x, y, z) (((x) & (WIDTH - 1)) + ((y) & (HEIGHT - 1)) * WIDTH + ((z) & (BREADTH - 1)) * WIDTH * HEIGHT)
//#define ELEMENT2(x, y, z) ((x & (WIDTH - 1)) * 4 + (y & (HEIGHT - 1)) * WIDTH + (z & (BREADTH - 1)) * WIDTH * HEIGHT)
#define ELEMENT2(x, y, z) (x) * 4 + (y) * WIDTH * 4 + (z) * WIDTH * HEIGHT * 4

val_t get_sample(int x, int y, int z) {
    return contents[ELEMENT(x, y, z)];
}

void set_sample(int x, int y, int z, val_t sample) {
    contents[ELEMENT(x, y, z)] = sample;
    ourfog->contents[ELEMENT2(x, y, z)] = (char)((sample + 1) * 128);
    ourfog->contents[ELEMENT2(x, y, z) + 1] = (char)((sample + 1) * 128);
    ourfog->contents[ELEMENT2(x, y, z) + 2] = (char)((sample + 1) * 128);
    ourfog->contents[ELEMENT2(x, y, z) + 3] = 255;
}


void sample_square(int x, int y, int z, int size, val_t val) {
    int hs = size / 2;

    val_t samples = 0.;

#define add_sample(x, y, z) samples += get_sample(x, y, z);

    add_sample(x - hs, y - hs, z - hs);
    add_sample(x + hs, y - hs, z - hs);
    add_sample(x - hs, y + hs, z - hs);
    add_sample(x + hs, y + hs, z - hs);
    add_sample(x - hs, y - hs, z + hs);
    add_sample(x + hs, y - hs, z + hs);
    add_sample(x - hs, y + hs, z + hs);
    add_sample(x + hs, y + hs, z + hs);

    //printf("%i %i %i SIZE %i SAMPLE %f\n", x, y, z, size, (samples / 8.) + val);
    set_sample(x, y, z, (samples / 8.) + val);
}

void sample_diamond(int x, int y, int z, int size, val_t val) {
    int hs = size / 2;

    val_t samples = 0.;

    add_sample(x - hs, y, z);
    add_sample(x + hs, y, z);
    add_sample(x, y - hs, z);
    add_sample(x, y + hs, z);
    add_sample(x, y, z - hs);
    add_sample(x, y, z + hs);

    set_sample(x, y, z, (samples / 6.) + val);
}


void diamond_square(int step, val_t scale) {
    int hs = step / 2;

    printf("%f\n", scale);

    for (int z = hs; z < BREADTH + hs; z += step) {
        for (int y = hs; y < HEIGHT + hs; y += step) {
            for (int x = hs; x < WIDTH + hs; x += step) {
                sample_square(x, y, z, step, frand() * scale);
            }
        }
    }

    for (int z = 0; z < BREADTH; z += step) {
        for (int y = 0; y < HEIGHT; y += step) {
            for (int x = 0; x < WIDTH; x += step) {
                sample_diamond(x + hs, y, z, step, frand() * scale);
                sample_diamond(x, y + hs, z, step, frand() * scale);
                sample_diamond(x, y, z + hs, step, frand() * scale);
            }
        }
    }
}


int main(int argc, char** argv) {
    char* filename = "fog.fog3";

    if (argc > 1) {
        filename = argv[1];
    }

    srand(time(NULL));

    contents = malloc(sizeof(val_t) * ELEMNUM);
    memset(contents, 5, sizeof(val_t) * ELEMNUM);

    size_t filesize = sizeof(fog3_head) + sizeof(char) * ELEMNUM * 4;

    ourfog = malloc(filesize);
    ourfog->magic = 0x1E3D;
    ourfog->width = WIDTH;
    ourfog->height = HEIGHT;
    ourfog->breadth = BREADTH;

    memset(ourfog->contents, 0, sizeof(char) * ELEMNUM * 4);

    for (int z = 0; z < BREADTH; z += FEATURE_SIZE) {
        for (int y = 0; y < HEIGHT; y += FEATURE_SIZE) {
            for (int x = 0; x < WIDTH; x += FEATURE_SIZE) {
                set_sample(x, y, z, frand());
            }
        }
    }

    int sample_size = FEATURE_SIZE;
    val_t scale = 1.;

    while (sample_size > 1) {
        diamond_square(sample_size, scale);

        sample_size /= 2;
        scale /= 2.;
    }

    for (int z = 0; z < BREADTH; z++) {
        char newfilename[10];
        sprintf(newfilename, "%s%u", filename, z);
        FILE* fp = fopen(newfilename, "wb");
        fwrite(ourfog->contents + z * HEIGHT * WIDTH * 4, HEIGHT * WIDTH * 4, 1, fp);
        fclose(fp);
    }

    /*FILE* fp = fopen(filename, "wb");
    fwrite(ourfog, filesize, 1, fp);
    fclose(fp);*/

    free(ourfog);
}
