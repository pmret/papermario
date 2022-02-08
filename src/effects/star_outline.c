#include "common.h"
#include "effects_internal.h"

void star_outline_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/star_outline", star_outline_main);

void star_outline_init(void) {
}

INCLUDE_ASM(s32, "effects/star_outline", star_outline_update);

void star_outline_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = star_outline_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/star_outline", star_outline_appendGfx);
