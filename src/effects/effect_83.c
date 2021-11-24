#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_83", fx_83_main);

void fx_83_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_83", fx_83_update);

void fx_83_appendGfx(EffectInstance* effect);
void fx_83_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_83_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00A639C(void) {
}

INCLUDE_ASM(s32, "effects/effect_83", fx_83_appendGfx);
