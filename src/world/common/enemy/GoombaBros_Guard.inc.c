#include "GoombaBros.h"

#include "world/common/enemy/ai/GuardAI.inc.c"

GuardAISettings N(AISettings_GoombaBros_Guard) = {
    .alertRadius = 130.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 2.5f,
    .chaseTurnRate = 180,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .unk_AI_20 = 1,
};

EvtScript N(EVS_NpcAI_GoombaBros_Guard) = {
    Call(N(GuardAI_Main), Ref(N(AISettings_GoombaBros_Guard)))
    Return
    End
};

NpcSettings N(NpcSettings_GoombaBros_Guard) = {
    .height = 20,
    .radius = 23,
    .level = ACTOR_LEVEL_GOOMBA,
    .ai = &N(EVS_NpcAI_GoombaBros_Guard),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
