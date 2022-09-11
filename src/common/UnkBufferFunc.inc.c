#include "common.h"

ApiStatus N(UnkBufferFunc)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_s1 = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);

    script->buffer = &script->buffer[temp_s1 + (temp_s0_3 * evt_get_variable(script, *args++))];
    return ApiStatus_DONE2;
}
