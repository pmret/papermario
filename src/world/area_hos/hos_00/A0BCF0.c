#include "hos_00.h"

extern char wMapBgName[];

ApiStatus func_80240000_A0BCF0(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->entryID == 3) {
        sprintf(wMapBgName, "hos_bg\0\0\0\0\0\0\0\0\0");
    }
    return ApiStatus_BLOCK;
}
