#include "common.h"

extern s32 D_80293B80[];

typedef struct BattleItemTableEntry {
    /* 0x0 */ u8* romStart;
    /* 0x4 */ u8* romEnd;
    /* 0x8 */ u8* vramStart;
    /* 0xC */ u8* vramEnd;
} BattleItemTableEntry; // size = 0x10

extern BattleItemTableEntry gBattleItemTable[];

ApiStatus LoadItemScript(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    s16 itemID = battleStatus->selectedItemID;
    StaticItem* item = &gItemTable[itemID];
    s32 i = 0;
    s32* itemPtr;

    while (1) {
        if (playerData->invItems[i] == itemID) {
            playerData->invItems[i] = 0;
            break;
        }
        i++;
    }
    sort_items();

    if (battleStatus->selectedMoveID == MOVE_DOUBLE_DIP) {
        if (battleStatus->itemUsesLeft == 2) {
            deduct_current_move_fp();
        }
    }

    if (battleStatus->selectedMoveID == MOVE_TRIPLE_DIP) {
        if (battleStatus->itemUsesLeft == 3) {
            deduct_current_move_fp();
        }
    }
    
    itemPtr = &D_80293B80[0];
    for (i = 0; *itemPtr != ITEM_NONE; i++, itemPtr++) {
        if (*itemPtr == battleStatus->selectedItemID) {
            break;
        }
    }

    if (*itemPtr == ITEM_NONE) {
        if (item->typeFlags & 0x80) {
            i = 0;
        } else {
            i = 1;
        }
    }

    dma_copy(gBattleItemTable[i].romStart, gBattleItemTable[i].romEnd, gBattleItemTable[i].vramStart);

    script->varTable[0] = (s32) gBattleItemTable[i].vramEnd;
    script->varTable[1] = 0;

    return ApiStatus_DONE2;
}

ApiStatus LoadFreeItemScript(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->playerActor;
    StaticItem* item = &gItemTable[battleStatus->selectedItemID];
    SelectableTarget* target;
    s32* itemPtr;
    s32 i;

    battleStatus->currentTargetListFlags = item->targetFlags | 0x8000;
    battleStatus->currentAttackElement = 0;

    player_create_target_list(actor);
    target = &actor->targetData[actor->targetIndexList[0]];

    battleStatus->currentTargetID = target->actorID;
    battleStatus->currentTargetPart = target->partID;

    itemPtr = &D_80293B80[0];
    for (i = 0; *itemPtr != ITEM_NONE; i++, itemPtr++) {
        if (*itemPtr == battleStatus->selectedItemID){
            break;
        }
    }

    if (*itemPtr == ITEM_NONE) {
        if (item->typeFlags & 0x80) {
            i = 0;
        } else {
            i = 1;
        }
    }

    dma_copy(gBattleItemTable[i].romStart, gBattleItemTable[i].romEnd, gBattleItemTable[i].vramStart);
    script->varTable[0] = (s32) gBattleItemTable[i].vramEnd;
    script->varTable[1] = 1;
    return ApiStatus_DONE2;
}

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
