#include "common.h"

API_CALLABLE(N(GetJumpHammerCharge)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gBattleStatus.jumpCharge);
    evt_set_variable(script, *args++, gBattleStatus.hammerCharge);

    return ApiStatus_DONE2;
}
