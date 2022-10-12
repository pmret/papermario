#include "Pokey.h"

#include "world/common/todo/SetNpcB5_3.inc.c"

MobileAISettings N(AISettings_Pokey) = {
    .moveSpeed = 1.8f,
    .moveTime = 50,
    .waitTime = 10,
    .alertRadius = 250.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 45,
    .chaseUpdateInterval = 6,
    .chaseRadius = 300.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Pokey) = {
    EVT_CALL(N(SetNpcB5_3))
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Pokey)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Pokey) = {
    .height = 72,
    .radius = 15,
    .level = 9,
    .ai = &N(EVS_NpcAI_Pokey),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
