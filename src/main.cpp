#include "globals.h"
#include "log.h"
#include "wm.h"

int main(int argc, char** argv) {
    int ret = 0;

    // Load
    debug("Initializing global variables");
    globals_init();

    debug("Initializing window manager");
    wm_init(argc, argv);

    debug("Creating window");
    wm.create_window();

    // End
    debug("Destroying window");
    wm.destroy_window();

    debug("Destroying window manager");
    wm_destroy();

    debug("Destroying global variables");
    globals_destroy();

    return ret;
}
