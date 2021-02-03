#include "end_01.h"

extern u8 D_80245D37_E0B097;

INCLUDE_ASM(s32, "world/area_end/end_01/E07C20", func_802428C0_E07C20);

INCLUDE_ASM(s32, "world/area_end/end_01/E07C20", func_80242900_E07C60);

INCLUDE_ASM(s32, "world/area_end/end_01/E07C20", func_80242978_E07CD8);

INCLUDE_ASM(s32, "world/area_end/end_01/E07C20", func_80242A68_E07DC8);

INCLUDE_ASM(s32, "world/area_end/end_01/E07C20", func_80242B68_E07EC8);

INCLUDE_ASM(s32, "world/area_end/end_01/E07C20", func_80242C68_E07FC8);

void func_80242C94_E07FF4(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, SHADE, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, SHADE, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80245D37_E0B097);
}
