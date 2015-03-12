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

#include "NKTool.h"

#include <NLog.h>
#include <NDynamic_t.h>
#include <stdio.h>
#include <math.h>

extern NKTool vecmathbuilder_tool;
extern NKTool fogbuilder_tool;
extern NKTool niffconv_tool;
extern NKTool niffflip_tool;

int main(int argc, char** argv) {
    NLIST_NEW(NKTool, tools);
    NLIST_PUSH(tools, vecmathbuilder_tool);
    NLIST_PUSH(tools, fogbuilder_tool);
#ifdef FREEIMAGE_FOUND
    NLIST_PUSH(tools, niffconv_tool);
    NLIST_PUSH(tools, niffflip_tool);
#endif

    if (argc < 2) {
        printf("Usage: %s tool [options]\n\n", argv[0]);
        printf("Tools available:\n\n");

        size_t maxsize = 0;

        for (size_t i = 0; i < tools.size; i++) {
            size_t len = strlen(tools.data[i].command);
            if (maxsize < len) {
                maxsize = len;
            }
        }

        for (size_t i = 0; i < tools.size; i++) {
            printf("    %s", tools.data[i].command);
            size_t len = strlen(tools.data[i].command);
            for (size_t j = 0; j < maxsize - len + 8; j++) {
                putchar('.');
            }
            printf("%s\n", tools.data[i].description);
        }

        puts("");

        return 0;
    }

    for (size_t i = 0; i < tools.size; i++) {
        if (NSTREQ(argv[1], tools.data[i].command)) {
            return tools.data[i].tool(argc - 1, argv + 1);
        }
    }

    Nerror("Tool %s not found!", argv[1]);
    return 1;
}
