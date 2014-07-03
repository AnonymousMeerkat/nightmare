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

#include "NRsc.h"

#include "NTypes.h"
//#include "NDll.h"
#include "NShader.h"
#include "NImage.h"
#include "NLog.h"
#include "NSprite.h"
#include "NSpritesheet.h"
#include "NLevel.h"
#include "NDynamic_t.h"

#include <string.h>

/*NDLL* NRsc_load_dll() {
    char* path = NRsc_get_path(NDLL_ADD_EXT("libgame"));
    NDLL* dll = NDLL_new(path);
    free(path);

    return dll;
}*/

NShader* NRsc_load_shader(char* name, NShader_attrib* attribs) {
    Ndebug("Loading paths");
    size_t pathlen = strlen(name) + 6;
    char* base_path = malloc(pathlen);
    strcpy(base_path, "glsl" N_SLASH);
    strcat(base_path, name);

    char* vertex_path = malloc(pathlen + 12);
    strcpy(vertex_path, base_path);
    strcat(vertex_path, N_SLASH "vertex.glsl");
    char* vertex_file = NRsc_read_file(vertex_path);
    free(vertex_path);

    char* fragment_path = malloc(pathlen + 14);
    strcpy(fragment_path, base_path);
    strcat(fragment_path, N_SLASH "fragment.glsl");
    char* fragment_file = NRsc_read_file(fragment_path);
    free(fragment_path);

    free(base_path);

    Ndebug("Loading shader");
    NShader* shader = NShader_new(vertex_file, fragment_file, attribs);
    free(vertex_file);
    free(fragment_file);

    return shader;
}

NImage* NRsc_load_image(char* name) {
    //size_t pathlen = strlen(name) + 5;
    Ndebug(name);
    size_t pathlen = strlen(name) + 1;
    char* simplepath = malloc(pathlen);
    /*strcpy(simplepath, "img" SLASH);
    strcat(simplepath, name);*/
    strcpy(simplepath, name);

    char* path = NRsc_get_path(simplepath);

    free(simplepath);

    NImage* ret = NImage_new(NImage_IMAGE);

    if (!ret) {
        Nerror("Error creating image!");
        ret = NULL;
        goto end;
    }
    if (!NImage_load(ret, path)) {
        Nerror("Error loading image!");
        NImage_destroy(ret);
        ret = NULL;
        goto end;
    }

end:
    free(path);

    return ret;
}

NSprite* NRsc_load_sprite(char** paths, NSprite_framedata* framedata) {
    NSprite* ret = NULL;
    bool okay = true;
    NLIST_NEW(NImage*, images);

    NImage* temp;
    char* currpath;
    for (size_t i = 0; (currpath = paths[i]); i++) {
        temp = NRsc_load_image(currpath);
        if (!temp) {
            okay = false;
            break;
        }
        NLIST_PUSH(images, temp);
    }

    if (!okay) {
        NLIST_DESTROY(images);
        goto end;
    }

    ret = NSprite_new(images.data, framedata);

end:
    return ret;
}

NSprite* NRsc_load_sprite_dir(char* path, NSprite_framedata* framedata) {
    char** names = NRsc_ls(path);
    size_t names_count;
    NRLIST_COUNT(names, names_count);
    char** paths = malloc(sizeof(char*) * (names_count + 1));

    char* currname;
    for (size_t i = 0; (currname = names[i]); i++) {
        char* noext = NRsc_remove_ext(currname);
        int ournumber = atoi(noext);
        free(noext);
        // XXX: Buffer overflow attack imminent here lol
        paths[ournumber] = NRsc_join_paths(path, currname);
    }

    paths[names_count] = NULL;

    NRsc_ls_free(names);

    NSprite* sprite = NRsc_load_sprite(paths, framedata);

    char* currpath;
    for (int i = 0; (currpath = paths[i]); i++) {
        free(currpath);
    }
    free(paths);

    return sprite;
}

