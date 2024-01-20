#include "ForestFuzzy.h"

#include "world/common/enemy/ai/HoppingAI.inc.c"

MobileAISettings N(AISettings_ForestFuzzy_Wander) = {
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

EvtScript N(EVS_NpcAI_ForestFuzzy_Wander) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Call(N(HoppingAI_Main), Ref(N(AISettings_ForestFuzzy_Wander)), 1)
    Return
    End
};

NpcSettings N(NpcSettings_ForestFuzzy_Wander) = {
    .height = 20,
    .radius = 22,
    .level = ACTOR_LEVEL_FOREST_FUZZY,
    .ai = &N(EVS_NpcAI_ForestFuzzy_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
