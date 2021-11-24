#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_90", fx_90_main);

void fx_90_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_90", fx_90_update);

void fx_90_appendGfx(EffectInstance* effect);
void fx_90_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_90_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 20;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00B4574(void) {
}

INCLUDE_ASM(s32, "effects/effect_90", fx_90_appendGfx);
