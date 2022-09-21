#include "common.h"
#include "effects_internal.h"

void firework_rocket_init(EffectInstance* effect);
void firework_rocket_render(EffectInstance* effect);
void firework_rocket_update(EffectInstance* effect);
void firework_rocket_appendGfx(void* effect);

EffectInstance* firework_rocket_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    EffectBlueprint bp;
    EffectInstance* effect;
    FireworkRocketFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = firework_rocket_init;
    bp.update = firework_rocket_update;
    bp.renderWorld = firework_rocket_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_FIREWORK_ROCKET;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.fireworkRocket = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.fireworkRocket != NULL);

    data->unk_00 = arg0;
    data->unk_20 = 0;
    if (arg8 <= 0) {
        data->unk_1C = 1000;
    } else {
        data->unk_1C = arg8 + 32;
    }
    data->unk_4C = 0;
    data->unk_30 = 255;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_44 = 0;
    data->unk_10 = arg4;
    data->unk_14 = arg5;
    data->unk_18 = arg6;
    data->unk_48 = arg7;
    data->unk_2C = 100;
    data->unk_38 = 100;
    data->unk_24 = 255;
    data->unk_28 = 255;
    data->unk_34 = 255;
    data->unk_3C = 150;
    data->unk_40 = 255;

    for (i = 0; i < 4; i++) {
        data->unk_50[i] = data->unk_04;
        data->unk_60[i] = data->unk_08 - 1000.0f;
        data->unk_70[i] = data->unk_0C;
        data->unk_80[i] = 0;
        data->unk_90[i] = 0;
        data->unk_A0[i] = 0;
    }

    return effect;
}

void firework_rocket_init(EffectInstance* effect) {
}

void firework_rocket_update(EffectInstance* effect) {
    FireworkRocketFXData* data = effect->data.fireworkRocket;
    f32 factor;
    s32 unk_20;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_1C = 16;
    }

    if (data->unk_1C < 1000) {
        data->unk_1C--;
    }

    data->unk_20++;

    if (data->unk_1C < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_20 = data->unk_20;

    if (data->unk_1C < 32) {
        data->unk_30 = data->unk_1C * 8;
    }

    if (data->unk_4C == 1) {
        factor = 0.95f;
        data->unk_04 += data->unk_10;
        data->unk_08 += data->unk_14;
        data->unk_0C += data->unk_18;
        data->unk_10 *= factor;
        data->unk_14 *= factor;
        data->unk_18 *= factor;
        data->unk_44 += (data->unk_48 - data->unk_44) * 0.11;
        data->unk_14 -= 0.15;
        return;
    }

    i = unk_20 & 3;
    data->unk_50[i] = data->unk_04 - data->unk_10 * (32 - unk_20);
    data->unk_60[i] = data->unk_08 - data->unk_14 * (32 - unk_20)
        - (80.0f - shim_sin_deg((s32) (unk_20 * 90) >> 5) * 80.0f);
    data->unk_70[i] = data->unk_0C - data->unk_18 * (32 - unk_20);
    data->unk_80[i] = (shim_rand_int(10) - 5) * 0.1f;
    data->unk_90[i] = (shim_rand_int(10) - 5) * 0.1f;
    data->unk_A0[i] = (shim_rand_int(10) - 5) * 0.1f;

    for (i = 0; i < 4; i++) {
        data->unk_50[i] += data->unk_80[i];
        data->unk_60[i] += data->unk_90[i];
        data->unk_70[i] += data->unk_A0[i];
        data->unk_90[i] -= 0.15;
        if (unk_20 >= 27) {
            data->unk_60[i] = -1000.0f;
        }
    }

    if (unk_20 >= 32) {
        data->unk_4C = 1;
        data->unk_20 = 1;
    }
}

void firework_rocket_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = firework_rocket_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 700;
    renderTask.renderMode =  RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/firework_rocket", firework_rocket_appendGfx);
