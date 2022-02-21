#include "common.h"
#include "effects_internal.h"

void func_E0080448(EffectInstance* effect);

extern Gfx D_09003540[];
extern Gfx D_09003580[];
extern Gfx D_090035C0[];
extern Gfx D_09003600[];
extern Gfx D_09003640[];
extern Gfx D_09003680[];
extern Gfx D_090036C0[];
extern Gfx D_09003700[];
extern Gfx D_09003740[];
extern Gfx D_09003780[];
extern Gfx D_090037C0[];
extern Gfx D_09003800[];

Gfx* D_E0080AC0[] = { D_09003540, D_09003580, D_090035C0, D_09003600, D_09003640, D_09003680, D_090036C0, D_09003700, D_09003740, D_09003780, D_090037C0, D_09003800, };

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
