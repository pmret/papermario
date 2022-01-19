#include "common.h"
#include "npc.h"

ApiStatus N(UnkFunc35)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 R = evt_get_variable(script, *args++);
    s32 G = evt_get_variable(script, *args++);
    s32 B = evt_get_variable(script, *args++);

    set_screen_overlay_color(0, R, G, B);
    return ApiStatus_DONE2;
}
