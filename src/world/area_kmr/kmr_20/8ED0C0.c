#include "kmr_20.h"

#include "world/common/atomic/ToadHouse.inc.c"

ApiStatus func_8024159C_8ED3BC(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_802415C4_8ED3E4(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 0x3F);
    return ApiStatus_DONE2;
}

#include "world/common/WaitForPlayerToLand.inc.c"
