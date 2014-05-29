#ifndef _NME_SPRITESHEET_H
#define _NME_SPRITESHEET_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NSprite.h"
#include "NPos.h"
#include "NTypes.h"

NSTRUCT(NSpritesheet_data, {
    char* name;
    NSprite_framedata* framedata;
    NSprite* sprite;
});

NSTRUCT(NSpritesheet_info, {
    char* name;
    NSpritesheet_data* datas;
});

NSTRUCT(NSpritesheet, {
    NSpritesheet_data* sprites;
});

NSpritesheet* NSpritesheet_new(NSpritesheet_data* sprites);
void NSpritesheet_destroy(NSpritesheet* sheet);

void NSpritesheet_update(NSpritesheet* sheet);
void NSpritesheet_draw(NSpritesheet* sheet, size_t id, NPos2i pos, bool flip);

END_HEAD

#endif
