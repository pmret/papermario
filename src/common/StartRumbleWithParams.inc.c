#include "common.h"
#include "npc.h"

API_CALLABLE(N(StartRumbleWithParams)) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);

    start_rumble(var0, var1);

    return ApiStatus_DONE2;
}
