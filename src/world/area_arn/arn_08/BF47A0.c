#include "arn_08.h"

ApiStatus N(func_80240000_BF47A0)(ScriptInstance *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_f20;
    f32 var;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
        func_800DFEFC(0x10007);
    }

    temp_f20 = func_800E34D8();
    playerStatus->position.y = func_800E3514(temp_f20, &var);
    script->functionTemp[0].s += fabsf(temp_f20);
    do {} while(0);
    return (script->functionTemp[0].s > 50) * ApiStatus_DONE2;
}

ApiStatus N(func_8024008C_BF482C)(ScriptInstance *script, s32 isInitialCall) {
    if (gPlayerStatus.position.y < -10.0f) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
