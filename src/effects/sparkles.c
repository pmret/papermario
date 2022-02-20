#include "common.h"
#include "effects_internal.h"

void sparkles_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/sparkles", sparkles_main);

void sparkles_init(void) {
}

INCLUDE_ASM(s32, "effects/sparkles", sparkles_update);

void sparkles_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sparkles_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/sparkles", sparkles_appendGfx);
