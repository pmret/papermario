#include "osr_01.h"

s32 func_80240000_AAFFF0(void) {
    if (gGameStatusPtr->entryID == osr_01_ENTRY_3) {
        sprintf(wMapBgName, "hos_bg");
    }
    return FALSE;
}

const char* N(exit_str_0) = "mac_01\0\0hos_00\0\0mac_04";
