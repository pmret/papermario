#include "common.h"

void begin_state_init(void) {
    D_8009A650[0] |= 8;
    GAME_STATUS->loadMenuState = 3;
}

INCLUDE_ASM("code_e940_len_290", step_init_state);

void func_80033788(void) {
    func_8002AB5C(0, 0, 0x13F, 0xEF, 0, 0, 0, 0xFF);
}
