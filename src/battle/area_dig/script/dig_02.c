#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_dig_dig_02_script

ApiStatus func_802186E0_6DE4A0(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = BTL_MENU_TYPE_JUMP;
    battleStatus->selectedMoveID = MOVE_POWER_BOUNCE;
    battleStatus->moveArgument = gCurrentEncounter.hitTier;
    battleStatus->currentTargetListFlags = gMoveTable[MOVE_POWER_BOUNCE].flags;

    player_create_target_list(player);
    player->selectedTargetIndex = 1;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

EvtScript NAMESPACE = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(3)
    EVT_CALL(SetCamViewport, 1, 29, 20, 262, 177)
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(func_802186E0_6DE4A0)
    EVT_CALL(SetBattleState, BATTLE_STATE_PLAYER_MOVE)
    EVT_WAIT(130)
    EVT_LOOP(30)
        EVT_CALL(SetCommandAutoSuccess, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};
