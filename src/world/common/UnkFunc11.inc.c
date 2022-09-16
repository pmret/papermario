#include "common.h"
#include "npc.h"

ApiStatus N(UnkFunc11)(Evt* script, s32 isInitialCall) {
    s32 pushableColliderID = evt_get_variable(script, *script->ptrReadPos);
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;

    if (((collisionStatus->pushingAgainstWall != pushableColliderID) && (playerStatus->actionState == ACTION_STATE_PUSHING_BLOCK)) ||
        playerStatus->enableCollisionOverlapsCheck || playerStatus->inputEnabledCounter) {
        set_action_state(ACTION_STATE_IDLE);
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    if (collisionStatus->pushingAgainstWall != pushableColliderID) {
        script->varTable[0] = 0;
    } else if ((playerStatus->actionState != ACTION_STATE_PUSHING_BLOCK) && (playerStatus->actionState != ACTION_STATE_WALK) &&
               (playerStatus->actionState != ACTION_STATE_RUN)) {
        script->varTable[0] = 0;
    } else if (playerStatus->animFlags & PA_FLAGS_HOLDING_WATT) {
        script->varTable[0] = 0;
    } else {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
