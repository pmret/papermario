#include "common.h"
#include "effects_internal.h"

void gather_magic_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/gather_magic", gather_magic_main);

void gather_magic_init(void) {
}

INCLUDE_ASM(s32, "effects/gather_magic", gather_magic_update);

void gather_magic_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = gather_magic_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/gather_magic", gather_magic_appendGfx);
