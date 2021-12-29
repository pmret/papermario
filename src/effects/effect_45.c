#include "common.h"
#include "effects_internal.h"

void fx_45_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_45", fx_45_main);

void fx_45_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_45", fx_45_update);

void fx_45_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_45_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_45", fx_45_appendGfx);
