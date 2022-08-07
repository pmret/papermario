#include "common.h"
#include "effects_internal.h"

void chapter_change_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/chapter_change", func_E010E000);

INCLUDE_ASM(s32, "effects/chapter_change", chapter_change_main);

void chapter_change_init(void) {
}

INCLUDE_ASM(s32, "effects/chapter_change", chapter_change_update);

void chapter_change_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = chapter_change_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/chapter_change", chapter_change_appendGfx);
