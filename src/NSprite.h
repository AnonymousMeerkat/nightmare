#ifndef _NME_SPRITE_H
#define _NME_SPRITE_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NTypes.h"
#include "NPos.h"

NTS(NImage);

NSTRUCT(NSprite_framedata, {
    size_t image_id;
    uint millis;
    bool notnull;
});

NSTRUCT(NSprite, {
    NImage** images;
    NSprite_framedata* frames;

    size_t frame_count;

    size_t id;
    ushort frame_delta;
});

NSprite* NSprite_new(NImage** images, NSprite_framedata* frames);
void NSprite_destroy(NSprite* sprite);

void NSprite_update(NSprite* sprite);
void NSprite_draw(NSprite* sprite, NPos2i pos, bool flip);

END_HEAD

#endif
