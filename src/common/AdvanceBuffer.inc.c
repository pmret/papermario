#include "common.h"

// skips ahead in buffer by constant + count * size
API_CALLABLE(N(AdvanceBuffer)) {
    Bytecode* args = script->ptrReadPos;
    s32 constant = evt_get_variable(script, *args++);
    s32 size = evt_get_variable(script, *args++);
    s32 count = evt_get_variable(script, *args++);

    script->buffer = &script->buffer[constant + size * count];
    return ApiStatus_DONE2;
}
