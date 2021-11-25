#include "common.h"
#include "effects_internal.h"

void fx_25_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_25", fx_25_main);

void fx_25_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_25", fx_25_update);

void fx_25_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_25_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_25", fx_25_appendGfx);
