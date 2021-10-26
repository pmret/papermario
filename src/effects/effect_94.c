#include "common.h"

INCLUDE_ASM(s32, "effects/effect_94", fx_94_main);

void fx_94_init(void) {
}

f32 func_E00BC1D8(f32 arg0) {
    return (f32)shim_rand_int((s32)arg0) - arg0 * 0.5;
}

INCLUDE_ASM(s32, "effects/effect_94", fx_94_update);

INCLUDE_ASM(s32, "effects/effect_94", fx_94_render);

void func_E00BC36C(void) {
}

INCLUDE_ASM(s32, "effects/effect_94", fx_94_appendGfx);
