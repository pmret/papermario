#include "common.h"

ApiStatus N(GetJumpHammerCharge)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_variable(script, *args++, gBattleStatus.jumpCharge);
    set_variable(script, *args++, gBattleStatus.hammerCharge);

    return ApiStatus_DONE2;
}
