#include "common.h"
#include "effects_internal.h"

void ring_blast_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/ring_blast", ring_blast_main);

void ring_blast_init(void) {
}

INCLUDE_ASM(s32, "effects/ring_blast", ring_blast_update);

void ring_blast_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = ring_blast_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_MODE_2;
}

INCLUDE_ASM(s32, "effects/ring_blast", ring_blast_appendGfx);
