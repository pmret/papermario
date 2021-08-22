#include "arn_08.h"

ApiStatus N(func_80240000_BF47A0)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_f20;
    s32 colliderID;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        suggest_player_anim_clearUnkFlag(0x10007);
    }

    temp_f20 = func_800E34D8();
    playerStatus->position.y = player_check_collision_below(temp_f20, &colliderID);
    script->functionTemp[0] += fabsf(temp_f20);
    do {} while (0);
    return (script->functionTemp[0] > 50) * ApiStatus_DONE2;
}

ApiStatus N(func_8024008C_BF482C)(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.position.y < -10.0f) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
