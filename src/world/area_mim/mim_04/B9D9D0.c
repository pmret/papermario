#include "mim_04.h"

extern s32 D_80241530_B9EE90;
extern s32 D_80241534_B9EE94;
extern s32 D_80241538_B9EE98;

void func_80240070_B9D9D0(s32 index) {
    switch (D_80241530_B9EE90) {
        case 1:
            D_80241538_B9EE98 = 0;
            D_80241530_B9EE90 = 2;
            break;
        case 2:
            D_80241538_B9EE98 += 10;
            if (D_80241538_B9EE98 >= 256) {
                D_80241538_B9EE98 = 255;
                D_80241534_B9EE94 = 20;
                D_80241530_B9EE90 = 3;
            }
            break;
        case 3:
            D_80241534_B9EE94--;
            if (D_80241534_B9EE94 < 0) {
                D_80241534_B9EE94 = 0;
                D_80241530_B9EE90 = 4;
            }
            break;
        case 4:
            D_80241538_B9EE98 -= 10;
            if (D_80241538_B9EE98 < 0) {
                D_80241538_B9EE98 = 0;
                D_80241530_B9EE90 = 0;
            }
            break;
    }

    gDPSetCycleType(gMasterGfxPos++, G_CYC_2CYCLE);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_80241538_B9EE98);
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE_ALPHA, 0, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2);
}

INCLUDE_ASM(s32, "world/area_mim/mim_04/B9D9D0", func_802401DC_B9DB3C);
