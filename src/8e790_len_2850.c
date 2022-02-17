#include "common.h"
typedef struct DefaultWindowStyle {
    /* 0x00 */ u8 bgIndex;
    /* 0x01 */ u8 cornersIndex;
    /* 0x02 */ u8 unk_2;
    /* 0x03 */ Color_RGBA8 color1;
    /* 0x07 */ Color_RGBA8 color2;
} DefaultWindowStyle; // size = 0x0B

typedef struct UnkDrawStruct {
    Vtx vert[16];
} UnkDrawStruct; // size = 0x100

static UnkDrawStruct D_8010D6B0[];

DefaultWindowStyle D_801098E0[] = {
    {
        .bgIndex = 1,
        .cornersIndex = 0,
        .unk_2 = 0,
        .color1 = { .r = 200, .g = 191, .b = 164, .a = 255 },
        .color2 = { .r = 128, .g = 128, .b = 128, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 1,
        .unk_2 = 1,
        .color1 = { .r = 255, .g = 200, .b = 128, .a = 255 },
        .color2 = { .r = 128, .g = 128, .b = 128, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 2,
        .unk_2 = 1,
        .color1 = { .r = 232, .g = 196, .b = 77, .a = 255 },
        .color2 = { .r = 163, .g = 123, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 0,
        .cornersIndex = 3,
        .unk_2 = 1,
        .color1 = { .r = 226, .g = 225, .b = 216, .a = 255 },
        .color2 = { .r = 217, .g = 208, .b = 201, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 61, .g = 74, .b = 188, .a = 255 },
        .color2 = { .r = 0, .g = 25, .b = 28, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 5,
        .unk_2 = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 90, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 6,
        .unk_2 = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 99, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 215, .g = 191, .b = 116, .a = 255 },
        .color2 = { .r = 132, .g = 70, .b = 50, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 215, .g = 191, .b = 116, .a = 255 },
        .color2 = { .r = 132, .g = 70, .b = 50, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 141, .g = 143, .b = 255, .a = 255 },
        .color2 = { .r = 43, .g = 69, .b = 102, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .unk_2 = 1,
        .color1 = { .r = 141, .g = 143, .b = 255, .a = 255 },
        .color2 = { .r = 43, .g = 69, .b = 102, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 170, .g = 208, .b = 128, .a = 255 },
        .color2 = { .r = 71, .g = 123, .b = 83, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .unk_2 = 1,
        .color1 = { .r = 170, .g = 208, .b = 128, .a = 255 },
        .color2 = { .r = 71, .g = 123, .b = 83, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 200, .g = 200, .b = 90, .a = 255 },
        .color2 = { .r = 140, .g = 140, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 8,
        .unk_2 = 1,
        .color1 = { .r = 200, .g = 200, .b = 90, .a = 255 },
        .color2 = { .r = 140, .g = 140, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 235, .g = 230, .b = 119, .a = 255 },
        .color2 = { .r = 142, .g = 90, .b = 37, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 142, .g = 212, .b = 236, .a = 255 },
        .color2 = { .r = 67, .g = 98, .b = 69, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 167, .g = 151, .b = 119, .a = 255 },
        .color2 = { .r = 98, .g = 55, .b = 154, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 7,
        .unk_2 = 1,
        .color1 = { .r = 17, .g = 151, .b = 29, .a = 255 },
        .color2 = { .r = 8, .g = 55, .b = 14, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 7,
        .unk_2 = 1,
        .color1 = { .r = 110, .g = 110, .b = 200, .a = 255 },
        .color2 = { .r = 10, .g = 10, .b = 100, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 181, .g = 60, .b = 60, .a = 255 },
        .color2 = { .r = 76, .g = 10, .b = 0, .a = 255 }
    },
    {
        .bgIndex = 1,
        .cornersIndex = 4,
        .unk_2 = 1,
        .color1 = { .r = 174, .g = 227, .b = 235, .a = 255 },
        .color2 = { .r = 76, .g = 110, .b = 60, .a = 255 }
    },
    {
        .bgIndex = 0,
        .cornersIndex = 3,
        .unk_2 = 1,
        .color1 = { .r = 126, .g = 125, .b = 216, .a = 255 },
        .color2 = { .r = 217, .g = 108, .b = 201, .a = 255 }
    }
};

#include "ui/corners9.png.inc.c"
#include "ui/corners8.png.inc.c"
#include "ui/corners6.png.inc.c"
#include "ui/corners7.png.inc.c"
#include "ui/corners3.png.inc.c"
#include "ui/corners5.png.inc.c"
#include "ui/corners4.png.inc.c"
#include "ui/background1.png.inc.c"
#include "ui/corners1.png.inc.c"
#include "ui/corners2.png.inc.c"
#include "ui/background2.png.inc.c"

WindowBackground D_8010BAE8[] = {
    {
        .imgData = ui_background1_png,
        .packedTileFormat = 0x40,
        .width = 16,
        .height = 16,
        .unk_07 = { 0, 0, 0, 0},
        .size = 128
    },
    {
        .imgData = ui_background2_png,
        .packedTileFormat = 0x40,
        .width = 16,
        .height = 1,
        .unk_07 = { 0, 0, 0, 0},
        .size = 8
    }
};

WindowCorners D_8010BB00[] = {
    {
        .imgData = ui_corners1_png,
        .packedTileFormat = 0x31,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners2_png,
        .packedTileFormat = 0x40,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners3_png,
        .packedTileFormat = 0x31,
        .size1 = { 16, 32},
        .size2 = { 16, 32},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners4_png,
        .packedTileFormat = 0x31,
        .size1 = { 8, 8},
        .size2 = { 8, 8},
        .size3 = { 8, 8},
        .size4 = { 8, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners5_png,
        .packedTileFormat = 0x31,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners6_png,
        .packedTileFormat = 0x31,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners7_png,
        .packedTileFormat = 0x31,
        .size1 = { 16, 8},
        .size2 = { 16, 8},
        .size3 = { 16, 8},
        .size4 = { 16, 8},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners8_png,
        .packedTileFormat = 0x31,
        .size1 = { 24, 24},
        .size2 = { 24, 24},
        .size3 = { 24, 24},
        .size4 = { 24, 24},
        .unk_0D = { 0, 0, 0}
    },
    {
        .imgData = ui_corners9_png,
        .packedTileFormat = 0x31,
        .size1 = { 16, 16},
        .size2 = { 16, 16},
        .size3 = { 16, 16},
        .size4 = { 16, 16},
        .unk_0D = { 0, 0, 0}
    }
};

Gfx D_8010BB90[] = {
    gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL1, TEXEL0, ENVIRONMENT, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0, 0, 0, 0, TEXEL1, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED),
    gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE, 0, TEXEL1, 0, PRIMITIVE, 0, TEXEL0, ENVIRONMENT, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetCombineLERP(TEXEL0, 0, TEXEL1, 0, TEXEL1, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED)
};
s32 D_8010BBB0 = 0;
s32 D_8010BBB4 = 0;
Vp D_8010BBB8 = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 }
    }
};

#include "vtx/drawbox1.vtx.inc.c"

/*
| 0.0  0.0  0.0  0.0|
| 0.0  0.0  0.0  0.0|
| 0.0  0.0  0.0  0.0|
|-6.0  0.0  0.0  0.0|
*/
Mtx D_8010BC08 = {
    .m = {
        // integer portion
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000,
          0xFFFA0000, 0x00000000 },
        //fractional portion
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 },
        { 0x00000000, 0x00000000,
          0x00000000, 0x00000000 }
    }
};

INCLUDE_ASM(void, "8e790_len_2850", draw_box, s32 flags, WindowStyle windowStyle, s32 posX, s32 posY, s32 posZ, s32 width,
            s32 height, s32 opacity, s32 darkening, f32 scaleX, f32 scaleY, f32 rotX, f32 rotY, f32 rotZ,
            void (*fpDrawContents)(s32),s32 drawContentsArg0, Matrix4f rotScaleMtx, s32 translateX, s32 translateY,
            f32 (*outMtx)[4]);

