#include "common.h"
#include "effects_internal.h"

void fx_87_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_87", fx_87_main);

void fx_87_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_87", fx_87_update);

void fx_87_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_87_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00AE544(void) {
}

INCLUDE_ASM(s32, "effects/effect_87", fx_87_appendGfx);
