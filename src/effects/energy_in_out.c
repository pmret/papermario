#include "common.h"
#include "effects_internal.h"

void energy_in_out_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/energy_in_out", energy_in_out_main);

void energy_in_out_init(void) {
}

INCLUDE_ASM(s32, "effects/energy_in_out", energy_in_out_update);

void energy_in_out_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = energy_in_out_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00D6978(void) {
}

INCLUDE_ASM(s32, "effects/energy_in_out", energy_in_out_appendGfx);
