#ifndef _NME_DYNAMIC_T_H
#define _NME_DYNAMIC_T_H

#include "NCompat.h"

START_HEAD

#include "NTypes.h"

#include <stdlib.h>

// Raw lists

#define NRLIST_NEW(typesize) malloc(typesize)

#define NRLIST_INIT(name, typesize, size) {\
    name[0] = 0;\
    size = 0;\
}

#define NRLIST_DESTROY(name) free(name)

#define NRLIST_PUSH(name, typesize, size, item) {\
    name[size] = item;\
    name = realloc(name, (typesize) * ((++(size)) + 1));\
    name[size] = 0;\
}

#define NRLIST_POP(name, typesize, size) {\
    name = realloc(name, (typesize) * ((--(size)) + 1));\
    name[size] = 0;\
}

#define NRLIST_INSERT(name, typesize, size, index, item) {\
    name = realloc(name, (typesize) * ((++(size)) + 1));\
    memmove(name + (index) + 1, name + (index), typesize * ((size) - (index)));\
    name[index] = item;\
    name[size] = 0;\
}

#define NRLIST_REMOVE(name, typesize, size, index) {\
    memmove(name + (index), name + (index) + 1, typesize * ((--(size)) - (index)));\
    name = realloc(name, (typesize) * ((size) + 1));\
    name[size] = 0;\
}

#define NRLIST_COUNT(name, size) {\
    for (size = 0; name[size]; size++);\
}

// Easy lists

#define NLIST(type) \
    struct {\
        type* data;\
        size_t e_size;\
        size_t size;\
    }

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
    NRLIST_PUSH(name.data, name.e_size, name.size, element);\
}

#define NLIST_POP(name) {\
    NRLIST_POP(name.data, name.e_size, name.size);\
}

#define NLIST_INSERT(name, index, element) {\
    NRLIST_INSERT(name.data, name.e_size, name.size, index, element);\
}

#define NLIST_REMOVE(name, index) {\
    NRLIST_REMOVE(name.data, name.e_size, name.size, index);\
}

#define NLIST_ITER(name, itername, ...) {\
    for (size_t itername = 0; itername < name.size; itername++) {\
        __VA_ARGS__;\
    }\
}

#define NLIST_COUNT(name, size) NRLIST_COUNT(name.data, size)

#define NLIST_FROM_ARR(name, arr) {\
    free(name.data);\
    name.data = arr;\
    NLIST_COUNT(name, name.size);\
}

#define NLIST_NEW_FROM_ARR(type, name, arr)\
    NLIST_NEW(type, name);\
    NLIST_FROM_ARR(name, arr);

// String functions

static inline bool Nstreq(char* str1, char* str2) {
    bool ret = true;
    for (size_t i = 0; ((str1[i] == str2[i]) || (ret = false)) && str1[i] != 0; i++);
    return ret;
}

END_HEAD

#endif
