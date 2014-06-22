#include "NImage.h"

#include "NLog.h"
#include "NGlobals.h"
#include "NSquare.h"
#include "NShader.h"
#include "NTypes.h"

#include "wrap/gl.h"
#include <lodepng.h>
#include <stdlib.h>
#include <GLKit/GLKMath.h>

void NImage_gl_parameters() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

NSTRUCT(fbo_data, {
    GLuint rbo;
    GLuint fbo;
});

bool NImage_new_fbo(NImage* image) {
    fbo_data* data = malloc(sizeof(fbo_data));
    image->size = N_win_size;
    glGenFramebuffers(1, &data->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, data->fbo);
    glBindTexture(GL_TEXTURE_2D, image->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, N_win_size.x, N_win_size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
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
    image->size = NPos2i0;

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

bool NImage_load(NImage* image, char* path) {
    bool ret = false;
    if (image->type != NImage_IMAGE) {
        Nerror("Error loading image file into framebuffer!");
        goto end;
    }

    unsigned int error;
    unsigned char* raw_data;
    unsigned int width, height;

    error = lodepng_decode32_file(&raw_data, &width, &height, path);
    image->size.x = width;
    image->size.y = height;
    if (error) {
        Nerror("Error loading image %s (%u): %s", path, error, lodepng_error_text(error));
        ret = false;
        goto end;
    }

    unsigned char* good_data = malloc(width * height * 4);
    for (size_t y = 0; y < height; y++) {
        for (size_t x = 0; x < width * 4; x++) {
            good_data[4 * width * y + x] = raw_data[4 * width * (height - 1 - y) + x];
        }
    }

    free(raw_data);

    NImage_bind(image);
    NImage_gl_parameters();
    glTexImage2D(GL_TEXTURE_2D, 0, 4, image->size.x, image->size.y, 0,
        GL_RGBA, GL_UNSIGNED_BYTE, good_data);
    glGenerateMipmap(GL_TEXTURE_2D);
    NImage_unbind();

    free(good_data);

    ret = true;
end:
    return ret;
}

void NImage_record(NImage* image) {
    if (image->type != NImage_FBO) {
        return;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, ((fbo_data*)image->data)->fbo);
    //glViewport(0, 0, N_win_size.x, N_win_size.y);
}

void NImage_stoprecord() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void NImage_bind(NImage* image) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, image->id);
}

void NImage_unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void NImage_draw(NImage* image, NPos2i pos, bool flip, float alpha) {
    NImage_bind(image);
    NShader* shader = N_shaders[N_SHADER_IMAGE];
    NShader_run(shader);
    NShader_set_int(shader, "N_UV_flip", flip);
    NShader_set_float(shader, "N_alpha", alpha);
    NSquare_draw(pos, image->size);
    NShader_stop();
    NImage_unbind();
}
