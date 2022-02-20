#include "common.h"
#include "effects_internal.h"

void radial_shimmer_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/radial_shimmer", radial_shimmer_main);

void radial_shimmer_init(void) {
}

INCLUDE_ASM(s32, "effects/radial_shimmer", radial_shimmer_update);

void radial_shimmer_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = radial_shimmer_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/radial_shimmer", radial_shimmer_appendGfx);
