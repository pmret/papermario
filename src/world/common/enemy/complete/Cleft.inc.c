
#include "common.h"
#include "world/common/enemy/CleftAI.inc.c"

MobileAISettings N(AISettings_Cleft) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 8.5f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 3,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Cleft) = {
    EVT_CALL(N(CleftAI_Main), EVT_PTR(N(AISettings_Cleft)), 8)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Cleft) = {
    .height = 24,
    .radius = 24,
    .level = 15,
    .ai = &N(EVS_NpcAI_Cleft),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
