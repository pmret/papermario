#include "Bzzap.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(AISettings_Bzzap) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 4.5f,
    .chaseTurnRate = 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 90.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Bzzap) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -630)
    EVT_CALL(SetSelfVar, 6, 50)
    EVT_CALL(SetSelfVar, 1, 200)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(AISettings_Bzzap)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bzzap) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_BZZAP,
    .ai = &N(EVS_NpcAI_Bzzap),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
