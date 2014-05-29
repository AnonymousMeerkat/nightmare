#include "NImage.h"

#include "NLog.h"
#include "NGlobals.h"
#include "NSquare.h"
#include "NShader.h"
#include "NTypes.h"

#include "wrap/gl.h"
#include <FreeImage.h>
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
    // Basically copied over from DBAB
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &image->id);
    NImage_bind(image);
    NImage_gl_parameters();
    fbo_data* data = malloc(sizeof(fbo_data));
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, N_win_size.x, N_win_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
    glGenRenderbuffers(1, &data->rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, data->rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, N_win_size.x, N_win_size.y);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glGenFramebuffers(1, &data->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, data->fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, image->id, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, data->rbo);
    image->data = data;
    GLenum status;
    if ((status = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE) {
        Nerror("Framebuffer error! %i", status);
        return false;
    }
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

    FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(path, 0);
    if (fif == FIF_UNKNOWN) {
        fif = FreeImage_GetFIFFromFilename(path);
    }

    if (fif != FIF_UNKNOWN && FreeImage_FIFSupportsReading(fif)) {
        image->data = FreeImage_Load(fif, path, 0);
        if (!image->data) {
            Nerror("Error loading image!");
            goto end;
        }

        FIBITMAP* temp = image->data;
        image->data = FreeImage_ConvertTo32Bits(temp);
        FreeImage_Unload(temp);

        if (!image->data) {
            Nerror("Error converting image!");
            goto end;
        }

        image->size.x = FreeImage_GetWidth(image->data);
        image->size.y = FreeImage_GetHeight(image->data);

        NImage_bind(image);
        NImage_gl_parameters();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image->size.x, image->size.y, 0,
            GL_BGRA, GL_UNSIGNED_BYTE, FreeImage_GetBits(image->data));
        glGenerateMipmap(GL_TEXTURE_2D);
        NImage_unbind();

        ret = true;
    } else {
        Nerror("Image %s not supported!", path);
        goto end;
    }

    FreeImage_Unload(image->data);
    image->data = NULL;
end:
    return ret;
}

void NImage_record(NImage* image) {
    if (image->type != NImage_FBO) {
        return;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, ((fbo_data*)image->data)->fbo);
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

void NImage_draw(NImage* image, NPos2i pos, bool flip) {
    NImage_bind(image);
    NSquare_draw(N_shaders[N_SHADER_IMAGE], pos, image->size, flip);
    NImage_unbind();
}
