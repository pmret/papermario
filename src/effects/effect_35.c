#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_35", fx_35_main);

void fx_35_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_35", fx_35_update);

void fx_35_appendGfx(EffectInstance* effect);
void fx_35_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_35_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_35", fx_35_appendGfx);
