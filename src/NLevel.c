#include "NLevel.h"

#include "NGlobals.h"
#include <stdlib.h>
#include <GLKit/GLKMath.h>

NLevel* NLevel_new(NLevel_layer* layers, NPosz offset) {
    NLevel* level = malloc(sizeof(NLevel));
    level->layers = layers;
    level->offset = offset;
    NLIST_INIT(NEntity*, level->entities);
    return level;
}

void NLevel_destroy(NLevel* level) {
    NLevel_layer layer;
    for (int i = 0; (layer = level->layers[i]).base; i++) {
        NImage_destroy(layer.base);
    }
    free(level->layers);
    NLIST_DESTROY(level->entities);
    free(level);
}


NPosf NLevel_get_camera(NLevel* level) {
    NPosf player_center = NEntity_center(N_player).x;
    NPosf half_width = N_win_size.x / 2;
    // TODO: Optimize this
    return NCLAMP(player_center, half_width, level->layers[0].base->size.x - half_width) - half_width;
}

void NLevel_draw(NLevel* level) {
    NLevel_layer layer;
    GLKMatrix4 oldview = N_gl_view;
    level->camera = NLevel_get_camera(level);
    N_gl_view = GLKMatrix4Translate(N_gl_view, -level->camera, 0, 0);
    for (int i = 0; (layer = level->layers[i]).base; i++) {
        NImage_draw(layer.base, NPos2i0, false, 1);

        NPosz z = i + level->offset;

        NEntity* entity;
        for (size_t j = 0; j < level->entities.size && (entity = level->entities.data[j])->z == z; j++) {
            NEntity_draw(entity);
        }

        if (N_player->z == z) {
            NEntity_draw(N_player);
        }
    }
    N_gl_view = oldview;
}
