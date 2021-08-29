#include "common.h"
#include "map.h"

ApiStatus N(UnkYawFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    f32 a = evt_get_variable(script, a0);
    s32 a1 = *args++;
    f32 b = evt_get_variable(script, a1);
    s32 a2 = *args++;
    f32 c = evt_get_variable(script, a2);
    Npc* partner = get_npc_unsafe(NPC_PARTNER);
    f32 currentCamYaw = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 180.0f);

    add_vec2D_polar(&a, &c, 15.0f, partner->yaw);
    add_vec2D_polar(&a, &c, 10.0f, currentCamYaw);

    evt_set_variable(script, a0, a);
    evt_set_variable(script, a1, b);
    evt_set_variable(script, a2, c);

    return ApiStatus_DONE2;
}
