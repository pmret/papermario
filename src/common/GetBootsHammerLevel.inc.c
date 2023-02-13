#include "common.h"

API_CALLABLE(N(GetBootsHammerLevel)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.bootsLevel);
    evt_set_variable(script, *args++, gPlayerData.hammerLevel);

    return ApiStatus_DONE2;
}
