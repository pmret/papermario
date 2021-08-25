#include "common.h"

INCLUDE_ASM(s32, "1967B0", LoadItemScript);

extern s32 D_80293B80;

typedef struct BattleItemTableEntry {
    /* 0x0 */ u8* romStart;
    /* 0x4 */ u8* romEnd;
    /* 0x8 */ u8* vramStart;
    /* 0xC */ u8* vramEnd;
} BattleItemTableEntry; // size = 0x10

extern BattleItemTableEntry gBattleItemTable[];

INCLUDE_ASM(s32, "1967B0", LoadFreeItemScript);

ApiStatus LoadMoveScript(Evt* script, s32 isInitialCall) {
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
