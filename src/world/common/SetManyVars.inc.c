#include "common.h"
#include "map.h"

ApiStatus N(SetManyVars)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->varTable[2] = evt_get_variable(script, *args++);
    script->varTable[3] = evt_get_variable(script, *args++);
    script->varTable[4] = evt_get_variable(script, *args++);
    script->varTable[5] = evt_get_variable(script, *args++);
    script->varTable[6] = evt_get_variable(script, *args++);
    script->varTable[7] = evt_get_variable(script, *args++);
    script->varTable[8] = evt_get_variable(script, *args++);
    script->varTable[9] = evt_get_variable(script, *args++);
    script->varTable[10] = evt_get_variable(script, *args++);
    script->varTable[11] = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}
