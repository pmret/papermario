#include "Toad.h"

#include "world/common/enemy/ai/StationaryAI.inc.c"

StationaryAISettings N(AISettings_Toad_Guard) = {
    .playerSearchInterval = -1,
    .chaseRadius = 300.0f,
    .unk_20 = 30,
};

EvtScript N(EVS_NpcAI_Toad_Guard) = {
    EVT_CALL(N(StationaryAI_Main), EVT_PTR(N(AISettings_Toad_Guard)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Toad_Guard) = {
    .height = 30,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_Toad_Guard),
};

NpcSettings N(NpcSettings_ToadKid_Guard) = {
    .height = 23,
    .radius = 19,
    .level = 99,
    .ai = &N(EVS_NpcAI_Toad_Guard),
};
