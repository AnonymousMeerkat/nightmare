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

#include "NWMan.h"

#include "WMan/SDL.h"
#include "WMan/SDL2.h"
#include "WMan/W32.h"
#include "WMan/X11.h"
#include "WMan/WL.h"

#include "NLog.h"
#include <NDynamic_t.h>

NWMan N_WMan;

NWMan_event NWMan_event_new(NWMan_event_type type) {
    NWMan_event event;
    event.type = type;

    return event;
}


struct NWMan_backend {
    char* name;
    bool pickme;
    bool egl;
    NWMan* wman;
};

bool NWMan_init() {
    bool ret = false;
    NLIST_NEW(struct NWMan_backend, backends);

#ifdef WL_FOUND
    struct NWMan_backend wl_backend = {"Wayland", NSTRIEQ(N_WMan_backend, "wayland"), true, &N_WMan_WL};
    NLIST_PUSH(backends, wl_backend);
#endif
#ifdef X11_FOUND
    struct NWMan_backend x11_backend = {"X11", NSTRIEQ(N_WMan_backend, "x11"), false, &N_WMan_X11};
    NLIST_PUSH(backends, x11_backend;);
#endif
#ifdef WIN32
    struct NWMan_backend w32_backend = {"Windows", NSTRIEQ(N_WMan_backend, "w32") ||
                          NSTRIEQ(N_WMan_backend, "windows"), false, &N_WMan_W32};
    NLIST_PUSH(backends, w32_backend);
#endif

    bool has_preference = (N_WMan_backend[0] != 0);

    for (size_t i = 0; i < backends.size; i++) {
        struct NWMan_backend backend = backends.data[i];

        bool pickme = true;
        bool returnme = false;

        if (has_preference) {
            pickme = backend.pickme;
            returnme = true;
        }

        if (pickme) {
            Ndebug("Trying %s", backend.name);
            bool okay;
            NINDENT(okay = backend.wman->init());
            if (okay) {
                Ndebug("WM Backend = %s", backend.name);
                N_WMan = *backend.wman;
                N_shader_egl = backend.egl;
                ret = true;
                goto end;
            } else if (returnme) {
                ret = false;
                goto end;
            }
        }
    }

    Nerror("No backend available!");

end:
    NLIST_DESTROY(backends);
    return ret;
}

bool NWMan_destroy() {
    return N_WMan.destroy();
}
