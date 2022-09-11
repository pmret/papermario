#include "common.h"
#include "effects_internal.h"

void confetti_appendGfx(void* effect);

void func_E0088000(ConfettiFXData* part) {
    part->unk_04 = shim_rand_int(700) * 0.1f - 35.0f;
    part->unk_08 = 0;
    part->unk_0C = shim_rand_int(300) * 0.1f - 15.0f;
    part->unk_10 = (part->unk_04 + shim_rand_int(100) * 0.1f - 5.0f) * 0.03;
    part->unk_14 = -1.7 - shim_rand_int(800) * 0.1f * 0.01;
    part->unk_18 = (shim_rand_int(200) * 0.1f - 10.0f) * 0.05;
    part->unk_20 = 120;
}

INCLUDE_ASM(s32, "effects/confetti", confetti_main);

void confetti_init(void) {
}

void confetti_update(EffectInstance* effect) {
    ConfettiFXData* part = effect->data.confetti;
    s32 unk_00;
    s32 unk_24;
    s32 unk_2C;
    s32 i;

    part->unk_20--;
    if (part->unk_20 < 0) {
        shim_remove_effect(effect);
        return;
    }

    part->unk_24++;
    if (part->unk_24 > 324000) {
        part->unk_24 = 10;
    }

    unk_24 = part->unk_24;
    unk_00 = part->unk_00;
    unk_2C = part->unk_2C;

    if (part->unk_20 < 10) {
        part->unk_28 = part->unk_20 * 25;
    }

    part++;
    for (i = 0; i < unk_2C; i++, part++) {
        if (unk_00 == 3) {
            if (part->unk_30 <= 0 || --part->unk_30 <= 0) {
                part->unk_20--;
                if (part->unk_20 < 0) {
                    func_E0088000(part);
                    part->unk_20--;
                }
                part->unk_04 += part->unk_10;
                part->unk_08 += part->unk_14;
                part->unk_0C += part->unk_18;
            }
        } else {
            if (part->unk_30 <= 0 || --part->unk_30 <= 0) {
                if (unk_00 >= 4) {
                    part->unk_10 *= 0.98;
                    part->unk_14 *= 0.98;
                    part->unk_18 *= 0.98;
                    if (unk_24 >= 6 && part->unk_14 > -0.5) {
                        part->unk_14 += part->unk_1C;
                    }
                }
                part->unk_04 += part->unk_10;
                part->unk_08 += part->unk_14;
                part->unk_0C += part->unk_18;
            }
        }
    }
}

void confetti_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = confetti_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/confetti", confetti_appendGfx);
