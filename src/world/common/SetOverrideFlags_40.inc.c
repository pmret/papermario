#include "common.h"
#include "map.h"

ApiStatus N(SetOverrideFlags_40)(ScriptInstance* script, s32 isInitialCall) {
    gOverrideFlags |= 0x40;
    return ApiStatus_DONE2;
}
