#include "common.h"

ApiStatus N(GetBootsHammerLevel)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.bootsLevel);
    evt_set_variable(script, *args++, gPlayerData.hammerLevel);

    return ApiStatus_DONE2;
}
