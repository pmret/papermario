#include "common.h"

#include "world/common/enemy/ParatroopaAI.inc.c"

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0, 
};

MobileAISettings N(AISettings_ParaTroopa) = {
    .moveSpeed = 2.0f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 20.0f,
    .playerSearchInterval = 10,
    .chaseSpeed = 2.6f,
    .chaseTurnRate = 60,
    .chaseUpdateInterval = 10,
    .chaseRadius = 150.0f,
    .chaseOffsetDist = 20.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ParaTroopa) = {
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_CALL(SetSelfVar, 5, -650)
    EVT_CALL(SetSelfVar, 6, 30)
    EVT_CALL(SetSelfVar, 1, 600)
    EVT_CALL(N(ParatroopaAI_Main), EVT_PTR(N(AISettings_ParaTroopa)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ParaTroopa) = {
    .height = 40,
    .radius = 24,
    .level = 6,
    .ai = &N(EVS_NpcAI_ParaTroopa),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
