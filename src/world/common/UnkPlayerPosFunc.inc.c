#include "common.h"
#include "npc.h"

ApiStatus N(UnkPlayerPosFunc)(Evt* script, s32 isInitialCall) {
    Npc* player = get_npc_safe(ACTOR_PLAYER);
    f32 yaw = -player->yaw;
    f32 x = player->pos.x + 30.0f + (sin_deg(yaw) * 70.0f);
    f32 z = player->pos.z + (cos_deg(yaw) * 70.0f);
    f32 y = player->pos.y + 50.0f;

    evt_set_float_variable(script, EVT_VAR(0), x);
    evt_set_float_variable(script, EVT_VAR(1), y);
    evt_set_float_variable(script, EVT_VAR(2), z);
    return ApiStatus_DONE2;
}
