#include "hos_03.h"

extern u16 D_80243BD4_A1ECD4;

#include "world/common/atomic/TexturePan.inc.c"

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1B130", func_8024033C_A1B43C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1B130", func_8024060C_A1B70C);

INCLUDE_ASM(s32, "world/area_hos/hos_03/A1B130", func_802407E8_A1B8E8);

void func_80240928_A1BA28(void) {
    f32 scale = ((sins(D_80243BD4_A1ECD4) * (1 / 32768.0f)) * 0.5 * 0.5) + 1.05;

    D_80243BD4_A1ECD4 += 409;
    guScale(&gDisplayContext->matrixStack[gMatrixListPos], scale, scale, scale);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
}

ApiStatus func_80240A50_A1BB50(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
