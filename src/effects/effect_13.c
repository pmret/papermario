#include "common.h"
#include "effects_internal.h"

void fx_13_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_13", fx_13_main);

void fx_13_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_13", fx_13_update);

void fx_13_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_13_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_13", fx_13_appendGfx);
