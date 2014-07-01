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

#include "NEngine.h"

#include "NGlobals.h"
#include "NWMan.h"
#include "NLog.h"

#include "NSquare.h"
#include "NShader.h"
#include "NRsc.h"
#include "NImage.h"
#include "NSplu.h"
#include "NSprite.h"
#include "NSpritesheet.h"
#include "NEntity.h"
#include "Game.h"

#include "wrap/gl.h"
#include <GLKit/GLKMath.h>
#include <stdlib.h>

NRectf viewport;

void NEngine_update_time() {
    N_currtime = N_WMan.get_millis();
    N_delta = N_currtime - N_lasttime;
    N_lasttime = N_currtime;
}

void NEngine_update_fps() {
    if (N_currtime >= (N_lastsecond + 1000)) {
        N_lastsecond = N_currtime;
        Ndebug("FPS: %i", N_fps);
        N_fps = 0;
    }
}

void NEngine_gl_init() {
    /*glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();*/
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void NEngine_viewport() {
    glViewport(viewport.pos.x, viewport.pos.y, viewport.size.x, viewport.size.y);
}

bool NEngine_init() {
    NEngine_update_time();
    NEngine_update_fps();

    NEngine_gl_init();
    viewport = Nsplu_calc_viewport();

    srand(0);

    Ndebug("Initializing matrices");
    N_gl_projection = GLKMatrix4MakeOrtho(0.0f, N_game_size.x, N_game_size.y, 0.0f, -1, 1);
    N_gl_view = GLKMatrix4Identity;
    N_gl_model = GLKMatrix4Identity;

    //N_gl_view = GLKMatrix4Scale(N_gl_view, (float)N_win_size.x / (float)N_game_size.x, (float)N_win_size.y / (float)N_game_size.y, 1.0f);

    Ndebug("Loading models");
    NSquare_init();

    Ndebug("Loading shaders");
    NRsc_load_shaders(G_shader_infos);

    Ndebug("Loading images");
    NRsc_load_images(G_image_infos);

    Ndebug("Loading spritesheets");
    NRsc_load_spritesheets(G_spritesheet_infos);

    Ndebug("Loading levels");
    NRsc_load_levels(G_level_infos);

    Game_init();

    return true;
}

bool NEngine_destroy() {
    NRsc_free_levels();
    NRsc_free_spritesheets();
    NRsc_free_images();
    NRsc_free_shaders();
    Game_destroy();
    return true;
}

void NEngine_check_events() {
    NWMan_event event;
    N_WMan.get_events();
    while (N_running && N_WMan.next_event(&event)) {
        Ndebug("Event: %i", event.type);
        switch(event.type) {
            case N_WMAN_QUIT:
                N_running = false;
                break;
            case N_WMAN_KEYBOARD:
                N_key_states[event.keyboard.key] = event.keyboard.state;
                break;
            default:
                break;
        }
    }
}

void NEngine_run() {
    int glVersion[2] = {-1, -1}; // Set some default values for the version
glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]); // Get back the OpenGL MAJOR version we are using
glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]); // Get back the OpenGL MAJOR version we are using
Ndebug("OpenGL: %i %i", glVersion[0], glVersion[1]);
    while (N_running) {
        NEngine_update_time();
        NEngine_update_fps();
        NEngine_check_events();

        NEngine_gl_init();
        NEngine_viewport();

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);

        Game_loop();

        N_fps++;
        N_WMan.swap_buffers();
    }
}
