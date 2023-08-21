#include "PyroGuy.h"

MobileAISettings N(AISettings_PyroGuy) = {
    .moveSpeed = 3.0f,
    .moveTime = 30,
    .waitTime = 60,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 5.0f,
    .chaseTurnRate = 8,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_PyroGuy) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_PyroGuy)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_PyroGuy) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_PYRO_GUY,
    .ai = &N(EVS_NpcAI_PyroGuy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
