#include "common.h"
#include "map.h"

ApiStatus N(UnkBattleFunc2)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 z = get_variable(script, *args++);

    func_802D7460(x, y, z, get_variable(script, *args++));

    return ApiStatus_DONE2;
}
