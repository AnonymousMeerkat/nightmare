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

#ifndef _NME_NGL_H
#define _NME_NGL_H

/**
 * @file
 *
 * @ingroup NGL
 *
 * @brief NGL API
 *
 * Nightmare Engine Graphics Library
 */

#include "NUtil.h"
#include "NTypes.h"

typedef void NGL_void;
typedef int NGL_int;
typedef unsigned int NGL_uint;
typedef float NGL_float;
typedef signed char NGL_char;
typedef unsigned char NGL_uchar;
typedef unsigned int NGL_object;

NTE(NGL_enum);

NSTRUCT(NGL, {
    void (*init)();
    void (*destroy)();

    void (*set)(NGL_enum name, void* value);
    void* (*get)(NGL_enum name);

    NGL_object (*create)(NGL_enum type);
    void (*delete)(NGL_enum type, NGL_object object);

    void (*draw)(void);

    void (*compile)(void);
    void (*link)(void);

    /**
     * @brief Dispatches all changes to the backend.
     */
    void (*dispatch)(void);
});

#endif

#define NGL_SET(x, y) NGL.set(x, (typeof(y)[]){y})

#define NGL_PARAM(c, t, n) N_GL_##n // for ngloptbuilder

NENUM(NGL_enum, {
#pragma NGL_READONLY

    NGL_PARAM(NULL, NGL_char*, INFO_STRING),

    NGL_PARAM(NULL, NGL_float, VERSION),
    NGL_PARAM(NULL, NGL_int, VERSION_MAJOR),
    NGL_PARAM(NULL, NGL_int, VERSION_MINOR),

    NGL_PARAM(NULL, NGL_char*, BACKEND),

    NGL_PARAM(NULL, NGL_float, BACKEND_VERSION),
    NGL_PARAM(NULL, NGL_int, BACKEND_VERSION_MAJOR),
    NGL_PARAM(NULL, NGL_int, BACKEND_VERSION_MINOR),

    NGL_PARAM(NULL, NGL_char*, BACKEND_SHADING_LANG),
    NGL_PARAM(NULL, NGL_float, BACKEND_SHADING_LANG_VERSION),
    NGL_PARAM(NULL, NGL_int, BACKEND_SHADING_LANG_VERSION_MAJOR),
    NGL_PARAM(NULL, NGL_int, BACKEND_SHADING_LANG_VERSION_MINOR),

#pragma NGL_READWRITE

    // Matrix

    NGL_PARAM(NULL, NGL_float*, MATRIX_PROJECTION),
    NGL_PARAM(NULL, NGL_float*, MATRIX_VIEW),
    NGL_PARAM(NULL, NGL_float*, MATRIX_MODEL),

    // Texture

    NGL_PARAM(NULL, NGL_object, TEXTURE_1D),
    NGL_PARAM(TEXTURE_1D, NGL_int, TEXTURE_1D_WIDTH),
    NGL_PARAM(TEXTURE_1D, NGL_void*, TEXTURE_1D_DATA),

    NGL_PARAM(NULL, NGL_object, TEXTURE_2D),
    NGL_PARAM(TEXTURE_2D, NGL_int, TEXTURE_2D_WIDTH),
    NGL_PARAM(TEXTURE_2D, NGL_int, TEXTURE_2D_HEIGHT),
    NGL_PARAM(TEXTURE_2D, NGL_void*, TEXTURE_2D_DATA),

    NGL_PARAM(NULL, NGL_object, TEXTURE_3D),
    NGL_PARAM(TEXTURE_3D, NGL_int, TEXTURE_3D_WIDTH),
    NGL_PARAM(TEXTURE_3D, NGL_int, TEXTURE_3D_HEIGHT),
    NGL_PARAM(TEXTURE_3D, NGL_int, TEXTURE_3D_BREADTH),
    NGL_PARAM(TEXTURE_3D, NGL_void*, TEXTURE_3D_DATA),


    // Vertex

    NGL_PARAM(NULL, NGL_object, VERTEX_ARRAY),
    NGL_PARAM(VERTEX_ARRAY, NGL_int, VERTEX_ARRAY_FORMAT),
    NGL_PARAM(VERTEX_ARRAY, NGL_int, VERTEX_ARRAY_LENGTH),
    NGL_PARAM(VERTEX_ARRAY, NGL_void*, VERTEX_ARRAY_DATA),

    NGL_PARAM(NULL, NGL_object, INDEX_ARRAY),
    NGL_PARAM(INDEX_ARRAY, NGL_int, INDEX_ARRAY_LENGTH),
    NGL_PARAM(INDEX_ARRAY, NGL_void*, INDEX_ARRAY_DATA),


    // Draw

    NGL_PARAM(NULL, NGL_enum, DRAW_METHOD),


    // Shader

    NGL_PARAM(NULL, NGL_object, SHADER_PROGRAM),
    NGL_PARAM(SHADER_PROGRAM, NGL_object*, SHADER_PROGRAM_SHADERS),

    NGL_PARAM(SHADER_PROGRAM, NGL_object, SHADER),
    NGL_PARAM(SHADER, NGL_enum, SHADER_TYPE),
    NGL_PARAM(SHADER, NGL_char*, SHADER_SOURCE),

#pragma NGL_WRITEONLY

#pragma NGL_NOPTION

    // Draw

    N_GL_POINTS,
    N_GL_LINES,
    N_GL_TRIANGLES,
    N_GL_TRIANGLE_STRIP,
    N_GL_TRIANGLE_FAN,


    // Vertex

    N_GL_VERTEX_XYZ = 0x01,
    N_GL_VERTEX_COLOR = 0x02,
    N_GL_VERTEX_TEX = 0x04,


    // Shader

    N_GL_SHADER_VERTEX,
    N_GL_SHADER_FRAGMENT
});

