#include "globals.h"

void globals_init() {
    win_x = 0;
    win_y = 0;
    win_width = 800;
    win_height = 600;
    win_title = "Silent Ponyville";

    info_indent = 0;
    debug_indent = 0;
    error_indent = 0;

    running = true;
    delta = 0;
    lasttime = 0;
    currtime = 0;
    lastsecond = 0;
    fps = 0;
}

void globals_destroy() {
    // Wheeeeee!
    return; // Useless
}
