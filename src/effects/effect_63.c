#include "common.h"
#include "effects_internal.h"

void fx_63_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_63", fx_63_main);

void fx_63_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_63", fx_63_update);

void fx_63_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_63_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_63", fx_63_appendGfx);
