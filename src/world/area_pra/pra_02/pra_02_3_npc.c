#include "pra_02.h"

EvtScript N(EVS_NpcAuxAI_Unused) = {
    Return
    End
};

NpcSettings N(NpcSettings_Unused) = {
    .height = 70,
    .radius = 25,
    .level = ACTOR_LEVEL_NONE,
    .otherAI = &N(EVS_NpcAuxAI_Unused),
};

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"
