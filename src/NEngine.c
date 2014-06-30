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

bool NEngine_init() {
    NEngine_update_time();
    NEngine_update_fps();

    NEngine_gl_init();

    srand(0);

    Ndebug("Initializing matrices");
    N_gl_projection = GLKMatrix4MakeOrtho(0.0f, N_win_size.x, N_win_size.y, 0.0f, -1, 1);
    N_gl_view = GLKMatrix4Identity;
    N_gl_model = GLKMatrix4Identity;

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

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);

        Game_loop();

        N_fps++;
        N_WMan.swap_buffers();
    }
}
