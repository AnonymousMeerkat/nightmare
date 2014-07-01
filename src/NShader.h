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

#ifndef _NME_SHADER_H
#define _NME_SHADER_H

#include "NCompat.h"

START_HEAD

#include "NUtil.h"
#include "NTypes.h"

#include "wrap/gl.h"

NSTRUCT(NShader_attrib, {
    GLuint attrib;
    char* name;
});

NSTRUCT(NShader_info, {
    char* name;
    NShader_attrib* attribs;
});

NSTRUCT(NShader, {
    GLuint shader_handle;
    GLuint vertex_handle;
    GLuint fragment_handle;
});

NShader* NShader_new(char* vertex, char* fragment, NShader_attrib* attribs);
void NShader_destroy(NShader* shader);

void NShader_set_int(NShader* shader, char* name, int value);
void NShader_set_float(NShader* shader, char* name, float value);
void NShader_set_vec2(NShader* shader, char* name, GLKVector2 vec);
void NShader_set_vec4(NShader* shader, char* name, GLKVector4 vec);
void NShader_set_mat4(NShader* shader, char* name, GLKMatrix4 matrix);
void NShader_update_MVP(NShader* shader);

void NShader_run(NShader* shader);
void NShader_stop();

END_HEAD

#endif
