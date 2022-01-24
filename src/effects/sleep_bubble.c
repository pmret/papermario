#include "common.h"
#include "effects_internal.h"

void sleep_bubble_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/sleep_bubble", sleep_bubble_main);

void sleep_bubble_init(void) {
}

INCLUDE_ASM(s32, "effects/sleep_bubble", sleep_bubble_update);

void sleep_bubble_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = sleep_bubble_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/sleep_bubble", sleep_bubble_appendGfx);
