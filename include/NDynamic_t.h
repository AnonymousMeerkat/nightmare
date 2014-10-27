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

#ifndef _NME_DYNAMIC_T_H
#define _NME_DYNAMIC_T_H

#include "NTypes.h"

#include <stdlib.h>
#include <string.h>

// Raw lists

#define NRLIST_SET_LAST_0(name, typesize, size) memset((name) + (size), 0, typesize)

#define NRLIST_NEW(typesize) malloc(typesize)

#define NRLIST_INIT(name, typesize, size) {\
    NRLIST_SET_LAST_0(name, typesize, 0);\
    size = 0;\
}

#define NRLIST_DESTROY(name) free(name)

#define NRLIST_PUSH(name, typesize, size, item) {\
    name[size] = item;\
    name = realloc(name, (typesize) * ((++(size)) + 1));\
    NRLIST_SET_LAST_0(name, typesize, size);\
}

#define NRLIST_POP(name, typesize, size) {\
    name = realloc(name, (typesize) * ((--(size)) + 1));\
    NRLIST_SET_LAST_0(name, typesize, size);\
}

#define NRLIST_INSERT(name, typesize, size, index, item) {\
    name = realloc(name, (typesize) * ((++(size)) + 1));\
    memmove((name) + (index) + 1, (name) + (index), typesize * ((size) - (index)));\
    name[index] = item;\
    NRLIST_SET_LAST_0(name, typesize, size);\
}

#define NRLIST_REMOVE(name, typesize, size, index) {\
    memmove((name) + (index), (name) + (index) + 1, typesize * ((--(size)) - (index)));\
    name = realloc(name, (typesize) * ((size) + 1));\
    NRLIST_SET_LAST_0(name, typesize, size);\
}

#define NRLIST_FREMOVE(name, typesize, size, value) {\
    size_t i;\
    for (i = 0; i < size; i++) {\
        if ((name)[i] == value) {\
            break;\
        }\
    }\
    if (i < size) {\
        NRLIST_REMOVE(name, typesize, size, i);\
    }\
}

#define NRLIST_COUNT(name, size) {\
    for (size = 0; (name)[size]; size++);\
}

// Easy lists

#define NLIST(type) \
    struct {\
        type* data;\
        size_t e_size;\
        size_t size;\
    }

typedef NLIST(int) NINTLIST;

#define NLIST_INIT(type, name) {\
    name.e_size = sizeof(type);\
    name.data = NRLIST_NEW(sizeof(type));\
    NRLIST_INIT(name.data, sizeof(type), name.size);\
}

#define NLIST_NEW(type, name)\
    NLIST(type) name;\
    NLIST_INIT(type, name);

#define NLIST_DESTROY(name) {\
    NRLIST_DESTROY(name.data);\
}

#define NLIST_PUSH(name, element) {\
    NRLIST_PUSH((name).data, (name).e_size, (name).size, element);\
}

#define NLIST_POP(name) {\
    NRLIST_POP((name).data, (name).e_size, (name).size);\
}

#define NLIST_INSERT(name, index, element) {\
    NRLIST_INSERT((name).data, (name).e_size, (name).size, index, element);\
}

#define NLIST_REMOVE(name, index) {\
    NRLIST_REMOVE((name).data, (name).e_size, (name).size, index);\
}

#define NLIST_FREMOVE(name, value) {\
    NRLIST_FREMOVE((name).data, (name).e_size, (name).size, value);\
}

#define NLIST_ITER(name, itername, ...) {\
    for (size_t itername = 0; itername < (name).size; itername++) {\
        __VA_ARGS__;\
    }\
}

#define NLIST_COUNT(name, size) NRLIST_COUNT((name).data, size)

#define NLIST_FROM_ARR(name, arr) {\
    free((name).data);\
    (name).data = arr;\
    NLIST_COUNT(name, (name).size);\
}

#define NLIST_NEW_FROM_ARR(type, name, arr)\
    NLIST_NEW(type, (name));\
    NLIST_FROM_ARR((name), arr);

#define NLIST_DUPLICATE(name, newname) {\
    (newname) = (name);\
    (newname).data = malloc(((name).size + 1) * (name).e_size);\
    memcpy((newname).data, (name).data, ((name).size + 1) * (name).e_size);\
}

#define NLIST_NEW_FROM_LIST(name, newname) {\
    typeof(name) (newname);\
    NLIST_DUPLICATE((name), (newname));\
}

// String functions

static inline bool Nstreq(char* str1, char* str2) {
    bool ret = true;
    for (size_t i = 0; ((str1[i] == str2[i]) || (ret = false)) && str1[i] != 0; i++);
    return ret;
}

#endif
