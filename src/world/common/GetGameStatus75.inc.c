#include "common.h"
#include "npc.h"

ApiStatus N(GetGameStatus75)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, EVT_VAR(0), gGameStatusPtr->debugQuizmo);
    return ApiStatus_DONE2;
}
