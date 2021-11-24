#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_121", func_E010E000);

INCLUDE_ASM(s32, "effects/effect_121", fx_121_main);

void fx_121_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_121", fx_121_update);

void fx_121_appendGfx(EffectInstance* effect);
void fx_121_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_121_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_121", fx_121_appendGfx);
