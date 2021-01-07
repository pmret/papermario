#include "common.h"
#include "map.h"

ApiStatus N(SomeXYZFunc2)(ScriptInstance* script, s32 isInitialStatus) {
    PlayerStatus* playerStatus = PLAYER_STATUS;
    f32 r = get_float_variable(script, *script->ptrReadPos);
    f32 x = playerStatus->position.x;
    f32 y = playerStatus->position.y;
    f32 z = playerStatus->position.z;

    add_vec2D_polar(&x, &z, r, playerStatus->targetYaw);
    set_float_variable(script, SI_VAR(0), x);
    set_float_variable(script, SI_VAR(1), y);
    set_float_variable(script, SI_VAR(2), z);

    return ApiStatus_DONE2;
}
