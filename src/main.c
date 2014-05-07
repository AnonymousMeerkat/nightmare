#include "globals.h"
#include "log.h"
#include "wm.h"
#include "wrap/gl.h"
#include "resource.h"
#include "game.h"

int main(int argc, char** argv) {
    int ret = 0;

    bool okay;

    // Load
    debug("Initializing global variables");
    globals_init();

    debug("Initializing window manager");
    indent(okay = wm_init(argc, argv));

    if (!okay) {
        error("Error initializing window manager!");
    }

    debug("Creating window");
    indent(okay = wm.create_window());

    if (!okay) {
        error("Error creating window!");
    }

    debug("Initializing GLEW");
    if (glewInit() != GLEW_OK) {
        error("Error initializing GLEW!");
    }

    debug("Initializing paths");
    indent(okay = rsc_init());

    /*if (!okay) {
        return;
    }*/

    debug("Loading game");
    indent(okay = game_load());

    if (!okay) {
        error("Error loading game!");
    }

    // Game
    newline();
    game_run();

    // End
    debug("Destroying paths");
    indent(rsc_destroy());

    debug("Destroying window");
    indent(wm.destroy_window());

    debug("Destroying window manager");
    wm_destroy();

    debug("Destroying global variables");
    globals_destroy();

    return ret;
}
