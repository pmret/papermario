#include "common.h"

#define NAMESPACE b_area_dig

#include "common/Set80218630_Var0.inc.c"

ApiStatus func_80218644_6DE404(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = 1;
    battleStatus->selectedMoveID = MOVE_HAMMER1;
    battleStatus->selectedItemID = gCurrentEncounter.hitTier;
    battleStatus->currentTargetListFlags = gMoveTable[MOVE_HAMMER1].flags;

    player_create_target_list(player);
    player->selectedTargetIndex = 0;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}
