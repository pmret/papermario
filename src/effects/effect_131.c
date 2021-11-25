#include "common.h"
#include "effects_internal.h"

void fx_131_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_131", fx_131_main);

void fx_131_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_131", fx_131_update);

void fx_131_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_131_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_131", fx_131_appendGfx);
