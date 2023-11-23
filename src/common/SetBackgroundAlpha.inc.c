#include "common.h"
#include "model.h"

API_CALLABLE(N(SetBackgroundAlpha)) {
    Bytecode* args = script->ptrReadPos;

    mdl_set_shroud_tint_params(0, 0, 0, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}
