#include "common.h"
#include "effects_internal.h"

void sun_init(EffectInstance* effect);
void sun_update(EffectInstance* effect);
void sun_render(EffectInstance* effect);
void sun_appendGfx(void* effect);

EffectInstance* sun_main(s32 arg0, f32 offsetX, f32 offsetY, f32 offsetZ, f32 arg4, s32 duration) {
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
    data->lifeTime = 0;
    if (duration <= 0) {
        data->timeLeft = 1000;
    } else {
        data->timeLeft = duration;
    }
    data->unk_04.x = offsetX;
    data->unk_04.y = offsetY;
    data->unk_04.z = offsetZ;
    data->unk_34 = arg4;
    data->unk_18 = 255;
    data->unk_19 = 255;
    data->unk_1A = 255;
    data->unk_1B = 255;
    data->unk_1C = 255;
    data->unk_1D = 255;
    data->unk_1E = 255;

    for (i = 0; i < ARRAY_COUNT(data->unk_20); i++) {
        data->unk_20[i] = 0.0f;
    }
    data->targetAlpha = 255;
    data->alpha = 0;
    
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
