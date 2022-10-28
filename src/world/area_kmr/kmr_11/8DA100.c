#include "kmr_11.h"

static char* N(exit_str_0) = "kmr_24";
static char* N(exit_str_1) = "kmr_12";
static char* N(exit_str_2) = "kmr_10";
static char* N(exit_str_3) = "";

#include "common/foliage.inc.c"

#include "common/UnkFogFunc.inc.c"

ApiStatus func_8024027C_8DA37C(Evt* script, s32 isInitialCall) {
    set_map_change_fade_rate(10);
    return ApiStatus_DONE2;
}
