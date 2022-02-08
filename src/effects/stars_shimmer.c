#include "common.h"
#include "effects_internal.h"

void stars_shimmer_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/stars_shimmer", stars_shimmer_main);

void stars_shimmer_init(void) {
}

INCLUDE_ASM(s32, "effects/stars_shimmer", stars_shimmer_update);

void stars_shimmer_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = stars_shimmer_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/stars_shimmer", stars_shimmer_appendGfx);
