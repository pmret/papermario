#include "common.h"
#include "effects_internal.h"

void smoke_burst_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_main);

void smoke_burst_init(void) {
}

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_update);

void smoke_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/smoke_burst", smoke_burst_appendGfx);
