#include "SpikedGoomba.h"

MobileAISettings N(AISettings_SpikedGoomba_Wander) = {
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

EvtScript N(EVS_NpcAI_SpikedGoomba_Wander) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_SpikedGoomba_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpikedGoomba_Wander) = {
    .height = 23,
    .radius = 23,
    .level = ACTOR_LEVEL_SPIKED_GOOMBA,
    .ai = &N(EVS_NpcAI_SpikedGoomba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
