#include "jan_10.h"

#include "common/foliage.inc.c"

ApiStatus func_802414BC_B6D84C(Evt* script, s32 isInitialCall) {
    if (get_enemy_safe(1) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }
    return ApiStatus_DONE2;
}
