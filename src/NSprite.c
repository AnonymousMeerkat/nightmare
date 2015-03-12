/*
    Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Nightmare Project nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

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


bool NSprite_update(NSprite* sprite) {
    uint millis = sprite->frames[sprite->id].millis;

    sprite->frame_delta += N_delta;
    sprite->id += sprite->frame_delta / millis;
    size_t old_id = sprite->id;
    sprite->frame_delta %= millis;
    sprite->id %= sprite->frame_count;
    return sprite->id < old_id;
}

void NSprite_draw(NSprite* sprite, NVec2i_t pos, NVec2i_t size, bool flip, float alpha) {
    NIMAGE_DRAW(sprite->images[sprite->frames[sprite->id].image_id], .pos = pos, .size = size, .flip = flip, .alpha = alpha);
}
