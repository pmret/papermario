#include "mim_08.h"

static char* N(exit_str_0) = "mim_01";
static char* N(exit_str_1) = "mim_05";

#include "world/common/SetForeverForestFog.inc.c"

ApiStatus func_80240068_BAD9A8(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_xz_dist_to_player(0.0f, 0.0f);
    return 2;
}

#include "world/common/atomic/enemy/BzzapAI.inc.c"

#include "world/common/atomic/enemy/PiranhaPlantAI.inc.c"
