#include "common.h"
#include "effects_internal.h"

void shimmer_burst_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/shimmer_burst", shimmer_burst_main);

void shimmer_burst_init(void) {
}

INCLUDE_ASM(s32, "effects/shimmer_burst", shimmer_burst_update);

void shimmer_burst_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shimmer_burst_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E0070738(void) {
}

INCLUDE_ASM(s32, "effects/shimmer_burst", shimmer_burst_appendGfx);
