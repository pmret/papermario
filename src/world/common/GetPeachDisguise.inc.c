#include "common.h"
#include "npc.h"

ApiStatus N(GetPeachDisguise)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerStatus.peachDisguise);
    return ApiStatus_DONE2;
}
