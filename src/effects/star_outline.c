#include "common.h"
#include "effects_internal.h"

void star_outline_appendGfx(void* effect);

void star_outline_init(EffectInstance* effect);
void star_outline_update(EffectInstance* effect);
void star_outline_render(EffectInstance* effect);

EffectInstance* star_outline_main(s32 arg0, f32 posX, f32 posY, f32 posZ, f32 arg4, s32 arg5) {
    EffectBlueprint effectBp;
    EffectInstance* effect;
    StarOutlineFXData* data;
    s32 numParts = 1;

    effectBp.init = star_outline_init;
    effectBp.update = star_outline_update;
    effectBp.renderWorld = star_outline_render;
    effectBp.unk_00 = 0;
    effectBp.unk_14 = 0;
    effectBp.effectID = EFFECT_STAR_OUTLINE;

    effect = shim_create_effect_instance(&effectBp);
    effect->numParts = numParts;

    data = effect->data.starOutline = shim_general_heap_malloc(numParts * sizeof(*data));
    ASSERT(data != NULL);

    data->unk_00 = 1;
    data->unk_02 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->pos.x = posX;
    data->pos.y = posY;
    data->pos.z = posZ;
    data->unk_38 = arg4;
    data->unk_18 = 255;
    data->unk_1C = 255;
    data->unk_20 = 120;
    data->unk_28 = 255;
    data->unk_2C = 120;
    data->unk_30 = 0;
    data->unk_34 = 255;
    data->unk_24 = 255;
    data->unk_3C.x = 0;
    data->unk_3C.y = 0;
    data->unk_3C.z = 0;

    return effect;
}

void star_outline_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/star_outline", star_outline_update);

void star_outline_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = star_outline_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/star_outline", star_outline_appendGfx);
