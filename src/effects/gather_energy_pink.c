#include "common.h"
#include "effects_internal.h"

void gather_energy_pink_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/gather_energy_pink", gather_energy_pink_main);

void gather_energy_pink_init(void) {
}

INCLUDE_ASM(s32, "effects/gather_energy_pink", gather_energy_pink_update);

void gather_energy_pink_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = gather_energy_pink_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/gather_energy_pink", gather_energy_pink_appendGfx);
