#include "RaphaelRaven.h"

EvtScript N(EVS_NpcAuxAI_RaphaelRaven) = {
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(1.5), EVT_FLOAT(1.5), EVT_FLOAT(1.5))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_RaphaelRaven) = {
    .height = 98,
    .radius = 80,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_RaphaelRaven),
};
