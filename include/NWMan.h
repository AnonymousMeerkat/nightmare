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

#ifndef _NME_WMAN_H
#define _NME_WMAN_H

// Internal window manager API

#include "NPos.h"
#include "NUtil.h"
#include "NTypes.h"

NTS(NWMan_event);

NSTRUCT(NWMan, {
    // Init stuff
    bool (*init)();
    bool (*destroy)();

    // Window stuff
    bool (*create_window)();
    bool (*destroy_window)();

    void (*swap_buffers)();

    // Event stuff
    void (*get_events)();
    bool (*next_event)(NWMan_event* event);

    // Time stuff
    uint (*get_millis)();
    void (*sleep)(uint millis);

    // Info
    int shift_key;
    int left_key;
    int right_key;
});

NENUM(NWMan_event_type, {
    N_WMAN_MOUSE_MOVE = 0,
    N_WMAN_MOUSE_BUTTON = 1,
    N_WMAN_MOUSE_WHEEL = 2,

    N_WMAN_KEYBOARD = 10,

    N_WMAN_QUIT = 20,
    N_WMAN_FOCUS = 21
});

#define N_WMAN_MOUSE_LEFT 0
#define N_WMAN_MOUSE_RIGHT 1
#define N_WMAN_MOUSE_MIDDLE 2

NSTRUCT(NWMan_event, {
    NWMan_event_type type;

    union {
        // Mouse

        NPos2i mouse_pos;

        struct {
            short id;
            bool state;
        } mouse_button;

        signed char mouse_wheel; // 1 if up, -1 if down

        // Keyboard

        struct {
            short key;
            bool state;
        } keyboard;

        // Window

        bool window_focus;
    };
});

NWMan_event NWMan_event_new(NWMan_event_type type);


bool NWMan_init();
bool NWMan_destroy();

extern NWMan N_WMan;

#endif
