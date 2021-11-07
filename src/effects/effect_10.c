#include "common.h"
#include "effects_internal.h"

void fx_10_init(EffectInstance* effect);
void fx_10_update(EffectInstance* effect);
void fx_10_render(EffectInstance* effect);
void fx_10_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_10", fx_10_main);

void fx_10_init(EffectInstance* effect) {
}

INCLUDE_ASM(s32, "effects/effect_10", fx_10_update);

void fx_10_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_10_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_10", fx_10_appendGfx);
