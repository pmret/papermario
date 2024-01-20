#include "Koopatrol.h"

#include "world/common/enemy/ai/TackleAI.inc.c"

MobileAISettings N(AISettings_Koopatrol_Wander) = {
    .moveSpeed = 1.0f,
    .moveTime = 30,
    .waitTime = 50,
    .alertRadius = 90.0f,
    .alertOffsetDist = 40.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 11.0f,
    .chaseRadius = 100.0f,
    .chaseOffsetDist = 40.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Koopatrol_Wander) = {
    Call(SetSelfVar, 2, 5)
    Call(SetSelfVar, 3, 4)
    Call(SetSelfVar, 5, 10)
    Call(SetSelfVar, 7, 5)
    Call(N(TackleAI_Main), Ref(N(AISettings_Koopatrol_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Koopatrol_Wander) = {
    .height = 40,
    .radius = 24,
    .level = ACTOR_LEVEL_KOOPATROL,
    .ai = &N(EVS_NpcAI_Koopatrol_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
