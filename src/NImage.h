#ifndef _NME_IMAGE_H
#define _NME_IMAGE_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NPos.h"
#include "NTypes.h"

NENUM(NImage_type, {
    NImage_IMAGE = 0,
    NImage_FBO = 1
});

NSTRUCT(NImage, {
    NImage_type type;
    uint id;
    NPos2i size;
    void* data;
});

NImage* NImage_new(NImage_type type);
void NImage_destroy(NImage* image);

unsigned char* NImage_load_raw(char* path, NPos2i* size);
bool NImage_load(NImage* image, char* path);

void NImage_record(NImage* image); // FBO
void NImage_stoprecord();

void NImage_bind(NImage* image);
void NImage_unbind();

void NImage_draw(NImage* image, NPos2i pos, bool flip, float alpha);

END_HEAD

#endif
