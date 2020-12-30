#include "common.h"

#define NAMESPACE b_area_dig

#include "common/Set80218630_Var0.inc.c"

extern s32 D_8008F0A0;

ApiStatus func_80218644_6DE404(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = BATTLE_STATUS;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = 1;
    battleStatus->selectedMoveID = 3;
    battleStatus->selectedItemID = gCurrentEncounter.hitTier;
    battleStatus->currentTargetListFlags = D_8008F0A0;

    player_create_target_list(player);
    player->selectedTargetIndex = 0;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}
