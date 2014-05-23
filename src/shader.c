#include "shader.h"

#include "log.h"
#include "resource.h"
#include "splu.h"
#include <stdlib.h>

void Shader_print_log(bool shader, GLuint handle, char* prefix) {
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
        debug("%s error:\n---\n%s", prefix, our_log);
        free(our_log);
    }
}

bool Shader_load(GLenum type, const GLchar* shader, GLuint* handle) {
    int status;

    debug("Creating shader");
    GLuint i_handle;
    i_handle = glCreateShader(type);
    *handle = i_handle;
    debug("Loading shader");
    glShaderSource(i_handle, 1, &shader, NULL);
    debug("Compiling shader");
    glCompileShader(i_handle);
    glGetShaderiv(i_handle, GL_COMPILE_STATUS, &status);
    Shader_print_log(true, i_handle, "Compilation");
    if (status != GL_TRUE) {
        return false;
    }
    return true;
}

Shader* Shader_new(char* vertex, char* fragment) {
    Shader* ret = NULL;

    debug("Creating shader program");
    Shader* shader = malloc(sizeof(Shader));
    shader->shader_handle = glCreateProgram();
    if (!shader->shader_handle) {
        error("Error creating shader program");
        goto end;
    }

    debug("Loading vertex shader");
    if (!Shader_load(GL_VERTEX_SHADER, vertex, &shader->vertex_handle)) {
        error("Error loading vertex shader");
        goto deleteshader;
    }
    debug("Attaching vertex shader");
    glAttachShader(shader->shader_handle, shader->vertex_handle);

    debug("Loading fragment shader");
    if (!Shader_load(GL_FRAGMENT_SHADER, fragment, &shader->fragment_handle)) {
        error("Error loading fragment shader");
        goto deletevertex;
    }
    debug("Attaching fragment shader");
    glAttachShader(shader->shader_handle, shader->fragment_handle);

    ret = shader;
    goto end;

deletevertex:
    glDeleteShader(shader->vertex_handle);
deleteshader:
    glDeleteProgram(shader->shader_handle);
end:
    return ret;
}

void Shader_destroy(Shader* shader) {
    Shader_stop();
    glDetachShader(shader->shader_handle, shader->fragment_handle);
    glDetachShader(shader->shader_handle, shader->vertex_handle);
    glDeleteShader(shader->fragment_handle);
    glDeleteShader(shader->vertex_handle);
    glDeleteProgram(shader->shader_handle);
    free(shader);
}


void Shader_bind_attrib(Shader* shader, GLuint attrib, char* name) {
    glBindAttribLocation(shader->shader_handle, attrib, name);
}

bool Shader_link(Shader* shader) {
    int status;
    bool ret = false;

    debug("Linking shader");
    glLinkProgram(shader->shader_handle);
    glGetProgramiv(shader->shader_handle, GL_LINK_STATUS, &status);
    if (status == GL_TRUE) {
        glValidateProgram(shader->shader_handle);
        glGetProgramiv(shader->shader_handle, GL_VALIDATE_STATUS, &status);
        if (status == GL_TRUE) {
            ret = true;
        } else {
            Shader_print_log(false, shader->shader_handle, "Validation");
        }
    } else {
        Shader_print_log(false, shader->shader_handle, "Linking");
    }

    return ret;
}


void Shader_set_int(Shader* shader, char* name, int value) {
    glUniform1i(glGetUniformLocation(shader->shader_handle, name), value);
}

void Shader_set_vec4(Shader* shader, char* name, GLKVector4 value) {
    glUniform4fv(glGetUniformLocation(shader->shader_handle, name), 1, value.v);
}

void Shader_set_mat4(Shader* shader, char* name, GLKMatrix4 value) {
    glUniformMatrix4fv(glGetUniformLocation(shader->shader_handle, name), 1, GL_FALSE, value.m);
}


void Shader_run(Shader* shader) {
    glUseProgram(shader->shader_handle);
    Shader_set_mat4(shader, "MVP", splu_calc_mvp());
}

void Shader_stop() {
    glUseProgram(0);
}
