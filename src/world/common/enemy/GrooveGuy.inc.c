#include "GrooveGuy.h"

#include "world/common/enemy/ai/GrooveGuyAI.inc.c"

MobileAISettings N(AISettings_GrooveGuy) = {
    .moveSpeed = 1.7f,
    .moveTime = 80,
    .waitTime = 1,
    .alertRadius = 100.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 4.5f,
    .chaseTurnRate = 20,
    .chaseUpdateInterval = 1,
    .chaseRadius = 140.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_GrooveGuy) = {
    Call(N(GrooveGuyAI_Main), Ref(N(AISettings_GrooveGuy)))
    Return
    End
};

NpcSettings N(NpcSettings_GrooveGuy) = {
    .height = 24,
    .radius = 22,
    .level = ACTOR_LEVEL_GROOVE_GUY,
    .ai = &N(EVS_NpcAI_GrooveGuy),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