#undef NGL_PARAM

#if 0
NGL_object shader_prog = NGL.create(NGL_SHADER_PROGRAM);
NGL_SET(NGL_SHADER_PROGRAM, shader_prog);

NGL_object shader_vert = NGL.create(NGL_SHADER);
NGL_SET(NGL_SHADER, shader_vert);
NGL_SET(NGL_SHADER_TYPE, NGL_SHADER_VERTEX);
NGL_SET(NGL_SHADER_SOURCE, ...); // Since this is just a string, not an array of strings, NGL_SET instead of NGL.set is okay
NGL.compile();

NGL_object shader_frag = NGL.create(NGL_SHADER);
NGL_SET(NGL_SHADER, shader_frag);
NGL_SET(NGL_SHADER_TYPE, NGL_SHADER_FRAGMENT);
NGL_SET(NGL_SHADER_SOURCE, ...);
NGL.compile();

NGL.set(NGL_SHADER_PROGRAM_SHADERS, (NGL_object[]){shader_vert, shader_frag, 0});
NGL.link();

NGL.dispatch();


NGL_object texture = NGL.create(NGL_TEXTURE_2D);
NGL.set(NGL_TEXTURE_2D, (NGL_object[]){texture});
NGL.set(NGL_TEXTURE_2D_WIDTH, (NGL_int[]){500});
NGL.set(NGL_TEXTURE_2D_HEIGHT, (NGL_int[]){500});
// or
NGL_SET(NGL_TEXTURE_2D_HEIGHT, 500);
NGL.set(NGL_TEXTURE_2D_DATA, ...);
NGL.dispatch();


NGL_object vao = NGL.create(NGL_VERTEX_ARRAY);
NGL_SET(NGL_VERTEX_ARRAY, vao);
NGL_SET(NGL_VERTEX_ARRAY_FORMAT, NGL_VERTEX_XYZ | NGL_VERTEX_TEX);
NGL_SET(NGL_VERTEX_ARRAY_LENGTH, 4);
NGL.set(NGL_VERTEX_ARRAY_DATA, ...);
NGL_SET(NGL_VERTEX_ARRAY, 0);

NGL_object iao = NGL.create(NGL_INDEX_ARRAY);
NGL_SET(NGL_INDEX_ARRAY, iao);
NGL_SET(NGL_INDEX_ARRAY_LENGTH, 4);
NGL.set(NGL_INDEX_ARRAY_DATA, ...);
NGL_SET(NGL_INDEX_ARRAY, 0);

NGL.dispatch();


NGL_SET(NGL_VERTEX_ARRAY, vao);
NGL_SET(NGL_INDEX_ARRAY, iao);
NGL_SET(NGL_DRAW_METHOD, NGL_TRIANGLE_STRIP);
NGL.draw();
NGL_SET(NGL_INDEX_ARRAY, 0);
NGL_SET(NGL_VERTEX_ARRAY, 0);

NGL.dispatch();
#endif
