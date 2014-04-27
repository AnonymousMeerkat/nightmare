#include "../wm.h"
#include "../globals.h"

// SDL 1 implementation

#include <SDL/SDL.h>

wm_s wm_sdl;

bool sdl_init(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    return true;
}

bool sdl_destroy() {
    SDL_Quit();
    return true;
}


bool sdl_create_window() {
    if (SDL_SetVideoMode(win_width, win_height, 8, SDL_OPENGL) == NULL) {
        return false;
    }
    return true;
}

bool sdl_destroy_window() {
    return true; // We'll use sdl_destroy to actually destroy the window
}


void sdl_swap_buffers() {
    SDL_GL_SwapBuffers();
}


bool sdl_next_event(wm_event* event) {
    enum wm_event_type type;
    SDL_Event sev;

nextevent:

    if (!SDL_PollEvent(&sev)) {
        return false;
    }

    switch(sev.type) {
        case SDL_QUIT:
            type = WM_QUIT;
            break;
        case SDL_ACTIVEEVENT:
            type = WM_FOCUS;
            break;
        case SDL_VIDEORESIZE:
            type = WM_RESIZE;
            break;
        case SDL_KEYUP:
        case SDL_KEYDOWN:
            type = WM_KEYBOARD;
            break;
        case SDL_MOUSEMOTION:
            type = WM_MOUSE_MOVE;
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            type = WM_MOUSE_BUTTON;
            break;
        default:
            goto nextevent;
            break;
    };

    *event = wm_event_new(type);

    switch(type) {
        case WM_QUIT:
            break;
        case WM_FOCUS:
            if (sev.active.state == SDL_APPMOUSEFOCUS) {
                goto nextevent;
            }
            event->window_focus = sev.active.gain;
            break;
        case WM_RESIZE:
            event->window_size.x = sev.resize.w;
            event->window_size.y = sev.resize.h;
            break;
        case WM_KEYBOARD:
            event->keyboard.state = (sev.type == SDL_KEYDOWN);
            event->keyboard.key = sev.key.keysym.sym;
            break;
        case WM_MOUSE_MOVE:
            event->mouse_pos.x = sev.motion.x;
            event->mouse_pos.y = sev.motion.y;
            break;
        case WM_MOUSE_BUTTON:
            event->mouse_button.state = (sev.type == SDL_MOUSEBUTTONDOWN);
            switch(sev.button.button) {
                case SDL_BUTTON_LEFT:
                    event->mouse_button.id = WM_MOUSE_LEFT;
                    break;
                case SDL_BUTTON_RIGHT:
                    event->mouse_button.id = WM_MOUSE_RIGHT;
                    break;
                case SDL_BUTTON_MIDDLE:
                    event->mouse_button.id = WM_MOUSE_MIDDLE;
                    break;
                case SDL_BUTTON_WHEELUP:
                    event->type = WM_MOUSE_WHEEL;
                    event->mouse_wheel = 1;
                    break;
                case SDL_BUTTON_WHEELDOWN:
                    event->type = WM_MOUSE_WHEEL;
                    event->mouse_wheel = -1;
                    break;
            };
            break;
        default:
            goto nextevent;
            break;
    }

    return true;
}


void wm_sdl_init() {
    wm_sdl.init = sdl_init;
    wm_sdl.destroy = sdl_destroy;

    wm_sdl.create_window = sdl_create_window;
    wm_sdl.destroy_window = sdl_destroy_window;

    wm_sdl.swap_buffers = sdl_swap_buffers;

    wm_sdl.next_event = sdl_next_event;
}
