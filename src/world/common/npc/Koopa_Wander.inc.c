#include "common.h"
#include "Koopa.h"

MobileAISettings N(AISettings_Koopa_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Koopa_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Koopa_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Koopa_Wander) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Koopa_Wander),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_TallKoopa_Wander) = {
    .height = 42,
    .radius = 24,
    .ai = &N(EVS_NpcAI_Koopa_Wander),
    .level = ACTOR_LEVEL_NONE,
};
