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

#include "W32.h"

#include <NGlobals.h>
#include <NUtil.h>
#include <NDynamic_t.h>
#include <NLog.h>
#include <wrap/gl.h>
#include <windows.h>
#include <windowsx.h>
#include <GL/wglext.h>

NWMan N_WMan_W32;

extern HINSTANCE hInstance;
HWND hWnd;
HANDLE hThread;
HGLRC hRC;
HDC hDC;
HPALETTE hPalette;
bool FAKEWINDOW;

NLIST(NWMan_event*) _w32_events;

PFNWGLCREATECONTEXTATTRIBSARBPROC _wglCreateContextAttribsARB;
PFNWGLCHOOSEPIXELFORMATARBPROC _wglChoosePixelFormatARB;
PFNWGLGETEXTENSIONSSTRINGARBPROC _wglGetExtensionsStringARB;

DWORD WINAPI _w32_msg_thread(LPVOID lpParam) {
    NUNUSED(lpParam);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}

bool _w32_setup_dc_fake() {
    PIXELFORMATDESCRIPTOR pfd =
    {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
        PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
        32,                        //Colordepth of the framebuffer.
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        0,                        //Number of bits for the depthbuffer
        8,                        //Number of bits for the stencilbuffer
        0,                        //Number of Aux buffers in the framebuffer.
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    int pixelFormat = ChoosePixelFormat(hDC, &pfd);
    if (!pixelFormat) {
        Nerror("Unable to choose pixel format!");
        return false;
    }
    if (SetPixelFormat(hDC, pixelFormat, &pfd) != TRUE) {
        Nerror("Unable to set pixel format!");
        return false;
    }
    return true;
}

bool _w32_setup_dc() {
    const int PFAL[] = {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
        WGL_SWAP_METHOD_ARB, WGL_SWAP_EXCHANGE_ARB,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_COLOR_BITS_ARB, 24,
        WGL_DEPTH_BITS_ARB, 0,
        WGL_STENCIL_BITS_ARB, 8,
        WGL_RED_BITS_ARB, 8,
        WGL_GREEN_BITS_ARB, 8,
        WGL_BLUE_BITS_ARB, 8,
        WGL_ALPHA_BITS_ARB, 8,
        WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB, GL_TRUE,
        WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
        0
    };

    int pixelformat[1];
    uint numformats;
    PIXELFORMATDESCRIPTOR pfd;
    if (!_wglChoosePixelFormatARB(hDC, PFAL, NULL, 1, pixelformat, &numformats)) {
        Nerror("Unable to choose pixel format!");
        return false;
    }
    if (!SetPixelFormat(hDC, pixelformat[0], &pfd)) {
        Nerror("Unable to set pixel format!");
        return false;
    }
    return true;
}

void _w32_add_event(NWMan_event event) {
    NWMan_event* ep = malloc(sizeof(NWMan_event));
    *ep = event;
    NLIST_PUSH(_w32_events, ep);
}

bool keyspressed[256];

LRESULT APIENTRY WndProc(HWND hWndf, UINT message, WPARAM wParam, LPARAM lParam) {
    if (FAKEWINDOW) {
        return DefWindowProc(hWndf, message, wParam, lParam);
    }
    NWMan_event e;
    bool event = true;
    ushort key;
    switch(message) {
        case WM_DESTROY:
            if (!FAKEWINDOW) {
                wglMakeCurrent(hDC, NULL);
                wglDeleteContext(hRC);
                ReleaseDC(hWndf, hDC);
                e = NWMan_event_new(N_WMAN_QUIT);
                //event = false;
                if (message == WM_DESTROY) {
                    PostQuitMessage(0);
                }
            }
            break;
        case WM_PAINT:
            e = NWMan_event_new(N_WMAN_FOCUS);
            break;
        case WM_KEYDOWN:
        case WM_KEYUP:
            e = NWMan_event_new(N_WMAN_KEYBOARD);
            key = wParam;
            /*if (key == VK_SHIFT) {
                Ndebug("SHIIIIFT! %i %i", message == WM_KEYDOWN, e.type);
                //key = VK_LSHIFT;
            }*/
            e.keyboard.key = key;
            e.keyboard.state = message == WM_KEYDOWN;
            //keyspressed[key] = e.keyboard.state;
            break;
        case WM_MOUSEMOVE:
            e = NWMan_event_new(N_WMAN_MOUSE_MOVE);
            e.mouse_pos = Npos2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            break;
        case WM_MOUSEWHEEL:
            e = NWMan_event_new(N_WMAN_MOUSE_WHEEL);
            if (GET_WHEEL_DELTA_WPARAM(wParam) > 0) {
                e.mouse_wheel = 1;
            } else {
                e.mouse_wheel = -1;
            }
            break;
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MBUTTONUP:
            e = NWMan_event_new(N_WMAN_MOUSE_BUTTON);
            e.mouse_button.state = (message-513)%3;
            e.mouse_button.id = (message-513)/3;
            break;
        default:
            event = false;
            break;
    }
    if (event && !FAKEWINDOW) {
        _w32_add_event(e);
    }
    return DefWindowProc(hWndf, message, wParam, lParam);
}

bool w32_init() {
    WNDCLASSEX wcex;
    ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = NULL;
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = "nightmaregame";
    wcex.hIconSm        = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex)) {
        Nerror("Couldn't register window class!");
        return false;
    }

    NLIST_INIT(NWMan_event, _w32_events);

    return true;
}

