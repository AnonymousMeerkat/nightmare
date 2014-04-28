#include "../wm.h"
#include "../globals.h"
#include "../log.h"

// SDL 2 implementation

#include <SDL2/SDL.h>

wm_s wm_sdl2;

SDL_Window* sdl2_window;
SDL_GLContext sdl2_glcontext;

bool sdl2_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    return true;
}

bool sdl2_destroy() {
    SDL_Quit();
    return true;
}


bool sdl2_create_window() {
    debug("Creating window");
    sdl2_window = SDL_CreateWindow(
        win_title,
        win_x,
        win_y,
        win_width,
        win_height,
        SDL_WINDOW_OPENGL
    );
    if (sdl2_window == NULL) {
        return false;
    }
    debug("Creating GL context");
    sdl2_glcontext = SDL_GL_CreateContext(sdl2_window);
    return true;
}

bool sdl2_destroy_window() {
    debug("Destroying GL context");
    SDL_GL_DeleteContext(sdl2_glcontext);
    debug("Destroying window");
    SDL_DestroyWindow(sdl2_window);
    return true;
}


void sdl2_swap_buffers() {
    SDL_GL_SwapWindow(sdl2_window);
}


bool sdl2_next_event(wm_event* event) {
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
        case SDL_WINDOWEVENT:
            switch(sev.window.event) {
                case SDL_WINDOWEVENT_SHOWN:
                case SDL_WINDOWEVENT_HIDDEN:
                case SDL_WINDOWEVENT_EXPOSED:
                case SDL_WINDOWEVENT_RESTORED:
                case SDL_WINDOWEVENT_MINIMIZED:
                case SDL_WINDOWEVENT_MAXIMIZED:
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                case SDL_WINDOWEVENT_FOCUS_LOST:
                    type = WM_FOCUS;
                    break;
                case SDL_WINDOWEVENT_RESIZED:
                    type = WM_RESIZE;
                    break;
                default:
                    goto nextevent;
                    break;
            };
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
        case SDL_MOUSEWHEEL:
            type = WM_MOUSE_WHEEL;
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
            switch(sev.window.event) {
                case SDL_WINDOWEVENT_SHOWN:
                case SDL_WINDOWEVENT_EXPOSED:
                case SDL_WINDOWEVENT_RESTORED:
                case SDL_WINDOWEVENT_MAXIMIZED:
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    event->window_focus = true;
                    break;
                default:
                    event->window_focus = false;
                    break;
            };
            break;
        case WM_RESIZE:
            event->window_size.x = sev.window.data1;
            event->window_size.y = sev.window.data2;
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
                case SDL_BUTTON_X1:
                    event->mouse_button.id = 3;
                    break;
                case SDL_BUTTON_X2:
                    event->mouse_button.id = 4;
                    break;
            };
            break;
        case WM_MOUSE_WHEEL:
            event->mouse_wheel = sev.wheel.y; // XXX: Is this okay?
            break;
        default:
            goto nextevent;
            break;
    }

    return true;
}

uint sdl2_get_millis() {
    return SDL_GetTicks();
}

void sdl2_sleep(uint millis) {
    SDL_Delay(millis);
}


void wm_sdl2_init() {
    wm_sdl2.init = sdl2_init;
    wm_sdl2.destroy = sdl2_destroy;

    wm_sdl2.create_window = sdl2_create_window;
    wm_sdl2.destroy_window = sdl2_destroy_window;

    wm_sdl2.swap_buffers = sdl2_swap_buffers;

    wm_sdl2.next_event = sdl2_next_event;

    wm_sdl2.get_millis = sdl2_get_millis;
    wm_sdl2.sleep = sdl2_sleep;
}
