#ifndef _NME_ENTITY_H
#define _NME_ENTITY_H

#include "NCompat.h"

START_HEAD

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
    NEntity_BACK = 4
});

NSTRUCT(NEntity_info, {
    NPos2i size;
    NSpritesheet* sheet;
    NPosf speed;
});

NSTRUCT(NEntity, {
    NPos2f pos;
    NPos2i size;

    NEntity_state state;
    NSpritesheet* sheet;

    NPosf speed;
    bool facing_left;

    // Functions
});

NEntity* NEntity_new(NEntity_info info);
void NEntity_destroy(NEntity* entity);

NPosi NEntity_distance(NEntity* entity, NEntity* other);

void NEntity_flip(NEntity* entity);
void NEntity_forward(NEntity* entity);
void NEntity_left(NEntity* entity);
void NEntity_right(NEntity* entity);
void NEntity_move_towards(NEntity* entity, NEntity* other);

void NEntity_update(NEntity* entity);
void NEntity_draw(NEntity* entity);

END_HEAD

#endif
