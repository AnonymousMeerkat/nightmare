#include "NSplu.h"

#include <GLKit/GLKMath.h>

#include "wrap/gl.h"
#include "NGlobals.h"

GLKMatrix4 Nsplu_calc_mvp() {
    return GLKMatrix4Multiply(N_gl_projection, GLKMatrix4Multiply(N_gl_view, N_gl_model));
}
