#include "common.h"
#include "effects_internal.h"

void fx_12_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_12", func_E0018000);

INCLUDE_ASM(s32, "effects/effect_12", fx_12_main);

void fx_12_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_12", fx_12_update);

void fx_12_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_12_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_12", func_E00183BC);

INCLUDE_ASM(s32, "effects/effect_12", fx_12_appendGfx);
