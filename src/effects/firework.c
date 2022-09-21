#include "common.h"
#include "effects_internal.h"

extern u8 D_E0086AC0[];
extern u8 D_E0086AC4[];
extern u8 D_E0086AD4[];

void func_E00863B4();

INCLUDE_ASM(s32, "effects/firework", firework_main);

void firework_init(void) {
}

void firework_update(EffectInstance* effect) {
    FireworkFXData* part = effect->data.firework;
    s32 unk_00 = part->unk_00;
    s32 unk_34;
    s32 idx;
    s32 i;

    part->unk_30--;
    part->unk_34++;

    if (part->unk_30 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_34 = part->unk_34;

    if (D_E0086AC0[unk_00] >= unk_34) {
        part->unk_38 = D_E0086AC4[unk_34 - 1] / 256.0f;
    } else {
        part->unk_38 = 1.0f;
    }

    part++;
    for (i = 1; i < effect->numParts; i++, part++) {
        if (D_E0086AC0[unk_00] >= unk_34) {
            idx = unk_34 - 1;
        } else {
            idx = 12;
        }
        part->unk_04 = D_E0086AD4[idx];
        part->unk_08 = 0;
        part->unk_0C = 0;
    }
}

void firework_render(void) {
}

void func_E0086398(void) {
    func_E00863B4();
}

INCLUDE_ASM(s32, "effects/firework", func_E00863B4);
