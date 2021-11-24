#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_89", fx_89_main);

void fx_89_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_89", fx_89_update);

void fx_89_appendGfx(EffectInstance* effect);
void fx_89_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_89_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00B24A8(void) {
}

INCLUDE_ASM(s32, "effects/effect_89", fx_89_appendGfx);
