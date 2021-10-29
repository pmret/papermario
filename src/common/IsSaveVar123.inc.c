#include "common.h"
#include "npc.h"

ApiStatus N(IsSaveVar123)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if (evt_get_variable(NULL, EVT_SAVE_VAR(123)) >= 8) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
