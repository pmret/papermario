#include "common.h"
#include "effects_internal.h"

void sun_init(EffectInstance* effect);
void sun_update(EffectInstance* effect);
void sun_render(EffectInstance* effect);
void sun_appendGfx(void* effect);

EffectInstance* sun_main(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    EffectBlueprint sp10;
    EffectInstance* effect;
    SunFXData* data;
    s32 numParts = 1;
    s32 i;

    sp10.init = sun_init;
    sp10.update = sun_update;
    sp10.renderWorld = sun_render;
    sp10.unk_00 = 0;
    sp10.unk_14 = NULL;
    sp10.effectID = EFFECT_SUN;
    
    effect = shim_create_effect_instance(&sp10);
    effect->numParts = numParts;
    
    data = effect->data.sun = shim_general_heap_malloc(sizeof(*data));
    ASSERT(data != NULL);
    
    data->unk_00 = arg0;
    data->unk_14 = 0;
    if (arg5 <= 0) {
        data->unk_10 = 1000;
    } else {
        data->unk_10 = arg5;
    }
    data->unk_04.x = arg1;
    data->unk_04.y = arg2;
    data->unk_04.z = arg3;
    data->unk_34 = arg4;
    data->unk_18 = 255;
    data->unk_19 = 255;
    data->unk_1A = 255;
    data->unk_1B = 255;
    data->unk_1C = 255;
    data->unk_1D = 255;
    data->unk_1E = 255;

    for (i = 0; i < 5; i++) {
        data->unk_20[i] = 0.0f;
    }
    data->unk_3C = 255;
    data->unk_38 = 0;
    
    return effect;
}

void sun_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/sun", sun_update);

void sun_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sun_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/sun", sun_appendGfx);
