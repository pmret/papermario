#include "Paragoomba.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(AISettings_Paragoomba_Wander) = {
    .moveSpeed = 1.6f,
    .moveTime = 60,
    .waitTime = 30,
    .alertRadius = 80.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 2.2f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 15,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Paragoomba_Wander) = {
    Call(SetSelfVar, 0, 0)
    Call(SetSelfVar, 5, -500)
    Call(SetSelfVar, 6, 21)
    Call(SetSelfVar, 1, 580)
    Call(N(FlyingAI_Main), Ref(N(AISettings_Paragoomba_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Paragoomba_Wander) = {
    .height = 20,
    .radius = 21,
    .level = ACTOR_LEVEL_PARAGOOMBA,
    .ai = &N(EVS_NpcAI_Paragoomba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_02,
};
