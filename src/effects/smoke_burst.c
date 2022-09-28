#include "common.h"
#include "effects_internal.h"

void smoke_burst_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_main);

void smoke_burst_init(void) {
}

// INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_update);
void smoke_burst_update(EffectInstance *effect) {
    SmokeBurstFXData* data = ((EffectInstance*)effect)->data.smokeBurst;
    s32 timeAlive = data->unk18;
    s32 timeLeft = data->unk14 - 1;

    data->unk14--;    
    data->unk18++;
    
    data->unk20 = (f32) (((f32) timeAlive * 8.0f) / (f32) data->unk1C);
    if (timeLeft < 0) {
        shim_remove_effect(effect);
        return;
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
