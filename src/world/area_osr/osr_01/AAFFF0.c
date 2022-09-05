#include "osr_01.h"

extern s8 D_800D9668;

ApiStatus func_80240000_AAFFF0(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->entryID == 3) {
        sprintf(&D_800D9668, "hos_bg");
    }
    return ApiStatus_BLOCK;
}

const char* N(exit_str_0) = "mac_01\0\0hos_00\0\0mac_04";
