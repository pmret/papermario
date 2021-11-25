#include "common.h"
#include "effects_internal.h"

void fx_111_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_111", fx_111_main);

void fx_111_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_111", fx_111_update);

void fx_111_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_111_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 6;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_111", fx_111_appendGfx);
