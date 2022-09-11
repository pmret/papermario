#include "isk_07.h"
#include "mapfs/isk_07_hit.h"

ApiStatus func_802400F0_982530(Evt* script, s32 isInitialCall) {
    if (gCollisionStatus.currentFloor == COLLIDER_o2022) {
        return ApiStatus_BLOCK;
    } else {
        return ApiStatus_DONE2;
    }
}

