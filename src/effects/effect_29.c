#include "common.h"
#include "effects_internal.h"

void fx_29_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_29", fx_29_main);

void fx_29_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_29", fx_29_update);

void fx_29_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_29_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_29", fx_29_appendGfx);
