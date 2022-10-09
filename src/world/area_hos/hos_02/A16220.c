#include "hos_02.h"

static char* N(exit_str_0) = "hos_01";
static char* N(exit_str_1) = "hos_03";

extern u16 D_802433AC_A195CC;

#include "world/common/atomic/TexturePan.inc.c"

void func_8024030C_A1652C(void) {
    f32 scale = ((sins(D_802433AC_A195CC) * (1 / 32768.0f)) * 0.5 * 0.5) + 1.05;

    D_802433AC_A195CC += 409;
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], scale, scale, scale);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240434_A16654);

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240610_A16830);

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240904_A16B24);

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240BFC_A16E1C);

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240EF4_A17114);

INCLUDE_ASM(s32, "world/area_hos/hos_02/A16220", func_80240F68_A17188);
