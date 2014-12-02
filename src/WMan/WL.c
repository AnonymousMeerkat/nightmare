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

#include <NLog.h>
#include <NGlobals.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#include <wayland-client.h>
#include <wayland-egl.h>
#include <wayland-cursor.h>
#include <wl/xdg-shell-client-protocol.h>

#include <GLES2/gl2.h>
#include <EGL/egl.h>

#include "event.h"
#include "wayland/common.h"

extern const struct xdg_shell_listener _WL_xdg_shell_listener;
extern const struct wl_registry_listener _WL_registry_listener;
extern const struct xdg_surface_listener _WL_xdg_surface_listener;
extern const struct wl_seat_listener _WL_seat_listener;
extern const struct wl_pointer_listener _WL_pointer_listener;
extern const struct wl_keyboard_listener _WL_keyboard_listener;


bool WL_init() {
    _WL_display.running = true;

    // Initialize wayland
    _WL_display.display = wl_display_connect(NULL);

    if (!_WL_display.display) {
        Nerror("Can't connect to display (WL)");
        return false;
    }

    // Initialize events
    NWMan_events_init();

    // Initialize registry
    _WL_display.registry = wl_display_get_registry(_WL_display.display);
    wl_registry_add_listener(_WL_display.registry, &_WL_registry_listener, NULL);

    // Sync
    wl_display_dispatch(_WL_display.display);

    return true;
}

bool WL_destroy() {
    wl_registry_destroy(_WL_display.registry);
    NWMan_events_destroy();
    wl_display_flush(_WL_display.display);
    wl_display_disconnect(_WL_display.display);

    return true;
}


bool WL_create_window();
bool WL_destroy_window();
void WL_swap_buffers();


void WL_get_events() {
    wl_display_dispatch_pending(_WL_display.display);
}

bool WL_next_event(NWMan_event* e) {
    if (_NWMan_events.size > 0) {
        *e = NWMan_events_pop();
        return true;
    } else {
        return false;
    }
}


NWMan N_WMan_WL = {
    .init = WL_init,
    .destroy = WL_destroy,

    .create_window = WL_create_window,
    .destroy_window = WL_destroy_window,

    .swap_buffers = WL_swap_buffers,

    .get_events = WL_get_events,
    .next_event = WL_next_event,

    .shift_key = 16,
    .left_key = 37,
    .right_key = 39
};
