#include "Toad_Collection.h"

#include "world/common/enemy/ai/PatrolNoAttackAI.inc.c"

MobileAISettings N(AISettings_Toad_Patrol) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Toad_Patrol) = {
    Call(N(PatrolNoAttackAI_Main), Ref(N(AISettings_Toad_Patrol)))
    Return
    End
};

NpcSettings N(NpcSettings_Toad_Patrol) = {
    .height = 30,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Toad_Patrol),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_ToadKid_Patrol) = {
    .height = 23,
    .radius = 19,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Toad_Patrol),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};
