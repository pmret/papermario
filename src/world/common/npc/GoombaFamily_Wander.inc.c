#include "GoombaFamily.h"

MobileAISettings N(AISettings_GoombaFamily_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_GoombaFamily_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_GoombaFamily_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_GoombaFamily_Wander) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_GoombaFamily_Wander),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};
