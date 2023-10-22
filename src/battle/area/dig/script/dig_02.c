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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(3)
    EVT_CALL(SetCamViewport, CAM_BATTLE, 29, 20, 262, 177)
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(N(SetupDemoPlayerMove))
    EVT_CALL(SetBattleState, BATTLE_STATE_PLAYER_MOVE)
    EVT_WAIT(130)
    EVT_LOOP(30)
        EVT_CALL(SetCommandAutoSuccess, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
