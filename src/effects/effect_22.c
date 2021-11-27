#include "common.h"
#include "effects_internal.h"

void fx_22_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_22", fx_22_main);

void fx_22_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_22", fx_22_update);

void fx_22_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_22_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_22", fx_22_appendGfx);
