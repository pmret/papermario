#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_91", fx_91_main);

void fx_91_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_91", fx_91_update);

void fx_91_appendGfx(EffectInstance* effect);
void fx_91_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_91_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00B62D8(void) {
}

INCLUDE_ASM(s32, "effects/effect_91", fx_91_appendGfx);
