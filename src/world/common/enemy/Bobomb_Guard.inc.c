#include "common.h"
#include "Bobomb.h"

#include "world/common/enemy/ai/GuardAI.inc.c"

GuardAISettings N(AISettings_Bobomb_Guard) = {
    .alertRadius = 110.0f,
    .alertOffsetDist = 65.0f,
    .playerSearchInterval = 8,
    .chaseSpeed = 3.4f,
    .chaseTurnRate = 120,
    .chaseUpdateInterval = 2,
    .chaseRadius = 110.0f,
    .chaseOffsetDist = 65.0f,
    .unk_AI_20 = 1,
};

EvtScript N(EVS_NpcAI_Bobomb_Guard) = {
    EVT_CALL(N(GuardAI_Main), EVT_PTR(N(AISettings_Bobomb_Guard)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bobomb_Guard) = {
    .height = 23,
    .radius = 20,
    .level = ACTOR_LEVEL_BOB_OMB,
    .ai = &N(EVS_NpcAI_Bobomb_Guard),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
};
