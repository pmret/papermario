#include "common.h"
#include "npc.h"
#include "battle/action_cmd.h"

API_CALLABLE(N(UnkMoveFunc1)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 posX = playerActor->curPos.x;
    f32 posY = playerActor->curPos.y;
    f32 posZ = playerActor->curPos.z;
    f32 goalX = playerActor->state.goalPos.x;
    f32 goalY = playerActor->state.goalPos.y;
    f32 goalZ = playerActor->state.goalPos.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] > 20) {
        script->varTable[0] = 20;
    }

    if (battleStatus->actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED) {
        if (script->varTable[0] < 6) {
            script->varTable[0] = 6;
        }
    } else if (script->varTable[0] < 12) {
        script->varTable[0] = 12;
    }

    return ApiStatus_DONE2;
}
