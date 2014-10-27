#ifndef _NME_NIFF_H
#define _NME_NIFF_H

#include <NUtil.h>
#include <NTypes.h>

#define NIFF_MAGIC 0x1EA19190

NSTRUCT(NIFF_t, {
    int32_t magic;
    uint32_t x_size;
    uint32_t y_size;
    uint32_t z_size;
    uint8_t channels;
    uint8_t bpp;
    uint32_t palette_size;

    uchar contents[];
});

#define NIFF_SIZE(x) ((x).x_size * (x).y_size * (x).z_size * (x).bpp)

NIFF_t* NIFF_from_raw(uchar* raw, uint8_t channels, uint32_t x_size, uint32_t y_size, uint32_t z_size);
uchar* NIFF_to_raw(NIFF_t* niff);

#endif
