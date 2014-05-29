#include "NWMan.h"

#include "WMan/SDL.h"
#include "WMan/SDL2.h"

#include "NLog.h"

NWMan N_WMan;

NWMan_event NWMan_event_new(NWMan_event_type type) {
    NWMan_event event;
    event.type = type;

    if (type == N_WMAN_QUIT) {
        event.window_quit = true;
    }

    return event;
}


bool NWMan_init() {
    NWMan_SDL_init();
    NWMan_SDL2_init();

    Ndebug("Choosing WM backend");
    if (SDL_FOUND) {
        Ndebug("Chosen SDL");
        N_WMan = N_WMan_SDL;
    } else if (SDL2_FOUND) {
        Ndebug("Chosen SDL2");
        N_WMan = N_WMan_SDL2;
    } else {
        Nerror("No backend chosen!");
        return false;
    }
    return N_WMan.init();
}

bool NWMan_destroy() {
    return N_WMan.destroy();
}
