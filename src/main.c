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

#include "NGlobals.h"
#include "NLog.h"
#include "NWMan.h"
#include "wrap/gl.h"
#include "NRsc.h"
#include "NEngine.h"
#include "NPorting.h"
#include "NArgs.h"
#include <stdlib.h>
#include <string.h>

#include "NIFF.h"
#include <stdio.h>
#include "NImage.h"

void parse_args() {
    NArg* args = NArgs_parse();
    NArg arg;
    for (int i = 0; (arg = args[i]).name; i++) {
        switch(arg.type) {
            case NARG_BOOL:
                Ndebug("%s = %i", arg.name, arg.bool_val);
                break;
            case NARG_STR:
                Ndebug("%s = %s", arg.name, arg.str_val);
                break;
        }

        if (NSTREQ(arg.name, "wm")) {
            N_WMan_backend = arg.str_val;
        }
    }
    free(args);
}

void testie(char* path) {
    Ndebug("=== Test: %s ===", path);
    NEngine_update_time();

    uint curr;

    curr = N_currtime;

    NPos3i size;
    uchar* raw = NImage_load_png(path, &size);

    NEngine_update_time();
    Ndebug("Time: %i", N_currtime - curr);

    NIFF_t* niff_gen = NIFF_from_raw(raw, 4, size.x, size.y, size.z);
    FILE* fp = fopen("thingy.txt", "wb");
    fwrite(niff_gen, 1, size.x*size.y*niff_gen->bpp +  niff_gen->palette_size * 4 + sizeof(NIFF_t), fp);
    fclose(fp);

    Ndebug("Size: %i, %i", size.x*size.y*niff_gen->bpp, niff_gen->palette_size * 4 + sizeof(NIFF_t));

    NEngine_update_time();
    curr = N_currtime;

    uchar* reraw = NIFF_to_raw(niff_gen);
    fp = fopen("thingy.txt", "rb");
    fread(niff_gen, 1, size.x*size.y*niff_gen->bpp +  niff_gen->palette_size * 4 + sizeof(NIFF_t), fp);
    fclose(fp);

    NEngine_update_time();
    Ndebug("Time: %i", N_currtime - curr);

   /* bool is_ok = true;
    for (int i = 0; i < size.x*size.y*4; i++) {
        if (reraw[i] != raw[i]) {
            //printf("NOOO!\n");
            is_ok = false;
        } else {
            //printf("YESSS!\n");
        }
    }

    printf("%i\n", is_ok);

    FILE* fp = fopen("thingy.txt", "wb");
    int n = fwrite(niff_gen, 1, 16*16 * 1 + niff_gen->palette_size * 4 + sizeof(NIFF_t), fp);
    printf("%i %i\n", n, 16*16 * 1 + niff_gen->palette_size * 4 + sizeof(NIFF_t));
    fclose(fp);*/
}

int main(int argc, char** argv) {
    int ret = 0;

    bool okay;

    N_argc = argc;
    N_argv = argv;

    // Load

    Ndebug("Initializing global variables");
    NGlobals_init();

    Ndebug("Parsing arguments");
    NINDENT(parse_args());

    Ndebug("Initializing window manager");
    NINDENT(okay = NWMan_init());

    if (!okay) {
        Nerror("Error initializing window manager!");
        return 1;
    }



    testie("/home/mijyn/workspace/silentponyville/game/levels/test/0.png");
    testie("/home/mijyn/workspace/silentponyville/game/levels/test/-1.png");
    testie("/home/mijyn/workspace/silentponyville/game/levels/test/1.png");
    testie("/home/mijyn/workspace/silentponyville/game/levels/test/-2.png");



    Ndebug("Creating window");
    NINDENT(okay = N_WMan.create_window());

    if (!okay) {
        Nerror("Error creating window!");
        return 1;
    }

    Ndebug("Initializing OpenGL");
    if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
        Nerror("Error initializing OpenGL!");
        return 1;
    }

    Ndebug("Initializing paths");
    NINDENT(okay = NRsc_init());

    if (!okay) {
        Ndebug("Error initializing paths!");
        return 1;
    }

    Ndebug("Loading engine");
    NINDENT(okay = NEngine_init());

    if (!okay) {
        Nerror("Error loading engine!");
        return 1;
    }

    // Game
    Nnewline();
    NEngine_run();

    // End
    Ndebug("Destroying engine");
    NINDENT(NEngine_destroy());

    Ndebug("Destroying paths");
    NINDENT(NRsc_destroy());

    Ndebug("Destroying window");
    NINDENT(N_WMan.destroy_window());

    Ndebug("Destroying window manager");
    NWMan_destroy();

    Ndebug("Destroying global variables");
    NGlobals_destroy();

    return ret;
}
