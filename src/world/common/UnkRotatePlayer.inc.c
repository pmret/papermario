#include "common.h"

static ApiStatus UnkRotatePlayer(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    if (isInitialCall) {
        script->functionTemp[0].s = 60;
    }

    playerStatus->targetYaw += 30.0f;
    if (playerStatus->targetYaw >= 360.0f) {
        playerStatus->targetYaw -= 360.0f;
    }

    script->functionTemp[0].s--;

    return (script->functionTemp[0].s >> 0x1F) & ApiStatus_DONE2;
}
