#include "common.h"
#include "effects_internal.h"

void stars_burst_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/stars_burst", stars_burst_main);

void stars_burst_init(void) {
}

INCLUDE_ASM(s32, "effects/stars_burst", stars_burst_update);

void stars_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stars_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/stars_burst", stars_burst_appendGfx);
