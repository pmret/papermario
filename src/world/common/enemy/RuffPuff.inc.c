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
    Call(SetSelfVar, 0, 1)
    Call(SetSelfVar, 5, 0)
    Call(SetSelfVar, 6, 0)
    Call(SetSelfVar, 1, 600)
    Call(N(FlyingNoAttackAI_Main), Ref(N(AISettings_RuffPuff)))
    Return
    End
};

NpcSettings N(NpcSettings_RuffPuff) = {
    .height = 24,
    .radius = 28,
    .level = ACTOR_LEVEL_RUFF_PUFF,
    .ai = &N(EVS_NpcAI_RuffPuff),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
