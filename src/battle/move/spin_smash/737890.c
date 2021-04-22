#include "common.h"

#define NAMESPACE battle_move_spin_smash

ApiStatus func_802A1000_737890(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->currentPos.x + 20.0f;
    f32 yPos = playerActor->currentPos.y + 15.0f;
    f32 zPos = playerActor->currentPos.z + 5.0f;

    func_80070970(0, xPos, yPos, zPos, 6, 20);

    return ApiStatus_DONE2;
}

ApiStatus func_802A1074_737904(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 xPos = playerActor->currentPos.x + 20.0f;
    f32 yPos = playerActor->currentPos.y + 15.0f;
    f32 zPos = playerActor->currentPos.z + 5.0f;

    func_800709D0(0, xPos, yPos, zPos, 1.0f, 20);

    return ApiStatus_DONE2;
}

#include "world/common/IsBerserkerEquipped.inc.c"

#include "world/common/IsRightOnEquipped.inc.c"
