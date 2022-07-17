#include "common.h"
#include "effects_internal.h"

void energy_shockwave_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/energy_shockwave", energy_shockwave_main);

void energy_shockwave_init(void) {
}

INCLUDE_ASM(s32, "effects/energy_shockwave", energy_shockwave_update);

void energy_shockwave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = energy_shockwave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/energy_shockwave", energy_shockwave_appendGfx);
