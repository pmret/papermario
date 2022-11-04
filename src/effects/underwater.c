#include "common.h"
#include "effects_internal.h"

void underwater_init(EffectInstance* effect);
void underwater_update(EffectInstance* effect);
void underwater_render(EffectInstance* effect);
void underwater_appendGfx(void* effect);

EffectInstance* underwater_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    UnderwaterFXData* data;
    s32 numParts = 1;
    s32 i;
    s32 j;

    bp.init = underwater_init;
    bp.update = underwater_update;
    bp.renderWorld = underwater_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_UNDERWATER;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.underwater = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.underwater != NULL);

    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_1F = 0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_18 = arg4;
    data->unk_1C = 10;
    data->unk_1D = 110;
    data->unk_1E = 255;
    data->unk_20 = 190;
    data->unk_21 = 220;
    data->unk_22 = 255;

    for (i = 0; i < ARRAY_COUNT(data->unk_23); i++) {
        for (j = 0; j < ARRAY_COUNT(data->unk_23[0]); j++) {
            data->unk_23[i][j] = 0;
            data->unk_11A[i][j] = 0;
        }
    }

    return effect;
}

void underwater_init(EffectInstance* effect) {
}

void underwater_update(EffectInstance* effect) {
    UnderwaterFXData* data = effect->data.underwater;
    s32 unk_10;
    s32 unk_14;
    s32 var_a0;
    f32 factor;
    s32 i;
    s32 j;

    if (effect->flags & EFFECT_INSTANCE_FLAGS_10) {
        effect->flags &= ~EFFECT_INSTANCE_FLAGS_10;
        data->unk_10 = 32;
    }

    if (data->unk_10 < 1000) {
        data->unk_10--;
    }

    data->unk_14++;

    if (data->unk_10 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_10 = data->unk_10;
    unk_14 = data->unk_14;

    var_a0 = 255;
    if (unk_10 < 32) {
        var_a0 = unk_10 * 8;
    }
    if (unk_14 < 16) {
        var_a0 = unk_14 * 16 + 15;
    }

    data->unk_1F = (f32) var_a0;
    factor = (f32) var_a0 / 255.0f;

    for (i = 1; i < ARRAY_COUNT(data->unk_23) - 1; i++) {
        data->unk_23[i][6] = shim_sin_deg(-((unk_14 - i) * 20)) * -64.0f * factor;
    }

    for (i = 1; i < ARRAY_COUNT(data->unk_23) - 1; i++) {
        for (j = 1; j < ARRAY_COUNT(data->unk_23[0]) - 1; j++) {
            f32 m11 = data->unk_23[i][j] * 4.0f;
            f32 m21 = data->unk_23[i + 1][j];
            f32 m01 = data->unk_23[i - 1][j];
            f32 m12 = data->unk_23[i][j + 1];
            f32 m10 = data->unk_23[i][j - 1];
            f32 m22 = data->unk_23[i + 1][j + 1];
            f32 m02 = data->unk_23[i - 1][j + 1];
            f32 m20 = data->unk_23[i + 1][j - 1];
            f32 m00 = data->unk_23[i - 1][j - 1];
            f32 temp1 = m21 + m01 + m12 + m10 - m11;
            f32 temp2 = (m22 + m02 + m20 + m00) * 0.5;

            data->unk_11A[i][j] += temp1 + temp2 - m11 * 0.7;
            data->unk_11A[i][j] *= 0.98;

            if (unk_10 < 32) {
                data->unk_23[i][j] *= factor;
            }
        }
    }

    for (i = 1; i < ARRAY_COUNT(data->unk_23) - 1; i++) {
        for (j = 1; j < ARRAY_COUNT(data->unk_23[0]) - 1; j++) {
            data->unk_23[i][j] += data->unk_11A[i][j] * 0.02;
        }
    }
}

void underwater_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = underwater_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 100;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00BA618(void) {
}

INCLUDE_ASM(s32, "effects/underwater", underwater_appendGfx);
