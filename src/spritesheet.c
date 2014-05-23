#include "spritesheet.h"

#include "sprite.h"
#include "yasl/yutil.h"

Spritesheet* Spritesheet_new(spritesheet_data* sprites) {
    Spritesheet* sheet = malloc(sizeof(Spritesheet));
    sheet->sprites = sprites;
    sheet->id = 0;
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

void Spritesheet_draw(Spritesheet* sheet, Pos2i pos) {
    Sprite_draw(sheet->sprites[sheet->id].sprite, pos);
}
