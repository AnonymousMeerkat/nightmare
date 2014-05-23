#ifndef _SP_IMAGE_H
#define _SP_IMAGE_H

#include "compat.h"

#include "misc.h"
#include "pos.h"
#include "types.h"

START_HEAD

ENUM(Image_type, {
    Image_IMAGE = 0,
    Image_FBO = 1
});

STRUCT(Image, {
    Image_type type;
    uint id;
    Pos2i size;
    void* data;
});

Image* Image_new(Image_type type);
void Image_destroy(Image* image);

bool Image_load(Image* image, char* path);

void Image_record(Image* image); // FBO
void Image_stoprecord();

void Image_bind(Image* image);
void Image_unbind();

void Image_draw(Image* image, Pos2i pos);

END_HEAD

#endif
