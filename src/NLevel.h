#ifndef _NME_LEVEL_H
#define _NME_LEVEL_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NDynamic_t.h"
#include "NRect.h"
#include "NImage.h"
#include "NEntity.h"

NENUM(NLevel_hotspot_type, {
    N_LEVEL_HOTSPOT_CLICK = 0,
    N_LEVEL_HOTSPOT_LOCATION = 1
});

NSTRUCT(NLevel_hotspot, {
    NRecti area;
    NLevel_hotspot_type type;
    int action_type;
    void* data;
});

NSTRUCT(NLevel_layer, {
    NImage* base;
    NLevel_hotspot* hotspots;
});

NSTRUCT(NLevel_layer_data, {
    NLevel_hotspot* hotspots;
});

NSTRUCT(NLevel_info, {
    char* name;
    NLevel_layer_data* datas;
});

NSTRUCT(NLevel, {
    NLevel_layer* layers;
    NPosz offset;
    NPosf camera;

    NLIST(NEntity*) entities;
});

NLevel* NLevel_new(NLevel_layer* layers, NPosz offset);
void NLevel_destroy(NLevel* level);

#define NLEVEL_GET_LAYER(level, id) ((level)->layers[(id) - (level)->offset])

void NLevel_draw(NLevel* level);

END_HEAD

#endif
