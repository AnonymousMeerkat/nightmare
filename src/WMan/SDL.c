/*
    Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Nightmare Project nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "../NWMan.h"

#include "../NGlobals.h"

// SDL 1 implementation

#include <SDL/SDL.h>

NWMan N_WMan_SDL;

bool WMSDL_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
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

    var.lshift_key = SDLK_LSHIFT;
    var.rshift_key = SDLK_RSHIFT;
    var.left_key = SDLK_LEFT;
    var.right_key = SDLK_RIGHT;
}
