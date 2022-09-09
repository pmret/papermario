#include "jan_00.h"

static char* N(exit_str_0) = "jan_01";
static char* N(exit_str_1) = "jan_08";
static char* N(exit_str_2) = "mac_06";

extern u32 N(unkAngle1);
extern s32 N(unkAngle2);
extern s32 N(unkAngle3);

void N(unkVtxFunc001)(Vtx* firstVertex, Vtx* copiedVertices, s32 numVertices, s32* arg3);

#include "world/common/resolve_npc.inc.c"

#include "world/common/UnkAngleFunc001.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B216E0", jan_00_unkVtxFunc001);

#include "world/common/unkAngleFuncs023.inc.c"

#include "world/common/UnkFloatFunc001.inc.c"

ApiStatus func_80241868_B21DA8(Evt* script, s32 isInitialCall) {
    Npc* player = get_npc_safe(ACTOR_PLAYER);
    f32 yaw = -player->yaw;
    f32 x = player->pos.x + 30.0f + (sin_deg(yaw) * 170.0f);
    f32 z = player->pos.z + (cos_deg(yaw) * 170.0f);
    f32 y = player->pos.y + 50.0f;

    evt_set_float_variable(script, LocalVar(0), x);
    evt_set_float_variable(script, LocalVar(1), y);
    evt_set_float_variable(script, LocalVar(2), z);
    return ApiStatus_DONE2;
}
