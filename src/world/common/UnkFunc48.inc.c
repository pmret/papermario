#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc48)(Evt* script, s32 isInitialCall) {
    gPlayerStatus.unk_8C = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
