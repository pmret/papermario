#include "common.h"

ApiStatus func_802A1000_74F130(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = *(&gBattleStatus.unk_83);
    script->varTable[1] = 15;

    if (is_ability_active(Ability_BERSERKER) != FALSE) {
        script->varTable[0] = 0;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1050_74F180(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;

    if (is_ability_active(Ability_RIGHT_ON) != FALSE) {
        script->varTable[0] = 1;
    }

    if ((gBattleStatus.flags1 & 0x1000) != FALSE) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A10A4_74F1D4(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = 0;

    if (battleStatus->hammerCharge >= 99) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A10C8_74F1F8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    func_800718D0(0, var1, var2, var3, 1.0f, 60);
    battleStatus->hammerCharge += 1;

    if (battleStatus->hammerCharge >= 100) {
        (*&battleStatus)->hammerCharge = 99; // TODO: macro?
    }

    battleStatus->jumpCharge = 0;
    battleStatus->flags1 = ((battleStatus->flags1 | 0x10000000) & 0xDFFFFFFF);

    return ApiStatus_DONE2;
}

ApiStatus func_802A11CC_74F2FC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);

    func_800720B0(6, (var0 + 10), (var1 + 18), var2, var3, 45);

    return ApiStatus_DONE2;
}
