#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/partner_buff", partner_buff_main);

void partner_buff_init(void) {
}

INCLUDE_ASM(s32, "effects/partner_buff", partner_buff_update);

void partner_buff_render(void) {
}

INCLUDE_ASM(s32, "effects/partner_buff", func_E011A3A0);

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

INCLUDE_ASM(s32, "effects/partner_buff", func_E011A48C);

INCLUDE_ASM(s32, "effects/partner_buff", func_E011A700);
