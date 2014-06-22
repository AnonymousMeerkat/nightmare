#include "NWMan.h"

#include "WMan/SDL.h"
#include "WMan/SDL2.h"
#include "WMan/W32.h"
#include "WMan/X11.h"

#include "NLog.h"

NWMan N_WMan;

NWMan_event NWMan_event_new(NWMan_event_type type) {
    NWMan_event event;
    event.type = type;

    return event;
}


bool NWMan_init() {
    Ndebug("Choosing WM backend");
#if defined(X11_FOUND)
        Ndebug("Chosen X11");
        NWMan_X11_init();
        N_WMan = N_WMan_X11;
#elif defined(WIN32)
        Ndebug("Chosen W32");
        NWMan_W32_init();
        N_WMan = N_WMan_W32;
#elif defined(SDL_FOUND)
        Ndebug("Chosen SDL");
        NWMan_SDL_init();
        N_WMan = N_WMan_SDL;
#elif defined(SDL2_FOUND)
        Ndebug("Chosen SDL2");
        NWMan_SDL2_init();
        N_WMan = N_WMan_SDL2;
#else
        Nerror("No backend available!!");
        return false;
#endif
    return N_WMan.init();
}

bool NWMan_destroy() {
    return N_WMan.destroy();
}
