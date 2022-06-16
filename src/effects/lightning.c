#include "common.h"
#include "effects_internal.h"

void lightning_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/lightning", lightning_main);

void lightning_init(void) {
}

INCLUDE_ASM(s32, "effects/lightning", lightning_update);

void lightning_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lightning_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/lightning", lightning_appendGfx);
