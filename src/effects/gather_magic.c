#include "common.h"
#include "effects_internal.h"

void gather_magic_appendGfx(void* effect);
void gather_magic_init(EffectInstance* effect);
void gather_magic_update(EffectInstance* effect);
void gather_magic_render(EffectInstance* effect);

EffectInstance* gather_magic_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint bp;
    EffectInstance* effect;
    GatherMagicFXData* data;
    s32 numParts = 31;
    s32 i;

    bp.unk_00 = 0;
    bp.init = gather_magic_init;
    bp.update = gather_magic_update;
    bp.renderWorld = gather_magic_render;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_GATHER_MAGIC;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    data = shim_general_heap_malloc(numParts * sizeof(*data));
    effect->data = data;
    ASSERT(effect->data != NULL);

    data->unk_04 = arg0;
    data->unk_1C = 0;
    if (arg5 <= 0) {
        data->unk_18 = 100;
    } else {
        data->unk_18 = arg5;
    }
    data->unk_14 = 0;
    data->unk_08 = arg1;
    data->unk_0C = arg2;
    data->unk_10 = arg3;

    if (arg0 == 0) {
        data->unk_30 = 255;
        data->unk_34 = 0;
        data->unk_38 = 255;
        data->unk_3C = 255;
        data->unk_40 = 255;
        data->unk_44 = 255;
    } else {
        data->unk_30 = 255;
        data->unk_34 = 20;
        data->unk_38 = 33;
        data->unk_3C = 50;
        data->unk_40 = 20;
        data->unk_44 = 10;
    }

    data++;
    for (i = 1; i < numParts; i++, data++) {
        s32 d = numParts - 1;
        f32 zero = 0.0f;

        data->unk_20 = ((i - 1) * 3240) / d;
        data->unk_24 = zero;
        data->unk_2C = ((i - 1) * 100) / d;
        data->unk_00 = 0;
    }
    return effect;
}

void gather_magic_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/gather_magic", gather_magic_update);

void gather_magic_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = gather_magic_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/gather_magic", gather_magic_appendGfx);
