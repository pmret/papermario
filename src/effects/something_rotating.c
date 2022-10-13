#include "common.h"
#include "effects_internal.h"

void something_rotating_init(EffectInstance* effect);
void something_rotating_update(EffectInstance* effect);
void something_rotating_render(EffectInstance* effect);
void something_rotating_appendGfx(void* effect);

EffectInstance* something_rotating_main(
    s32 arg0,
    f32 arg1,
    f32 arg2,
    f32 arg3,
    f32 arg4,
    s32 arg5
) {
    EffectBlueprint bp;
    EffectInstance* effect;
    SomethingRotatingFXData* part;
    s32 numParts = 8;
    s32 i;

    bp.init = something_rotating_init;
    bp.update = something_rotating_update;
    bp.renderWorld = something_rotating_render;
    bp.unk_00 = 0;
    bp.unk_14 = NULL;
    bp.effectID = EFFECT_SOMETHING_ROTATING;

    effect = shim_create_effect_instance(&bp);
    effect->numParts = numParts;
    part = effect->data.somethingRotating = shim_general_heap_malloc(numParts * sizeof(*part));
    ASSERT(effect->data.somethingRotating != NULL);

    part->unk_00 = arg0;
    part->unk_14 = 0;
    if (arg5 <= 0) {
        part->unk_10 = 1000;
    } else {
        part->unk_10 = arg5;
    }
    part->unk_04 = arg1;
    part->unk_08 = arg2;
    part->unk_0C = arg3;
    part->unk_18 = arg4;
    part->unk_1C = 30.0f;
    part->unk_20 = 0;

    part++;
    for (i = 1; i < numParts; i++, part++) {
        part->unk_24 = 0;
        part->unk_18 = arg4 * 0.5;
        part->unk_26 = 255;
        part->unk_27 = 255;
        part->unk_28 = 0;
        part->unk_25 = 0;
        part->unk_1C = 30.0f;
        part->unk_20 = 0;
        part->unk_29 = 0;
        part->unk_2C = 50.0f;
    }

    return effect;
}

void something_rotating_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/something_rotating", something_rotating_update);

void something_rotating_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = something_rotating_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/something_rotating", func_E01166E8);

INCLUDE_ASM(s32, "effects/something_rotating", something_rotating_appendGfx);
