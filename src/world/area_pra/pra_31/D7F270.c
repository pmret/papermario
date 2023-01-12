#include "pra_31.h"

typedef struct UnkPra31 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} UnkPra31; // size = 0x18

typedef struct UnkPra31Big {
    /* 0x00 */ UnkPra31 unk_00[3];
    /* 0x48 */ s16 unk_48[3][9];
    /* 0x7E */ char unk_7E[0x2];
} UnkPra31Big; // size = 0x80

extern s32 D_802424F0_D81250[][3];
extern s32 D_80242514_D81274[][3];
extern s16 D_80242538_D81298[3][9];

ApiStatus func_80240510_D7F270(Evt* script, s32 isInitialCAll) {
    UnkPra31Big* big;
    UnkPra31* inner;
    s32 temp_a1;
    s32 cond;
    s32 i, j;

    if (isInitialCAll) {
        big = heap_malloc(sizeof(*big));
        evt_set_variable(script, MapVar(0), (s32) big);
        temp_a1 = evt_get_variable(script, GameByte(0));

        for (i = 0; i < ARRAY_COUNT(big->unk_48); i++) {
            for (j = 0; j < ARRAY_COUNT(big->unk_48[0]); j++) {
                big->unk_48[i][j] = 0;
            }
        }

        for (j = 0, inner = &big->unk_00[0]; j < ARRAY_COUNT(big->unk_48); j++, inner++) {
            if (temp_a1 < 85) {
                inner->unk_00 = D_802424F0_D81250[j][0];
                inner->unk_02 = D_802424F0_D81250[j][1];
                inner->unk_14 = D_802424F0_D81250[j][2];
            } else {
                inner->unk_00 = D_80242514_D81274[j][0];
                inner->unk_02 = D_80242514_D81274[j][1];
                inner->unk_14 = D_80242514_D81274[j][2];
            }
            inner->unk_04 = inner->unk_0C = (inner->unk_00 * 50) + 50;
            inner->unk_08 = inner->unk_10 = (inner->unk_02 * 50) + 75;
            big->unk_48[inner->unk_02][inner->unk_00] = -1;
        }
        evt_set_variable(script, MapVar(3), 270);
        evt_set_variable(script, MapVar(4), 270);
        evt_set_variable(script, MapVar(5), 270);
    }

    big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    inner = &big->unk_00[0];
    for (j = 0; j < ARRAY_COUNT(big->unk_48); j++, inner++) {
        if (inner->unk_04 < inner->unk_0C) {
            inner->unk_04 += 1.25f;
        }
        if (inner->unk_04 > inner->unk_0C) {
            inner->unk_04 -= 1.25f;
        }
        if (inner->unk_08 < inner->unk_10) {
            inner->unk_08 += 1.25f;
        }
        if (inner->unk_08 > inner->unk_10) {
            inner->unk_08 -= 1.25f;
        }
    }

    cond = FALSE;
    for (i = 0; i < ARRAY_COUNT(big->unk_48); i++) {
        for (j = 0; j < ARRAY_COUNT(big->unk_48[0]); j++) {
            if (big->unk_48[i][j] > 0) {
                big->unk_48[i][j]--;
            }

            if (big->unk_48[i][j] != D_80242538_D81298[i][j]) {
                cond = TRUE;
            }
        }
    }

    if (!cond) {
        evt_set_variable(script, MapVar(1), 1);
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80240818_D7F578(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    f32 temp_f20 = evt_get_float_variable(script, *args++);
    UnkPra31Big* big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &big->unk_00[idx];

    structPtr->unk_14 = temp_f20;
    return ApiStatus_DONE2;
}

ApiStatus func_80240894_D7F5F4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31Big* big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &big->unk_00[idx];
    s32 var_s0;
    s32 var_s1;
    s32 i;

    script->varTable[0] = 0;

    switch ((s32) structPtr->unk_14) {
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

    for (i = 0; i < ARRAY_COUNT(big->unk_48); i++) {
        if (i != idx &&
            var_s0 == big->unk_00[i].unk_00 &&
            var_s1 == big->unk_00[i].unk_02)
        {
            script->varTable[0] = 1;
        }
    }

    if (var_s0 < 0) {
        script->varTable[0] = 1;
    }
    if (var_s0 >= ARRAY_COUNT(big->unk_48[0])) {
        script->varTable[0] = 1;
    }
    if (var_s1 < 0) {
        script->varTable[0] = 1;
    }
    if (var_s1 >= ARRAY_COUNT(big->unk_48)) {
        script->varTable[0] = 1;
    }
    if (script->varTable[0] == 1 && gPlayerStatusPtr->actionState == ACTION_STATE_PUSHING_BLOCK) {
        set_action_state(ACTION_STATE_IDLE);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80240A3C_D7F79C(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31Big* big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &big->unk_00[idx];

    big->unk_48[structPtr->unk_02][structPtr->unk_00] = 20;

    switch ((s32) structPtr->unk_14) {
        case 0:
            structPtr->unk_02--;
            break;
        case 90:
            structPtr->unk_00++;
            break;
        case 180:
            structPtr->unk_02++;
            break;
        case 270:
            structPtr->unk_00--;
    }

    big->unk_48[structPtr->unk_02][structPtr->unk_00] = -1;
    structPtr->unk_0C = ((structPtr->unk_00 * 50) + 50);
    structPtr->unk_10 = ((structPtr->unk_02 * 50) + 75);
    return ApiStatus_DONE2;
}

ApiStatus func_80240BBC_D7F91C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31Big* big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &big->unk_00[idx];
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
    UnkPra31Big* big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &big->unk_00[idx];
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
    UnkPra31Big* big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &big->unk_00[idx];

    evt_set_float_variable(script, LocalVar(0), structPtr->unk_04);
    evt_set_float_variable(script, LocalVar(1), -structPtr->unk_08);
    evt_set_float_variable(script, LocalVar(2), clamp_angle(structPtr->unk_14 + 90.0));
    return ApiStatus_DONE2;
}

ApiStatus func_80240F2C_D7FC8C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++);
    UnkPra31Big* big = (UnkPra31Big*) evt_get_variable(script, MapVar(0));
    UnkPra31* structPtr = &big->unk_00[idx];

    evt_set_float_variable(script, LocalVar(0), structPtr->unk_04);
    evt_set_float_variable(script, LocalVar(1), structPtr->unk_08);
    evt_set_float_variable(script, LocalVar(2), clamp_angle(structPtr->unk_14));
    return ApiStatus_DONE2;
}

ApiStatus func_80240FD0_D7FD30(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->animFlags |= PA_FLAG_PUSHED_ALBINO_DINO;
    return ApiStatus_DONE2;
}

#include "world/common/todo/UnkFunc11.inc.c"
