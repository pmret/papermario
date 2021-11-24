#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_34", fx_34_main);

void fx_34_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_34", fx_34_update);

void fx_34_appendGfx(EffectInstance* effect);
void fx_34_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_34_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_34", fx_34_appendGfx);
