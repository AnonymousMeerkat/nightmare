#ifndef _SP_OBJECT_H
#define _SP_OBJECT_H

#include "compat.h"

#include "misc.h"
#include "types.h"

// XXX: What the heck's the purpose of this class?

START_HEAD

#include "spritesheet.h"

STRUCT(Object, {
    Pos2i pos;
    Pos2i size;

    Spritesheet* sheet;
});

END_HEAD

#endif
