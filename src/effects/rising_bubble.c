#include "common.h"
#include "effects_internal.h"

void rising_bubble_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/rising_bubble", rising_bubble_main);

void rising_bubble_init(void) {
}

INCLUDE_ASM(s32, "effects/rising_bubble", rising_bubble_update);

void rising_bubble_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = rising_bubble_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/rising_bubble", rising_bubble_appendGfx);
