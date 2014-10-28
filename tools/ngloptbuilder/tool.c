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
#include <NDynamic_t.h>
#include <NUtil.h>
#include <NLog.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

NENUM(pragmatype, {
    NGL_READONLY,
    NGL_READWRITE,
    NGL_WRITEONLY,
    NGL_NOPTION
});

NENUM(paramformat, {
    P_type,
    P_macro,
    P_pointer
});

// Copied from http://stackoverflow.com/a/9444636/999400
char* to_upper(char* str) {
    char *newstr, *p;
    p = newstr = strdup(str);
    while (*p != 0) {
        *p = toupper(*p);
        p++;
    }

    return newstr;
}

NSTRUCT(param_type, {
    char* type;
    char* macro;
    bool pointer;
});

NSTRUCT(param, {
    char* context;
    bool context_first;
    param_type type;
    char* name;
});


int ngloptbuilder(int argc, char** argv) {
    if (argc < 2) {
        eprintf("Usage: %s input [output]\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (!input) {
        eprintf("File %s cannot be opened\n", argv[1]);
        return 1;
    }

    FILE* output = stdout;

    if (argc == 3) {
        output = fopen(argv[2], "w");
        if (!output) {
            eprintf("File %s cannot be written to\n", argv[2]);
            return 1;
        }
    }

    NLIST(param) pragmas[4];
    NLIST_INIT(param, pragmas[0]);
    NLIST_INIT(param, pragmas[1]);
    NLIST_INIT(param, pragmas[2]);
    NLIST_INIT(param, pragmas[3]);

    NLIST_NEW(param_type, param_types);
    NLIST_NEW(char*, contexts);

    // Read pragmas

    int lastc = 0;
    int c;
    bool hadnewline = false;
    bool hashash = false;
    bool inpragma = false;
    bool comment = false;
    pragmatype pragma = 0;
    char currline[1024];
    int currline_pos = 0;
    while ((c = fgetc(input)) != EOF) {
        if (c == '\n') {
            comment = false;
            currline[currline_pos] = 0;
            currline_pos = 0;
            if (hashash) {
                char* str;
                int i = 0;
                str = strtok(currline, " \t");
                while (str != NULL) {
                    if (i == 0) {
                        if (strcmp(str, "pragma")) {
                            break;
                        }
                        i++;
                        goto loopend;
                    }

                    if (strstr(str, "NGL_") != str) {
                        break;
                    }

                    inpragma = true;

#define checkpragma(name)\
                    if (NSTREQ(str, #name)) {\
                        pragma = name;\
                        break;\
                    }

                    checkpragma(NGL_READONLY);
                    checkpragma(NGL_READWRITE);
                    checkpragma(NGL_WRITEONLY);
                    checkpragma(NGL_NOPTION);

                    eprintf("Unrecognized pragma %s\n", str);
                    return 1;

                    loopend:
                    str = strtok(NULL, " \t");
                }

                hashash = false;
            } else if (inpragma && currline[0] != 0) {
                char* str = currline;
                param our_param;
                if (strstr(str, "NGL_PARAM") == str) {
                    char* str1 = strtok(currline + 9, ",");
                    size_t str1_len;

                    bool contextfound = false;
                    size_t i;
                    for (i = 0; i < contexts.size; i++) {
                        if (NSTREQ(contexts.data[i], str1)) {
                            contextfound = true;
                            break;
                        }
                    }

                    if (contextfound) {
                        our_param.context = contexts.data[i];
                        our_param.context_first = false;
                    } else {
                        our_param.context = strdup(str1);
                        NLIST_PUSH(contexts, our_param.context);
                        our_param.context_first = true;
                    }

                    str1 = strtok(NULL, ",");
                    str1_len = strlen(str1);

                    bool typefound = false;
                    for (i = 0; i < param_types.size; i++) {
                        if (NSTREQ(param_types.data[i].type, str1)) {
                            typefound = true;
                            break;
                        }
                    }

                    if (typefound) {
                        our_param.type = param_types.data[i];
                    } else {
                        our_param.type.type = strdup(str1);

                        if (str1[str1_len-1] == '*') {
                            str1[str1_len-1] = 'p';
                            our_param.type.pointer = true;
                        } else {
                            our_param.type.pointer = false;
                        }

                        our_param.type.macro = to_upper(str1 + 4);

                        NLIST_PUSH(param_types, our_param.type);
                    }

                    str = strtok(NULL, ",");
                } else {
                    our_param.context = NULL;
                    our_param.type = (param_type){NULL, NULL, false};
                }
                our_param.name = malloc(strlen(str));
                strcpy(our_param.name, str);
                NLIST_PUSH(pragmas[pragma], our_param);
            }

            hadnewline = true;
            continue;
        }

        if ((c == '/' && lastc == '/') || c == '=') {
            comment = true;
        }

        if (comment) {
            continue;
        }

        if (c == '#' && hadnewline) {
            hashash = true;
            currline_pos = 0;
        } else if (hashash) {
            currline[currline_pos++] = c;
        }

        if (c != ' ' && c != '\t') {
            if (inpragma && !hashash) {
                if (hadnewline && c == '}') {
                    inpragma = false;
                } else {
                    if (c == '_' || c == ',' || c == '*' || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                        currline[currline_pos++] = c;
                    }
                }
            }
            hadnewline = false;
        }

        lastc = c;
    }



#define access_macro_gen()\
    put_macro_f("ACCESS", "READONLY")\
    put_macro_f("ACCESS", "READWRITE")\
    put_macro_f("ACCESS", "WRITEONLY")\
    put_macro_f("ACCESS", "NOPTION")

#define types_macro_gen()\
    for (size_t i = 0; i < param_types.size; i++) {\
        put_macro_f("TYPE", param_types.data[i].macro);\
    }

#define context_macro_gen()\
    for (size_t i = 0; i < contexts.size; i++) {\
        put_macro_f("CONTEXT", contexts.data[i]);\
    }

    int enum_counter = 0;

#define put_enum_macro(name) fprintf(output, "#define N_GL_PARAM_%s %i\n", name, enum_counter++)

    put_enum_macro("ACCESS_READONLY");
    put_enum_macro("ACCESS_READWRITE");
    put_enum_macro("ACCESS_WRITEONLY");
    put_enum_macro("ACCESS_NOPTION");

    fputs("\n", output);

#define put_macro_f(prefix, name) fprintf(output, "#define _N_GL_PARAM_%s_%s_ENABLED 1\n", prefix, name);
    access_macro_gen();
    types_macro_gen();
    context_macro_gen();
#undef put_macro_f

    fputs("\n"
          "#ifdef N_GL_PARAM_EXCLUDE\n",
          output);

#define put_macro_f(prefix, name) \
    fprintf(output, \
        "#  ifdef N_GL_PARAM_EXCLUDE_%s_%s\n"\
        "#    undef _N_GL_PARAM_%s_%s_ENABLED\n"\
        "#  endif\n", prefix, name, prefix, name);
    access_macro_gen();
    types_macro_gen();
    context_macro_gen();
#undef put_macro_f

    fputs("#elif defined(N_GL_PARAM_INCLUDE)\n", output);

#define put_macro_f(prefix, name) fprintf(output, "#  undef _N_GL_PARAM_%s_%s_ENABLED\n", prefix, name);
    access_macro_gen();
    types_macro_gen();
    context_macro_gen();
#undef put_macro_f

#define put_macro_f(prefix, name) \
    fprintf(output, \
        "#  ifdef N_GL_PARAM_INCLUDE_%s_%s\n"\
        "#    define _N_GL_PARAM_%s_%s_ENABLED 1\n"\
        "#  endif\n", prefix, name, prefix, name);
    access_macro_gen();
    types_macro_gen();
    context_macro_gen();
#undef put_macro_f

    fputs(
        "#  ifdef N_GL_PARAM_INCLUDE_ALLACCESS\n",
    output);

#define put_macro_f(prefix, name) fprintf(output, "#    define _N_GL_PARAM_%s_%s_ENABLED 1\n", prefix, name);
    access_macro_gen();

    fputs(
        "#  endif\n"
        "#  ifdef N_GL_PARAM_INCLUDE_ALLTYPES\n",
    output);

    types_macro_gen();

    fputs(
        "#  endif\n"
        "#  ifdef N_GL_PARAM_INCLUDE_ALLCONTEXTS\n",
    output);

    context_macro_gen();
#undef put_macro_f

    fputs("#  endif\n", output);

    fputs("#endif\n\n", output);

#define put_macro_f(name, args)\
    fputs(\
        "#ifndef NGL_"name"\n"\
        "#  define N_GL_"name"_UNDEF\n"\
        "#  define NGL_"name"("args")\n"\
        "#endif\n\n",\
    output);

    put_macro_f("CONTEXT", "c");
    put_macro_f("CONTEXT_END", "c");
    put_macro_f("PARAM", "c, a, t, p");

#undef put_macro_f

#define put_param_macro(prefix, name, t)\
    fprintf(output, \
        "#ifndef NGL_%s_%s_PARAM\n"\
        "#  define N_GL_%s_%s_PARAM_UNDEF\n"\
        "#  define NGL_%s_%s_PARAM("t")\n"\
        "#endif\n\n", prefix, name, prefix, name, prefix, name)

#define put_macro_f(prefix, name) put_param_macro(prefix, name, "c, t, p");
    access_macro_gen();
#undef put_macro_f

#define put_macro_f(prefix, name) put_param_macro(prefix, name, "c, a, p");
    types_macro_gen();
#undef put_macro_f

#define put_macro_f(prefix, name) put_param_macro(prefix, name, "c, a, t, p")
    put_macro_f("TYPE", "POINTER");
    put_macro_f("TYPE", "NPOINTER");
#undef put_macro_f

#define put_macro_f(prefix, name) put_param_macro(prefix, name, "a, t, p")
    context_macro_gen();
#undef put_macro_f

    fputs("\n", output);

/*#define put_macro_f(prefix, name) fprintf(output, "NGL_CONTEXT(%s)\n", name)
    context_macro_gen();
#undef put_macro_f

    fputs("\n\n", output);*/

    bool first_context = true;
    char* old_context = NULL;

    for (int i = 0; i < 4; i++) {
        char* access = "";
        switch(i) {
            case NGL_READONLY:
                access = "READONLY";
                break;
            case NGL_READWRITE:
                access = "READWRITE";
                break;
            case NGL_WRITEONLY:
                access = "WRITEONLY";
                break;
            case NGL_NOPTION:
                access = "NOPTION";
                break;
            default:
                Nerror("This is not supposed to happen!");
                break;
        }

        for (int x = 0; pragmas[i].data[x].name; x++) {
            param our_param = pragmas[i].data[x];
            if (i < 3) {
                if (our_param.context_first) {
                    if (first_context) {
                        first_context = false;
                    } else {
                        fprintf(output, "NGL_CONTEXT_END(%s)\n\n", old_context);
                    }
                    old_context = our_param.context;
                    fprintf(output, "NGL_CONTEXT(%s)\n\n", our_param.context);
                }
                fprintf(output, "#define N_GL_PARAM_%s_ACCESS %s\n", our_param.name, access);
                fprintf(output, "#define N_GL_PARAM_%s_%s 1\n", our_param.name, access);
                fprintf(output, "#define N_GL_PARAM_%s_TYPE %s\n", our_param.name, our_param.type.type);
                fprintf(output, "#define N_GL_PARAM_%s_%s 1\n", our_param.name, our_param.type.macro);
                fprintf(output, "#define N_GL_PARAM_%s_POINTER %i\n", our_param.name, our_param.type.pointer);
                fprintf(output, "#define N_GL_PARAM_%s_CONTEXT %s\n", our_param.name, our_param.context);
                fprintf(output, "#define N_GL_PARAM_%s_CONTEXT_%s 1\n", our_param.name, our_param.context);
                fprintf(output, "#if defined(_N_GL_PARAM_%s_ENABLED) && defined(_N_GL_PARAM_%s_ENABLED) && defined(_N_GL_PARAM_CONTEXT_%s_ENABLED)\n",
                    our_param.type.macro, access, our_param.context);
                fprintf(output, "NGL_PARAM(%s, N_GL_PARAM_ACCESS_%s, %s, %s)\n",
                    our_param.context, access, our_param.type.type, our_param.name);
                fprintf(output, "NGL_%s_PARAM(%s, %s, %s)\n", access, our_param.context, our_param.type.type, our_param.name);
                fprintf(output, "NGL_%s_PARAM(%s, N_GL_PARAM_ACCESS_%s, %s)\n", our_param.type.macro, our_param.context, access, our_param.name);
                fprintf(output, "NGL_%s_PARAM(%s, N_GL_PARAM_ACCESS_%s, %s, %s)\n", our_param.type.pointer ? "POINTER" : "NPOINTER", our_param.context, access, our_param.type.type, our_param.name);
                fprintf(output, "NGL_%s_PARAM(N_GL_PARAM_ACCESS_%s, %s, %s)\n", our_param.context, access, our_param.type.type, our_param.name);
                fprintf(output, "#endif\n");
                fputs("\n", output);
            }
        }
    }

    fprintf(output, "NGL_CONTEXT_END(%s)\n\n", old_context);

#define rem_param_macro(prefix, name)\
    fprintf(output, \
        "#ifdef N_GL_%s_%s_PARAM_UNDEF\n"\
        "#  undef N_GL_%s_%s_PARAM_UNDEF\n"\
        "#  undef NGL_%s_%s_PARAM\n"\
        "#endif\n\n", prefix, name, prefix, name, prefix, name)

#define put_macro_f(prefix, name) rem_param_macro(prefix, name);
    access_macro_gen();
    types_macro_gen();
    context_macro_gen();
#undef put_macro_f

    rem_param_macro("TYPE", "POINTER");
    rem_param_macro("TYPE", "NPOINTER");

#undef rem_param_macro
#define rem_param_macro(name)\
    fputs("#ifdef NGL_"name"_UNDEF\n"\
          "#  undef NGL_"name"_UNDEF\n"\
          "#  undef NGL_"name"\n"\
          "#endif\n\n", output);

    rem_param_macro("PARAM");
    rem_param_macro("CONTEXT_END");
    rem_param_macro("CONTEXT");

    return 0;
}

NKTool ngloptbuilder_tool = {
    .command = "ngloptbuilder",
    .description = "Generates param.h from NGL.h (deprecated)",
    .tool = ngloptbuilder
};
