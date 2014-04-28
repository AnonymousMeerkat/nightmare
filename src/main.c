#include "globals.h"
#include "log.h"
#include "wm.h"
#include "game.h"

int main(int argc, char** argv) {
    int ret = 0;

    bool okay;

    // Load
    debug("Initializing global variables");
    globals_init();

    debug("Initializing window manager");
    indent(debug, okay = wm_init(argc, argv));

    if (!okay) {
        error("Error initializing window manager!");
    }

    debug("Creating window");
    indent(debug, okay = wm.create_window());

    if (!okay) {
        error("Error creating window!");
    }

    debug("Loading game");
    indent(debug, okay = game_load());

    if (!okay) {
        error("Error loading game!");
    }

    // Game
    newline();
    game_run();

    // End
    debug("Destroying window");
    indent(debug, wm.destroy_window());

    debug("Destroying window manager");
    wm_destroy();

    debug("Destroying global variables");
    globals_destroy();

    return ret;
}
