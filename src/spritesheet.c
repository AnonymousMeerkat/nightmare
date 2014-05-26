#include "spritesheet.h"

#include "sprite.h"
#include "yasl/yutil.h"

Spritesheet* Spritesheet_new(spritesheet_data* sprites) {
    Spritesheet* sheet = malloc(sizeof(Spritesheet));
    sheet->sprites = sprites;
    return sheet;
}

void Spritesheet_destroy(Spritesheet* sheet) {
    Sprite* sprite;
    for (int i = 0; (sprite = sheet->sprites[i].sprite); i++) {
        Sprite_destroy(sprite);
    }
    free(sheet);
}


void Spritesheet_update(Spritesheet* sheet) {
    Sprite* sprite;
    for (int i = 0; (sprite = sheet->sprites[i].sprite); i++) {
        Sprite_update(sprite);
    }
}

void Spritesheet_draw(Spritesheet* sheet, size_t id, Pos2i pos, bool flip) {
    Sprite_draw(sheet->sprites[id].sprite, pos, flip);
}
