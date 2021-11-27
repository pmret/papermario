#include "common.h"
#include "effects_internal.h"

void fx_92_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_92", fx_92_main);

void fx_92_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_92", fx_92_update);

void fx_92_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_92_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00B8200(void) {
}

INCLUDE_ASM(s32, "effects/effect_92", fx_92_appendGfx);
