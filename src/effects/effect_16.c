#include "common.h"
#include "effects_internal.h"

void fx_16_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_16", func_E0020000);

INCLUDE_ASM(s32, "effects/effect_16", fx_16_main);

void fx_16_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_16", fx_16_update);

void fx_16_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_16_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_16", fx_16_appendGfx);
