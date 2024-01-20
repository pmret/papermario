#include "Spiny.h"

#include "world/common/enemy/ai/TackleAI.inc.c"

MobileAISettings N(AISettings_Spiny) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 60.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 6.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 3,
};

EvtScript N(EVS_NpcAI_Spiny) = {
    Call(SetSelfVar, 2, 3)
    Call(SetSelfVar, 3, 18)
    Call(SetSelfVar, 5, 3)
    Call(SetSelfVar, 7, 4)
    Call(N(TackleAI_Main), Ref(N(AISettings_Spiny)))
    Return
    End
};

NpcSettings N(NpcSettings_Spiny) = {
    .height = 21,
    .radius = 22,
    .level = ACTOR_LEVEL_SPINY,
    .ai = &N(EVS_NpcAI_Spiny),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
