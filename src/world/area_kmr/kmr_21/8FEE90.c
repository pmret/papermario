#include "kmr_21.h"

extern u8 D_80240333_8FF1B3;
extern s32 D_80240334_8FF1B4;
extern Gfx D_80240338_8FF1B8[];

// BSS
extern IMG_PTR kmr_21_802407F4;

void func_80240010_8FEE90(void) {
    s32 i;

    gSPDisplayList(gMasterGfxPos++, D_80240338_8FF1B8);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80240333_8FF1B3);
    gDPPipeSync(gMasterGfxPos++);

    for (i = 0; i < 56; i++) {
        gDPLoadTextureTile(gMasterGfxPos++, &kmr_21_802407F4[1600 * i], G_IM_FMT_RGBA, G_IM_SIZ_32b, 200, 112,
                           0, 0, 199, 1, 0,
                           G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMasterGfxPos++, 60 * 4, (i * 2 + D_80240334_8FF1B4) * 4, 260 * 4, ((i * 2 + 2) + D_80240334_8FF1B4) * 4,
                            G_TX_RENDERTILE, 0, 0, 1024, 1024);
    }
    gDPPipeSync(gMasterGfxPos++);
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_21/8FEE90", func_80240210_8FF090);

INCLUDE_ASM(s32, "world/area_kmr/kmr_21/8FEE90", func_80240298_8FF118);

INCLUDE_ASM(s32, "world/area_kmr/kmr_21/8FEE90", func_802402B4_8FF134);

INCLUDE_ASM(s32, "world/area_kmr/kmr_21/8FEE90", func_802402C8_8FF148);
