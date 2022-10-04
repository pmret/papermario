#include "jan_00.h"

static char* N(exit_str_0) = "jan_01";
static char* N(exit_str_1) = "jan_08";
static char* N(exit_str_2) = "mac_06";

extern u32 N(unkAngle1);
extern s32 N(unkAngle2);
extern s32 N(unkAngle3);

#include "world/common/atomic/WhaleAnim.inc.c"

ApiStatus jan_00_UnkPlayerPosFunc(Evt* script, s32 isInitialCall) {
    Npc* player = get_npc_safe(ACTOR_PLAYER);
    f32 yaw = -player->yaw;
    f32 x = player->pos.x + 30.0f + (sin_deg(yaw) * 170.0f);
    f32 z = player->pos.z + (cos_deg(yaw) * 170.0f);
    f32 y = player->pos.y + 50.0f;

    evt_set_float_variable(script, LVar0, x);
    evt_set_float_variable(script, LVar1, y);
    evt_set_float_variable(script, LVar2, z);
    return ApiStatus_DONE2;
}
