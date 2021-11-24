#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_71", fx_71_main);

void fx_71_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_71", fx_71_update);

void fx_71_appendGfx(EffectInstance* effect);
void fx_71_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_71_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER3;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_71", fx_71_appendGfx);
