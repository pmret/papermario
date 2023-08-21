#include "HyperCleft.h"

#include "world/common/enemy/ai/CleftAI.inc.c"

MobileAISettings N(AISettings_HyperCleft) = {
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

EvtScript N(EVS_NpcAI_HyperCleft) = {
    EVT_CALL(N(CleftAI_Main), EVT_PTR(N(AISettings_HyperCleft)), 8)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HyperCleft) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_HYPER_CLEFT,
    .ai = &N(EVS_NpcAI_HyperCleft),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
