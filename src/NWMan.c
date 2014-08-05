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

#include "NLog.h"

NWMan N_WMan;

NWMan_event NWMan_event_new(NWMan_event_type type) {
    NWMan_event event;
    event.type = type;

    return event;
}


bool NWMan_init() {
#if defined(X11_FOUND)
        Ndebug("WM Backend = X11");
        NWMan_X11_init();
        N_WMan = N_WMan_X11;
#elif defined(WIN32)
        Ndebug("WM Backend = W32");
        NWMan_W32_init();
        N_WMan = N_WMan_W32;
#elif defined(SDL_FOUND)
        Ndebug("WM Backend = SDL");
        NWMan_SDL_init();
        N_WMan = N_WMan_SDL;
#elif defined(SDL2_FOUND)
        Ndebug("WM Backend = SDL2");
        NWMan_SDL2_init();
        N_WMan = N_WMan_SDL2;
#else
        Nerror("No backend available!!");
        return false;
#endif
    return N_WMan.init();
}

bool NWMan_destroy() {
    return N_WMan.destroy();
}
