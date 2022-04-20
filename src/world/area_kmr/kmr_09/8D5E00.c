#include "kmr_09.h"

static char* N(exit_str_0) = "kmr_02";
static char* N(exit_str_1) = "kmr_06";

#include "world/common/atomic/enemy/BzzapAI.inc.c"

ApiStatus func_802414F8_8D72F8(Evt* script, s32 isInitialCall) {
    script->varTable[0] = get_enemy_safe(2);

    return ApiStatus_DONE2;
}
