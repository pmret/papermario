#include "common.h"

ApiStatus func_802A1000_74AD90(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = *(&gBattleStatus.unk_83);
    script->varTable[1] = 15;

    if (is_ability_active(Ability_BERSERKER) != FALSE) {
        script->varTable[0] = 0;
        script->varTable[1] = 40;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1050_74ADE0(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;

    if (is_ability_active(Ability_RIGHT_ON) != FALSE) {
        script->varTable[0] = 1;
    }

    if ((gBattleStatus.flags1 & 0x1000) != FALSE) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A10A4_74AE34(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    if (script->varTable[10] == 0) {
        func_80070B50(TRUE, (var0 + 30), (var1 + 25), var2, 45.0f);
    } else {
        func_80070B50(FALSE, (var0 + 30), (var1 + 25), var2, 45.0f);
    }

    return ApiStatus_DONE2;
}
