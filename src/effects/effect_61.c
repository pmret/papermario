#include "common.h"
#include "effects_internal.h"

void fx_61_appendGfx(EffectInstance* effect);

INCLUDE_ASM(s32, "effects/effect_61", fx_61_main);

void fx_61_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_61", fx_61_update);

void fx_61_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_61_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E007A884(void) {
}

INCLUDE_ASM(s32, "effects/effect_61", fx_61_appendGfx);
