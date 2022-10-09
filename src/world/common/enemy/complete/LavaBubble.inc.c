#include "LavaBubble.h"

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0,
};

#include "world/common/enemy/FlyingAI.inc.c"

#include "world/common/enemy/FlyingNoAttackAI.inc.c"

MobileAISettings N(AISettings_LavaBubble) = {
    .moveSpeed = 0.8f,
    .moveTime = 100,
    .alertRadius = 90.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 3.2f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 100.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_LavaBubble) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, 0)
    EVT_CALL(SetSelfVar, 6, 0)
    EVT_CALL(SetSelfVar, 1, 150)
    EVT_CALL(N(FlyingNoAttackAI_Main), EVT_PTR(N(AISettings_LavaBubble)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_LavaBubble) = {
    .height = 20,
    .radius = 22,
    .level = 17,
    .ai = &N(EVS_NpcAI_LavaBubble),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
