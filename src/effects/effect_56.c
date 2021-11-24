#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_56", fx_56_main);

void fx_56_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_56", fx_56_update);

void fx_56_appendGfx(EffectInstance* effect);
void fx_56_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_56_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E0070738(void) {
}

INCLUDE_ASM(s32, "effects/effect_56", fx_56_appendGfx);
