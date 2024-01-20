#include "KoopaTroopa.h"

#include "world/common/enemy/ai/TackleAI.inc.c"

MobileAISettings N(AISettings_KoopaTroopa_Wander) = {
    .moveSpeed = 1.5f,
    .moveTime = 45,
    .waitTime = 20,
    .alertRadius = 70.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 7.5f,
    .chaseRadius = 80.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_KoopaTroopa_Wander) = {
    Call(SetSelfVar, 2, 8)
    Call(SetSelfVar, 3, 12)
    Call(SetSelfVar, 5, 10)
    Call(SetSelfVar, 7, 0)
    Call(N(TackleAI_Main), Ref(N(AISettings_KoopaTroopa_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_KoopaTroopa_Wander) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPA_TROOPA,
    .ai = &N(EVS_NpcAI_KoopaTroopa_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
