#include "common.h"
#include "effects_internal.h"

void shockwave_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/shockwave", shockwave_main);

void shockwave_init(void) {
}

INCLUDE_ASM(s32, "effects/shockwave", shockwave_update);

void shockwave_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = shockwave_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/shockwave", shockwave_appendGfx);
