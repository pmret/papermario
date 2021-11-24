#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_98", fx_98_main);

void fx_98_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_98", fx_98_update);

void fx_98_appendGfx(EffectInstance* effect);
void fx_98_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_98_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00C4300(void) {
}

INCLUDE_ASM(s32, "effects/effect_98", fx_98_appendGfx);
