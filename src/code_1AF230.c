#include "common.h"

typedef struct StarPower { void* dmaStart; void* dmaEnd; void* dmaDest; Bytecode* init; } StarPower;

extern StarPower D_8029C7D0[13];

typedef struct WhateverThisIs { s8 starpoints; s8 a; s8 b; s8 c; s32 w; s32 x; s32 y; s32 z; } WhateverThisIs;

extern WhateverThisIs D_8008F071[];

ApiStatus LoadStarPowerScript(ScriptInstance *script, s32 isInitialCall) {
    BattleStatus *battleStatus = &gBattleStatus;
    PlayerData *playerData = &gPlayerData;
    s16 selectedItemID;

    playerData->specialBarsFilled -= D_8008F071[battleStatus->selectedMoveID].starpoints * 256;
    selectedItemID = battleStatus->selectedItemID;
    dma_copy((&D_8029C7D0[selectedItemID])->dmaStart, (&D_8029C7D0[selectedItemID])->dmaEnd, (&D_8029C7D0[selectedItemID])->dmaDest);
    script->varTable[0] = (&D_8029C7D0[selectedItemID])->init;
    return ApiStatus_DONE2;
}
