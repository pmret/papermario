#include "hos_05.h"

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EC30", func_802449F0_A2EC30);

ApiStatus func_80244C60_A2EEA0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    void (*callback)(void) = (void (*)(void))evt_get_variable(script, *args++);
    set_curtain_draw_callback(callback);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EC30", func_80244C8C_A2EECC);
