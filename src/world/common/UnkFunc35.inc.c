#include "common.h"
#include "npc.h"

ApiStatus N(UnkFunc35)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    set_screen_overlay_color(0, var1, var2, var3);
    return ApiStatus_DONE2;
}
