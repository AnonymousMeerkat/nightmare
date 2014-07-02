/*
    Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>
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

#include "NEntity.h"

#include "NGlobals.h"
#include <stdlib.h>
#include <GLKit/GLKMath.h>

#define en_ds ((float)N_delta) * ((entity->state == NEntity_WALK) ? entity->walk_speed : entity->trot_speed)

NEntity* NEntity_new(NEntity_info info) {
    NEntity* entity = malloc(sizeof(NEntity));
    entity->pos = NPos2f0;
    entity->z = 0;
    entity->size = info.size;
    entity->sheet = info.sheet;
    entity->walk_speed = info.walk_speed;
    entity->trot_speed = info.trot_speed;

    entity->state = 0;
    entity->facing_left = 0;

    return entity;
}

void NEntity_destroy(NEntity* entity) {
    // Is this seriously all we have to do? XD
    free(entity);
}


NPos2f NEntity_center(NEntity* entity) {
    return GLKVector2Add(entity->pos, GLKVector2DivideScalar(GLKpos2i(entity->size), 2));
}

NPosi NEntity_distance(NEntity* entity, NEntity* other) {
    return abs(entity->pos.x - other->pos.x);
}


void NEntity_still(NEntity* entity) {
    entity->state = NEntity_STILL;
}

void NEntity_walk(NEntity* entity) {
    entity->state = NEntity_WALK;
}

void NEntity_trot(NEntity* entity) {
    entity->state = NEntity_TROT;
}

void NEntity_flip(NEntity* entity) {
    entity->facing_left = !entity->facing_left;
}

void NEntity_forward(NEntity* entity) {
    entity->pos.x += (entity->facing_left ? -1 : 1) * en_ds;
}

void NEntity_left(NEntity* entity) {
    if (!entity->facing_left) {
        NEntity_flip(entity);
    } else {
        NEntity_forward(entity);
    }
}

void NEntity_right(NEntity* entity) {
    if (entity->facing_left) {
        NEntity_flip(entity);
    } else {
        NEntity_forward(entity);
    }
}

void NEntity_move_towards(NEntity* entity, NEntity* other) {
    NPosf diff = other->pos.x - entity->pos.x;
    NPosf delta_speed;
    if ((entity->facing_left && diff > 0) || (!entity->facing_left && diff < 0)) {
        NEntity_flip(entity);
    } else if ((delta_speed = en_ds) > diff) {
        NEntity_forward(entity);
    } else {
        NEntity_forward(entity);
    }
}


void NEntity_update(NEntity* entity) {
    NSpritesheet_update(entity->sheet);
    // TODO: CR
}

void NEntity_draw_scale(NEntity* entity, NPos2i scale) {
    NSpritesheet_draw(entity->sheet, entity->state, Npos2i(entity->pos.x, entity->pos.y), scale, !entity->facing_left);
}

void NEntity_draw(NEntity* entity) {
    NEntity_draw_scale(entity, NPos2i0);
}
