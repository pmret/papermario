#include "common.h"
#include "npc.h"

API_CALLABLE(N(StartRumbleWithParams)) {
    Bytecode* args = script->ptrReadPos;

    start_rumble(evt_get_variable(script, *args++), evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}
