#include "kpa_16.h"

ApiStatus func_80240310_A5A340(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 zoom = evt_get_variable(script, *args++);
    
    set_screen_overlay_params_front(0, zoom);
    return ApiStatus_DONE2;
}

ApiStatus func_8024034C_A5A37C(Evt* script, s32 isInitialCall) {
    snd_ambient_80055618(0, 1);
    return ApiStatus_DONE2;
}

#include "world/common/todo/GetFloorCollider.inc.c"
