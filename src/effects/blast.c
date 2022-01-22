#include "common.h"
#include "effects_internal.h"

void blast_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/blast", blast_main);

void blast_init(void) {
}

INCLUDE_ASM(s32, "effects/blast", blast_update);

void blast_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = blast_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/blast", blast_appendGfx);
