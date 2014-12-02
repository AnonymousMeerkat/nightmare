set(SOURCES common.c event.c)

if(SDL2_FOUND)
    set(SOURCES ${SOURCES} SDL2.c)
endif(SDL2_FOUND)
#if(SDL_FOUND)
#    set(SOURCES ${SOURCES} SDL.c)
#endif(SDL_FOUND)
if(WIN32)
    set(SOURCES ${SOURCES} W32.c)
endif(WIN32)
if(X11_FOUND)
    set(SOURCES ${SOURCES} X11.c)
endif(X11_FOUND)
if(WL_FOUND)
    set(SOURCES ${SOURCES}
        wayland/common.c
        wayland/seat.c
        wayland/keyboard.c
        wayland/pointer.c
        wayland/registry.c
        wayland/window.c
        wayland/xdg-shell.c
        wayland/xdg-surface.c
        WL.c
    )
endif(WL_FOUND)

add_library(NWMan STATIC ${SOURCES})
