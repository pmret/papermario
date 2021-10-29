#include "common.h"
#include "npc.h"

ApiStatus N(StartRumbleWithParams)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    start_rumble(evt_get_variable(script, *args++), evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}
