#include "HyperParagoomba.h"

#include "world/common/enemy/ai/FlyingAI.inc.c"

MobileAISettings N(AISettings_HyperParagoomba) = {
    .moveSpeed = 1.8f,
    .moveTime = 60,
    .waitTime = 15,
    .alertRadius = 120.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 5,
    .chaseUpdateInterval = 1,
    .chaseRadius = 150.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_HyperParagoomba) = {
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_CALL(SetSelfVar, 5, -850)
    EVT_CALL(SetSelfVar, 6, 60)
    EVT_CALL(SetSelfVar, 1, 700)
    EVT_CALL(N(FlyingAI_Main), EVT_PTR(N(AISettings_HyperParagoomba)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_HyperParagoomba) = {
    .height = 18,
    .radius = 20,
    .level = ACTOR_LEVEL_HYPER_GOOMBA,
    .ai = &N(EVS_NpcAI_HyperParagoomba),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
