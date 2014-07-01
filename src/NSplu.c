#include "NSplu.h"

#include <GLKit/GLKMath.h>

#include "wrap/gl.h"
#include "NGlobals.h"

NRectf Nsplu_calc_viewport() {
    const float aspect = N_game_size.x / (float)N_game_size.y;

    NPos2f size;
    size.x = N_win_size.x;
    size.y = (int)(size.x / aspect + 0.5);
    if (size.y > N_win_size.y) {
        size.y = N_win_size.y;
        size.x = (int)(size.y * aspect + 0.5);
    }

    NPos2f vp;
    vp.x = (N_win_size.x - size.x) / 2.;
    vp.y = (N_win_size.y - size.y) / 2.;

    NRectf viewport;
    viewport.pos = vp;
    viewport.size = size;

    return viewport;
}

GLKMatrix4 Nsplu_calc_pos(GLKVector2 pos) {
    GLKMatrix4 model = N_gl_model;
    model = GLKMatrix4Translate(model, pos.x, pos.y, 0);
    return model;
}

GLKMatrix4 Nsplu_calc_rect(GLKVector2 pos, GLKVector2 size) {
    GLKMatrix4 model = N_gl_model;
    model = GLKMatrix4Translate(model, pos.x, pos.y, 0);
    model = GLKMatrix4Scale(model, size.x, size.y, 0);
    return model;
}

GLKMatrix4 Nsplu_calc_mvp() {
    return GLKMatrix4Multiply(N_gl_projection, GLKMatrix4Multiply(N_gl_view, N_gl_model));
}
