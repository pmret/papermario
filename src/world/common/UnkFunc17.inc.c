#include "common.h"
#include "npc.h"

ApiStatus N(UnkFunc17)(Evt* script, s32 isInitialCall) {
    gOverrideFlags &= ~0x40;
    return ApiStatus_DONE2;
}
