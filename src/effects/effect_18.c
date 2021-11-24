#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_18", fx_18_main);

void fx_18_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_18", fx_18_update);

void fx_18_appendGfx(EffectInstance* effect);
void fx_18_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_18_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_18", func_E0024324);

INCLUDE_ASM(s32, "effects/effect_18", func_E00243BC);

INCLUDE_ASM(s32, "effects/effect_18", fx_18_appendGfx);
