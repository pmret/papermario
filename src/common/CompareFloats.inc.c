#include "common.h"

API_CALLABLE(N(CompareFloats)) {
    Bytecode* args = script->ptrReadPos;
    f32 temp_f20 = evt_get_float_variable(script, *args++);
    f32 temp = evt_get_float_variable(script, *args++);

    if (temp < temp_f20) {
        evt_set_variable(script, *args++, true);
    } else {
        evt_set_variable(script, *args++, false);
    }
    return ApiStatus_DONE2;
}
