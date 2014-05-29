#ifndef _NME_UTIL_H
#define _NME_UTIL_H

#include "NCompat.h"

START_HEAD

#define NUNUSED(x) ((void*)x)
#define NTS(x) typedef struct _##x x
#define NTE(x) typedef enum _##x x
#define NSTRUCT(name, ...) struct _##name __VA_ARGS__;NTS(name)
#define NENUM(name, ...) enum _##name __VA_ARGS__;NTE(name)

END_HEAD

#endif
