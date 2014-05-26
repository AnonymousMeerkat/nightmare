#include "sprite.h"

#include "image.h"
#include "globals.h"

Sprite* Sprite_new(Image** images, sprite_framedata* frames) {
    Sprite* sprite = malloc(sizeof(Sprite));
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

void Sprite_destroy(Sprite* sprite) {
    Image* image;
    for (size_t i = 0; (image = sprite->images[i]); i++) {
        Image_destroy(image);
    }
    free(sprite->images);
    free(sprite);
}


void Sprite_update(Sprite* sprite) {
    time_t millis = sprite->frames[sprite->id].millis;

    sprite->frame_delta += delta;
    sprite->id += sprite->frame_delta / millis;
    sprite->frame_delta %= millis;
    sprite->id %= sprite->frame_count;
}

void Sprite_draw(Sprite* sprite, Pos2i pos, bool flip) {
    Image_draw(sprite->images[sprite->frames[sprite->id].image_id], pos, flip);
}
