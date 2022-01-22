#include "common.h"
#include "effects_internal.h"

void shimmer_wave_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/shimmer_wave", shimmer_wave_main);

void shimmer_wave_init(void) {
}

INCLUDE_ASM(s32, "effects/shimmer_wave", shimmer_wave_update);

void shimmer_wave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shimmer_wave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/shimmer_wave", shimmer_wave_appendGfx);
