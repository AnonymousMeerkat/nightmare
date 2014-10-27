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

#ifndef _NME_RSC_H
#define _NME_RSC_H

#include "NPorting.h"
#include "NUtil.h"
#include "NTypes.h"

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

#define NRSC_JOIN_PATHS(path1, path2) path1 N_SLASH path2

char* NRsc_join_paths(char* path1, char* path2); // FREE
char* NRsc_remove_ext(char* path); // FREE
char* NRsc_get_ext(char* path);

// All of these functions ONLY accept simple paths
char* NRsc_get_path(char* simplepath); // FREE
char** NRsc_ls(char* path); \
void NRsc_ls_free(char** lsd);
char* NRsc_read_file(char* simplepath);

char* NRsc_read_file_rp(char* path);

// Misc
bool NRsc_load_shader_head();
NShader* NRsc_load_shader(char* name, NShader_attrib* attribs);
NImage* NRsc_load_image(char* name);
NImage* NRsc_load_fog(char* name);
NSprite* NRsc_load_sprite(char** paths, NSprite_framedata* framedata);
NSprite* NRsc_load_sprite_dir(char* path, NSprite_framedata* framedata);
NSpritesheet* NRsc_load_spritesheet(char* name, NSpritesheet_data* datas);
NLevel* NRsc_load_level(char* name, NLevel_layer_data* info);

bool NRsc_load_shaders(NShader_info* infos);
bool NRsc_load_images(char** names);
bool NRsc_load_spritesheets(NSpritesheet_info* infos);
bool NRsc_load_levels(NLevel_info* infos);

void NRsc_free_shaders();
void NRsc_free_images();
void NRsc_free_spritesheets();
void NRsc_free_levels();

#endif
