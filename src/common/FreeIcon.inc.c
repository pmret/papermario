#include "common.h"
#include "map.h"

ApiStatus N(FreeIcon)(ScriptInstance* script, s32 isInitialCall) {
    hud_element_free(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
