#include <NIFF.h>

#include <NDynamic_t.h>

#include <math.h>

#include <stdio.h>

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

#if 0
    // Pass .5: Build the palette hash

    NINTLIST palette_hash[4][256];

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 256; j++) {
            NLIST_INIT(int32_t, palette_hash[i][j]);
        }
    }
#endif

    // Pass 1: Build the palette

#if 1
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
#else
    for (size_t i = 0; i < raw_size; i += channels) {
        bool found = true;
        NINTLIST common;
        NLIST_INIT(int, common);
        int* common_ptr;
        for (int c = 0; c < channels; c++) {
            NINTLIST list = palette_hash[c][raw[i + c]];
            if (list.size == 0) {
                found = false;
                break;
            }
            if (common.size == 0) {
                if (c != 0) {
                    found = false;
                    break;
                }
                NLIST_DUPLICATE(list, common);
                common_ptr = common.data;
                continue;
            }
            bool found_common = false;
            for (size_t j = 0; j < common.size; j++) {
                bool found_list = false;
                for (size_t x = 0; x < list.size; x++) {
                    if (common_ptr[0] == list.data[x]) {
                        found_list = true;
                        break;
                    }
                }
                if (found_list) {
                    found_common = true;
                    break;
                }
                common_ptr++;
                common.size--;
            }
        }
        if (!found) {
            for (int c = 0; c < channels; c++) {
                NLIST_PUSH(palette_hash[c][raw[i + c]], palette.size);
            }
            NLIST_PUSH(palette, *((int*)(raw + i)));
        }
        NLIST_DESTROY(common);
    }
#endif

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

#if 1
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
#else
    for (size_t i = 0; i < raw_size; i += channels) {
        NINTLIST common;
        NLIST_INIT(int, common);
        int* common_ptr;
        for (int c = 0; c < channels; c++) {
            NINTLIST list = palette_hash[c][raw[i + c]];
            if (list.size == 0) {
                break;
            }
            if (common.size == 0) {
                if (c != 0) {
                    break;
                }
                NLIST_DUPLICATE(list, common);
                common_ptr = common.data;
                continue;
            }
            bool found_common = false;
            for (size_t j = 0; j < common.size; j++) {
                bool found_list = false;
                for (size_t x = 0; x < list.size; x++) {
                    if (common_ptr[0] == list.data[x]) {
                        found_list = true;
                        break;
                    }
                }
                if (found_list) {
                    found_common = true;
                    break;
                }
                common_ptr++;
                common.size--;
            }
        }
        memcpy(ret_contents + (i / channels) * bpp, common_ptr, bpp);

        NLIST_DESTROY(common);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 256; j++) {
            NLIST_DESTROY(palette_hash[i][j]);
        }
    }
    NLIST_DESTROY(palette);
#endif

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
