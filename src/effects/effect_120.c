#include "common.h"
#include "effects_internal.h"

void fx_120_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_120", fx_120_main);

void fx_120_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_120", fx_120_update);

void fx_120_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_120_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_120", fx_120_appendGfx);
