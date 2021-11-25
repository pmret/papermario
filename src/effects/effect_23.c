#include "common.h"
#include "effects_internal.h"

void fx_23_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_23", fx_23_main);

void fx_23_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_23", fx_23_update);

void fx_23_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_23_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/effect_23", fx_23_appendGfx);
