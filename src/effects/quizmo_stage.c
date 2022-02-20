#include "common.h"
#include "effects_internal.h"

void quizmo_stage_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/quizmo_stage", quizmo_stage_main);

void quizmo_stage_init(void) {
}

INCLUDE_ASM(s32, "effects/quizmo_stage", quizmo_stage_update);

void quizmo_stage_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = quizmo_stage_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_SURFACE_OPA;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/quizmo_stage", quizmo_stage_appendGfx);
