
#include "common.h"
#include "HyperGoomba.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_HyperGoomba_Patrol) = {
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

EvtScript N(EVS_NpcAI_HyperGoomba_Patrol) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_HyperGoomba_Patrol)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HyperGoomba_Patrol) = {
    .height = 20,
    .radius = 23,
    .level = ACTOR_LEVEL_HYPER_GOOMBA,
    .ai = &N(EVS_NpcAI_HyperGoomba_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
