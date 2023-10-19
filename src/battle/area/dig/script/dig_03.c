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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(3)
    EVT_CALL(SetCamViewport, CAM_BATTLE, 29, 20, 262, 177)
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(N(SetupDemoPlayerMove))
    EVT_CALL(SetBattleState, BATTLE_STATE_PARTNER_MOVE)
    EVT_WAIT(90)
    EVT_RETURN
    EVT_END
};
