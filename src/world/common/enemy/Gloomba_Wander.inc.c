#include "Gloomba.h"

MobileAISettings N(AISettings_Gloomba_Wander) = {
    .moveSpeed = 2.2f,
    .alertRadius = 70.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.2f,
    .chaseTurnRate = 15,
    .chaseUpdateInterval = 1,
    .chaseRadius = 90.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Gloomba_Wander) = {
    Call(BasicAI_Main, Ref(N(AISettings_Gloomba_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Gloomba_Wander) = {
    .height = 20,
    .radius = 23,
    .level = ACTOR_LEVEL_GLOOMBA,
    .ai = &N(EVS_NpcAI_Gloomba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
