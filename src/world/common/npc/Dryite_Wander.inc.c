#include "Dryite.h"

MobileAISettings N(AISettings_Dryite_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Dryite_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Dryite_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Dryite_Wander) = {
    .height = 26,
    .radius = 23,
    .ai = &N(EVS_NpcAI_Dryite_Wander),
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = 16,
};
