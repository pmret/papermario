#include "SpikedGoomba.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_SpikedGoomba_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 130.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 2.5f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpikedGoomba_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_SpikedGoomba_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_SpikedGoomba_Patrol) = {
    .height = 23,
    .radius = 23,
    .level = ACTOR_LEVEL_SPIKED_GOOMBA,
    .ai = &N(EVS_NpcAI_SpikedGoomba_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
