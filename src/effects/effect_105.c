#include "common.h"
#include "effects_internal.h"

void fx_105_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_105", fx_105_main);

void fx_105_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_105", fx_105_update);

void fx_105_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_105_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00D227C(void) {
}

INCLUDE_ASM(s32, "effects/effect_105", fx_105_appendGfx);
