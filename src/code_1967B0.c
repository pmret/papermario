#include "common.h"

INCLUDE_ASM(s32, "code_1967B0", LoadItemScript);

INCLUDE_ASM(s32, "code_1967B0", LoadFreeItemScript);

ApiStatus LoadMoveScript(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32* moveScript = gMoveScriptTable[battleStatus->selectedMoveID];

    dma_copy(moveScript[0], moveScript[1], moveScript[2]);
    script->varTable[0] = moveScript[3];
    
    deduct_current_move_fp();

    if (gBattleStatus.flags2 & 0x8000000) {
        enable_player_blur();
    }

    return ApiStatus_DONE2;
}
