#include "wm.h"

#include "wm/sdl.h"

wm_s wm;

wm_event wm_event_new(enum wm_event_type type) {
    wm_event event;
    event.type = type;

    if (type == WM_QUIT) {
        event.window_quit = true;
    }

    return event;
}


bool wm_init(int argc, char** argv) {
    wm_sdl_init();

    wm = wm_sdl; // FIXME
    return wm.init(argc, argv);
}

bool wm_destroy() {
    return wm.destroy();
}
