#include "NLevel.h"

#include "NGlobals.h"
#include <stdlib.h>

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


void NLevel_draw(NLevel* level) {
    NLevel_layer layer;
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
}
