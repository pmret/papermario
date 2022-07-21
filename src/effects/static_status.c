#include "common.h"
#include "effects_internal.h"

void static_status_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/static_status", static_status_main);

void static_status_init(void) {
}

INCLUDE_ASM(s32, "effects/static_status", static_status_update);

void static_status_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = static_status_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00E651C(void) {
}

INCLUDE_ASM(s32, "effects/static_status", static_status_appendGfx);