bool w32_destroy() {
    if (!TerminateThread(hThread, 0)) {
        return false;
    }
    return true;
}

void _w32_create_window_ex() {
    hWnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        "nightmaregame",
        N_win_title,
        /*WS_OVERLAPPED | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU |
                WS_CLIPCHILDREN | WS_CLIPSIBLINGS,*/
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        N_win_size.x, N_win_size.y,
        NULL,
        NULL,
        hInstance,
        NULL
    );
}

// Copied from GLFW
int _glfwStringInExtensionString(const char* string, const GLubyte* extensions)
{
    const GLubyte* start;
    GLubyte* where;
    GLubyte* terminator;

    start = extensions;
    for (;;)
    {
        where = (GLubyte*) strstr((const char*) start, string);
        if (!where)
            return GL_FALSE;

        terminator = where + strlen(string);
        if (where == start || *(where - 1) == ' ')
        {
            if (*terminator == ' ' || *terminator == '\0')
                break;
        }

        start = terminator;
    }

    return GL_TRUE;
}

bool _w32_check_extension(char* str) {
#if 0
    int num_extensions;
    glGetIntegerv(GL_NUM_EXTENSIONS, &num_extensions);
    Ndebug("%i", num_extensions);
    for (int i = 0; i < num_extensions; i++) {
        if (NSTREQ((char*)glGetStringi(GL_EXTENSIONS, i), str)) {
            return true;
        }
    }
#else
    return _glfwStringInExtensionString(str, (GLubyte*)_wglGetExtensionsStringARB(hDC));
#endif
    return false;
}

