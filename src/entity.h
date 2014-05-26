#ifndef _SP_ENTITY_H
#define _SP_ENTITY_H

#include "compat.h"

START_HEAD

#include "misc.h"
#include "types.h"

#include "pos.h"
#include "rect.h"
#include "spritesheet.h"

ENUM(Entity_state, {
    Entity_STILL = 0,
    Entity_WALK = 1,
    Entity_TROT = 2,
    Entity_ATTACK = 3,
    Entity_BACK = 4
});

STRUCT(entity_info, {
    Pos2i size;
    Spritesheet* sheet;
    Posf speed;
});

STRUCT(Entity, {
    Pos2f pos;
    Pos2i size;

    Entity_state state;
    Spritesheet* sheet;

    Posf speed;
    bool facing_left;

    // Functions
});

Entity* Entity_new(entity_info info);
void Entity_destroy(Entity* entity);

Posi Entity_distance(Entity* entity, Entity* other);

void Entity_flip(Entity* entity);
void Entity_forward(Entity* entity);
void Entity_left(Entity* entity);
void Entity_right(Entity* entity);
void Entity_move_towards(Entity* entity, Entity* other);

void Entity_update(Entity* entity);
void Entity_draw(Entity* entity);

END_HEAD

#endif
