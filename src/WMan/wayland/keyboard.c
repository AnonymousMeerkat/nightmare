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
#include "../event.h"

#include <wayland-client.h>

#define CTRL_KEY 17
#define SHIFT_KEY 16
#define ALT_KEY 18
#define SUPER_KEY 91
#define F_KEY(n) (111 + n)

// Based off of /usr/include/linux/input.h
static char _WL_keymap[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 8,
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\n',
    CTRL_KEY, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '`', SHIFT_KEY, '\\',
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', SHIFT_KEY, '*', ALT_KEY, ' ', 0,
    F_KEY(1), F_KEY(2), F_KEY(3), F_KEY(4), F_KEY(5), F_KEY(6), F_KEY(7), F_KEY(8), F_KEY(9), F_KEY(10), 0, 0,
    '7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', '.',
    0, 0, F_KEY(11), F_KEY(12), 0, 0, 0, 0, 0, 0, 0, '\n', CTRL_KEY, '/', 0, ALT_KEY, '\n',
    36, 38, 33, 37, 39, 35, 40, 34, 45, 46, 0, 0, 0, 0, 0, '=', 0, 19, 0,
    ',', 0, 0, 0, 0, SUPER_KEY, SUPER_KEY, 0
};

static void _WLkeyboard_handle_keymap(void *data, struct wl_keyboard *keyboard, uint32_t format, int fd, uint32_t size) {
    NUNUSED(data);
    NUNUSED(keyboard);
    NUNUSED(format);
    NUNUSED(fd);
    NUNUSED(size);
}

static void _WLkeyboard_handle_enter(void *data, struct wl_keyboard *keyboard, uint32_t serial, struct wl_surface *surface, struct wl_array *keys) {
    NUNUSED(data);
    NUNUSED(keyboard);
    NUNUSED(serial);
    NUNUSED(surface);
    NUNUSED(keys);

    // TODO: Switch this to the single-command format, for prettiness (as in _WLkeyboard_handle_key)
    NWMan_event e;
    e.type = N_WMAN_FOCUS;
    e.window_focus = true;

    NWMan_events_push(e);
}

static void _WLkeyboard_handle_leave(void *data, struct wl_keyboard *keyboard, uint32_t serial, struct wl_surface *surface) {
    NUNUSED(data);
    NUNUSED(keyboard);
    NUNUSED(serial);
    NUNUSED(surface);

    NWMan_event e;
    e.type = N_WMAN_FOCUS;
    e.window_focus = false;

    NWMan_events_push(e);
}

static void _WLkeyboard_handle_key(void *data, struct wl_keyboard *keyboard, uint32_t serial, uint32_t time, uint32_t key, uint32_t state) {
    NUNUSED(data);
    NUNUSED(keyboard);
    NUNUSED(serial);
    NUNUSED(time);

    if (key > 127 || !_WL_keymap[key]) {
        return;
    }

    NWMan_events_push((NWMan_event){
        .type = N_WMAN_KEYBOARD,
        .keyboard = {
            .key = _WL_keymap[key],
            .state = state
        }
    });
}

static void _WLkeyboard_handle_modifiers(void *data, struct wl_keyboard *keyboard, uint32_t serial, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group) {
    NUNUSED(data);
    NUNUSED(keyboard);
    NUNUSED(serial);
    NUNUSED(mods_depressed);
    NUNUSED(mods_latched);
    NUNUSED(mods_locked);
    NUNUSED(group);
}

static void _WLkeyboard_repeat_info(void *data, struct wl_keyboard *keyboard, int32_t rate, int32_t delay) {
    NUNUSED(data);
    NUNUSED(keyboard);
    NUNUSED(rate);
    NUNUSED(delay);
}

const struct wl_keyboard_listener _WL_keyboard_listener = {
    _WLkeyboard_handle_keymap,
    _WLkeyboard_handle_enter,
    _WLkeyboard_handle_leave,
    _WLkeyboard_handle_key,
    _WLkeyboard_handle_modifiers,
    _WLkeyboard_repeat_info
};
