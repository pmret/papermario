#include "common.h"
#include "map.h"

ApiStatus N(GetGameStatus75)(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, SI_VAR(0), gGameStatusPtr->debugQuizmo);
    return ApiStatus_DONE2;
}
