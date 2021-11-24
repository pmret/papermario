#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_124", fx_124_main);

void fx_124_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_124", fx_124_update);

void fx_124_appendGfx(EffectInstance* effect);
void fx_124_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_124_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_124", fx_124_appendGfx);
