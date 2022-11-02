#include "common.h"

extern IMG_BIN D_802ED970[];
extern IMG_BIN D_802F39D0[];
extern IMG_BIN D_802EE8D0[];

u8 D_802EB3D0[] = {
    11,  8,  8, 10,  9,  9,  9,  4,
     8,  8,  9,  9,  5,  9,  5, 10,
     9,  7,  9,  9,  9,  9,  9,  9,
     9,  9,  5,  5,  8,  9,  8,  9,
    10,  9,  9,  9,  9,  9,  9,  9,
     9,  7,  9,  9,  9,  9,  9,  9,
     9,  9,  9,  9,  9,  9,  9,  9,
     9,  9,  9,  7,  9,  6,  7,  9,
     6,  9,  8,  8,  9,  8,  8,  8,
     7,  4,  7,  8,  4,  9,  8,  7,
     9,  8,  8,  8,  8,  8,  8,  9,
     8,  8,  8,  7,  3,  7, 10,  7,
     9,  9,  9,  9,  9,  9,  9,  9,
     9,  7,  7,  7,  8,  9,  9,  9,
     9,  9,  9,  9,  9,  9,  9,  9,
     9,  9,  9,  8,  8,  8,  8,  8,
     6,  6,  6,  7,  9,  7,  7,  7,
     8,  8,  8,  8,  8,  6,  9,  7,
    11, 11, 11, 11, 12, 12, 11, 11,
    13, 13, 14, 14, 12, 13, 13, 13,
    13, 16,  9,  9,  5,  5,  0,  0,
};

MessageCharData D_802EB478[] = {
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 10,
        .baseHeightOffset = 0xFE,
    },
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharData D_802EB4B4[] = {
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 9,
        .baseHeightOffset = 0xFE,
    },
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 9,
        .baseHeightOffset = 0,
    },
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 9,
        .baseHeightOffset = 0,
    },
    {
        .raster = D_802EE8D0,
        .charWidthTable = D_802EB3D0,
        .monospaceWidth = 9,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharset D_802EB4F0 = {
    .texSize = { 16, 16 },
    .unk_02 = 14,
    .newLineY = 16,
    .charRasterSize = 128,
    .rasters = D_802EB478
};

MessageCharset D_802EB4FC = {
    .texSize = { 16, 16 },
    .unk_02 = 14,
    .newLineY = 16,
    .charRasterSize = 128,
    .rasters = D_802EB4B4
};

u8 D_802EB508[] = {
    8, 8, 8, 9, 8, 8, 8, 8,
    5, 8, 9, 8,10, 8, 8, 9,
    8, 9, 8, 8, 8, 8,10, 9,
    9, 8, 4, 3, 4, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 9,10,
    10, 0, 0, 0
};

u8 D_802EB534[] = {
    9, 9, 8, 8, 7, 7, 8, 7,
    3, 7, 7, 7, 8, 7, 8, 8,
    8, 7, 7, 8, 7, 7, 8, 8,
    8, 7, 4, 3, 4, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 0, 0, 0
};

MessageCharData D_802EB560[] = {
    {
        .raster = D_802ED970,
        .charWidthTable = D_802EB508,
        .monospaceWidth = 14,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharData D_802EB578[] = {
    {
        .raster = D_802F39D0,
        .charWidthTable = D_802EB534,
        .monospaceWidth = 10,
        .baseHeightOffset = 0,
    },
    {}
};

MessageCharset D_802EB590 = {
    .texSize = { 12, 15 },
    .unk_02 = 14,
    .newLineY = 16,
    .charRasterSize = 96,
    .rasters = D_802EB560
};

MessageCharset D_802EB59C = {
    .texSize = { 12, 12 },
    .unk_02 = 10,
    .newLineY = 10,
    .charRasterSize = 72,
    .rasters = D_802EB578
};

MessageCharset* gMsgCharsets[] = {
    &D_802EB4F0,
    &D_802EB4FC,
    &D_802EB4FC,
    &D_802EB590,
    &D_802EB59C
};
