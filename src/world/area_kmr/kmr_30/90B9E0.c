#include "kmr_30.h"

extern u8 D_80240C0F;

INCLUDE_ASM(s32, "world/area_kmr/kmr_30/90B9E0", func_80240310_90B9E0);

INCLUDE_ASM(s32, "world/area_kmr/kmr_30/90B9E0", func_8024045C_90BB2C);

void func_80240488_90BB58(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80240C0F);
}
