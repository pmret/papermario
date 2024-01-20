#include "RaphaelRaven.h"

EvtScript N(EVS_NpcAuxAI_RaphaelRaven) = {
    Call(SetNpcScale, NPC_SELF, Float(1.5), Float(1.5), Float(1.5))
    Return
    End
};

NpcSettings N(NpcSettings_RaphaelRaven) = {
    .height = 98,
    .radius = 80,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_RaphaelRaven),
};
