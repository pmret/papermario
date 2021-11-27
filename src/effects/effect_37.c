#include "common.h"
#include "effects_internal.h"

void fx_37_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_37", fx_37_main);

void fx_37_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_37", fx_37_update);

void fx_37_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_37_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_37", fx_37_appendGfx);
