#include "common.h"
#include "npc.h"

ApiStatus N(FreeIcon)(Evt* script, s32 isInitialCall) {
    hud_element_free(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
