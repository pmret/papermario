#include "common.h"
#include "effects_internal.h"

void fx_125_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_125", fx_125_main);

void fx_125_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_125", fx_125_update);

void fx_125_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_125_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_125", func_E01166E8);

INCLUDE_ASM(s32, "effects/effect_125", fx_125_appendGfx);
