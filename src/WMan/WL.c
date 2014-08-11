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
#include "../NLog.h"

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

#include <libinput.h>

#include <GLES2/gl2.h>
#include <EGL/egl.h>


NWMan N_WMan_WL;

// Most of this is based off of weston-simple-egl

struct display {
    struct wl_display* display;
    struct wl_registry* registry;
    struct wl_shell* shell;
    struct wl_compositor* compositor;
};

struct egl {
    EGLDisplay display;
    EGLContext context;
    EGLConfig config;
};

struct window {
    struct wl_egl_window* native;
    struct wl_surface* surface;
    struct wl_shell_surface* shell_surface;
    EGLSurface egl_surface;
    bool opaque;
    int buffer_size;
};

struct input {
    struct udev* udev;
    struct libinput* li;
};

struct display display;
struct egl egl;
struct window window;
struct input input;

static void _WLregistry_handle(void* data, struct  wl_registry* registry, uint32_t name, const char* interface, uint32_t version) {
    NUNUSED(data);
    NUNUSED(version);
    /*if (NSTREQ(interface, "xdg_shell")) {
        display.xdg_shell = wl_registry_bind(registry, name, &_WL_xdg_shell_interface, 1);
        xdg_shell_add_listener(display.xdg_shell, &_WL_xdg_shell_listener, NULL);
    }*/
    if (NSTREQ(interface, "wl_compositor")) {
        display.compositor = wl_registry_bind(registry, name, &wl_compositor_interface, 1);
    }
}

static void _WLregistry_handle_remove(void* data, struct wl_registry* registry, uint32_t name) {
    NUNUSED(data);
    NUNUSED(registry);
    NUNUSED(name);
}

static const struct wl_registry_listener _WL_registry_listener = {
    _WLregistry_handle,
    _WLregistry_handle_remove
};

static int _WL_open_restricted(const char* path, int flags, void* data) {
    NUNUSED(data);

    int fd = open(path, flags);
    return fd < 0 ? -errno : fd;
}

static void _WL_close_restricted(int fd, void* data) {
    NUNUSED(data);

    close(fd);
}

static const struct libinput_interface _WL_input_interface = {
    .open_restricted = _WL_open_restricted,
    .close_restricted = _WL_close_restricted
};

bool WL_init() {
    // Initialize wayland
    display.display = wl_display_connect(NULL);

    if (!display.display) {
        Nerror("Can't connect to display (WL)");
        return false;
    }

    display.registry = wl_display_get_registry(display.display);
    wl_registry_add_listener(display.registry, &_WL_registry_listener, NULL);

    wl_display_dispatch(display.display);

    // Initialize input
    input.udev = udev_new();
    if (!input.udev) {
        Nerror("Failed to initialize udev");
        return false;
    }

    input.li = libinput_udev_create_context(&_WL_input_interface, NULL, input.udev);
    if (!input.li || libinput_udev_assign_seat(input.li, "seat0")) {
        Nerror("Failed to initialize libinput context from udev");
        return false;
    }

    return true;
}

bool WL_destroy() {
    libinput_unref(input.li);
    udev_unref(input.udev);

    wl_registry_destroy(display.registry);
    wl_display_flush(display.display);
    wl_display_disconnect(display.display);

    return true;
}


static void _WLshell_surface_ping(void* data, struct wl_shell_surface* shell_surface, unsigned int serial) {
    if (!shell_surface) {
        return;
    }

    wl_shell_surface_pong(shell_surface, serial);
}

static void _WLshell_surface_configure(void* data, struct wl_shell_surface* shell_surface, unsigned int edges, int w, int h) {
    return;
}

static void _WLshell_surface_popup_done(void* data, struct wl_shell_surface* shell_surface) {
    return;
}

static const struct wl_shell_surface_listener _WL_shell_surface_listener = {
    _WLshell_surface_ping,
    _WLshell_surface_configure,
    _WLshell_surface_popup_done
};

