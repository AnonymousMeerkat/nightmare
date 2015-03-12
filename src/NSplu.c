/*
    Copyright (c) 2014, Anonymous Meerkat <meerkatanonymous@gmail.com>
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

#include "NSplu.h"

#include "NVecMath.h"
#include "wrap/gl.h"
#include "NGlobals.h"

NRectf Nsplu_calc_viewport() {
    const float aspect = N_game_size.x / (float)N_game_size.y;

    NVec2f_t size;
    size.x = N_win_size.x;
    size.y = (int)(size.x / aspect + 0.5);
    if (size.y > N_win_size.y) {
        size.y = N_win_size.y;
        size.x = (int)(size.y * aspect + 0.5);
    }

    NVec2f_t vp;
    vp.x = (N_win_size.x - size.x) / 2.;
    vp.y = (N_win_size.y - size.y) / 2.;

    NRectf viewport;
    viewport.pos = vp;
    viewport.size = size;

    return viewport;
}

NMat4f_t Nsplu_calc_pos(NVec2f_t pos) {
    NMat4f_t model = N_gl_model;
    model = NMat4f_translate_3f(model, NVec3f(pos.x, pos.y, 0));
    return model;
}

NMat4f_t Nsplu_calc_rect(NVec2f_t pos, NVec2f_t size) {
    NMat4f_t model = N_gl_model;
    model = NMat4f_translate_3f(model, NVec3f(pos.x, pos.y, 0));
    model = NMat4f_scale_3f(model, NVec3f(size.x, size.y, 0));
    return model;
}

NMat4f_t Nsplu_calc_mvp() {
    return NMat4f_mul(N_gl_projection, NMat4f_mul(N_gl_view, N_gl_model));
}
