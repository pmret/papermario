#include "common.h"
#include "effects_internal.h"

void red_impact_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/red_impact", red_impact_main);

void red_impact_init(void) {
}

INCLUDE_ASM(s32, "effects/red_impact", red_impact_update);

void red_impact_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = red_impact_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/red_impact", red_impact_appendGfx);
