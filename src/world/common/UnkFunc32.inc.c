#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc32)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);

    set_transition_stencil_center(0, 0, 190, 145);
    set_transition_stencil_zoom_0(var1, var2);

    return ApiStatus_DONE2;
}
