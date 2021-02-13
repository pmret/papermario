#include "common.h"

typedef struct StarPowerEntry {
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ void* dmaDest;S
    /* 0x10 */ Bytecode* init;
} StarPowerEntry; // size = 0x14

extern StarPowerEntry D_8029C7D0[13];

typedef struct StarPowerDesc {
    /* 0x00 */ s8 starPoints;
    /* 0x01 */ s8 a;
    /* 0x02 */ s8 b;
    /* 0x03 */ s8 c;
    /* 0x04 */ s32 w;
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 y;
    /* 0x10 */ s32 z;
} StarPowerDesc; // size = 0x14

extern StarPowerDesc D_8008F071[];

ApiStatus LoadStarPowerScript(ScriptInstance *script, s32 isInitialCall) {
    BattleStatus *battleStatus = &gBattleStatus;
    PlayerData *playerData = &gPlayerData;
    s16 selectedItemID;

    playerData->specialBarsFilled -= D_8008F071[battleStatus->selectedMoveID].starPoints * 256;
    selectedItemID = battleStatus->selectedItemID;
    dma_copy((&D_8029C7D0[selectedItemID])->dmaStart, (&D_8029C7D0[selectedItemID])->dmaEnd, (&D_8029C7D0[selectedItemID])->dmaDest);
    script->varTable[0] = (&D_8029C7D0[selectedItemID])->init;
    return ApiStatus_DONE2;
}
