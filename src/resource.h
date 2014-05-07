#ifndef _SP_RESOURCE_H
#define _SP_RESOURCE_H

#include "compat.h"

#include "misc.h"
#include "porting.h"

START_HEAD

TS(Shader);
TS(Image);

bool rsc_init();
void rsc_destroy();

#ifndef WIN32
#  define SLASH "/"
#else
#  define SLASH "\\"
#endif

#define RSC_JOIN_PATHS(path1, path2) path1 SLASH path2

char* rsc_join_paths(char* path1, char* path2);

char* rsc_get_path(char* simplepath);
char* rsc_read_file(char* path);

// Misc
Shader* rsc_load_shader(char* name);
Image* rsc_load_image(char* name);

END_HEAD

#endif
