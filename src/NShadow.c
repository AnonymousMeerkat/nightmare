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
