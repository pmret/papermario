#include "kkj_12.h"

static char* N(exit_str_0) = "kkj_11";
static char* N(exit_str_1) = "kkj_13";

ApiStatus func_80240000_AD4090(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < 2; i++) {
        D_80151328->sources[i].flags = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80240034_AD40C4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}
