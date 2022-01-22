#include "common.h"
#include "effects_internal.h"

void lens_flare_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/lens_flare", lens_flare_main);

void lens_flare_init(void) {
}

INCLUDE_ASM(s32, "effects/lens_flare", lens_flare_update);

void lens_flare_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = lens_flare_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 20;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/lens_flare", lens_flare_appendGfx);
