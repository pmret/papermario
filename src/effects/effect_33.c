#include "common.h"
#include "effects_internal.h"

void fx_33_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_33", fx_33_main);

void fx_33_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_33", fx_33_update);

void fx_33_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_33_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_33", fx_33_appendGfx);
