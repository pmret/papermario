#include "common.h"
#include "effects_internal.h"

void fx_102_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_102", fx_102_main);

void fx_102_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_102", fx_102_update);

void fx_102_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_102_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00CC9C8(void) {
}

INCLUDE_ASM(s32, "effects/effect_102", fx_102_appendGfx);
