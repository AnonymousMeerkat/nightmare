#ifndef _NME_UTIL_H
#define _NME_UTIL_H

#include "NCompat.h"

START_HEAD

#define NUNUSED(x) (void)(x)
#define NTS(x) typedef struct _##x x
#define NTE(x) typedef enum _##x x
#define NSTRUCT(name, ...) struct _##name __VA_ARGS__;NTS(name)
#define NENUM(name, ...) enum _##name __VA_ARGS__;NTE(name)

#define NSTREQ(x, y) (!strcmp(x, y))

#define NABS(x) ((x) > 0 ? (x) : -(x))
#define NMAX(x, y) ((x) > (y) ? (x) : (y))
#define NMIN(x, y) ((x) < (y) ? (x) : (y))

#define NCLAMP(x, min, max) (NMIN(NMAX(x, min), max))

#define NINRANGE(x, min, max) ((x) >= (min) && (x) <= (max))
#define NINRANGEX(x, min, max) ((x) > (min) && (x) < (max))
#define NOUTRANGE(x, min, max) ((x) <= (min) && (x) >= (max))
#define NOUTRANGEX(x, min, max) ((x) < (min) && (x) > (max))

#define NSPACESHIP(x, y) ((x) > (y) ? 1 : ((x) < (y) ? -1 : 0))

END_HEAD

#endif
