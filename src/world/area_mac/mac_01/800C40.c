#include "mac_01.h"

INCLUDE_ASM(s32, "world/area_mac/mac_01/800C40", func_802403C0_800C40);

void func_802405E8_800E68(void) {
    gSPClearGeometryMode(gMasterGfxPos++, G_TEXTURE_GEN);
    gSPEndDisplayList(gMasterGfxPos++);
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/800C40", func_80240628_800EA8);
