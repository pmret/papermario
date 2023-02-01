#include "Fuzzy.h"

#include "world/common/enemy/ai/HoppingAI.inc.c"

MobileAISettings N(AISettings_Fuzzy) = {
    .moveSpeed = 2.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 4.5f,
    .chaseTurnRate = 70,
    .chaseUpdateInterval = 10,
    .chaseRadius = 200.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Fuzzy) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
    EVT_CALL(N(HoppingAI_Main), EVT_PTR(N(AISettings_Fuzzy)), 0)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Fuzzy) = {
    .height = 20,
    .radius = 22,
    .level = 6,
    .ai = &N(EVS_NpcAI_Fuzzy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
