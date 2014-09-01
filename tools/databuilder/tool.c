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

#include "../NKTool.h"

#include <jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define error(...) fprintf(stderr, __VA_ARGS__)
#define BUFSIZE 8192

const char Fheader[] =
"#include <NShader.h>\n"
"#include <NSprite.h>\n"
"#include <NSpritesheet.h>\n"
"#include <NLevel.h>\n"
"\n"
"// AUTOMATICALLY GENERATED\n"
"// DO NOT MODIFY!\n"
"\n"
;

void showhelp(char* name) {
    printf("Usage: %s input output\n", name);
}

char* read_file(char* path) {
    FILE* file = fopen(path, "r");
    fseek (file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind (file);
    char* ret = malloc(file_size + 1);
    memset(ret, 0, file_size + 1);
    size_t n_read = fread(ret, 1, file_size, file);
    if (n_read != file_size) {
        error("Error reading file\n");
        return NULL;
    }
    fclose(file);
    return ret;
}

int databuilder(int argc, char** argv) {
    char* input = NULL;
    FILE* output = stdout;

    if (argc >= 3) {
        output = fopen(argv[2], "w");
    }

    if (argc < 2) {
        showhelp(argv[0]);
        return 1;
    }

    /*while ((c = getopt(argc, argv, "ho:")) != -1) {
        switch (c) {
            case 'h':
                showhelp(argv[0]);
                return 0;
            case 'o':
                output = fopen(optarg, "w");
                break;
        }
    }*/

    input = argv[1];

    if (access(input, F_OK) == -1) {
        error("%s: No such file or directory\n", input);
        return 2;
    }

    char* contents = read_file(input);

    json_t* root;
    json_error_t error;

    root = json_loads(contents, 0, &error);

    free(contents);

    if (!root) {
        error("Error parsing file on line %d: %s\n", error.line, error.text);
        return 3;
    }

    if (!json_is_object(root)) {
        error("JSON root is not an object\n");
        json_decref(root);
        return 3;
    }

    size_t index;
    json_t* value;

    char FINAL[BUFSIZE];

    strcpy(FINAL, Fheader);

    const char* title = json_string_value(json_object_get(root, "title"));
    char TITLE_TEMP[BUFSIZE];
    sprintf(TITLE_TEMP, "char* N_win_title = \"%s\";\n\n", title);

    strcat(FINAL, TITLE_TEMP);

    char shader_attribs[BUFSIZE];
    shader_attribs[0] = 0;

    char shader_infos[BUFSIZE];
    sprintf(shader_infos, "NShader_info _G_shader_infos[] = {\n");

    json_array_foreach(json_object_get(root, "shaders"), index, value) {
        char temp[BUFSIZE];
        const char* name = json_string_value(json_array_get(value, 0));
        sprintf(temp, "NShader_attrib _shader_%s_attribs[] = {\n", name);
        strcat(shader_attribs, temp);

        json_t* attribs = json_array_get(value, 1);
        size_t ind;
        json_t* attrib;

        json_array_foreach(attribs, ind, attrib) {
            sprintf(temp, "\t{%lld, \"%s\"},\n", json_integer_value(json_array_get(attrib, 0)),
                    json_string_value(json_array_get(attrib, 1)));
            strcat(shader_attribs, temp);
        }
        strcat(shader_attribs, "\t{0, NULL}\n};\n");

        sprintf(temp, "\t{\"%s\", _shader_%s_attribs},\n", name, name);
        strcat(shader_infos, temp);
    }

    strcat(shader_infos, "\t{NULL, NULL}\n};\nNShader_info* G_shader_infos = _G_shader_infos;\n\n");

    strcat(FINAL, shader_attribs);
    strcat(FINAL, shader_infos);

    strcat(FINAL, "char* _G_image_infos[] = {\n");

    json_array_foreach(json_object_get(root, "images"), index, value) {
        strcat(FINAL, "\t\"");
        strcat(FINAL, json_string_value(value));
        strcat(FINAL, "\",\n");
    }

    strcat(FINAL, "\tNULL\n};\nchar** G_image_infos = _G_image_infos;\n\n");

    char* sprites = shader_attribs;
    sprites[0] = 0;
    char* ss_infos = shader_infos;
    strcpy(ss_infos, "NSpritesheet_info _G_spritesheet_infos[] = {\n");

    json_array_foreach(json_object_get(root, "sprites"), index, value) {
        char ssdata[BUFSIZE];
        char framedata[BUFSIZE];
        char temp[BUFSIZE];

        framedata[0] = 0;

        const char* name = json_string_value(json_array_get(value, 0));

        sprintf(ssdata, "NSpritesheet_data _ss_%s_data[] = {\n", name);

        sprintf(temp, "\t{\"%s\", _ss_%s_data},\n", name, name);
        strcat(ss_infos, temp);

        size_t ind;
        json_t* fdm;

        json_array_foreach(json_array_get(value, 1), ind, fdm) {
            const char* fdname = json_string_value(json_array_get(fdm, 0));

            sprintf(temp, "NSprite_framedata _ss_%s_%s_%zu_data[] = {\n", name, fdname, ind);
            strcat(framedata, temp);

            sprintf(temp, "\t{\"%s\", _ss_%s_%s_%zu_data, NULL},\n", fdname, name, fdname, ind);
            strcat(ssdata, temp);

            size_t i;
            json_t* fdarr;

            json_array_foreach(json_array_get(fdm, 1), i, fdarr) {
                sprintf(temp, "\t{%lld, %lld, 1},\n", json_integer_value(json_array_get(fdarr, 0)),
                        json_integer_value(json_array_get(fdarr, 1)));
                strcat(framedata, temp);
            }

            strcat(framedata, "\t{0, 0, 0}\n};\n");
        }

        strcat(ssdata, "\t{NULL, NULL, NULL}\n};\n");

        strcat(sprites, framedata);
        strcat(sprites, ssdata);
    }

    strcat(ss_infos, "\t{NULL, NULL}\n};\nNSpritesheet_info* G_spritesheet_infos = _G_spritesheet_infos;\n\n");

    strcat(FINAL, sprites);
    strcat(FINAL, ss_infos);

    strcpy(ss_infos, "NLevel_info _G_level_infos[] = {\n");

    json_array_foreach(json_object_get(root, "levels"), index, value) {
        char lyrsdata[BUFSIZE];
        lyrsdata[0] = 0;
        char lvldata[BUFSIZE];
        char temp[BUFSIZE];

        const char* name = json_string_value(json_array_get(value, 0));

        sprintf(lvldata, "NLevel_layer_data _lvl_%s_data[] = {\n", name);

        sprintf(temp, "\t{\"%s\", _lvl_%s_data},\n", name, name);
        strcat(ss_infos, temp);

        size_t ind;
        json_t* lyrm;

        json_array_foreach(json_array_get(value, 1), ind, lyrm) {
            char lyrdata[BUFSIZE];
            int num = json_integer_value(json_array_get(lyrm, 0));
            char* minus = "";
            if (num < 0) {
                minus = "m";
                num = -num;
            }

            int z_size = 20;
            json_t* z_size_v = json_object_get(json_array_get(lyrm, 1), "z_size");
            if (z_size_v) {
                z_size = json_integer_value(z_size_v);
            }

            sprintf(temp, "\t{_lvl_%s_%s_%i_hotspots, %i},\n", name, minus, num, z_size);
            strcat(lvldata, temp);

            sprintf(lyrdata, "NLevel_hotspot _lvl_%s_%s_%i_hotspots[] = {\n", name, minus, num);

            json_t* hotspots = json_object_get(json_array_get(lyrm, 1), "hotspots");
            if (hotspots) {
                size_t i;
                json_t* htspt;

                json_array_foreach(hotspots, i, htspt) {
                    json_t* areav = json_object_get(htspt, "area");
#define area_value(n) json_integer_value(json_array_get(areav, n))
                    long long int area[] = {
                        area_value(0),
                        area_value(1),
                        area_value(2),
                        area_value(3),
                    };

                    char* type = "N_LEVEL_HOTSPOT_CLICK";
                    if (strcmp(json_string_value(json_object_get(htspt, "type")), "location") == 0) {
                        type = "N_LEVEL_HOTSPOT_LOCATION";
                    }

                    sprintf(temp, "\t{{%lld, %lld, %lld, %lld}, %s, %lld, \"%s\"},\n",
                        area[0], area[1], area[2], area[3],
                        type,
                        json_integer_value(json_object_get(htspt, "action")),
                        json_string_value(json_object_get(htspt, "data"))
                    );

                    strcat(lyrdata, temp);
                }
            }

            strcat(lyrdata, "\t{{0, 0, 0, 0}, 0, 0, NULL}\n};\n");

            strcat(lyrsdata, lyrdata);
        }

        strcat(lvldata, "\t{NULL, 0}\n};\n");

        strcat(FINAL, lyrsdata);
        strcat(FINAL, lvldata);
    }

    strcat(ss_infos, "\t{NULL, NULL}\n};\nNLevel_info* G_level_infos = _G_level_infos;\n\n");
    strcat(FINAL, ss_infos);

    fputs(FINAL, output);

    if (output != stdout) {
        fclose(output);
    }

    return 0;
}

NKTool databuilder_tool = {
    .command = "databuilder",
    .tool = databuilder
};
