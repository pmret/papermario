#include "Boo.h"

MobileAISettings N(AISettings_BooWander) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Boo_Wander) = {
    Call(BasicAI_Main, Ref(N(AISettings_BooWander)))
    Return
    End
};

NpcSettings N(NpcSettings_Boo_Wander) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Boo_Wander),
};
