#include "../NWMan.h"

#include "../NGlobals.h"

// SDL 1 implementation

#include <SDL/SDL.h>

NWMan N_WMan_SDL;

bool WMSDL_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    return true;
}

bool WMSDL_destroy() {
    SDL_Quit();
    return true;
}


bool WMSDL_create_window() {
    if (SDL_SetVideoMode(N_win_size.x, N_win_size.y, 8, SDL_OPENGL) == NULL) {
        return false;
    }
    SDL_WM_SetCaption(N_win_title, NULL);
    return true;
}

bool WMSDL_destroy_window() {
    return true; // We'll use sdl_destroy to actually destroy the window
}


void WMSDL_swap_buffers() {
    SDL_GL_SwapBuffers();
}


bool WMSDL_next_event(NWMan_event* event) {
    NWMan_event_type type;
    SDL_Event sev;

nextevent:

    if (!SDL_PollEvent(&sev)) {
        return false;
    }

    switch(sev.type) {
        case SDL_QUIT:
            type = N_WMAN_QUIT;
            break;
        case SDL_ACTIVEEVENT:
            type = N_WMAN_FOCUS;
            break;
        case SDL_VIDEORESIZE:
            type = N_WMAN_RESIZE;
            break;
        case SDL_KEYUP:
        case SDL_KEYDOWN:
            type = N_WMAN_KEYBOARD;
            break;
        case SDL_MOUSEMOTION:
            type = N_WMAN_MOUSE_MOVE;
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
            type = N_WMAN_MOUSE_BUTTON;
            break;
        default:
            goto nextevent;
            break;
    };

    *event = NWMan_event_new(type);

    switch(type) {
        case N_WMAN_QUIT:
            break;
        case N_WMAN_FOCUS:
            if (sev.active.state == SDL_APPMOUSEFOCUS) {
                goto nextevent;
            }
            event->window_focus = sev.active.gain;
            break;
        case N_WMAN_RESIZE:
            event->window_size.x = sev.resize.w;
            event->window_size.y = sev.resize.h;
            break;
        case N_WMAN_KEYBOARD:
            event->keyboard.state = (sev.type == SDL_KEYDOWN);
            event->keyboard.key = sev.key.keysym.sym;
            break;
        case N_WMAN_MOUSE_MOVE:
            event->mouse_pos.x = sev.motion.x;
            event->mouse_pos.y = sev.motion.y;
            break;
        case N_WMAN_MOUSE_BUTTON:
            event->mouse_button.state = (sev.type == SDL_MOUSEBUTTONDOWN);
            switch(sev.button.button) {
                case SDL_BUTTON_LEFT:
                    event->mouse_button.id = N_WMAN_MOUSE_LEFT;
                    break;
                case SDL_BUTTON_RIGHT:
                    event->mouse_button.id = N_WMAN_MOUSE_RIGHT;
                    break;
                case SDL_BUTTON_MIDDLE:
                    event->mouse_button.id = N_WMAN_MOUSE_MIDDLE;
                    break;
                case SDL_BUTTON_WHEELUP:
                    event->type = N_WMAN_MOUSE_WHEEL;
                    event->mouse_wheel = 1;
                    break;
                case SDL_BUTTON_WHEELDOWN:
                    event->type = N_WMAN_MOUSE_WHEEL;
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

uint WMSDL_get_millis() {
    return SDL_GetTicks();
}

void WMSDL_sleep(uint millis) {
    SDL_Delay(millis);
}


void NWMan_SDL_init() {
#define var N_WMan_SDL
    var.init = WMSDL_init;
    var.destroy = WMSDL_destroy;

    var.create_window = WMSDL_create_window;
    var.destroy_window = WMSDL_destroy_window;

    var.swap_buffers = WMSDL_swap_buffers;

    var.next_event = WMSDL_next_event;

    var.get_millis = WMSDL_get_millis;
    var.sleep = WMSDL_sleep;
}