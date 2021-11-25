#include "common.h"
#include "effects_internal.h"

void fx_133_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_133", fx_133_main);

void fx_133_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_133", fx_133_update);

void fx_133_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_133_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_133", fx_133_appendGfx);
