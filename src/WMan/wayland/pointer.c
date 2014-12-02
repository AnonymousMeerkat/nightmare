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

#include <NWMan.h>
#include "../event.h"

#include <wayland-client.h>

static void _WLpointer_handle_enter(void *data, struct wl_pointer *pointer, uint32_t serial, struct wl_surface *surface, wl_fixed_t sx, wl_fixed_t sy) {
    NUNUSED(data);
    NUNUSED(pointer);
    NUNUSED(serial);
    NUNUSED(surface);
    NUNUSED(sx);
    NUNUSED(sy);

    wl_pointer_set_cursor(pointer, serial, NULL, 0, 0);

    NWMan_event e;
    e.type = N_WMAN_FOCUS;
    e.window_focus = true;

    NWMan_events_push(e);
}

static void _WLpointer_handle_leave(void *data, struct wl_pointer *pointer, uint32_t serial, struct wl_surface *surface) {
    NUNUSED(data);
    NUNUSED(pointer);
    NUNUSED(serial);
    NUNUSED(surface);

    NWMan_event e;
    e.type = N_WMAN_FOCUS;
    e.window_focus = false;

    NWMan_events_push(e);
}

// TODO: Implement!
static void _WLpointer_handle_motion(void *data, struct wl_pointer *pointer, uint32_t time, wl_fixed_t sx, wl_fixed_t sy) {
    NUNUSED(data);
    NUNUSED(pointer);
    NUNUSED(time);
    NUNUSED(sx);
    NUNUSED(sy);
}

static void _WLpointer_handle_button(void *data, struct wl_pointer *pointer, uint32_t serial, uint32_t time, uint32_t button, uint32_t state) {
    NUNUSED(data);
    NUNUSED(pointer);
    NUNUSED(serial);
    NUNUSED(time);
    NUNUSED(button);
    NUNUSED(state);
}

static void _WLpointer_handle_axis(void *data, struct wl_pointer *pointer, uint32_t time, uint32_t axis, wl_fixed_t value) {
    NUNUSED(data);
    NUNUSED(pointer);
    NUNUSED(time);
    NUNUSED(axis);
    NUNUSED(value);
}

const struct wl_pointer_listener _WL_pointer_listener = {
    _WLpointer_handle_enter,
    _WLpointer_handle_leave,
    _WLpointer_handle_motion,
    _WLpointer_handle_button,
    _WLpointer_handle_axis
};
