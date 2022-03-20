#include "common.h"

ApiStatus N(CompareFloats)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f20 = evt_get_float_variable(script, *args++);
    f32 temp = evt_get_float_variable(script, *args++);

    if (temp < temp_f20) {
        evt_set_variable(script, *args++, TRUE);
    } else {
        evt_set_variable(script, *args++, FALSE);
    }
    return ApiStatus_DONE2;
}
