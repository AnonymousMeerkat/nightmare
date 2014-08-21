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

#ifndef _NME_ENTITY_H
#define _NME_ENTITY_H

#include "NUtil.h"
#include "NTypes.h"
#include "NPos.h"
#include "NRect.h"
#include "NSpritesheet.h"

NENUM(NEntity_state, {
    NEntity_STILL = 0,
    NEntity_WALK = 1,
    NEntity_TROT = 2,
    NEntity_ATTACK = 3,
    NEntity_DEAD = 4,
    NEntity_BACK = 5,
});

NSTRUCT(NEntity_info, {
    NPos2i size;
    NSpritesheet* sheet;
    NPosf walk_speed;
    NPosf trot_speed;
});

NSTRUCT(NEntity, {
    NPos2f pos;
    NPosz z;
    NPos2i size;

    NEntity_state old_state;
    NEntity_state state;
    NSpritesheet* sheet;

    NPosf walk_speed;
    NPosf trot_speed;
    bool facing_left;

    void* data;

    // Functions
});

NEntity* NEntity_new(NEntity_info info);
void NEntity_destroy(NEntity* entity);

NPos2f NEntity_center(NEntity* entity);
NPosi NEntity_distance(NEntity* entity, NEntity* other);
bool NEntity_facing(NEntity* entity, NEntity* other);

void NEntity_still(NEntity* entity);
void NEntity_walk(NEntity* entity);
void NEntity_trot(NEntity* entity);
void NEntity_attack(NEntity* entity);

void NEntity_flip(NEntity* entity);
void NEntity_forward(NEntity* entity);
void NEntity_left(NEntity* entity);
void NEntity_right(NEntity* entity);
void NEntity_move_towards(NEntity* entity, NEntity* other);

void NEntity_update(NEntity* entity);

struct NEntity_draw_args {
    NPos2i size;
    float alpha;
};
void NEntity_draw(NEntity* entity, struct NEntity_draw_args args);
#define NENTITY_DRAW(entity, ...) NEntity_draw(entity, (struct NEntity_draw_args){.size = N_Pos2i0, .alpha = 1., __VA_ARGS__})

#endif
