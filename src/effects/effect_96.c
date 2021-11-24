#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_96", fx_96_main);

void fx_96_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_96", fx_96_update);

void fx_96_appendGfx(EffectInstance* effect);
void fx_96_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_96_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = -10;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00C0758(void) {
}

INCLUDE_ASM(s32, "effects/effect_96", fx_96_appendGfx);
