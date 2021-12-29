#include "common.h"
#include "effects_internal.h"

void fx_40_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_40", fx_40_main);

void fx_40_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_40", fx_40_update);

void fx_40_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_40_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_40", fx_40_appendGfx);
