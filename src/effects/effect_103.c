#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_103", fx_103_main);

void fx_103_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_103", fx_103_update);

void fx_103_appendGfx(EffectInstance* effect);
void fx_103_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_103_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00CE470(void) {
}

INCLUDE_ASM(s32, "effects/effect_103", fx_103_appendGfx);
