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

#include "X11.h"
#include "../NLog.h"
#include "../NGlobals.h"

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/XKBlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

// Stolen from the WinAPI keyboard mappings ... cuz laziness
#define SHIFT_K 0xA0
#define CTRL_K 0xA2
#define UP_K 0x26
#define DOWN_K 0x28
#define LEFT_K 0x25
#define RIGHT_K 0x27
#define ESC_K 27

NWMan N_WMan_X11;

Display* xl_display;
XVisualInfo* xl_visual_info;
Window xl_root;
Colormap xl_colormap;
Window xl_window;

GLXContext glx_context;

Atom WM_PROTOCOLS;
Atom WM_DELETE_WINDOW;

short _keycodes[256];

int _X11_translate_keycode(int keycode) {
    if (NOUTRANGEX(keycode, 8, 255)) {
        return 0;
    }

    int keysym = XkbKeycodeToKeysym(xl_display, keycode, 0, 0);

    if (NINRANGE(keysym, 'a', 'z')) {
        return keysym - ('a' - 'A');
    }

    switch(keysym) {
        case XK_Shift_R:
        case XK_Shift_L:
            return SHIFT_K;

        case XK_Control_R:
        case XK_Control_L:
            return CTRL_K;

        case XK_Up:
            return UP_K;

        case XK_Down:
            return DOWN_K;

        case XK_Left:
            return LEFT_K;

        case XK_Right:
            return RIGHT_K;

        case XK_Escape:
            return ESC_K;

        default:
            return 0;
    }

    return 0; // Just in case ;)
}

bool _X11_update_keycodes() {
    // Get layout-independant keyboard mapping

    int unused;
    if (!XkbQueryExtension(xl_display, &unused, &unused, &unused, &unused, &unused)) {
        Nerror("XKB not supported!");
        return false;
    }

    static const short mapping[][13] = {
        {
            '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0
        },
        {
            'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', 0
        },
        {
            'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', 0,  0
        },
        {
            'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/',  0,   0,  0
        }
    };

    static const char numbers[][2] = {
        "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"
    };

    XkbDescPtr xkb_description = XkbGetKeyboard(xl_display, XkbAllComponentsMask, XkbUseCoreKbd);
    int min_key_code = NMAX(xkb_description->min_key_code, 0);
    int max_key_code = NMIN(xkb_description->max_key_code, 255);
    int keycode;
    for (keycode = min_key_code; keycode < max_key_code; keycode++) {
        char name[XkbKeyNameLength + 1];
        strncpy(name, xkb_description->names->keys[keycode].name, XkbKeyNameLength);
        name[XkbKeyNameLength] = 0;

        if (name[0] != 'A') {
            continue;
        }

        for (char c = 'E'; c >= 'B'; c--) {
            if (name[1] != c) {
                continue;
            }
            int id = 'E' - c;
            for (int i = 0; mapping[id][i]; i++) {
                if (name[2] != numbers[i][0]) {
                    i = 8;
                    continue;
                }
                if (name[3] == numbers[i][1]) {
                    _keycodes[keycode] = mapping[id][i];
                    break;
                }
            }
            break;
        }
    }

    XkbFreeKeyboard(xkb_description, 0, True);


    // Get layout-dependant keyboard mapping (using plain ole Keysyms)
    for (int keycode = 8; keycode < 256; keycode++) {
        if (_keycodes[keycode] == 0) {
            _keycodes[keycode] = _X11_translate_keycode(keycode);
        }
    }

    return true;
}


bool X11_init() {
    xl_display = XOpenDisplay(NULL);
    if (!xl_display) {
        Nerror("Can't open display");
        return false;
    }

    xl_root = DefaultRootWindow(xl_display);

    return _X11_update_keycodes();
}

bool X11_destroy() {
    XCloseDisplay(xl_display);
    return true;
}


