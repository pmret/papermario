#include "common.h"
#include "effects_internal.h"

void fx_95_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_95", fx_95_main);

void fx_95_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_95", fx_95_update);

void fx_95_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_95_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

void func_E00BE5B4(void) {
}

INCLUDE_ASM(s32, "effects/effect_95", fx_95_appendGfx);
