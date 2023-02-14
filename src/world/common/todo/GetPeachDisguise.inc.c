#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetPeachDisguise)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerStatus.peachDisguise);
    return ApiStatus_DONE2;
}
