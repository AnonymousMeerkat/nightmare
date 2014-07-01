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
