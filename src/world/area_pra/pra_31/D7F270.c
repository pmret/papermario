#include "pra_31.h"

typedef struct UnkPra31 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[0x8];
    /* 0x14 */ f32 unk_14;
} UnkPra31; // size = 0x18

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240510_D7F270);

ApiStatus func_80240818_D7F578(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    f32 temp_f20 = evt_get_float_variable(script, *args++);
    UnkPra31* structs = (UnkPra31*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &structs[idx];

    structPtr->unk_14 = temp_f20;
    return ApiStatus_DONE2;
}

ApiStatus func_80240894_D7F5F4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31* structs = (UnkPra31*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &structs[idx];
    s32 var_s0;
    s32 var_s1;
    s32 temp_f2;
    s32 i;

    script->varTable[0] = 0;
    temp_f2 = structPtr->unk_14;

    switch (temp_f2) {
        case 0:
            var_s0 = structPtr->unk_00;
            var_s1 = structPtr->unk_02 - 1;
            break;
        case 90:
            var_s1 = structPtr->unk_02;
            var_s0 = structPtr->unk_00 + 1;
            break;
        case 180:
            var_s0 = structPtr->unk_00;
            var_s1 = structPtr->unk_02 + 1;
            break;
        case 270:
            var_s1 = structPtr->unk_02;
            var_s0 = structPtr->unk_00 - 1;
            break;
    }

    for (i = 0; i < 3; i++) {
        if (i != idx && var_s0 == structs[i].unk_00 && var_s1 == structs[i].unk_02) {
            script->varTable[0] = 1;
        }
    }

    if (var_s0 < 0) {
        script->varTable[0] = 1;
    }
    if (var_s0 >= 9) {
        script->varTable[0] = 1;
    }
    if (var_s1 < 0) {
        script->varTable[0] = 1;
    }
    if (var_s1 >= 3) {
        script->varTable[0] = 1;
    }
    if (script->varTable[0] == 1 && gPlayerStatusPtr->actionState == ACTION_STATE_PUSHING_BLOCK) {
        set_action_state(ACTION_STATE_IDLE);
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7F270", func_80240A3C_D7F79C);

ApiStatus func_80240BBC_D7F91C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31* structs = (UnkPra31*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &structs[idx];
    s32 temp_f2 = structPtr->unk_14;

    switch (temp_f2) {
        case 0:
            script->varTable[0] = 180;
            break;
        case 0xB4:
            script->varTable[0] = 0;
            break;
        case 90:
        case 270:
            script->varTable[0] = temp_f2;
            break;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240C70_D7F9D0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31* structs = (UnkPra31*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &structs[idx];
    s32 temp_f4 = structPtr->unk_14;

    switch (temp_f4) {
        case 0:
            script->varTable[3] = playerStatus->position.z;
            script->varTable[4] = playerStatus->position.z + 50.0f;
            script->varTable[5] = 1;
            break;
        case 90:
            script->varTable[3] = playerStatus->position.x;
            script->varTable[4] = playerStatus->position.x + 50.0f;
            script->varTable[5] = 0;
            break;
        case 180:
            script->varTable[3] = playerStatus->position.z;
            script->varTable[4] = playerStatus->position.z - 50.0f;
            script->varTable[5] = 1;
            break;
        case 270:
            script->varTable[3] = playerStatus->position.x;
            script->varTable[4] = playerStatus->position.x - 50.0f;
            script->varTable[5] = 0;
            break;
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc12.inc.c"

ApiStatus func_80240E70_D7FBD0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31* structs = (UnkPra31*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &structs[idx];

    evt_set_float_variable(script, LocalVar(0), structPtr->unk_04);
    evt_set_float_variable(script, LocalVar(1), -structPtr->unk_08);
    evt_set_float_variable(script, LocalVar(2), clamp_angle(structPtr->unk_14 + 90.0));
    return ApiStatus_DONE2;
}

ApiStatus func_80240F2C_D7FC8C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31* structs = (UnkPra31*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &structs[idx];

    evt_set_float_variable(script, LocalVar(0), structPtr->unk_04);
    evt_set_float_variable(script, LocalVar(1), structPtr->unk_08);
    evt_set_float_variable(script, LocalVar(2), clamp_angle(structPtr->unk_14));
    return ApiStatus_DONE2;
}

ApiStatus func_80240FD0_D7FD30(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= PA_FLAGS_PUSHED_ALBINO_DINO;
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc11.inc.c"
