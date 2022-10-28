#include "sam_12.h"

static char* N(exit_str_0) = "sam_10";
static char* N(exit_str_1) = "";

ApiStatus func_80240000_D4BA20(Evt* script, s32 isInitialCall) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTempF[1] = 0.0f;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
    }
    npc = script->functionTempPtr[2];
    npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 5.0f;
    script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 4.5f);
    return ApiStatus_BLOCK;
}
