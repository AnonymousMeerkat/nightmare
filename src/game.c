#include "game.h"

#include "globals.h"
#include "wm.h"
#include "log.h"

#include "wrap/gl.h"

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

bool game_load() {
    game_update_time();
    game_update_fps();
    return true;
}

void game_check_events() {
    wm_event event;
    while (running && wm.next_event(&event)) {
        switch(event.type) {
            case WM_QUIT:
                running = false;
                break;
            default:
                break;
        }
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

void game_run() {
    while (running) {
        game_update_time();
        game_update_fps();
        game_check_events();

        game_gl_init();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 1.0);

        fps++;
        wm.swap_buffers();
    }
}
