#include "AmazyDayzee.h"

#include "world/common/enemy/ai/AvoidPlayerAI.inc.c"

MobileAISettings N(AISettings_AmazyDayzee) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 3,
    .chaseSpeed = 2.4f,
    .chaseTurnRate = 15,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .chaseOffsetDist = 30.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_AmazyDayzee) = {
    EVT_CALL(N(AvoidPlayerAI_Main), EVT_PTR(N(AISettings_AmazyDayzee)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_AmazyDayzee) = {
    EVT_LABEL(0)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 30)
        EVT_SUB(LVar2, 2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 30)
        EVT_WAIT(15)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_AmazyDayzee) = {
    .height = 30,
    .radius = 24,
    .level = ACTOR_LEVEL_AMAZY_DAYZEE,
    .ai = &N(EVS_NpcAI_AmazyDayzee),
    .onHit = &EnemyNpcHit,
    .aux = &N(EVS_NpcAux_AmazyDayzee),
    .onDefeat = &EnemyNpcDefeat,
};
