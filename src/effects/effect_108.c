#include "common.h"

INCLUDE_ASM(s32, "effects/effect_108", fx_108_main);

void fx_108_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_108", fx_108_update);

void fx_108_render(void) {
}

INCLUDE_ASM(s32, "effects/effect_108", func_E00D8264);

void func_E00D8280(void) {
}

void func_E00D8288(s32 l, s32 r, s32 t, s32 b) {
    if (l < 0) {
        l = 0;
    }
    if (r < 0) {
        r = 0;
    }
    if (t < 0) {
        t = 0;
    }
    if (b < 0) {
        b = 0;
    }

    if (l > SCREEN_WIDTH - 1) {
        l = SCREEN_WIDTH - 1;
    }
    if (r > SCREEN_HEIGHT - 1) {
        r = SCREEN_HEIGHT - 1;
    }
    if (t > SCREEN_WIDTH - 1) {
        t = SCREEN_WIDTH - 1;
    }
    if (b > SCREEN_HEIGHT - 1) {
        b = SCREEN_HEIGHT - 1;
    }

    gDPFillRectangle(gMasterGfxPos++, l, r, t, b);
}

INCLUDE_ASM(s32, "effects/effect_108", func_E00D8334);

INCLUDE_ASM(s32, "effects/effect_108", func_E00D8630);
