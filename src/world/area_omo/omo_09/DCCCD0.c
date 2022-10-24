#include "omo_09.h"

static char* N(exit_str_0) = "omo_08";
static char* N(exit_str_1) = "";

ApiStatus func_80240000_DCCCD0(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "world/area_omo/omo_09/DCCCD0", func_80240000_DCCCD0);

ApiStatus func_80240054_DCCD24(Evt* script, s32 isInitialCall) {
    if (func_80240000_DCCCD0(script, isInitialCall) == ApiStatus_BLOCK) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_omo/omo_09/DCCCD0", func_80240078_DCCD48);
