#ifndef _SP_ENTITY_H
#define _SP_ENTITY_H

#include "compat.h"

#include "misc.h"
#include "types.h"

START_HEAD

ENUM(Entity_state, {
    Entity_STILL = 0,
    Entity_WALK = 1,
    Entity_TROT = 2,
    Entity_ATTACK = 3,
    Entity_BACK = 4
}

STRUCT(Entity, {
    Pos pos;
    Pos size;

    bool attacking;
    Pos attack_pos;
    Pos attack_size;

    Entity_state state;
});

Entity*

END_HEAD

#endif
