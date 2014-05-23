#ifndef _SP_RESOURCE_H
#define _SP_RESOURCE_H

#include "compat.h"

#include "misc.h"
#include "porting.h"
#include "yasl/yutil.h"

START_HEAD

TS(Shader);
TS(Image);
TS(Sprite);
TS(Spritesheet);
TS(sprite_framedata);
TS(spritesheet_data);

bool rsc_init();
void rsc_destroy();

#ifndef WIN32
#  define SLASH "/"
#else
#  define SLASH "\\"
#endif

#define RSC_JOIN_PATHS(path1, path2) path1 SLASH path2

char* rsc_join_paths(char* path1, char* path2); // FREE
char* rsc_remove_ext(char* path); // FREE

// All of these functions ONLY accept simple paths
char* rsc_get_path(char* simplepath); // FREE
char** rsc_ls(char* path); \
void rsc_ls_free(char** lsd);
char* rsc_read_file(char* path);

// Misc
Shader* rsc_load_shader(char* name);
Image* rsc_load_image(char* name);
Sprite* rsc_load_sprite(char** paths, sprite_framedata* framedata);
Sprite* rsc_load_sprite_dir(char* path, sprite_framedata* framedata);
Spritesheet* rsc_load_spritesheet(char* name, spritesheet_data* datas);

END_HEAD

#endif
