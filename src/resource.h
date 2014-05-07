#ifndef _SP_RESOURCE_H
#define _SP_RESOURCE_H

#include "compat.h"

#include "misc.h"

START_HEAD

TS(Shader);
TS(Image);

bool rsc_init();
void rsc_destroy();

char* rsc_get_path(char* simplepath);
char* rsc_read_file(char* path);

// Misc
Shader* rsc_load_shader(char* name);
Image* rsc_load_image(char* name);

END_HEAD

#endif
