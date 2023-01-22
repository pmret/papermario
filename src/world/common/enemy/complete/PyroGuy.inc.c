#include "PyroGuy.h"

MobileAISettings N(D_8024608C_DF4F2C) = {
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
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_8024608C_DF4F2C)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_PyroGuy) = {
    .height = 23,
    .radius = 22,
    .level = 15,
    .ai = &N(EVS_NpcAI_PyroGuy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
