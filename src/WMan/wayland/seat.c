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
#include <NUtil.h>
#include "common.h"
#include <wayland-client.h>


extern const struct wl_pointer_listener _WL_pointer_listener;
extern const struct wl_keyboard_listener _WL_keyboard_listener;

static void _WLseat_handle_capabilities(void *data, struct wl_seat *seat, enum wl_seat_capability caps) {
    NUNUSED(data);

    if ((caps & WL_SEAT_CAPABILITY_POINTER) && !_WL_display.pointer) {
        _WL_display.pointer = wl_seat_get_pointer(seat);
        wl_pointer_add_listener(_WL_display.pointer, &_WL_pointer_listener, NULL);
    } else if (!(caps & WL_SEAT_CAPABILITY_POINTER) && _WL_display.pointer) {
        wl_pointer_destroy(_WL_display.pointer);
        _WL_display.pointer = NULL;
    }

    if ((caps & WL_SEAT_CAPABILITY_KEYBOARD) && !_WL_display.keyboard) {
        _WL_display.keyboard = wl_seat_get_keyboard(seat);
        wl_keyboard_add_listener(_WL_display.keyboard, &_WL_keyboard_listener, NULL);
    } else if (!(caps & WL_SEAT_CAPABILITY_KEYBOARD) && _WL_display.keyboard) {
        wl_keyboard_destroy(_WL_display.keyboard);
        _WL_display.keyboard = NULL;
    }
}

const struct wl_seat_listener _WL_seat_listener = {
    _WLseat_handle_capabilities,
    NULL
};
