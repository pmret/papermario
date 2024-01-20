#include "../area.h"

#define NAMESPACE A(dig_04_script)

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
    battleStatus->curAttackElement = 0;
    playerData->invItems[0] = selectedItemID;
    battleStatus->curTargetListFlags = gItemTable[selectedItemID].targetFlags | TARGET_FLAG_PRIMARY_ONLY;

    create_current_pos_target_list(player);
    player->selectedTargetIndex = 0;
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
    Return
    End
};
