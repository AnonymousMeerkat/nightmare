#ifndef _SP_WM_H
#define _SP_WM_H

// Window manager API

#include "compat.h"
#include "pos.h"
#include "yasl/yutil.h"
#include "types.h"

START_HEAD

typedef struct wm_event wm_event;

typedef struct {
    // Init stuff
    bool (*init)();
    bool (*destroy)();

    // Window stuff
    bool (*create_window)();
    bool (*destroy_window)();

    void (*swap_buffers)();

    // Event stuff
    bool (*next_event)(wm_event* event);

    // Time stuff
    uint (*get_millis)();
    void (*sleep)(uint millis);
} wm_s;

enum wm_event_type {
    WM_MOUSE_MOVE = 0,
    WM_MOUSE_BUTTON = 1,
    WM_MOUSE_WHEEL = 2,

    WM_KEYBOARD = 10,

    WM_QUIT = 20,
    WM_RESIZE = 21,
    WM_FOCUS = 22
};

#define WM_MOUSE_LEFT 0
#define WM_MOUSE_RIGHT 1
#define WM_MOUSE_MIDDLE 2

struct wm_event {
    enum wm_event_type type;

    union {
        // Mouse

        Pos2i mouse_pos;

        struct {
            short id;
            bool state;
        } mouse_button;

        signed char mouse_wheel; // 1 if up, -1 if down

        // Keyboard

        struct {
            uchar key;
            bool state;
        } keyboard;

        // Window

        bool window_quit; // Will always be true if WM_QUIT

        Pos2i window_size;

        bool window_focus;
    };
};

wm_event wm_event_new(enum wm_event_type type);


bool wm_init();
bool wm_destroy();

extern wm_s wm;

END_HEAD

#endif
