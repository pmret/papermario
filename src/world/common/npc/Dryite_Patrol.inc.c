#include "Dryite.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_Dryite_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Dryite_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Dryite_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_Dryite_Patrol) = {
    .height = 26,
    .radius = 23,
    .ai = &N(EVS_NpcAI_Dryite_Patrol),
    .level = ACTOR_LEVEL_NONE,
    .actionFlags = 16,
};
