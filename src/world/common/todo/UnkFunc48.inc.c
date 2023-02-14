#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc48)) {
    gPlayerStatus.pitch = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