bool X11_create_window() {
    static GLint glx_attributes[] = {
        GLX_RGBA,
        GLX_DEPTH_SIZE, 0,
        GLX_DOUBLEBUFFER,
        None
    };

    xl_visual_info = glXChooseVisual(xl_display, 0, glx_attributes);

    if (xl_visual_info == NULL) {
        Nerror("Can't choose visual (GLX)");
        return false;
    }

    XSetWindowAttributes swag; // Set Window Attributes ......... Great.
    swag.colormap = xl_colormap = XCreateColormap(xl_display, xl_root, xl_visual_info->visual, AllocNone);
    swag.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask;

    xl_window = XCreateWindow(
        xl_display, xl_root,
        0, 0, N_win_size.x, N_win_size.y,
        0, xl_visual_info->depth, InputOutput, xl_visual_info->visual, CWColormap | CWEventMask, &swag);

    WM_PROTOCOLS = XInternAtom(xl_display, "WM_PROTOCOLS", False);
    WM_DELETE_WINDOW = XInternAtom(xl_display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(xl_display, xl_window, &WM_DELETE_WINDOW, 1);

    XMapWindow(xl_display, xl_window);
    XStoreName(xl_display, xl_window, N_win_title);

    {
        XSizeHints* hints = XAllocSizeHints();
        hints->flags = PMinSize | PMaxSize;
        hints->min_width = hints->max_width = N_win_size.x;
        hints->min_height = hints->max_height = N_win_size.y;
        XSetWMNormalHints(xl_display, xl_window, hints);
        XFree(hints);
    };

    glx_context = glXCreateContext(xl_display, xl_visual_info, NULL, True);
    if (!glx_context) {
        Nerror("Can't create context (GLX)");
        return false;
    }
    glXMakeCurrent(xl_display, xl_window, glx_context);
    return true;
}

bool X11_destroy_window() {
    // Destroy context
    glXMakeCurrent(xl_display, 0, 0);
    glXDestroyContext(xl_display, glx_context);

    // Destroy window
    XUnmapWindow(xl_display, xl_window);
    XDestroyWindow(xl_display, xl_window);

    // Destroy display
    XFreeColormap(xl_display, xl_colormap);
    XFree(xl_visual_info);
    XFlush(xl_display);

    return true;
}


void X11_swap_buffers() {
    glXSwapBuffers(xl_display, xl_window);
}


void X11_get_events() {
    // Nothing to see here, move along 8)
}

bool X11_next_event(NWMan_event* e) {
    if (XPending(xl_display) <= 0) {
        return false;
    }

    XEvent event;
    XNextEvent(xl_display, &event);

    int type = event.type;

    switch (type) {
        case Expose:
            e->type = N_WMAN_FOCUS;
            e->window_focus = true;

            goto end;

        case KeyPress:
        case KeyRelease:
            if (NOUTRANGE(event.xkey.keycode, 0, 255)) {
                return false;
            }

            e->type = N_WMAN_KEYBOARD;
            e->keyboard.state = type == KeyPress;
            e->keyboard.key = _keycodes[event.xkey.keycode];

            goto end;

        case ClientMessage:
            if (event.xclient.message_type == WM_PROTOCOLS) {
                if ((unsigned long) event.xclient.data.l[0] == WM_DELETE_WINDOW) {
                    e->type = N_WMAN_QUIT;
                }
            }

            goto end;
    }

    return false;

end:
    return true;
}

uint X11_get_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL); /// Replace to clock_gettime()
                              // FreeBSD: CLOCK_UPTIME_FAST or CLOCK_MONOTONIC_FAST
                              // Linux: CLOCK_MONOTONIC_RAW, then CLOCK_MONOTONIC_COARSE
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void X11_sleep(uint millis) {
    usleep(millis * 1000);
}

void NWMan_X11_init() {
#define var N_WMan_X11
    var.init = X11_init;
    var.destroy = X11_destroy;

    var.create_window = X11_create_window;
    var.destroy_window = X11_destroy_window;

    var.swap_buffers = X11_swap_buffers;

    var.get_events = X11_get_events;
    var.next_event = X11_next_event;

    var.get_millis = X11_get_millis;
    var.sleep = X11_sleep;

    var.shift_key = SHIFT_K;
    var.left_key = LEFT_K;
    var.right_key = RIGHT_K;
}
