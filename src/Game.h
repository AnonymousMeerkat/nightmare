#ifndef _NME_GAME_H
#define _NME_GAME_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"

NTS(NShader_info);
NTS(NSpritesheet_info);

extern NShader_info* G_shader_infos;
extern char** G_image_infos;
extern NSpritesheet_info* G_spritesheet_infos;
extern NLevel_info* G_level_infos;

void Game_init();
void Game_destroy();
void Game_loop();

END_HEAD


#endif
