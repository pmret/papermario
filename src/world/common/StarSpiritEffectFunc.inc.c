#include "common.h"
#include "map.h"
#include "effects.h"

ApiStatus N(StarSpiritEffectFunc1)(Evt* script, s32 isInitialCall) {
    StarSpiritEffect* ptr = (StarSpiritEffect*)script->varTable[0];

    sfx_adjust_env_sound_pos(SOUND_UNKNOWN_A2, 0, ptr->unk_00, ptr->unk_04, ptr->unk_08);

    if (ptr->unk_44 < 2) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

ApiStatus N(StarSpiritEffectFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        StarSpiritEffect* ptr = heap_malloc(sizeof(StarSpiritEffect));
        script->varTable[0] = ptr;
        evt_set_variable(NULL, EVT_MAP_VAR(1), ptr);
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
        ptr->unk_50 = (struct StarSpiritEffectUnkStruct*) playFX_83(2, ptr->unk_0C, ptr->unk_10, ptr->unk_14, 1.0f, 0);
        ptr->unk_4E = 0;
        ptr->unk_48 = 0;
        ptr->unk_4A = 0;
        ptr->unk_44 = 0;
        ptr->unk_46 = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(StarSpiritEffectFunc3)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    StarSpiritEffect* ptr = (StarSpiritEffect*)script->varTable[0];

    switch (ptr->unk_44) {
        case 0:
            ptr->unk_04 = update_lerp(5, ptr->unk_10, ptr->unk_1C, ptr->unk_46, ptr->unk_3C);
            ptr->unk_00 = update_lerp(0, ptr->unk_0C, ptr->unk_18, ptr->unk_46, ptr->unk_3C);
            ptr->unk_08 = update_lerp(0, ptr->unk_14, ptr->unk_20, ptr->unk_46, ptr->unk_3C);
            ptr->unk_50->unk_0C->unk_08 = ptr->unk_00;
            ptr->unk_50->unk_0C->unk_0C = ptr->unk_04;
            ptr->unk_50->unk_0C->unk_10 = ptr->unk_08;
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
                ptr->unk_50->unk_0C->unk_70 = 1;
                ptr->unk_50->unk_0C->unk_74 = 0;
            }
            break;
        case 2:
            ptr->unk_46++;
            if (ptr->unk_46 >= 60) {
                ptr->unk_54 = playFX_7B(1, ptr->unk_18, ptr->unk_1C, ptr->unk_20, 1.0f, 0);
                *((s8*)ptr->unk_54->unk_0C + 0x34) = ptr->unk_38;
                ptr->unk_54->unk_0C->unk_20 = 0;
                ptr->unk_40 = create_shadow_type(0, ptr->unk_18, ptr->unk_28, ptr->unk_20);
                ptr->unk_44 = 3;
                ptr->unk_46 = 0;
                ptr->unk_2C = 0.0f;
                ptr->unk_48 = 1;
                ptr->unk_30 = 36.0f;
            }
            break;
        case 3:
            ptr->unk_30 = update_lerp(0, 36.0f, 19.0f, ptr->unk_46, 120);
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
            ptr->unk_2C = update_lerp(4, ptr->unk_34, 1440.0f, ptr->unk_4C, 120);
            ptr->unk_04 = update_lerp(0xA, ptr->unk_1C, ptr->unk_24, ptr->unk_4C, 120);
            ptr->unk_4C++;
            if (ptr->unk_4C >= 120) {
                ptr->unk_4C = 0x10E;
                ptr->unk_4A = 2;
                ptr->unk_4E = 2;
            }
            break;
        case 2:
            ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
            ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
            if (!(dist3D(playerStatus->position.x, playerStatus->position.y + 20.0f, playerStatus->position.z,
                         ptr->unk_00, ptr->unk_04, ptr->unk_08) > 30.0f)) {
                ptr->unk_4E = 3;
            }
            break;
    }

    switch (ptr->unk_48) {
        case 1:
            ptr->unk_2C = clamp_angle(ptr->unk_2C + ptr->unk_30);
        case 2:
            ptr->unk_54->unk_0C->unk_24.f = ptr->unk_2C;
            ptr->unk_54->unk_0C->unk_04 = ptr->unk_18;
            ptr->unk_54->unk_0C->unk_08 = ptr->unk_04;
            ptr->unk_54->unk_0C->unk_0C = ptr->unk_20;
            break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus N(StarSpiritEffectFunc4)(Evt* script, s32 isInitialCall) {
    s32 var = evt_get_variable(script, *script->ptrReadPos);
    StarSpiritEffect* ptr = (StarSpiritEffect*) script->varTable[0];

    return (ptr->unk_4E == var) * ApiStatus_DONE2;
}

ApiStatus N(StarSpiritEffectFunc5)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        StarSpiritEffect* ptr = (StarSpiritEffect*) heap_malloc(sizeof(StarSpiritEffect));
        script->varTable[0] = ptr;
        ptr->unk_38 = evt_get_variable(script, *args++);
        ptr->unk_18 = evt_get_float_variable(script, *args++);
        ptr->unk_24 = evt_get_float_variable(script, *args++);
        ptr->unk_20 = evt_get_float_variable(script, *args++);
        ptr->unk_28 = evt_get_float_variable(script, *args++);
        ptr->unk_54 = playFX_7B(1, ptr->unk_18, ptr->unk_24, ptr->unk_20, 1.0f, 0);
        ptr->unk_54->unk_0C->unk_34 = ptr->unk_38;
        ptr->unk_54->unk_0C->unk_20 = 0;
        ptr->unk_40 = create_shadow_type(0, ptr->unk_18, ptr->unk_28, ptr->unk_20);
        ptr->unk_4C = 0x10E;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(StarSpiritEffectFunc6)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    StarSpiritEffect* ptr = (StarSpiritEffect*) script->varTable[0];

    ptr->unk_04 = ptr->unk_24 + (2.0f * (sin_deg(ptr->unk_4C) + 1.0f));
    ptr->unk_4C = clamp_angle(ptr->unk_4C + 8);
    if (dist2D(playerStatus->position.x, playerStatus->position.z,
               ptr->unk_18, ptr->unk_20) <= 30.0f) {
        ptr->unk_4E = 3;
    }
    ptr->unk_54->unk_0C->unk_04 = ptr->unk_18;
    ptr->unk_54->unk_0C->unk_08 = ptr->unk_04;
    ptr->unk_54->unk_0C->unk_0C = ptr->unk_20;

    return ApiStatus_BLOCK;
}
