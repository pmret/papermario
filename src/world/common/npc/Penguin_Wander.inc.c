#include "common.h"
#include "Penguin.h"

MobileAISettings N(AISettings_Penguin_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Penguin_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Penguin_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Penguin_Wander) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Penguin_Wander),
};
