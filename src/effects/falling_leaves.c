#include "common.h"
#include "effects_internal.h"

void falling_leaves_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/falling_leaves", falling_leaves_main);

void falling_leaves_init(void) {
}

INCLUDE_ASM(s32, "effects/falling_leaves", falling_leaves_update);

void falling_leaves_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = falling_leaves_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/falling_leaves", falling_leaves_appendGfx);
