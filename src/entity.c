#include "entity.h"

#include "globals.h"

#include <stdlib.h>

#define en_ds ((float)delta) * entity->speed

Entity* Entity_new(entity_info info) {
    Entity* entity = malloc(sizeof(Entity));
    entity->pos = Pos2fblank;
    entity->size = info.size;
    entity->sheet = info.sheet;
    entity->speed = info.speed;

    entity->state = 0;
    entity->facing_left = 0;

    return entity;
}

void Entity_destroy(Entity* entity) {
    // Is this seriously all we have to do? XD
    free(entity);
}


Posi Entity_distance(Entity* entity, Entity* other) {
    return abs(entity->pos.x - other->pos.x);
}


void Entity_flip(Entity* entity) {
    entity->facing_left = !entity->facing_left;
}

void Entity_forward(Entity* entity) {
    entity->pos.x += (entity->facing_left ? -1 : 1) * en_ds;
}

void Entity_left(Entity* entity) {
    if (!entity->facing_left) {
        Entity_flip(entity);
    } else {
        Entity_forward(entity);
    }
}

void Entity_right(Entity* entity) {
    if (entity->facing_left) {
        Entity_flip(entity);
    } else {
        Entity_forward(entity);
    }
}

void Entity_move_towards(Entity* entity, Entity* other) {
    Posf diff = other->pos.x - entity->pos.x;
    Posf delta_speed;
    if ((entity->facing_left && diff > 0) || (!entity->facing_left && diff < 0)) {
        Entity_flip(entity);
    } else if ((delta_speed = en_ds) > diff) {
        if (entity->facing_left) {
            entity->pos.x -= delta_speed;
        } else {
            entity->pos.x += delta_speed;
        }
    } else {
        Entity_forward(entity);
    }
}


void Entity_update(Entity* entity) {
    Spritesheet_update(entity->sheet);
    // TODO: CR
}

void Entity_draw(Entity* entity) {
    Spritesheet_draw(entity->sheet, entity->state, pos2i(entity->pos.x, entity->pos.y), !entity->facing_left);
}
