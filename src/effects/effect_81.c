#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_81", fx_81_main);

void fx_81_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_81", fx_81_update);

void fx_81_appendGfx(EffectInstance* effect);
void fx_81_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_81_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 100;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00A2234(void) {
}

INCLUDE_ASM(s32, "effects/effect_81", fx_81_appendGfx);
