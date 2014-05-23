#ifndef _YASL_YUTIL_H
#define _YASL_YUTIL_H

//#include "yasl.h"
#include "../compat.h"
#include "../types.h"

START_HEAD

#include <stdlib.h>
//#include <string.h>

#define yrlist_new(typesize) malloc(typesize)

#define yrlist_init(name, typesize, size) {\
    name[0] = NULL;\
    size = 0;\
}

#define yrlist_destroy(name) free(name)

#define yrlist_push(name, typesize, size, item) {\
    name[size] = item;\
    name = realloc(name, (typesize) * ((++(size)) + 1));\
    name[size] = NULL;\
}

#define yrlist_pop(name, typesize, size) {\
    name = realloc(name, (typesize) * ((--(size)) + 1));\
    name[size] = NULL;\
}

#define yrlist_count(name, size) {\
    for (size = 0; name[size]; size++);\
}


#define ylist(type) \
    struct {\
        type* data;\
        size_t e_size;\
        size_t size;\
    }

#define ylist_init(type, name) {\
    name.e_size = sizeof(type);\
    name.data = yrlist_new(sizeof(type));\
    yrlist_init(name.data, sizeof(type), name.size);\
}

#define ylist_new(type, name)\
    ylist(type) name;\
    ylist_init(type, name);

#define ylist_destroy(name) {\
    yrlist_destroy(name.data);\
}

#define ylist_push(name, element) {\
    yrlist_push(name.data, name.e_size, name.size, element);\
}

#define ylist_pop(name) {\
    yrlist_pop(name.data, name.e_size, name.size);\
}

#define ylist_iter(name, itername, ...) {\
    for (size_t itername = 0; itername < name.size; itername++) {\
        __VA_ARGS__;\
    }\
}

#define ylist_count(name, size) yrlist_count(name.data, size)

#define ylist_from_arr(name, arr) {\
    free(name.data);\
    name.data = arr;\
    ylist_count(name, name.size);\
}

#define ylist_new_from_arr(type, name, arr)\
    ylist_new(type, name);\
    ylist_from_array(name, arr);

static inline bool ystreq(char* str1, char* str2) {
    bool ret = true;
    for (size_t i = 0; ((str1[i] == str2[i]) || (ret = false)) && str1[i] != 0; i++);
    return ret;
}

//#define ystreq(str1, str2) (strcmp(str1, str2) == 0) // This, my friend, HAS TO BE OPTIMIZED!!

END_HEAD

#endif
