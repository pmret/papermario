#include "common.h"
#include "effects_internal.h"

void fx_116_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_116", fx_116_main);

void fx_116_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_116", fx_116_update);

void fx_116_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_116_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_116", fx_116_appendGfx);
