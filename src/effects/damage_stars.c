#include "common.h"
#include "effects_internal.h"

void damage_stars_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/damage_stars", damage_stars_main);

void damage_stars_init(void) {
}

void damage_stars_update(EffectInstance* effect) {
    DamageStarsFXData* part = effect->data.damageStars;
    s32 unk_28;
    s32 unk_2C;
    s32 i;

    part->unk_28--;
    part->unk_2C++;

    if (part->unk_28 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_28 = part->unk_28;
    unk_2C = part->unk_2C;

    for (i = 0; i < effect->numParts; i++, part++) {
        if (part->unk_00 == 2) {
            part->unk_14 = shim_cos_deg(unk_2C * 6) * 4.0f;
            part->unk_10 *= 0.94;
            part->unk_18 *= 0.94;
            if (part->unk_14 < 0.0f) {
                part->unk_20 *= 0.8;
                part->unk_24 *= 0.6;
            }
        } else {
            if (unk_28 >= 6) {
                part->unk_10 *= 0.8;
                part->unk_14 *= 0.8;
                part->unk_18 *= 0.8;
            }
            if (unk_28 - 6 < 0xEU) {
                if (part->unk_00 == 0) {
                    part->unk_20 += 1.0f;
                }
            } else if (unk_28 < 5) {
                part->unk_20 *= 0.8;
                part->unk_24 *= 0.6;
                part->unk_10 *= 0.7;
                part->unk_14 *= 0.7;
                part->unk_18 *= 0.7;
            }
        }

        part->unk_04 += part->unk_10;
        part->unk_08 += part->unk_14;
        part->unk_0C += part->unk_18;
        part->unk_1C += part->unk_20;
    }
}

void damage_stars_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = damage_stars_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/damage_stars", damage_stars_appendGfx);
