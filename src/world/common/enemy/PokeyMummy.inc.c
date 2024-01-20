#include "PokeyMummy.h"

#include "world/common/todo/SetInstigatorValue_3.inc.c"

MobileAISettings N(AISettings_PokeyMummy) = {
    .moveSpeed = 1.8f,
    .moveTime = 40,
    .waitTime = 10,
    .alertRadius = 100.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 45,
    .chaseUpdateInterval = 6,
    .chaseRadius = 300.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_PokeyMummy) = {
    Call(N(SetInstigatorValue_3))
    Call(BasicAI_Main, Ref(N(AISettings_PokeyMummy)))
    Return
    End
};

NpcSettings N(NpcSettings_PokeyMummy) = {
    .height = 72,
    .radius = 15,
    .level = ACTOR_LEVEL_POKEY_MUMMY,
    .ai = &N(EVS_NpcAI_PokeyMummy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
