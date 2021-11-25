#include "common.h"
#include "effects_internal.h"

void fx_123_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_123", fx_123_main);

void fx_123_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_123", fx_123_update);

void fx_123_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_123_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_123", func_E0112330);

INCLUDE_ASM(s32, "effects/effect_123", fx_123_appendGfx);
