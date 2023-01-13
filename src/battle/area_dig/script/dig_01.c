#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_dig_dig_01_script

#include "common/Set80218630_Var0.inc.c"

ApiStatus func_80218644_6DE404(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = BTL_MENU_TYPE_SMASH;
    battleStatus->selectedMoveID = MOVE_HAMMER1;
    battleStatus->moveArgument = gCurrentEncounter.hitTier;
    battleStatus->currentTargetListFlags = gMoveTable[MOVE_HAMMER1].flags;

    player_create_target_list(player);
    player->selectedTargetIndex = 0;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

EvtScript NAMESPACE = {
    EVT_WAIT(3)
    EVT_CALL(SetCamViewport, 1, 29, 20, 262, 177)
    EVT_CALL(func_802535B4, 0)
    EVT_SET(LVar0, 15)
    EVT_CALL(N(Set80218630_Var0))
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(func_80218644_6DE404)
    EVT_CALL(SetBattleState, BATTLE_STATE_PLAYER_MOVE)
    EVT_WAIT(10000)
    EVT_RETURN
    EVT_END
};