bool w32_create_window() {
    //FAKEWINDOW = true;
    FAKEWINDOW = false;
    // Create the fake window
    _w32_create_window_ex();

    if (!hWnd) {
        return false;
    }

    hDC = GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,                     /* version */
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |
        PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,                    /* 32-bit color depth */
        0, 0, 0, 0, 0, 0,      /* color bits */
        0,                     /* alpha buffer */
        0,                     /* shift bit */
        0,                     /* accumulation buffer */
        0, 0, 0, 0,            /* accum bits */
        0,                     /* z-buffer */
        8,                     /* stencil buffer */
        0,                     /* auxiliary buffer */
        PFD_MAIN_PLANE,        /* main layer */
        0,                     /* reserved */
        0, 0, 0                /* layer masks */
    };

    int pixelFormat = ChoosePixelFormat(hDC, &pfd);
    if (!pixelFormat) {
        Nerror("Unable to choose fake pixel format!");
        return false;
    }
    if (!SetPixelFormat(hDC, pixelFormat, &pfd)) {
        Nerror("Unable to set fake pixel format!");
        return false;
    }
    HGLRC hRC_t = wglCreateContext(hDC);
    if (!hRC_t) {
        Nerror("Couldn't create temp context!");
        return false;
    }
    if (!wglMakeCurrent(hDC, hRC_t)) {
        Nerror("Couldn't activate temp context!");
        return false;
    }

    Ndebug("Created fake window");

    // Get the stuff we need
    _wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) wglGetProcAddress("wglGetExtensionsStringARB");
    if (!_wglGetExtensionsStringARB || !_w32_check_extension("WGL_ARB_create_context") || !_w32_check_extension("WGL_ARB_pixel_format")) {
        Nerror("Extensions are missing!");
        return false;
    }
    _wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC) wglGetProcAddress("wglCreateContextAttribsARB");
    _wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) wglGetProcAddress("wglChoosePixelFormatARB");

    if (!_wglCreateContextAttribsARB || !_wglChoosePixelFormatARB) {
        Nerror("Couldn't load needed functions!");
        return false;
    }

    int attribs[] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
        WGL_CONTEXT_MINOR_VERSION_ARB, 0,
        0
    };

    hRC = _wglCreateContextAttribsARB(hDC, 0, attribs);

    wglMakeCurrent(NULL, NULL);

    /*wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC_t);
    ReleaseDC(hWnd, hDC);
    DestroyWindow(hWnd);
    FAKEWINDOW = false;


    _w32_create_window_ex();

    if (!hWnd) {
        Nerror("Couldn't re-create window");
        return false;
    }

    hDC = GetDC(hWnd);
    if (!hDC) {
        Nerror("Can't re-initialize DC");
        return false;
    }
        const int PFAL[] =
      {
         WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
         WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
         WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
         WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
         WGL_COLOR_BITS_ARB, 32,
         WGL_DEPTH_BITS_ARB, 24,
         WGL_STENCIL_BITS_ARB, 8,
         0 // End of attributes list
      };
    uint numformats;
    if (!_wglChoosePixelFormatARB(hDC, PFAL, NULL, 1, &pixelFormat, &numformats)) {
        Nerror("Unable to choose pixel format!");
        return false;
    }
    if (!SetPixelFormat(hDC, pixelFormat, &pfd)) {
        Nerror("Unable to set pixel format!");
        return false;
    }

    const int CA[] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
        WGL_CONTEXT_MINOR_VERSION_ARB, 2,
        //WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
       // WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        //WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
        0
    };

    hRC = _wglCreateContextAttribsARB(hDC, 0, CA);
    if (!hRC) {
        Nerror("Failed to create context!");
    }

    /*wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRCfake);*/
    if (!wglMakeCurrent(hDC, hRC)) {
        Nerror("Failed to activate real context!");
        return false;
    }

    ShowWindow(hWnd, SW_SHOW);
    /*SetForegroundWindow(hWnd);
    SetFocus(hWnd);*/
    UpdateWindow(hWnd);
    return true;
}

bool w32_destroy_window() {
    return DestroyWindow(hWnd);
}

void w32_swap_buffers() {
    SwapBuffers(hDC);
}

void w32_get_events() {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    const int lshiftDown = (GetAsyncKeyState(VK_LSHIFT) >> 15) & 1;
    const int rshiftDown = (GetAsyncKeyState(VK_RSHIFT) >> 15) & 1;

    if (!lshiftDown && keyspressed[VK_LSHIFT]) {
        NWMan_event e = NWMan_event_new(N_WMAN_KEYBOARD);
        e.keyboard.key = VK_LSHIFT;
        e.keyboard.state = false;
        _w32_add_event(e);
    }

    if (!rshiftDown && keyspressed[VK_RSHIFT]) {
        NWMan_event e = NWMan_event_new(N_WMAN_KEYBOARD);
        e.keyboard.key = VK_RSHIFT;
        e.keyboard.state = false;
        _w32_add_event(e);
    }
}

bool w32_next_event(NWMan_event* event) {
    if (_w32_events.size == 0) {
        return false;
    }
    *event = *(_w32_events.data[0]);
    free(_w32_events.data[0]);
    NLIST_REMOVE(_w32_events, 0);
    return true;
}

uint w32_get_millis() {
    return GetTickCount();
}

void w32_sleep(uint millis) {
    Sleep(millis);
}

void NWMan_W32_init() {
#define var N_WMan_W32
    var.init = w32_init;
    var.destroy = w32_destroy;

    var.create_window = w32_create_window;
    var.destroy_window = w32_destroy_window;

    var.swap_buffers = w32_swap_buffers;

    var.get_events = w32_get_events;
    var.next_event = w32_next_event;

    var.get_millis = w32_get_millis;
    var.sleep = w32_sleep;

    var.shift_key = VK_SHIFT;
    var.left_key = VK_LEFT;
    var.right_key = VK_RIGHT;
}
