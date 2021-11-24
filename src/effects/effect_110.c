#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_110", fx_110_main);

void fx_110_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_110", fx_110_update);

void fx_110_appendGfx(EffectInstance* effect);
void fx_110_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_110_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00DC2FC(void) {
}

INCLUDE_ASM(s32, "effects/effect_110", fx_110_appendGfx);
