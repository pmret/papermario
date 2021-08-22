#include "common.h"
#include "map.h"

ApiStatus N(FreeIcon)(Evt* script, s32 isInitialCall) {
    free_hud_element(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
