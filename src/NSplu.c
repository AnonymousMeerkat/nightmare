#include "NSplu.h"

#include <GLKit/GLKMath.h>

#include "wrap/gl.h"
#include "NGlobals.h"

GLKMatrix4 Nsplu_calc_pos(GLKVector2 pos) {
    GLKMatrix4 model = GLKMatrix4Identity;
    model = GLKMatrix4Translate(model, pos.x, pos.y, 0);
    return model;
}

GLKMatrix4 Nsplu_calc_rect(GLKVector2 pos, GLKVector2 size) {
    GLKMatrix4 model = GLKMatrix4Identity;
    model = GLKMatrix4Translate(model, pos.x, pos.y, 0);
    model = GLKMatrix4Scale(model, size.x, size.y, 0);
    return model;
}

GLKMatrix4 Nsplu_calc_mvp() {
    return GLKMatrix4Multiply(N_gl_projection, GLKMatrix4Multiply(N_gl_view, N_gl_model));
}
