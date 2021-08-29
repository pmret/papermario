#include "common.h"

ApiStatus func_80282880(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->position.x += (script->varTable[0] - playerStatus->position.x) / 2;
    playerStatus->position.z += (script->varTable[2] - playerStatus->position.z) / 2;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/script_api/7E3700", func_802828DC);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80282C40);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80282E30);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283080);

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283174);

ApiStatus CheckActionState(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;
    s32 var = evt_get_float_variable(script, *args);

    evt_set_variable(script, a0, gPlayerActionState == var);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/script_api/7E3700", func_80283240);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", CreatePushBlockGrid, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", SetPushBlock, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", GetPushBlock, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", GetGridIndexFromPos, Evt* script, s32 isInitialCall);

INCLUDE_ASM(ApiStatus, "world/script_api/7E3700", SetPushBlockFallEffect, Evt* script, s32 isInitialCall);
