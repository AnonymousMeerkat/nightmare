#include <Nightmare.h>

/*NShader_attrib image_attribs[] = {
    {0, "vertex_position"},
    {1, "vertex_UV"}
};
NShader_info _G_shader_infos[] = {
    {"image", image_attribs},
    {NULL, NULL}
};
NShader_info* G_shader_infos = _G_shader_infos;

char* _G_image_infos[] = {
    NULL
};
char** G_image_infos = _G_image_infos;

NSprite_framedata walk_data[] = {
    {1, 100, 1},
    {2, 100, 1},
    {3, 100, 1},
    {4, 100, 1},
    {5, 100, 1},
    {6, 100, 1},
    {0,   0, 0}
};
NSprite_framedata trot_data[] = {
    {0, 100, 1},
    {1, 100, 1},
    {2, 100, 1},
    {3, 100, 1},
    {4, 100, 1},
    {5, 100, 1},
    {0,   0, 0}
};
NSpritesheet_data player_data[] = {
    {"walk", walk_data, NULL},
    {"trot", trot_data, NULL},
    {NULL, NULL, NULL},
};
NSpritesheet_info _G_spritesheet_infos[] = {
    {"player", player_data},
    {NULL, NULL}
};
NSpritesheet_info* G_spritesheet_infos = _G_spritesheet_infos;*/

void Game_init() {
    Ndebug("Initing!");
}

void Game_destroy() {
    Ndebug("Destroying!");
}

void Game_loop() {
    NSpritesheet_update(N_spritesheets[0]);
    NSpritesheet_draw(N_spritesheets[0], 0, Npos2i(50, 50), 1);
}
