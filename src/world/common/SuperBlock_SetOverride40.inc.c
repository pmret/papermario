#include "common.h"
#include "npc.h"

ApiStatus N(SuperBlock_SetOverride40)(Evt* script, s32 isInitialCall) {
    gOverrideFlags |= GLOBAL_OVERRIDES_40;
    return ApiStatus_DONE2;
}
