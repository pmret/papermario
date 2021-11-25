#include "common.h"
#include "effects_internal.h"

void fx_17_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_17", fx_17_main);

void fx_17_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_17", fx_17_update);

void fx_17_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_17_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_17", fx_17_appendGfx);
