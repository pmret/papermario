#include "CrazyDayzee.h"

MobileAISettings N(AISettings_CrazyDayzee) = {
    .moveSpeed = 1.0f,
    .moveTime = 500,
    .waitTime = 10,
    .alertRadius = 50.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 40,
    .chaseUpdateInterval = 3,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_CrazyDayzee) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_CrazyDayzee)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_CrazyDayzee) = {
    .height = 30,
    .radius = 24,
    .level = ACTOR_LEVEL_CRAZEE_DAYZEE,
    .ai = &N(EVS_NpcAI_CrazyDayzee),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
