#include "common.h"
#include "effects_internal.h"

void fx_43_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_43", fx_43_main);

void fx_43_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_43", fx_43_update);

void fx_43_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_43_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_43", fx_43_appendGfx);
