#include "common.h"
#include "effects_internal.h"

void fx_62_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_62", fx_62_main);

void fx_62_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_62", fx_62_update);

void fx_62_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_62_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_62", fx_62_appendGfx);
