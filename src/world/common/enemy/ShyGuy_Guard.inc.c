#include "ShyGuy.h"

#include "world/common/enemy/ai/GuardAI.inc.c"

GuardAISettings N(AISettings_ShyGuy_Guard) = {
    .alertRadius = 100.0f,
    .alertOffsetDist = 30.0f,
    .playerSearchInterval = 4,
    .chaseSpeed = 4.0f,
    .chaseTurnRate = 6,
    .chaseUpdateInterval = 1,
    .chaseRadius = 160.0f,
    .chaseOffsetDist = 50.0f,
    .unk_AI_20 = 1,
};

EvtScript N(EVS_NpcAI_ShyGuy_Guard) = {
    Call(N(GuardAI_Main), Ref(N(AISettings_ShyGuy_Guard)))
    Return
    End
};

NpcSettings N(NpcSettings_ShyGuy_Guard) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy_Guard),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};
