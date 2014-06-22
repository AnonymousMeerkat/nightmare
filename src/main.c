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