bool WL_create_window() {
    Ndebug("Initializing EGL");
    static const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    const char* extensions;

    EGLint renderable_type = EGL_OPENGL_ES2_BIT;
    if (window.opaque || window.buffer_size == 16) {
        renderable_type = 0;
    }

    EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RED_SIZE, 1,
        EGL_GREEN_SIZE, 1,
        EGL_BLUE_SIZE, 1,
        EGL_RENDERABLE_TYPE, renderable_type,
        EGL_NONE
    };

    EGLint major, minor;
    EGLConfig* configs;

    egl.display = eglGetDisplay(display.display);
    if (!egl.display) {
        Nerror("Can't connect to display (EGL)");
        return false;
    }

    if (!eglInitialize(egl.display, &major, &minor)) {
        Nerror("Failed to initialize EGL");
        return false;
    }

    if (!eglBindAPI(EGL_OPENGL_ES_API)) {
        Nerror("Failed to bind OpenGL ES");
        return false;
    }

    EGLint count;
    if (!eglGetConfigs(egl.display, NULL, 0, &count) || count < 1) {
        Nerror("Failed to acquire EGL configurations (test)");
        return false;
    }

    configs = malloc(sizeof(EGLConfig) * count);

    EGLint n;
    if (!eglChooseConfig(egl.display, config_attribs, configs, count, &n) || n < 1) {
        Nerror("Failed to acquire EGL configurations (real)");
        return false;
    }

    for (EGLint i = 0; i < n; i++) {
        EGLint buffer_size;
        eglGetConfigAttrib(egl.display, configs[i], EGL_BUFFER_SIZE, &buffer_size);
        if (buffer_size == 32) {
            egl.config = configs[i];
            break;
        }
    }

    free(configs);

    if (egl.config == NULL) {
        Nerror("Failed to choose EGL configuration");
        return false;
    }


    egl.context = eglCreateContext(egl.display, egl.config, EGL_NO_CONTEXT, context_attribs);
    if (!egl.context) {
        Nerror("Failed to create EGL context");
        return false;
    }


    Ndebug("Creating window");

    window.surface = wl_compositor_create_surface(display.compositor);
    window.shell_surface = wl_shell_get_shell_surface(display.shell, window.surface);
    wl_shell_surface_add_listener(window.shell_surface, &_WL_shell_surface_listener, NULL);
    window.native = wl_egl_window_create(window.surface, N_win_size.x, N_win_size.y);
    window.egl_surface = eglCreateWindowSurface(egl.display, egl.config, window.native, NULL);

    wl_shell_surface_set_title(window.shell_surface, N_win_title);

    if (!eglMakeCurrent(egl.display, window.egl_surface, window.egl_surface, egl.context)) {
        Nerror("Failed to make EGL context current");
        return false;
    }

    eglSwapInterval(egl.display, 0);

    return true;
}

bool WL_destroy_window() {
    eglMakeCurrent(egl.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(egl.display, window.egl_surface);

    wl_egl_window_destroy(window.native);

    wl_shell_surface_destroy(window.shell_surface);
    wl_surface_destroy(window.surface);

    eglTerminate(egl.display);
    eglReleaseThread();

    return true;
}


void  WL_swap_buffers() {
    eglSwapBuffers(egl.display, window.egl_surface);
}


void WL_get_events() {
    // Don't y'love OSS and their lack of needing to manually fetch events? 8)
}

bool WL_next_event(NWMan_event* e) {
    struct libinput_event* ev;
    enum libinput_event_type ev_type;
    bool ret = true;

    libinput_dispatch(input.li);

    ev = libinput_get_event(input.li);
    if (!ev) {
        return false;
    }

    ev_type = libinput_event_get_type(ev);

    if (ev_type == LIBINPUT_EVENT_NONE) {
        ret = false;
        goto end;
    }


    switch (libinput_event_get_type(ev)) {
        case LIBINPUT_EVENT_KEYBOARD_KEY: {
            struct libinput_event_keyboard* k = libinput_event_get_keyboard_event(ev);

            e->type = N_WMAN_KEYBOARD;
            e->keyboard.state = libinput_event_keyboard_get_key_state(k) == LIBINPUT_KEY_STATE_PRESSED;
            e->keyboard.key = libinput_event_keyboard_get_key(k);

            goto end;
        default:
            ret = false;
            goto end;
        }
    }

end:
    libinput_event_destroy(ev);
    return ret;
}


uint WL_get_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void WL_sleep(uint millis) {
    usleep(millis * 1000);
}


void NWMan_WL_init() {
#define var N_WMan_WL
    var.init = WL_init;
    var.destroy = WL_destroy;

    var.create_window = WL_create_window;
    var.destroy_window = WL_destroy_window;

    var.swap_buffers = WL_swap_buffers;

    var.get_events = WL_get_events;
    var.next_event = WL_next_event;

    var.get_millis = WL_get_millis;
    var.sleep = WL_sleep;

    /*var.shift_key = SHIFT_K;
    var.left_key = LEFT_K;
    var.right_key = RIGHT_K;*/
}
