#include "splu.h"

#include "wrap/gl.h"
#include "globals.h"

GLKMatrix4 splu_calc_mvp() {
    return GLKMatrix4Multiply(gl_projection, GLKMatrix4Multiply(gl_view, gl_model));
}
