#ifndef _NME_WMAN_H
#define _NME_WMAN_H

// Internal window manager API

#include "NCompat.h"

START_HEAD

#include "NPos.h"
#include "NUtil.h"
#include "NTypes.h"

NTS(NWMan_event);

NSTRUCT(NWMan, {
    // Init stuff
    bool (*init)();
    bool (*destroy)();

    // Window stuff
    bool (*create_window)();
    bool (*destroy_window)();

    void (*swap_buffers)();

    // Event stuff
    void (*get_events)();
    bool (*next_event)(NWMan_event* event);

    // Time stuff
    uint (*get_millis)();
    void (*sleep)(uint millis);

    // Info
    int shift_key;
    int left_key;
    int right_key;
});

NENUM(NWMan_event_type, {
    N_WMAN_MOUSE_MOVE = 0,
    N_WMAN_MOUSE_BUTTON = 1,
    N_WMAN_MOUSE_WHEEL = 2,

    N_WMAN_KEYBOARD = 10,

    N_WMAN_QUIT = 20,
    N_WMAN_FOCUS = 21
});

#define N_WMAN_MOUSE_LEFT 0
#define N_WMAN_MOUSE_RIGHT 1
#define N_WMAN_MOUSE_MIDDLE 2

NSTRUCT(NWMan_event, {
    NWMan_event_type type;

    union {
        // Mouse

        NPos2i mouse_pos;

        struct {
            short id;
            bool state;
        } mouse_button;

        signed char mouse_wheel; // 1 if up, -1 if down

        // Keyboard

        struct {
            short key;
            bool state;
        } keyboard;

        // Window

        bool window_focus;
    };
});

NWMan_event NWMan_event_new(NWMan_event_type type);


bool NWMan_init();
bool NWMan_destroy();

extern NWMan N_WMan;

END_HEAD

#endif
