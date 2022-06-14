#include "kmr_20.h"

static char* N(exit_str_0) = "mac_00";
static char* N(exit_str_1) = "osr_00";
static char* N(exit_str_2) = "mac_00\0";
static char* N(exit_str_3) = "kmr_02";
static char* N(exit_str_4) = "mac_00\0\0";
static char* N(exit_str_5) = "";

ApiStatus func_80240000_8EBE20(Evt* script, s32 isInitialCall) {
    snd_ambient_slow_fade_out(0, 500);
    return ApiStatus_DONE2;
}
