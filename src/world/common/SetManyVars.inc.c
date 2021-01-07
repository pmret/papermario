#include "common.h"
#include "map.h"

ApiStatus N(SetManyVars)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->varTable[2] = get_variable(script, *args++);
    script->varTable[3] = get_variable(script, *args++);
    script->varTable[4] = get_variable(script, *args++);
    script->varTable[5] = get_variable(script, *args++);
    script->varTable[6] = get_variable(script, *args++);
    script->varTable[7] = get_variable(script, *args++);
    script->varTable[8] = get_variable(script, *args++);
    script->varTable[9] = get_variable(script, *args++);
    script->varTable[10] = get_variable(script, *args++);
    script->varTable[11] = get_variable(script, *args++);
    return ApiStatus_DONE2;
}
