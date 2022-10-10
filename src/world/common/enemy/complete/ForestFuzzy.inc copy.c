#include "ForestFuzzy.h"

#include "world/common/enemy/HoppingAI.inc.c"

MobileAISettings N(AISettings_ForestFuzzy) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 10,
    .alertRadius = 120.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 4.5f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 5,
    .chaseRadius = 160.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ForestFuzzy) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
    EVT_CALL(N(HoppingAI_Main), EVT_PTR(N(AISettings_ForestFuzzy)), 1)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ForestFuzzy) = {
    .height = 20,
    .radius = 22,
    .level = 11,
    .ai = &N(EVS_NpcAI_ForestFuzzy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
