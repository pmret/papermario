#include "common.h"
#include "effects_internal.h"

void fx_85_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_85", fx_85_main);

void fx_85_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_85", fx_85_update);

void fx_85_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_85_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_85", fx_85_appendGfx);
