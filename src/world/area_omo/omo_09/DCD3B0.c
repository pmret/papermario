#include "omo_09.h"

ApiStatus func_802406E0_DCD3B0(Evt* script, s32 isInitialCall) {
    if (gPlayerStatus.position.x < 850.0f) {
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}
