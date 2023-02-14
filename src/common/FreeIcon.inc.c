#include "common.h"
#include "npc.h"

API_CALLABLE(N(FreeIcon)) {
    hud_element_free(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
