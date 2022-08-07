#include "end_00.h"

#ifdef NON_MATCHING
ApiStatus func_80242AD4_DF94D4(Evt *script, s32 isInitialCall) {
    D_80249D60_E00760 = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_end/end_00/DF9510", func_80242B10_DF9510);
#endif

