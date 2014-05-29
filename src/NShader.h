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
void NShader_set_vec4(NShader* shader, char* name, GLKVector4 vec);
void NShader_set_mat4(NShader* shader, char* name, GLKMatrix4 matrix);

void NShader_run(NShader* shader);
void NShader_stop();

END_HEAD

#endif
