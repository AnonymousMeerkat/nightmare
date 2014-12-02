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

#include <NLog.h>
#include "common.h"

#include <stdlib.h>

extern const struct xdg_surface_listener _WL_xdg_surface_listener;

static bool _WL_create_egl_context() {
    Ndebug("Initializing EGL");

    static const EGLint context_attribs[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };

    EGLint renderable_type = EGL_OPENGL_ES2_BIT;

    EGLint config_attribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RED_SIZE, 1,
        EGL_GREEN_SIZE, 1,
        EGL_BLUE_SIZE, 1,
        EGL_ALPHA_SIZE, 1,
        EGL_RENDERABLE_TYPE, renderable_type,
        EGL_NONE
    };

    EGLint major, minor;
    EGLConfig* configs;

    _WL_display.egl.display = eglGetDisplay(_WL_display.display);
    if (!_WL_display.egl.display) {
        Nerror("Can't connect to display (EGL)");
        return false;
    }

    if (!eglInitialize(_WL_display.egl.display, &major, &minor)) {
        Nerror("Failed to initialize EGL");
        return false;
    }

    Ndebug("EGL version %i.%i", major, minor);

    if (!eglBindAPI(EGL_OPENGL_ES_API)) {
        Nerror("Failed to bind OpenGL ES");
        return false;
    }

    EGLint count;
    if (!eglGetConfigs(_WL_display.egl.display, NULL, 0, &count) || count < 1) {
        Nerror("Failed to acquire EGL configurations (test)");
        return false;
    }

    // Calloc 'cuz zeroing
    configs = calloc(sizeof(EGLConfig), count);

    EGLint n;
    if (!eglChooseConfig(_WL_display.egl.display, config_attribs, configs, count, &n) || n < 1) {
        Nerror("Failed to acquire EGL configurations (real)");
        return false;
    }

    for (EGLint i = 0; i < n; i++) {
        EGLint buffer_size;
        eglGetConfigAttrib(_WL_display.egl.display, configs[i], EGL_BUFFER_SIZE, &buffer_size);
        if (buffer_size == 32) {
            _WL_display.egl.config = configs[i];
            break;
        }
    }

    free(configs);

    if (_WL_display.egl.config == NULL) {
        Nerror("Failed to choose EGL configuration");
        return false;
    }


    _WL_display.egl.context = eglCreateContext(_WL_display.egl.display, _WL_display.egl.config, EGL_NO_CONTEXT, context_attribs);
    if (!_WL_display.egl.context) {
        Nerror("Failed to create EGL context");
        return false;
    }

    return true;
}



bool WL_create_window() {
    if (!_WL_create_egl_context()) {
        return false;
    }

    Ndebug("Creating window");

    _WL_display.window.surface = wl_compositor_create_surface(_WL_display.compositor);
    _WL_display.window.xdg_surface = xdg_shell_get_xdg_surface(_WL_display.shell, _WL_display.window.surface);
    xdg_surface_add_listener(_WL_display.window.xdg_surface, &_WL_xdg_surface_listener, NULL);
    _WL_display.window.native = wl_egl_window_create(_WL_display.window.surface, N_win_size.x, N_win_size.y);
    _WL_display.window.egl_surface = eglCreateWindowSurface(_WL_display.egl.display, _WL_display.egl.config, _WL_display.window.native, NULL);

    //wl_shell_surface_set_title(_WL_display.window.xdg_surface, N_win_title);

    if (!eglMakeCurrent(_WL_display.egl.display, _WL_display.window.egl_surface, _WL_display.window.egl_surface, _WL_display.egl.context)) {
        Nerror("Failed to make EGL context current");
        return false;
    }

    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    eglSwapBuffers(_WL_display.egl.display, _WL_display.window.egl_surface);

    eglSwapInterval(_WL_display.egl.display, 1);

    wl_display_dispatch(_WL_display.display);

    return true;
}

bool WL_destroy_window() {
    eglMakeCurrent(_WL_display.egl.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroySurface(_WL_display.egl.display, _WL_display.window.egl_surface);

    wl_egl_window_destroy(_WL_display.window.native);

    xdg_surface_destroy(_WL_display.window.xdg_surface);
    wl_surface_destroy(_WL_display.window.surface);

    eglTerminate(_WL_display.egl.display);
    eglReleaseThread();

    return true;
}


void WL_swap_buffers() {
    wl_surface_set_opaque_region(_WL_display.window.surface, NULL);
    eglSwapBuffers(_WL_display.egl.display, _WL_display.window.egl_surface);
}
