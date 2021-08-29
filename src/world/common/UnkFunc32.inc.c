#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc32)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    set_screen_overlay_center(0, 0, 190, 145);
    set_screen_overlay_params_front(var1, var2);

    return ApiStatus_DONE2;
}
