#include "dll.h"

#include "porting.h"
#include "log.h"

#ifdef WIN32
#  include <windows.h>
#else
#  include <dlfcn.h>
#endif

NDLL* NDLL_new(char* dllpath) {
    void* handle;

#ifdef WIN32
    handle = LoadLibrary(dllpath);
#else
    handle = dlopen(dllpath, RTLD_NOW);
#endif

    if (!handle) {
        Nerror("DLL/SO %s couldn't be loaded!", dllpath);
    }

    return handle;
}

void NDLL_destroy(NDLL* dll) {
#ifdef WIN32
    FreeLibrary(dll);
#else
    dlclose(dll);
#endif
}

void* NDLL_get(NDLL* dll, char* name) {
#ifdef WIN32
    return GetProcAddress(dll, name);
#else
    return dlsym(dll, name);
#endif
}
