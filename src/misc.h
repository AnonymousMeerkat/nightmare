#ifndef _SP_MISC_H
#define _SP_MISC_H

#define UNUSED(x) ((void*)x)
#define TS(x) typedef struct _##x x
#define TE(x) typedef enum _##x x
#define STRUCT(name, ...) struct _##name __VA_ARGS__;TS(name)
#define ENUM(name, ...) enum _##name __VA_ARGS__;TE(name)

#endif
