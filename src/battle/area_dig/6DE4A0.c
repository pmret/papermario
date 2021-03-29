#include "common.h"

#define NAMESPACE b_area_dig

extern s32 D_8008F2E4;
extern s32 D_8008FC44;

ApiStatus func_802186E0_6DE4A0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = 0;
    battleStatus->selectedMoveID = 0x20;
    battleStatus->selectedItemID = gCurrentEncounter.hitTier;
    battleStatus->currentTargetListFlags = D_8008F2E4;

    player_create_target_list(player);
    player->selectedTargetIndex = 1;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

ApiStatus func_80218770_6DE530(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = 6;
    do {} while(0);
    battleStatus->selectedItemID = 0;
    battleStatus->selectedMoveID = 0x98;
    battleStatus->currentTargetListFlags = D_8008FC44;

    player_create_target_list(partner);
    partner->selectedTargetIndex = 0;
    selectableTarget = &partner->targetData[partner->targetIndexList[partner->selectedTargetIndex]];
    partner->targetActorID = selectableTarget->actorID;
    partner->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

ApiStatus func_802187F0_6DE5B0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s32 selectedItemID;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = 2;
    battleStatus->selectedItemID = ITEM_THUNDER_RAGE;
    selectedItemID = battleStatus->selectedItemID;
    battleStatus->selectedMoveID = 0;
    battleStatus->currentAttackElement = 0;
    playerData->invItems[0] = selectedItemID;
    battleStatus->currentTargetListFlags = gItemTable[playerData->invItems[0]].targetFlags | 0x8000;

    player_create_target_list(player);
    player->selectedTargetIndex = 0;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

