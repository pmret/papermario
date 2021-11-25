#include "common.h"
#include "effects_internal.h"

void fx_38_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_38", fx_38_main);

void fx_38_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_38", fx_38_update);

void fx_38_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_38_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_38", fx_38_appendGfx);
