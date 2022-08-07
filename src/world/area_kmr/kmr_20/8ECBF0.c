#include "kmr_20.h"

ApiStatus func_80240DD0_8ECBF0(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 0x3F);
    return ApiStatus_DONE2;
}

#include "world/common/UnsetCamera0MoveFlag1.inc.c"
