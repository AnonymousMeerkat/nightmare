#include "square.h"

#include "shader.h"
#include "globals.h"
#include <GLKit/GLKMath.h>

GLuint square_id;

GLuint vao;
GLuint vbo;
GLuint ibo;

#define VERTICES 4
#define INDICES 6

typedef struct {
    GLfloat position[3];
    GLfloat texcoord[2];
} vertex;

void square_init() {
    vertex vertexdata[VERTICES] = {
        { { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f } },
        { { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
        { { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
        { { 1.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } }
    };
    GLubyte indexdata[INDICES] = {0, 1, 2, 1, 3, 2};

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTICES * sizeof(vertex), vertexdata, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, position));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, texcoord));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDICES * sizeof(GLubyte), indexdata, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    square_id = vao;
}

void square_destroy() {
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glDeleteBuffers(1, &ibo);
    glDeleteBuffers(1, &vbo);

    glDeleteVertexArrays(1, &vao);
}


void square_draw_shape() {
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glDrawElements(GL_TRIANGLES, INDICES, GL_UNSIGNED_BYTE, NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

void square_draw(Shader* shader, Pos2i pos, Pos2i size, bool flip) {
    GLKMatrix4 model = gl_model;
    gl_model = GLKMatrix4Translate(gl_model, pos.x, pos.y, 0);
    gl_model = GLKMatrix4Scale(gl_model, size.x, size.y, 0);
    Shader_run(shader);
    Shader_set_int(shader, "flip", flip);
    square_draw_shape();
    Shader_stop();
    gl_model = model;
}
