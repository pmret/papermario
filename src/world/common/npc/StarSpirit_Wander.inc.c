#include "StarSpirit.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(AISettings_StarSpirit_Wander) = {
    .moveSpeed = 1.2f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_StarSpirit_Wander) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 5, 0)
    Call(SetSelfVar, 6, 0)
    Call(SetSelfVar, 1, 200)
    Call(N(FlyingAI_Main), Ref(N(AISettings_StarSpirit_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_StarSpirit_Wander) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_StarSpirit_Wander),
};

NpcSettings N(NpcSettings_StarKid_Wander) = {
    .height = 20,
    .radius = 20,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_StarSpirit_Wander),
};

NpcSettings N(NpcSettings_StarMan_Wander) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_StarSpirit_Wander),
};
