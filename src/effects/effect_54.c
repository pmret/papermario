#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_54", fx_54_main);

void fx_54_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_54", fx_54_update);

void fx_54_appendGfx(EffectInstance* effect);
void fx_54_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_54_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_54", fx_54_appendGfx);
