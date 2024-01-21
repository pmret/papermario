#include "common.h"
#include "DarkTroopa.h"

#include "world/common/enemy/ai/TackleAI.inc.c"

MobileAISettings N(AISettings_DarkTroopa_Wander) = {
    .moveSpeed = 2.0f,
    .moveTime = 60,
    .waitTime = 5,
    .alertRadius = 80.0f,
    .alertOffsetDist = 60.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 9.0f,
    .chaseRadius = 90.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_DarkTroopa_Wander) = {
    Call(SetSelfVar, 2, 6)
    Call(SetSelfVar, 3, 4)
    Call(SetSelfVar, 5, 13)
    Call(SetSelfVar, 7, 1)
    Call(N(TackleAI_Main), Ref(N(AISettings_DarkTroopa_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_DarkTroopa_Wander) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_DARK_KOOPA,
    .ai = &N(EVS_NpcAI_DarkTroopa_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
