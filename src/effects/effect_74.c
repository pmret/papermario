#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_74", fx_74_main);

void fx_74_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_74", fx_74_update);

void fx_74_appendGfx(EffectInstance* effect);
void fx_74_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_74_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_74", fx_74_appendGfx);
