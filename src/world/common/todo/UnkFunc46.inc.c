#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc46)) {
    f32 var1 = script->varTable[0];
    f32 var2 = script->varTable[2];
    f32 var3 = 0.0f;
    f32 var4 = 2000.0f;

    if (npc_raycast_down_sides(COLLISION_CHANNEL_10000, &var1, &var2, &var3, &var4)) {
        script->varTable[0] = var1;
        script->varTable[2] = var2 + 55.0f;
    }

    return ApiStatus_DONE2;
}
