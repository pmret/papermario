#include "common.h"
#include "effects_internal.h"

void fx_20_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_20", fx_20_main);

void fx_20_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_20", fx_20_update);

void fx_20_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_20_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_20", fx_20_appendGfx);
