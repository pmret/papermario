#include "common.h"
#include "npc.h"
#include "effects.h"

#ifndef STAR_SPIRIT_DATA_VAR
    #error STAR_SPIRIT_DATA_VAR is not defined!
#endif

// seems to be a macro in the original based on usage
#define EVT_SPIRIT_ADJUST_CAM(pitch) \
    EVT_CALL(GetCamDistance, CAM_DEFAULT, LVar1) \
    EVT_SUB(LVar1, 100) \
    EVT_CALL(SetCamDistance, CAM_DEFAULT, LVar1) \
    EVT_IF_NE(pitch, 10000) \
        EVT_CALL(GetCamPitch, CAM_DEFAULT, LVar2, LVar3) \
        EVT_CALL(SetCamPitch, CAM_DEFAULT, LVar2, pitch) \
    EVT_END_IF

API_CALLABLE(N(StarSpiritEffectFunc1)) {
    StarSpiritData* ptr = script->varTablePtr[0];

    sfx_adjust_env_sound_pos(SOUND_LRAW_STAR_ORB_RISING, SOUND_SPACE_DEFAULT, ptr->unk_00, ptr->unk_04, ptr->unk_08);

    if (ptr->unk_44 < 2) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(StarSpiritEffectFunc2)) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        StarSpiritData* ptr = heap_malloc(sizeof(*ptr));

        script->varTablePtr[0] = ptr;
        evt_set_variable(NULL, STAR_SPIRIT_DATA_VAR, script->varTable[0]);
        ptr->unk_38 = evt_get_variable(script, *args++);
        ptr->unk_3C = evt_get_variable(script, *args++);
        ptr->unk_0C = evt_get_float_variable(script, *args++);
        ptr->unk_10 = evt_get_float_variable(script, *args++);
        ptr->unk_14 = evt_get_float_variable(script, *args++);
        ptr->unk_18 = evt_get_float_variable(script, *args++);
        ptr->unk_1C = evt_get_float_variable(script, *args++);
        ptr->unk_20 = evt_get_float_variable(script, *args++);
        ptr->unk_24 = evt_get_float_variable(script, *args++);
        ptr->unk_28 = evt_get_float_variable(script, *args++);
        ptr->unk_50 = fx_star_spirits_energy(2, ptr->unk_0C, ptr->unk_10, ptr->unk_14, 1.0f, 0);
        ptr->unk_4E = 0;
        ptr->unk_48 = 0;
        ptr->unk_4A = 0;
        ptr->unk_44 = 0;
        ptr->unk_46 = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(StarSpiritEffectFunc3)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    StarSpiritData* ptr = script->varTablePtr[0];

    switch (ptr->unk_44) {
        case 0:
            ptr->unk_04 = update_lerp(EASING_CUBIC_OUT, ptr->unk_10, ptr->unk_1C, ptr->unk_46, ptr->unk_3C);
            ptr->unk_00 = update_lerp(EASING_LINEAR, ptr->unk_0C, ptr->unk_18, ptr->unk_46, ptr->unk_3C);
            ptr->unk_08 = update_lerp(EASING_LINEAR, ptr->unk_14, ptr->unk_20, ptr->unk_46, ptr->unk_3C);
            ptr->unk_50->data.starSpiritsEnergy->unk_08 = ptr->unk_00;
            ptr->unk_50->data.starSpiritsEnergy->unk_0C = ptr->unk_04;
            ptr->unk_50->data.starSpiritsEnergy->unk_10 = ptr->unk_08;
            ptr->unk_46++;
            if (ptr->unk_46 >= ptr->unk_3C) {
                ptr->unk_44 = 1;
                ptr->unk_46 = 0;
            }
            break;
        case 1:
            ptr->unk_46++;
            if (ptr->unk_46 >= 60) {
                ptr->unk_44 = 2;
                ptr->unk_46 = 0;
                ptr->unk_50->data.starSpiritsEnergy->unk_70 = 1;
                ptr->unk_50->data.starSpiritsEnergy->unk_74 = 0;
            }
            break;
        case 2:
            ptr->unk_46++;
            if (ptr->unk_46 >= 60) {
                ptr->unk_54 = fx_spirit_card(1, ptr->unk_18, ptr->unk_1C, ptr->unk_20, 1.0f, 0);
                ptr->unk_54->data.spiritCard->chapter = ptr->unk_38;
                ptr->unk_54->data.spiritCard->unk_20 = 0;
                ptr->unk_40 = create_shadow_type(SHADOW_VARYING_CIRCLE, ptr->unk_18, ptr->unk_28, ptr->unk_20);
                ptr->unk_44 = 3;
                ptr->unk_46 = 0;
                ptr->unk_2C = 0.0f;
                ptr->unk_48 = 1;
                ptr->unk_30 = 36.0f;
            }
            break;
        case 3:
            ptr->unk_30 = update_lerp(EASING_LINEAR, 36.0f, 19.0f, ptr->unk_46, 120);
            ptr->unk_46++;
            if (ptr->unk_46 >= 120) {
                ptr->unk_4C = 0;
                ptr->unk_4A = 1;
                ptr->unk_48 = 2;
                ptr->unk_4E = 1;
                ptr->unk_44 = 4;
                ptr->unk_46 = 0;
                ptr->unk_34 = ptr->unk_2C;
            }
            break;
        case 4:
            break;
    }

    switch (ptr->unk_4A) {
        case 1:
            ptr->unk_2C = update_lerp(EASING_QUADRATIC_OUT, ptr->unk_34, 1440.0f, ptr->unk_4C, 120);
            ptr->unk_04 = update_lerp(EASING_COS_IN_OUT, ptr->unk_1C, ptr->unk_24, ptr->unk_4C, 120);
            ptr->unk_4C++;
            if (ptr->unk_4C >= 120) {
                ptr->unk_4C = 270;
                ptr->unk_4A = 2;
                ptr->unk_4E = 2;
            }
            break;
        case 2:
            ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
            ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
            if (!(dist3D(playerStatus->pos.x, playerStatus->pos.y + 20.0f, playerStatus->pos.z,
                         ptr->unk_00, ptr->unk_04, ptr->unk_08) > 30.0f)) {
                ptr->unk_4E = 3;
            }
            break;
    }

    switch (ptr->unk_48) {
        case 1:
            ptr->unk_2C = clamp_angle(ptr->unk_2C + ptr->unk_30);
        case 2:
            ptr->unk_54->data.spiritCard->yaw = ptr->unk_2C;
            ptr->unk_54->data.spiritCard->pos.x = ptr->unk_18;
            ptr->unk_54->data.spiritCard->pos.y = ptr->unk_04;
            ptr->unk_54->data.spiritCard->pos.z = ptr->unk_20;
            break;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(StarSpiritEffectFunc4)) {
    s32 var = evt_get_variable(script, *script->ptrReadPos);
    StarSpiritData* ptr = script->varTablePtr[0];

    return (ptr->unk_4E == var) * ApiStatus_DONE2;
}

