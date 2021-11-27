#include "common.h"
#include "effects_internal.h"

void fx_50_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_50", fx_50_main);

void fx_50_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_50", fx_50_update);

void fx_50_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_50_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_50", fx_50_appendGfx);
