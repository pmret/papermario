#include "common.h"
#include "map.h"

ApiStatus N(UnkMoveFunc1)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 posX = playerActor->currentPos.x;
    f32 posY = playerActor->currentPos.y;
    f32 posZ = playerActor->currentPos.z;
    f32 goalX = playerActor->walk.goalPos.x;
    f32 goalY = playerActor->walk.goalPos.y;
    f32 goalZ = playerActor->walk.goalPos.z;

    script->varTable[0].s = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0].s > 20) {
        script->varTable[0].s = 20;
    }

    if (battleStatus->unk_83 != 0) {
        if (script->varTable[0].s < 6) {
            script->varTable[0].s = 6;
        }
    } else if (script->varTable[0].s < 12) {
        script->varTable[0].s = 12;
    }

    return ApiStatus_DONE2;
}
