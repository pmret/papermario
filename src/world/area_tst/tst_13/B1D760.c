#include "tst_13.h"

extern Gfx D_80242860_B1FFC0[];
extern s32 D_80242BF8_B20358;

ApiStatus func_80240000_B1D760(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 dist = dist2D(playerStatus->position.x, playerStatus->position.z, script->array[2], script->array[3]);

    script->varTable[0] = 1;
    if (playerStatus->actionState != ACTION_STATE_SPIN_POUND && playerStatus->actionState != ACTION_STATE_TORNADO_POUND) {
        script->varTable[0] = 0;
    }
    if (script->array[4] <= dist) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

#include "world/common/UnkDistFunc2.inc.c"

void func_8024013C_B1D89C(void) {
    Matrix4f sp10;
    Matrix4f sp50;
    f32 x;
    f32 y;
    f32 z;

    D_80242BF8_B20358 += 1;
    guTranslateF(sp10, gPlayerStatus.position.x, 0.0f, gPlayerStatus.position.z);

    x = (sin_rad(D_80242BF8_B20358 / 50.0f) * 0.5) + 0.5;
    y = SQ(cos_rad(D_80242BF8_B20358 / 50.0f)) + 0.1;
    z = (sin_rad(D_80242BF8_B20358 / 50.0f) * 0.5) + 0.5;

    guScaleF(sp50, x, y, z);
    guMtxCatF(sp50, sp10, sp10);
    guMtxF2L(sp10, &gDisplayContext->matrixStack[gMatrixListPos]);
    mdl_project_tex_coords(1, D_80242860_B1FFC0, sp10, NULL);

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    mdl_draw_hidden_panel_surface(&gMasterGfxPos, 1);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, D_80242860_B1FFC0);
    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
}
