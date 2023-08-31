#include "RuffPuff.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"
#include "world/common/enemy/ai/FlyingNoAttackAI.inc.c"

MobileAISettings N(AISettings_RuffPuff) = {
    .moveSpeed = 1.0f,
    .moveTime = 45,
    .waitTime = 60,
    .alertRadius = 100.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.6f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 120.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_RuffPuff) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(AISettings_RuffPuff)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_RuffPuff) = {
    .height = 24,
    .radius = 28,
    .level = ACTOR_LEVEL_RUFF_PUFF,
    .ai = &N(EVS_NpcAI_RuffPuff),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
