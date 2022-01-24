#include "common.h"
#include "effects_internal.h"

void green_impact_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/green_impact", green_impact_main);

void green_impact_init(void) {
}

INCLUDE_ASM(s32, "effects/green_impact", green_impact_update);

void green_impact_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = green_impact_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/green_impact", green_impact_appendGfx);
