#include "YoshiKid.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_YoshiKid_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_YoshiKid_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_YoshiKid_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_YoshiKid_Patrol) = {
    .height = 28,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_YoshiKid_Patrol),
};
