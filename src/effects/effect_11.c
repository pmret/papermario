#include "common.h"
#include "effects_internal.h"

void fx_11_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_11", fx_11_main);

void fx_11_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_11", fx_11_update);

void fx_11_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_11_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_11", fx_11_appendGfx);
