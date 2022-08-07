#include "common.h"
#include "effects_internal.h"

void star_spirits_energy_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/star_spirits_energy", star_spirits_energy_main);

void star_spirits_energy_init(void) {
}

INCLUDE_ASM(s32, "effects/star_spirits_energy", star_spirits_energy_update);

void star_spirits_energy_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = star_spirits_energy_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/star_spirits_energy", star_spirits_energy_appendGfx);
