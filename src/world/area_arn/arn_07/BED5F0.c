#include "arn_07.h"

ApiStatus N(func_80240800_BED5F0)(Evt* script, s32 isInitialCall) {
    f32 temp_f0 = evt_get_float_variable(script, LVar0);

    if (temp_f0 >= 360.0) {
        temp_f0 -= 360.0;
    }
    evt_set_float_variable(script, LVar0, temp_f0);
    return ApiStatus_DONE2;
}
