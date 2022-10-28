#include "common.h"
#include "Bubulb.h"

EvtScript N(EVS_NpcAuxAI_Bubulb) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bubulb) = {
    .height = 42,
    .radius = 26,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_Bubulb),
};
