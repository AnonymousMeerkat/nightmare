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
#include "NShadow.h"
#include <stdlib.h>
#include <GLKit/GLKMath.h>

NLevel* NLevel_new(NLevel_layer* layers, NPosz default_layer) {
    NLevel* level = malloc(sizeof(NLevel));
    level->default_layer = default_layer;

    NLevel_layer layer;
    int count;
    for (count = 0; (layer = layers[count]).base; count++);
    level->layers.data = layers;
    level->layers.e_size = sizeof(NLevel_layer);
    level->layers.size = count;

    NLIST_INIT(NEntity*, level->entities);

    return level;
}

void NLevel_destroy(NLevel* level) {
    for (size_t i = 0; i < level->layers.size; i++) {
        NImage_destroy(level->layers.data[i].base);
    }
    NLIST_DESTROY(level->layers);
    NLIST_DESTROY(level->entities);
    free(level);
}


NPosf NLevel_get_z(NLevel* level, NPosz z) {
    size_t z_u = z;
    if (z_u >= level->layers.size) {
        return 0;
    }

    NPosf ret = 0;

    for (NPosz i = 0; i < z; i++) {
        ret += level->layers.data[(int)i].z_size;
    }

    return ret;
}

NPosf NLevel_get_camera(NLevel* level) {
    NPosf player_center = NEntity_center(N_player).x;
    NPosf half_width = N_win_size.x / 2;
    // TODO: Optimize this
    return NCLAMP(player_center, half_width, level->layers.data[0].base->size.x - half_width) - half_width;
}

void NLevel_draw(NLevel* level, NImage* fog) {
    GLKMatrix4 oldview = N_gl_view;
    level->camera = NLevel_get_camera(level);
    N_gl_view = GLKMatrix4Translate(N_gl_view, -level->camera, 0, 0);

    NLevel_layer layer;
    for (size_t i = 0; i < level->layers.size; i++) {
        layer = level->layers.data[i];
        NIMAGE_DRAW(layer.base);

        NPosz z = i;

        NEntity* entity;
        for (size_t j = 0; j < level->entities.size && (entity = level->entities.data[j])->z >= z; j++) {
            if (entity->z > z) {
                NShadow_draw(level, entity, z);
            } else {
                NENTITY_DRAW(entity);
            }
        }

        if (N_player->z > z) {
            NShadow_draw(level, N_player, z);
        } else if (N_player->z == z) {
            NENTITY_DRAW(N_player);
        }

        uint move_x_amt = ((N_currtime/40)-(int)level->camera)%1024u;
        uint move_y_amt = (-N_currtime/100)%1024u;
        NShader_run(N_shaders[3]);
        NIMAGE_DRAW(fog, .size = Npos2i(1024, 1024), .pos = Npos2i(move_x_amt, move_y_amt));
        NIMAGE_DRAW(fog, .size = Npos2i(1024, 1024), .pos = Npos2i(move_x_amt - 1024, move_y_amt));
        NIMAGE_DRAW(fog, .size = Npos2i(1024, 1024), .pos = Npos2i(move_x_amt - 1024, move_y_amt - 1024));
        NIMAGE_DRAW(fog, .size = Npos2i(1024, 1024), .pos = Npos2i(move_x_amt, move_y_amt - 1024));
        NIMAGE_DRAW(fog, .size = Npos2i(1024, 1024), .pos = Npos2i(move_x_amt + 1024, move_y_amt));
        NIMAGE_DRAW(fog, .size = Npos2i(1024, 1024), .pos = Npos2i(move_x_amt + 1024, move_y_amt - 1024));
        NShader_stop();
    }
    N_gl_view = oldview;
}
