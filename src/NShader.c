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

#include "NShader.h"

#include "NLog.h"
#include "NRsc.h"
#include "NSplu.h"
#include <stdlib.h>
#include <string.h>

const char versionstr_egl[] =
"#version 100\n"
"#extension GL_OES_texture_3D : enable\n"
"precision mediump float;\n";

const char versionstr_gl[] =
"#version 130\n"
"#define lowp\n"
"#define mediump\n"
"#define highp\n"
"#extension GL_EXT_gpu_shader4: enable\n";

void NShader_print_log(bool shader, GLuint handle, char* prefix) {
    GLsizei len_dont_use;
    GLsizei len;
    glGetShaderiv(handle, GL_INFO_LOG_LENGTH , &len);
    if (len > 1) {
        GLchar* our_log = malloc(len);
        if (shader) {
            glGetShaderInfoLog(handle, len, &len_dont_use, our_log);
        } else {
            glGetProgramInfoLog(handle, len, &len_dont_use, our_log);
        }
        Ndebug("%s error:\n---\n%s", prefix, our_log);
        free(our_log);
    }
}

bool NShader_load(GLenum type, const GLchar* shader, GLuint* handle) {
    int status;

    const char* versionstr = NULL;
    size_t versionstr_len = 0;
    if (N_shader_egl) {
        versionstr = versionstr_egl;
        versionstr_len = sizeof(versionstr_egl);
    } else {
        versionstr = versionstr_gl;
        versionstr_len = sizeof(versionstr_gl);
    }

    Ndebug("Creating shader");
    GLuint i_handle;
    i_handle = glCreateShader(type);
    *handle = i_handle;
    Ndebug("Loading shader");
    size_t shaderlen = strlen(shader);
    GLchar* newsrc = malloc(sizeof(GLchar) * (versionstr_len + shaderlen + N_shader_head_len + 1));
    strcpy(newsrc, versionstr);
    strcat(newsrc, N_shader_head);
    strcat(newsrc, shader);
    glShaderSource(i_handle, 1, (const GLchar* const*) &newsrc, NULL);
    Ndebug("Compiling shader");
    glCompileShader(i_handle);
    free(newsrc);
    glGetShaderiv(i_handle, GL_COMPILE_STATUS, &status);
    NShader_print_log(true, i_handle, "Compilation");
    if (status != GL_TRUE) {
        return false;
    }
    return true;
}

NShader* NShader_new(char* vertex, char* fragment, NShader_attrib* attribs) {
    NShader* ret = NULL;

    Ndebug("Creating shader program");
    N_indent++;
    NShader* shader = malloc(sizeof(NShader));
    shader->shader_handle = glCreateProgram();
    if (!shader->shader_handle) {
        Nerror("Error creating shader program");
        goto end;
    }

    Ndebug("Loading vertex shader");
    N_indent++;
    if (!NShader_load(GL_VERTEX_SHADER, vertex, &shader->vertex_handle)) {
        Nerror("Error loading vertex shader");
        goto deleteshader;
    }
    Ndebug("Attaching vertex shader");
    glAttachShader(shader->shader_handle, shader->vertex_handle);

    N_indent--;

    Ndebug("Loading fragment shader");
    N_indent++;
    if (!NShader_load(GL_FRAGMENT_SHADER, fragment, &shader->fragment_handle)) {
        Nerror("Error loading fragment shader");
        goto deletevertex;
    }
    Ndebug("Attaching fragment shader");
    glAttachShader(shader->shader_handle, shader->fragment_handle);

    N_indent -= 2;

    for (GLuint i = 0; attribs[i].name; i++) {
        glBindAttribLocation(shader->shader_handle, attribs[i].attrib, attribs[i].name);
    }

    glBindFragDataLocation(shader->shader_handle, 0, "color");

    int status;

    Ndebug("Linking shader");
    glLinkProgram(shader->shader_handle);
    glGetProgramiv(shader->shader_handle, GL_LINK_STATUS, &status);
    if (status == GL_TRUE) {
        glValidateProgram(shader->shader_handle);
        glGetProgramiv(shader->shader_handle, GL_VALIDATE_STATUS, &status);
        if (status != GL_TRUE) {
            NShader_print_log(false, shader->shader_handle, "Validation");
        } else {
            return shader;
        }
    } else {
        NShader_print_log(false, shader->shader_handle, "Linking");
    }

//deletefragment:
    glDeleteShader(shader->fragment_handle);
deletevertex:
    glDeleteShader(shader->vertex_handle);
deleteshader:
    glDeleteProgram(shader->shader_handle);
end:
    return NULL;
}

void NShader_destroy(NShader* shader) {
    NShader_stop();
    glDetachShader(shader->shader_handle, shader->fragment_handle);
    glDetachShader(shader->shader_handle, shader->vertex_handle);
    glDeleteShader(shader->fragment_handle);
    glDeleteShader(shader->vertex_handle);
    glDeleteProgram(shader->shader_handle);
    free(shader);
}

#define getuniform() GLint uniform = glGetUniformLocation(shader->shader_handle, name); if (uniform < 0) {return;}

void NShader_set_int(NShader* shader, char* name, GLint value) {
    getuniform();
    glUniform1i(uniform, value);
}

void NShader_set_uint(NShader* shader, char* name, GLuint value) {
    getuniform();
    glUniform1ui(uniform, value);
}

void NShader_set_float(NShader* shader, char* name, GLfloat value) {
    getuniform();
    glUniform1f(uniform, value);
}

void NShader_set_vec2(NShader* shader, char* name, GLKVector2 value) {
    getuniform();
    glUniform2fv(uniform, 1, value.v);
}

void NShader_set_vec4(NShader* shader, char* name, GLKVector4 value) {
    getuniform();
    glUniform4fv(uniform, 1, value.v);
}

void NShader_set_mat4(NShader* shader, char* name, GLKMatrix4 value) {
    getuniform();
    glUniformMatrix4fv(uniform, 1, GL_FALSE, value.m);
}

void NShader_update_MVP(NShader* shader) {
    NShader_set_mat4(shader, "N_MVP", Nsplu_calc_mvp());
}


void NShader_run(NShader* shader) {
    glUseProgram(shader->shader_handle);
    N_shader = shader;
    NShader_set_uint(shader, "N_time", N_currtime);
    NShader_set_float(shader, "N_rand", (float)rand() / (float)RAND_MAX);
}

void NShader_stop() {
    glUseProgram(0);
    N_shader = NULL;
}
