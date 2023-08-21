#include "Koopatrol.h"

#include "world/common/enemy/ai/TackleAI.inc.c"

MobileAISettings N(AISettings_Koopatrol_Wander) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 11.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Koopatrol_Wander) = {
    EVT_CALL(SetSelfVar, 2, 5)
    EVT_CALL(SetSelfVar, 3, 4)
    EVT_CALL(SetSelfVar, 5, 10)
    EVT_CALL(SetSelfVar, 7, 5)
    EVT_CALL(N(TackleAI_Main), EVT_PTR(N(AISettings_Koopatrol_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Koopatrol_Wander) = {
    .height = 40,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPATROL,
    .ai = &N(EVS_NpcAI_Koopatrol_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
