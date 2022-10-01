#include "hos_00.h"

static char* N(exit_str_4) = "osr_01";

ApiStatus func_802407C0_A0C4B0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gPlayerData.currentPartner = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}
