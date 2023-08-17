#include "common.h"
#include "Bubulb.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_Bubulb_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Bubulb_Patrol) = {
    EVT_CALL(N(PatrolNoAttackAI_Main), EVT_PTR(N(AISettings_Bubulb_Patrol)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bubulb_Patrol) = {
    .height = 42,
    .radius = 28,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Bubulb_Patrol),
};
