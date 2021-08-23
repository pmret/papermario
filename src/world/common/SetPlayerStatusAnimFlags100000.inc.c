#include "common.h"
#include "map.h"

ApiStatus N(SetPlayerStatusAnimFlags100000)(Evt* script, s32 isInitialCall) {
    gPlayerStatusPtr->animFlags |= 0x100000;
    return ApiStatus_DONE2;
}
