#include "common_structs.h"
#include "effects.h"
#include "evt.h"

API_CALLABLE(N(PlayBigSmokePuff)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_big_smoke_puff(x, y, z);

    return ApiStatus_DONE2;
}
