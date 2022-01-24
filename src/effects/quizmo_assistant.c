#include "common.h"
#include "effects_internal.h"

void quizmo_assistant_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/quizmo_assistant", quizmo_assistant_main);

void quizmo_assistant_init(void) {
}

INCLUDE_ASM(s32, "effects/quizmo_assistant", quizmo_assistant_update);

void quizmo_assistant_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = quizmo_assistant_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 10;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/quizmo_assistant", quizmo_assistant_appendGfx);
