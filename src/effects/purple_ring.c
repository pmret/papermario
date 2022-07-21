#include "common.h"
#include "effects_internal.h"

void purple_ring_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/purple_ring", purple_ring_main);

void purple_ring_init(void) {
}

INCLUDE_ASM(s32, "effects/purple_ring", purple_ring_update);

void purple_ring_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = purple_ring_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/purple_ring", purple_ring_appendGfx);
