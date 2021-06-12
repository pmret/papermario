#include "common.h"
#include "map.h"

ApiStatus N(SetManyVars)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->varTable[2].s = get_variable(script, *args++);
    script->varTable[3].s = get_variable(script, *args++);
    script->varTable[4].s = get_variable(script, *args++);
    script->varTable[5].s = get_variable(script, *args++);
    script->varTable[6].s = get_variable(script, *args++);
    script->varTable[7].s = get_variable(script, *args++);
    script->varTable[8].s = get_variable(script, *args++);
    script->varTable[9].s = get_variable(script, *args++);
    script->varTable[10].s = get_variable(script, *args++);
    script->varTable[11].s = get_variable(script, *args++);
    return ApiStatus_DONE2;
}
