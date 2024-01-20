#include "KoopaTroopa.h"

#include "world/common/enemy/ai/KoopaPatrolAI.inc.c"

MobileAISettings N(AISettings_KoopaTroopa_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 25,
    .waitTime = 20,
    .alertRadius = 70.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 7.0f,
    .chaseRadius = 80.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_KoopaTroopa_Patrol) = {
    Call(SetSelfVar, 2, 8)
    Call(SetSelfVar, 3, 12)
    Call(SetSelfVar, 5, 10)
    Call(N(KoopaPatrolAI_Main), Ref(N(AISettings_KoopaTroopa_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_KoopaTroopa_Patrol) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPA_TROOPA,
    .ai = &N(EVS_NpcAI_KoopaTroopa_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
