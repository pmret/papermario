#include "common.h"

ApiStatus func_80238000_714CF0(ScriptInstance *arg0) {
    BattleStatus* battleStatus = BATTLE_STATUS;
    if ((battleStatus->flags2 & 0x40) != 0) {
        arg0->varTable[0] = 1;
    } else {
        arg0->varTable[0] = 0;
    }
    return ApiStatus_DONE2;
}
INCLUDE_ASM(s32, "battle/partner/twink_714CF0", func_80238028_714D18);
