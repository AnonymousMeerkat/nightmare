/*
    Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
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

#include <string.h>
#include <NUtil.h>
#include "common.h"

extern const struct xdg_shell_listener _WL_xdg_shell_listener;
extern const struct wl_seat_listener _WL_seat_listener;

static void _WLregistry_handle(void* data, struct  wl_registry* registry, uint32_t name, const char* interface, uint32_t version) {
    NUNUSED(data);
    NUNUSED(version);

    if (NSTREQ(interface, "wl_compositor")) {
        _WL_display.compositor = wl_registry_bind(registry, name, &wl_compositor_interface, 1);
    } else if (NSTREQ(interface, "xdg_shell")) {
        _WL_display.shell = wl_registry_bind(registry, name, &xdg_shell_interface, 1);
        xdg_shell_add_listener(_WL_display.shell, &_WL_xdg_shell_listener, NULL);
        xdg_shell_use_unstable_version(_WL_display.shell, 4);
    } else if (NSTREQ(interface, "wl_seat")) {
        _WL_display.seat = wl_registry_bind(registry, name, &wl_seat_interface, 1);
        wl_seat_add_listener(_WL_display.seat, &_WL_seat_listener, NULL);
    }
}

static void _WLregistry_handle_remove(void* data, struct wl_registry* registry, uint32_t name) {
    NUNUSED(data);
    NUNUSED(registry);
    NUNUSED(name);
}

const struct wl_registry_listener _WL_registry_listener = {
    _WLregistry_handle,
    _WLregistry_handle_remove
};
