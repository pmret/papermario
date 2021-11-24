#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_48", fx_48_main);

void fx_48_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_48", fx_48_update);

void fx_48_appendGfx(EffectInstance* effect);
void fx_48_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_48_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_48", fx_48_appendGfx);