NSpritesheet* NRsc_load_spritesheet(char* name, NSpritesheet_data* datas) {
    char* path = NRsc_join_paths("sprites", name);

    for (size_t i = 0; datas[i].name || datas[i].framedata || datas[i].sprite; i++) {
        char* currpath = NRsc_join_paths(path, datas[i].name);
        datas[i].sprite = NRsc_load_sprite_dir(currpath, datas[i].framedata);
        free(currpath);
    }

    free(path);

    return NSpritesheet_new(datas);
}

NLevel* NRsc_load_level(char* name, NLevel_layer_data* datas) {
    bool okay = true;

    char* path = NRsc_join_paths("levels", name);
    char** names = NRsc_ls(path);
    size_t names_count;
    NRLIST_COUNT(names, names_count);

    NLevel_layer* layers = malloc(sizeof(NLevel_layer) * (names_count + 1));
    int* numbers = malloc(sizeof(int) * names_count);

    NPosz offset = 0x7F;

    for (size_t i = 0; i < names_count; i++) {
        char* noext = NRsc_remove_ext(names[i]);
        int ournum = atoi(noext);
        numbers[i] = ournum;
        free(noext);
        offset = NMIN(ournum, offset);
    }

    for (size_t i = 0; i < names_count; i++) {
        NLevel_layer layer;

        char* currpath = NRsc_join_paths(path, names[i]);
        NImage* image = NRsc_load_image(currpath);
        free(currpath);
        if (!image) {
            okay = false;
            break;
        }
        layer.base = image;
        layer.hotspots = datas[i].hotspots; // Since it's a global .... :D
        layer.z_size = datas[i].z_size;

        layers[numbers[i] - offset] = layer;
    }

    NLevel_layer blank = {NULL, NULL, 0};
    layers[names_count] = blank;

    free(path);
    free(numbers);
    NRsc_ls_free(names);

    if (!okay) {
        return NULL;
    }

    return NLevel_new(layers, -offset);
}


void NRsc_load_shaders(NShader_info* infos) {
    NLIST_NEW_FROM_ARR(NShader*, shaders, N_shaders);
    for (size_t i = 0; infos[i].name; i++) {
        NLIST_PUSH(shaders, NRsc_load_shader(infos[i].name, infos[i].attribs));
        //Ndebug("%p", shaders.data[i]);
    }
    N_shaders = shaders.data;
    //Ndebug("%u", shaders.data[0]->shader_handle);
}

void NRsc_load_images(char** names) {
    NLIST_NEW_FROM_ARR(NImage*, images, N_images);
    for (size_t i = 0; names[i]; i++) {
        char* path = NRsc_join_paths("img" N_SLASH, names[i]);
        NLIST_PUSH(images, NRsc_load_image(path));
        free(path);
    }
    N_images = images.data;
}

void NRsc_load_spritesheets(NSpritesheet_info* infos) {
    NLIST_NEW_FROM_ARR(NSpritesheet*, spritesheets, N_spritesheets);
    for (size_t i = 0; infos[i].name; i++) {
        NLIST_PUSH(spritesheets, NRsc_load_spritesheet(infos[i].name, infos[i].datas));
    }
    N_spritesheets = spritesheets.data;
}

void NRsc_load_levels(NLevel_info* infos) {
    NLIST_NEW_FROM_ARR(NLevel*, levels, N_levels);
    for (size_t i = 0; infos[i].name; i++) {
        NLIST_PUSH(levels, NRsc_load_level(infos[i].name, infos[i].datas));
    }
    N_levels = levels.data;
}


void NRsc_free_shaders() {
    for (size_t i = 0; N_shaders[i]; i++) {
        NShader_destroy(N_shaders[i]);
    }
    free(N_shaders);
    N_shaders = NULL;
}

void NRsc_free_images() {
    for (size_t i = 0; N_images[i]; i++) {
        NImage_destroy(N_images[i]);
    }
    free(N_images);
    N_images = NULL;
}

void NRsc_free_spritesheets() {
    for (size_t i = 0; N_spritesheets[i]; i++) {
        NSpritesheet_destroy(N_spritesheets[i]);
    }
    free(N_spritesheets);
    N_spritesheets = NULL;
}

void NRsc_free_levels() {
    for (size_t i = 0; N_levels[i]; i++) {
        NLevel_destroy(N_levels[i]);
    }
    free(N_levels);
    N_levels = NULL;
}
