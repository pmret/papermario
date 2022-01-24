#include "common.h"
#include "effects_internal.h"

void drop_leaves_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/drop_leaves", drop_leaves_main);

void drop_leaves_init(void) {
}

INCLUDE_ASM(s32, "effects/drop_leaves", drop_leaves_update);

void drop_leaves_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = drop_leaves_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/drop_leaves", drop_leaves_appendGfx);
