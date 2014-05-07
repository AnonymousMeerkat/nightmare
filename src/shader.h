#ifndef _SP_SHADER_H
#define _SP_SHADER_H

#include "compat.h"

#include "misc.h"
#include "types.h"

START_HEAD

#include "wrap/gl.h"

STRUCT(Shader, {
    GLuint shader_handle;
    GLuint vertex_handle;
    GLuint fragment_handle;
});

Shader* Shader_new(char* vertex, char* fragment);
void Shader_destroy(Shader* shader);

void Shader_bind_attrib(Shader* shader, GLuint attrib, char* name);
bool Shader_link(Shader* shader);

void Shader_set_vec4(Shader* shader, char* name, GLKVector4 vec);
void Shader_set_mat4(Shader* shader, char* name, GLKMatrix4 matrix);

void Shader_run(Shader* shader);
void Shader_stop();

END_HEAD

#endif
