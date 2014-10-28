#include <NIFF.h>

#include <NDynamic_t.h>
#include <math.h>

NIFF_t* NIFF_from_raw(uchar* raw, uint8_t channels, uint32_t x_size, uint32_t y_size, uint32_t z_size) {
    NIFF_t head = {
        .magic = NIFF_MAGIC,
        .x_size = x_size,
        .y_size = y_size,
        .z_size = z_size,
        .channels = channels
    };

    size_t raw_size = x_size * y_size * z_size * channels;

    NLIST_NEW(int32_t, palette);

    // Pass 1: Build the palette

    for (size_t i = 0; i < raw_size; i += channels) {
        int32_t value = 0;
        memcpy(&value, raw + i, channels);

        bool continueme = false;
        for (size_t j = 0; j < palette.size; j++) {
            if (palette.data[j] == value) {
                continueme = true;
                break;
            }
        }
        if (continueme) {
            continue;
        }
        NLIST_PUSH(palette, value);
    }

    // Pass 2: Encode it

    uint32_t palette_size_copy = palette.size;
    palette_size_copy--;
    uint8_t bpp = 0;
    while (palette_size_copy > 0) {
        bpp++;
        palette_size_copy >>= 8;
    }

    head.bpp = bpp;
    head.palette_size = palette.size;

    size_t palette_csize = palette.size * 4;
    size_t raw_bsize = x_size * y_size * z_size * bpp;

    size_t contents_size = palette_csize + raw_bsize;

    NIFF_t* ret = malloc(sizeof(NIFF_t) + contents_size);

    memcpy(ret, &head, sizeof(NIFF_t));

    int32_t* palette_contents = (int32_t*)ret->contents;

    for (size_t i = 0; i < palette.size; i++) {
        palette_contents[i] = palette.data[i];
    }

    uchar* ret_contents = ret->contents + palette_csize;

    for (size_t i = 0; i < raw_size; i += channels) {
        int32_t value = 0;
        memcpy(&value, raw + i, channels);

        bool continueme = false;
        for (size_t j = 0; j < palette.size; j++) {
            if (palette.data[j] == value) {
                memcpy(ret_contents + (i / channels) * bpp, &j, bpp);
                continueme = true;
                break;
            }
        }
        if (continueme) {
            continue;
        }
    }

    return ret;
}

uchar* NIFF_to_raw(NIFF_t* niff) {
    int32_t* palette = (int32_t*) niff->contents;
    uchar* contents = niff->contents + (niff->palette_size * 4);

    uchar bpp = niff->bpp;

    size_t size = niff->x_size * niff->y_size * niff->z_size;

    uchar* ret = malloc(size * niff->channels);

    for (size_t i = 0; i < size * bpp; i += bpp) {
        uint32_t pid = 0;
        memcpy(&pid, contents + i, bpp);

        int32_t val = palette[pid];

        memcpy(ret + (i/bpp) * niff->channels, &val, niff->channels);
    }

    return ret;
}
