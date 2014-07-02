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

#include "NPos.h"
#include "NLevel.h"
#include "NLog.h"
#include "NEntity.h"
#include "NShader.h"
#include <GLKit/GLKMath.h>

void NShadow_draw(NLevel* level, NEntity* entity, NPosz layer) {
    GLKVector3 light_pos = GLKVector3Make(400, 170, 40.7);

    NPosf layer_z = NLevel_get_z(level, layer);
    NPosf entity_z = NLevel_get_z(level, entity->z);

    NPosf z_ratio = (light_pos.z - layer_z) / (light_pos.z - entity_z);

    GLKVector3 entity_pos = GLKVector3Make(entity->pos.x, entity->pos.y, entity_z);
    GLKVector3 entity_size = GLKVector3Make(entity->pos.x + entity->size.x, entity->pos.y + entity->size.y, entity_z);


    GLKVector3 pos_dir = GLKVector3Subtract(entity_pos, light_pos);
    GLKVector3 pos_projected = GLKVector3Add(light_pos, GLKVector3MultiplyScalar(pos_dir, z_ratio));

    GLKVector3 size_dir = GLKVector3Subtract(entity_size, light_pos);
    GLKVector3 size_projected = GLKVector3Add(light_pos, GLKVector3MultiplyScalar(size_dir, z_ratio));

    GLKVector3 size = GLKVector3Subtract(size_projected, pos_projected);
    if (pos_projected.y + size.y < 203) {
        size.y = 203 - pos_projected.y;
    }

    // FIXME: This is a hack!
    NPos2f old_pos = entity->pos;
    entity->pos = Npos2f(pos_projected.x, pos_projected.y);
    NShader_run(N_shaders[2]);
    NEntity_draw_scale(entity, Npos2i(size.x, size.y));
    NShader_stop();
    entity->pos = old_pos;
}
