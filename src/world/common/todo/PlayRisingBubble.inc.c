#include "common_structs.h"
#include "effects.h"
#include "evt.h"

API_CALLABLE(N(PlayRisingBubble)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_rising_bubble(0, x, y, z, 0);

    return ApiStatus_DONE2;
}
