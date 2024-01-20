#include "../area.h"

#define NAMESPACE A(dig_02_script)

API_CALLABLE(N(SetupDemoPlayerMove)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = BTL_MENU_TYPE_JUMP;
    battleStatus->selectedMoveID = MOVE_POWER_BOUNCE;
    battleStatus->moveArgument = gCurrentEncounter.hitTier;
    battleStatus->curTargetListFlags = gMoveTable[MOVE_POWER_BOUNCE].flags;

    create_current_pos_target_list(player);
    player->selectedTargetIndex = 1;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartID = selectableTarget->partID;

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
    Call(SetBattleState, BATTLE_STATE_PLAYER_MOVE)
    Wait(130)
    Loop(30)
        Call(SetCommandAutoSuccess, FALSE)
        Wait(1)
    EndLoop
    Return
    End
};
