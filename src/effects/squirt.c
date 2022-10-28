#include "common.h"
#include "effects_internal.h"

s32 D_E00B2BA0[] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFC88020, 0x00000000 };

void squirt_init(EffectInstance* effect);
void squirt_update(EffectInstance* effect);
void squirt_render(EffectInstance* effect);
void squirt_appendGfx(void* effect);

EffectInstance* squirt_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SquirtFXData* data;
    s32 numParts = 1;
    s32 i;

    bp.init = squirt_init;
    bp.update = squirt_update;
    bp.renderWorld = squirt_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_SQUIRT;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.squirt = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.squirt != NULL);

    data->unk_00 = arg0;
    data->unk_30 = 0;
    if (arg8 <= 0) {
        data->unk_2C = 1000;
    } else if (arg0 == 0) {
        data->unk_2C = arg8 * 2;
    } else {
        data->unk_2C = arg8 * 4;
    }
    data->unk_28 = arg8;
    if (arg0 == 0) {
        data->unk_40 = 200;
    } else {
        data->unk_40 = 255;
    }
    data->unk_10 = arg1;
    data->unk_14 = arg2;
    data->unk_18 = arg3;
    data->unk_04 = data->unk_10;
    data->unk_08 = data->unk_14;
    data->unk_0C = data->unk_18;
    data->unk_1C = arg4;
    data->unk_20 = arg5;
    data->unk_24 = arg6;
    data->unk_50 = arg7;
    data->unk_34 = 210;
    data->unk_38 = 230;
    data->unk_3C = 255;
    data->unk_44 = 0;
    data->unk_48 = 30;
    data->unk_4C = 205;
    data->unk_54 = 0;

    for (i = 0; i < 12; i++) {
        data->unk_58[i] = 10.0f;
        data->unk_88[i] = 2.0f;
        data->unk_B8[i] = 0;
        if (arg0 == 0) {
            data->unk_178[i] = i + 1;
        } else {
            data->unk_178[i] = i * 5 + 1;
        }
        data->unk_E8[i] = data->unk_04;
        data->unk_118[i] = data->unk_08;
        data->unk_148[i] = data->unk_0C;
        data->unk_1A8[i] = 0;
    }

    return effect;
}

void squirt_init(EffectInstance* effect) {
}

void squirt_update(EffectInstance* effect) {
    SquirtFXData* data = effect->data.squirt;
    s32 unk_00 = data->unk_00;
    s32 unk_28;
    s32 var_v1;
    f32 factor;
    s32 i;

    if (effect->flags & 0x10) {
        effect->flags &= ~0x10;
        data->unk_2C = 16;
    }

    if (data->unk_2C < 1000) {
        data->unk_2C--;
    }

    data->unk_30++;

    if (data->unk_2C < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk_28 = data->unk_28;

    data->unk_54++;
    if (data->unk_54 > 12) {
        data->unk_54 = 12;
    }

    for (i = 0; i < 12; i++) {
        if (data->unk_178[i] == 0 || --data->unk_178[i] == 0) {
            data->unk_1A8[i]++;
            if (data->unk_1A8[i] >= unk_28) {
                var_v1 = unk_28;
            } else {
                var_v1 = data->unk_1A8[i];
            }

            factor = (f32) var_v1 / unk_28;

            if (unk_00 == 0) {
                data->unk_E8[i] = data->unk_10 + (data->unk_1C - data->unk_10) * factor;
                data->unk_118[i] = data->unk_14 + (data->unk_20 - data->unk_14) * factor;
                data->unk_148[i] = data->unk_18 + (data->unk_24 - data->unk_18) * factor;
            } else {
                data->unk_E8[i] = data->unk_10 + (data->unk_1C - data->unk_10) * factor;
                data->unk_118[i] = data->unk_14 + (data->unk_20 - data->unk_14) * factor + shim_sin_deg(factor * 180.0f) * 120.0f;
                data->unk_148[i] = data->unk_18 + (data->unk_24 - data->unk_18) * factor;
                data->unk_1D8[i] = 255.0f - factor * 255.0f;
            }
        }
    }
}

void squirt_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = squirt_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00B24A8(void) {
}

INCLUDE_ASM(s32, "effects/squirt", squirt_appendGfx);
