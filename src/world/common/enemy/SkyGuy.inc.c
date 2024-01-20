#include "SkyGuy.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(AISettings_SkyGuy) = {
    .moveSpeed = 1.8f,
    .alertRadius = 120.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SkyGuy) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 5, -650)
    Call(SetSelfVar, 6, 30)
    Call(SetSelfVar, 1, 600)
    Call(N(FlyingAI_Main), Ref(N(AISettings_SkyGuy)))
    Return
    End
};

NpcSettings N(NpcSettings_SkyGuy) = {
    .height = 25,
    .radius = 22,
    .level = ACTOR_LEVEL_SKY_GUY,
    .ai = &N(EVS_NpcAI_SkyGuy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
