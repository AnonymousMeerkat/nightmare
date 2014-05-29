#include "NSprite.h"

#include "NImage.h"
#include "NGlobals.h"

#include <stdlib.h>

NSprite* NSprite_new(NImage** images, NSprite_framedata* frames) {
    NSprite* sprite = malloc(sizeof(NSprite));
    sprite->images = images; // FFS DON'T FREE images MANUALLY!
    sprite->frames = frames;
    sprite->frame_count = 0;
    for (int i = 0; frames[i].notnull; i++) {
        sprite->frame_count++;
    }
    sprite->id = 0;
    sprite->frame_delta = 0;
    return sprite;
}

void NSprite_destroy(NSprite* sprite) {
    NImage* image;
    for (size_t i = 0; (image = sprite->images[i]); i++) {
        NImage_destroy(image);
    }
    free(sprite->images);
    free(sprite);
}


void NSprite_update(NSprite* sprite) {
    uint millis = sprite->frames[sprite->id].millis;

    sprite->frame_delta += N_delta;
    sprite->id += sprite->frame_delta / millis;
    sprite->frame_delta %= millis;
    sprite->id %= sprite->frame_count;
}

void NSprite_draw(NSprite* sprite, NPos2i pos, bool flip) {
    NImage_draw(sprite->images[sprite->frames[sprite->id].image_id], pos, flip);
}
