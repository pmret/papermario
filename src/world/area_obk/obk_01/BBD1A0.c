#include "obk_01.h"
#include "model.h"

static char* N(exit_str_0) = "mim_11";
static char* N(exit_str_1) = "obk_02";
static char* N(exit_str_2) = "obk_05";
static char* N(exit_str_3) = "obk_07";
static char* N(exit_str_4) = "obk_08";
static char* N(exit_str_5) = "obk_09";

extern s32 D_80241C58_BBEDF8[];

#include "world/common/todo/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/todo/SetCamera0MoveFlag1.inc.c"

ApiStatus func_80240038_BBD1D8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gCameras[CAM_DEFAULT].vfov = (s32) evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_8024007C_BBD21C(Evt* script, s32 isInitialCall) {
    u32 pressedButtons = gGameStatusPtr->pressedButtons[0];
    s32 val;

    if (pressedButtons & BUTTON_A) {
        val = TRUE;
    } else {
        val = FALSE;
    }
    script->varTable[6] = val;
    return ApiStatus_DONE2;
}

typedef struct UnkObk01 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32* unk_08;
    /* 0x0C */ f32 unk_0C; // some angle
    /* 0x10 */ f32 unk_10; // some y
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ Matrix4f unk_1C;
    /* 0x5C */ Model* models[4];
} UnkObk01; // size = 0x6C;

