#include "common.h"
#include "effects_internal.h"

void smoke_impact_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/smoke_impact", smoke_impact_main);

void smoke_impact_init(void) {
}

INCLUDE_ASM(s32, "effects/smoke_impact", smoke_impact_update);

void smoke_impact_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_impact_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/smoke_impact", smoke_impact_appendGfx);
