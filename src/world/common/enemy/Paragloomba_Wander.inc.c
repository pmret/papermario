#include "Paragloomba.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(AISettings_Paragloomba_Wander) = {
    .moveSpeed = 2.0f,
    .alertRadius = 80.0f,
    .playerSearchInterval = 5,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 2,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Paragloomba_Wander) = {
    Call(SetSelfVar, 0, 1)
    Call(SetSelfVar, 5, -850)
    Call(SetSelfVar, 6, 60)
    Call(SetSelfVar, 1, 600)
    Call(N(FlyingAI_Main), Ref(N(AISettings_Paragloomba_Wander)))
    Return
    End
};

NpcSettings N(NpcSettings_Paragloomba_Wander) = {
    .height = 20,
    .radius = 21,
    .level = ACTOR_LEVEL_PARAGLOOMBA,
    .ai = &N(EVS_NpcAI_Paragloomba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
