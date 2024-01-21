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
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 5, -630)
    Call(SetSelfVar, 6, 50)
    Call(SetSelfVar, 1, 200)
    Call(N(FlyingAI_Main), Ref(N(AISettings_Bzzap)))
    Return
    End
};

NpcSettings N(NpcSettings_Bzzap) = {
    .height = 26,
    .radius = 24,
    .level = ACTOR_LEVEL_BZZAP,
    .ai = &N(EVS_NpcAI_Bzzap),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
