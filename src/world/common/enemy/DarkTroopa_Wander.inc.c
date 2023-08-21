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
    EVT_CALL(SetSelfVar, 2, 6)
    EVT_CALL(SetSelfVar, 3, 4)
    EVT_CALL(SetSelfVar, 5, 13)
    EVT_CALL(SetSelfVar, 7, 1)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_DarkTroopa_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_DarkTroopa_Wander) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_DARK_KOOPA,
    .ai = &N(EVS_NpcAI_DarkTroopa_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
