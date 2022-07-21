#include "common.h"
#include "effects_internal.h"

void peach_star_beam_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/peach_star_beam", peach_star_beam_main);

void peach_star_beam_init(void) {
}

INCLUDE_ASM(s32, "effects/peach_star_beam", peach_star_beam_update);

void peach_star_beam_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = peach_star_beam_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/peach_star_beam", peach_star_beam_appendGfx);
