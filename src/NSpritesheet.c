#include "NSpritesheet.h"

#include "NSprite.h"

#include <stdlib.h>

NSpritesheet* NSpritesheet_new(NSpritesheet_data* sprites) {
    NSpritesheet* sheet = malloc(sizeof(NSpritesheet));
    sheet->sprites = sprites;
    return sheet;
}

void NSpritesheet_destroy(NSpritesheet* sheet) {
    NSprite* sprite;
    for (size_t i = 0; (sprite = sheet->sprites[i].sprite); i++) {
        NSprite_destroy(sprite);
    }
    free(sheet);
}


void NSpritesheet_update(NSpritesheet* sheet) {
    NSprite* sprite;
    for (size_t i = 0; (sprite = sheet->sprites[i].sprite); i++) {
        NSprite_update(sprite);
    }
}

void NSpritesheet_draw(NSpritesheet* sheet, size_t id, NPos2i pos, bool flip) {
    NSprite_draw(sheet->sprites[id].sprite, pos, flip);
}
