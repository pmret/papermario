#include "common.h"
#include "map.h"

ApiStatus N(UnkRotatePlayer)(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 60;
    }

    playerStatus->targetYaw += 30.0f;
    if (playerStatus->targetYaw >= 360.0f) {
        playerStatus->targetYaw -= 360.0f;
    }

    script->functionTemp[0]--;

    return (script->functionTemp[0] >> 0x1F) & ApiStatus_DONE2;
}
