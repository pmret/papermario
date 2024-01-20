#include "SpikedGloomba.h"

MobileAISettings N(AISettings_SpikedGloomba_Wander) = {
    .moveSpeed = 2.2f,
    .alertRadius = 70.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 3.2f,
    .chaseTurnRate = 15,
    .chaseUpdateInterval = 1,
    .chaseRadius = 90.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpikedGloomba_Wander) = {
    Call(BasicAI_Main, Ref(N(AISettings_SpikedGloomba_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_SpikedGloomba_Wander) = {
    .height = 23,
    .radius = 23,
    .level = ACTOR_LEVEL_SPIKED_GLOOMBA,
    .ai = &N(EVS_NpcAI_SpikedGloomba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
