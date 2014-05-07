#include "resource.h"

#include "types.h"
#include "shader.h"
#include "image.h"
#include "log.h"

#include <string.h>
#include <stdlib.h>

Shader* rsc_load_shader(char* name) {
    debug("Loading paths");
    size_t pathlen = strlen(name) + 6;
    char* base_path = malloc(pathlen);
    strcpy(base_path, "glsl/");
    strcat(base_path, name);

    char* vertex_path = malloc(pathlen + 12);
    strcpy(vertex_path, base_path);
    strcat(vertex_path, "/vertex.glsl");
    char* vertex_file = rsc_read_file(vertex_path);
    free(vertex_path);

    char* fragment_path = malloc(pathlen + 14);
    strcpy(fragment_path, base_path);
    strcat(fragment_path, "/fragment.glsl");
    char* fragment_file = rsc_read_file(fragment_path);
    free(fragment_path);

    free(base_path);

    debug("Loading shader");
    Shader* shader = Shader_new(vertex_file, fragment_file);
    free(vertex_file);
    free(fragment_file);

    return shader;
}

Image* rsc_load_image(char* name) {
    size_t pathlen = strlen(name) + 5;
    char* simplepath = malloc(pathlen);
    strcpy(simplepath, "img/");
    strcat(simplepath, name);

    char* path = rsc_get_path(simplepath);

    free(simplepath);

    Image* ret = Image_new(Image_IMAGE);
    if (!ret) {
        error("Error creating image!");
        return NULL;
    }
    if (!Image_load(ret, path)) {
        error("Error loading image!");
        Image_destroy(ret);
        return NULL;
    }

    free(path);

    return ret;
}
