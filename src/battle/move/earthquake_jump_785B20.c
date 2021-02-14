#include "common.h"

ApiStatus func_802A1000_785B20(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* secondBattleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 posX = playerActor->currentPos.x;
    f32 posY = playerActor->currentPos.y;
    f32 posZ = playerActor->currentPos.z;
    f32 goalX = playerActor->movePos.goal.x;
    f32 goalY = playerActor->movePos.goal.y;
    f32 goalZ = playerActor->movePos.goal.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (secondBattleStatus->unk_83 != 0) {
        if (script->varTable[0] < 6) {
            script->varTable[0] = 6;
        }
    } else if (script->varTable[0] < 12) {
        script->varTable[0] = 12;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/move/earthquake_jump_785B20", func_802A10E4_785C04);
