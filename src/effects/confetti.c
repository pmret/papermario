#include "common.h"
#include "effects_internal.h"

void confetti_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/confetti", func_E0088000);

INCLUDE_ASM(s32, "effects/confetti", confetti_main);

void confetti_init(void) {
}

INCLUDE_ASM(s32, "effects/confetti", confetti_update);

void confetti_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = confetti_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/confetti", confetti_appendGfx);
