#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_104", fx_104_main);

void fx_104_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_104", fx_104_update);

void fx_104_appendGfx(EffectInstance* effect);
void fx_104_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_104_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_104", fx_104_appendGfx);
