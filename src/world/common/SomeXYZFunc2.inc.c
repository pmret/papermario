#include "common.h"
#include "map.h"

ApiStatus N(SomeXYZFunc2)(Evt* script, s32 isInitialStatus) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 r = evt_get_float_variable(script, *script->ptrReadPos);
    f32 x = playerStatus->position.x;
    f32 y = playerStatus->position.y;
    f32 z = playerStatus->position.z;

    add_vec2D_polar(&x, &z, r, playerStatus->targetYaw);
    evt_set_float_variable(script, EVT_VAR(0), x);
    evt_set_float_variable(script, EVT_VAR(1), y);
    evt_set_float_variable(script, EVT_VAR(2), z);

    return ApiStatus_DONE2;
}
