#include "common.h"
#include "effects_internal.h"

void fx_134_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_134", fx_134_main);

void fx_134_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_134", fx_134_update);

void fx_134_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_134_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_134", fx_134_appendGfx);
