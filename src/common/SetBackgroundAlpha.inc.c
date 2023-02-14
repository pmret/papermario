#include "common.h"
#include "model.h"

API_CALLABLE(N(SetBackgroundAlpha)) {
    Bytecode* args = script->ptrReadPos;

    set_background_color_blend(0, 0, 0, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}