ApiStatus func_80240098_BBD238(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Matrix4f sp18;
    f32 temp_f20;
    f32 var_f22;
    s32 var_a0;
    s32 temp_s0_2;
    Model* model;
    UnkObk01* temp_v0;
    s32 i;

    if (isInitialCall) {
        script->functionTempPtr[1] = temp_v0 = heap_malloc(sizeof(*temp_v0));
        temp_v0->unk_08 = (s32*) evt_get_variable(script, *args++);
        temp_v0->unk_08[0] = (s32) temp_v0; // what is going on here?

        for (i = 0; i < ARRAY_COUNT(temp_v0->models); i++) {
            temp_v0->models[i] = get_model_from_list_index(get_model_list_index_from_tree_index(D_80241C58_BBEDF8[i]));
        }

        model = temp_v0->models[0];
        copy_matrix(model->transformMatrix, temp_v0->unk_1C);

        var_f22 = 0.0f;
        temp_v0->unk_10 = var_f22;
        temp_v0->unk_14 = var_f22;
        temp_v0->unk_0C = 180.0f;
        temp_v0->unk_18 = 10.0f;
        temp_v0->unk_00 = 0;

        script->functionTemp[0] = 0;
        script->functionTemp[2] = 0;
        script->functionTemp[3] = 0;
    }

    temp_v0 = script->functionTempPtr[1];
    model = temp_v0->models[0];
    var_f22 = temp_v0->unk_10;
    if (temp_v0->unk_08[1] == 2) {
        script->functionTemp[0] = 10;
        temp_v0->unk_08[1] = 3;
        temp_v0->unk_04 = 10;
    }

    switch (script->functionTemp[0]) {
        case 0:
            if (temp_v0->unk_08[1] != 0) {
                var_f22 = 0.0f;
                temp_v0->unk_04 = 35;
                temp_v0->unk_10 = 0.0f;
                temp_v0->unk_14 = 0.0f;
                temp_v0->unk_18 = 10.0f;
                temp_v0->unk_0C = 180.0f;
                temp_v0->unk_00 |= 2 | 1;
                script->functionTemp[0] = 1;
            }
            break;
        case 1:
            temp_v0->unk_04--;
            if (temp_v0->unk_04 == -1) {
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            temp_v0->unk_10 += -1.4666667f;
            if (temp_v0->unk_10 < -220.0f) {
                temp_v0->unk_10 = -220.0f;
                script->functionTemp[0] = 3;
            }
            break;
        case 3:
            temp_v0->unk_18 -= 0.06666667f;
            if (temp_v0->unk_18 < 0.0f) {
                temp_v0->unk_18 = 0.0f;
                script->functionTemp[0] = 4;
                temp_v0->unk_00 &= ~0x1;
                temp_v0->unk_00 |= 0x4;
            }
            break;
        case 10:
            temp_v0->unk_04--;
            if (temp_v0->unk_04 == -1) {
                script->functionTemp[0] = 11;
            }
            break;
        case 11:
            var_a0 = 0;
            temp_v0->unk_00 &= ~0x4;
            temp_v0->unk_10 += 4.0f;
            if (temp_v0->unk_10 >= 0.0f) {
                temp_v0->unk_10 = 0.0f;
                var_a0 = 1;
            }
            temp_v0->unk_18 -= 0.2f;
            if (temp_v0->unk_18 < 0.0f) {
                var_a0++;
                temp_v0->unk_18 = 0.0f;
                temp_v0->unk_00 &= ~0x1;
            }
            if (var_a0 == 2) {
                temp_v0->unk_08[1] = 0;
                script->functionTemp[0] = 0;
            }
            break;
    }

    if (temp_v0->unk_00 & 1) {
        temp_v0->unk_0C = clamp_angle(temp_v0->unk_0C + 3.6f);
        temp_f20 = sin_deg(temp_v0->unk_0C) * temp_v0->unk_18;
        if (temp_v0->unk_14 == 0.0f) {
            temp_v0->unk_14 = 1.0f;
        }
        if (temp_f20 * temp_v0->unk_14 <= 0.0f) {
            sfx_play_sound_at_player(SOUND_9D, 0);
        }
        temp_v0->unk_14 = temp_f20;
    }
    if (script->functionTemp[2] == 0) {
        if (temp_v0->unk_10 != var_f22) {
            sfx_play_sound_at_position(SOUND_8000000F, 0, 440.0f, temp_v0->unk_10, 271.0f);
            script->functionTemp[2] = 1;
        }
    } else if (temp_v0->unk_10 == var_f22) {
        sfx_stop_sound(SOUND_8000000F);
        script->functionTemp[2] = 0;
    }
    temp_s0_2 = evt_get_variable(script, MapVar(11));
    if (script->functionTemp[3] == 0) {
        if (temp_s0_2 != script->varTable[1]) {
            f32 x, y, z;

            get_collider_center(0x6E, &x, &y, &z);
            sfx_play_sound_at_position(SOUND_80000010, 0, x, y, z);
            script->functionTemp[3] = 1;
        }
    } else if (temp_s0_2 == script->varTable[1]) {
        sfx_stop_sound(SOUND_80000010);
        script->functionTemp[3] = 0;
    }
    script->varTable[1] = temp_s0_2;
    guTranslateF(model->transformMatrix, 0.0f, temp_v0->unk_10 - 300.0f, 0.0f);
    guRotateF(sp18, temp_v0->unk_14, 0.0f, 0.0f, 1.0f);
    guMtxCatF(model->transformMatrix, sp18, model->transformMatrix);
    guTranslateF(sp18, 0.0f, 300.0f, 0.0f);
    guMtxCatF(model->transformMatrix, sp18, model->transformMatrix);
    guMtxCatF(temp_v0->unk_1C, model->transformMatrix, model->transformMatrix);
    model->flags |= MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED;

    for (i = 1; i < ARRAY_COUNT(temp_v0->models); i++) {
        copy_matrix(model->transformMatrix, temp_v0->models[i]->transformMatrix);
        temp_v0->models[i]->flags |= MODEL_FLAGS_USES_TRANSFORM_MATRIX | MODEL_FLAGS_HAS_TRANSFORM_APPLIED;
    }

    if (temp_v0->unk_00 & 2) {
        playerStatus->position.x = (-sin_deg(temp_v0->unk_14) * (temp_v0->unk_10 - 300.0f)) + 445.0f;
        playerStatus->position.y = ((cos_deg(temp_v0->unk_14) * (temp_v0->unk_10 - 300.0f)) - 135.0f) + 300.0f;
        playerStatus->position.z = 279.0f;
    }
    return ApiStatus_BLOCK;
}

// unused?
ApiStatus func_802406AC_BBD84C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* var; // TODO what is this?
    s32 temp_a1;

    if (isInitialCall) {
        var = (s32*) evt_get_variable(script, *args++);
        script->functionTemp[1] = *var;
    }

    var = script->functionTempPtr[1];
    if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
        if (*var & 4) {
            script->varTable[0] = 1;
        } else {
            script->varTable[0] = 0;
        }
        *var &= ~2;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80240730_BBD8D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* var; // TODO what is this?
    s32 temp_a1;

    if (isInitialCall) {
        var = (s32*) evt_get_variable(script, *args++);
        script->functionTemp[1] = *var;
    }

    var = script->functionTempPtr[1];
    if (*var & 4) {
        *var &= ~2;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80240790_BBD930(Evt* script, s32 isInitialCall) {
    ItemEntity* item = get_item_entity(script->varTable[0]);

    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAGS_TRANSPARENT);
    item->alpha = -1;
    return ApiStatus_DONE2;
}
