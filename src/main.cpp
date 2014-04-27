#include "globals.h"
#include "log.h"
#include "wm.h"

int main(int argc, char** argv) {
    int ret = 0;

    bool okay;

    // Load
    debug("Initializing global variables");
    globals_init();

    debug("Initializing window manager");
    debug_indent++;
    okay = wm_init(argc, argv);
    debug_indent--;

    if (!okay) {
        error("Error initializing window manager!");
    }

    debug("Creating window");
    debug_indent++;
    okay = wm.create_window();
    debug_indent--;

    if (!okay) {
        error("Error creating window!");
    }

    // Game
    newline();

    // End
    debug("Destroying window");
    debug_indent++;
    wm.destroy_window();
    debug_indent--;

    debug("Destroying window manager");
    wm_destroy();

    debug("Destroying global variables");
    globals_destroy();

    return ret;
}
