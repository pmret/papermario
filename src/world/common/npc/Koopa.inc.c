#include "common.h"
#include "Koopa.h"
#include "Kooper.h"

NpcSettings N(NpcSettings_Koopa) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};
