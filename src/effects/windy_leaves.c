#include "common.h"
#include "effects_internal.h"

void windy_leaves_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/windy_leaves", windy_leaves_main);

void windy_leaves_init(void) {
}

INCLUDE_ASM(s32, "effects/windy_leaves", windy_leaves_update);

void windy_leaves_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = windy_leaves_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/windy_leaves", windy_leaves_appendGfx);
