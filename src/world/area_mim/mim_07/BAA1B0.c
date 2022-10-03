#include "mim_07.h"

extern s32 D_80241680_BAB7C0;
extern s32 D_80241684_BAB7C4;
extern s32 D_80241688_BAB7C8;

#include "world/common/SetForeverForestFog.inc.c"

void func_802400D8_BAA218(s32 index) {
    switch (D_80241680_BAB7C0) {
        case 1:
            D_80241688_BAB7C8 = 0;
            D_80241680_BAB7C0 = 2;
            break;
        case 2:
            D_80241688_BAB7C8 += 10;
            if (D_80241688_BAB7C8 >= 256) {
                D_80241688_BAB7C8 = 255;
                D_80241684_BAB7C4 = 50;
                D_80241680_BAB7C0 = 3;
            }
            break;
        case 3:
            D_80241684_BAB7C4--;
            if (D_80241684_BAB7C4 < 0) {
                D_80241684_BAB7C4 = 0;
                D_80241680_BAB7C0 = 4;
            }
            break;
        case 4:
            D_80241688_BAB7C8 -= 7;
            if (D_80241688_BAB7C8 < 0) {
                D_80241688_BAB7C8 = 0;
                D_80241680_BAB7C0 = 0;
            }
            break;
    }

    gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80241688_BAB7C8);
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2);
}

INCLUDE_ASM(s32, "world/area_mim/mim_07/BAA1B0", func_80240244_BAA384);
