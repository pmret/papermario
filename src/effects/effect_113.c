#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_113", fx_113_main);

void fx_113_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_113", fx_113_update);

void fx_113_appendGfx(EffectInstance* effect);
void fx_113_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_113_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00E2210(void) {
}

INCLUDE_ASM(s32, "effects/effect_113", fx_113_appendGfx);
