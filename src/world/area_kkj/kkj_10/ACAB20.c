#include "kkj_10.h"

static char* N(exit_str_0) = "osr_02";
static char* N(exit_str_1) = "kkj_11";
static char* N(exit_str_2) = "kkj_21";
static char* N(exit_str_3) = "kkj_19";
static char* N(exit_str_4) = "kkj_20";
static char* N(exit_str_5) = "kkj_29";

ApiStatus func_80240000_ACAB20(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80151328->sources); i++) {
        D_80151328->sources[i].flags = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240034_ACAB54(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}
