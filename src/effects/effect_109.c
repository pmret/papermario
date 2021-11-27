#include "common.h"
#include "effects_internal.h"

void fx_109_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_109", fx_109_main);

void fx_109_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_109", fx_109_update);

void fx_109_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_109_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00DA228(void) {
}

INCLUDE_ASM(s32, "effects/effect_109", fx_109_appendGfx);
