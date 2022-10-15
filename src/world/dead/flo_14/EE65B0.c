#include "flo_14.h"

extern f32 D_80243B44_EEA0F4;

#include "world/common/atomic/TexturePan.inc.c"

void fx_sun_undeclared(s32, s32, s32, s32, s32, s32);

ApiStatus func_8024030C_EE68BC(Evt *script, s32 isInitialCall) {
    fx_sun_undeclared(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc43.inc.c"

ApiStatus func_802403D4_EE6984(Evt* script, s32 isInitialCall) {
    if (gPlayerData.currentPartner == PARTNER_NONE) {
        script->varTable[14] = 0;
        return ApiStatus_DONE2;
    }

    script->varTable[14] = 1;
    evt_set_variable(NULL, MapVar(0), get_npc_unsafe(NPC_PARTNER)->flags);
    return ApiStatus_DONE2;
}

ApiStatus func_8024042C_EE69DC(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(NPC_PARTNER);

    npc->flags = evt_get_variable(NULL, MapVar(0));
    return ApiStatus_DONE2;
}

ApiStatus func_8024046C_EE6A1C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_194, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);

    return ApiStatus_DONE2;
}

void func_80240504_EE6AB4(void) {
    Matrix4f matrix;
    Vtx* sp50;
    Vtx* sp54;
    s32 sp58;
    s32 new_var;

    guMtxIdentF(matrix);

    matrix[0][0] = (sin_rad(D_80243B44_EEA0F4 / 11.0f) * 0.04) + 0.98;
    matrix[0][1] = sin_rad(D_80243B44_EEA0F4 / 12.0f) * 0.04;
    matrix[0][2] = cos_rad(D_80243B44_EEA0F4 / 13.0f) * 0.04;

    matrix[1][1] = (sin_rad(D_80243B44_EEA0F4 / 7.0f + 1.0f) * 0.04) + 0.98;
    matrix[1][0] = sin_rad(D_80243B44_EEA0F4 / 14.0f) * 0.04;
    matrix[1][2] = cos_rad(D_80243B44_EEA0F4 / 15.0f) * 0.04;

    matrix[2][2] = (sin_rad(D_80243B44_EEA0F4 * 0.25f + 2.0f)  * 0.04) + 0.98;
    matrix[2][0] = sin_rad(D_80243B44_EEA0F4 * 0.0625f) * 0.04;
    matrix[2][1] = cos_rad(D_80243B44_EEA0F4 / 17.0f) * 0.04;

    guMtxF2L(matrix, &gDisplayContext->matrixStack[gMatrixListPos]);
    mdl_get_copied_vertices(0, &sp50, &sp54, &sp58);

    new_var = 0;
    while (new_var); // TODO required to match

    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
              G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gMasterGfxPos++, mdl_get_copied_gfx(0));

    D_80243B44_EEA0F4 += 1.0f;
}


INCLUDE_ASM(s32, "EE65B0", func_802407D4_EE6D84);
