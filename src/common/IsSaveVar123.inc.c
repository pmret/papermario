#include "common.h"
#include "map.h"

ApiStatus N(IsSaveVar123)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0].s = 0;
    if (get_variable(NULL, SI_SAVE_VAR(123)) >= 8) {
        script->varTable[0].s = 1;
    }

    return ApiStatus_DONE2;
}
