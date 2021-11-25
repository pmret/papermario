#include "common.h"
#include "effects_internal.h"

void fx_31_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_31", fx_31_main);

void fx_31_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_31", fx_31_update);

void fx_31_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_31_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_31", fx_31_appendGfx);
