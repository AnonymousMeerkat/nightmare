#include "NShader.h"

#include "NLog.h"
#include "NRsc.h"
#include "NSplu.h"
#include <stdlib.h>

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

    Ndebug("Creating shader");
    GLuint i_handle;
    i_handle = glCreateShader(type);
    *handle = i_handle;
    Ndebug("Loading shader");
    glShaderSource(i_handle, 1, &shader, NULL);
    Ndebug("Compiling shader");
    glCompileShader(i_handle);
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
    NShader* shader = malloc(sizeof(NShader));
    shader->shader_handle = glCreateProgram();
    if (!shader->shader_handle) {
        Nerror("Error creating shader program");
        goto end;
    }

    Ndebug("Loading vertex shader");
    if (!NShader_load(GL_VERTEX_SHADER, vertex, &shader->vertex_handle)) {
        Nerror("Error loading vertex shader");
        goto deleteshader;
    }
    Ndebug("Attaching vertex shader");
    glAttachShader(shader->shader_handle, shader->vertex_handle);

    Ndebug("Loading fragment shader");
    if (!NShader_load(GL_FRAGMENT_SHADER, fragment, &shader->fragment_handle)) {
        Nerror("Error loading fragment shader");
        goto deletevertex;
    }
    Ndebug("Attaching fragment shader");
    glAttachShader(shader->shader_handle, shader->fragment_handle);

    for (GLuint i = 0; attribs[i].name; i++) {
        glBindAttribLocation(shader->shader_handle, attribs[i].attrib, attribs[i].name);
    }

    int status;

    Ndebug("Linking shader");
    glLinkProgram(shader->shader_handle);
    glGetProgramiv(shader->shader_handle, GL_LINK_STATUS, &status);
    if (status == GL_TRUE) {
        glValidateProgram(shader->shader_handle);
        glGetProgramiv(shader->shader_handle, GL_VALIDATE_STATUS, &status);
        if (status != GL_TRUE) {
            NShader_print_log(false, shader->shader_handle, "Validation");
        }
    } else {
        NShader_print_log(false, shader->shader_handle, "Linking");
    }

    ret = shader;
    goto end;

//deletefragment:
    glDeleteShader(shader->fragment_handle);
deletevertex:
    glDeleteShader(shader->vertex_handle);
deleteshader:
    glDeleteProgram(shader->shader_handle);
end:
    return ret;
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


void NShader_set_int(NShader* shader, char* name, int value) {
    glUniform1i(glGetUniformLocation(shader->shader_handle, name), value);
}

void NShader_set_vec4(NShader* shader, char* name, GLKVector4 value) {
    glUniform4fv(glGetUniformLocation(shader->shader_handle, name), 1, value.v);
}

void NShader_set_mat4(NShader* shader, char* name, GLKMatrix4 value) {
    glUniformMatrix4fv(glGetUniformLocation(shader->shader_handle, name), 1, GL_FALSE, value.m);
}


void NShader_run(NShader* shader) {
    glUseProgram(shader->shader_handle);
    NShader_set_mat4(shader, "N_MVP", Nsplu_calc_mvp());
}

void NShader_stop() {
    glUseProgram(0);
}
