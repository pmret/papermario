#include "sbk_56.h"

static char* N(exit_str_0) = "sbk_55";
static char* N(exit_str_1) = "sbk_46";
static char* N(exit_str_2) = "sbk_66";
static char* N(exit_str_3) = "";

#include "world/common/SpawnSunEffect.inc.c"

ApiStatus func_80240038_953FF8(void) {
    bgm_set_variation(0, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_8024005C_95401C(void) {
    bgm_set_variation(0, 0);
    return ApiStatus_DONE2;
}

#include "world/common/atomic/SuperBlock.inc.c"
