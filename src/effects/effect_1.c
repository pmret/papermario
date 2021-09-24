#include "common.h"

INCLUDE_ASM(s32, "effects/effect_1", fx_1_main);

void func_E00021B4(void) {
}

INCLUDE_ASM(s32, "effects/effect_1", func_E00021BC);

INCLUDE_ASM(s32, "effects/effect_1", func_E00022BC);

INCLUDE_ASM(s32, "effects/effect_1", func_E0002300);

void func_E0002738(void) {
    shim_remove_effect();
}
