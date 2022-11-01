#include "hos_06.h"
#include "effects.h"
#include "model.h"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

extern u8 D_802447D0_A3DCB0[];

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240F7C_A3A45C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80240FD0_A3A4B0);

extern s32 hos_06_D_80246430[];

ApiStatus func_80241008_A3A4E8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            hos_06_D_80246430[i] = ptr[i];
        }
        hos_06_D_80246430[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            hos_06_D_80246430[i] = i + 16;
            hos_06_D_80246430[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#define NAMESPACE dup_hos_06
#include "world/common/todo/StashVars.inc.c"
#define NAMESPACE hos_06

#include "world/common/todo/GetItemName.inc.c"

s32 func_802411BC_A3A69C(s32 badgeID) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPlayerData.badges); i++) {
        if (gPlayerData.badges[i] == badgeID) {
            return TRUE;
        }
    }
    return FALSE;
}

ApiStatus func_802411F0_A3A6D0(Evt* script, s32 isInitialCall) {
    u32 i;

    for (i = 0; i < 79; i++) {
        evt_set_variable(NULL, AreaFlag(3) + i, 0);
    }
    for (i = 0; i < 16; i++) {
        evt_set_variable(NULL, AreaFlag(100) + i, 0);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_8024126C_A3A74C);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_802414E4_A3A9C4);

INCLUDE_ASM(s32, "world/area_hos/hos_06/A3A230", func_80241668_A3AB48);

ApiStatus func_802417EC_A3ACCC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    if (gPlayerData.coins < D_802447D0_A3DCB0[idx]) {
        evt_set_variable(script, outVar, TRUE);
    } else {
        evt_set_variable(script, outVar, FALSE);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80241860_A3AD40(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    gPlayerData.coins -= D_802447D0_A3DCB0[idx];
    return ApiStatus_DONE2;
}

ApiStatus func_802418A4_A3AD84(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);

    gPlayerData.coins += D_802447D0_A3DCB0[idx];
    return ApiStatus_DONE2;
}

ApiStatus func_802418E8_A3ADC8(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x79)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7A)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7B)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7C)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7D)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7F)), -1, 3);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0xD0)), -1, 3);
        set_model_env_color_parameters(255, 255, 255, 0, 0, 0);
        script->functionTemp[0] = 255;
    }

    script->functionTemp[0] -= 4;
    if (script->functionTemp[0] < 64) {
        script->functionTemp[0] = 64;
    }
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);
    if (script->functionTemp[0] == 64) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80241A58_A3AF38(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
        script->functionTemp[2] = 64;
        script->functionTemp[1] = 0;
    }
    if (script->functionTemp[1] == 0) {
        script->functionTemp[0] += 4;
        script->functionTemp[2] += 4;
        if (script->functionTemp[0] > 127) {
            script->functionTemp[0] = 127;
        }
        if (script->functionTemp[2] > 127) {
            script->functionTemp[2] = 127;
        }
        if (script->functionTemp[0] == 127 && (script->functionTemp[2] == script->functionTemp[0])) {
            script->functionTemp[1] = 1;
        }
    } else {
        script->functionTemp[0] -= 4;
        script->functionTemp[2] -= 4;
        if (script->functionTemp[0] < 64) {
            script->functionTemp[0] = 64;
        }
        if (script->functionTemp[2] < 0) {
            script->functionTemp[2] = 0;
        }
    }
    set_model_env_color_parameters(
        script->functionTemp[0], script->functionTemp[0], script->functionTemp[0],
        script->functionTemp[2], script->functionTemp[2], script->functionTemp[2]
    );
    if (script->functionTemp[0] == 64 && script->functionTemp[2] == 0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80241B74_A3B054(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 64;
    }

    script->functionTemp[0] += 4;
    if (script->functionTemp[0] > 255) {
        script->functionTemp[0] = 255;
    }
    set_model_env_color_parameters(script->functionTemp[0], script->functionTemp[0], script->functionTemp[0], 0, 0, 0);

    if (script->functionTemp[0] == 255) {
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x79)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7A)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7B)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7C)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7D)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0x7F)), -1, 0);
        set_mdl_custom_gfx_set(get_model_from_list_index(get_model_list_index_from_tree_index(0xD0)), -1, 0);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

// TODO may not be motionBlurFlame
ApiStatus func_80241CCC_A3B1AC(Evt* script, s32 isInitialCall) {
    EffectInstance* effects[3];
    Matrix4f sp28, sp68;
    f32 tx;
    f32 ty;
    f32 temp_f24;
    f32 temp_f28;
    f32 temp_f30;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 180;
        script->functionTempPtr[1] = (EffectInstance*) evt_get_variable(script, ArrayVar(3));
        script->functionTempPtr[2] = (EffectInstance*) evt_get_variable(script, ArrayVar(4));
        script->functionTempPtr[3] = (EffectInstance*) evt_get_variable(script, ArrayVar(5));
    }

    effects[0] = script->functionTempPtr[1];
    effects[1] = script->functionTempPtr[2];
    effects[2] = script->functionTempPtr[3];
    temp_f30 = (sin_deg(script->functionTemp[0]) * 10.0f) + 10.0f;
    temp_f28 = (sin_deg(script->functionTemp[0]) * 25.0f) + 10.0f;
    temp_f24 = script->functionTemp[0] * 10;

    for (i = 0; i < ARRAY_COUNT(effects); i++) {
        guRotateF(sp28, -gCameras[gCurrentCameraID].currentYaw, 0.0f, 1.0f, 0.0f);
        guRotateF(sp68, i * 120, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp68, sp28, sp28);
        tx = temp_f30 * sin_deg(temp_f24);
        ty = temp_f28 * cos_deg(temp_f24);
        guTranslateF(sp68, tx, ty, 0.0f);
        guMtxCatF(sp68, sp28, sp28);
        effects[i]->data.motionBlurFlame->pos.x = sp28[3][0];
        effects[i]->data.motionBlurFlame->pos.y = sp28[3][1];
        effects[i]->data.motionBlurFlame->pos.z = sp28[3][2];
    }

    script->functionTemp[0]--;
    if (script->functionTemp[0] < 16) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            effects[i]->data.motionBlurFlame->unk_4C = script->functionTemp[0];
        }
    }

    if (script->functionTemp[0] < 0) {
        for (i = 0; i < ARRAY_COUNT(effects); i++) {
            remove_effect(effects[i]);
        }
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80241F98_A3B478(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    // TODO effect may be wrong
    effect->data.energyOrbWave->unk_1C++;
    return ApiStatus_DONE2;
}
