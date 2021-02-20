#include "common.h"
#include "map.h"

ApiStatus N(GetGameStatus75)(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, SI_VAR(0), (*gGameStatusPtr)->unk_75);
    return ApiStatus_DONE2;
}
