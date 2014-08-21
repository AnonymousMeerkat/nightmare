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

#include "NGlobals.h"

#include "NDynamic_t.h"


int N_argc;
char** N_argv;

NPos2i N_win_pos;
NPos2i N_win_size;
//char* N_win_title;

short N_indent;

char* N_rsc_path;

GLKMatrix4 N_gl_projection;
GLKMatrix4 N_gl_view;
GLKMatrix4 N_gl_model;

NShader** N_shaders;
NImage** N_images;
NSpritesheet** N_spritesheets;
NLevel** N_levels;
NEntity* N_player;

bool N_key_states[65536];

char* N_shader_head;
size_t N_shader_head_len;

bool N_running;
uint N_delta;
uint N_lasttime;
uint N_currtime;
uint N_lastsecond;
uint N_fps;

NPos2i N_game_size;

NShader* N_shader;


void NGlobals_init() {
    N_win_pos = N_Pos2i0;
    N_win_size = Npos2i(800, 600);

    N_indent = 0;

    N_rsc_path = "";

    NLIST_NEW(NShader*, N__shaders);
    N_shaders = N__shaders.data;
    NLIST_NEW(NImage*, N__images);
    N_images = N__images.data;
    NLIST_NEW(NSpritesheet*, N__spritesheets);
    N_spritesheets = N__spritesheets.data;
    NLIST_NEW(NLevel*, N__levels);
    N_levels = N__levels.data;

    N_shader_head = NULL;
    N_shader_head_len = 0;

    N_running = true;
    N_delta = 0;
    N_lasttime = 0;
    N_currtime = 0;
    N_lastsecond = 0;
    N_fps = 0;

    N_game_size = Npos2i(800, 256);

    N_shader = NULL;
}

void NGlobals_destroy() {
}
