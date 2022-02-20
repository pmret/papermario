#include "common.h"
#include "effects_internal.h"

void func_E0080448(EffectInstance* effect);

s32 D_E0080AC0[] = { 0x09003540, 0x09003580, 0x090035C0, 0x09003600, 0x09003640, 0x09003680, 0x090036C0, 0x09003700, 0x09003740, 0x09003780, 0x090037C0, 0x09003800 };

s32 D_E0080AF0[] = { 0x3E800000, 0x3F000000, 0x3F400000, 0x3F800000, 0x3F666666, 0x3F8CCCCD, 0x3F800000 };

f32 D_E0080B0C[] = { 0.25, 0.5, 0.75, 1.0, 1.2, 0.9, 1.0, 0.0, 0.0 };

INCLUDE_ASM(s32, "effects/recover", recover_main);

void recover_init(void) {
}

INCLUDE_ASM(s32, "effects/recover", recover_update);

void recover_render(void) {
}

void func_E008042C(EffectInstance* effect) {
    func_E0080448(effect);
}

INCLUDE_ASM(s32, "effects/recover", func_E0080448);
