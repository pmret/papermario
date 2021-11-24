#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_84", fx_84_main);

void fx_84_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_84", fx_84_update);

void fx_84_appendGfx(EffectInstance* effect);
void fx_84_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_84_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00A8318(void) {
}

INCLUDE_ASM(s32, "effects/effect_84", fx_84_appendGfx);
