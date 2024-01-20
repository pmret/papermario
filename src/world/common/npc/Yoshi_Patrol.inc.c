#include "Yoshi.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_Yoshi_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Yoshi_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Yoshi_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_Yoshi_Patrol) = {
    .height = 48,
    .radius = 32,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Yoshi_Patrol),
};
