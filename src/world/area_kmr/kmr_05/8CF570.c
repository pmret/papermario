#include "kmr_05.h"

#include "world/common/foliage.inc.c"

ApiStatus func_8024173C_8CF7AC(ScriptInstance* script, s32 isInitialCall) {
    if (get_enemy_safe(6) == NULL) {
        script->varTable[0] = FALSE;
    } else {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}
