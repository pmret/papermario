#include "kmr_03.h"

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"

ApiStatus func_80240358_8C82E8(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    f32 xDelta = playerStatus->currentSpeed * 5.0f * sin_deg(playerStatus->targetYaw);
    f32 zDelta = playerStatus->currentSpeed * 5.0f * -cos_deg(playerStatus->targetYaw);

    script->varTable[0] = playerStatus->position.x + xDelta;
    script->varTable[1] = playerStatus->position.z + zDelta;

    return ApiStatus_DONE2;
}
