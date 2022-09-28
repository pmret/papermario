#include "common.h"
#include "effects_internal.h"

void smoke_burst_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_main);

void smoke_burst_init(void) {
}

// INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_update);
void smoke_burst_update(EffectInstance *arg0) {
    s32 *temp_v0;
    s32 temp_a0;
    s32 temp_v1;

    temp_v0 = arg0->data.any;
    temp_v1 = temp_v0->unk18;
    temp_a0 = temp_v0->unk14 - 1;
    temp_v0->unk18 = (s32) (temp_v1 + 1);
    temp_v0->unk14 = temp_a0;
    temp_v0->unk20 = (f32) (((f32) temp_v1 * 8.0f) / (f32) temp_v0->unk1C);
    if (temp_a0 < 0) {
        shim_remove_effect(arg0);
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
