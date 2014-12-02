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

#include "NImage.h"

#include "NLog.h"
#include "NGlobals.h"
#include "NSquare.h"
#include "NShader.h"
#include "NIFF.h"
#include "NRsc.h"
#include "NTypes.h"
#include "NEngine.h"

#include "wrap/gl.h"
#include <stdlib.h>
#include <GLKit/GLKMath.h>

// TODO: Maybe add the option for bilinear filtering instead of trilinear?

void NImage_2D_parameters() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void NImage_3D_parameters() {
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

NSTRUCT(fbo_data, {
    GLuint rbo;
    GLuint fbo;
});

bool NImage_new_fbo(NImage* image) {
    fbo_data* data = malloc(sizeof(fbo_data));
    image->size = Npos2i_3i(N_game_size);
    glGenFramebuffers(1, &data->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, data->fbo);
    glBindTexture(GL_TEXTURE_2D, image->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, N_game_size.x, N_game_size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, image->id, 0);
    NImage_unbind(image);
    GLenum draw_bufs[] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers (1, draw_bufs);
    image->data = data;
    GLenum status;
    if ((status = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE) {
        Nerror("Framebuffer error! %i", status);
        return false;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return true;
}

void NImage_destroy_fbo(NImage* image) {
    fbo_data* data = image->data;
    glDeleteRenderbuffers(1, &data->rbo);
    glDeleteFramebuffers(1, &data->fbo);
    free(data);
}

NImage* NImage_new(NImage_type type) {
    NImage* image = malloc(sizeof(NImage));

    image->type = type;
    image->id = 0;
    image->data = NULL;
    image->size = N_Pos3i0;

    glGenTextures(1, &image->id);

    if (type == NImage_FBO) {
        if (!NImage_new_fbo(image)) {
            goto destroy;
        }
    }

    goto end;

destroy:
    NImage_destroy(image);
end:
    return image;
}

void NImage_destroy(NImage* image) {
    glDeleteTextures(1, &image->id);
    if (image->type == NImage_FBO) {
        NImage_destroy_fbo(image);
    }
    free(image);
}


unsigned char* NImage_load_niff(char* path, NPos3i* size) {
    char* read = NRsc_read_file_rp(path);

    NIFF_t* niff = (NIFF_t*)read;
    size->x = niff->x_size;
    size->y = niff->y_size;
    size->z = niff->z_size;

    unsigned char* raw = NIFF_to_raw(niff);

    free(read);

    return raw;
}

bool NImage_load(NImage* image, char* path) {
    bool ret;
    unsigned char* good_data = NImage_load_niff(path, &image->size);
    if (!good_data) {
        ret = false;
        goto end;
    }

    NImage_bind(image);
    NImage_2D_parameters();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image->size.x, image->size.y, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, good_data);
    glGenerateMipmap(GL_TEXTURE_2D);
    NImage_unbind();

    free(good_data);

    ret = true;
end:
    return ret;
}

bool NImage_load_3D(NImage* image, NPos3i size, uchar* data, uchar channels) {
    bool ret;
    if (!data) {
        ret = false;
        goto end;
    }

    image->size = size;

    GLenum internalformat = GL_RGBA8;
    GLenum pixelformat = GL_RGBA;

    switch (channels) {
        case 1:
            internalformat = GL_R8;
            pixelformat = GL_RED;
            break;
        default:
            break;
    }

    NImage_bind(image);
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    NImage_3D_parameters();
    glTexImage3D(GL_TEXTURE_3D, 0, internalformat, size.x, size.y, size.z, 0,
        pixelformat, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_3D);
    NImage_unbind();

    ret = true;
end:
    return ret;
}


void NImage_record(NImage* image) {
    if (image->type != NImage_FBO) {
        return;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, ((fbo_data*)image->data)->fbo);
    glViewport(0, 0, image->size.x, image->size.y);
}

void NImage_stoprecord() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    NEngine_update_viewport();
}

void NImage_bind(NImage* image) {
    glActiveTexture(GL_TEXTURE0);
    if (image->type == NImage_3D) {
        glBindTexture(GL_TEXTURE_3D, image->id);
    } else {
        glBindTexture(GL_TEXTURE_2D, image->id);
    }
}

void NImage_unbind() {
    glBindTexture(GL_TEXTURE_3D, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void NImage_draw(NImage* image, struct NImage_draw_args args) {
    NPos2i size = Npos3i_2i(image->size);
    if (args.size.x != 0 && args.size.y != 0) {
        size = args.size;
    }

    NImage_bind(image);

    NShader* shader = N_shaders[N_SHADER_IMAGE];

    bool ran_shader = false;
    if (!N_shader) {
        NShader_run(shader);
        ran_shader = true;
    }

    NShader_set_int(shader, "N_UV_flip", args.flip);
    NShader_set_float(shader, "N_UV_z", args.z);
    NShader_set_float(shader, "N_alpha", args.alpha);
    if (image->type == NImage_3D) {
        NShader_set_int(shader, "N_3D", 1);
    } else {
        NShader_set_int(shader, "N_3D", 0);
    }
    NSquare_draw(args.pos, size);

    if (ran_shader) {
        NShader_stop();
    }

    NImage_unbind();
}