API_CALLABLE(N(StarSpiritEffectFunc5)) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        StarSpiritData* ptr = heap_malloc(sizeof(*ptr));
        script->varTablePtr[0] = ptr;
        ptr->unk_38 = evt_get_variable(script, *args++);
        ptr->unk_18 = evt_get_float_variable(script, *args++);
        ptr->unk_24 = evt_get_float_variable(script, *args++);
        ptr->unk_20 = evt_get_float_variable(script, *args++);
        ptr->unk_28 = evt_get_float_variable(script, *args++);
        ptr->unk_54 = fx_spirit_card(1, ptr->unk_18, ptr->unk_24, ptr->unk_20, 1.0f, 0);
        ptr->unk_54->data.spiritCard->chapter = ptr->unk_38;
        ptr->unk_54->data.spiritCard->unk_20 = 0;
        ptr->unk_40 = create_shadow_type(SHADOW_VARYING_CIRCLE, ptr->unk_18, ptr->unk_28, ptr->unk_20);
        ptr->unk_4C = 270;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(StarSpiritEffectFunc6)) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    StarSpiritData* ptr = script->varTablePtr[0];

    ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
    ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
    if (dist2D(playerStatus->pos.x, playerStatus->pos.z,
               ptr->unk_18, ptr->unk_20) <= 30.0f) {
        ptr->unk_4E = 3;
    }
    ptr->unk_54->data.spiritCard->pos.x = ptr->unk_18;
    ptr->unk_54->data.spiritCard->pos.y = ptr->unk_04;
    ptr->unk_54->data.spiritCard->pos.z = ptr->unk_20;

    return ApiStatus_BLOCK;
}
