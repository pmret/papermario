#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_112", fx_112_main);

void fx_112_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_112", fx_112_update);

void fx_112_appendGfx(EffectInstance* effect);
void fx_112_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_112_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00E05F8(void) {
}

INCLUDE_ASM(s32, "effects/effect_112", fx_112_appendGfx);
