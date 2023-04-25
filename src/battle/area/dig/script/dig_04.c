#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE b_area_dig_dig_04_script

API_CALLABLE(N(SetupDemoPlayerMove)) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s32 selectedItemID;
    Actor* player = battleStatus->playerActor;
    SelectableTarget* selectableTarget;

    battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
    battleStatus->moveArgument = ITEM_THUNDER_RAGE;
    selectedItemID = battleStatus->moveArgument;
    battleStatus->selectedMoveID = 0;
    battleStatus->currentAttackElement = 0;
    playerData->invItems[0] = selectedItemID;
    battleStatus->currentTargetListFlags = gItemTable[playerData->invItems[0]].targetFlags | TARGET_FLAG_8000;

    player_create_target_list(player);
    player->selectedTargetIndex = 0;
    selectableTarget = &player->targetData[player->targetIndexList[player->selectedTargetIndex]];
    player->targetActorID = selectableTarget->actorID;
    player->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

EvtScript NAMESPACE = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(3)
    EVT_CALL(SetCamViewport, CAM_BATTLE, 29, 20, 262, 177)
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(N(SetupDemoPlayerMove))
    EVT_CALL(SetBattleState, BATTLE_STATE_PLAYER_MOVE)
    EVT_RETURN
    EVT_END
};
