#include "mac_04.h"

extern char wMapBgName[];

ApiStatus func_80240000_842BD0(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->entryID == 4) {
        sprintf(wMapBgName, "hos_bg");
    }
    return ApiStatus_BLOCK;
}

const char N(exit_str_0)[] = "mac_05";
const char N(exit_str_1)[] = "mac_02";
const char N(exit_str_2)[] = "omo_03";
const char N(exit_str_3)[] = "hos_20\0\0"; // todo remove padding after these are moved
