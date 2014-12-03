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

#include "NShadow.h"

#include "NLevel.h"
#include "NLog.h"
#include "NEntity.h"
#include "NShader.h"
#include "NVecMath.h"

void NShadow_draw(NLevel* level, NEntity* entity, int layer) {
    NVec3f_t light_pos = NVec3f(400, 170, 75);

    float layer_z = NLevel_get_z(level, layer);
    float entity_z = NLevel_get_z(level, entity->z);

    float z_ratio = (light_pos.z - layer_z) / (light_pos.z - entity_z);

    NVec3f_t entity_pos = NVec3f(entity->pos.x, entity->pos.y, entity_z);
    NVec3f_t entity_size = NVec3f(entity->pos.x + entity->size.x, entity->pos.y + entity->size.y, entity_z);


    NVec3f_t pos_dir = NVec3f_sub(entity_pos, light_pos);
    NVec3f_t pos_projection = NVec3f_muls(pos_dir, z_ratio);
    NVec3f_t pos_projected = NVec3f_add(light_pos, pos_projection);

    NVec3f_t size_dir = NVec3f_sub(entity_size, light_pos);
    NVec3f_t size_projected = NVec3f_add(light_pos, NVec3f_muls(size_dir, z_ratio));

    NVec3f_t size = NVec3f_sub(size_projected, pos_projected);
    if (pos_projected.y + size.y < 203) {
        size.y = 203 - pos_projected.y;
    }

    float angle = NVec3f_len(pos_projection) / NABS(light_pos.z - layer_z);
    float alpha = (9 - (NCLAMP(angle, 1, 10) - 1)) / 9;

    NShader_run(N_shaders[2]);
    NShader_set_float(N_shaders[2], "sample_dist", NCLAMP(1. - alpha, .2, .5));
    NENTITY_DRAW(entity, .pos = NVec3f_2i(pos_projected), .size = NVec3f_2i(size), .alpha = alpha);
    NShader_stop();
}
