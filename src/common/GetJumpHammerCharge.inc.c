#include "common.h"

ApiStatus N(GetJumpHammerCharge)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gBattleStatus.jumpCharge);
    evt_set_variable(script, *args++, gBattleStatus.hammerCharge);

    return ApiStatus_DONE2;
}
