#include "globals.h"
#include "log.h"

int main(int argc, char** argv) {
    int ret = 0;

    // Load
    debug("Initializing global variables");
    globals_init();

    // End
    debug("Destroying global variables");
    globals_destroy();

    return ret;
}
