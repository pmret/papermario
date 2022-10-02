#include "common.h"
#include "effects_internal.h"

void smoke_burst_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_main);

void smoke_burst_init(void) {
}

void smoke_burst_update(EffectInstance *effect) {
    SmokeBurstFXData* data = effect->data.smokeBurst;
    data->unk_20 = (f32) (((f32) data->unk_18 * 8.0f) / (f32) data->unk_1C);

    data->unk_18++;
    data->unk_14--;
    
    if (data->unk_14 < 0) {
        shim_remove_effect(effect);
    }
}

void smoke_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_appendGfx);
