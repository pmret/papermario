#include "end_00.h"

extern s32 D_80249D60_E00760;

ApiStatus func_80242B10_DF9510(Evt *script, s32 isInitialCall) {
    D_80249D60_E00760 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
