#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc35)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    set_transition_stencil_color(0, var1, var2, var3);
    return ApiStatus_DONE2;
}
