#include "common.h"
#include "effects_internal.h"

void fx_65_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_65", fx_65_main);

void fx_65_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_65", fx_65_update);

void fx_65_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_65_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/effect_65", fx_65_appendGfx);
