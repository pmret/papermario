#include "common.h"
#include "effects_internal.h"

void ending_decals_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/ending_decals", ending_decals_main);

void ending_decals_init(void) {
}

INCLUDE_ASM(s32, "effects/ending_decals", ending_decals_update);

void ending_decals_render(EffectInstance* effect) {
    EndingDecalsFXData* data = effect->data.endingDecals;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    RenderTask* retTask;

    renderTask.appendGfxArg = effect;
    renderTask.appendGfx = ending_decals_appendGfx;
    renderTask.distance = 10;
    if (data->unk_00 == 0) {
        renderTaskPtr->renderMode = RENDER_MODE_SURFACE_OPA;
    } else {
        renderTaskPtr->renderMode = RENDER_MODE_2D;
    }

    retTask = shim_queue_render_task(renderTaskPtr);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/ending_decals", ending_decals_appendGfx);
