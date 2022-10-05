#include "common.h"
#include "effects_internal.h"

void func_E0080448(EffectInstance* effect);

extern Gfx D_09003540_385340[];
extern Gfx D_09003580_385380[];
extern Gfx D_090035C0_3853C0[];
extern Gfx D_09003600_385400[];
extern Gfx D_09003640_385440[];
extern Gfx D_09003680_385480[];
extern Gfx D_090036C0_3854C0[];
extern Gfx D_09003700_385500[];
extern Gfx D_09003740_385540[];
extern Gfx D_09003780_385580[];
extern Gfx D_090037C0_3855C0[];
extern Gfx D_09003800_385600[];

Gfx* D_E0080AC0[] = { D_09003540_385340, D_09003580_385380, D_090035C0_3853C0,
                      D_09003600_385400, D_09003640_385440, D_09003680_385480,
                      D_090036C0_3854C0, D_09003700_385500, D_09003740_385540,
                      D_09003780_385580, D_090037C0_3855C0, D_09003800_385600, };

f32 D_E0080AF0[] = { 0.25f, 0.5f, 0.75f, 1.0f, 0.9f, 1.1f, 1.0f };

f32 D_E0080B0C[] = { 0.25f, 0.5f, 0.75f, 1.0f, 1.2f, 0.9f, 1.0f };

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
