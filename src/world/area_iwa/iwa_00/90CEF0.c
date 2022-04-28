#include "iwa_00.h"

ApiStatus func_802402B0_90CEF0(Evt* script, s32 isInitialCall) {
    gPlayerStatus.unk_D0 = script->varTable[0];
    gPlayerStatus.flags |= 0x10;
    return ApiStatus_DONE2;
}
