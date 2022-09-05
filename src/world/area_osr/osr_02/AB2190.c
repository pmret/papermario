#include "osr_02.h"

ApiStatus func_80240020_AB2190(Evt* script, s32 isInitialCall) {
    gPlayerStatus.unk_0D = evt_get_float_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
