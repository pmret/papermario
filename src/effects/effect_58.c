#include "common.h"
#include "effects_internal.h"

void fx_58_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_58", fx_58_main);

void fx_58_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_58", fx_58_update);

void fx_58_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_58_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_58", fx_58_appendGfx);
