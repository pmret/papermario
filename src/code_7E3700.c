#include "common.h"

INCLUDE_ASM(s32, "code_7E3700", func_80282880);

INCLUDE_ASM(s32, "code_7E3700", func_802828DC);

INCLUDE_ASM(s32, "code_7E3700", func_80282C40);

INCLUDE_ASM(s32, "code_7E3700", func_80282E30);

INCLUDE_ASM(s32, "code_7E3700", func_80283080);

INCLUDE_ASM(s32, "code_7E3700", func_80283174);

ApiStatus CheckActionState(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;
    s32 var = get_float_variable(script, *args);

    set_variable(script, a0, gPlayerActionState == var);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_7E3700", func_80283240);

INCLUDE_ASM(s32, "code_7E3700", CreatePushBlockGrid);

INCLUDE_ASM(s32, "code_7E3700", SetPushBlock);

INCLUDE_ASM(s32, "code_7E3700", GetPushBlock);

INCLUDE_ASM(s32, "code_7E3700", GetGridIndexFromPos);

INCLUDE_ASM(s32, "code_7E3700", SetPushBlockFallEffect);

INCLUDE_ASM(s32, "code_7E3700", func_80283810);

INCLUDE_ASM(s32, "code_7E3700", TeleportPartnerToPlayer);

INCLUDE_ASM(s32, "code_7E3700", func_80283908);

INCLUDE_ASM(s32, "code_7E3700", func_80283A50);

INCLUDE_ASM(s32, "code_7E3700", func_80283B88);

INCLUDE_ASM(s32, "code_7E3700", func_80283BB0);

INCLUDE_ASM(s32, "code_7E3700", func_80283BD0);

INCLUDE_ASM(s32, "code_7E3700", func_80283C34);

INCLUDE_ASM(s32, "code_7E3700", func_80283D00);

INCLUDE_ASM(s32, "code_7E3700", func_80283D6C);

INCLUDE_ASM(s32, "code_7E3700", func_80283DF0);

INCLUDE_ASM(s32, "code_7E3700", func_80283E2C);
