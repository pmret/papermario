#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_27", fx_27_main);

void fx_27_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_27", fx_27_update);

void fx_27_appendGfx(EffectInstance* effect);
void fx_27_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_27_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E003621C(void) {
}

INCLUDE_ASM(s32, "effects/effect_27", fx_27_appendGfx);
