#include "mac_05.h"

extern u32 N(unkAngle1);
extern s32 N(unkAngle2);
extern s32 N(unkAngle3);

#include "world/common/atomic/WhaleAnim.inc.c"

ApiStatus N(UnkPlayerPosFunc)(Evt* script, s32 isInitialCall) {
    Npc* player = get_npc_safe(ACTOR_PLAYER);
    f32 yaw = -player->yaw;
    f32 x = player->pos.x + 30.0f + (sin_deg(yaw) * 70.0f);
    f32 z = player->pos.z + (cos_deg(yaw) * 70.0f);
    f32 y = player->pos.y + 50.0f;

    evt_set_float_variable(script, LVar0, x);
    evt_set_float_variable(script, LVar1, y);
    evt_set_float_variable(script, LVar2, z);
    return ApiStatus_DONE2;
}

#include "world/common/atomic/WhaleGeyser.inc.c"

MAP_RODATA_PAD(2, unk);
