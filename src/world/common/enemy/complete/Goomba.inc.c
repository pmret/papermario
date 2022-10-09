
#include "common.h"

MobileAISettings N(AISettings_Goomba) = {
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

EvtScript N(EVS_NpcAI_Goomba) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Goomba)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Goomba) = {
    .height = 20,
    .radius = 23,
    .level = 12,
    .ai = &N(EVS_NpcAI_Goomba),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
