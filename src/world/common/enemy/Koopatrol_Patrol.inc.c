#include "Koopatrol.h"

#include "world/common/enemy/ai/KoopaPatrolAI.inc.c"

MobileAISettings N(AISettings_Koopatrol_Patrol) = {
    .moveSpeed = 1.0f,
    .moveTime = 34,
    .waitTime = 50,
    .alertRadius = 90.0f,
    .alertOffsetDist = 50.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 11.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 60.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Koopatrol_Patrol) = {
    Call(SetSelfVar, 2, 8)
    Call(SetSelfVar, 3, 15)
    Call(SetSelfVar, 5, 10)
    Call(N(KoopaPatrolAI_Main), Ref(N(AISettings_Koopatrol_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_Koopatrol_Patrol) = {
    .height = 40,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPATROL,
    .ai = &N(EVS_NpcAI_Koopatrol_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
