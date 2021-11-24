#include "common.h"
#include "effects_internal.h"

INCLUDE_ASM(s32, "effects/effect_59", fx_59_main);

void fx_59_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_59", fx_59_update);

void fx_59_appendGfx(EffectInstance* effect);
void fx_59_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_59_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E007684C(void) {
}

void func_E0076854(void) {
}

INCLUDE_ASM(s32, "effects/effect_59", fx_59_appendGfx);
