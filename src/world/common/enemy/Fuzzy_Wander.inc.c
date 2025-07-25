#include "Fuzzy.h"

#include "world/common/enemy/ai/HoppingAI.inc.c"

MobileAISettings N(AISettings_Fuzzy_Wander) = {
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

EvtScript N(EVS_NpcAI_Fuzzy_Wander) = {
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
    Call(N(HoppingAI_Main), Ref(N(AISettings_Fuzzy_Wander)), 0)
    Return
    End
};

NpcSettings N(NpcSettings_Fuzzy_Wander) = {
    .height = 20,
    .radius = 22,
    .level = ACTOR_LEVEL_FUZZY,
    .ai = &N(EVS_NpcAI_Fuzzy_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
