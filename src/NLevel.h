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
