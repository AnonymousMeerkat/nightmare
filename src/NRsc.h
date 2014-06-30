#ifndef _NME_RSC_H
#define _NME_RSC_H

#include "NCompat.h"

START_HEAD

#include "NPorting.h"
#include "NUtil.h"

typedef void* NDLL;

NTS(NShader);
NTS(NShader_attrib);
NTS(NShader_info);
NTS(NImage);
NTS(NSprite);
NTS(NSpritesheet);
NTS(NLevel);
NTS(NSprite_framedata);
NTS(NSpritesheet_data);
NTS(NSpritesheet_info);
NTS(NLevel_layer_data);
NTS(NLevel_info);

bool NRsc_init();
void NRsc_destroy();

#define NRSC_JOIN_PATHS(path1, path2) path1 SLASH path2

char* NRsc_join_paths(char* path1, char* path2); // FREE
char* NRsc_remove_ext(char* path); // FREE

// All of these functions ONLY accept simple paths
char* NRsc_get_path(char* simplepath); // FREE
char** NRsc_ls(char* path); \
void NRsc_ls_free(char** lsd);
char* NRsc_read_file(char* path);

// Misc
NDLL* NRsc_load_dll();
NShader* NRsc_load_shader(char* name, NShader_attrib* attribs);
NImage* NRsc_load_image(char* name);
NSprite* NRsc_load_sprite(char** paths, NSprite_framedata* framedata);
NSprite* NRsc_load_sprite_dir(char* path, NSprite_framedata* framedata);
NSpritesheet* NRsc_load_spritesheet(char* name, NSpritesheet_data* datas);
NLevel* NRsc_load_level(char* name, NLevel_layer_data* info);

void NRsc_load_shaders(NShader_info* infos);
void NRsc_load_images(char** names);
void NRsc_load_spritesheets(NSpritesheet_info* infos);
void NRsc_load_levels(NLevel_info* infos);

void NRsc_free_shaders();
void NRsc_free_images();
void NRsc_free_spritesheets();
void NRsc_free_levels();

END_HEAD

#endif
