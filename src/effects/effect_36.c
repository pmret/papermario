#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_36", fx_36_main);

void fx_36_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_36", fx_36_update);

void fx_36_appendGfx(EffectInstance* effect);
void fx_36_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_36_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_36", fx_36_appendGfx);
