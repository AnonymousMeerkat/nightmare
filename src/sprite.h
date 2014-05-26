#ifndef _SP_SPRITE_H
#define _SP_SPRITE_H

#include "compat.h"

#include "misc.h"
#include "types.h"

START_HEAD

#include "yasl/yutil.h"
#include "pos.h"

TS(Image);

STRUCT(sprite_framedata, {
    size_t image_id;
    time_t millis;
    bool notnull;
});

STRUCT(Sprite, {
    Image** images;
    sprite_framedata* frames;

    size_t frame_count;

    size_t id;
    ushort frame_delta;
});

Sprite* Sprite_new(Image** images, sprite_framedata* frames);
void Sprite_destroy(Sprite* sprite);

void Sprite_update(Sprite* sprite);
void Sprite_draw(Sprite* sprite, Pos2i pos, bool flip);

END_HEAD

#endif
