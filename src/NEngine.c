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

    Game_init();

    return true;
}

bool NEngine_destroy() {
    NRsc_free_spritesheets();
    NRsc_free_images();
    NRsc_free_shaders();
    Game_destroy();
    return true;
}

void NEngine_check_events() {
    NWMan_event event;
    while (N_running && N_WMan.next_event(&event)) {
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
