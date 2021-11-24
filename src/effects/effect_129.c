#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_129", fx_129_main);

void fx_129_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_129", fx_129_update);

void fx_129_appendGfx(EffectInstance* effect);
void fx_129_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_129_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 5;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_129", fx_129_appendGfx);
