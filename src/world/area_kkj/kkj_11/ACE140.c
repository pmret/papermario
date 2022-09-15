#include "kkj_11.h"

static char* N(exit_str_0) = "kkj_10";
static char* N(exit_str_1) = "kkj_12";
static char* N(exit_str_2) = "kkj_14";
static char* N(exit_str_3) = "kkj_16";
static char* N(exit_str_4) = "kkj_15";
static char* N(exit_str_5) = "kkj_17";
static char* N(exit_str_6) = "kkj_18";
static char* N(exit_str_7) = "kkj_11";

ApiStatus func_80240000_ACE140(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80151328->sources); i++) {
        D_80151328->sources[i].flags = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240034_ACE174(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}
