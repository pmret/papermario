#include "hos_05.h"

extern u8 D_8024DCCF_A37F0F;
extern u8 D_8024DCD3_A37F13;
extern u8 D_802D9D73;

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EF00", pause_tabs_draw_badges_A2EF00);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EF00", func_80244DE4_A2F024);

#define NAMESPACE dup_hos_05
#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"
#define NAMESPACE hos_05

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EF00", func_802452C4_A2F504);

void func_8024564C_A2F88C(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_802D9D73);
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EF00", func_8024569C_A2F8DC);

void func_802456C8_A2F908(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_8024DCCF_A37F0F);
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EF00", func_80245718_A2F958);

void func_80245744_A2F984(void) {
    gDPSetCombineLERP(gMasterGfxPos++, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0,
                      PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, D_8024DCD3_A37F13);
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EF00", func_80245794_A2F9D4);

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EF00", func_802457C0_A2FA00);
