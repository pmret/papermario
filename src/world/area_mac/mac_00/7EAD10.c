#include "mac_00.h"

static char* N(exit_str_0) = "kmr_10";
static char* N(exit_str_1) = "mac_01";
static char* N(exit_str_2) = "tik_19";
static char* N(exit_str_3) = "kmr_20";
static char* N(exit_str_4) = "mac_00";
static char* N(exit_str_5) = "\0\0\0\0";

#include "world/common/atomic/Pipe.inc.c"

#include "world/common/UpdateTexturePan.inc.c"

ApiStatus func_802405EC_7EB2FC(Evt* script, s32 isInitialCall) {
    f32 x;
    f32 y;
    f32 z;

    get_collider_center(evt_get_variable(script, *script->ptrReadPos), &x, &y, &z);
    return ApiStatus_DONE2;
}

ApiStatus func_80240624_7EB334(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}
