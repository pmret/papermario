#include "../area.h"

#define NAMESPACE A(dig_03_script)

API_CALLABLE(N(SetupDemoPlayerMove)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = BTL_MENU_TYPE_ABILITY;
    battleStatus->moveArgument = 0;
    battleStatus->selectedMoveID = MOVE_SHELL_SHOT;
    battleStatus->curTargetListFlags = gMoveTable[MOVE_SHELL_SHOT].flags;

    create_current_pos_target_list(partner);
    partner->selectedTargetIndex = 0;
    selectableTarget = &partner->targetData[partner->targetIndexList[partner->selectedTargetIndex]];
    partner->targetActorID = selectableTarget->actorID;
    partner->targetPartID = selectableTarget->partID;

    return ApiStatus_DONE2;
}

EvtScript NAMESPACE = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 1)
    Wait(3)
    Call(SetCamViewport, CAM_BATTLE, 29, 20, 262, 177)
    Call(EnableBattleStatusBar, FALSE)
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Call(N(SetupDemoPlayerMove))
    Call(SetBattleState, BATTLE_STATE_PARTNER_MOVE)
    Wait(90)
    Return
    End
};
