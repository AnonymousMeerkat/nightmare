#ifndef _SP_SPRITESHEET_H
#define _SP_SPRITESHEET_H

#include "compat.h"

#include "misc.h"
#include "yasl/yutil.h"

START_HEAD

#include "sprite.h"
#include "pos.h"

STRUCT(spritesheet_data, {
    char* name;
    sprite_framedata* framedata;
    Sprite* sprite;
});

STRUCT(Spritesheet, {
    spritesheet_data* sprites;
    size_t id;
});

Spritesheet* Spritesheet_new(spritesheet_data* sprites);
void Spritesheet_destroy(Spritesheet* sheet);

void Spritesheet_update(Spritesheet* sheet);
void Spritesheet_draw(Spritesheet* sheet, Pos2i pos);

END_HEAD

#endif
