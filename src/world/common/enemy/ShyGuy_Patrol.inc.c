#include "ShyGuy.h"

#include "world/common/enemy/ai/ShyGuyPatrolAI.inc.c"

MobileAISettings N(AISettings_ShyGuy_Patrol) = {
    .moveSpeed = 2.0f,
    .moveTime = 60,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 160.0f,
    .chaseOffsetDist = 50.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShyGuy_Patrol) = {
    Call(N(ShyGuyPatrolAI_Main), Ref(N(AISettings_ShyGuy_Patrol)))
    Return
    End
};

EvtScript N(EVS_NpcAI_ShyGuy_Patrol_Passive) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_ShyGuy_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_ShyGuy_Patrol) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy_Patrol),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_ShyGuy_Patrol_Passive) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy_Patrol_Passive),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
