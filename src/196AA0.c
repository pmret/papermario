#include "common.h"

INCLUDE_ASM(s32, "196AA0", LoadActionCommand);

INCLUDE_ASM(s32, "196AA0", func_80268224);

INCLUDE_ASM(s32, "196AA0", func_80268284);

INCLUDE_ASM(s32, "196AA0", func_80268770);

INCLUDE_ASM(s32, "196AA0", func_80268798);

INCLUDE_ASM(s32, "196AA0", func_802687BC);

INCLUDE_ASM(s32, "196AA0", func_802687E4);

INCLUDE_ASM(s32, "196AA0", func_8026880C);

INCLUDE_ASM(s32, "196AA0", func_80268834);

INCLUDE_ASM(s32, "196AA0", func_80268858);

INCLUDE_ASM(s32, "196AA0", func_80268938);

INCLUDE_ASM(s32, "196AA0", func_80268AF8);

INCLUDE_ASM(s32, "196AA0", func_80268C9C);

INCLUDE_ASM(s32, "196AA0", func_80268E88);

INCLUDE_ASM(s32, "196AA0", check_block_input);

INCLUDE_ASM(s32, "196AA0", func_80269118);

INCLUDE_ASM(s32, "196AA0", func_80269160);

ApiStatus func_8026919C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_434 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "196AA0", func_802691C8);

ApiStatus GetActionSuccess(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

ApiStatus SetActionSuccess(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.actionSuccess = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_802692EC(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_83 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_80269318(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_83);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "196AA0", func_80269344);

INCLUDE_ASM(s32, "196AA0", func_80269370);

INCLUDE_ASM(s32, "196AA0", func_8026939C);

ApiStatus func_802693F0(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 &= ~0x4000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "196AA0", CloseActionCommandInfo);

INCLUDE_ASM(s32, "196AA0", func_80269470);

INCLUDE_ASM(s32, "196AA0", func_802694A4);

ApiStatus GetActionSuccessCopy(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.actionSuccess);
    return ApiStatus_DONE2;
}

ApiStatus func_80269524(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_86);
    return ApiStatus_DONE2;
}

ApiStatus func_80269550(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_86 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus GetBlockResult(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.blockResult);
    return ApiStatus_DONE2;
}

ApiStatus func_802695A8(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_84);
    return ApiStatus_DONE2;
}

ApiStatus func_802695D4(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_84 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus func_80269600(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_85);
    return ApiStatus_DONE2;
}

ApiStatus func_8026962C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_85 = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
