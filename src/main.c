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

#include "NGlobals.h"
#include "NLog.h"
#include "NWMan.h"
#include "wrap/gl.h"
#include "NRsc.h"
#include "NEngine.h"
#include "NPorting.h"

int main(int argc, char** argv) {
    int ret = 0;

    bool okay;

    N_argc = argc;
    N_argv = argv;

    // Load
    Ndebug("Initializing global variables");
    NGlobals_init();

    Ndebug("Initializing window manager");
    NINDENT(okay = NWMan_init(argc, argv));

    if (!okay) {
        Nerror("Error initializing window manager!");
    }

    Ndebug("Creating window");
    NINDENT(okay = N_WMan.create_window());

    if (!okay) {
        Nerror("Error creating window!");
        return 1;
    }

    Ndebug("Initializing OpenGL");
    if (gl3wInit()) {
        Nerror("Error initializing OpenGL!");
        return 1;
    }

    if (!gl3wIsSupported(3, 0)) {
        Nerror("OpenGL 3.0 not supported!");
        return 1;
    }

    Ndebug("Initializing paths");
    NINDENT(okay = NRsc_init());

    /*if (!okay) {
        return;
    }*/

    Ndebug("Loading engine");
    NINDENT(okay = NEngine_init());

    if (!okay) {
        Nerror("Error loading engine!");
    }

    // Game
    Nnewline();
    NEngine_run();

    // End
    Ndebug("Destroying engine");
    NEngine_destroy();

    Ndebug("Destroying paths");
    NINDENT(NRsc_destroy());

    Ndebug("Destroying window");
    NINDENT(N_WMan.destroy_window());

    Ndebug("Destroying window manager");
    NWMan_destroy();

    Ndebug("Destroying global variables");
    NGlobals_destroy();

    return ret;
}
