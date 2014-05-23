#ifndef _SP_OBJECT_H
#define _SP_OBJECT_H

#include "compat.h"

#include "misc.h"
#include "types.h"

START_HEAD

STRUCT(Object, {
    Pos2i pos;
    Pos2i size;
});

END_HEAD

#endif
