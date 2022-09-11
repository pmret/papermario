#include "iwa_11.h"

static char* N(exit_str_0) = "mac_03";
static char* N(exit_str_1) = "iwa_10";
static char* N(exit_str_2) = "mac_03\0";
static char* N(exit_str_3) = "iwa_10\0";
static char* N(exit_str_4) = "kmr_22";
static char* N(exit_str_5) = "";

ApiStatus func_80240000_9269F0(Evt* script, s32 isInitialCall) {
    if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
