#include "osr_02.h"

extern s16 D_8024253C_AB46AC[];

ApiStatus func_80240060_AB21D0(Evt* script, s32 isInitialCall) {
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = 0.0f;
        script->functionTempPtr[2] = get_npc_safe(script->owner2.npcID);
        script->functionTemp[3] = D_8024253C_AB46AC[script->owner2.npcID - 2];
    }

    if (script->functionTemp[3] != 0) {
        script->functionTemp[3]--;
        return ApiStatus_BLOCK;
    }

    npc = script->functionTempPtr[2];
    npc->verticalRenderOffset = sin_deg(script->functionTempF[1]) * 1.5f;
    script->functionTempF[1] = clamp_angle(script->functionTempF[1] + 18.0f);
    return ApiStatus_BLOCK;
}
