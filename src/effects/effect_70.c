#include "common.h"
#include "effects_internal.h"

void fx_70_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_70", fx_70_main);

void fx_70_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_70", fx_70_update);

void fx_70_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_70_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_70", fx_70_appendGfx);
