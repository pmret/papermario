#include "kmr_03.h"

#include "world/common/SetCamera0MoveFlagNeg1.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_03/8C82B0", func_8024033C_8C82CC);

ApiStatus func_80240358_8C82E8(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = PLAYER_STATUS;

    f32 xDelta = playerStatus->currentSpeed * 5.0f * sin_deg(playerStatus->targetYaw);
    f32 zDelta = playerStatus->currentSpeed * 5.0f * -cos_deg(playerStatus->targetYaw);

    script->varTable[0] = playerStatus->position.x + xDelta;
    script->varTable[1] = playerStatus->position.z + zDelta;

    return ApiStatus_DONE2;
}
