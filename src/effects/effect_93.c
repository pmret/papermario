#include "common.h"
#include "effects_internal.h"

void fx_93_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_93", fx_93_main);

void fx_93_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_93", fx_93_update);

void fx_93_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_93_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 100;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00BA618(void) {
}

INCLUDE_ASM(s32, "effects/effect_93", fx_93_appendGfx);
