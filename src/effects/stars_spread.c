#include "common.h"
#include "effects_internal.h"

void stars_spread_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/stars_spread", stars_spread_main);

void stars_spread_init(void) {
}

INCLUDE_ASM(s32, "effects/stars_spread", stars_spread_update);

void stars_spread_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stars_spread_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/stars_spread", stars_spread_appendGfx);
