#include "common.h"
#include "TubbaBlubba.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_Tubba_Patrol) = {
    .moveSpeed = 4.5f,
    .alertRadius = 170.0f,
    .alertOffsetDist = 90.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.9f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 2,
    .chaseRadius = 170.0f,
    .chaseOffsetDist = 90.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Tubba_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Tubba_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_TubbaBlubba_Patrol) = {
    .height = 90,
    .radius = 65,
    .level = ACTOR_LEVEL_CLUBBA,
    .ai = &N(EVS_NpcAI_Tubba_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
