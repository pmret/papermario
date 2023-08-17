#include "ShyGuy.h"

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

MobileAISettings N(AISettings_ShyGuy_Wander) = {
    .moveSpeed = 2.0f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShyGuy_Wander) = {
    EVT_CALL(N(ShyGuyWanderAI_Main), EVT_PTR(N(AISettings_ShyGuy_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ShyGuy_Wander) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
