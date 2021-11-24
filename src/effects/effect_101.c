#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_101", fx_101_main);

void fx_101_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_101", fx_101_update);

void fx_101_appendGfx(EffectInstance* effect);
void fx_101_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_101_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_101", fx_101_appendGfx);
