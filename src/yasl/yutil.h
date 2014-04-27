#ifndef _YASL_YUTIL_H
#define _YASL_YUTIL_H

#include "yasl.h"

#include <stdlib.h>
#include <string.h>

#define yrlist_new(typesize) malloc(typesize)

#define yrlist_init(name, typesize, size) {\
    name[0] = NULL;\
    size = 0;\
}

#define yrlist_destroy(name) free(name)

#define yrlist_push(name, typesize, size, item) {\
    name[size] = item;\
    name = realloc(name, (typesize) * (++(size)));\
    name[size] = NULL;\
}

#define yrlist_pop(name, typesize, size) {\
    name = realloc(name, (typesize) * (--(size)));\
    name[size] = NULL;\
}


#define ylist(type) \
    struct {\
        type* data;\
        YASL_SIZE e_size;\
        YASL_SIZE size;\
    }

#define ylist_init(type, name) {\
    name.e_size = sizeof(type);\
    yrlist_new(sizeof(type));\
    yrlist_init(name.data, sizeof(type), name.size);\
}

#define ylist_new(type, name) {\
    ylist(type) name;\
    ylist_init(type, name);\
}

#define ylist_destroy(name) {\
    yrlist_destroy(name.data);\
}

#define ylist_push(name, element) {\
    yrlist_push(name, name.e_size, name.size, element);\
}

#define ylist_pop(name) {\
    yrlist_pop(name, name.e_size, name.size);\
}

#define ystreq(str1, str2) (strcmp(str1, str2) == 0) // This, my friend, HAS TO BE OPTIMIZED!!

#endif
