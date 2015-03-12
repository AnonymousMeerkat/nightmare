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

#include "NLog.h"

#include "NGlobals.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int _printf(FILE* f, const char* prepend, short indent, const char* append, const char* fmt, va_list args) {
    // Get the total length of the message
    va_list copy;
    va_copy(copy, args);
    int len = vsnprintf(NULL, 0, fmt, copy);
    va_end(copy);
    len++; // NULL character

    // Copy the message to a temporary buffer ("basic")
    char* basic = (char*) malloc(len);
    vsnprintf(basic, len, fmt, args);
    basic[len - 1] = 0;

    // Create a new buffer which contains the complete message
    len += strlen(prepend);
    len += indent;
    len += strlen(append);
    char* buf = (char*) malloc(len);
    strcpy(buf, prepend);
    char* space = (char*) malloc(indent + 1);
    memset(space, ' ', indent);
    space[indent] = 0;
    strcat(buf, space);
    strcat(buf, basic);
    strcat(buf, append);
    buf[len - 1] = 0;

    // Show the new message
    int ret = fputs(buf, f);
    fflush(f);

    // We don't want no memory leaks, now do we?
    free(space);
    free(basic);
    free(buf);

    // And finally, return an output similar to what printf would give
    return (ret > 0) ? len : ret;
}

#define func(name, stream, prepend, append) \
    int name(const char* fmt, ...) {\
        va_list args;\
        va_start(args, fmt);\
\
        int ret = _printf(stream, prepend, N_indent * 2, append, fmt, args);\
\
        va_end(args);\
\
        return ret;\
    }

func(Ninfo, stdout, "[INFO] ", "\n");
func(Ndebug, stdout, "[DEBUG] ", "\n");
func(Nerror, stderr, "[ERROR] ", "\n");

void Nnewline() {
    printf("\n");
    fflush(stdout);
}
