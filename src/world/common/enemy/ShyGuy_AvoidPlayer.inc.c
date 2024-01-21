#include "ShyGuy.h"

#include "world/common/enemy/ai/AvoidPlayerAI.inc.c"

MobileAISettings N(AISettings_ShyGuy_AvoidPlayer) = {
    .moveSpeed = 2.5f,
    .moveTime = 50,
    .waitTime = 15,
    .alertRadius = 100.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.9f,
    .chaseTurnRate = 20,
    .chaseUpdateInterval = 1,
    .chaseRadius = 180.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShyGuy_AvoidPlayer) = {
    Call(N(AvoidPlayerAI_Main), Ref(N(AISettings_ShyGuy_AvoidPlayer)))
    Return
    End
};

NpcSettings N(NpcSettings_ShyGuy_AvoidPlayer) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy_AvoidPlayer),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
