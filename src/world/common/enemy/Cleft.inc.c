
#include "Cleft.h"

#include "world/common/enemy/ai/CleftAI.inc.c"

MobileAISettings N(AISettings_Cleft) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 7.0f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 5,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Cleft) = {
    Call(N(CleftAI_Main), Ref(N(AISettings_Cleft)), 16)
    Return
    End
};

NpcSettings N(NpcSettings_Cleft) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_CLEFT,
    .ai = &N(EVS_NpcAI_Cleft),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
