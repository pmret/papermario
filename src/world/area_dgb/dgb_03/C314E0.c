#include "dgb_03.h"

ApiStatus N(func_80240000_C314E0)(ScriptInstance *script, s32 isInitialCall) {
    s32 var = get_variable(script, *script->ptrReadPos);
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;

    if (((collisionStatus->pushingAgainstWall != var) && (playerStatus->actionState == 20)) ||
        playerStatus->enableCollisionOverlapsCheck || playerStatus->statusMenuCounterinputEnabledCounter) {
        set_action_state(0);
        script->varTable[0] = 0;
        return ApiStatus_DONE2;
    }

    if (collisionStatus->pushingAgainstWall != var) {
        script->varTable[0] = 0;
    } else if ((playerStatus->actionState != 20) && (playerStatus->actionState != 1) &&
               (playerStatus->actionState != 2)) {
        script->varTable[0] = 0;
    } else if (playerStatus->animFlags & 1) {
        script->varTable[0] = 0;
    } else {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802400BC_C3159C)(ScriptInstance *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 posX, posY, posZ, posW;

    if (script->varTable[5] == 0) {
        playerStatus->position.x = script->varTable[0];
    } else {
        playerStatus->position.z = script->varTable[0];
    }

    posX = playerStatus->position.x;
    posY = playerStatus->position.y + 10.0f;
    posZ = playerStatus->position.z;
    posW = 40.0f;
    func_800DCB7C(0, &posX, &posY, &posZ, &posW);
    playerStatus->position.x = posX;
    playerStatus->position.y = posY;
    playerStatus->position.z = posZ;

    return ApiStatus_DONE2;
}

#include "world/common/SetEntityFlags100000.inc.c"

#include "world/common/GetEntityPosition.inc.c"
