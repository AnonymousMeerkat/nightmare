#ifndef _NME_DLL_H
#define _NME_DLL_H

#include "compat.h"

START_HEAD

#include "util.h"
#include "types.h"
#include "porting.h"

#ifdef WIN32
#  define N_DLL_EXT "dll"
#else
#  define N_DLL_EXT "so"
#endif

#define NDLL_ADD_EXT(filename) filename "." N_DLL_EXT

typedef void* NDLL;

NTS(NShader);
NTS(NImage);
NTS(NSpritesheet);

NSTRUCT(NDLL_info, {
    uint delta;
    bool* key_states;
    NShader** shaders;
    NImage** images;
    NSpritesheet** spritesheets;
});

NDLL* NDLL_new(char* dllpath);
void NDLL_destroy(NDLL* dll);

void* NDLL_get(NDLL* dll, char* function);

END_HEAD

#endif
