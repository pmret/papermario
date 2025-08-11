#include "../area.h"

#define NAMESPACE A(dig_01_script)

#include "common/SetDemoBattleBeginDelay.inc.c"

API_CALLABLE(N(SetupDemoPlayerMove)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = BTL_MENU_TYPE_SMASH;
    battleStatus->selectedMoveID = MOVE_HAMMER1;
    battleStatus->moveArgument = gCurrentEncounter.hitTier;
    battleStatus->curTargetListFlags = gMoveTable[MOVE_HAMMER1].flags;

    create_current_pos_target_list(player);
    player->selectedTargetIndex = 0;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartID = selectableTarget->partID;

    return ApiStatus_DONE2;
}

EvtScript NAMESPACE = {
    Wait(3)
    Call(SetCamViewport, CAM_BATTLE, 29, 20, 262, 177)
    Call(EnableBattleStatusBar, false)
    Set(LVar0, 15)
    Call(N(SetDemoBattleBeginDelay))
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Call(N(SetupDemoPlayerMove))
    Call(SetBattleState, BATTLE_STATE_PLAYER_MOVE)
    Wait(10000)
    Return
    End
};
