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
    EVT_CALL(SetSelfVar, 2, 8)
    EVT_CALL(SetSelfVar, 3, 12)
    EVT_CALL(SetSelfVar, 5, 10)
    EVT_CALL(SetSelfVar, 7, 0)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_KoopaTroopa_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_KoopaTroopa_Wander) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPA_TROOPA,
    .ai = &N(EVS_NpcAI_KoopaTroopa_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
