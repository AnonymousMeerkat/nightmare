#ifndef _NME_OBJECT_H
#define _NME_OBJECT_H

#include "NCompat.h"

// XXX: What the heck's the purpose of this class?

START_HEAD

#include "NUtil.h"
#include "NTypes.h"
#include "NPos.h"
#include "NSpritesheet.h"

STRUCT(NObject, {
    NPos2i pos;
    NPos2i size;

    NSpritesheet* sheet;
});

END_HEAD

#endif
