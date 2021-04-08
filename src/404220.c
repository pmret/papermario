#include "common.h"

INCLUDE_ASM(s32, "404220", func_E011A000);

void func_E011A0FC(void) {
}

INCLUDE_ASM(s32, "404220", func_E011A104);

void func_E011A398(void) {
}

INCLUDE_ASM(s32, "404220", func_E011A3A0);

#ifdef NON_MATCHING // gfx gbi macro issue
void func_E011A3BC(s16 alpha) {
    if (alpha == 255) {
        gDPSetRenderMode(gMasterGfxPos++, AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c1(G_BL_CLR_IN, G_BL_A_IN,
                         G_BL_CLR_MEM, G_BL_A_MEM), AA_EN | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM,
                                 G_BL_A_MEM));
        gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    } else {
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, TEXEL0, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x00, 0x00, 0x00, alpha);
    }
}
#else
INCLUDE_ASM(s32, "404220", func_E011A3BC);
#endif

INCLUDE_ASM(s32, "404220", func_E011A48C);

INCLUDE_ASM(s32, "404220", func_E011A700);
