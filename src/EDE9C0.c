#include "dead.h"
#include "common.h"

#define NAMESPACE EDE9C0

ApiStatus func_80240000_EDE9C0(Evt *script, s32 isInitialCall) {
    dead_playFX_82(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}
