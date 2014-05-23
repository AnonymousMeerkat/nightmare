#include "resource.h"

#include "types.h"
#include "shader.h"
#include "image.h"
#include "log.h"
#include "sprite.h"
#include "spritesheet.h"

#include <string.h>
#include <stdlib.h>

Shader* rsc_load_shader(char* name) {
    debug("Loading paths");
    size_t pathlen = strlen(name) + 6;
    char* base_path = malloc(pathlen);
    strcpy(base_path, "glsl" SLASH);
    strcat(base_path, name);

    char* vertex_path = malloc(pathlen + 12);
    strcpy(vertex_path, base_path);
    strcat(vertex_path, SLASH "vertex.glsl");
    char* vertex_file = rsc_read_file(vertex_path);
    free(vertex_path);

    char* fragment_path = malloc(pathlen + 14);
    strcpy(fragment_path, base_path);
    strcat(fragment_path, SLASH "fragment.glsl");
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
    //size_t pathlen = strlen(name) + 5;
    debug(name);
    size_t pathlen = strlen(name) + 1;
    char* simplepath = malloc(pathlen);
    /*strcpy(simplepath, "img" SLASH);
    strcat(simplepath, name);*/
    strcpy(simplepath, name);

    char* path = rsc_get_path(simplepath);

    free(simplepath);

    Image* ret = Image_new(Image_IMAGE);

    if (!ret) {
        error("Error creating image!");
        ret = NULL;
        goto end;
    }
    if (!Image_load(ret, path)) {
        error("Error loading image!");
        Image_destroy(ret);
        ret = NULL;
        goto end;
    }

end:
    free(path);

    return ret;
}

Sprite* rsc_load_sprite(char** paths, sprite_framedata* framedata) {
    Sprite* ret = NULL;
    bool okay = true;
    ylist_new(Image*, images);

    Image* temp;
    char* currpath;
    for (size_t i = 0; (currpath = paths[i]); i++) {
        temp = rsc_load_image(currpath);
        if (!temp) {
            okay = false;
            break;
        }
        ylist_push(images, temp);
    }

    if (!okay) {
        ylist_destroy(images);
        goto end;
    }

    ret = Sprite_new(images.data, framedata);

end:
    return ret;
}

Sprite* rsc_load_sprite_dir(char* path, sprite_framedata* framedata) {
    char** names = rsc_ls(path);
    size_t names_count;
    yrlist_count(names, names_count);
    char** paths = malloc(sizeof(char*) * (names_count + 1));

    char* currname;
    for (size_t i = 0; (currname = names[i]); i++) {
        char* noext = rsc_remove_ext(currname);
        int ournumber = atoi(noext);
        free(noext);
#if 0
        if (ournumber == 0) {
            continue;
        }
#endif
        // XXX: Buffer overflow attack imminent here lol
        paths[ournumber] = rsc_join_paths(path, currname);
    }

    paths[names_count] = NULL;

    rsc_ls_free(names);

    Sprite* sprite = rsc_load_sprite(paths, framedata);

    char* currpath;
    for (int i = 0; (currpath = paths[i]); i++) {
        free(currpath);
    }
    free(paths);

    return sprite;
}

Spritesheet* rsc_load_spritesheet(char* name, spritesheet_data* datas) {
    char* path = rsc_join_paths("sprites", name);

    size_t i;
    for (i = 0; datas[i].name || datas[i].framedata || datas[i].sprite; i++) {
        char* currpath = rsc_join_paths(path, datas[i].name);
        datas[i].sprite = rsc_load_sprite_dir(currpath, datas[i].framedata);
        free(currpath);
    }

    free(path);

    return Spritesheet_new(datas);
}
