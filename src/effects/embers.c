#include "common.h"
#include "effects_internal.h"

void embers_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/embers", embers_main);

void embers_init(void) {
}

INCLUDE_ASM(s32, "effects/embers", embers_update);

void embers_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = embers_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

void func_E00E05F8(void) {
}

INCLUDE_ASM(s32, "effects/embers", embers_appendGfx);
