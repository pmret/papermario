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
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, -850)
    EVT_CALL(SetSelfVar, 6, 60)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(AISettings_Paragloomba_Wander)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Paragloomba_Wander) = {
    .height = 20,
    .radius = 21,
    .level = ACTOR_LEVEL_PARAGLOOMBA,
    .ai = &N(EVS_NpcAI_Paragloomba_Wander),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
