#include "common.h"
#include "effects_internal.h"

void fx_100_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_100", fx_100_main);

void fx_100_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_100", fx_100_update);

void fx_100_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_100_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C844C(void) {
}

INCLUDE_ASM(s32, "effects/effect_100", fx_100_appendGfx);
