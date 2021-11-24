#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_88", fx_88_main);

void fx_88_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_88", fx_88_update);

void fx_88_appendGfx(EffectInstance* effect);
void fx_88_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_88_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_88", fx_88_appendGfx);
