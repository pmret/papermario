#include "hos_04.h"

const char D_80243330_A2A200[] = "hos_20\0\0kpa_60\0\0hos_00\0\0osr_03\0\0hos_05";

extern s32 D_80243284_A2A154;

void func_80240BD0_A27AA0(s32*);
INCLUDE_ASM(s32, "world/area_hos/hos_04/A27AA0", func_80240BD0_A27AA0);

ApiStatus func_80240E40_A27D10(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    set_curtain_draw_callback((void (*)) evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

void func_80240E6C_A27D3C(void) {
    func_80240BD0_A27AA0(&D_80243284_A2A154);
}
