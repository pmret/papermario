#include "common.h"
#include "map.h"

ApiStatus N(StartRumbleWithParams)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    start_rumble(get_variable(script, *args++), get_variable(script, *args++));

    return ApiStatus_DONE2;
}
