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
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -500)
    EVT_CALL(SetSelfVar, 6, 21)
    EVT_CALL(SetSelfVar, 1, 580)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(AISettings_Paragoomba_Wander)))
    EVT_RETURN
    EVT_END
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
