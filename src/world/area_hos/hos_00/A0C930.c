#include "hos_00.h"

void func_80240C40_A0C930(void) {
    s32 alpha = update_lerp(0, 0.0f, 216.0f, gPlayerStatus.position.x - 200.0f, 500);

    if (alpha < 0) {
        alpha = 0;
    }
    if (alpha > 216) {
        alpha = 216;
    }
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, SHADE, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);
}
