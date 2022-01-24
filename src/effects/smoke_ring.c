#include "common.h"
#include "effects_internal.h"

void smoke_ring_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/smoke_ring", smoke_ring_main);

void smoke_ring_init(void) {
}

INCLUDE_ASM(s32, "effects/smoke_ring", smoke_ring_update);

void smoke_ring_render(EffectInstance* effect) {
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = smoke_ring_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = 0;
    renderTask.renderMode = RENDER_MODE_28;

    retTask = shim_queue_render_task(&renderTask);
}

INCLUDE_ASM(s32, "effects/smoke_ring", smoke_ring_appendGfx);
