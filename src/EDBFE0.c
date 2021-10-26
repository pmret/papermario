#include "dead.h"
#include "common.h"

#define NAMESPACE ED8FE0

ApiStatus func_80240000_EDBFE0(Evt *script, s32 isInitialCall) {
    dead_playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
