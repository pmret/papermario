#include "common.h"
#include "map.h"

ApiStatus N(SetOverrideFlags_40)(ScriptInstance* script, s32 isInitialCall) {
    OVERRIDE_FLAG_SET(0x40);
    return ApiStatus_DONE2;
}
