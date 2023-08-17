#include "SpearGuy.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_SpearGuy_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_SpearGuy_Patrol) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_SpearGuy_Patrol)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_SpearGuy_Patrol) = {
    .height = 28,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_SpearGuy_Patrol),
};
