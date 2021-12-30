#include "common.h"
#include "effects_internal.h"

void fx_114_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_114", fx_114_main);

void fx_114_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_114", fx_114_update);

void fx_114_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_114_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 7;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

void func_E00E4954(void) {
}

INCLUDE_ASM(s32, "effects/effect_114", fx_114_appendGfx);
