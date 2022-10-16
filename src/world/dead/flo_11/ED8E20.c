#include "flo_11.h"

#include "world/common/entity/Pipe.inc.c"

void fx_sun(s32, s32, s32, s32, s32, s32);

ApiStatus func_80240318_ED9138(Evt* script, s32 isInitialCall) {
    fx_sun(0, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

const static char* exit_string1 = "flo_23";
const static char* exit_string2 = "flo_12";
const static char* exit_string3 = "flo_11";
