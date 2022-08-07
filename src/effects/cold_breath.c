#include "common.h"
#include "effects_internal.h"

void cold_breath_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/cold_breath", cold_breath_main);

void cold_breath_init(void) {
}

INCLUDE_ASM(s32, "effects/cold_breath", cold_breath_update);

void cold_breath_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = cold_breath_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 6;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/cold_breath", cold_breath_appendGfx);
