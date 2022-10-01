#include "common.h"
#include "effects_internal.h"

void chomp_drop_init(EffectInstance* effect);
void chomp_drop_update(EffectInstance* effect);
void chomp_drop_render(EffectInstance* effect);
void chomp_drop_appendGfx(void* effect);

EffectInstance* chomp_drop_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, f32 arg6, s32 arg7, f32 arg8, s32 arg9) {
    EffectBlueprint bp;
    EffectInstance* effect;
    ChompDropFXData* data;
    s32 numParts = 1;

    bp.init = chomp_drop_init;
    bp.update = chomp_drop_update;
    bp.renderWorld = chomp_drop_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_CHOMP_DROP;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = effect->data.chompDrop = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(effect->data.chompDrop != NULL);

    data->unk_00 = arg0;
    data->unk_04 = arg1;
    data->unk_08 = arg2;
    data->unk_0C = arg3;
    data->unk_28 = arg8;
    data->unk_14 = arg4;
    data->unk_1C = arg5;
    data->unk_18 = arg6;
    data->unk_34 = 1.0f;
    data->unk_20 = arg7;
    data->unk_38 = shim_rand_int(0x168);
    data->unk_40 = arg9;
    data->unk_44 = 0;
    data->unk_3C = arg5;
    data->unk_24 = arg4;
    data->unk_10 = 0;
    data->unk_2C = 0;

    return effect;
}

void chomp_drop_init(EffectInstance* effect) {
}

void chomp_drop_update(EffectInstance* effect) {
    ChompDropFXData* data = effect->data.chompDrop;
    s32 unk40;

    data->unk_40--;
    data->unk_44++;
    if (data->unk_40 < 0) {
        shim_remove_effect(effect);
        return;
    }

    unk40 = data->unk_40;
    switch (data->unk_2C) {
        case 0:
            data->unk_24 += (data->unk_18 - data->unk_24) * data->unk_28;
            data->unk_3C += (data->unk_20 - data->unk_3C) * data->unk_28;
            data->unk_34 -= 0.02;
            if (data->unk_34 < 0.0f) {
                data->unk_30 = 10;
                data->unk_34 = 0.0f;
                data->unk_10 = 0.0f;
                data->unk_2C = 1;
            }
            break;
        case 1:
            data->unk_30--;
            if (data->unk_30 <= 0) {
                data->unk_2C = 2;
                data->unk_30 = 10;
            }
            break;
        case 2:
            data->unk_30--;
            if (data->unk_30 <= 0) {
                data->unk_2C = 3;
            }
            break;
        case 3:
            data->unk_10 -= 1.0f;
            data->unk_08 += data->unk_10;
            if (data->unk_08 < 0.0f) {
                data->unk_08 = 0.0f;
                shim_load_effect(EFFECT_DUST);
                dust_main(2, data->unk_04 + 5.0f, data->unk_08, data->unk_0C, 30);
                dust_main(2, data->unk_04 - 5.0f, data->unk_08, data->unk_0C, 30);
                data->unk_2C = 4;
                data->unk_30 = 20;
            }
            break;
        case 4:
            data->unk_30--;
            if (data->unk_30 <= 0) {
                data->unk_2C = 5;
            }
            break;
        case 5:
            if (unk40 < 10) {
                data->unk_3C = unk40 * 25;
            }
            data->unk_34 -= 0.05;
            break;
    }
}

void chomp_drop_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = chomp_drop_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = -10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/chomp_drop", chomp_drop_appendGfx);
