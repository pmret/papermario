#include "common.h"
#include "effects_internal.h"

void something_rotating_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/something_rotating", something_rotating_main);

void something_rotating_init(void) {
}

INCLUDE_ASM(s32, "effects/something_rotating", something_rotating_update);

void something_rotating_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = something_rotating_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/something_rotating", func_E01166E8);

INCLUDE_ASM(s32, "effects/something_rotating", something_rotating_appendGfx);
