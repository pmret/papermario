#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_78", fx_78_main);

void fx_78_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_78", fx_78_update);

void fx_78_appendGfx(EffectInstance* effect);
void fx_78_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_78_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_78", fx_78_appendGfx);
