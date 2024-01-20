#include "Duplighost.h"

MobileAISettings N(AISettings_Duplighost_Wander) = {
    .moveSpeed = 2.0f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 100.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 3.5f,
    .chaseTurnRate = 30,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Duplighost_Wander) = {
    Call(BasicAI_Main, Ref(N(AISettings_Duplighost_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Duplighost_Wander) = {
    .height = 30,
    .radius = 30,
    .level = ACTOR_LEVEL_DUPLIGHOST,
    .ai = &N(EVS_NpcAI_Duplighost_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
