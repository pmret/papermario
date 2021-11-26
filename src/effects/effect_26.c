#include "common.h"
#include "effects_internal.h"

void fx_26_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_26", fx_26_main);

void fx_26_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_26", fx_26_update);

void fx_26_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_26_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 20;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_26", fx_26_appendGfx);
