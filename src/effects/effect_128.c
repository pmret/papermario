#include "common.h"
#include "effects_internal.h"

void fx_128_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/effect_128", fx_128_main);

void fx_128_init(void) {
}

INCLUDE_ASM(s32, "effects/effect_128", fx_128_update);

void fx_128_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = fx_128_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/effect_128", fx_128_appendGfx);
