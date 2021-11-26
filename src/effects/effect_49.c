#include "common.h"
#include "effects_internal.h"

void fx_49_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_49", fx_49_main);

void fx_49_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_49", fx_49_update);

void fx_49_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_49_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_49", fx_49_appendGfx);
