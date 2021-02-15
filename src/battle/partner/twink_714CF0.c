#include "common.h"

ApiStatus func_80238000_714CF0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = BATTLE_STATUS;

    if (battleStatus->flags2 & 0x40) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/twink_714CF0", func_80238028_714D18);
