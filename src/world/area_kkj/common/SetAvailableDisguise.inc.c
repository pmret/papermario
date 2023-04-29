#include "common.h"

API_CALLABLE(N(SetAvailableDisguise)) {
    Bytecode* args = script->ptrReadPos;

    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}
