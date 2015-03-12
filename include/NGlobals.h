/*
    Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
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

#ifndef _NME_GLOBALS_H
#define _NME_GLOBALS_H

/**
 * \file
 * \brief Global variables
 */

#include "NTypes.h"
#include "NUtil.h"
#include "NVecTypes.h"

// Exports
NTS(NShader);
NTS(NImage);
NTS(NSpritesheet);
NTS(NLevel);
NTS(NEntity);
NTS(NShader_info);
NTS(NSpritesheet_data);
NTS(NSpritesheet_info);
NTS(NLevel_info);

#define N_SHADER_IMAGE 0


// Functions

/**
 * \brief Initialize globals to starting values
 */
void NGlobals_init();

/**
 * \brief Free memory used by globals
 *
 * \details This function will only free memory to variables
 *   that allocated memory during the initialization.
 */
void NGlobals_destroy();

// Init

extern int N_argc;
extern char** N_argv;

// Window

extern char* N_WMan_backend;
extern NVec2i_t N_win_pos;
extern NVec2i_t N_win_size;

/**
 * \brief Window title
 *
 * \details The game will override this one
 */
extern char* N_win_title;

// Logging

extern short N_indent;

// Resource

extern char* N_rsc_path;

// OpenGL

extern NMat4f_t N_gl_projection;
extern NMat4f_t N_gl_view;
extern NMat4f_t N_gl_model;

// Shader

extern bool N_shader_egl;
extern char* N_shader_head;
extern size_t N_shader_head_len;

extern NShader* N_shader;

// Resource Pool

extern NShader** N_shaders;
extern NImage** N_images;
extern NSpritesheet** N_spritesheets;
extern NLevel** N_levels;
extern NEntity* N_player;

// Input

/**
 * \brief Key states (press or release)
 *
 * \details If you want to see whether the A key is pressed,
 *   you would check N_key_states['A']
 */
extern bool N_key_states[65536];

// Engine

extern bool N_running;
extern uint N_delta;
extern uint N_lasttime;
extern uint N_currtime;
extern uint N_lastsecond;
extern uint N_fps;

extern NVec2i_t N_game_size;

#endif
