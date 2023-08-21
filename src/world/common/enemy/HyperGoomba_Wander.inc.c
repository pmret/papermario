
#include "common.h"
#include "HyperGoomba.h"

MobileAISettings N(AISettings_HyperGoomba) = {
    .moveSpeed = 1.8f,
    .moveTime = 40,
    .waitTime = 15,
    .alertRadius = 150.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.3f,
    .chaseTurnRate = 70,
    .chaseUpdateInterval = 1,
    .chaseRadius = 180.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_HyperGoomba) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_HyperGoomba)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HyperGoomba) = {
    .height = 20,
    .radius = 23,
    .level = ACTOR_LEVEL_HYPER_GOOMBA,
    .ai = &N(EVS_NpcAI_HyperGoomba),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
