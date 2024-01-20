#include "Duplighost.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_Duplighost_Patrol) = {
    .moveSpeed = 2.0f,
    .alertRadius = 100.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 30,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Duplighost_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Duplighost_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_Duplighost_Patrol) = {
    .height = 30,
    .radius = 30,
    .level = ACTOR_LEVEL_DUPLIGHOST,
    .ai = &N(EVS_NpcAI_Duplighost_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
