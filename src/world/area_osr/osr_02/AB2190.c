#include "osr_02.h"

ApiStatus func_80240020_AB2190(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}
