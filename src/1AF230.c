#include "common.h"

typedef struct StarPowerEntry {
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ void* dmaDest;
    /* 0x10 */ Bytecode* init;
} StarPowerEntry; // size = 0x14

extern StarPowerEntry D_8029C7D0[13];

typedef struct StarPowerDesc {
    /* 0x00 */ s8 starPoints;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} StarPowerDesc; // size = 0x14

extern StarPowerDesc D_8008F071[];

ApiStatus LoadStarPowerScript(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s16 selectedItemID;

    playerData->specialBarsFilled -= D_8008F071[battleStatus->selectedMoveID].starPoints * 256;
    selectedItemID = battleStatus->selectedItemID;
    dma_copy((&D_8029C7D0[selectedItemID])->dmaStart, (&D_8029C7D0[selectedItemID])->dmaEnd,
             (&D_8029C7D0[selectedItemID])->dmaDest);
    script->varTable[0] = (&D_8029C7D0[selectedItemID])->init;
    return ApiStatus_DONE2;
}
