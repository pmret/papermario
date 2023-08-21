#include "Merlar.h"

API_CALLABLE(N(AddMerlarHoverMotion)) {
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

EvtScript N(EVS_NpcAuxAI_Merlar) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Merlar) = {
    .height = 60,
    .radius = 60,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_Merlar),
};

EvtScript N(EVS_NpcAux_Merlar) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Merlar) = {
    EVT_CALL(N(AddMerlarHoverMotion))
    EVT_RETURN
    EVT_END
};
