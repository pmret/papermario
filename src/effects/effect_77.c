#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_77", fx_77_main);

void fx_77_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_77", fx_77_update);

void fx_77_appendGfx(EffectInstance* effect);
void fx_77_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_77_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = -10;
    renderTask.renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_77", fx_77_appendGfx);
