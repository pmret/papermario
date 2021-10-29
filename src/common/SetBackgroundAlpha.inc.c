#include "common.h"
#include "npc.h"

ApiStatus N(SetBackgroundAlpha)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    set_background_color_blend(0, 0, 0, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}
