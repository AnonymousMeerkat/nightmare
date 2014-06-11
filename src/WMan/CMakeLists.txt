if(SDL_FOUND)
    set(SOURCES SDL.c)
endif(SDL_FOUND)
if(SDL2_FOUND)
    set(SOURCES ${SOURCES} SDL2.c)
endif(SDL2_FOUND)

add_library(NWMan ${SOURCES})
