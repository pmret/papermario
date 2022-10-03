#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_dig_dig_03_script

ApiStatus func_80218770_6DE530(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = 6;
    battleStatus->selectedItemID = 0;
    battleStatus->selectedMoveID = MOVE_SHELL_SHOT;
    battleStatus->currentTargetListFlags = gMoveTable[MOVE_SHELL_SHOT].flags;

    player_create_target_list(partner);
    partner->selectedTargetIndex = 0;
    selectableTarget = &partner->targetData[partner->targetIndexList[partner->selectedTargetIndex]];
    partner->targetActorID = selectableTarget->actorID;
    partner->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

EvtScript NAMESPACE = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(3)
    EVT_CALL(SetCamViewport, 1, 29, 20, 262, 177)
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(func_80218770_6DE530)
    EVT_CALL(SetBattleState, BATTLE_STATE_PARTNER_MOVE)
    EVT_WAIT(90)
    EVT_RETURN
    EVT_END
};
