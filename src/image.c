#include "image.h"

#include "log.h"
#include "globals.h"
#include "square.h"
#include "shader.h"

#include "wrap/gl.h"
#include <FreeImage.h>
#include <stdlib.h>
#include <GLKit/GLKMath.h>

void Image_gl_parameters() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

STRUCT(fbo_data, {
    GLuint rbo;
    GLuint fbo;
});

bool Image_new_fbo(Image* image) {
    // Basically copied over from DBAB
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &image->id);
    Image_bind(image);
    Image_gl_parameters();
    fbo_data* data = malloc(sizeof(fbo_data));
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, win_width, win_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
    glGenRenderbuffers(1, &data->rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, data->rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, win_width, win_height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glGenFramebuffers(1, &data->fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, data->fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, image->id, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, data->rbo);
    image->data = data;
    GLenum status;
    if ((status = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE) {
        error("Framebuffer error! %i", status);
        return false;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return true;
}

void Image_destroy_fbo(Image* image) {
    fbo_data* data = image->data;
    glDeleteRenderbuffers(1, &data->rbo);
    glDeleteFramebuffers(1, &data->fbo);
    free(data);
}

Image* Image_new(Image_type type) {
    Image* image = malloc(sizeof(Image));

    image->type = type;
    image->id = 0;
    image->data = NULL;
    image->size = Pos2iblank;

    glGenTextures(1, &image->id);

    if (type == Image_FBO) {
        if (!Image_new_fbo(image)) {
            goto destroy;
        }
    }

    goto end;

destroy:
    Image_destroy(image);
end:
    return image;
}

void Image_destroy(Image* image) {
    glDeleteTextures(1, &image->id);
    if (image->type == Image_FBO) {
        Image_destroy_fbo(image);
    }
    free(image);
}

bool Image_load(Image* image, char* path) {
    bool ret = false;
    if (image->type != Image_IMAGE) {
        error("I'm not gonna load an image onto a FRAMEBUFFER!");
        goto end;
    }

    FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(path, 0);
    if (fif == FIF_UNKNOWN) {
        fif = FreeImage_GetFIFFromFilename(path);
    }

    if (fif != FIF_UNKNOWN && FreeImage_FIFSupportsReading(fif)) {
        image->data = FreeImage_Load(fif, path, 0);
        if (!image->data) {
            error("Error loading image!");
            goto end;
        }

        FIBITMAP* temp = image->data;
        image->data = FreeImage_ConvertTo32Bits(temp);
        FreeImage_Unload(temp);

        if (!image->data) {
            error("Error converting image!");
            goto end;
        }

        image->size.x = FreeImage_GetWidth(image->data);
        image->size.y = FreeImage_GetHeight(image->data);

        Image_bind(image);
        Image_gl_parameters();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image->size.x, image->size.y, 0,
            GL_BGRA, GL_UNSIGNED_BYTE, FreeImage_GetBits(image->data));
        glGenerateMipmap(GL_TEXTURE_2D);
        Image_unbind();

        ret = true;
    } else {
        error("You seriously consider this to be an image?");
        goto end;
    }

    FreeImage_Unload(image->data);
    image->data = NULL;
end:
    return ret;
}

void Image_record(Image* image) {
    if (image->type != Image_FBO) {
        return;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, ((fbo_data*)image->data)->fbo);
}

void Image_stoprecord() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Image_bind(Image* image) {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, image->id);
}

void Image_unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Image_draw(Image* image, Pos2i pos) {
    Image_bind(image);
    square_draw(shader_image, pos, image->size);
    Image_unbind();
}
