#include "game.h"

#include "globals.h"
#include "wm.h"
#include "log.h"

#include "square.h"
#include "shader.h"
#include "resource.h"
#include "image.h"
#include "splu.h"
#include "sprite.h"
#include "spritesheet.h"

#include "wrap/gl.h"
#include <GLKit/GLKMath.h>

Image* eevee;
Spritesheet* sheet;
sprite_framedata walk_data[] = {
    {1, 100, 1},
    {2, 100, 1},
    {3, 100, 1},
    {4, 100, 1},
    {5, 100, 1},
    {6, 100, 1},
    {0,   0, 0}
};
sprite_framedata trot_data[] = {
    {0, 100, 1},
    {1, 100, 1},
    {2, 100, 1},
    {3, 100, 1},
    {4, 100, 1},
    {5, 100, 1},
    {0,   0, 0}
};
spritesheet_data data[] = {
    {"walk", walk_data, NULL},
    {"trot", trot_data, NULL},
    {NULL, NULL, NULL},
};

void game_update_time() {
    currtime = wm.get_millis();
    delta = currtime - lasttime;
    lasttime = currtime;
}

void game_update_fps() {
    if (currtime >= (lastsecond + 1000)) {
        lastsecond = currtime;
        debug("%i", fps);
        fps = 0;
    }
}

void game_gl_init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, win_width, win_height, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

bool game_load() {
    game_update_time();
    game_update_fps();

    game_gl_init();

    debug("Loading matrices");
    gl_projection = GLKMatrix4MakeOrtho(0.0f, win_width, win_height, 0.0f, -1, 1);
    gl_view = GLKMatrix4Identity;
    gl_model = GLKMatrix4Identity;
    /*gl_model = GLKMatrix4Translate(gl_model, 200, 100, 0);
    gl_model = GLKMatrix4Scale(gl_model, 200, 100, 0);
    GLKMatrix4 test = splu_calc_mvp();
    GLKVector4 test2 = GLKMatrix4MultiplyVector4(test, GLKVector4Make(1, 1, 0, 1));*/
    debug("Loading square");
    square_init();
    debug("Loading shader");
    shader_image = rsc_load_shader("image");
    Shader_bind_attrib(shader_image, 0, "vertex_position");
    Shader_bind_attrib(shader_image, 1, "vertex_UV");
    Shader_link(shader_image);
    debug("Loading image");
    eevee = rsc_load_image("eevee.png");
    debug("Loading sprite");
    sheet = rsc_load_spritesheet("player", data);
    sheet->id = 1;

    debug("FILES");
    char** files = rsc_ls(RSC_JOIN_PATHS("glsl", "image"));
    debug("OKIEEEE");
    /*char* afile;
    for (int i = 0; afile = files[i]; i++) {
        debug("YEAH %s", files[i]);
    }*/
    rsc_ls_free(files);
    debug("FREEEE");

    return true;
}

bool game_destroy() {
    square_destroy();
    Shader_destroy(shader_image);
    Spritesheet_destroy(sheet);
    return true;
}

void game_check_events() {
    wm_event event;
    while (running && wm.next_event(&event)) {
        switch(event.type) {
            case WM_QUIT:
                running = false;
                break;
            case WM_KEYBOARD:
                key_states[event.keyboard.key] = event.keyboard.state;
                break;
            default:
                break;
        }
    }
}

void game_run() {
    while (running) {
        game_update_time();
        game_update_fps();
        game_check_events();

        game_gl_init();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);

        //Image_draw(eevee, pos2i(50, 50));
        Spritesheet_update(sheet);
        Spritesheet_draw(sheet, pos2i(50, 50));

        fps++;
        wm.swap_buffers();
    }
    game_destroy();
}
