#ifndef _NME_GAME_H
#define _NME_GAME_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"

NTS(NShader_info);
NTS(NSpritesheet_info);

NShader_info* G_shader_infos;
char** G_image_infos;
NSpritesheet_info* G_spritesheet_infos;

void Game_init();
void Game_destroy();
void Game_loop();

END_HEAD


#endif
