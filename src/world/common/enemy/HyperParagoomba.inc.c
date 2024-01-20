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
    Call(SetSelfVar, 0, 1)
    Call(SetSelfVar, 5, -850)
    Call(SetSelfVar, 6, 60)
    Call(SetSelfVar, 1, 700)
    Call(N(FlyingAI_Main), Ref(N(AISettings_HyperParagoomba)))
    Return
    End
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
