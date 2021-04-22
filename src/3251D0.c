#include "common.h"

ApiStatus func_802BD100_3251D0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);

    func_8006FEF0(0, a, b, c, 60.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802BD1AC_32527C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    func_80071090(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus func_802BD26C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    func_80071090(1, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus func_802BD32C(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;
    s32 newHP = playerData->curHP + get_variable(script, *script->ptrReadPos);

    if (newHP > playerData->curMaxHP) {
        newHP = playerData->curMaxHP;
    }

    if (newHP <= 0) {
        newHP = 1;
    }

    playerData2->curHP = newHP;
    return ApiStatus_DONE2;
}

ApiStatus func_802BD388(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    PlayerData* playerData2 = &gPlayerData;
    s32 newFP = playerData->curFP + get_variable(script, *script->ptrReadPos);

    if (newFP > playerData->curMaxFP) {
        newFP = playerData->curMaxFP;
    }

    if (newFP <= 0) {
        newFP = 1;
    }

    playerData2->curFP = newFP;
    return ApiStatus_DONE2;
}

ApiStatus func_802BD3E4(ScriptInstance* script, s32 isInitialCall) {
    set_time_freeze_mode(2);
    OVERRIDE_FLAG_SET(0x200000);
    return ApiStatus_DONE2;
}

ApiStatus func_802BD41C(ScriptInstance* script, s32 isInitialCall) {
    set_time_freeze_mode(0);
    OVERRIDE_FLAG_UNSET(0x200000);
    return ApiStatus_DONE2;
}

ApiStatus func_802BD458(ScriptInstance* script, s32 isInitialCall) {
    s32 itemIdx = get_variable(script, *script->ptrReadPos);
    s32 var15;

    script->varTable[11] = (&gItemTable[itemIdx])->potencyA;
    script->varTable[12] = (&gItemTable[itemIdx])->potencyB;
    script->varTable[13] = 0;

    if ((&gItemTable[itemIdx])->typeFlags & 0x100) {
        script->varTable[13] = 1;
    }

    var15 = 0;
    if (script->varTable[11] < 0 || (script->varTable[11] <= 0 && script->varTable[12] < 0)) {
        var15 = 1;
    }
    script->varTable[15] = var15;

    return ApiStatus_DONE2;
}

ApiStatus func_802BD4E8(ScriptInstance* script, s32 isInitialCall) {
    remove_consumable();
    return ApiStatus_DONE2;
}
