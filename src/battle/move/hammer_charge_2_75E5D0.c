#include "common.h"

extern s32 D_802A4350;

ApiStatus func_802A1000_75E5D0(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = *(&gBattleStatus.unk_83);
    script->varTable[1] = 15;

    if (is_ability_active(Ability_BERSERKER) != FALSE) {
        script->varTable[0] = 0;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1050_75E620(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;

    if (is_ability_active(Ability_RIGHT_ON) != FALSE) {
        script->varTable[0] = 1;
    }

    if ((gBattleStatus.flags1 & 0x1000) != FALSE) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A10A4_75E674(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = 0;

    if (battleStatus->hammerCharge >= 99) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A10C8_75E698(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = battleStatus; // TODO: macro?
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32* var4;

    func_800718D0(2, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A4350;
    *var4 = 0;
    if (battleStatus2->hammerCharge > 0) {
        *var4 = 1;
    }

    battleStatus2->hammerCharge += 3;

    if (battleStatus2->hammerCharge >= 100) {
        (*&battleStatus)->hammerCharge = 99; // TODO: macro?
    }

    battleStatus2->jumpCharge = 0;
    battleStatus->flags1 = (battleStatus->flags1 | 0x10000000) & 0xDFFFFFFF;

    return ApiStatus_DONE2;
}

ApiStatus func_802A11E8_75E7B8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    f32 var4 = get_float_variable(script, *args++);
    s32 var5 = 45;
    s32 var6 = 30;

    func_800720B0(6, (var1 + 10), (var2 + 18), var3, var4, var5);
    func_80070BB0(13, (var1 + 10), (var2 + 18), var3, var4, var6);

    return ApiStatus_DONE2;
}

ApiStatus func_802A12FC_75E8CC(ScriptInstance* script, s32 isInitialCall) {
    if (D_802A4350 == 0) {
        script->varTable[0] = 4;
    } else {
        script->varTable[0] = 5;
    }

    return ApiStatus_DONE2;
}
