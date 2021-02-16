#include "common.h"

ApiStatus func_80238000_6FAD10(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s16 selectedMoveID;
    s32 soundID;

    func_80070130(0, var0, var1, var2);
    selectedMoveID = battleStatus->selectedMoveID;

    switch (selectedMoveID) {
        case 146:
            if (script->varTable[10] > 0) {
                func_800701F0(1, var0, var1 + 20, var2);
            } else {
                func_800701F0(0, var0, var1 + 20, var2);
            }
            play_sound(8214);
            break;
        case 147:
            if (script->varTable[10] > 0) {
                func_800701F0(1, var0, var1 + 20, var2);
            } else {
                func_800701F0(0, var0, var1 + 20, var2);
            }
            play_sound(8215);
            break;
        case 148:
            if (script->varTable[10] > 0) {
                func_800701F0(2, var0, var1 + 20, var2);
            } else {
                func_800701F0(1, var0, var1 + 20, var2);
            }
            play_sound(8215);
            break;
        default:
            func_800701F0(0, var0, var1 + 20, var2);
            play_sound(8214);
            break;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/bombette_6FAD10", func_80238244_6FAF54);

INCLUDE_ASM(s32, "battle/partner/bombette_6FAD10", func_80238358_6FB068);

INCLUDE_ASM(s32, "battle/partner/bombette_6FAD10", func_8023849C_6FB1AC);

INCLUDE_ASM(s32, "battle/partner/bombette_6FAD10", func_80238590_6FB2A0);
