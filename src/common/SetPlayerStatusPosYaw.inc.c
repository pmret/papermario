#include "common.h"

API_CALLABLE(N(SetPlayerStatusPosYaw)) {
    Bytecode* args = script->ptrReadPos;
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    f32 yaw = evt_get_float_variable(script, *args++);

    gPlayerStatus.pos.x = x;
    gPlayerStatus.pos.y = y;
    gPlayerStatus.pos.z = z;
    gPlayerStatus.targetYaw = yaw;
    return ApiStatus_DONE2;
}
