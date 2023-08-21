#include "Toad_Collection.h"

#include "world/common/enemy/ai/GuardAI.inc.c"

GuardAISettings N(AISettings_Toad_Guard) = {
    .playerSearchInterval = -1,
    .chaseRadius = 300.0f,
    .unk_AI_20 = 30,
};

EvtScript N(EVS_NpcAI_Toad_Guard) = {
    EVT_CALL(N(GuardAI_Main), EVT_PTR(N(AISettings_Toad_Guard)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Toad_Guard) = {
    .height = 30,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Toad_Guard),
};

NpcSettings N(NpcSettings_ToadKid_Guard) = {
    .height = 23,
    .radius = 19,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_Toad_Guard),
};
