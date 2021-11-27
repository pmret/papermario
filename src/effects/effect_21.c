#include "common.h"
#include "effects_internal.h"

void fx_21_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_21", fx_21_main);

void fx_21_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_21", fx_21_update);

void fx_21_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_21_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_21", fx_21_appendGfx);
