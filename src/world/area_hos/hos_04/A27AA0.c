#include "hos_04.h"

INCLUDE_ASM(s32, "world/area_hos/hos_04/A27AA0", func_80240BD0_A27AA0);

ApiStatus func_80240E40_A27D10(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    set_curtain_draw_callback((void (*)) evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_hos/hos_04/A27AA0", func_80240E6C_A27D3C);
