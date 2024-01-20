#include "Goomba.h"

MobileAISettings N(AISettings_Goomba_Wander) = {
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

EvtScript N(EVS_NpcAI_Goomba_Wander) = {
    Call(BasicAI_Main, Ref(N(AISettings_Goomba_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Goomba_Wander) = {
    .height = 20,
    .radius = 23,
    .level = ACTOR_LEVEL_GOOMBA,
    .ai = &N(EVS_NpcAI_Goomba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
