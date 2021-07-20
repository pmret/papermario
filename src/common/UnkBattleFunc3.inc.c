#include "common.h"

ApiStatus N(UnkBattleFunc3)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_variable(script, *args++, gPlayerData.bootsLevel);
    set_variable(script, *args++, gPlayerData.hammerLevel);

    return ApiStatus_DONE2;
}
